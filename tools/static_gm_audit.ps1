param(
    [string]$RootDir = ""
)

$ErrorActionPreference = "Stop"

if ([string]::IsNullOrWhiteSpace($RootDir)) {
    $RootDir = Resolve-Path (Join-Path $PSScriptRoot "..")
}
else {
    $RootDir = Resolve-Path $RootDir
}

$errors = New-Object System.Collections.Generic.List[string]
$warnings = New-Object System.Collections.Generic.List[string]

function Add-AuditError {
    param([string]$Message)
    $errors.Add($Message) | Out-Null
}

function Add-AuditWarning {
    param([string]$Message)
    $warnings.Add($Message) | Out-Null
}

function Get-SourceFiles {
    Get-ChildItem -Path (Join-Path $RootDir "gamemodes"), (Join-Path $RootDir "include") -Recurse -Include *.pwn,*.inc -File
}

function Read-AllSourceText {
    (($script:SourceFiles | ForEach-Object { Get-Content -Raw -LiteralPath $_.FullName }) -join "`n")
}

function Get-DefineString {
    param(
        [string]$Name,
        [string]$Default = ""
    )

    $pattern = "#define\s+$([regex]::Escape($Name))\s+`"([^`"]+)`""
    $match = [regex]::Match($script:AllSourceText, $pattern)
    if ($match.Success) { return $match.Groups[1].Value }
    return $Default
}

function Get-DefineInt {
    param(
        [string]$Name,
        [int]$Default = 0
    )

    $pattern = "#define\s+$([regex]::Escape($Name))\s+\(?\s*(-?\d+)\s*\)?"
    $match = [regex]::Match($script:AllSourceText, $pattern)
    if ($match.Success) { return [int]$match.Groups[1].Value }
    return $Default
}

function Test-IntText {
    param([string]$Value)
    return ($Value -match '^-?\d+$')
}

function Test-FloatText {
    param([string]$Value)
    return ($Value -match '^-?(?:\d+(?:\.\d+)?|\.\d+)$')
}

function Test-NumberRange {
    param(
        [double]$Value,
        [double]$Min,
        [double]$Max
    )
    return ($Value -ge $Min -and $Value -le $Max)
}

function Get-DataLines {
    param([string]$Path)

    $result = New-Object System.Collections.Generic.List[object]
    if (-not (Test-Path -LiteralPath $Path)) {
        Add-AuditError "Arquivo obrigatorio ausente: $Path"
        return $result
    }

    $lineNo = 0
    foreach ($line in Get-Content -LiteralPath $Path) {
        $lineNo++
        $trim = $line.Trim()
        if ([string]::IsNullOrWhiteSpace($trim) -or $trim.StartsWith("#")) { continue }
        $result.Add([pscustomobject]@{ Line = $lineNo; Text = $trim }) | Out-Null
    }
    return $result
}

function Remove-InlineComment {
    param([string]$Line)

    $semi = $Line.IndexOf(";")
    if ($semi -ge 0) { $Line = $Line.Substring(0, $semi) }
    $slashes = $Line.IndexOf("//")
    if ($slashes -ge 0) { $Line = $Line.Substring(0, $slashes) }
    return $Line.Trim()
}

function Split-CsvTokens {
    param([string]$Line)

    return (Remove-InlineComment $Line).Split(",") | ForEach-Object { $_.Trim() } | Where-Object { $_ -ne "" }
}

function Split-SpaceTokens {
    param([string]$Line)

    return (Remove-InlineComment $Line) -split '\s+' | Where-Object { $_ -ne "" }
}

function Test-TimersHavePublic {
    $timers = [regex]::Matches($script:AllSourceText, 'SetTimer(?:Ex)?\s*\(\s*"([A-Za-z0-9_]+)"') |
        ForEach-Object { $_.Groups[1].Value } |
        Sort-Object -Unique

    foreach ($timer in $timers) {
        $publicPattern = "public\s+$([regex]::Escape($timer))\s*\("
        if ($script:AllSourceText -notmatch $publicPattern) {
            Add-AuditError "Timer sem public: $timer"
        }
    }
    Write-Host ("[AUDIT] timers: {0} callbacks verificados" -f $timers.Count)
}

function Test-DialogIdsUnique {
    $defs = New-Object System.Collections.Generic.List[object]
    foreach ($file in $script:SourceFiles) {
        $lineNo = 0
        foreach ($line in Get-Content -LiteralPath $file.FullName) {
            $lineNo++
            if ($line -match '#define\s+(DIALOG_[A-Za-z0-9_]+)\s+\(?\s*([0-9]+)\s*\)?') {
                $defs.Add([pscustomobject]@{
                    Name = $Matches[1]
                    Id = [int]$Matches[2]
                    Path = $file.FullName
                    Line = $lineNo
                }) | Out-Null
            }
        }
    }

    foreach ($group in ($defs | Group-Object Id | Where-Object Count -gt 1)) {
        $names = ($group.Group | ForEach-Object { "{0}:{1}" -f $_.Name, $_.Line }) -join ", "
        Add-AuditError "Dialog ID duplicado $($group.Name): $names"
    }
    Write-Host ("[AUDIT] dialogs: {0} defines verificados" -f $defs.Count)
}

function Read-KeyValueFile {
    param([string]$Path)

    $data = @{}
    if (-not (Test-Path -LiteralPath $Path)) {
        Add-AuditError "Arquivo obrigatorio ausente: $Path"
        return $data
    }

    foreach ($line in Get-Content -LiteralPath $Path) {
        $trim = $line.Trim()
        if ([string]::IsNullOrWhiteSpace($trim) -or $trim.StartsWith("#")) { continue }
        $eq = $trim.IndexOf("=")
        if ($eq -le 0) {
            Add-AuditError "server_info invalido: linha sem chave=valor: $trim"
            continue
        }
        $key = $trim.Substring(0, $eq).Trim()
        $value = $trim.Substring($eq + 1).Trim()
        $data[$key] = $value
    }
    return $data
}

function Test-ServerInfo {
    $path = Join-Path $RootDir "scriptfiles\server_info.txt"
    $data = Read-KeyValueFile -Path $path

    $expected = @{
        server_name = Get-DefineString -Name "GM_NAME" -Default "Life Simulator BR"
        server_version = Get-DefineString -Name "GM_VERSION" -Default "v1.3.0 Stable"
        gamemode_text = Get-DefineString -Name "GM_TEXT" -Default "LS RPG 1.3.0"
        server_language = "Portuguese"
    }

    foreach ($key in $expected.Keys) {
        if (-not $data.ContainsKey($key)) {
            Add-AuditError "server_info.txt sem chave obrigatoria: $key"
        }
        elseif ($data[$key] -ne $expected[$key]) {
            Add-AuditError "server_info divergente em ${key}: atual='$($data[$key])' esperado='$($expected[$key])'"
        }
    }
    Write-Host "[AUDIT] server_info: padrao conferido"
}

function Test-CriticalCallbacks {
    $gmPath = Join-Path $RootDir "gamemodes\nova_gm.pwn"
    $lines = Get-Content -LiteralPath $gmPath
    $callbacks = @(
        "OnPlayerRequestSpawn",
        "OnPlayerGiveDamage",
        "OnPlayerTakeDamage",
        "OnDialogResponse",
        "OnPlayerCommandText"
    )

    foreach ($callback in $callbacks) {
        $index = -1
        for ($i = 0; $i -lt $lines.Count; $i++) {
            if ($lines[$i] -match "^\s*public\s+$([regex]::Escape($callback))\s*\(") {
                $index = $i
                break
            }
        }
        if ($index -lt 0) {
            Add-AuditError "Callback critico ausente: $callback"
            continue
        }

        $windowEnd = [Math]::Min($lines.Count - 1, $index + 18)
        $window = ($lines[$index..$windowEnd] -join "`n")
        if ($window -notmatch "IsValidConnectedPlayer\s*\(\s*playerid\s*\)") {
            Add-AuditError "Callback critico sem guarda IsValidConnectedPlayer(playerid): $callback"
        }
        if ($callback -eq "OnPlayerTakeDamage" -and $window -notmatch "issuerid\s*!=\s*INVALID_PLAYER_ID\s*&&\s*!IsValidConnectedPlayer\s*\(\s*issuerid\s*\)") {
            Add-AuditError "OnPlayerTakeDamage sem guarda defensiva para issuerid invalido"
        }
    }

    $dispatcherPath = Join-Path $RootDir "include\core\admin.inc"
    $adminLines = Get-Content -LiteralPath $dispatcherPath
    $dispatchLine = ($adminLines | Select-String -Pattern '^\s*stock\s+DispatchPlayerCommandText\s*\(' | Select-Object -First 1)
    if (-not $dispatchLine) {
        Add-AuditError "Dispatcher central ausente: DispatchPlayerCommandText"
    }
    else {
        $start = $dispatchLine.LineNumber - 1
        $end = [Math]::Min($adminLines.Count - 1, $start + 14)
        $window = ($adminLines[$start..$end] -join "`n")
        if ($window -notmatch "IsValidConnectedPlayer\s*\(\s*playerid\s*\)" -or $window -notmatch "IsPlayerNPC\s*\(\s*playerid\s*\)") {
            Add-AuditError "DispatchPlayerCommandText sem guarda para playerid invalido/NPC"
        }
    }
    Write-Host "[AUDIT] callbacks: guardas conferidas"
}

function Test-CriticalCommands {
    $path = Join-Path $RootDir "scriptfiles\critical_commands.txt"
    $commands = Get-DataLines -Path $path | ForEach-Object { $_.Text.Trim() }
    foreach ($command in $commands) {
        if ($command -notmatch '^/[A-Za-z0-9_]+$') {
            Add-AuditError "critical_commands.txt contem comando invalido: $command"
            continue
        }

        $pattern = 'strcmp\s*\(\s*command\s*,\s*"' + [regex]::Escape($command) + '"\s*,\s*true\s*\)\s*==\s*0'
        if ($script:AllSourceText -notmatch $pattern) {
            Add-AuditError "Comando vital sem handler roteado: $command"
        }
    }
    Write-Host ("[AUDIT] comandos vitais: {0} comandos conferidos" -f $commands.Count)
}

function Get-FunctionBodyText {
    param([string]$FunctionName)

    $pattern = "(?ms)^\s*stock\s+$([regex]::Escape($FunctionName))\s*\([^)]*\)\s*\{(?<body>.*?)(?=^\s*stock\s+|\z)"
    $match = [regex]::Match($script:AllSourceText, $pattern)
    if ($match.Success) {
        return $match.Groups["body"].Value
    }
    return ""
}

function Get-CommandComparisonsFromText {
    param([string]$Text)

    [regex]::Matches($Text, 'strcmp\s*\(\s*command\s*,\s*"(/[A-Za-z0-9_]+)"\s*,\s*true\s*\)\s*==\s*0') |
        ForEach-Object { $_.Groups[1].Value.ToLowerInvariant() } |
        Sort-Object -Unique
}

function Test-DispatcherDuplicateCommandRoutes {
    $dispatcherBody = Get-FunctionBodyText -FunctionName "DispatchPlayerCommandText"
    if ([string]::IsNullOrWhiteSpace($dispatcherBody)) {
        Add-AuditError "Nao foi possivel ler DispatchPlayerCommandText para detectar rotas duplicadas"
        return
    }

    $commands = [regex]::Matches($dispatcherBody, 'strcmp\s*\(\s*command\s*,\s*"(/[A-Za-z0-9_]+)"\s*,\s*true\s*\)\s*==\s*0') |
        ForEach-Object { $_.Groups[1].Value.ToLowerInvariant() }

    foreach ($group in ($commands | Group-Object | Where-Object Count -gt 1)) {
        Add-AuditError "DispatchPlayerCommandText tem rota duplicada para $($group.Name)"
    }

    Write-Host ("[AUDIT] dispatcher duplicado: {0} comparacoes diretas conferidas" -f $commands.Count)
}

function Test-CommandRouterCoverage {
    $allHandled = @(Get-CommandComparisonsFromText -Text $script:AllSourceText)
    $policeHandled = @(Get-CommandComparisonsFromText -Text (Get-FunctionBodyText -FunctionName "HandlePoliceCommands"))
    $crimeHandled = @(Get-CommandComparisonsFromText -Text (Get-FunctionBodyText -FunctionName "Crime_HandleCommands"))
    $policeDirect = @(Get-CommandComparisonsFromText -Text (Get-FunctionBodyText -FunctionName "Dispatch_IsPoliceCommand"))
    $crimeDirect = @(Get-CommandComparisonsFromText -Text (Get-FunctionBodyText -FunctionName "Dispatch_IsCrimeCommand"))
    $commandTests = @([regex]::Matches($script:AllSourceText, 'Dispatch_AddCommandTestLine\s*\([^,]+,\s*[^,]+,\s*[^,]+,\s*[^,]+,\s*"(/[A-Za-z0-9_]+)"') |
        ForEach-Object { $_.Groups[1].Value.ToLowerInvariant() } |
        Sort-Object -Unique)
    $criticalPath = Join-Path $RootDir "scriptfiles\critical_commands.txt"
    $criticalCommands = @(Get-DataLines -Path $criticalPath | ForEach-Object { $_.Text.Trim().ToLowerInvariant() })

    foreach ($command in $criticalCommands) {
        if ($allHandled -notcontains $command) {
            Add-AuditError "Comando critico sem comparacao de handler: $command"
        }
        if ($commandTests -notcontains $command) {
            Add-AuditError "Comando critico sem cobertura em /testarcomandos: $command"
        }
    }

    foreach ($command in $policeHandled) {
        if ($policeDirect -notcontains $command) {
            Add-AuditError "Comando policial sem rota direta Dispatch_IsPoliceCommand: $command"
        }
    }
    foreach ($command in $crimeHandled) {
        if ($crimeDirect -notcontains $command) {
            Add-AuditError "Comando criminal sem rota direta Dispatch_IsCrimeCommand: $command"
        }
    }

    Write-Host ("[AUDIT] roteador comandos: {0} handlers, {1} policiais diretos, {2} criminais diretos" -f $allHandled.Count, $policeDirect.Count, $crimeDirect.Count)
}

function Get-HelpExposedCommands {
    $commands = New-Object System.Collections.Generic.List[string]
    $adminPath = Join-Path $RootDir "include\core\admin.inc"

    foreach ($line in Get-Content -LiteralPath $adminPath) {
        if ($line -notmatch 'Help_AddLine\s*\(') { continue }

        foreach ($quoted in [regex]::Matches($line, '"([^"]*)"')) {
            foreach ($command in [regex]::Matches($quoted.Groups[1].Value, '(?<![A-Za-z0-9_])/[A-Za-z0-9_]+')) {
                $commands.Add($command.Value.ToLowerInvariant()) | Out-Null
            }
        }
    }

    return $commands | Sort-Object -Unique
}

function Test-HelpCommandsHaveHandlers {
    $commands = @(Get-HelpExposedCommands)

    foreach ($command in $commands) {
        $pattern = 'strcmp\s*\(\s*command\s*,\s*"' + [regex]::Escape($command) + '"\s*,\s*true\s*\)\s*==\s*0'
        if ($script:AllSourceText -notmatch $pattern) {
            Add-AuditError "Comando exposto na ajuda/menu sem handler real: $command"
        }
    }

    Write-Host ("[AUDIT] comandos expostos na ajuda/menu: {0} comandos conferidos" -f $commands.Count)
}

function Get-HelpCommandSegments {
    param([string]$Text)

    if ($Text -notmatch '^\s*/[A-Za-z0-9_]+') {
        return @()
    }

    if ($Text.Contains(",")) {
        return @($Text -split '\s*,\s*' | Where-Object { $_.Trim() -match '^/[A-Za-z0-9_]+' })
    }

    $matches = @([regex]::Matches($Text, '/[A-Za-z0-9_]+'))
    if ($matches.Count -eq 0) { return @() }

    $segments = New-Object System.Collections.Generic.List[string]
    for ($i = 0; $i -lt $matches.Count; $i++) {
        $start = $matches[$i].Index
        $end = if ($i + 1 -lt $matches.Count) { $matches[$i + 1].Index } else { $Text.Length }
        $segments.Add($Text.Substring($start, $end - $start).Trim()) | Out-Null
    }
    return $segments
}

function Get-HelpCommandKey {
    param([string]$Text)

    $match = [regex]::Match($Text, '/[A-Za-z0-9_]+')
    if ($match.Success) { return $match.Value.ToLowerInvariant() }
    return ""
}

function Test-HelpCommandsAlphabetical {
    $adminPath = Join-Path $RootDir "include\core\admin.inc"
    $script:HelpAlphaBlock = New-Object System.Collections.Generic.List[object]
    $lineNo = 0
    $checked = 0

    function Flush-HelpBlock {
        if ($script:HelpAlphaBlock.Count -gt 1) {
            $allCommandFirst = $true
            foreach ($item in $script:HelpAlphaBlock) {
                if ([string]::IsNullOrWhiteSpace($item.Key)) {
                    $allCommandFirst = $false
                    break
                }
            }
            if ($allCommandFirst) {
                for ($i = 1; $i -lt $script:HelpAlphaBlock.Count; $i++) {
                    if ([string]::Compare($script:HelpAlphaBlock[$i - 1].Key, $script:HelpAlphaBlock[$i].Key, $true) -gt 0) {
                        Add-AuditError "Ajuda fora de ordem alfabetica: $($script:HelpAlphaBlock[$i - 1].Key) antes de $($script:HelpAlphaBlock[$i].Key) na linha $($script:HelpAlphaBlock[$i].Line)"
                    }
                }
            }
        }
        $script:HelpAlphaBlock.Clear()
    }

    foreach ($line in Get-Content -LiteralPath $adminPath) {
        $lineNo++
        if ($line -match '^\s*Help_AddLine\s*\(') {
            $quoted = @([regex]::Matches($line, '"([^"]*)"') | ForEach-Object { $_.Groups[1].Value })
            if ($quoted.Count -gt 0) {
                foreach ($index in 0..($quoted.Count - 1)) {
                    if ($index -gt 0 -and $quoted[0] -match '^\s*/') { continue }
                    $segments = @(Get-HelpCommandSegments -Text $quoted[$index])
                    for ($i = 1; $i -lt $segments.Count; $i++) {
                        $previous = Get-HelpCommandKey $segments[$i - 1]
                        $current = Get-HelpCommandKey $segments[$i]
                        if ([string]::Compare($previous, $current, $true) -gt 0) {
                            Add-AuditError "Aliases do /ajuda fora de ordem alfabetica na linha ${lineNo}: $previous antes de $current"
                        }
                    }
                }

                $key = if ($quoted[0] -match '^\s*/') { Get-HelpCommandKey $quoted[0] } else { "" }
                $script:HelpAlphaBlock.Add([pscustomobject]@{ Key = $key; Line = $lineNo }) | Out-Null
                $checked++
            }
        }
        else {
            Flush-HelpBlock
        }
    }
    Flush-HelpBlock

    Write-Host ("[AUDIT] ordem alfabetica do /ajuda: {0} linhas conferidas" -f $checked)
}

function Test-MenuDialogHeaders {
    $adminPath = Join-Path $RootDir "include\core\admin.inc"
    $adminText = Get-Content -Raw -LiteralPath $adminPath

    if ($adminText -match 'DIALOG_MENU_MAIN\s*,\s*DIALOG_STYLE_TABLIST_HEADERS') {
        Add-AuditError "Menu principal usa TABLIST_HEADERS; isso pode deslocar listitem em alguns clientes"
    }
    if ($adminText -match 'format\s*\(\s*list\s*,\s*sizeof\s*\(\s*list\s*\)\s*,\s*"Menu\\tAcao\\n"') {
        Add-AuditError "Menu principal contem cabecalho selecionavel Menu\\tAcao"
    }
    if ($adminText -match 'format\s*\(\s*list\s*,\s*sizeof\s*\(\s*list\s*\)\s*,\s*"Acao\\tPermissao\\n"') {
        Add-AuditError "Menu staff contem cabecalho selecionavel Acao\\tPermissao"
    }

    Write-Host "[AUDIT] menu dialogs: cabecalhos selecionaveis conferidos"
}

function Test-MapObjects {
    $path = Join-Path $RootDir "scriptfiles\map_objects.txt"
    $lines = Get-DataLines -Path $path
    $max = Get-DefineInt -Name "MAX_MAP_OBJECTS" -Default 500
    if ($lines.Count -gt $max) {
        Add-AuditError "map_objects.txt excede MAX_MAP_OBJECTS: $($lines.Count)/$max"
    }

    $seen = @{}
    foreach ($item in $lines) {
        $tokens = $item.Text.Split("|") | ForEach-Object { $_.Trim() }
        if ($tokens.Count -lt 18) {
            Add-AuditError "map_objects.txt linha $($item.Line): esperado pelo menos 18 campos, veio $($tokens.Count)"
            continue
        }

        if (-not (Test-IntText $tokens[0]) -or @("0", "1") -notcontains $tokens[0]) {
            Add-AuditError "map_objects.txt linha $($item.Line): type invalido '$($tokens[0])'"
        }
        if (-not (Test-IntText $tokens[1]) -or -not (Test-NumberRange ([int]$tokens[1]) 1 20000)) {
            Add-AuditError "map_objects.txt linha $($item.Line): model invalido '$($tokens[1])'"
        }

        foreach ($idx in 2..13) {
            if (-not (Test-FloatText $tokens[$idx])) {
                Add-AuditError "map_objects.txt linha $($item.Line): campo numerico invalido '$($tokens[$idx])'"
            }
        }
        foreach ($idx in 2..4) {
            if ((Test-FloatText $tokens[$idx]) -and -not (Test-NumberRange ([double]$tokens[$idx]) -10000 10000)) {
                Add-AuditError "map_objects.txt linha $($item.Line): coordenada fora da faixa '$($tokens[$idx])'"
            }
        }
        if ((Test-FloatText $tokens[14]) -and -not (Test-NumberRange ([double]$tokens[14]) 0.1 200)) {
            Add-AuditError "map_objects.txt linha $($item.Line): range fora da faixa '$($tokens[14])'"
        }
        if ((Test-FloatText $tokens[15]) -and -not (Test-NumberRange ([double]$tokens[15]) 0.01 50)) {
            Add-AuditError "map_objects.txt linha $($item.Line): speed fora da faixa '$($tokens[15])'"
        }
        foreach ($idx in 16..17) {
            if (-not (Test-IntText $tokens[$idx]) -or -not (Test-NumberRange ([int]$tokens[$idx]) 0 65535)) {
                Add-AuditError "map_objects.txt linha $($item.Line): interior/world invalido '$($tokens[$idx])'"
            }
        }
        if ($tokens.Count -ge 20) {
            $jobMax = Get-DefineInt -Name "JOB_MAX_ID" -Default 29
            if (-not (Test-IntText $tokens[19]) -or -not (Test-NumberRange ([int]$tokens[19]) 0 $jobMax)) {
                Add-AuditError "map_objects.txt linha $($item.Line): job invalido '$($tokens[19])'"
            }
        }

        $key = "{0}|{1}|{2}|{3}|{4}" -f $tokens[0], $tokens[1], $tokens[2], $tokens[3], $tokens[4]
        if ($seen.ContainsKey($key)) {
            Add-AuditWarning "map_objects.txt linha $($item.Line): objeto duplicado por posicao/modelo (primeiro na linha $($seen[$key]))"
        }
        else {
            $seen[$key] = $item.Line
        }
    }
    Write-Host ("[AUDIT] map_objects: {0} linhas conferidas" -f $lines.Count)
}

function Test-JobVehicles {
    $path = Join-Path $RootDir "scriptfiles\job_vehicles.txt"
    $lines = Get-DataLines -Path $path
    $max = Get-DefineInt -Name "MAX_JOB_CONFIG_VEHICLES" -Default 200
    $jobMax = Get-DefineInt -Name "JOB_MAX_ID" -Default 29
    if ($lines.Count -gt $max) {
        Add-AuditError "job_vehicles.txt excede MAX_JOB_CONFIG_VEHICLES: $($lines.Count)/$max"
    }

    $seen = @{}
    foreach ($item in $lines) {
        $tokens = $item.Text.Split("|") | ForEach-Object { $_.Trim() }
        if ($tokens.Count -lt 11) {
            Add-AuditError "job_vehicles.txt linha $($item.Line): esperado 11 campos, veio $($tokens.Count)"
            continue
        }

        if (-not (Test-IntText $tokens[0]) -or -not (Test-NumberRange ([int]$tokens[0]) 1 $jobMax)) {
            Add-AuditError "job_vehicles.txt linha $($item.Line): job invalido '$($tokens[0])'"
        }
        if (-not (Test-IntText $tokens[1]) -or -not (Test-NumberRange ([int]$tokens[1]) 400 611)) {
            Add-AuditError "job_vehicles.txt linha $($item.Line): modelo de veiculo invalido '$($tokens[1])'"
        }
        foreach ($idx in 2..5) {
            if (-not (Test-FloatText $tokens[$idx])) {
                Add-AuditError "job_vehicles.txt linha $($item.Line): campo numerico invalido '$($tokens[$idx])'"
            }
        }
        foreach ($idx in 2..4) {
            if ((Test-FloatText $tokens[$idx]) -and -not (Test-NumberRange ([double]$tokens[$idx]) -10000 10000)) {
                Add-AuditError "job_vehicles.txt linha $($item.Line): coordenada fora da faixa '$($tokens[$idx])'"
            }
        }
        foreach ($idx in 6..7) {
            if (-not (Test-IntText $tokens[$idx]) -or -not (Test-NumberRange ([int]$tokens[$idx]) -1 255)) {
                Add-AuditError "job_vehicles.txt linha $($item.Line): cor invalida '$($tokens[$idx])'"
            }
        }
        if (-not (Test-IntText $tokens[8]) -or -not (Test-NumberRange ([int]$tokens[8]) 0 100)) {
            Add-AuditError "job_vehicles.txt linha $($item.Line): fuel invalido '$($tokens[8])'"
        }
        foreach ($idx in 9..10) {
            if (-not (Test-IntText $tokens[$idx]) -or -not (Test-NumberRange ([int]$tokens[$idx]) 0 65535)) {
                Add-AuditError "job_vehicles.txt linha $($item.Line): interior/world invalido '$($tokens[$idx])'"
            }
        }

        $key = "{0}|{1}|{2}|{3}|{4}" -f $tokens[0], $tokens[1], $tokens[2], $tokens[3], $tokens[4]
        if ($seen.ContainsKey($key)) {
            Add-AuditWarning "job_vehicles.txt linha $($item.Line): veiculo duplicado por job/modelo/posicao (primeiro na linha $($seen[$key]))"
        }
        else {
            $seen[$key] = $item.Line
        }
    }
    Write-Host ("[AUDIT] job_vehicles: {0} linhas conferidas" -f $lines.Count)
}

function Test-Radars {
    $path = Join-Path $RootDir "scriptfiles\radares.txt"
    $lines = Get-DataLines -Path $path
    foreach ($item in $lines) {
        $tokens = Split-SpaceTokens $item.Text
        if ($tokens.Count -lt 5) {
            Add-AuditError "radares.txt linha $($item.Line): esperado 5 campos, veio $($tokens.Count)"
            continue
        }
        foreach ($idx in 0..2) {
            if (-not (Test-FloatText $tokens[$idx])) {
                Add-AuditError "radares.txt linha $($item.Line): coordenada invalida '$($tokens[$idx])'"
            }
            elseif (-not (Test-NumberRange ([double]$tokens[$idx]) -10000 10000)) {
                Add-AuditError "radares.txt linha $($item.Line): coordenada fora da faixa '$($tokens[$idx])'"
            }
        }
        if (-not (Test-IntText $tokens[3]) -or -not (Test-NumberRange ([int]$tokens[3]) 20 250)) {
            Add-AuditError "radares.txt linha $($item.Line): limite invalido '$($tokens[3])'"
        }
        if (-not (Test-IntText $tokens[4]) -or -not (Test-NumberRange ([int]$tokens[4]) 0 200)) {
            Add-AuditError "radares.txt linha $($item.Line): streetid invalido '$($tokens[4])'"
        }
    }
    Write-Host ("[AUDIT] radares: {0} linhas conferidas" -f $lines.Count)
}

function Test-PropertyFiles {
    $dir = Join-Path $RootDir "scriptfiles\properties"
    if (-not (Test-Path -LiteralPath $dir)) {
        Add-AuditError "Diretorio obrigatorio ausente: $dir"
        return
    }

    $required = @("banks.txt", "businesses.txt", "houses.txt", "interiors.txt", "police.txt")
    foreach ($name in $required) {
        $path = Join-Path $dir $name
        $lines = Get-DataLines -Path $path
        if ($lines.Count -eq 0) {
            Add-AuditError "properties\$name sem linhas de dados"
            continue
        }

        $seen = @{}
        foreach ($item in $lines) {
            if ($name -eq "interiors.txt") {
                $tokens = Split-SpaceTokens $item.Text
                if ($tokens.Count -lt 6) {
                    Add-AuditError "properties\$name linha $($item.Line): esperado pelo menos 6 campos, veio $($tokens.Count)"
                    continue
                }
                if (-not (Test-IntText $tokens[0])) {
                    Add-AuditError "properties\$name linha $($item.Line): ID invalido '$($tokens[0])'"
                }
                elseif ($seen.ContainsKey($tokens[0])) {
                    Add-AuditError "properties\$name linha $($item.Line): ID duplicado '$($tokens[0])' (primeiro na linha $($seen[$tokens[0]]))"
                }
                else {
                    $seen[$tokens[0]] = $item.Line
                }
                if (-not (Test-IntText $tokens[1]) -or -not (Test-NumberRange ([int]$tokens[1]) 0 255)) {
                    Add-AuditError "properties\$name linha $($item.Line): interior invalido '$($tokens[1])'"
                }
                foreach ($idx in 2..5) {
                    if (-not (Test-FloatText $tokens[$idx])) {
                        Add-AuditError "properties\$name linha $($item.Line): numero invalido '$($tokens[$idx])'"
                    }
                }
                continue
            }

            $tokens = Split-CsvTokens $item.Text
            if ($tokens.Count -lt 7) {
                Add-AuditError "properties\$name linha $($item.Line): esperado pelo menos 7 campos, veio $($tokens.Count)"
                continue
            }
            if (-not (Test-IntText $tokens[0]) -or -not (Test-NumberRange ([int]$tokens[0]) 1 20000)) {
                Add-AuditError "properties\$name linha $($item.Line): model invalido '$($tokens[0])'"
            }
            foreach ($idx in 1..4) {
                if (-not (Test-FloatText $tokens[$idx])) {
                    Add-AuditError "properties\$name linha $($item.Line): numero invalido '$($tokens[$idx])'"
                }
            }
            if ((Test-FloatText $tokens[4]) -and -not (Test-NumberRange ([double]$tokens[4]) -360 360)) {
                Add-AuditError "properties\$name linha $($item.Line): angulo invalido '$($tokens[4])'"
            }
            foreach ($idx in 5..6) {
                if (-not (Test-IntText $tokens[$idx]) -or -not (Test-NumberRange ([int]$tokens[$idx]) 0 65535)) {
                    Add-AuditError "properties\$name linha $($item.Line): campo inteiro invalido '$($tokens[$idx])'"
                }
            }

            $key = "{0}|{1}|{2}|{3}" -f $tokens[0], $tokens[1], $tokens[2], $tokens[3]
            if ($seen.ContainsKey($key)) {
                Add-AuditError "properties\$name linha $($item.Line): local duplicado (primeiro na linha $($seen[$key]))"
            }
            else {
                $seen[$key] = $item.Line
            }
        }
        Write-Host ("[AUDIT] properties\{0}: {1} linhas conferidas" -f $name, $lines.Count)
    }
}

$script:SourceFiles = @(Get-SourceFiles)
$script:AllSourceText = Read-AllSourceText

Test-TimersHavePublic
Test-DialogIdsUnique
Test-ServerInfo
Test-CriticalCallbacks
Test-CriticalCommands
Test-DispatcherDuplicateCommandRoutes
Test-CommandRouterCoverage
Test-HelpCommandsHaveHandlers
Test-HelpCommandsAlphabetical
Test-MenuDialogHeaders
Test-MapObjects
Test-JobVehicles
Test-Radars
Test-PropertyFiles

foreach ($warning in $warnings) {
    Write-Host ("[AUDIT][WARN] {0}" -f $warning)
}

if ($errors.Count -gt 0) {
    Write-Host "AUDIT_BLOQUEADO"
    foreach ($errorItem in $errors) {
        Write-Host (" - {0}" -f $errorItem)
    }
    exit 1
}

Write-Host "AUDIT_OK"
exit 0

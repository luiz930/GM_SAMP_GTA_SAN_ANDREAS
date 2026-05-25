$ErrorActionPreference = "Stop"

$root = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)
$recordingDir = Join-Path $root "npcmodes\recordings"

function Write-OnFootRecording {
    param(
        [Parameter(Mandatory = $true)][string]$Name,
        [Parameter(Mandatory = $true)][object[]]$Points,
        [double]$Speed = 0.72
    )

    $path = Join-Path $recordingDir ($Name + ".rec")
    $stream = [System.IO.File]::Open($path, [System.IO.FileMode]::Create, [System.IO.FileAccess]::Write, [System.IO.FileShare]::None)
    $writer = [System.IO.BinaryWriter]::new($stream)
    try {
        $writer.Write([int32]1000)
        $writer.Write([int32]2)

        $time = 100
        $frameMs = 50

        for ($i = 0; $i -lt ($Points.Count - 1); $i++) {
            $from = $Points[$i]
            $to = $Points[$i + 1]
            $dx = [double]$to[0] - [double]$from[0]
            $dy = [double]$to[1] - [double]$from[1]
            $dz = [double]$to[2] - [double]$from[2]
            $distance = [Math]::Sqrt(($dx * $dx) + ($dy * $dy) + ($dz * $dz))
            if ($distance -le 0.01) {
                continue
            }

            $steps = [Math]::Max(2, [int][Math]::Ceiling($distance / ($Speed * ($frameMs / 1000.0))))
            $angle = [Math]::Atan2($dx, $dy)
            $qw = [single][Math]::Cos($angle / 2.0)
            $qz = [single][Math]::Sin($angle / 2.0)
            $vx = [single](($dx / $steps) * 0.40)
            $vy = [single](($dy / $steps) * 0.40)
            $vz = [single](($dz / $steps) * 0.40)

            for ($step = 0; $step -lt $steps; $step++) {
                $t = [double]$step / [double]$steps
                $x = [single]([double]$from[0] + ($dx * $t))
                $y = [single]([double]$from[1] + ($dy * $t))
                $z = [single]([double]$from[2] + ($dz * $t))

                $writer.Write([int32]$time)
                $writer.Write([int16]0)
                $writer.Write([int16]-128)
                $writer.Write([uint16]1024)
                $writer.Write($x)
                $writer.Write($y)
                $writer.Write($z)
                $writer.Write($qw)
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write($qz)
                $writer.Write([byte]100)
                $writer.Write([byte]0)
                $writer.Write([byte]0)
                $writer.Write([byte]0)
                $writer.Write([single]($vx * 0.65))
                $writer.Write([single]($vy * 0.65))
                $writer.Write([single]($vz * 0.65))
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write([uint16]0)
                $writer.Write([int32]0)
                $time += $frameMs
            }

            for ($pause = 0; $pause -lt 12; $pause++) {
                $writer.Write([int32]$time)
                $writer.Write([int16]0)
                $writer.Write([int16]0)
                $writer.Write([uint16]0)
                $writer.Write([single]$to[0])
                $writer.Write([single]$to[1])
                $writer.Write([single]$to[2])
                $writer.Write($qw)
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write($qz)
                $writer.Write([byte]100)
                $writer.Write([byte]0)
                $writer.Write([byte]0)
                $writer.Write([byte]0)
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write([single]0)
                $writer.Write([uint16]0)
                $writer.Write([int32]0)
                $time += $frameMs
            }
        }
    }
    finally {
        $writer.Close()
        $stream.Close()
    }
}

function Set-DriverRecordingVehicleId {
    param(
        [Parameter(Mandatory = $true)][string]$Name,
        [Parameter(Mandatory = $true)][int]$VehicleId
    )

    $path = Join-Path $recordingDir ($Name + ".rec")
    if (-not (Test-Path -LiteralPath $path)) {
        throw "Gravacao de motorista nao encontrada: $path"
    }

    $bytes = [System.IO.File]::ReadAllBytes($path)
    $frameSize = 67
    if ($bytes.Length -lt 75 -or (($bytes.Length - 8) % $frameSize) -ne 0) {
        throw "Formato inesperado da gravacao de motorista: $Name ($($bytes.Length) bytes)"
    }

    $vehicleBytes = [BitConverter]::GetBytes([int32]$VehicleId)
    for ($offset = 8; $offset -lt $bytes.Length; $offset += $frameSize) {
        [Array]::Copy($vehicleBytes, 0, $bytes, $offset + 4, 4)
    }
    [System.IO.File]::WriteAllBytes($path, $bytes)
}

$routes = @{
    "ls_ped_cityhall"      = @(@(1472.0,-1726.0,13.5469), @(1504.0,-1726.0,13.5469), @(1512.0,-1742.0,13.5469), @(1504.0,-1726.0,13.5469), @(1472.0,-1726.0,13.5469))
    "ls_ped_cityhall_2"    = @(@(1448.0,-1754.0,13.5469), @(1442.0,-1778.0,13.5469), @(1457.0,-1794.0,13.5469), @(1442.0,-1778.0,13.5469), @(1448.0,-1754.0,13.5469))
    "ls_ped_hospital"      = @(@(1177.3,-1328.1,14.0470), @(1192.0,-1338.0,14.0470), @(1203.0,-1325.0,14.0470), @(1192.0,-1338.0,14.0470), @(1177.3,-1328.1,14.0470))
    "ls_ped_idlewood"      = @(@(1837.2,-1684.5,13.5469), @(1818.0,-1684.5,13.5469), @(1818.0,-1706.0,13.5469), @(1818.0,-1684.5,13.5469), @(1837.2,-1684.5,13.5469))
    "ls_ped_prf"           = @(@(1422.9,-952.1,36.1640), @(1422.6,-955.7,36.1885), @(1428.1,-964.8,37.0835), @(1422.6,-955.7,36.1885), @(1422.9,-952.1,36.1640))
    "ls_ped_bank"          = @(@(1455.0,-1012.0,26.8438), @(1442.0,-1012.0,26.8438), @(1442.0,-1025.0,26.8438), @(1442.0,-1012.0,26.8438), @(1455.0,-1012.0,26.8438))
    "ls_ped_detran"        = @(@(1026.0,-1028.0,32.1016), @(1012.0,-1028.0,32.1016), @(1012.0,-1044.0,32.1016), @(1012.0,-1028.0,32.1016), @(1026.0,-1028.0,32.1016))
    "ls_ped_police_civil"  = @(@(1522.0,-1678.0,13.5469), @(1538.0,-1678.0,13.5469), @(1544.0,-1692.0,13.5469), @(1538.0,-1678.0,13.5469), @(1522.0,-1678.0,13.5469))
    "ls_ped_pf"            = @(@(1386.0,-1701.0,13.5395), @(1374.0,-1701.0,13.5395), @(1374.0,-1720.0,13.5395), @(1374.0,-1701.0,13.5395), @(1386.0,-1701.0,13.5395))
    "ls_ped_penal"         = @(@(1591.0,-1638.0,13.5469), @(1608.0,-1638.0,13.5469), @(1608.0,-1655.0,13.5469), @(1608.0,-1638.0,13.5469), @(1591.0,-1638.0,13.5469))
    "ls_ped_fire"          = @(@(1754.0,-1454.0,13.5313), @(1776.0,-1454.0,13.5313), @(1776.0,-1470.0,13.5313), @(1776.0,-1454.0,13.5313), @(1754.0,-1454.0,13.5313))
    "ls_ped_terminal"      = @(@(1804.0,-1900.0,13.5748), @(1794.0,-1908.0,13.5748), @(1794.0,-1930.0,13.5748), @(1794.0,-1908.0,13.5748), @(1804.0,-1900.0,13.5748))
    "ls_ped_pier"          = @(@(386.0,-2089.0,7.8359), @(407.0,-2089.0,7.8359), @(407.0,-2114.0,7.8359), @(407.0,-2089.0,7.8359), @(386.0,-2089.0,7.8359))
    "ls_ped_mechanic"      = @(@(1036.0,-1031.0,32.1016), @(1058.0,-1031.0,32.1016), @(1058.0,-1046.0,32.1016), @(1058.0,-1031.0,32.1016), @(1036.0,-1031.0,32.1016))
    "ls_ped_gas"           = @(@(1924.0,-1776.0,13.5469), @(1948.0,-1776.0,13.5469), @(1948.0,-1792.0,13.5469), @(1948.0,-1776.0,13.5469), @(1924.0,-1776.0,13.5469))
    "ls_ped_store"         = @(@(1363.0,-1280.0,13.5469), @(1382.0,-1280.0,13.5469), @(1382.0,-1300.0,13.5469), @(1382.0,-1280.0,13.5469), @(1363.0,-1280.0,13.5469))
}

foreach ($name in ($routes.Keys | Sort-Object)) {
    Write-OnFootRecording -Name $name -Points $routes[$name]
}

$driverVehicleIds = @{
    "ls_car_cityhall" = 1
    "ls_car_hospital" = 2
    "ls_car_idlewood" = 3
    "ls_car_prf" = 4
}

foreach ($name in ($driverVehicleIds.Keys | Sort-Object)) {
    Set-DriverRecordingVehicleId -Name $name -VehicleId $driverVehicleIds[$name]
}

Get-ChildItem -LiteralPath $recordingDir -Filter "ls_ped*.rec" |
    Sort-Object Name |
    Select-Object Name, Length, LastWriteTime

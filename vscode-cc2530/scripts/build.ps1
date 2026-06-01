param(
  [ValidateSet("CC2530F32", "CC2530F64", "CC2530F128", "CC2530F256")]
  [string]$Device = "CC2530F256",

  [switch]$Clean
)

$ErrorActionPreference = "Stop"

$workspaceRoot = Split-Path -Parent $PSScriptRoot
$srcDir = Join-Path $workspaceRoot "src"
$buildDir = Join-Path $workspaceRoot "build"
$objDir = Join-Path $buildDir "obj"

$iarRoot = "C:\Program Files (x86)\IAR Systems\Embedded Workbench 6.0 Evaluation"
$icc = Join-Path $iarRoot "8051\bin\icc8051.exe"
$a8051 = Join-Path $iarRoot "8051\bin\a8051.exe"
$xlink = Join-Path $iarRoot "8051\bin\xlink.exe"
$xcl = Join-Path $iarRoot ("8051\config\devices\Texas Instruments\lnk51ew_{0}.xcl" -f $Device.ToLower())
$iarInc = Join-Path $iarRoot "8051\inc"
$runtimeLib = Join-Path $iarRoot "8051\lib\clib\cl-pli-nsid-1e16x01.r51"

foreach ($tool in @($icc, $a8051, $xlink, $xcl, $iarInc, $runtimeLib)) {
  if (-not (Test-Path $tool)) {
    throw "Missing required IAR path: $tool"
  }
}

if ($Clean -and (Test-Path $buildDir)) {
  Remove-Item -LiteralPath $buildDir -Recurse -Force
}

New-Item -ItemType Directory -Force -Path $objDir | Out-Null

$sources = Get-ChildItem -Path $srcDir -Filter *.c | Sort-Object Name
$asmSources = Get-ChildItem -Path $srcDir -Filter *.s51 | Sort-Object Name
if ((-not $sources) -and (-not $asmSources)) {
  throw "No C sources found in $srcDir"
}

$objects = @()
foreach ($src in $sources) {
  $obj = Join-Path $objDir ($src.BaseName + ".r51")
  $dep = Join-Path $objDir ($src.BaseName + ".d")

  & $icc `
    "--core=plain" `
    "--code_model=near" `
    "--data_model=small" `
    "--clib" `
    "--debug" `
    "--silent" `
    "--dependencies=m" $dep `
    "-I$iarInc" `
    "-I$srcDir" `
    "-o" $obj `
    $src.FullName

  if ($LASTEXITCODE -ne 0) {
    throw "Compilation failed: $($src.Name)"
  }

  $objects += $obj
}

foreach ($src in $asmSources) {
  $obj = Join-Path $objDir ($src.BaseName + ".r51")

  & $a8051 `
    $src.FullName `
    "-r" `
    "-o" $obj

  if ($LASTEXITCODE -ne 0) {
    throw "Assembly failed: $($src.Name)"
  }

  $objects += $obj
}

$outDebug = Join-Path $buildDir "app.d51"
$outHex = Join-Path $buildDir "app.hex"
$mapDir = Join-Path $buildDir "map"
New-Item -ItemType Directory -Force -Path $mapDir | Out-Null

& $xlink `
  "-f" $xcl `
  "-D_IDATA_STACK_SIZE=0x90" `
  "-D_PDATA_STACK_SIZE=0x90" `
  "-D_XDATA_STACK_SIZE=0x0EFF" `
  "-D_EXTENDED_STACK_START=0x002000" `
  "-D_EXTENDED_STACK_SIZE=0x03FF" `
  "-D_XDATA_HEAP_SIZE=0x0800" `
  "-D_NR_OF_VIRTUAL_REGISTERS=0x20" `
  "-I$($iarRoot)\8051\lib" `
  "-I$($iarRoot)\8051\lib\clib" `
  "-l" (Join-Path $mapDir "app") `
  "-xms" `
  "-Ointel-standard=$outHex" `
  "-rt" `
  "-o" $outDebug `
  $objects `
  $runtimeLib

if ($LASTEXITCODE -ne 0) {
  throw "Link failed"
}

Write-Output "Build succeeded"
Write-Output "Device: $Device"
Write-Output "Debug image: $outDebug"
Write-Output "HEX image: $outHex"

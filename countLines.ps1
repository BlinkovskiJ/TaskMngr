$linecount = 0

$files = Get-ChildItem -Recurse -Include *.cpp, *.hpp -File

foreach ($file in $files) {
    $lines = (Get-Content $file | Measure-Object -Line).Lines
    $linecount += $lines
}

Write-Host "Total lines of code: $linecount"

$totalTime = 0

For($i=0;$i -lt 100;$i++) {
    $time = Measure-Command {./x64-release/libtest}
    $totalTime += $time.TotalMilliseconds
}

Write-Output ($totalTime / 100)
Add-Type -AssemblyName System.Windows.Forms
$note = New-Object System.Windows.Forms.NotifyIcon
$path = (Get-Process -id $pid).Path
$note.Icon = [System.Drawing.Icon]::ExtractAssociatedIcon($path)
$note.BalloonTipIcon = [System.Windows.Forms.ToolTipIcon]::Warning
$note.BalloonTipText = 'Build process finished'
$note.BalloonTipTitle = "Done"
$note.Visible = $true
$note.ShowBalloonTip(10000)

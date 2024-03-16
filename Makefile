SHELL := powershell.exe
.SHELLFLAGS := -NoProfile -Command

compiler = cl
cflags = /EHsc /Zi
target = target.exe
output = artifacts/
header = header

command := powershell "(Get-ChildItem source -Include *.c, *.cpp -Recurse | Resolve-Path -Relative) -join ' '"

rebuild : clean build

.ONESHELL:
build :
	$(eval result = $(shell $(command)))
	$(compiler) $(cflags) /Fo$(output) /Fe:$(target) $(result) /I $(header)

clean : 
	@Write-Output "Cleaning build directory"
	Remove-Item "$(output)*.obj"
	@Write-Output "Cleaning executables"
	Remove-Item "*.exe"

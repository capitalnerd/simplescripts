@echo off
set /p image_url="Enter Path: "
for /f "tokens=*" %%F in ("%image_url%") do set "filename=%%~nxF"
curl "%image_url%" -o "%filename%"

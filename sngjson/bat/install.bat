@echo off
xcopy /Y /D ..\x64\Debug\sngjsond.lib ..\lib
xcopy /Y /D ..\x64\Release\sngjson.lib ..\lib
xcopy /Y /D ..\lib\*.* ..\..\lib
xcopy /Y /D ..\bin\*.* ..\..\bin

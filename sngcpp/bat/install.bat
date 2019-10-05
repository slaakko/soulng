@echo off
xcopy /Y /D ..\x64\Debug\sngcppastd.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcppast.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcppastd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcppast.dll ..\bin

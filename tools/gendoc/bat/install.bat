@echo off
xcopy /Y /D ..\x64\Debug\gendocd.exe ..\..\..\bin
xcopy /Y /D ..\x64\Debug\gendochtmld.dll ..\..\..\bin
xcopy /Y /D ..\x64\Release\gendoc.exe ..\..\..\bin
xcopy /Y /D ..\x64\Release\gendochtml.dll ..\..\..\bin

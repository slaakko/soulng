@echo off
xcopy /Y /D ..\x64\Debug\sngcmastd.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcmast.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcmlexerd.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcmlexer.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcmparserd.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcmparser.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcmastd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcmast.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcmlexerd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcmlexer.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcmparserd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcmparser.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcmtesterd.exe ..\bin
xcopy /Y /D ..\x64\Release\sngcmtester.exe ..\bin
xcopy /Y /D ..\lib\*.* ..\..\lib
xcopy /Y /D ..\bin\*.* ..\..\bin

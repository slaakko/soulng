@echo off
xcopy /Y /D ..\x64\Debug\cmajorastd.lib ..\lib
xcopy /Y /D ..\x64\Release\cmajorast.lib ..\lib
xcopy /Y /D ..\x64\Debug\cmajorlexerd.lib ..\lib
xcopy /Y /D ..\x64\Release\cmajorlexer.lib ..\lib
xcopy /Y /D ..\x64\Debug\cmajorparserd.lib ..\lib
xcopy /Y /D ..\x64\Release\cmajorparser.lib ..\lib
xcopy /Y /D ..\x64\Debug\cmajorastd.dll ..\bin
xcopy /Y /D ..\x64\Release\cmajorast.dll ..\bin
xcopy /Y /D ..\x64\Debug\cmajorlexerd.dll ..\bin
xcopy /Y /D ..\x64\Release\cmajorlexer.dll ..\bin
xcopy /Y /D ..\x64\Debug\cmajorparserd.dll ..\bin
xcopy /Y /D ..\x64\Release\cmajorparser.dll ..\bin
xcopy /Y /D ..\x64\Debug\cmajortesterd.exe ..\bin
xcopy /Y /D ..\x64\Release\cmajortester.exe ..\bin
xcopy /Y /D ..\bin\*.* ..\..\..\bin

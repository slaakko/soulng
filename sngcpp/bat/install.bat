@echo off
xcopy /Y /D ..\x64\Debug\sngcppastd.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcppast.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcppastd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcppast.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcpplexerd.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcpplexer.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcpplexerd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcpplexer.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcppparserd.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcppparser.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcppparserd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcppparser.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcppsymbolsd.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcppsymbolsd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcppsymbols.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcppsymbols.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcppbinderd.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcppbinderd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcppbinder.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcppbinder.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcppppd.lib ..\lib
xcopy /Y /D ..\x64\Release\sngcpppp.lib ..\lib
xcopy /Y /D ..\x64\Debug\sngcppppd.dll ..\bin
xcopy /Y /D ..\x64\Release\sngcpppp.dll ..\bin
xcopy /Y /D ..\x64\Debug\sngcpppptesterd.exe ..\bin
xcopy /Y /D ..\x64\Release\sngcpppptester.exe ..\bin
xcopy /Y /D ..\x64\Debug\sngcppparsertesterd.exe ..\bin
xcopy /Y /D ..\x64\Release\sngcppparsertester.exe ..\bin
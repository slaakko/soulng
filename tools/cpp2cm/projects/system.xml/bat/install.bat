@echo off
cpp2cm -iv ..\system.xml.xml
xcopy /Y /D ..\parser\*.parser D:\work\cmajorm\cmajor\system\System.Xml
xcopy /Y /D ..\parser\*.spg D:\work\cmajorm\cmajor\system\System.Xml

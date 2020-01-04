@echo off
cpp2cm -iv ../system.xpath.xml
xcopy /Y /D ..\lexer\*.lexer D:\work\cmajorm\cmajor\system\System.XPath
xcopy /Y /D ..\parser\*.parser D:\work\cmajorm\cmajor\system\System.XPath
xcopy /Y /D ..\parser\*.spg D:\work\cmajorm\cmajor\system\System.XPath

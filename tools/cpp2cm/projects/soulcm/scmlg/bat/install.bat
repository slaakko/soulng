@echo off
cpp2cm -iv ../scmlg.xml
xcopy /Y /D ..\lexer\*.lexer D:\work\cmajorm\cmajor\projects\tools\soulcm\scmlg
xcopy /Y /D ..\parser\*.parser D:\work\cmajorm\cmajor\projects\tools\soulcm\scmlg
xcopy /Y /D ..\parser\*.spg D:\work\cmajorm\cmajor\projects\tools\soulcm\scmlg

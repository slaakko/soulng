@echo off
cpp2cm -iv ../scmpg.xml
xcopy /Y /D ..\lexer\*.lexer D:\work\cmajorm\cmajor\projects\tools\soulcm\scmpg
xcopy /Y /D ..\parser\*.parser D:\work\cmajorm\cmajor\projects\tools\soulcm\scmpg
xcopy /Y /D ..\parser\*.spg D:\work\cmajorm\cmajor\projects\tools\soulcm\scmpg

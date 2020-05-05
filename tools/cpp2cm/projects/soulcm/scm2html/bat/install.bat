@echo off
cpp2cm -iv ../scm2html.xml
xcopy /Y /D ..\lexer\*.lexer D:\work\cmajorm\cmajor\projects\tools\soulcm\scm2html
xcopy /Y /D ..\parser\*.parser D:\work\cmajorm\cmajor\projects\tools\soulcm\scm2html
xcopy /Y /D ..\parser\*.spg D:\work\cmajorm\cmajor\projects\tools\soulcm\scm2html

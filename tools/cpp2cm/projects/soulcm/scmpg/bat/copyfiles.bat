@echo off
xcopy /Y /D ..\lexer\*.cm ..\merge
xcopy /Y /D ..\parser\*.cm ..\merge
xcopy /Y /D ..\lexer\*.lexer ..\scmpg
xcopy /Y /D ..\parser\*.parser ..\scmpg
xcopy /Y /D ..\parser\*.spg ..\scmpg

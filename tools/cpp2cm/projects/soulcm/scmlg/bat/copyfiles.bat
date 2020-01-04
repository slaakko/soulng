@echo off
xcopy /Y /D ..\lexer\*.cm ..\merge
xcopy /Y /D ..\parser\*.cm ..\merge
xcopy /Y /D ..\lexer\*.lexer ..\scmlg
xcopy /Y /D ..\parser\*.parser ..\scmlg
xcopy /Y /D ..\parser\*.spg ..\scmlg

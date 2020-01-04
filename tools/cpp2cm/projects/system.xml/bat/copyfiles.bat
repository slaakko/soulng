@echo off
xcopy /Y /D ..\parser\*.cm ..\merge
xcopy /Y /D ..\parser\*.parser ..\build
xcopy /Y /D ..\parser\*.spg ..\build

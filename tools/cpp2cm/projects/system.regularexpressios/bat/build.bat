@echo off
scmlg -v ../lexer/RexLexer.lexer
xcopy /Y /D ..\lexer\*.cm ..\merge
xcopy /Y /D ..\lexer\*.lexer ..\build
scmpg -v ../parser/RexParser.spg
xcopy /Y /D ..\parser\*.cm ..\merge
xcopy /Y /D ..\parser\*.parser ..\build
xcopy /Y /D ..\parser\*.spg ..\build
cpp2cm -v ../system.regularexpressions.xml

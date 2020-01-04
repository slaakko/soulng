@echo off
scmlg -v ../lexer/XPathLexer.lexer
xcopy /Y /D ..\lexer\*.cm ..\merge
scmpg -v ../parser/XPathParser.spg
xcopy /Y /D ..\parser\*.cm ..\merge
xcopy /Y /D ..\lexer\*.lexer ..\build
xcopy /Y /D ..\parser\*.parser ..\build
xcopy /Y /D ..\parser\*.spg ..\build
cpp2cm -v ../system.xpath.xml

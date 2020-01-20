@echo off
scmlg -v ../lexer/LexerFileLexer.lexer
scmlg -v ../lexer/RegExLexer.lexer
scmpg -v ../lexer/Parsers.spg
xcopy /Y /D ..\lexer\*.cm ..\merge
cpp2cm -v ../scm2html.xml

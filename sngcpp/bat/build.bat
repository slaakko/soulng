@echo off
slg -v ..\lexer\CppLexer.lexer
spg -v ..\parser\CppParsers.spg
slg -v ..\pp\PPLexer.lexer
spg -v ..\pp\PPParser.spg
slg -v ..\pp\TextLexer.lexer

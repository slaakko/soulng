@echo off
slg -v ..\soulng\slg\LexerFileLexer.lexer
slg -v ..\soulng\slg\RegExLexer.lexer
slg -v ..\soulng\spg\ParserFileLexer.lexer
slg -v ..\soulng\spg\ProjectFileLexer.lexer
spg -v ..\soulng\slg\Parsers.spg
spg -v ..\soulng\spg\Parsers.spg

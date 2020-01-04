@echo off
soulngcm_slg -v ../lexer/LexerFileLexer.lexer
soulngcm_slg -v ../lexer/RegExLexer.lexer
soulngcm_spg -v ../parser/Parsers.spg
call copyfiles.bat
cpp2cm -v ../scmlg.xml

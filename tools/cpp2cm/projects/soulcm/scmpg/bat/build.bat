@echo off
soulngcm_slg -v ../lexer/ParserFileLexer.lexer
soulngcm_slg -v ../lexer/ProjectFileLexer.lexer
soulngcm_spg -v ../parser/Parsers.spg
call copyfiles.bat
cpp2cm -v ../scmpg.xml

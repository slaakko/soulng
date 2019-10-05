@echo off
slg -v ..\soulng\slg\LexerFileLexer.lexer
slg -v ..\soulng\slg\RegExLexer.lexer
slg -v ..\soulng\spg\ParserFileLexer.lexer
slg -v ..\soulng\spg\ProjectFileLexer.lexer
spg -v ..\soulng\slg\Parsers.spg
spg -v ..\soulng\spg\Parsers.spg
spg -v ..\sngxml\xml\XmlParser.spg
slg -v ..\sngxml\xpath\XPathLexer.lexer
spg -v ..\sngxml\xpath\XPathParser.spg
slg -v ..\soulng\rex\RexLexer.lexer
spg -v ..\soulng\rex\RexParser.spg

#	Makefile for soulng and tools
#	Run with nmake from Visual Studio 2019 x64 Native Tools Command Prompt

all: spg soulng cpplexer cppparser sngcpp20

spg: ..\bin\spgd.exe ..\bin\spg.exe soulng
	
..\bin\spgd.exe ..\bin\spg.exe: ..\soulng\spg\CppDeclarationParser.parser ..\soulng\spg\CppExpressionParser.parser ..\soulng\spg\CppIdentifierParser.parser \
..\soulng\spg\CppLiteralParser.parser ..\soulng\spg\CppStatementParser.parser ..\soulng\spg\ParserFileLexer.lexer ..\soulng\spg\ParserFileParser.parser \
..\soulng\spg\ProjectFileLexer.lexer ..\soulng\spg\ProjectFileParser.parser 
	slg -v ..\soulng\spg\ParserFileLexer.lexer
	slg -v ..\soulng\spg\ProjectFileLexer.lexer
	spg -v ..\soulng\spg\Parsers.spg

soulng:
	MSBuild -m -verbosity:minimal ..\soulng\soulng.sln -p:Configuration="Debug"
	snginst -v ..\soulng\x64\Debug\*.exe ..\soulng\x64\Debug\*.dll ..\bin
	snginst -v ..\soulng\x64\Debug\*.lib ..\lib
	MSBuild -m -verbosity:minimal ..\soulng\soulng.sln -p:Configuration="Release"
	snginst -v ..\soulng\x64\Release\*.exe ..\soulng\x64\Release\*.dll ..\bin
	snginst -v ..\soulng\x64\Release\*.lib ..\lib

sngcpp20: 
	MSBuild -m -verbosity:minimal ..\sngcpp20\sngcpp20.sln -p:Configuration="Debug"
	snginst -v ..\sngcpp20\x64\Debug\*.exe ..\sngcpp20\x64\Debug\*.dll ..\bin
	snginst -v ..\sngcpp20\x64\Debug\*.lib ..\lib
	MSBuild -m -verbosity:minimal ..\sngcpp20\sngcpp20.sln -p:Configuration="Release"
	snginst -v ..\sngcpp20\x64\Release\*.exe ..\sngcpp20\x64\Release\*.dll ..\bin
	snginst -v ..\sngcpp20\x64\Release\*.lib ..\lib
	
cpplexer: ..\bin\sngcpp20_lexerd.dll ..\bin\sngcpp20_lexer.dll sngcpp20
	
..\bin\sngcpp20_lexerd.dll ..\lib\sngcpp20_lexer.dll: ..\sngcpp20\lexer\CppLexer.lexer ..\sngcpp20\lexer\CppTokenLexer.lexer
	slg -v ..\sngcpp20\lexer\CppLexer.lexer
	slg -v ..\sngcpp20\lexer\CppTokenLexer.lexer

cppparser: ..\bin\sngcpp20_parserd.dll ..\bin\sngcpp20_parser.dll sngcpp20

..\bin\sngcpp20_parserd.dll ..\bin\sngcpp20_parser.dll: ..\sngcpp20\parser\AttributeParser.parser ..\sngcpp20\parser\ClassParser.parser ..\sngcpp20\parser\ConceptParser.parser ..\sngcpp20\parser\DeclarationParser.parser \
	..\sngcpp20\parser\EnumParser.parser ..\sngcpp20\parser\ExpressionParser.parser ..\sngcpp20\parser\FunctionParser.parser ..\sngcpp20\parser\GuardParser.parser \
	..\sngcpp20\parser\IdentifierParser.parser ..\sngcpp20\parser\InitializationParser.parser ..\sngcpp20\parser\LambdaParser.parser ..\sngcpp20\parser\LiteralParser.parser \
	..\sngcpp20\parser\ModuleParser.parser ..\sngcpp20\parser\SimpleTypeParser.parser ..\sngcpp20\parser\StatementParser.parser ..\sngcpp20\parser\TemplateParser.parser \
	..\sngcpp20\parser\TranslationUnitParser.parser ..\sngcpp20\parser\TypeParser.parser
	spg -v ..\sngcpp20\parser\CppParser.spg

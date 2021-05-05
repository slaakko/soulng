#	Makefile for soulng and tools
#	Run with nmake from Visual Studio 2019 x64 Native Tools Command Prompt

all: soulng cpplexer cppparser project

soulng:
	MSBuild -m -verbosity:minimal ..\soulng\soulng.sln -p:Configuration="Debug"
	MSBuild -m -verbosity:minimal ..\soulng\soulng.sln -p:Configuration="Release"
	install.bat

cpplexer: ..\bin\sngcpp20_lexerd.dll ..\bin\sngcpp20_lexer.dll
	
..\bin\sngcpp20_lexerd.dll ..\lib\sngcpp20_lexer.dll: ..\sngcpp20\lexer\CppLexer.lexer ..\sngcpp20\lexer\CppTokenLexer.lexer
	slg -v ..\sngcpp20\lexer\CppLexer.lexer
	slg -v ..\sngcpp20\lexer\CppTokenLexer.lexer
	MSBuild -m -verbosity:minimal ..\sngcpp20\sngcpp20.sln -p:Configuration="Debug"
	MSBuild -m -verbosity:minimal ..\sngcpp20\sngcpp20.sln -p:Configuration="Release"
	install.bat

cppparser: ..\bin\sngcpp20_parserd.dll ..\bin\sngcpp20_parser.dll

..\bin\sngcpp20_parserd.dll ..\bin\sngcpp20_parser.dll: ..\sngcpp20\parser\AttributeParser.parser ..\sngcpp20\parser\ClassParser.parser ..\sngcpp20\parser\ConceptParser.parser ..\sngcpp20\parser\DeclarationParser.parser \
	..\sngcpp20\parser\EnumParser.parser ..\sngcpp20\parser\ExpressionParser.parser ..\sngcpp20\parser\FunctionParser.parser ..\sngcpp20\parser\GuardParser.parser \
	..\sngcpp20\parser\IdentifierParser.parser ..\sngcpp20\parser\InitializationParser.parser ..\sngcpp20\parser\LambdaParser.parser ..\sngcpp20\parser\LiteralParser.parser \
	..\sngcpp20\parser\ModuleParser.parser ..\sngcpp20\parser\SimpleTypeParser.parser ..\sngcpp20\parser\StatementParser.parser ..\sngcpp20\parser\TemplateParser.parser \
	..\sngcpp20\parser\TranslationUnitParser.parser ..\sngcpp20\parser\TypeParser.parser
	spg -v ..\sngcpp20\parser\CppParser.spg
	MSBuild -m -verbosity:minimal ..\sngcpp20\sngcpp20.sln -p:Configuration="Debug"
	MSBuild -m -verbosity:minimal ..\sngcpp20\sngcpp20.sln -p:Configuration="Release"
	install.bat

project:
	MSBuild -m -verbosity:minimal ..\sngcpp20\sngcpp20.sln -p:Configuration="Debug"
	MSBuild -m -verbosity:minimal ..\sngcpp20\sngcpp20.sln -p:Configuration="Release"
	install.bat
	
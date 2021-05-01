#	Makefile for soulng
#	Run with nmake from Visual Studio 2019 x64 Native Tools Command Prompt

all: soulng sngcpp

soulng:
	MSBuild -m -verbosity:minimal ..\soulng\soulng.sln -p:Configuration="Debug"
	MSBuild -m -verbosity:minimal ..\soulng\soulng.sln -p:Configuration="Release"

sngcpp: 
	MSBuild -m -verbosity:minimal ..\sngcpp_next\sngcpp_next.sln -p:Configuration="Debug"
	MSBuild -m -verbosity:minimal ..\sngcpp_next\sngcpp_next.sln -p:Configuration="Release"

lexers: pplexer 

parsers: ppparser

pplexer:
	slg -v ..\sngcpp20\pp\PPLexer.lexer
	spg -v ..\sngcpp20\pp\PPParser.spg
	slg -v ..\sngcpp20\pp\TextLexer.lexer

ppparser:
	spg -v ..\sngcpp20\pp\PPParser.spg

cpplexer:
	slg -v ..\sngcpp20\lexer\CppLexer.lexer
	slg -v ..\sngcpp20\lexer\CppTokenLexer.lexer

cppparser:
	spg -v ..\sngcpp20\parser\CppParser.spg
	
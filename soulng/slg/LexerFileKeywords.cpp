
// this file has been automatically generated from 'C:/work/soulng/soulng/slg/LexerFileLexer.lexer' using soulng lexer generator slg version 3.10.0

#include <soulng/slg/LexerFileKeywords.hpp>
#include <soulng/slg/LexerFileTokens.hpp>

namespace LexerFileKeywords
{
    using namespace LexerFileTokens;

    Keyword keywords[] =
    {
        {U"classmap", CLASSMAP}, 
        {U"prefix", PREFIX}, 
        {U"tokens", TOKENS}, 
        {U"keywords", KEYWORDS}, 
        {U"expressions", EXPRESSIONS}, 
        {U"lexer", LEXER}, 
        {U"variables", VARIABLES}, 
        {U"actions", ACTIONS}, 
        {U"api", API}, 
        {U"include", INCLUDE}, 
        {U"auto", AUTO}, 
        {U"register", REGISTER}, 
        {U"static", STATIC}, 
        {U"extern", EXTERN}, 
        {U"mutable", MUTABLE}, 
        {U"char", CHAR}, 
        {U"wchar_t", WCHART}, 
        {U"bool", BOOL}, 
        {U"short", SHORT}, 
        {U"int", INT}, 
        {U"long", LONG}, 
        {U"signed", SIGNED}, 
        {U"unsigned", UNSIGNED}, 
        {U"float", FLOAT}, 
        {U"double", DOUBLE}, 
        {U"void", VOID}, 
        {U"typedef", TYPEDEF}, 
        {U"const", CONST}, 
        {U"volatile", VOLATILE}, 
        {U"using", USING}, 
        {U"namespace", NAMESPACE}, 
        {U"throw", THROW}, 
        {U"sizeof", SIZEOF}, 
        {U"operator", OPERATOR}, 
        {U"dynamic_cast", DYNAMICCAST}, 
        {U"static_cast", STATICCAST}, 
        {U"reinterpret_cast", REINTERPRETCAST}, 
        {U"const_cast", CONSTCAST}, 
        {U"typeid", TYPEID}, 
        {U"this", THIS}, 
        {U"new", NEW}, 
        {U"delete", DELETE}, 
        {U"true", TRUE}, 
        {U"false", FALSE}, 
        {U"nullptr", NULLPTR}, 
        {U"case", CASE}, 
        {U"default", DEFAULT}, 
        {U"if", IF}, 
        {U"else", ELSE}, 
        {U"switch", SWITCH}, 
        {U"while", WHILE}, 
        {U"do", DO}, 
        {U"for", FOR}, 
        {U"break", BREAK}, 
        {U"continue", CONTINUE}, 
        {U"return", RETURN}, 
        {U"goto", GOTO}, 
        {U"try", TRY}, 
        {U"catch", CATCH},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

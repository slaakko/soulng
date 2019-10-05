
// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/lexer/CppLexer.lexer' using soulng lexer generator slg version 1.2.0

#include <sngcpp/lexer/CppLexerKeywords.hpp>
#include <sngcpp/lexer/CppLexerTokens.hpp>

namespace CppLexerKeywords
{
    using namespace CppLexerTokens;

    Keyword keywords[] =
    {
        {U"char", CHAR}, 
        {U"char16_t", CHAR16_T}, 
        {U"char32_t", CHAR32_T}, 
        {U"wchar_t", WCHAR_T}, 
        {U"bool", BOOL}, 
        {U"short", SHORT}, 
        {U"int", INT}, 
        {U"long", LONG}, 
        {U"signed", SIGNED}, 
        {U"unsigned", UNSIGNED}, 
        {U"float", FLOAT}, 
        {U"double", DOUBLE}, 
        {U"void", VOID}, 
        {U"auto", AUTO}, 
        {U"nullptr", NULLPTR}, 
        {U"true", TRUE}, 
        {U"false", FALSE}, 
        {U"throw", THROW}, 
        {U"sizeof", SIZEOF}, 
        {U"alignof", ALIGNOF}, 
        {U"new", NEW}, 
        {U"delete", DELETE}, 
        {U"this", THIS}, 
        {U"static_cast", STATIC_CAST}, 
        {U"dynamic_cast", DYNAMIC_CAST}, 
        {U"reinterpret_cast", REINTERPRET_CAST}, 
        {U"const_cast", CONST_CAST}, 
        {U"typeid", TYPEID}, 
        {U"operator", OPERATOR},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

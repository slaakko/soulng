
// this file has been automatically generated from 'C:/work/soulng/sngcpp20/pp/PPLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/pp/PPKeywords.hpp>
#include <sngcpp20/pp/PPTokens.hpp>

namespace PPKeywords
{
    using namespace PPTokens;

    Keyword keywords[] =
    {
        {U"define", DEFINE}, 
        {U"include", INCLUDE}, 
        {U"if", IF}, 
        {U"elif", ELIF}, 
        {U"else", ELSE}, 
        {U"endif", ENDIF}, 
        {U"ifdef", IFDEF}, 
        {U"ifndef", IFNDEF}, 
        {U"undef", UNDEF}, 
        {U"line", LINE}, 
        {U"error", ERROR}, 
        {U"pragma", PRAGMA}, 
        {U"defined", DEFINED},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

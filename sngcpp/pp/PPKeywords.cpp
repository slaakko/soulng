
// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/pp/PPLexer.lexer' using soulng lexer generator slg version 2.0.0

#include <sngcpp/pp/PPKeywords.hpp>
#include <sngcpp/pp/PPTokens.hpp>

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
        {U"defined", DEFINED},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

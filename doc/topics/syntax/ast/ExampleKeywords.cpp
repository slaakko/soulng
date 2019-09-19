
// this file has been automatically generated from 'D:/work/soulng-project/doc/topics/syntax/ast/ExampleLexer.lexer' using soulng lexer generator slg version 1.0.0

#include "ExampleKeywords.hpp"
#include "ExampleTokens.hpp"

namespace ExampleKeywords
{
    using namespace ExampleTokens;

    Keyword keywords[] =
    {
        {U"while", WHILE},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

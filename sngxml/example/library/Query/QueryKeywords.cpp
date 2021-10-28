
// this file has been automatically generated from 'C:/work/soulng/sngxml/example/library/Query/QueryLexer.lexer' using soulng lexer generator slg version 3.1.0

#include <Query/QueryKeywords.hpp>
#include <Query/QueryTokens.hpp>

namespace QueryKeywords
{
    using namespace QueryTokens;

    Keyword keywords[] =
    {
        {U"true", TRUE}, 
        {U"false", FALSE}, 
        {U"get", GET}, 
        {U"where", WHERE}, 
        {U"match", MATCH}, 
        {U"and", AND}, 
        {U"or", OR}, 
        {U"not", NOT},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

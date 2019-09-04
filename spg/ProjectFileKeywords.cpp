
// this file has been automatically generated from 'D:/work/soulng/spg/ProjectFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <soulng/spg/ProjectFileKeywords.hpp>
#include <soulng/spg/ProjectFileTokens.hpp>

namespace ProjectFileKeywords
{
    using namespace ProjectFileTokens;

    Keyword keywords[] =
    {
        {U"project", PROJECT}, 
        {U"source", SOURCE},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

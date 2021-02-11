
// this file has been automatically generated from 'C:/work/soulng/soulng/spg/ProjectFileLexer.lexer' using soulng lexer generator slg version 3.10.0

#include <soulng/spg/ProjectFileKeywords.hpp>
#include <soulng/spg/ProjectFileTokens.hpp>

namespace ProjectFileKeywords
{
    using namespace ProjectFileTokens;

    Keyword keywords[] =
    {
        {U"project", PROJECT}, 
        {U"source", SOURCE}, 
        {U"recovery", RECOVERY}, 
        {U"tokens", TOKENS},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

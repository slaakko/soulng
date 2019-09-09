#include "CommentKeywords.hpp"
#include "CommentTokens.hpp"

namespace CommentKeywords
{
    using namespace CommentTokens;

    static Keyword keywords[] =
    {
        {nullptr, -1}
    };

    static KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

#ifndef CmajorKeywords_HPP
#define CmajorKeywords_HPP
#include <soulng/cmajorlexer/TokenValueParsers.hpp>
#include <soulng/cmajorlexer/CmajorLexerApi.hpp>
#include <soulng/lexer/Keyword.hpp>

namespace CmajorKeywords
{
    using namespace soulng::lexer;

    CMAJOR_LEXER_API KeywordMap* GetKeywordMap();
}
#endif

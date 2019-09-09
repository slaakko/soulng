#ifndef ContainerFileKeywords_HPP
#define ContainerFileKeywords_HPP
#include <soulng/cmajorlexer/CmajorLexerApi.hpp>
#include <soulng/cmajorlexer/TokenValueParsers.hpp>
#include <soulng/lexer/Keyword.hpp>

namespace ContainerFileKeywords
{
    using namespace soulng::lexer;

    CMAJOR_LEXER_API KeywordMap* GetKeywordMap();
}
#endif

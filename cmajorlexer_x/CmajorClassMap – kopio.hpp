#ifndef CmajorClassMap_HPP
#define CmajorClassMap_HPP
#include <soulng/cmajorlexer/TokenValueParsers.hpp>
#include <soulng/cmajorlexer/CmajorLexerApi.hpp>

struct CMAJOR_LEXER_API CmajorClassMap
{
    static int GetClass(char32_t c);
};
#endif

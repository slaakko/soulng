#ifndef ContainerFileClassMap_HPP
#define ContainerFileClassMap_HPP
#include <soulng/cmajorlexer/CmajorLexerApi.hpp>
#include <soulng/cmajorlexer/TokenValueParsers.hpp>

struct CMAJOR_LEXER_API ContainerFileClassMap
{
    static int GetClass(char32_t c);
};
#endif

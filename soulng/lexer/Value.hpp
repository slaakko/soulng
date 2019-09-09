// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_VALUE_INCLUDED
#define SOULNG_LEXER_VALUE_INCLUDED
#include <soulng/lexer/LexerApi.hpp>

namespace soulng { namespace lexer {

struct SOULNG_LEXER_API Value
{
    enum Kind
    {
        integer, floating
    };
    Kind kind;
    virtual ~Value();
};

} } // namespace soulng::lexer

#endif // SOULNG_LEXER_VALUE_INCLUDED

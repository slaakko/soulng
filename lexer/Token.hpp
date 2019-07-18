// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_TOKEN_INCLUDED
#define SOULNG_LEXER_TOKEN_INCLUDED
#include <soulng/lexer/Lexeme.hpp>
#include <soulng/lexer/Value.hpp>

namespace soulng { namespace lexer {

const int INVALID_TOKEN = -1;
const int END = 0;

struct LEXER_API Token
{
    Token() : id(INVALID_TOKEN), match(), value(nullptr), line(1) { }
    Token(int id_) : id(id_), match(), value(nullptr), line(1) { }
    int id;
    Lexeme match;
    Value* value;
    int line;
};

} } // namespace soulng::lexer

#endif // SOULNG_LEXER_TOKEN_INCLUDED

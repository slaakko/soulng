// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_SOURCE_POS_INCLUDED
#define SOULNG_LEXER_SOURCE_POS_INCLUDED
#include <soulng/lexer/LexerApi.hpp>
#include <string>
 
namespace soulng { namespace lexer {

struct SOULNG_LEXER_API SourcePos
{
    SourcePos() : line(0), col(0) {}
    SourcePos(int line_, int col_) : line(line_), col(col_) {}
    bool IsValid() const { return line != 0; }
    int line;
    int col;
};

SOULNG_LEXER_API inline bool operator==(const SourcePos& left, const SourcePos& right)
{
    return left.line == right.line && left.col == right.col;
}

SOULNG_LEXER_API inline bool operator!=(const SourcePos& left, const SourcePos& right)
{
    return !(left == right);
}

SOULNG_LEXER_API inline bool operator<(const SourcePos& left, const SourcePos& right)
{
    if (left.line < right.line) return true;
    if (left.line > right.line) return false;
    return left.col < right.col;
}

SOULNG_LEXER_API std::string ToString(const SourcePos& sourcePos);

} } // namespace soulng::lexer

#endif // SOULNG_LEXER_SOURCE_POS_INCLUDED

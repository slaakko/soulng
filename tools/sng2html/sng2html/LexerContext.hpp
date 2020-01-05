// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_LEXER_CONTEXT_INCLUDED
#define SNG2HTML_SNG2HTML_LEXER_CONTEXT_INCLUDED
#include <sng2html/sng2html/Symbol.hpp>
#include <map>

namespace sng2html { namespace sng2html {

enum class IdentifierClassKind
{
    none, unicode, ascii
};

class LexerContext
{
public:
    LexerContext(IdentifierClassKind identifierClassKind);
    ~LexerContext();
    Symbol* MakeChar(char32_t c);
    Symbol* MakeAny() { return &any; }
    Symbol* MakeEpsilon() { return &epsilon; }
    Symbol* MakeRange(char32_t start, char32_t end);
    Class* MakeIdStart() { return idStart; }
    Class* MakeIdCont() { return idCont; }
    Class* MakeClass();
private:
    std::vector<Symbol*> symbols;
    std::map<char32_t, Symbol*> charSymbols;
    std::map<Range, Symbol*> rangeSymbols;
    Any any;
    Char epsilon;
    Class* idStart;
    Class* idCont;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_LEXER_CONTEXT_INCLUDED

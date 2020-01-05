// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/LexerContext.hpp>
#include <sng2html/sng2html/LexerFile.hpp>
#include <sng2html/sng2html/Identifier.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Path.hpp>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

namespace sng2html { namespace sng2html {

using namespace soulng::unicode;
using namespace soulng::util;

LexerContext::LexerContext(IdentifierClassKind identifierClassKind) : any(), epsilon('\0'), idStart(new Class(0)), idCont(new Class(0))
{
    if (identifierClassKind == IdentifierClassKind::unicode)
    {
        MakeUnicodeIdentifierClasses(*this);
        symbols.push_back(idStart);
        symbols.push_back(idCont);
    }
    else if (identifierClassKind == IdentifierClassKind::ascii)
    {
        MakeAsciiIdentifierClasses(*this);
        symbols.push_back(idStart);
        symbols.push_back(idCont);
    }
}

LexerContext::~LexerContext()
{
    for (Symbol* symbol : symbols)
    {
        delete symbol;
    }
}

Symbol* LexerContext::MakeChar(char32_t c)
{
    auto it = charSymbols.find(c);
    if (it != charSymbols.cend())
    {
        return it->second;
    }
    Symbol* symbol = new Char(c);
    symbols.push_back(symbol);
    charSymbols[c] = symbol;
    return symbol;
}

Symbol* LexerContext::MakeRange(char32_t start, char32_t end)
{
    Range range(start, end);
    auto it = rangeSymbols.find(range);
    if (it != rangeSymbols.cend())
    {
        return it->second;
    }
    Symbol* symbol = new Range(start, end);
    symbols.push_back(symbol);
    rangeSymbols[range] = symbol;
    return symbol;
}

Class* LexerContext::MakeClass()
{
    Class* cls = new Class(0);
    symbols.push_back(cls);
    return cls;
}

} } // namespace sng2html::sng2html

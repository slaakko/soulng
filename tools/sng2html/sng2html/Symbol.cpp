// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/Symbol.hpp>

namespace sng2html { namespace sng2html {

Symbol::Symbol()
{
}

Symbol::~Symbol()
{
}

Char::Char(char32_t chr_) : chr(chr_)
{
}

void Char::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Any::Any()
{
}

void Any::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Range::Range(char32_t start_, char32_t end_) : start(start_), end(end_)
{
}

void Range::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Class::Class(int index_) : index(index_), inverse(false)
{
}

void Class::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void Class::AddSymbol(Symbol* symbol)
{
    symbols.push_back(symbol);
}

} } // namespace sng2html::sng2html

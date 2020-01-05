// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/RegEx.hpp>

namespace sng2html { namespace sng2html {

RegExpression::RegExpression()
{
}

RegExpression::~RegExpression()
{
}

UnaryRegExpression::UnaryRegExpression(RegExpression* child_) : child(child_)
{
}

BinaryRegExpression::BinaryRegExpression(RegExpression* left_, RegExpression* right_) : left(left_), right(right_)
{
}

Alt::Alt(RegExpression* left_, RegExpression* right_) : BinaryRegExpression(left_, right_)
{
}

void Alt::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Cat::Cat(RegExpression* left_, RegExpression* right_) : BinaryRegExpression(left_, right_)
{
}

void Cat::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Kleene::Kleene(RegExpression* child_) : UnaryRegExpression(child_)
{
}

void Kleene::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Pos::Pos(RegExpression* child_) : UnaryRegExpression(child_)
{
}

void Pos::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Opt::Opt(RegExpression* child_) : UnaryRegExpression(child_)
{
}

void Opt::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ParenExpr::ParenExpr(RegExpression* child_) : UnaryRegExpression(child_)
{
}

void ParenExpr::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SymbolExpr::SymbolExpr(Symbol* symbol_) : symbol(symbol_)
{
}

void SymbolExpr::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

RefExpr::RefExpr(const std::u32string& exprId_) : exprId(exprId_)
{
}

void RefExpr::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sng2html::sng2html

// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_REGEX_INCLUDED
#define SNG2HTML_SNG2HTML_REGEX_INCLUDED
#include <sng2html/sng2html/Symbol.hpp>
#include <sng2html/sng2html/Visitor.hpp>
#include <memory>

namespace sng2html { namespace sng2html {

class RegExpression
{
public:
    RegExpression();
    virtual ~RegExpression();
    virtual void Accept(Visitor& visitor) = 0;
    virtual bool IsCharSymbolExpr() const { return false; }
};

class UnaryRegExpression : public RegExpression
{
public:
    UnaryRegExpression(RegExpression* child_);
    RegExpression* Child() const { return child.get(); }
private:
    std::unique_ptr<RegExpression> child;
};

class BinaryRegExpression : public RegExpression
{
public:
    BinaryRegExpression(RegExpression* left_, RegExpression* right_);
    RegExpression* Left() const { return left.get(); }
    RegExpression* Right() const { return right.get(); }
    bool IsCharSymbolExpr() const override { return left->IsCharSymbolExpr() && right->IsCharSymbolExpr(); }
private:
    std::unique_ptr<RegExpression> left;
    std::unique_ptr<RegExpression> right;
};

class Alt : public BinaryRegExpression
{
public:
    Alt(RegExpression* left_, RegExpression* right_);
    void Accept(Visitor& visitor) override;
};

class Cat : public BinaryRegExpression
{
public:
    Cat(RegExpression* left_, RegExpression* right_);
    void Accept(Visitor& visitor) override;
};

class Kleene : public UnaryRegExpression
{
public:
    Kleene(RegExpression* child_);
    void Accept(Visitor& visitor) override;
};

class Pos : public UnaryRegExpression
{
public:
    Pos(RegExpression* child_);
    void Accept(Visitor& visitor) override;
};

class Opt : public UnaryRegExpression
{
public:
    Opt(RegExpression* child_);
    void Accept(Visitor& visitor) override;
};

class ParenExpr : public UnaryRegExpression
{
public:
    ParenExpr(RegExpression* child_);
    void Accept(Visitor& visitor) override;
};

class SymbolExpr : public RegExpression
{
public:
    SymbolExpr(Symbol* symbol_);
    Symbol* GetSymbol() const { return symbol; }
    void Accept(Visitor& visitor) override;
    bool IsCharSymbolExpr() const override { return symbol->IsChar(); }
private:
    Symbol* symbol;
};

class RefExpr : public RegExpression
{
public:
    RefExpr(const std::u32string& exprId_);
    const std::u32string& ExprId() const { return exprId; }
    void Accept(Visitor& visitor) override;
private:
    std::u32string exprId;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_REGEX_INCLUDED

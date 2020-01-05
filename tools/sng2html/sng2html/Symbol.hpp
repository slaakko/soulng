// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_SYMBOL_INCLUDED
#define SNG2HTML_SNG2HTML_SYMBOL_INCLUDED
#include <sng2html/sng2html/Visitor.hpp>
#include <string>
#include <vector>

namespace sng2html { namespace sng2html {

class Symbol
{
public:
    Symbol();
    virtual ~Symbol();
    virtual void Accept(Visitor& visitor) = 0;
    virtual bool IsClass() const { return false; }
    virtual bool IsChar() const { return false; }
    virtual bool IsAny() const { return false; }
    virtual bool IsRange() const { return false; }
    const std::string& Name() const { return name; }
private:
    std::string name;
};

class Char : public Symbol
{
public:
    Char(char32_t chr_);
    bool IsChar() const override { return true; }
    void Accept(Visitor& visitor) override;
    char32_t Chr() const { return chr; }
private:
    char32_t chr;
};

class Any : public Symbol
{
public:
    Any();
    void Accept(Visitor& visitor) override;
    bool IsAny() const override { return true; }
};

class Range : public Symbol
{
public:
    Range(char32_t start_, char32_t end_);
    void Accept(Visitor& visitor) override;
    bool IsRange() const override { return true; }
    bool IsEmpty() const { return start > end; }
    char32_t Start() const { return start; }
    char32_t End() const { return end; }
private:
    char32_t start;
    char32_t end;
};

inline bool operator==(const Range& left, const Range& right)
{
    return left.Start() == right.Start() && left.End() == right.End();
}

inline bool operator<(const Range& left, const Range& right)
{
    if (left.Start() < right.Start()) return true;
    if (left.Start() > right.Start()) return false;
    return left.End() < right.End();
}

class Class : public Symbol
{
public:
    Class(int index_);
    void Accept(Visitor& visitor) override;
    bool IsClass() const override { return true; }
    bool Inverse() const { return inverse; }
    void SetInverse() { inverse = true; }
    const std::vector<Symbol*>& Symbols() const { return symbols; }
    void AddSymbol(Symbol* symbol);
    int Index() const { return index; }
    bool IsEmpty() const { return symbols.empty(); }
private:
    int index;
    bool inverse;
    std::vector<Symbol*> symbols;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_SYMBOL_INCLUDED

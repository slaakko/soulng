// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_SYMBOL_INCLUDED
#define SOULNG_SLG_SYMBOL_INCLUDED
#include <soulng/slg/Visitor.hpp>
#include <vector>
#include <set>
#include <list>

namespace soulng { namespace slg {

const char32_t eps = '\0';

class Class;
class LexerContext;

class Symbol
{
public:
    Symbol();
    virtual ~Symbol();
    virtual bool Match(char32_t c) = 0;
    virtual void Accept(Visitor& visitor) = 0;
    virtual bool IsClass() const { return false; }
    virtual bool IsChar() const { return false; }
    virtual bool IsAny() const { return false; }
    virtual bool IsRange() const { return false; }
    void SetName(const std::string& name_);
    const std::string& Name() const { return name; }
    bool Contained() const { return contained; }
    void SetContained() { if (!dontSetContained) contained = true; }
    void DontSetContained() { dontSetContained = true; }
private:
    std::string name;
    bool contained;
    bool dontSetContained;
};

class Char : public Symbol
{
public:
    Char(char32_t chr_);
    bool IsChar() const override { return true; }
    bool Match(char32_t c) override;
    void Accept(Visitor& visitor) override;
    char32_t Chr() const { return chr; }
private:
    char32_t chr;
};

class Any : public Symbol
{
public:
    Any();
    bool Match(char32_t c) override;
    void Accept(Visitor& visitor) override;
    bool IsAny() const override { return true; }
};

class Range : public Symbol
{
public:
    Range(char32_t start_, char32_t end_);
    bool Match(char32_t c) override;
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

bool Intersect(const Range& left, const Range& right);

Range operator&(const Range& left, const Range& right);

std::vector<Range> operator-(const Range& left, const Range& right);

std::vector<Range> operator~(const Range& that);

class Class : public Symbol
{
public:
    Class(int index_);
    bool Match(char32_t c) override;
    void Accept(Visitor& visitor) override;
    bool IsClass() const override { return true; }
    bool Inverse() const { return inverse; }
    void SetInverse() { inverse = true; }
    const std::vector<Symbol*>& Symbols() const { return symbols; }
    void AddSymbol(Symbol* symbol);
    void AddChar(char32_t c);
    int Index() const { return index; }
    void SetIndex(int index_);
    const std::vector<char32_t>& Chars() const { return chars; }
    Class* MakeCanonical(LexerContext& lexerContext);
    void MakeMinimal(LexerContext& lexerContext);
    void MakeInverse(LexerContext& lexerContext);
    Class* Clone();
    bool IsEmpty() const { return symbols.empty(); }
    const std::list<Range>& Ranges() const { return ranges; }
    std::list<Range>& Ranges() { return ranges; }
private:
    int index;
    bool inverse;
    std::vector<Symbol*> symbols;
    std::vector<char32_t> chars;
    std::list<Range> ranges;
};

bool operator==(const Class& left, const Class& right);

bool Intersect(const Class& left, const Class& right);

Class* MakeIntertersection(const Class& left, const Class& right, LexerContext& lexerContext);

Class* MakeDifference(const Class& left, const Class& right, LexerContext& lexerContext);

} } // namespace soulng::slg

#endif // SOULNG_SLG_SYMBOL_INCLUDED

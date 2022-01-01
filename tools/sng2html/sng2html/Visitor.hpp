// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_VISITOR_INCLUDED
#define SNG2HTML_SNG2HTML_VISITOR_INCLUDED

namespace sng2html { namespace sng2html {

class EmptyParser;
class TokenParser;
class CharParser;
class StringParser;
class CharSetParser;
class OptionalParser;
class KleeneParser;
class PositiveParser;
class ExpectationParser;
class GroupingParser;
class SequenceParser;
class AlternativeParser;
class DifferenceParser;
class ListParser;
class LookaheadParser;
class ActionParser;
class NonterminalParser;
class RuleParser;
class GrammarParser;
class ParserFile;
class LexerFile;
class Domain;
class Char;
class Any;
class Range;
class Class;
class Alt;
class Cat;
class Kleene;
class Pos;
class Opt;
class ParenExpr;
class SymbolExpr;
class RefExpr;

class Visitor
{
public:
    virtual ~Visitor();
    virtual void Visit(EmptyParser& parser) {}
    virtual void Visit(TokenParser& parser) {}
    virtual void Visit(CharParser& parser) {}
    virtual void Visit(StringParser& parser) {}
    virtual void Visit(CharSetParser& parser) {}
    virtual void Visit(OptionalParser& parser) {}
    virtual void Visit(KleeneParser& parser) {}
    virtual void Visit(PositiveParser& parser) {}
    virtual void Visit(ExpectationParser& parser) {}
    virtual void Visit(GroupingParser& parser) {}
    virtual void Visit(SequenceParser& parser) {}
    virtual void Visit(AlternativeParser& parser) {}
    virtual void Visit(DifferenceParser& parser) {}
    virtual void Visit(ListParser& parser) {}
    virtual void Visit(LookaheadParser& parser) {}
    virtual void Visit(ActionParser& parser) {}
    virtual void Visit(NonterminalParser& parser) {}
    virtual void Visit(RuleParser& parser) {}
    virtual void Visit(GrammarParser& parser) {}
    virtual void Visit(ParserFile& parserFile) {}
    virtual void Visit(Domain& domain) {}
    virtual void Visit(LexerFile& lexerFile) {}
    virtual void Visit(Char& symbol) {}
    virtual void Visit(Any& symbol) {}
    virtual void Visit(Range& symbol) {}
    virtual void Visit(Class& symbol) {}
    virtual void Visit(Alt& alt) {}
    virtual void Visit(Cat& cat) {}
    virtual void Visit(Kleene& kleene) {}
    virtual void Visit(Pos& pos) {}
    virtual void Visit(Opt& opt) {}
    virtual void Visit(ParenExpr& parenExpr) {}
    virtual void Visit(SymbolExpr& symbolExpr) {}
    virtual void Visit(RefExpr& refExpr) {}
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_VISITOR_INCLUDED

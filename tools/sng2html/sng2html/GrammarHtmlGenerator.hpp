// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_GRAMMAR_HTML_GENERATOR_INCLUDED
#define SNG2HTML_SNG2HTML_GRAMMAR_HTML_GENERATOR_INCLUDED
#include <sng2html/sng2html/Visitor.hpp>
#include <sng2html/sng2html/Grammar.hpp>
#include <sng2html/sng2html/LexerFile.hpp>
#include <sngxml/dom/Element.hpp>
#include <unordered_map>

namespace sng2html { namespace sng2html {

class GrammarHtmlGeneratorVisitor : public Visitor
{
public:
    GrammarHtmlGeneratorVisitor(bool verbose_, std::unordered_map<GrammarParser*, Grammar*>& parserGrammarMap_, std::unordered_map<RuleParser*, Rule*>& parserRuleMap_,
        std::unordered_map<LexerFile*, Grammar*>& lexerGrammarMap_, std::unordered_map<Expression*, Rule*>& lexerRuleMap_,
        std::unordered_map<std::u32string, LexerFile*>& lexerMap_, const std::u32string& styleFilePath_);
    void Visit(Char& symbol) override;
    void Visit(Any& symbol) override;
    void Visit(Range& symbol) override;
    void Visit(Class& symbol) override;
    void Visit(Alt& alt) override;
    void Visit(Cat& cat) override;
    void Visit(Kleene& kleene) override;
    void Visit(Pos& pos) override;
    void Visit(Opt& opt) override;
    void Visit(ParenExpr& parenExpr) override;
    void Visit(SymbolExpr& symbolExpr) override;
    void Visit(RefExpr& refExpr) override;
    void Visit(EmptyParser& parser) override;
    void Visit(TokenParser& parser) override;
    void Visit(CharParser& parser) override;
    void Visit(StringParser& parser) override;
    void Visit(CharSetParser& parser) override;
    void Visit(OptionalParser& parser) override;
    void Visit(KleeneParser& parser) override;
    void Visit(PositiveParser& parser) override;
    void Visit(ExpectationParser& parser) override;
    void Visit(GroupingParser& parser) override;
    void Visit(SequenceParser& parser) override;
    void Visit(AlternativeParser& parser) override;
    void Visit(DifferenceParser& parser) override;
    void Visit(ListParser& parser) override;
    void Visit(ActionParser& parser) override;
    void Visit(NonterminalParser& parser) override;
    void Visit(RuleParser& parser) override;
    void Visit(GrammarParser& parser) override;
    void Visit(ParserFile& parserFile) override;
    void Visit(Domain& domain) override;
    void Visit(LexerFile& lexerFile) override;
    Grammar* GetGrammar(GrammarParser* parser) const;
    Rule* GetRule(RuleParser* parser) const;
private:
    bool verbose;
    std::unordered_map<GrammarParser*, Grammar*>& parserGrammarMap;
    std::unordered_map<RuleParser*, Rule*>& parserRuleMap;
    std::unordered_map<LexerFile*, Grammar*>& lexerGrammarMap;
    std::unordered_map<Expression*, Rule*>& lexerRuleMap;
    std::unordered_map<std::u32string, LexerFile*>& lexerMap;
    LexerFile* lexerFile;
    std::u32string styleFilePath;
    sngxml::dom::Element* ruleTable;
    sngxml::dom::Element* ruleBodyElement;
    GrammarParser* currentGrammar;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_GRAMMAR_HTML_GENERATOR_INCLUDED

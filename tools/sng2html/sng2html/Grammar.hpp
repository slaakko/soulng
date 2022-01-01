// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_GRAMMAR_INCLUDED
#define SNG2HTML_SNG2HTML_GRAMMAR_INCLUDED
#include <sng2html/sng2html/Parser.hpp>
#include <sng2html/sng2html/LexerFile.hpp>

namespace sng2html { namespace sng2html {

class Rule
{
public:
    enum class Kind
    {
        lexical, parser
    };
    Rule(const std::u32string& name_, Expression* expression_);
    Rule(const std::u32string& name_, RuleParser* parser_);
    const std::u32string& Name() const { return name; }
    Expression* GetExpression() const { return expression; }
    RuleParser* Parser() const { return parser; }
private:
    Kind kind;
    std::u32string name;
    Expression* expression;
    RuleParser* parser;
};

class Grammar
{
public:
    enum class Kind
    {
        lexical, parser
    };
    Grammar(const std::u32string& name_, const std::u32string& title_, const std::string& htmlFilePath_, LexerFile* lexerFile_);
    Grammar(const std::u32string& name_, const std::u32string& title_, const std::string& htmlFilePath_, GrammarParser* parser_);
    Kind GetKind() const { return kind; }
    const std::u32string& Name() const { return name; }
    const std::u32string& Title() const { return title; }
    const std::string& HtmlFilePath() const { return htmlFilePath; }
    GrammarParser* Parser() const { return parser; }
    const std::u32string& HtmlFileName() const { return htmlFileName; }
    void AddRule(Rule* rule);
    const std::vector<std::unique_ptr<Rule>>& Rules() const { return rules; }
private:
    Kind kind;
    std::u32string name;
    std::u32string title;
    std::string htmlFilePath;
    LexerFile* lexerFile;
    GrammarParser* parser;
    std::u32string htmlFileName;
    std::string htmfFilePath;
    std::vector<std::unique_ptr<Rule>> rules;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_GRAMMAR_INCLUDED

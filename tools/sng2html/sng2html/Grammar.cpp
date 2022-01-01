// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/Grammar.hpp>

namespace sng2html { namespace sng2html {

Rule::Rule(const std::u32string& name_, Expression* expression_) : kind(Kind::lexical), name(name_), expression(expression_), parser(nullptr)
{
}

Rule::Rule(const std::u32string& name_, RuleParser* parser_) : kind(Kind::parser), name(name_), parser(parser_), expression(nullptr)
{
}

Grammar::Grammar(const std::u32string& name_, const std::u32string& title_, const std::string& htmlFilePath_, LexerFile* lexerFile_) :
    kind(Kind::lexical), name(name_), title(title_), htmlFilePath(htmlFilePath_), lexerFile(lexerFile_), parser(nullptr), htmlFileName(name + U".html")
{
}

Grammar::Grammar(const std::u32string& name_, const std::u32string& title_, const std::string& htmlFilePath_, GrammarParser* parser_) :
    kind(Kind::parser), name(name_), title(title_), htmlFilePath(htmlFilePath_), parser(parser_), lexerFile(nullptr), htmlFileName(name + U".html")
{
}

void Grammar::AddRule(Rule* rule)
{
    rules.push_back(std::unique_ptr<Rule>(rule));
}

} } // namespace sng2html::sng2html

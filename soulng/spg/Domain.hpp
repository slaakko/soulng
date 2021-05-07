// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_DOMAIN_INCLUDED
#define SOULNG_SPG_DOMAIN_INCLUDED
#include <soulng/spg/ParserFile.hpp>
#include <soulng/spg/Tokens.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <map>

namespace soulng { namespace spg {

class Domain
{
public:
    Domain();
    void SetName(const std::string& name_);
    void Accept(Visitor& visitor);
    void AddParserFile(ParserFile* parserFile);
    const std::vector<ParserFile*>& ParserFiles() const { return parserFiles; }
    void AddParser(GrammarParser* parser);
    GrammarParser* GetParser(const std::u32string& parserName) const;
    const std::string& RuleHeaderFilePath() const { return ruleHeaderFilePath; }
    void SetRuleHeaderFilePath(const std::string& ruleHeaderFilePath_);
    const std::string& RuleSourceFilePath() const { return ruleSourceFilePath; }
    void SetRuleSourceFilePath(const std::string& ruleSourceFilePath_);
    void SetRecovery() { recovery = true; }
    bool Recovery() const { return recovery; }
    bool InverseAdded() const { return inverseAdded; }
    void SetInverseAdded() { inverseAdded = true; }
    void SetTokens(Tokens* tokens_) { tokens.reset(tokens_); }
    Tokens* GetTokens() const { return tokens.get(); }
    void Write(CodeFormatter& formatter);
    RuleParser* Start() const { return  start; }
    void SetStart(RuleParser* start_) { start = start_; }
    void AddRule(RuleParser* rule);
    const std::vector<RuleParser*>& Rules() const { return rules; }
private:
    std::string name;
    std::vector<ParserFile*> parserFiles;
    std::unique_ptr<Tokens> tokens;
    std::string ruleHeaderFilePath;
    std::string ruleSourceFilePath;
    std::map<std::u32string, GrammarParser*> parserMap;
    bool recovery;
    bool inverseAdded;
    RuleParser* start;
    std::vector<RuleParser*> rules;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_DOMAIN_INCLUDED

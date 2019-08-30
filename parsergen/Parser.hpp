// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSERGEN_PARSER_INCLUDED
#define SOULNG_PARSERGEN_PARSER_INCLUDED
#include <soulng/lexer/Token.hpp>
#include <soulng/codedom/Statement.hpp>
#include <soulng/codedom/Type.hpp>
#include <string>
#include <memory>
#include <map>

namespace soulng { namespace parsergen {

class Visitor;

class Parser
{
public:
    Parser(const std::u32string& name_);
    virtual ~Parser();
    virtual Parser* Clone() const;
    virtual void Accept(Visitor& visitor) = 0;
    virtual bool IsNonterminal() const { return false; }
    virtual bool IsAction() const { return false; }
    virtual bool IsTokenSwitch() const { return false; }
    virtual bool IsActionToken() const { return false; }
    virtual bool IsToken() const { return false; }
    const std::u32string& Name() const { return name; }
    Parser* Parent() const { return parent; }
    void SetParent(Parser* parent_) { parent = parent_; }
private:
    Parser* parent;
    std::u32string name;
};

class UnaryParser : public Parser
{
public:
    UnaryParser(const std::u32string& name_, Parser* child_);
    Parser* Child() const { return child.get(); }
private:
    std::unique_ptr<Parser> child;
};

class BinaryParser : public Parser
{
public:
    BinaryParser(const std::u32string& name_, Parser* left_, Parser* right_);
    Parser* Left() const { return left.get(); }
    Parser* Right() const { return right.get(); }
private:
    std::unique_ptr<Parser> left;
    std::unique_ptr<Parser> right;
};

class EmptyParser : public Parser
{
public:
    EmptyParser();
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
};

class TokenParser : public Parser
{
public:
    TokenParser(const std::u32string& tokenName_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    bool IsToken() const override { return true; }
    const std::u32string& TokenName() const { return tokenName; }
private:
    std::u32string tokenName;
};

class OptionalParser : public UnaryParser
{
public:
    OptionalParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
};

class KleeneParser : public UnaryParser
{
public:
    KleeneParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
};

class PositiveParser : public UnaryParser
{
public:
    PositiveParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
};

class ExpectationParser : public UnaryParser
{
public:
    ExpectationParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
};

class GroupingParser : public UnaryParser
{
public:
    GroupingParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    bool IsAction() const override { return Child()->IsAction(); }
};

class SequenceParser : public BinaryParser
{
public:
    SequenceParser(Parser* left_, Parser* right_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
};

class AlternativeParser : public BinaryParser
{
public:
    AlternativeParser(Parser* left_, Parser* right_);
    bool IsTokenSwitch() const override { return Left()->IsActionToken() && Right()->IsActionToken() || Left()->IsTokenSwitch() && Right()->IsActionToken(); }
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
};

class DifferenceParser : public BinaryParser
{
public:
    DifferenceParser(Parser* left_, Parser* right_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
};

class ListParser : public UnaryParser
{
public:
    ListParser(Parser* left_, Parser* right_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    Parser* Left() const { return left; }
    Parser* Right() const { return right; }
private:
    Parser* left;
    Parser* right;
};

class ActionParser : public UnaryParser
{
public:
    ActionParser(soulng::codedom::CompoundStatement* successCode_, soulng::codedom::CompoundStatement* failCode_, Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    bool IsAction() const override { return true; }
    bool IsActionToken() const override;
    soulng::codedom::CompoundStatement* SuccessCode() const { return successCode; }
    soulng::codedom::CompoundStatement* FailCode() const { return failCode; }
private:
    soulng::codedom::CompoundStatement* successCode;
    std::unique_ptr<soulng::codedom::CompoundStatement> ownedSuccessCode;
    soulng::codedom::CompoundStatement* failCode;
    std::unique_ptr<soulng::codedom::CompoundStatement> ownedFailCode;
};

struct Parameter
{
    Parameter(soulng::codedom::TypeId* type_, const std::u32string& name_);
    Parameter(soulng::codedom::TypeId* type_, const std::u32string& name_, bool variable_);
    virtual ~Parameter();
    std::unique_ptr<soulng::codedom::TypeId> type;
    std::u32string name;
    bool variable;
};

struct Variable : Parameter
{
    Variable(soulng::codedom::TypeId* type_, const std::u32string& name_);
};

class RuleParser;

class NonterminalParser : public Parser
{
public:
    NonterminalParser(const std::u32string& name_, const std::u32string& ruleName_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    bool IsNonterminal() const override { return true; }
    const std::u32string& RuleName() const { return ruleName; }
    void SetRule(RuleParser* rule) { this->rule = rule; }
    RuleParser* Rule() const { return rule; }
    void SetArguments(const std::vector<soulng::codedom::CppObject*>& args_);
    const std::vector<soulng::codedom::CppObject*>& Arguments() const { return args; }
private:
    std::u32string ruleName;
    RuleParser* rule;
    std::vector<soulng::codedom::CppObject*> args;
    std::vector<std::unique_ptr<soulng::codedom::CppObject>> ownedArgs;
};

class RuleParser : public UnaryParser
{
public:
    RuleParser(const std::u32string& name_, Parser* definition_);
    void Accept(Visitor& visitor) override;
    void SetParameters(std::vector<Parameter*>& params);
    const std::vector<std::unique_ptr<Parameter>>& Parameters() const { return parameters; }
    const std::vector < std::unique_ptr<Variable>>& Variables() const { return variables; }
    void SetReturnType(soulng::codedom::TypeId* returnType_);
    soulng::codedom::TypeId* ReturnType() const { return returnType.get(); }
    void AddNonterminal(NonterminalParser* nonterminal);
    const std::vector<NonterminalParser*>& Nonterminals() const { return nonterminals; }
    const std::u32string& Info() const { return info; }
    void SetInfo(const std::u32string& info_);
    void SetHasReturn() { hasReturn = true; }
    bool HasReturn() const { return hasReturn; }
private:
    std::vector<std::unique_ptr<Parameter>> parameters;
    std::vector<std::unique_ptr<Variable>> variables;
    std::unique_ptr<soulng::codedom::TypeId> returnType;
    std::vector<NonterminalParser*> nonterminals;
    std::u32string info;
    bool hasReturn;
};

class GrammarParser : public Parser
{
public:
    GrammarParser(const std::u32string& name_);
    void Accept(Visitor& visitor) override;
    void SetMain() { main = true; }
    bool Main() const { return main; }
    void AddUsing(const std::u32string& using_);
    const std::vector<std::u32string>& Usings() const { return usings; }
    void SetLexer(const std::u32string& lexer_) { lexer = lexer_; }
    const std::u32string& Lexer() const { return lexer; }
    void AddRule(RuleParser* rule);
    void MapRule(RuleParser* rule);
    RuleParser* GetRule(const std::u32string& ruleName) const;
    const std::vector<std::unique_ptr<RuleParser>>& Rules() const { return rules; }
    void AddRuleInfo(const std::u32string& ruleName, const std::u32string& ruleInfo);
    const std::vector<std::pair<std::u32string, std::u32string>>& RuleInfos() const { return ruleInfos; }
private:
    bool main;
    std::vector<std::u32string> usings;
    std::u32string lexer;
    std::vector<std::unique_ptr<RuleParser>> rules;
    std::map<std::u32string, RuleParser*> ruleMap;
    std::vector<std::pair<std::u32string, std::u32string>> ruleInfos;
};

} } // namespae soulng::parsergen

#endif // SOULNG_PARSERGEN_PARSER_INCLUDED

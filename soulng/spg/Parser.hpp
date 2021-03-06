// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_PARSER_INCLUDED
#define SOULNG_SPG_PARSER_INCLUDED
#include <soulng/spg/CharSet.hpp>
#include <soulng/spg/Tokens.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/cppcode/Expression.hpp>
#include <soulng/cppcode/Statement.hpp>
#include <soulng/cppcode/Type.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <string>
#include <memory>
#include <map>

namespace soulng { namespace spg {

using namespace soulng::util;

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
    virtual bool IsNothrow() const;
    virtual bool IsState() const;
    virtual std::string Kind() const = 0;
    const std::u32string& Name() const { return name; }
    Parser* Parent() const { return parent; }
    void SetParent(Parser* parent_) { parent = parent_; }
    const TokenSet& First() const { return first; }
    void SetFirst(const TokenSet& first_);
private:
    Parser* parent;
    std::u32string name;
    bool firstComputed;
    TokenSet first;
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
    std::string Kind() const override { return "empty"; }
};

class AnyParser : public Parser
{
public:
    AnyParser();
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    std::string Kind() const override { return "any"; }
};

class TokenParser : public Parser
{
public:
    TokenParser(const std::u32string& tokenName_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    bool IsToken() const override { return true; }
    const std::u32string& TokenName() const { return tokenName; }
    std::string Kind() const override { return "token"; }
private:
    std::u32string tokenName;
};

class CharParser : public Parser
{
public:
    CharParser(char32_t chr_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    char32_t Chr() const { return chr; }
    std::string Kind() const override { return "char"; }
private:
    char32_t chr;
};

class StringParser : public Parser
{
public:
    StringParser(const std::u32string& str_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    const std::u32string& Str() const { return str; }
    void SetArrayName(const std::string& arrayName_);
    const std::string& ArrayName() const { return arrayName;  }
    std::string Kind() const override { return "string"; }
private:
    std::u32string str;
    std::string arrayName;
};

class CharSetParser : public Parser
{
public:
    CharSetParser(const CharSet& set_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    const CharSet& Set() const { return set; }
    void SetArrayName(const std::string& arrayName_);
    const std::string& ArrayName() const { return arrayName; }
    std::string Kind() const override { return "set"; }
private:
    CharSet set;
    std::string arrayName;
};

class OptionalParser : public UnaryParser
{
public:
    OptionalParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    std::string Kind() const override { return "optional"; }
};

class KleeneParser : public UnaryParser
{
public:
    KleeneParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    std::string Kind() const override { return "kleene"; }
};

class PositiveParser : public UnaryParser
{
public:
    PositiveParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    std::string Kind() const override { return "positive"; }
};

class ExpectationParser : public UnaryParser
{
public:
    ExpectationParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    std::string Kind() const override { return "expectation"; }
};

class GroupingParser : public UnaryParser
{
public:
    GroupingParser(Parser* child_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    bool IsAction() const override { return Child()->IsAction(); }
    std::string Kind() const override { return "grouping"; }
};

class SequenceParser : public BinaryParser
{
public:
    SequenceParser(Parser* left_, Parser* right_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    std::string Kind() const override { return "sequence"; }
};

class AlternativeParser : public BinaryParser
{
public:
    AlternativeParser(Parser* left_, Parser* right_);
    bool IsTokenSwitch() const override { return Left()->IsActionToken() && Right()->IsActionToken() || Left()->IsTokenSwitch() && Right()->IsActionToken(); }
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    std::string Kind() const override { return "choice"; }
};

class DifferenceParser : public BinaryParser
{
public:
    DifferenceParser(Parser* left_, Parser* right_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    std::string Kind() const override { return "difference"; }
};

class ListParser : public UnaryParser
{
public:
    ListParser(Parser* left_, Parser* right_);
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    Parser* Left() const { return left; }
    Parser* Right() const { return right; }
    std::string Kind() const override { return "list"; }
private:
    Parser* left;
    Parser* right;
};

class ActionParser : public UnaryParser
{
public:
    ActionParser(soulng::cppcode::CompoundStatement* successCode_, soulng::cppcode::CompoundStatement* failCode_, Parser* child_);
    ~ActionParser();
    Parser* Clone() const override;
    void Accept(Visitor& visitor) override;
    bool IsAction() const override { return true; }
    bool IsActionToken() const override;
    soulng::cppcode::CompoundStatement* SuccessCode() const { return successCode; }
    soulng::cppcode::CompoundStatement* FailCode() const { return failCode; }
    std::string Kind() const override { return "action"; }
private:
    soulng::cppcode::CompoundStatement* successCode;
    std::unique_ptr<soulng::cppcode::CompoundStatement> ownedSuccessCode;
    soulng::cppcode::CompoundStatement* failCode;
    std::unique_ptr<soulng::cppcode::CompoundStatement> ownedFailCode;
};

struct Parameter
{
    Parameter(soulng::cppcode::TypeId* type_, const std::u32string& name_);
    Parameter(soulng::cppcode::TypeId* type_, const std::u32string& name_, bool variable_);
    virtual ~Parameter();
    std::unique_ptr<soulng::cppcode::TypeId> type;
    std::u32string name;
    bool variable;
};

struct Variable : Parameter
{
    Variable(soulng::cppcode::TypeId* type_, const std::u32string& name_);
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
    void SetArguments(soulng::cppcode::ExpressionList* args_);
    const std::vector<soulng::cppcode::CppObject*>& Arguments() const { return args; }
    std::string Kind() const override { return "nonterminal"; }
private:
    std::u32string ruleName;
    RuleParser* rule;
    std::vector<soulng::cppcode::CppObject*> args;
    std::vector<std::unique_ptr<soulng::cppcode::CppObject>> ownedArgs;
};

class RuleParser : public Parser
{
public:
    RuleParser(const std::u32string& name_);
    void Accept(Visitor& visitor) override;
    void SetDefinition(Parser* definition_);
    Parser* Definition() { return definition.get(); }
    void AddParamOrVariable(Parameter* paramOrVariable);
    const std::vector<std::unique_ptr<Parameter>>& Parameters() const { return parameters; }
    const std::vector< std::unique_ptr<Variable>>& Variables() const { return variables; }
    void SetReturnType(soulng::cppcode::TypeId* returnType_);
    soulng::cppcode::TypeId* ReturnType() const { return returnType.get(); }
    void AddNonterminal(NonterminalParser* nonterminal);
    const std::vector<NonterminalParser*>& Nonterminals() const { return nonterminals; }
    const std::u32string& Info() const { return info; }
    void SetInfo(const std::u32string& info_);
    void SetHasReturn() { hasReturn = true; }
    bool HasReturn() const { return hasReturn; }
    void AddParser(Parser* parser);
    std::string Kind() const override { return "rule"; }
    void Write(CodeFormatter& formatter);
    void SetId(int id_) { id = id_; }
    int Id() const { return id; }
private:
    std::unique_ptr<Parser> definition;
    std::vector<std::unique_ptr<Parameter>> parameters;
    std::vector<std::unique_ptr<Variable>> variables;
    std::unique_ptr<soulng::cppcode::TypeId> returnType;
    std::vector<NonterminalParser*> nonterminals;
    std::u32string info;
    bool hasReturn;
    std::vector<Parser*> parsers;
    int id;
};

class GrammarParser : public Parser
{
public:
    GrammarParser(const std::u32string& name_, const std::u32string& api_);
    void Accept(Visitor& visitor) override;
    const std::u32string& Api() const { return api; }
    void SetMain() { main = true; }
    bool Main() const { return main; }
    void SetStart() { start = true; }
    bool Start() const { return start; }
    void SetNothrow() { nothrow = true; }
    bool Nothrow() const { return nothrow; }
    bool IsNothrow() const override { return Nothrow(); }
    bool IsState() const { return state; }
    void SetState() { state = true; }
    void SetFarthestError() { farthestError = true; }
    bool IsFarthestError() const { return farthestError; }
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
    std::string Kind() const override { return "grammar"; }
    void Write(CodeFormatter& formatter);
private:
    std::u32string api;
    bool main;
    bool start;
    bool nothrow;
    bool farthestError;
    bool state;
    std::vector<std::u32string> usings;
    std::u32string lexer;
    std::vector<std::unique_ptr<RuleParser>> rules;
    std::map<std::u32string, RuleParser*> ruleMap;
    std::vector<std::pair<std::u32string, std::u32string>> ruleInfos;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_PARSER_INCLUDED

// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/Parser.hpp>
#include <sng2html/sng2html/Visitor.hpp>
#include <soulng/util/Unicode.hpp>

namespace sng2html { namespace sng2html {

using namespace soulng::unicode;

Parser::Parser(const std::u32string& name_) : name(name_), parent(nullptr), parentIsList(false)
{
}

Parser::~Parser()
{
}

Parser* Parser::Clone() const
{
    throw std::runtime_error("this class does not support clone operation");
}

UnaryParser::UnaryParser(const std::u32string& name_, Parser* child_) : Parser(name_), child(child_)
{
    child->SetParent(this);
}

BinaryParser::BinaryParser(const std::u32string& name_, Parser* left_, Parser* right_) : Parser(name_), left(left_), right(right_)
{
    left->SetParent(this);
    right->SetParent(this);
}

EmptyParser::EmptyParser() : Parser(U"empty")
{
}

Parser* EmptyParser::Clone() const
{
    return new EmptyParser();
}

void EmptyParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TokenParser::TokenParser(const std::u32string& tokenName_) : Parser(tokenName_), tokenName(tokenName_)
{
}

Parser* TokenParser::Clone() const
{
    return new TokenParser(tokenName);
}

void TokenParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CharParser::CharParser(char32_t chr_) : Parser(std::u32string(1, chr_)), chr(chr_)
{
}

Parser* CharParser::Clone() const
{
    return new CharParser(chr);
}

void CharParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

StringParser::StringParser(const std::u32string& str_) : Parser(str_), str(str_)
{
}

Parser* StringParser::Clone() const
{
    return new StringParser(str);
}

void StringParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void StringParser::SetArrayName(const std::string& arrayName_)
{
    arrayName = arrayName_;
}

CharSetParser::CharSetParser(const CharSet& set_) : Parser(U"charset"), set(set_)
{
}

Parser* CharSetParser::Clone() const
{
    return new CharSetParser(set);
}

void CharSetParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CharSetParser::SetArrayName(const std::string& arrayName_)
{
    arrayName = arrayName_;
}

OptionalParser::OptionalParser(Parser* child_) : UnaryParser(U"optional", child_)
{
}

Parser* OptionalParser::Clone() const
{
    return new OptionalParser(Child()->Clone());
}

void OptionalParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

KleeneParser::KleeneParser(Parser* child_) : UnaryParser(U"kleene", child_)
{
}

Parser* KleeneParser::Clone() const
{
    return new KleeneParser(Child()->Clone());
}

void KleeneParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PositiveParser::PositiveParser(Parser* child_) : UnaryParser(U"positive", child_)
{
}

Parser* PositiveParser::Clone() const
{
    return new PositiveParser(Child()->Clone());
}

void PositiveParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExpectationParser::ExpectationParser(Parser* child_) : UnaryParser(U"expectation", child_)
{
}

Parser* ExpectationParser::Clone() const
{
    return new ExpectationParser(Child()->Clone());
}

void ExpectationParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

GroupingParser::GroupingParser(Parser* child_) : UnaryParser(U"grouping", child_)
{
}

Parser* GroupingParser::Clone() const
{
    return new GroupingParser(Child()->Clone());
}

void GroupingParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SequenceParser::SequenceParser(Parser* left_, Parser* right_) : BinaryParser(U"sequence", left_, right_)
{
}

Parser* SequenceParser::Clone() const
{
    return new SequenceParser(Left()->Clone(), Right()->Clone());
}

void SequenceParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

bool SequenceParser::IsAction() const
{
    if (Left()->IsEmptyOrEmptyActionParser())
    {
        return Right()->IsAction();
    }
    else if (Right()->IsEmptyOrEmptyActionParser())
    {
        return Left()->IsAction();
    }
    else
    {
        return false;
    }
}

AlternativeParser::AlternativeParser(Parser* left_, Parser* right_) : BinaryParser(U"alternative", left_, right_)
{
}

Parser* AlternativeParser::Clone() const
{
    return new AlternativeParser(Left()->Clone(), Right()->Clone());
}

void AlternativeParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DifferenceParser::DifferenceParser(Parser* left_, Parser* right_) : BinaryParser(U"difference", left_, right_)
{
}

Parser* DifferenceParser::Clone() const
{
    return new DifferenceParser(Left()->Clone(), Right()->Clone());
}

void DifferenceParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ListParser::ListParser(Parser* left_, Parser* right_) :
    UnaryParser(U"list", new SequenceParser(left_, new KleeneParser(new SequenceParser(right_, left_->Clone())))), left(left_), right(right_)
{
    left->SetParentIsList();
    right->SetParentIsList();
}

Parser* ListParser::Clone() const
{
    return new ListParser(left->Clone(), right->Clone());
}

void ListParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ActionParser::ActionParser(soulng::cppcode::CompoundStatement* successCode_, soulng::cppcode::CompoundStatement* failCode_, Parser* child_) :
    UnaryParser(U"action", child_), successCode(successCode_), failCode(failCode_)
{
    if (successCode && !successCode->IsOwned())
    {
        successCode->SetOwned();
        ownedSuccessCode.reset(successCode);
    }
    if (failCode && !failCode->IsOwned())
    {
        failCode->SetOwned();
        ownedFailCode.reset(failCode);
    }
}

ActionParser::~ActionParser()
{

}

Parser* ActionParser::Clone() const
{
    return new ActionParser(successCode, failCode, Child()->Clone());
}

void ActionParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

bool ActionParser::IsActionToken() const
{
    return Child()->IsToken(); // todo
}

Parameter::Parameter(soulng::cppcode::TypeId* type_, const std::u32string& name_) : type(type_), name(name_), variable(false)
{
}

Parameter::Parameter(soulng::cppcode::TypeId* type_, const std::u32string& name_, bool variable_) : type(type_), name(name_), variable(variable_)
{
}

Parameter::~Parameter()
{
}

Variable::Variable(soulng::cppcode::TypeId* type_, const std::u32string& name_) : Parameter(type_, name_, true)
{
}

NonterminalParser::NonterminalParser(const std::u32string& name_, const std::u32string& ruleName_) : Parser(name_), ruleName(ruleName_), rule(nullptr)
{
}

Parser* NonterminalParser::Clone() const
{
    NonterminalParser* clone = new NonterminalParser(Name(), ruleName);
    clone->args = args;
    return clone;
}

void NonterminalParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NonterminalParser::SetArguments(soulng::cppcode::ExpressionList* args_)
{
    if (args_)
    {
        for (const auto& arg : args_->Args())
        {
            args.push_back(arg);
            if (!arg->IsOwned())
            {
                arg->SetOwned();
                ownedArgs.push_back(std::unique_ptr<soulng::cppcode::CppObject>(arg));
            }
        }
    }
}

RuleParser::RuleParser(const std::u32string& name_) : Parser(name_), hasReturn(false)
{
}

GrammarParser* RuleParser::GetGrammar() const
{
    if (Parent())
    {
        if (Parent()->IsGrammar())
        {
            return static_cast<GrammarParser*>(Parent());
        }
        else
        {
            throw std::runtime_error("error: parent of rule not grammar");
        }
    }
    else
    {
        throw std::runtime_error("error: rule has no parent");
    }
}

void RuleParser::SetDefinition(Parser* definition_)
{
    definition.reset(definition_);
}

void RuleParser::AddParamOrVariable(Parameter* paramOrVariable)
{
    if (paramOrVariable->variable)
    {
        variables.push_back(std::unique_ptr<Variable>(static_cast<Variable*>(paramOrVariable)));
    }
    else
    {
        parameters.push_back(std::unique_ptr<Parameter>(paramOrVariable));
    }
}

void RuleParser::SetReturnType(soulng::cppcode::TypeId* returnType_)
{
    returnType.reset(returnType_);
}

void RuleParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void RuleParser::AddNonterminal(NonterminalParser* nonterminal)
{
    nonterminals.push_back(nonterminal);
}

void RuleParser::SetInfo(const std::u32string& info_)
{
    info = info_;
}

GrammarParser::GrammarParser(const std::u32string& name_, const std::u32string& api_) : Parser(name_), api(api_), main(false)
{
}

void GrammarParser::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void GrammarParser::AddUsing(const std::u32string& using_)
{
    usings.push_back(using_);
}

void GrammarParser::AddRule(RuleParser* rule)
{
    rule->SetParent(this);
    rules.push_back(std::unique_ptr<RuleParser>(rule));
    ruleMap[rule->Name()] = rule;
}

void GrammarParser::MapRule(RuleParser* rule)
{
    ruleMap[rule->Name()] = rule;
}

RuleParser* GrammarParser::GetRule(const std::u32string& ruleName) const
{
    auto it = ruleMap.find(ruleName);
    if (it != ruleMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("rule '" + ToUtf8(ruleName) + "' not found from parser '" + ToUtf8(Name()) + "'");
    }
}

void GrammarParser::AddRuleInfo(const std::u32string& ruleName, const std::u32string& ruleInfo)
{
    ruleInfos.push_back(std::make_pair(ruleName, ruleInfo));
}

} } // namespace sng2html::sng2html

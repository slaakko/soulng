#include "Lexer.hpp"
#include <soulng/parsing/Action.hpp>
#include <soulng/parsing/Rule.hpp>
#include <soulng/parsing/ParsingDomain.hpp>
#include <soulng/parsing/Primitive.hpp>
#include <soulng/parsing/Composite.hpp>
#include <soulng/parsing/Nonterminal.hpp>
#include <soulng/parsing/Exception.hpp>
#include <soulng/parsing/StdLib.hpp>
#include <soulng/parsing/XmlLog.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/code/Statement.hpp>
#include <soulng/code/Declarator.hpp>

namespace soulng { namespace lexergen {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

LexerGrammar* LexerGrammar::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

LexerGrammar* LexerGrammar::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    LexerGrammar* grammar(new LexerGrammar(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

LexerGrammar::LexerGrammar(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("LexerGrammar"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.lexergen")), parsingDomain_)
{
    SetOwner(0);
    keywords0.push_back(ToUtf32("actions"));
    keywords0.push_back(ToUtf32("api"));
    keywords0.push_back(ToUtf32("expressions"));
    keywords0.push_back(ToUtf32("keywords"));
    keywords0.push_back(ToUtf32("lexer"));
    keywords0.push_back(ToUtf32("tokens"));
}

LexerFile* LexerGrammar::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName)
{
    soulng::parsing::Scanner scanner(start, end, fileName, fileIndex, SkipRule());
    std::unique_ptr<soulng::parsing::XmlLog> xmlLog;
    if (Log())
    {
        xmlLog.reset(new soulng::parsing::XmlLog(*Log(), MaxLogLineLength()));
        scanner.SetLog(xmlLog.get());
        xmlLog->WriteBeginRule("parse");
    }
    soulng::parsing::ObjectStack stack;
    std::unique_ptr<soulng::parsing::ParsingData> parsingData(new soulng::parsing::ParsingData(GetParsingDomain()->GetNumRules()));
    scanner.SetParsingData(parsingData.get());
    soulng::parsing::Match match = soulng::parsing::Grammar::Parse(scanner, stack, parsingData.get());
    soulng::parsing::Span stop = scanner.GetSpan();
    if (Log())
    {
        xmlLog->WriteEndRule("parse");
    }
    if (!match.Hit() || stop.Start() != int(end - start))
    {
        if (StartRule())
        {
            throw soulng::parsing::ExpectationFailure(StartRule()->Info(), fileName, stop, start, end);
        }
        else
        {
            throw soulng::parsing::ParsingException("grammar '" + ToUtf8(Name()) + "' has no start rule", fileName, scanner.GetSpan(), start, end);
        }
    }
    std::unique_ptr<soulng::parsing::Object> value = std::move(stack.top());
    LexerFile* result = *static_cast<soulng::parsing::ValueObject<LexerFile*>*>(value.get());
    stack.pop();
    return result;
}

class LexerGrammar::LexerFileRule : public soulng::parsing::Rule
{
public:
    LexerFileRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("LexerFile*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<LexerFile*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LexerFileRule>(this, &LexerFileRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LexerFileRule>(this, &LexerFileRule::A1Action));
        soulng::parsing::NonterminalParser* declarationNonterminalParser = GetNonterminal(ToUtf32("Declaration"));
        declarationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LexerFileRule>(this, &LexerFileRule::PostDeclaration));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new LexerFile;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value->Add(context->fromDeclaration);
    }
    void PostDeclaration(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromDeclaration_value = std::move(stack.top());
            context->fromDeclaration = *static_cast<soulng::parsing::ValueObject<Declaration*>*>(fromDeclaration_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromDeclaration() {}
        LexerFile* value;
        Declaration* fromDeclaration;
    };
};

class LexerGrammar::DeclarationRule : public soulng::parsing::Rule
{
public:
    DeclarationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Declaration*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Declaration*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A4Action));
        soulng::parsing::ActionParser* a5ActionParser = GetAction(ToUtf32("A5"));
        a5ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A5Action));
        soulng::parsing::ActionParser* a6ActionParser = GetAction(ToUtf32("A6"));
        a6ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DeclarationRule>(this, &DeclarationRule::A6Action));
        soulng::parsing::NonterminalParser* classMapNonterminalParser = GetNonterminal(ToUtf32("ClassMap"));
        classMapNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::PostClassMap));
        soulng::parsing::NonterminalParser* prefixNonterminalParser = GetNonterminal(ToUtf32("Prefix"));
        prefixNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::PostPrefix));
        soulng::parsing::NonterminalParser* includeNonterminalParser = GetNonterminal(ToUtf32("Include"));
        includeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::PostInclude));
        soulng::parsing::NonterminalParser* tokensNonterminalParser = GetNonterminal(ToUtf32("Tokens"));
        tokensNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::PostTokens));
        soulng::parsing::NonterminalParser* keywordsNonterminalParser = GetNonterminal(ToUtf32("Keywords"));
        keywordsNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::PostKeywords));
        soulng::parsing::NonterminalParser* expressionsNonterminalParser = GetNonterminal(ToUtf32("Expressions"));
        expressionsNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::PostExpressions));
        soulng::parsing::NonterminalParser* lexerNonterminalParser = GetNonterminal(ToUtf32("Lexer"));
        lexerNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<DeclarationRule>(this, &DeclarationRule::PostLexer));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromClassMap;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromPrefix;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromInclude;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromTokens;
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromKeywords;
    }
    void A5Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromExpressions;
    }
    void A6Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromLexer;
    }
    void PostClassMap(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromClassMap_value = std::move(stack.top());
            context->fromClassMap = *static_cast<soulng::parsing::ValueObject<ClassMap*>*>(fromClassMap_value.get());
            stack.pop();
        }
    }
    void PostPrefix(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPrefix_value = std::move(stack.top());
            context->fromPrefix = *static_cast<soulng::parsing::ValueObject<Prefix*>*>(fromPrefix_value.get());
            stack.pop();
        }
    }
    void PostInclude(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromInclude_value = std::move(stack.top());
            context->fromInclude = *static_cast<soulng::parsing::ValueObject<Include*>*>(fromInclude_value.get());
            stack.pop();
        }
    }
    void PostTokens(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTokens_value = std::move(stack.top());
            context->fromTokens = *static_cast<soulng::parsing::ValueObject<Tokens*>*>(fromTokens_value.get());
            stack.pop();
        }
    }
    void PostKeywords(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromKeywords_value = std::move(stack.top());
            context->fromKeywords = *static_cast<soulng::parsing::ValueObject<Keywords*>*>(fromKeywords_value.get());
            stack.pop();
        }
    }
    void PostExpressions(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpressions_value = std::move(stack.top());
            context->fromExpressions = *static_cast<soulng::parsing::ValueObject<Expressions*>*>(fromExpressions_value.get());
            stack.pop();
        }
    }
    void PostLexer(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromLexer_value = std::move(stack.top());
            context->fromLexer = *static_cast<soulng::parsing::ValueObject<Lexer*>*>(fromLexer_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromClassMap(), fromPrefix(), fromInclude(), fromTokens(), fromKeywords(), fromExpressions(), fromLexer() {}
        Declaration* value;
        ClassMap* fromClassMap;
        Prefix* fromPrefix;
        Include* fromInclude;
        Tokens* fromTokens;
        Keywords* fromKeywords;
        Expressions* fromExpressions;
        Lexer* fromLexer;
    };
};

class LexerGrammar::ClassMapRule : public soulng::parsing::Rule
{
public:
    ClassMapRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("ClassMap*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<ClassMap*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ClassMapRule>(this, &ClassMapRule::A0Action));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("Identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ClassMapRule>(this, &ClassMapRule::PostIdentifier));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ClassMap(context->fromIdentifier);
    }
    void PostIdentifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdentifier_value = std::move(stack.top());
            context->fromIdentifier = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromIdentifier_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromIdentifier() {}
        ClassMap* value;
        std::u32string fromIdentifier;
    };
};

class LexerGrammar::PrefixRule : public soulng::parsing::Rule
{
public:
    PrefixRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Prefix*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Prefix*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrefixRule>(this, &PrefixRule::A0Action));
        soulng::parsing::NonterminalParser* prefixNonterminalParser = GetNonterminal(ToUtf32("prefix"));
        prefixNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrefixRule>(this, &PrefixRule::Postprefix));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Prefix(context->fromprefix);
    }
    void Postprefix(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromprefix_value = std::move(stack.top());
            context->fromprefix = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromprefix_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromprefix() {}
        Prefix* value;
        std::u32string fromprefix;
    };
};

class LexerGrammar::IncludeRule : public soulng::parsing::Rule
{
public:
    IncludeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Include*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Include*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IncludeRule>(this, &IncludeRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Include(std::u32string(matchBegin, matchEnd));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        Include* value;
    };
};

class LexerGrammar::TokensRule : public soulng::parsing::Rule
{
public:
    TokensRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Tokens*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Tokens*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TokensRule>(this, &TokensRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TokensRule>(this, &TokensRule::A1Action));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("Identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TokensRule>(this, &TokensRule::PostIdentifier));
        soulng::parsing::NonterminalParser* tokenNonterminalParser = GetNonterminal(ToUtf32("Token"));
        tokenNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TokensRule>(this, &TokensRule::PostToken));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Tokens(context->fromIdentifier);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value->Add(context->fromToken);
    }
    void PostIdentifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdentifier_value = std::move(stack.top());
            context->fromIdentifier = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromIdentifier_value.get());
            stack.pop();
        }
    }
    void PostToken(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromToken_value = std::move(stack.top());
            context->fromToken = *static_cast<soulng::parsing::ValueObject<Token>*>(fromToken_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromIdentifier(), fromToken() {}
        Tokens* value;
        std::u32string fromIdentifier;
        Token fromToken;
    };
};

class LexerGrammar::TokenRule : public soulng::parsing::Rule
{
public:
    TokenRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Token"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Token>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TokenRule>(this, &TokenRule::A0Action));
        soulng::parsing::NonterminalParser* idNonterminalParser = GetNonterminal(ToUtf32("id"));
        idNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TokenRule>(this, &TokenRule::Postid));
        soulng::parsing::NonterminalParser* infoNonterminalParser = GetNonterminal(ToUtf32("info"));
        infoNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<TokenRule>(this, &TokenRule::Postinfo));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = Token(context->fromid, ToUtf8(context->frominfo));
    }
    void Postid(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromid_value = std::move(stack.top());
            context->fromid = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromid_value.get());
            stack.pop();
        }
    }
    void Postinfo(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frominfo_value = std::move(stack.top());
            context->frominfo = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(frominfo_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromid(), frominfo() {}
        Token value;
        std::u32string fromid;
        std::u32string frominfo;
    };
};

class LexerGrammar::KeywordsRule : public soulng::parsing::Rule
{
public:
    KeywordsRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Keywords*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Keywords*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<KeywordsRule>(this, &KeywordsRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<KeywordsRule>(this, &KeywordsRule::A1Action));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("Identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordsRule>(this, &KeywordsRule::PostIdentifier));
        soulng::parsing::NonterminalParser* keywordNonterminalParser = GetNonterminal(ToUtf32("Keyword"));
        keywordNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordsRule>(this, &KeywordsRule::PostKeyword));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Keywords(context->fromIdentifier);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value->Add(context->fromKeyword);
    }
    void PostIdentifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdentifier_value = std::move(stack.top());
            context->fromIdentifier = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromIdentifier_value.get());
            stack.pop();
        }
    }
    void PostKeyword(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromKeyword_value = std::move(stack.top());
            context->fromKeyword = *static_cast<soulng::parsing::ValueObject<Keyword*>*>(fromKeyword_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromIdentifier(), fromKeyword() {}
        Keywords* value;
        std::u32string fromIdentifier;
        Keyword* fromKeyword;
    };
};

class LexerGrammar::KeywordRule : public soulng::parsing::Rule
{
public:
    KeywordRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Keyword*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Keyword*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<KeywordRule>(this, &KeywordRule::A0Action));
        soulng::parsing::NonterminalParser* kwNonterminalParser = GetNonterminal(ToUtf32("kw"));
        kwNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordRule>(this, &KeywordRule::Postkw));
        soulng::parsing::NonterminalParser* tknNonterminalParser = GetNonterminal(ToUtf32("tkn"));
        tknNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordRule>(this, &KeywordRule::Posttkn));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Keyword(context->fromkw, context->fromtkn);
    }
    void Postkw(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromkw_value = std::move(stack.top());
            context->fromkw = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromkw_value.get());
            stack.pop();
        }
    }
    void Posttkn(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromtkn_value = std::move(stack.top());
            context->fromtkn = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromtkn_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromkw(), fromtkn() {}
        Keyword* value;
        std::u32string fromkw;
        std::u32string fromtkn;
    };
};

class LexerGrammar::ExpressionsRule : public soulng::parsing::Rule
{
public:
    ExpressionsRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Expressions*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("int"), ToUtf32("index")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Expressions*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExpressionsRule>(this, &ExpressionsRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExpressionsRule>(this, &ExpressionsRule::A1Action));
        soulng::parsing::NonterminalParser* expressionNonterminalParser = GetNonterminal(ToUtf32("Expression"));
        expressionNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<ExpressionsRule>(this, &ExpressionsRule::PreExpression));
        expressionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ExpressionsRule>(this, &ExpressionsRule::PostExpression));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Expressions;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value->Add(context->fromExpression);
        context->index = context->index + 1;
    }
    void PreExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<int>(context->index)));
    }
    void PostExpression(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromExpression_value = std::move(stack.top());
            context->fromExpression = *static_cast<soulng::parsing::ValueObject<Expression*>*>(fromExpression_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), index(), fromExpression() {}
        Expressions* value;
        int index;
        Expression* fromExpression;
    };
};

class LexerGrammar::ExpressionRule : public soulng::parsing::Rule
{
public:
    ExpressionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("int"), ToUtf32("index")));
        SetValueTypeName(ToUtf32("Expression*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> index_value = std::move(stack.top());
        context->index = *static_cast<soulng::parsing::ValueObject<int>*>(index_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Expression*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExpressionRule>(this, &ExpressionRule::A0Action));
        soulng::parsing::NonterminalParser* idNonterminalParser = GetNonterminal(ToUtf32("id"));
        idNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ExpressionRule>(this, &ExpressionRule::Postid));
        soulng::parsing::NonterminalParser* valNonterminalParser = GetNonterminal(ToUtf32("val"));
        valNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ExpressionRule>(this, &ExpressionRule::Postval));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Expression(context->index, context->fromid, context->fromval);
    }
    void Postid(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromid_value = std::move(stack.top());
            context->fromid = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromid_value.get());
            stack.pop();
        }
    }
    void Postval(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromval_value = std::move(stack.top());
            context->fromval = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromval_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): index(), value(), fromid(), fromval() {}
        int index;
        Expression* value;
        std::u32string fromid;
        std::u32string fromval;
    };
};

class LexerGrammar::ExprRule : public soulng::parsing::Rule
{
public:
    ExprRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::u32string"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::u32string>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExprRule>(this, &ExprRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ExprRule>(this, &ExprRule::A1Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value.append(1, '"');
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value.append(1, *matchBegin);
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        std::u32string value;
    };
};

class LexerGrammar::VariableRule : public soulng::parsing::Rule
{
public:
    VariableRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Variable*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Variable*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<VariableRule>(this, &VariableRule::A0Action));
        soulng::parsing::NonterminalParser* typeNonterminalParser = GetNonterminal(ToUtf32("type"));
        typeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<VariableRule>(this, &VariableRule::Posttype));
        soulng::parsing::NonterminalParser* nameNonterminalParser = GetNonterminal(ToUtf32("name"));
        nameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<VariableRule>(this, &VariableRule::Postname));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Variable(context->fromtype, context->fromname);
    }
    void Posttype(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromtype_value = std::move(stack.top());
            context->fromtype = *static_cast<soulng::parsing::ValueObject<soulng::codedom::TypeId*>*>(fromtype_value.get());
            stack.pop();
        }
    }
    void Postname(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromname_value = std::move(stack.top());
            context->fromname = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromname_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromtype(), fromname() {}
        Variable* value;
        soulng::codedom::TypeId* fromtype;
        std::u32string fromname;
    };
};

class LexerGrammar::LexerRule : public soulng::parsing::Rule
{
public:
    LexerRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Lexer*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Lexer*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LexerRule>(this, &LexerRule::A0Action));
        soulng::parsing::NonterminalParser* apiNonterminalParser = GetNonterminal(ToUtf32("Api"));
        apiNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LexerRule>(this, &LexerRule::PostApi));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("Identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LexerRule>(this, &LexerRule::PostIdentifier));
        soulng::parsing::NonterminalParser* lexerClauseNonterminalParser = GetNonterminal(ToUtf32("LexerClause"));
        lexerClauseNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<LexerRule>(this, &LexerRule::PreLexerClause));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Lexer(context->fromApi, context->fromIdentifier);
    }
    void PostApi(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromApi_value = std::move(stack.top());
            context->fromApi = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromApi_value.get());
            stack.pop();
        }
    }
    void PostIdentifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdentifier_value = std::move(stack.top());
            context->fromIdentifier = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromIdentifier_value.get());
            stack.pop();
        }
    }
    void PreLexerClause(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Lexer*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromApi(), fromIdentifier() {}
        Lexer* value;
        std::u32string fromApi;
        std::u32string fromIdentifier;
    };
};

class LexerGrammar::LexerClauseRule : public soulng::parsing::Rule
{
public:
    LexerClauseRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("Lexer*"), ToUtf32("lexer")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexer_value = std::move(stack.top());
        context->lexer = *static_cast<soulng::parsing::ValueObject<Lexer*>*>(lexer_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LexerClauseRule>(this, &LexerClauseRule::A0Action));
        soulng::parsing::NonterminalParser* exprNonterminalParser = GetNonterminal(ToUtf32("expr"));
        exprNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LexerClauseRule>(this, &LexerClauseRule::Postexpr));
        soulng::parsing::NonterminalParser* actionNonterminalParser = GetNonterminal(ToUtf32("action"));
        actionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LexerClauseRule>(this, &LexerClauseRule::Postaction));
        soulng::parsing::NonterminalParser* stmtNonterminalParser = GetNonterminal(ToUtf32("stmt"));
        stmtNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<LexerClauseRule>(this, &LexerClauseRule::Poststmt));
        soulng::parsing::NonterminalParser* variablesNonterminalParser = GetNonterminal(ToUtf32("Variables"));
        variablesNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<LexerClauseRule>(this, &LexerClauseRule::PreVariables));
        soulng::parsing::NonterminalParser* actionsNonterminalParser = GetNonterminal(ToUtf32("Actions"));
        actionsNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<LexerClauseRule>(this, &LexerClauseRule::PreActions));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->lexer->AddStatement(new LexerStatement(context->fromexpr, context->fromstmt, context->fromaction));
    }
    void Postexpr(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromexpr_value = std::move(stack.top());
            context->fromexpr = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromexpr_value.get());
            stack.pop();
        }
    }
    void Postaction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromaction_value = std::move(stack.top());
            context->fromaction = *static_cast<soulng::parsing::ValueObject<int>*>(fromaction_value.get());
            stack.pop();
        }
    }
    void Poststmt(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromstmt_value = std::move(stack.top());
            context->fromstmt = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CompoundStatement*>*>(fromstmt_value.get());
            stack.pop();
        }
    }
    void PreVariables(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Lexer*>(context->lexer)));
    }
    void PreActions(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Lexer*>(context->lexer)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexer(), fromexpr(), fromaction(), fromstmt() {}
        Lexer* lexer;
        std::u32string fromexpr;
        int fromaction;
        soulng::codedom::CompoundStatement* fromstmt;
    };
};

class LexerGrammar::VariablesRule : public soulng::parsing::Rule
{
public:
    VariablesRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("Lexer*"), ToUtf32("lexer")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexer_value = std::move(stack.top());
        context->lexer = *static_cast<soulng::parsing::ValueObject<Lexer*>*>(lexer_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<VariablesRule>(this, &VariablesRule::A0Action));
        soulng::parsing::NonterminalParser* variableNonterminalParser = GetNonterminal(ToUtf32("variable"));
        variableNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<VariablesRule>(this, &VariablesRule::Postvariable));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->lexer->AddVariable(context->fromvariable);
    }
    void Postvariable(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromvariable_value = std::move(stack.top());
            context->fromvariable = *static_cast<soulng::parsing::ValueObject<Variable*>*>(fromvariable_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexer(), fromvariable() {}
        Lexer* lexer;
        Variable* fromvariable;
    };
};

class LexerGrammar::IdentifierRule : public soulng::parsing::Rule
{
public:
    IdentifierRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::u32string"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::u32string>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IdentifierRule>(this, &IdentifierRule::A0Action));
        soulng::parsing::NonterminalParser* identifierNonterminalParser = GetNonterminal(ToUtf32("identifier"));
        identifierNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<IdentifierRule>(this, &IdentifierRule::Postidentifier));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromidentifier;
    }
    void Postidentifier(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromidentifier_value = std::move(stack.top());
            context->fromidentifier = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromidentifier_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromidentifier() {}
        std::u32string value;
        std::u32string fromidentifier;
    };
};

class LexerGrammar::ApiRule : public soulng::parsing::Rule
{
public:
    ApiRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::u32string"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::u32string>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ApiRule>(this, &ApiRule::A0Action));
        soulng::parsing::NonterminalParser* idNonterminalParser = GetNonterminal(ToUtf32("id"));
        idNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ApiRule>(this, &ApiRule::Postid));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromid;
    }
    void Postid(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromid_value = std::move(stack.top());
            context->fromid = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromid_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromid() {}
        std::u32string value;
        std::u32string fromid;
    };
};

class LexerGrammar::ActionsRule : public soulng::parsing::Rule
{
public:
    ActionsRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("Lexer*"), ToUtf32("lexer")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> lexer_value = std::move(stack.top());
        context->lexer = *static_cast<soulng::parsing::ValueObject<Lexer*>*>(lexer_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ActionsRule>(this, &ActionsRule::A0Action));
        soulng::parsing::NonterminalParser* actionNonterminalParser = GetNonterminal(ToUtf32("action"));
        actionNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ActionsRule>(this, &ActionsRule::Postaction));
        soulng::parsing::NonterminalParser* stmtNonterminalParser = GetNonterminal(ToUtf32("stmt"));
        stmtNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ActionsRule>(this, &ActionsRule::Poststmt));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->lexer->AddAction(new soulng::lexergen::Action(context->fromaction, context->fromstmt));
    }
    void Postaction(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromaction_value = std::move(stack.top());
            context->fromaction = *static_cast<soulng::parsing::ValueObject<int>*>(fromaction_value.get());
            stack.pop();
        }
    }
    void Poststmt(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromstmt_value = std::move(stack.top());
            context->fromstmt = *static_cast<soulng::parsing::ValueObject<soulng::codedom::CompoundStatement*>*>(fromstmt_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): lexer(), fromaction(), fromstmt() {}
        Lexer* lexer;
        int fromaction;
        soulng::codedom::CompoundStatement* fromstmt;
    };
};

class LexerGrammar::ActionRule : public soulng::parsing::Rule
{
public:
    ActionRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("int"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<int>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ActionRule>(this, &ActionRule::A0Action));
        soulng::parsing::NonterminalParser* iNonterminalParser = GetNonterminal(ToUtf32("i"));
        iNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ActionRule>(this, &ActionRule::Posti));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromi;
    }
    void Posti(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromi_value = std::move(stack.top());
            context->fromi = *static_cast<soulng::parsing::ValueObject<int32_t>*>(fromi_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromi() {}
        int value;
        int32_t fromi;
    };
};

void LexerGrammar::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar0)
    {
        grammar0 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.code.Declarator"));
    if (!grammar1)
    {
        grammar1 = soulng::code::Declarator::Create(pd);
    }
    AddGrammarReference(grammar1);
    soulng::parsing::Grammar* grammar2 = pd->GetGrammar(ToUtf32("soulng.code.Statement"));
    if (!grammar2)
    {
        grammar2 = soulng::code::Statement::Create(pd);
    }
    AddGrammarReference(grammar2);
}

void LexerGrammar::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("string"), this, ToUtf32("soulng.parsing.stdlib.string")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("identifier"), this, ToUtf32("soulng.parsing.stdlib.identifier")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("int"), this, ToUtf32("soulng.parsing.stdlib.int")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("TypeId"), this, ToUtf32("soulng.code.Declarator.TypeId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("spaces_and_comments"), this, ToUtf32("soulng.parsing.stdlib.spaces_and_comments")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("CompoundStatement"), this, ToUtf32("soulng.code.Statement.CompoundStatement")));
    AddRule(new LexerFileRule(ToUtf32("LexerFile"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::EmptyParser()),
            new soulng::parsing::KleeneStarParser(
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Declaration"), ToUtf32("Declaration"), 0)))))));
    AddRule(new DeclarationRule(ToUtf32("Declaration"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::ActionParser(ToUtf32("A0"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("ClassMap"), ToUtf32("ClassMap"), 0)),
                                new soulng::parsing::ActionParser(ToUtf32("A1"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("Prefix"), ToUtf32("Prefix"), 0))),
                            new soulng::parsing::ActionParser(ToUtf32("A2"),
                                new soulng::parsing::NonterminalParser(ToUtf32("Include"), ToUtf32("Include"), 0))),
                        new soulng::parsing::ActionParser(ToUtf32("A3"),
                            new soulng::parsing::NonterminalParser(ToUtf32("Tokens"), ToUtf32("Tokens"), 0))),
                    new soulng::parsing::ActionParser(ToUtf32("A4"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Keywords"), ToUtf32("Keywords"), 0))),
                new soulng::parsing::ActionParser(ToUtf32("A5"),
                    new soulng::parsing::NonterminalParser(ToUtf32("Expressions"), ToUtf32("Expressions"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A6"),
                new soulng::parsing::NonterminalParser(ToUtf32("Lexer"), ToUtf32("Lexer"), 0)))));
    AddRule(new ClassMapRule(ToUtf32("ClassMap"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::KeywordParser(ToUtf32("classmap")),
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("Identifier"), ToUtf32("Identifier"), 0)))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser(';')))));
    AddRule(new PrefixRule(ToUtf32("Prefix"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::KeywordParser(ToUtf32("prefix")),
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("prefix"), ToUtf32("string"), 0)))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser(';')))));
    AddRule(new IncludeRule(ToUtf32("Include"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::StringParser(ToUtf32("#include")),
                    new soulng::parsing::TokenParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('<'),
                                new soulng::parsing::KleeneStarParser(
                                    new soulng::parsing::CharSetParser(ToUtf32(">"), true))),
                            new soulng::parsing::CharParser('>'))))))));
    AddRule(new TokensRule(ToUtf32("Tokens"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("tokens")),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("Identifier"), ToUtf32("Identifier"), 0)))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ListParser(
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::NonterminalParser(ToUtf32("Token"), ToUtf32("Token"), 0)),
                            new soulng::parsing::CharParser(','))))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new TokenRule(ToUtf32("Token"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('('),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("id"), ToUtf32("Identifier"), 0))),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::CharParser(','))),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("info"), ToUtf32("string"), 0))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(')')))))));
    AddRule(new KeywordsRule(ToUtf32("Keywords"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("keywords")),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("Identifier"), ToUtf32("Identifier"), 0)))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::OptionalParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ListParser(
                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                new soulng::parsing::NonterminalParser(ToUtf32("Keyword"), ToUtf32("Keyword"), 0)),
                            new soulng::parsing::CharParser(','))))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new KeywordRule(ToUtf32("Keyword"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::CharParser('('),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("kw"), ToUtf32("string"), 0))),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::CharParser(','))),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("tkn"), ToUtf32("Identifier"), 0))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(')')))))));
    AddRule(new ExpressionsRule(ToUtf32("Expressions"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::KeywordParser(ToUtf32("expressions"))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::KleeneStarParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ActionParser(ToUtf32("A1"),
                            new soulng::parsing::NonterminalParser(ToUtf32("Expression"), ToUtf32("Expression"), 1))))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new ExpressionRule(ToUtf32("Expression"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("id"), ToUtf32("Identifier"), 0),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::CharParser('='))),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("val"), ToUtf32("Expr"), 0))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(';')))))));
    AddRule(new ExprRule(ToUtf32("Expr"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::TokenParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::CharParser('\"'),
                    new soulng::parsing::KleeneStarParser(
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::ActionParser(ToUtf32("A0"),
                                    new soulng::parsing::GroupingParser(
                                        new soulng::parsing::SequenceParser(
                                            new soulng::parsing::CharParser('\\'),
                                            new soulng::parsing::CharParser('\"')))),
                                new soulng::parsing::ActionParser(ToUtf32("A1"),
                                    new soulng::parsing::CharSetParser(ToUtf32("\""), true)))))),
                new soulng::parsing::CharParser('\"')))));
    AddRule(new VariableRule(ToUtf32("Variable"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("type"), ToUtf32("TypeId"), 0),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("name"), ToUtf32("Identifier"), 0))),
                    new soulng::parsing::CharParser(';'))))));
    AddRule(new LexerRule(ToUtf32("Lexer"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::KeywordParser(ToUtf32("lexer")),
                            new soulng::parsing::NonterminalParser(ToUtf32("Api"), ToUtf32("Api"), 0)),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("Identifier"), ToUtf32("Identifier"), 0)))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::KleeneStarParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::NonterminalParser(ToUtf32("LexerClause"), ToUtf32("LexerClause"), 1)))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new LexerClauseRule(ToUtf32("LexerClause"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::ActionParser(ToUtf32("A0"),
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("expr"), ToUtf32("Expr"), 0),
                                new soulng::parsing::OptionalParser(
                                    new soulng::parsing::GroupingParser(
                                        new soulng::parsing::NonterminalParser(ToUtf32("action"), ToUtf32("Action"), 0)))),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("stmt"), ToUtf32("CompoundStatement"), 0))))),
                new soulng::parsing::NonterminalParser(ToUtf32("Variables"), ToUtf32("Variables"), 1)),
            new soulng::parsing::NonterminalParser(ToUtf32("Actions"), ToUtf32("Actions"), 1))));
    AddRule(new VariablesRule(ToUtf32("Variables"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("variables")),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::KleeneStarParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::NonterminalParser(ToUtf32("variable"), ToUtf32("Variable"), 0))))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new IdentifierRule(ToUtf32("Identifier"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::DifferenceParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("identifier"), ToUtf32("identifier"), 0),
                    new soulng::parsing::NonterminalParser(ToUtf32("LexerKeyword"), ToUtf32("LexerKeyword"), 0))))));
    AddRule(new ApiRule(ToUtf32("Api"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::GroupingParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::KeywordParser(ToUtf32("api")),
                                new soulng::parsing::CharParser('(')),
                            new soulng::parsing::NonterminalParser(ToUtf32("id"), ToUtf32("identifier"), 0)),
                        new soulng::parsing::CharParser(')')))),
            new soulng::parsing::EmptyParser())));
    AddRule(new soulng::parsing::Rule(ToUtf32("LexerKeyword"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::KeywordListParser(ToUtf32("identifier"), keywords0)));
    AddRule(new ActionsRule(ToUtf32("Actions"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("actions")),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('{'))),
                new soulng::parsing::KleeneStarParser(
                    new soulng::parsing::GroupingParser(
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::SequenceParser(
                                        new soulng::parsing::NonterminalParser(ToUtf32("action"), ToUtf32("Action"), 0),
                                        new soulng::parsing::ExpectationParser(
                                            new soulng::parsing::CharParser('='))),
                                    new soulng::parsing::ExpectationParser(
                                        new soulng::parsing::NonterminalParser(ToUtf32("stmt"), ToUtf32("CompoundStatement"), 0)))))))),
            new soulng::parsing::ExpectationParser(
                new soulng::parsing::CharParser('}')))));
    AddRule(new ActionRule(ToUtf32("Action"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::TokenParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('$'),
                        new soulng::parsing::CharParser('(')),
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("i"), ToUtf32("int"), 0))),
                new soulng::parsing::CharParser(')')))));
    SetSkipRuleName(ToUtf32("spaces_and_comments"));
}

} } // namespace soulng.lexergen

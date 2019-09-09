#include "ProjectFile.hpp"
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

namespace soulng { namespace syntax {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

ProjectFile* ProjectFile::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

ProjectFile* ProjectFile::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    ProjectFile* grammar(new ProjectFile(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

ProjectFile::ProjectFile(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("ProjectFile"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.syntax")), parsingDomain_)
{
    SetOwner(0);
}

Project* ProjectFile::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName)
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
    Project* result = *static_cast<soulng::parsing::ValueObject<Project*>*>(value.get());
    stack.pop();
    return result;
}

class ProjectFile::ProjectFileRule : public soulng::parsing::Rule
{
public:
    ProjectFileRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("Project*"));
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
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Project*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ProjectFileRule>(this, &ProjectFileRule::A0Action));
        soulng::parsing::NonterminalParser* projectNameNonterminalParser = GetNonterminal(ToUtf32("projectName"));
        projectNameNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ProjectFileRule>(this, &ProjectFileRule::PostprojectName));
        soulng::parsing::NonterminalParser* projectFileContentNonterminalParser = GetNonterminal(ToUtf32("ProjectFileContent"));
        projectFileContentNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<ProjectFileRule>(this, &ProjectFileRule::PreProjectFileContent));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new Project(ToUtf8(context->fromprojectName), fileName);
    }
    void PostprojectName(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromprojectName_value = std::move(stack.top());
            context->fromprojectName = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromprojectName_value.get());
            stack.pop();
        }
    }
    void PreProjectFileContent(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<Project*>(context->value)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromprojectName() {}
        Project* value;
        std::u32string fromprojectName;
    };
};

class ProjectFile::ProjectFileContentRule : public soulng::parsing::Rule
{
public:
    ProjectFileContentRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        AddInheritedAttribute(AttrOrVariable(ToUtf32("Project*"), ToUtf32("project")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        std::unique_ptr<soulng::parsing::Object> project_value = std::move(stack.top());
        context->project = *static_cast<soulng::parsing::ValueObject<Project*>*>(project_value.get());
        stack.pop();
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ProjectFileContentRule>(this, &ProjectFileContentRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ProjectFileContentRule>(this, &ProjectFileContentRule::A1Action));
        soulng::parsing::NonterminalParser* sourceNonterminalParser = GetNonterminal(ToUtf32("Source"));
        sourceNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ProjectFileContentRule>(this, &ProjectFileContentRule::PostSource));
        soulng::parsing::NonterminalParser* referenceNonterminalParser = GetNonterminal(ToUtf32("Reference"));
        referenceNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ProjectFileContentRule>(this, &ProjectFileContentRule::PostReference));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->project->AddSourceFile(ToUtf8(context->fromSource));
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->project->AddReferenceFile(ToUtf8(context->fromReference));
    }
    void PostSource(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSource_value = std::move(stack.top());
            context->fromSource = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromSource_value.get());
            stack.pop();
        }
    }
    void PostReference(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromReference_value = std::move(stack.top());
            context->fromReference = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromReference_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): project(), fromSource(), fromReference() {}
        Project* project;
        std::u32string fromSource;
        std::u32string fromReference;
    };
};

class ProjectFile::SourceRule : public soulng::parsing::Rule
{
public:
    SourceRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SourceRule>(this, &SourceRule::A0Action));
        soulng::parsing::NonterminalParser* filePathNonterminalParser = GetNonterminal(ToUtf32("FilePath"));
        filePathNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<SourceRule>(this, &SourceRule::PostFilePath));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromFilePath;
    }
    void PostFilePath(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromFilePath_value = std::move(stack.top());
            context->fromFilePath = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromFilePath_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromFilePath() {}
        std::u32string value;
        std::u32string fromFilePath;
    };
};

class ProjectFile::ReferenceRule : public soulng::parsing::Rule
{
public:
    ReferenceRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ReferenceRule>(this, &ReferenceRule::A0Action));
        soulng::parsing::NonterminalParser* filePathNonterminalParser = GetNonterminal(ToUtf32("FilePath"));
        filePathNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<ReferenceRule>(this, &ReferenceRule::PostFilePath));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromFilePath;
    }
    void PostFilePath(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromFilePath_value = std::move(stack.top());
            context->fromFilePath = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromFilePath_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromFilePath() {}
        std::u32string value;
        std::u32string fromFilePath;
    };
};

class ProjectFile::FilePathRule : public soulng::parsing::Rule
{
public:
    FilePathRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
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
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<FilePathRule>(this, &FilePathRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = std::u32string(matchBegin, matchEnd);
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        std::u32string value;
    };
};

void ProjectFile::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar0)
    {
        grammar0 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar0);
}

void ProjectFile::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("qualified_id"), this, ToUtf32("soulng.parsing.stdlib.qualified_id")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("spaces_and_comments"), this, ToUtf32("soulng.parsing.stdlib.spaces_and_comments")));
    AddRule(new ProjectFileRule(ToUtf32("ProjectFile"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("project")),
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("projectName"), ToUtf32("qualified_id"), 0))),
                new soulng::parsing::CharParser(';')),
            new soulng::parsing::NonterminalParser(ToUtf32("ProjectFileContent"), ToUtf32("ProjectFileContent"), 1))));
    AddRule(new ProjectFileContentRule(ToUtf32("ProjectFileContent"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::KleeneStarParser(
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Source"), ToUtf32("Source"), 0)),
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Reference"), ToUtf32("Reference"), 0)))))));
    AddRule(new SourceRule(ToUtf32("Source"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("source")),
                        new soulng::parsing::NonterminalParser(ToUtf32("FilePath"), ToUtf32("FilePath"), 0)),
                    new soulng::parsing::CharParser(';'))))));
    AddRule(new ReferenceRule(ToUtf32("Reference"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::KeywordParser(ToUtf32("reference")),
                        new soulng::parsing::NonterminalParser(ToUtf32("FilePath"), ToUtf32("FilePath"), 0)),
                    new soulng::parsing::CharParser(';'))))));
    AddRule(new FilePathRule(ToUtf32("FilePath"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::TokenParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::CharParser('<'),
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::GroupingParser(
                            new soulng::parsing::PositiveParser(
                                new soulng::parsing::CharSetParser(ToUtf32(">\r\n"), true))))),
                new soulng::parsing::CharParser('>')))));
    SetSkipRuleName(ToUtf32("spaces_and_comments"));
}

} } // namespace soulng.syntax

// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SYNTAX_PARSERFILECONTENT_INCLUDED
#define SOULNG_SYNTAX_PARSERFILECONTENT_INCLUDED

#include <soulng/parsing/ParsingDomain.hpp>
#include <soulng/parsing/Namespace.hpp>

namespace soulng { namespace syntax {

class ParserFileContent
{
public:
    ParserFileContent(int id_, soulng::parsing::ParsingDomain* parsingDomain_);
    void SetFilePath(const std::string& filePath_) { filePath = filePath_; }
    void AddIncludeDirective(const std::string& includeDirective_, const std::string& fileAttribute_);
    void AddUsingObject(soulng::codedom::UsingObject* usingObjectSubject);
    void AddGrammar(soulng::parsing::Grammar* grammar);
    void BeginNamespace(const std::u32string& ns);
    void EndNamespace();
    int Id() const { return id; }
    const std::string& FilePath() const { return filePath; }
    soulng::parsing::ParsingDomain* ParsingDomain() const { return parsingDomain; }
    const std::vector<std::pair<std::string, std::string>>& IncludeDirectives() const { return includeDirectives; }
    const std::vector<std::unique_ptr<soulng::parsing::UsingObject>>& UsingObjects() const { return usingObjects; }
    soulng::parsing::Scope* CurrentScope() const { return parsingDomain->CurrentScope(); }
private:
    int id;
    std::string filePath;
    soulng::parsing::ParsingDomain* parsingDomain;
    std::vector<std::pair<std::string, std::string>> includeDirectives;
    std::vector<std::unique_ptr<soulng::parsing::UsingObject>> usingObjects;
};

} } // namespace soulng::syntax

#endif // SOULNG_SYNTAX_PARSERFILECONTENT_INCLUDED

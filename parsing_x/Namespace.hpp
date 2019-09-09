// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSING_NAMESPACE_INCLUDED
#define SOULNG_PARSING_NAMESPACE_INCLUDED
#include <soulng/parsing/ParsingObject.hpp>
#include <soulng/codedom/Declaration.hpp>

namespace soulng { namespace parsing {

class PARSING_API Namespace: public ParsingObject
{
public:
    Namespace(const std::u32string& name_, Scope* enclosingScope_);
    void Accept(Visitor& visitor) override;
    bool IsNamespace() const override { return true; }
};

class Scope;

class PARSING_API UsingObject: public ParsingObject
{
public:
    UsingObject(soulng::codedom::UsingObject* subject_, Scope* enclosingScope_);
    void Accept(Visitor& visitor) override;
    soulng::codedom::UsingObject* Subject() const { return subject; }
private:
    soulng::codedom::UsingObject* subject;
    std::unique_ptr<soulng::codedom::UsingObject> ownedSubject;
};

} } // namespace soulng::parsing

#endif // SOULNG_PARSING_NAMESPACE_INCLUDED

// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_SYMBOL_INCLUDED
#include <sngcpp/symbols/SymbolsApi.hpp>
#include <sngcpp/ast/Specifier.hpp>
#include <sngxml/dom/Element.hpp>
#include <soulng/lexer/Span.hpp>

namespace sngcpp { namespace symbols {

using soulng::lexer::Span;

using namespace sngcpp::ast;

class ContainerSymbol;
class ContainerScope;
class TypeSymbol;
class ClassTypeSymbol;

enum class SymbolAccess : uint8_t
{
    public_, protected_, private_
};

SNGCPP_SYMBOLS_API std::u32string ToString(SymbolAccess access);

class SNGCPP_SYMBOLS_API Symbol
{
public:
    Symbol(const Span& span_, const std::u32string& name_);
    Symbol(const Symbol&) = delete;
    Symbol(Symbol&&) = delete;
    Symbol& operator=(const Symbol&) = delete;
    Symbol& operator=(Symbol&&) = delete;
    virtual ~Symbol();
    const Span& GetSpan() const { return span; }
    const std::u32string& Name() const { return name; }
    void SetName(const std::u32string& name_) { name = name_; }
    virtual bool NameBefore(Symbol* that) { return name < that->Name(); }
    virtual const std::u32string& SimpleName() const { return name; }
    virtual TypeSymbol* GetType() { return nullptr; }
    virtual bool IsParentSymbol() const { return false; }
    std::u32string FullName();
    SymbolAccess Access() const { return access; }
    void SetAccess(Specifier accessSpecifier);
    virtual ContainerScope* GetContainerScope() { return nullptr; }
    virtual std::u32string KindStr() = 0;
    virtual std::u32string IdStr();
    virtual std::u32string Id();
    virtual std::unique_ptr<sngxml::dom::Element> CreateElement() = 0;
    std::unique_ptr<sngxml::dom::Element> ToDomElement();
    virtual std::unique_ptr<sngxml::dom::Element> Namespaces();
    virtual std::unique_ptr<sngxml::dom::Element> Classes();
    virtual std::unique_ptr<sngxml::dom::Element> Constructors();
    virtual std::unique_ptr<sngxml::dom::Element> Functions();
    virtual std::unique_ptr<sngxml::dom::Element> EnumTypes();
    virtual std::unique_ptr<sngxml::dom::Element> Enumerators();
    virtual std::unique_ptr<sngxml::dom::Element> Typedefs();
    virtual std::unique_ptr<sngxml::dom::Element> Variables();
    virtual std::unique_ptr<sngxml::dom::Element> Grammars();
    ContainerSymbol* Parent() { return parent; }
    void SetParent(ContainerSymbol* parent_) { parent = parent_; }
    ClassTypeSymbol* Class();
    virtual bool IsInstallSymbol() const { return true; }
    virtual bool IsNamespaceSymbol() const { return false; }
    virtual bool IsContainerSymbol() const { return false; }
    virtual bool IsTypeSymbol() const { return false; }
    virtual bool IsClassTypeSymbol() const { return false; }
    virtual bool IsClassTemplateSpecializationSymbol() const { return false; }
    virtual bool IsConstructorSymbol() const { return false; }
    virtual bool IsDestructorSymbol() const { return false; }
    virtual bool IsCallableSymbol() const { return false; }
    virtual bool IsFunctionSymbol() const { return false; }
    virtual bool IsFunctionDeclarationSymbol() const { return false; }
    virtual bool IsConstructorDeclarationSymbol() const { return false; }
    virtual bool IsFunctionGroupSymbol() const { return false; }
    virtual bool IsClassGroupSymbol() const { return false; }
    virtual bool IsClassGroupTypeSymbol() const { return  false; }
    virtual bool IsEnumTypeSymbol() const { return false; }
    virtual bool IsEnumeratorSymbol() const { return false; }
    virtual bool IsTypedefSymbol() const { return false; }
    virtual bool IsParameterSymbol() const { return false; }
    virtual bool IsVariableSymbol() const { return false; }
    virtual bool IsDeclarationBlockSymbol() const { return false; }
    virtual bool IsGrammarSymbol() const { return false; }
    virtual bool IsRuleSymbol() const { return false; }
    void SetProjectName(const std::u32string& projectName_);
    const std::u32string& ProjectName() const { return projectName; }
private:
    Span span;
    std::u32string name;
    ContainerSymbol* parent;
    SymbolAccess access;
    std::u32string projectName;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_INCLUDED

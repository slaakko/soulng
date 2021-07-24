// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

class TemplateDeclarationSymbol;
class TemplateParameterSymbol;

class SYMBOLS_API ClassTypeSymbol : public TypeSymbol
{
public:
    ClassTypeSymbol(const std::u32string& name_);
    bool IsClassTemplate() const;
    TemplateDeclarationSymbol* GetTemplateDeclarationSymbol() const { return templateDeclarationSymbol; }
    void SetTemplateDeclarationSymbol(TemplateDeclarationSymbol* templateDeclarationSymbol_) { templateDeclarationSymbol = templateDeclarationSymbol_; }
    std::string SymbolKindStr() const override { return "class type symbol"; }
    void AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context) override;
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    Scope* GetGroupScope() override { return groupScope; }
    void SetIdNode(Node* idNode_) { idNode = idNode_; }
    Node* IdNode() const { return idNode; }
    int Level() const;
    const std::vector<Symbol*>& BaseClasses() const { return baseClasses; }
    void AddBaseClass(Symbol* baseClass, const SourcePos& sourcePos, Context* context);
    const std::vector<Symbol*>& TemplateArguments() const { return templateArguments; }
    void SetTemplateArguments(const std::vector<Symbol*>& templateArguments_);
    void AddTemplateParameters(const std::vector<TemplateParameterSymbol*>& templateParameters);
    void SetClassTemplate(ClassTypeSymbol* classTemplate_) { classTemplate = classTemplate_; }
    ClassTypeSymbol* ClassTemplate() const { return classTemplate; }
    ClassGroupSymbol* Group() const { return group; }
    void SetGroup(ClassGroupSymbol* group_) { group = group_; }
private:
    Node* idNode;
    std::vector<Symbol*> baseClasses;
    std::vector<Symbol*> templateArguments;
    ClassTypeSymbol* classTemplate;
    TemplateDeclarationSymbol* templateDeclarationSymbol;
    Scope* groupScope;
    ClassGroupSymbol* group;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED

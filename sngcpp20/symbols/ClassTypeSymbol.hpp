// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

class SYMBOLS_API ClassTypeSymbol : public TypeSymbol
{
public:
    ClassTypeSymbol(const std::u32string& name_);
    bool IsClassTypeSymbol() const override { return true; }
    std::string SymbolKindStr() const override { return "class type symbol"; }
    void AddToGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context);
    bool IsValidDeclarationScope(ScopeKind scopeKind) const override;
    bool CanInstall() const override { return false; }
    void SetIdNode(Node* idNode_) { idNode = idNode_; }
    Node* IdNode() const { return idNode; }
    int Level() const;
    int TemplateArity() const { return templateArity; }
    const std::vector<ClassTypeSymbol*>& BaseClasses() const { return baseClasses; }
    void AddBaseClass(ClassTypeSymbol* baseClass, const SourcePos& sourcePos, Context* context);
private:
    Node* idNode;
    int templateArity;
    std::vector<ClassTypeSymbol*> baseClasses;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED

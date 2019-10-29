// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/TypeResolver.hpp>
#include <sngcpp/symbols/DerivedTypeSymbol.hpp>
#include <sngcpp/symbols/PseudoTypeSymbol.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/TypeExpr.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Template.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp { namespace binder {

using namespace soulng::unicode;

class TypeResolver : public Visitor
{
public:
    TypeResolver(SymbolTable& symbolTable_, ContainerScope* containerScope_, BoundSourceFile& boundSourceFile_, TypeResolverFlags flags_);
    void Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode) override;
    void Visit(ElaborateClassNameNode& elaborateClassNameNode) override;
    void Visit(SimpleTypeNode& simpleTypeNode) override;
    void Visit(ConstNode& constNode) override;
    void Visit(VolatileNode& volatileNode) override;
    void Visit(PointerNode& pointerNode) override;
    void Visit(RValueRefNode& rValueRefNode) override;
    void Visit(LValueRefNode& lValueRefNode) override;
    void Visit(TypeExprNode& typeExprNode) override;
    void Visit(IdentifierNode& identifierNode) override;
    void Visit(NestedIdNode& nestedIdNode) override;
    void Visit(TemplateIdNode& templateIdNode) override;
    void Visit(TemplateArgumentNode& templateArgumentNode) override;
    void Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode) override;
    void Visit(IntegerLiteralNode& integerLiteralNode) override;
    void Visit(StringLiteralNode& stringLiteralNode) override;
    TypeSymbol* GetType(bool noDerived);
    TypeSymbol* GetType() { return GetType(false); }
    const std::vector<IdentifierNode*>& IdNodeSequence() { return idNodeSequence; }
private:
    SymbolTable& symbolTable;
    ContainerScope* containerScope;
    ContainerScope* currentContainerScope;
    BoundSourceFile& boundSourceFile;
    TypeResolverFlags flags;
    TypeSymbol* type;
    std::vector<Derivation> derivations;
    ClassGroupSymbol* classGroup;
    std::vector<TypeSymbol*> templateArgumentTypes;
    std::vector<Node*> templateArgumentNodes;
    std::vector<IdentifierNode*> idNodeSequence;
    Span span;
    ClassKey classKey;
    bool parentResolved;
    TypeExprNode* typeExpressionNode;
    void AddBaseDerivation();
    void ResolveSymbol(Node& node, Symbol* symbol);
    void MakeExternalType();
};

TypeResolver::TypeResolver(SymbolTable& symbolTable_, ContainerScope* containerScope_, BoundSourceFile& boundSourceFile_, TypeResolverFlags flags_) :
    symbolTable(symbolTable_), containerScope(containerScope_), currentContainerScope(containerScope), boundSourceFile(boundSourceFile_), flags(flags_),
    type(nullptr), classGroup(nullptr), classKey(ClassKey::none), parentResolved(true), typeExpressionNode(nullptr)
{
}

TypeSymbol* TypeResolver::GetType(bool noDerived)
{
    if (!type)
    {
        if ((flags & TypeResolverFlags::resolveClassGroup) == TypeResolverFlags::none && classGroup)
        {
            type = classGroup->GetClass(0);
            if (classKey != ClassKey::none)
            {
                type = symbolTable.MakeElaborateClassTypeSymbol(classKey, type);
            }
        }
        else if (classGroup)
        {
            type = symbolTable.MakeClassGroupTypeSymbol(classGroup);
        }
    }
    if (!type)
    {
        if (!idNodeSequence.empty())
        {
            if ((flags & TypeResolverFlags::noExternalTypes) == TypeResolverFlags::none)
            {
                MakeExternalType();
            }
        }
        else if ((flags & TypeResolverFlags::nothrow) == TypeResolverFlags::none)
        {
            throw std::runtime_error("type not resolved");
        }
    }
    if (!noDerived && type)
    {
        if (!(derivations.empty() || derivations.size() == 1 && derivations.front() == Derivation::base))
        {
            TypeSymbol* baseType = type;
            type = symbolTable.MakeDerivedTypeSymbol(derivations, baseType);
        }
    }
    return type;
}

void TypeResolver::MakeExternalType()
{
    std::u32string externalTypeName;
    int n = idNodeSequence.size();
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
        {
            externalTypeName.append(U"::");
        }
        IdentifierNode* idNode = idNodeSequence[i];
        if (idNode)
        {
            externalTypeName.append(idNode->Identifier());
        }
    }
    type = symbolTable.MakeExternalTypeSymbol(span, externalTypeName, classKey);
}

void TypeResolver::Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode)
{
    forwardClassDeclarationNode.ClassName()->Accept(*this);
    classKey = forwardClassDeclarationNode.GetClassKey();
}

void TypeResolver::Visit(ElaborateClassNameNode& elaborateClassNameNode)
{
    elaborateClassNameNode.ClassName()->Accept(*this);
    classKey = elaborateClassNameNode.GetClassKey();
}

void TypeResolver::Visit(SimpleTypeNode& simpleTypeNode)
{
    type = symbolTable.MakeSimpleTypeSymbol(simpleTypeNode);
    AddBaseDerivation();
}

void TypeResolver::Visit(ConstNode& constNode)
{
    derivations.push_back(Derivation::const_);
    constNode.Child()->Accept(*this);
}

void TypeResolver::Visit(VolatileNode& volatileNode)
{
    derivations.push_back(Derivation::volatile_);
    volatileNode.Child()->Accept(*this);
}

void TypeResolver::Visit(PointerNode& pointerNode)
{
    pointerNode.Child()->Accept(*this);
    derivations.push_back(Derivation::ptr);
}

void TypeResolver::Visit(RValueRefNode& rValueRefNode)
{
    rValueRefNode.Child()->Accept(*this);
    derivations.push_back(Derivation::rvalueRef);
}

void TypeResolver::Visit(LValueRefNode& lValueRefNode)
{
    lValueRefNode.Child()->Accept(*this);
    derivations.push_back(Derivation::lvalueRef);
}

void TypeResolver::Visit(TypeExprNode& typeExprNode)
{
    typeExpressionNode = &typeExprNode;
    typeExprNode.Child()->Accept(*this);
}

void TypeResolver::Visit(IdentifierNode& identifierNode)
{
    span = identifierNode.GetSpan();
    AddBaseDerivation();
    Symbol* symbol = nullptr;
    if (parentResolved)
    {
        symbol = currentContainerScope->Lookup(identifierNode.Identifier(), ScopeLookup::this_and_bases_and_parent);
        if (!symbol)
        {
            for (const std::unique_ptr<FileScope>& fileScope : boundSourceFile.FileScopes())
            {
                symbol = fileScope->Lookup(identifierNode.Identifier());
                if (symbol)
                {
                    break;
                }
            }
        }
        if (!symbol)
        {
            if (classGroup)
            {
                ClassTypeSymbol* classTypeSymbol = classGroup->GetClass(0);
                symbol = classTypeSymbol->GetContainerScope()->Lookup(identifierNode.Identifier(), ScopeLookup::this_and_bases_and_parent);
            }
        }
    }
    if (symbol)
    {
        ResolveSymbol(identifierNode, symbol);
        idNodeSequence.push_back(&identifierNode);
    }
    else
    {
        idNodeSequence.push_back(&identifierNode);
        parentResolved = false;
    }
}

void TypeResolver::Visit(NestedIdNode& nestedIdNode)
{
    if (nestedIdNode.Left())
    {
        nestedIdNode.Left()->Accept(*this);
    }
    else
    {
        idNodeSequence.push_back(nullptr);
    }
    nestedIdNode.Right()->Accept(*this);
}

void TypeResolver::Visit(TemplateIdNode& templateIdNode)
{
    span = templateIdNode.GetSpan();
    AddBaseDerivation();
    Symbol* symbol = currentContainerScope->Lookup(templateIdNode.Id()->Identifier(), ScopeLookup::this_and_bases_and_parent);
    if (!symbol)
    {
        for (const std::unique_ptr<FileScope>& fileScope : boundSourceFile.FileScopes())
        {
            symbol = fileScope->Lookup(templateIdNode.Id()->Identifier());
            if (symbol)
            {
                break;
            }
        }
    }
    TypeSymbol* primaryClassTemplate = nullptr;
    if (symbol)
    {
        ResolveSymbol(templateIdNode, symbol);
        idNodeSequence.push_back(templateIdNode.Id());
        if (classGroup)
        {
            primaryClassTemplate = classGroup->GetClass(templateIdNode.Arity());
        }
        else if (type)
        {
            primaryClassTemplate = type;
        }
        else
        {
            idNodeSequence.push_back(templateIdNode.Id());
            primaryClassTemplate = GetType(true);
        }
    }
    else
    {
        idNodeSequence.push_back(templateIdNode.Id());
        primaryClassTemplate = GetType(true);
    }
    symbolTable.MapNode(&templateIdNode, primaryClassTemplate);
    symbolTable.MapIdNodeSequence(&templateIdNode, idNodeSequence);
    if (templateIdNode.TemplateArguments())
    {
        templateIdNode.TemplateArguments()->Accept(*this);
    }
    if (primaryClassTemplate)
    {
        type = symbolTable.MakeClassTemplateSpecializationSymbol(span, primaryClassTemplate, &templateIdNode, templateArgumentTypes, templateArgumentNodes, typeExpressionNode);
    }
}

void TypeResolver::Visit(TemplateArgumentNode& templateArgumentNode)
{
    templateArgumentTypes.push_back(ResolveType(symbolTable, containerScope, boundSourceFile, TypeResolverFlags::noPseudoTypes, templateArgumentNode.Arg()));
    templateArgumentNodes.push_back(templateArgumentNode.Arg());
}

void TypeResolver::Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode)
{
    templateArgumentSequenceNode.Left()->Accept(*this);
    templateArgumentSequenceNode.Right()->Accept(*this);
}

void TypeResolver::Visit(IntegerLiteralNode& integerLiteralNode)
{
    if ((flags & TypeResolverFlags::noExternalTypes) == TypeResolverFlags::none)
    {
        type = symbolTable.MakeIntegerLiteralTypeSymbol(integerLiteralNode.GetSpan(), ToUtf32(std::to_string(integerLiteralNode.Value())));
    }
}

void TypeResolver::Visit(StringLiteralNode& stringLiteralNode)
{
    if (stringLiteralNode.EncodigPrefix().empty() || stringLiteralNode.EncodigPrefix() == U"u8")
    {
        std::vector<sngcpp::symbols::Derivation> derivations;
        derivations.push_back(sngcpp::symbols::Derivation::const_);
        derivations.push_back(sngcpp::symbols::Derivation::lvalueRef);
        type = symbolTable.MakeDerivedTypeSymbol(derivations, symbolTable.MakeExternalTypeSymbol(stringLiteralNode.GetSpan(), U"std::string", sngcpp::ast::ClassKey::none));
    }
    else if (stringLiteralNode.EncodigPrefix() == U"u")
    {
        std::vector<sngcpp::symbols::Derivation> derivations;
        derivations.push_back(sngcpp::symbols::Derivation::const_);
        derivations.push_back(sngcpp::symbols::Derivation::lvalueRef);
        type = symbolTable.MakeDerivedTypeSymbol(derivations, symbolTable.MakeExternalTypeSymbol(stringLiteralNode.GetSpan(), U"std::u16string", sngcpp::ast::ClassKey::none));
    }
    else if (stringLiteralNode.EncodigPrefix() == U"U")
    {
        std::vector<sngcpp::symbols::Derivation> derivations;
        derivations.push_back(sngcpp::symbols::Derivation::const_);
        derivations.push_back(sngcpp::symbols::Derivation::lvalueRef);
        type = symbolTable.MakeDerivedTypeSymbol(derivations, symbolTable.MakeExternalTypeSymbol(stringLiteralNode.GetSpan(), U"std::u32string", sngcpp::ast::ClassKey::none));
    }
    else if (stringLiteralNode.EncodigPrefix() == U"L")
    {
        std::vector<sngcpp::symbols::Derivation> derivations;
        derivations.push_back(sngcpp::symbols::Derivation::const_);
        derivations.push_back(sngcpp::symbols::Derivation::lvalueRef);
        type = symbolTable.MakeDerivedTypeSymbol(derivations, symbolTable.MakeExternalTypeSymbol(stringLiteralNode.GetSpan(), U"std::wstring", sngcpp::ast::ClassKey::none));
    }
}

void TypeResolver::AddBaseDerivation()
{
    if (derivations.empty())
    {
        derivations.push_back(Derivation::base);
    }
    else
    {
        if (derivations.back() != Derivation::base)
        {
            derivations.push_back(Derivation::base);
        }
    }
}

void TypeResolver::ResolveSymbol(Node& node, Symbol* symbol)
{
    if (symbol->IsNamespaceSymbol())
    {
        currentContainerScope = symbol->GetContainerScope();
        parentResolved = true;
    }
    else if (symbol->IsClassGroupSymbol())
    {
        classGroup = static_cast<ClassGroupSymbol*>(symbol);
        parentResolved = true;
    }
    else if (symbol->IsTypeSymbol())
    {
        symbolTable.MapNode(&node, symbol);
        type = static_cast<TypeSymbol*>(symbol);
        currentContainerScope = type->GetContainerScope();
        parentResolved = true;
    }
    else if (symbol->IsFunctionGroupSymbol() && (flags & TypeResolverFlags::noPseudoTypes) == TypeResolverFlags::none)
    {
        symbolTable.MapNode(&node, symbol);
        type = symbolTable.MakePseudoTypeSymbol(node.GetSpan(), symbol->Name());
        PseudoTypeSymbol* pseudoType = static_cast<PseudoTypeSymbol*>(type);
        FunctionGroupSymbol* functionGroup = static_cast<FunctionGroupSymbol*>(symbol);
        pseudoType->SetFunctionGroup(functionGroup);
        parentResolved = false;
    }
    else
    {
        parentResolved = false;
    }
}

TypeSymbol* ResolveType(SymbolTable& symbolTable, ContainerScope* containerScope, BoundSourceFile& boundSourceFile, Node* node)
{
    return ResolveType(symbolTable, containerScope, boundSourceFile, TypeResolverFlags::none, node);
}

TypeSymbol* ResolveType(SymbolTable& symbolTable, ContainerScope* containerScope, BoundSourceFile& boundSourceFile, TypeResolverFlags flags, Node* node)
{
    TypeResolver typeResolver(symbolTable, containerScope, boundSourceFile, flags);
    node->Accept(typeResolver);
    TypeSymbol* type = typeResolver.GetType();
    if (type)
    {
        symbolTable.MapNode(node, type);
        symbolTable.MapIdNodeSequence(node, typeResolver.IdNodeSequence());
        return type;
    }
    else if ((flags & TypeResolverFlags::nothrow) == TypeResolverFlags::none)
    {
        throw std::runtime_error("type not resolved");
    }
    else
    {
        return nullptr;
    }
}

} } // namespace sngcpp::cppbinder

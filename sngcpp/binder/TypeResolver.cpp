// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/TypeResolver.hpp>
#include <sngcpp/symbols/DerivedTypeSymbol.hpp>
#include <sngcpp/symbols/TypedefSymbol.hpp>
#include <sngcpp/symbols/ClassTemplateSpecializationSymbol.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/TypeExpr.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Template.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp { namespace binder {

using namespace soulng::unicode;

class TypeResolver : public sngcpp::ast::Visitor
{
public:
    TypeResolver(SymbolTable& symbolTable_, ContainerScope* containerScope_, const std::vector<ContainerScope*>& prevContainerScopes_, BoundSourceFile& boundSourceFile_,
        ClassTypeSymbol* currentClass_, TypeResolverFlags flags_);
    void Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode) override;
    void Visit(ElaborateClassNameNode& elaborateClassNameNode) override;
    void Visit(SimpleTypeNode& simpleTypeNode) override;
    void Visit(ConstNode& constNode) override;
    void Visit(VolatileNode& volatileNode) override;
    void Visit(PointerNode& pointerNode) override;
    void Visit(RValueRefNode& rValueRefNode) override;
    void Visit(LValueRefNode& lValueRefNode) override;
    void Visit(IdentifierNode& identifierNode) override;
    void Visit(NestedIdNode& nestedIdNode) override;
    void Visit(TemplateIdNode& templateIdNode) override;
    void Visit(TemplateArgumentNode& templateArgumentNode) override;
    void Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode) override;
    void Visit(IntegerLiteralNode& integerLiteralNode) override;
    void Visit(StringLiteralNode& stringLiteralNode) override;
    sngcpp::symbols::TypeSymbol* GetType(bool noDerived);
    sngcpp::symbols::TypeSymbol* GetType() { return GetType(false); }
    const std::vector<IdentifierNode*>& IdNodeSequence() { return idNodeSequence; }
private:
    SymbolTable& symbolTable;
    ContainerScope* containerScope;
    std::vector<ContainerScope*> prevContainerScopes;
    ContainerScope* currentContainerScope;
    BoundSourceFile& boundSourceFile;
    TypeResolverFlags flags;
    sngcpp::symbols::TypeSymbol* type;
    std::vector<Derivation> derivations;
    ClassGroupSymbol* classGroup;
    std::vector<sngcpp::symbols::TypeSymbol*> templateArgumentTypes;
    std::vector<Node*> templateArgumentNodes;
    std::vector<IdentifierNode*> idNodeSequence;
    Span span;
    ClassKey classKey;
    ClassTypeSymbol* currentClass;
    bool parentResolved;
    void AddBaseDerivation();
    void ResolveSymbol(Node& node, Symbol* symbol);
    void MakeExternalType();
};

TypeResolver::TypeResolver(SymbolTable& symbolTable_, ContainerScope* containerScope_, const std::vector<ContainerScope*>& prevContainerScopes_, BoundSourceFile& boundSourceFile_,
    ClassTypeSymbol* currentClass_, TypeResolverFlags flags_) :
    symbolTable(symbolTable_), containerScope(containerScope_), prevContainerScopes(prevContainerScopes_), currentContainerScope(containerScope), boundSourceFile(boundSourceFile_),
    currentClass(currentClass_), flags(flags_), type(nullptr), classGroup(nullptr), classKey(ClassKey::none), parentResolved(true)
{
}

sngcpp::symbols::TypeSymbol* TypeResolver::GetType(bool noDerived)
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
            sngcpp::symbols::TypeSymbol* baseType = type;
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
                for (const auto& classTypeSymbol : classGroup->Classes())
                {
                    if (classTypeSymbol)
                    {
                        symbol = classTypeSymbol->GetContainerScope()->Lookup(identifierNode.Identifier(), ScopeLookup::this_and_bases_and_parent);
                        if (symbol) break;
                    }
                }
            }
        }
        if (!symbol)
        {
            for (ContainerScope* prevContainerScope : prevContainerScopes)
            {
                symbol = prevContainerScope->Lookup(identifierNode.Identifier(), ScopeLookup::this_and_bases_and_parent);
                if (symbol)
                {
                    break;
                }
            }
        }
    }
    if (symbol)
    {
        ResolveSymbol(identifierNode, symbol);
        idNodeSequence.push_back(&identifierNode);
        if (!symbolTable.GetSymbolNothrow(&identifierNode))
        {
            symbolTable.MapNode(&identifierNode, symbol);
        }
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
    sngcpp::symbols::TypeSymbol* primaryClassTemplate = nullptr;
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
    symbolTable.MapIdNodeSequence(&templateIdNode, idNodeSequence);
    if (templateIdNode.TemplateArguments())
    {
        templateIdNode.TemplateArguments()->Accept(*this);
    }
    if (primaryClassTemplate)
    {
        type = symbolTable.MakeClassTemplateSpecializationSymbol(span, primaryClassTemplate, templateArgumentTypes);
        for (const auto& member : primaryClassTemplate->Members())
        {
            if (member->IsTypedefSymbol())
            {
                TypedefSymbol* typedef_ = static_cast<TypedefSymbol*>(member.get());
                if (type->GetContainerScope()->Lookup(typedef_->Name()) == nullptr)
                {
                    TypedefSymbol* clonedTypedef = new TypedefSymbol(soulng::lexer::Span(), typedef_->Name());
                    clonedTypedef->SetProjectName(typedef_->ProjectName());
                    clonedTypedef->SetType(typedef_);
                    clonedTypedef->SetPrimaryId(member->Id());
                    type->AddMember(std::unique_ptr<Symbol>(clonedTypedef));
                }
            }
        }
        symbolTable.MapNode(&templateIdNode, type);
        symbolTable.MapTemplateIdToTemplateArgumentNodes(&templateIdNode, templateArgumentNodes);
        currentContainerScope = type->GetContainerScope();
    }
}

void TypeResolver::Visit(TemplateArgumentNode& templateArgumentNode)
{
    templateArgumentTypes.push_back(ResolveType(symbolTable, containerScope, prevContainerScopes, boundSourceFile, TypeResolverFlags::none, currentClass, templateArgumentNode.Arg()));
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
        if ((flags & TypeResolverFlags::notSelf) == TypeResolverFlags::none && currentClass && currentClass->Name() == classGroup->Name())
        {
            type = currentClass;
            currentContainerScope = type->GetContainerScope();
        }
        parentResolved = true;
    }
    else if (symbol->IsTypeSymbol())
    {
        symbolTable.MapNode(&node, symbol);
        type = static_cast<sngcpp::symbols::TypeSymbol*>(symbol);
        sngcpp::symbols::TypeSymbol* resolvedType = type;
        if (resolvedType->IsTypedefSymbol())
        {
            sngcpp::symbols::TypedefSymbol* typedefSymbol = static_cast<sngcpp::symbols::TypedefSymbol*>(resolvedType);
            resolvedType = typedefSymbol->GetType();
        }
        if (resolvedType)
        {
            currentContainerScope = resolvedType->GetContainerScope();
            parentResolved = true;
        }
        else
        {
            parentResolved = false;
        }
    }
    else
    {
        parentResolved = false;
    }
}

sngcpp::symbols::TypeSymbol* ResolveType(SymbolTable& symbolTable, ContainerScope* containerScope, const std::vector<ContainerScope*>& prevContainerScopes, BoundSourceFile& boundSourceFile,
    ClassTypeSymbol* currentClassType, Node* node)
{
    return ResolveType(symbolTable, containerScope, prevContainerScopes, boundSourceFile, TypeResolverFlags::none, currentClassType, node);
}

sngcpp::symbols::TypeSymbol* ResolveType(SymbolTable& symbolTable, ContainerScope* containerScope, const std::vector<ContainerScope*>& prevContainerScopes, BoundSourceFile& boundSourceFile,
    TypeResolverFlags flags, ClassTypeSymbol* currentClassType, Node* node)
{
    TypeResolver typeResolver(symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentClassType, flags);
    node->Accept(typeResolver);
    sngcpp::symbols::TypeSymbol* type = typeResolver.GetType();
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

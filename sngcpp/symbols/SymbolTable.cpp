// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngcpp/symbols/ParameterSymbol.hpp>
#include <sngcpp/symbols/VariableSymbol.hpp>
#include <sngcpp/symbols/TypedefSymbol.hpp>
#include <sngcpp/symbols/ExternalTypeSymbol.hpp>
#include <sngcpp/symbols/ClassTemplateSpecializationSymbol.hpp>
#include <sngcpp/symbols/IntegerLiteralTypeSymbol.hpp>
#include <sngcpp/symbols/LambdaExpressionSymbol.hpp>
#include <sngcpp/symbols/GrammarSymbol.hpp>
#include <sngcpp/ast/Class.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Sha1.hpp>
#include <algorithm>

namespace sngcpp { namespace symbols {

using namespace soulng::unicode;
using namespace soulng::util;

SymbolTable::SymbolTable() : globalNs(Span(), U""), container(&globalNs), blockNumber(0), gendocMode(false)
{
    globalNs.SetAccess(Specifier::public_);
}

std::unique_ptr<sngxml::dom::Document> SymbolTable::ToDomDocument()
{
    std::unique_ptr<sngxml::dom::Document> symbolTableDoc(new sngxml::dom::Document());
    symbolTableDoc->AppendChild(std::move(ToDomElement()));
    return symbolTableDoc;
}

std::unique_ptr<sngxml::dom::Element> SymbolTable::ToDomElement()
{
    std::unique_ptr<sngxml::dom::Element> symbolTableElement(new sngxml::dom::Element(U"symbolTable"));
    std::unique_ptr<sngxml::dom::Element> globalNsElement = globalNs.ToDomElement();
    symbolTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(globalNsElement.release()));
    std::unique_ptr<sngxml::dom::Element> typesElement = CreateTypesElement();
    if (typesElement)
    {
        symbolTableElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(typesElement.release()));
    }
    return symbolTableElement;
}

std::unique_ptr<sngxml::dom::Element> SymbolTable::CreateTypesElement()
{
    std::unique_ptr<sngxml::dom::Element> typesElement;
    if (!types.empty())
    {
        typesElement.reset(new sngxml::dom::Element(U"types"));
        std::vector<TypeSymbol*> typeSymbols;
        for (const std::unique_ptr<TypeSymbol>& type : types)
        {
            typeSymbols.push_back(type.get());
        }
        std::sort(typeSymbols.begin(), typeSymbols.end(), ByName());
        for (TypeSymbol* typeSymbol : typeSymbols)
        {
            std::unique_ptr<sngxml::dom::Element> typeElement = typeSymbol->ToDomElement();
            typesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(typeElement.release()));
        }
    }
    return typesElement;
}

void SymbolTable::BeginContainer(ContainerSymbol* container_)
{
    containerStack.push(container);
    container = container_;
}

void SymbolTable::EndContainer()
{
    container = containerStack.top();
    containerStack.pop();
}

int SymbolTable::BeginNameSequence(const std::vector<std::pair<std::u32string, int>>& nameSequence)
{
    int result = 0;
    int n = nameSequence.size();
    for (int i = 0; i < n - 1; ++i)
    {
        if (nameSequence[i].first.empty())
        {
            BeginContainer(&globalNs);
            ++result;
        }
        else
        {
            Symbol* symbol = container->GetContainerScope()->Lookup(nameSequence[i].first);
            if (symbol)
            {
                if (symbol->IsClassGroupSymbol())
                {
                    ClassGroupSymbol* classGroup = static_cast<ClassGroupSymbol*>(symbol);
                    ClassTypeSymbol* cls = classGroup->GetClass(nameSequence[i].second);
                    if (cls)
                    {
                        BeginContainer(cls);
                        ++result;
                    }
                }
                else if (symbol->IsContainerSymbol())
                {
                    ContainerSymbol* containerSymbol = static_cast<ContainerSymbol*>(symbol);
                    BeginContainer(containerSymbol);
                    ++result;
                }
            }
        }
    }
    return result;
}

void SymbolTable::EndNameSequence(int n)
{
    for (int i = 0; i < n; ++i)
    {
        EndContainer();
    }
}

void SymbolTable::BeginNamespace(const std::u32string& namespaceName, const std::u32string& projectName)
{
    if (namespaceName.empty())
    {
        BeginContainer(&globalNs);
    }
    else
    {
        Symbol* symbol = container->GetContainerScope()->Lookup(namespaceName);
        if (symbol)
        {
            if (symbol->IsNamespaceSymbol())
            {
                NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(symbol);
                if (!projectName.empty())
                {
                    ns->AddProject(projectName);
                }
                BeginContainer(ns);
            }
            else
            {
                throw std::runtime_error(ToUtf8(namespaceName) + " does not denote a namespace");
            }
        }
        else
        {
            std::unique_ptr<NamespaceSymbol> newNs(new NamespaceSymbol(Span(), namespaceName));
            newNs->SetAccess(Specifier::public_);
            NamespaceSymbol* ns = newNs.get();
            if (!projectName.empty())
            {
                ns->AddProject(projectName);
            }
            container->AddMember(std::move(newNs));
            BeginContainer(ns);
        }
    }
}

void SymbolTable::EndNamespace()
{
    EndContainer();
}

void SymbolTable::BeginClass(ClassNode* classNode, const std::u32string& className, std::vector<std::unique_ptr<TypeSymbol>>& templateParameters, const std::u32string& projectName)
{
    ClassTypeSymbol* classType = new ClassTypeSymbol(classNode->GetSpan(), className, classNode->GetClassKey());
    classType->SetProjectName(projectName);
    MapNode(classNode, classType);
    for (std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
    {
        classType->AddTemplateParameter(std::move(templateParameter));
    }
    BeginContainer(classType);
}

void SymbolTable::EndClass(const std::u32string& projectName)
{
    ClassTypeSymbol* classType = static_cast<ClassTypeSymbol*>(container);
    EndContainer();
    container->AddMember(std::unique_ptr<Symbol>(classType));
    if (container->IsNamespaceSymbol())
    {
        if (container->Name() == U"")
        {
            NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(container);
            ns->AddProject(projectName);
        }
    }
}

void SymbolTable::BeginLambdaExpression(LambdaExpressionNode* lambdaExpressionNode)
{
    LambdaExpressionSymbol* lambdaExpression = new LambdaExpressionSymbol(lambdaExpressionNode->GetSpan());
    MapNode(lambdaExpressionNode, lambdaExpression);
    BeginContainer(lambdaExpression);
}

void SymbolTable::EndLambdaExpression()
{
    LambdaExpressionSymbol* lambdaExpression = static_cast<LambdaExpressionSymbol*>(container);
    EndContainer();
    container->AddMember(std::unique_ptr<Symbol>(lambdaExpression));
}

void SymbolTable::BeginGrammar(const Span& span, const std::u32string& grammarName, const std::u32string& projectName)
{
    GrammarSymbol* grammar = new GrammarSymbol(span, grammarName);
    grammar->SetProjectName(projectName);
    BeginContainer(grammar);
}

void SymbolTable::EndGrammar(const std::u32string& projectName)
{
    GrammarSymbol* grammar = static_cast<GrammarSymbol*>(container);
    EndContainer();
    container->AddMember(std::unique_ptr<Symbol>(grammar));
    if (container->IsNamespaceSymbol() && container->Name() == U"")
    {
        NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(container);
        ns->AddProject(projectName);
    }
}

RuleSymbol* SymbolTable::AddRule(const Span& span, const std::u32string& ruleName)
{
    RuleSymbol* rule = new RuleSymbol(span, ruleName);
    container->AddMember(std::unique_ptr<Symbol>(rule));
    return rule;
}

void SymbolTable::BeginEnumType(EnumTypeNode* enumTypeNode, const std::u32string& enumTypeName, const std::u32string& projectName)
{
    EnumTypeSymbol* enumType = new EnumTypeSymbol(enumTypeNode->GetSpan(), enumTypeName, enumTypeNode->GetEnumKey());
    enumType->SetProjectName(projectName);
    MapNode(enumTypeNode, enumType);
    BeginContainer(enumType);
}

void SymbolTable::EndEnumType(const std::u32string& projectName)
{
    EnumTypeSymbol* enumType = static_cast<EnumTypeSymbol*>(container);
    EndContainer();
    container->AddMember(std::unique_ptr<Symbol>(enumType));
    if (container->IsNamespaceSymbol() && container->Name() == U"")
    {
        NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(container);
        ns->AddProject(projectName);
    }
}

void SymbolTable::AddEnumerator(EnumeratorNode* enumeratorNode, const std::u32string& enumeratorName, const std::u32string& enumeratorValue)
{
    EnumeratorSymbol* enumeratorSymbol = new EnumeratorSymbol(enumeratorNode->GetSpan(), enumeratorName, enumeratorValue);
    MapNode(enumeratorNode, enumeratorSymbol);
    container->AddMember(std::unique_ptr<Symbol>(enumeratorSymbol));
}

void SymbolTable::BeginFunction(FunctionDeclaratorNode* functionDeclaratorNode, const std::u32string& groupName, const std::u32string& functionName,
    std::vector<std::unique_ptr<TypeSymbol>>& templateParameters, Specifier specifiers, const std::u32string& projectName)
{
    if (container->IsClassTypeSymbol() && groupName == U"destructor")
    {
        DestructorSymbol* destructorSymbol = new DestructorSymbol(functionDeclaratorNode->GetSpan(), groupName, specifiers);
        destructorSymbol->SetProjectName(projectName);
        MapNode(functionDeclaratorNode, destructorSymbol);
        BeginContainer(destructorSymbol);
    }
    else if (container->IsClassTypeSymbol() && groupName == container->Name())
    {
        ConstructorSymbol* constructorSymbol = new ConstructorSymbol(functionDeclaratorNode->GetSpan(), groupName, specifiers);
        constructorSymbol->SetProjectName(projectName);
        MapNode(functionDeclaratorNode, constructorSymbol);
        BeginContainer(constructorSymbol);
        for (std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
        {
            constructorSymbol->AddTemplateParameter(std::move(templateParameter));
        }
    }
    else
    {
        FunctionSymbol* functionSymbol = new FunctionSymbol(functionDeclaratorNode->GetSpan(), groupName, functionName, specifiers);
        functionSymbol->SetProjectName(projectName);
        MapNode(functionDeclaratorNode, functionSymbol);
        BeginContainer(functionSymbol);
        for (std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
        {
            functionSymbol->AddTemplateParameter(std::move(templateParameter));
        }
    }
}

void SymbolTable::EndFunction(const std::u32string& projectName)
{
    FunctionSymbol* functionSymbol = static_cast<FunctionSymbol*>(container);
    EndContainer();
    container->AddMember(std::unique_ptr<Symbol>(functionSymbol));
    if (container->IsNamespaceSymbol() && container->Name() == U"")
    {
        NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(container);
        ns->AddProject(projectName);
    }
}

void SymbolTable::BeginFunctionDeclaration(FunctionDeclaratorNode* functionDeclaratorNode, const std::u32string& groupName, const std::u32string& functionName,
    std::vector<std::unique_ptr<TypeSymbol>>& templateParameters, Specifier specifiers, const std::u32string& projectName)
{
    if (container->IsClassTypeSymbol() && groupName == container->Name())
    {
        ConstructorDeclarationSymbol* constructorDeclarationSymbol = new ConstructorDeclarationSymbol(functionDeclaratorNode->GetSpan(), groupName, specifiers);
        constructorDeclarationSymbol->SetProjectName(projectName);
        MapNode(functionDeclaratorNode, constructorDeclarationSymbol);
        BeginContainer(constructorDeclarationSymbol);
        for (std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
        {
            constructorDeclarationSymbol->AddTemplateParameter(std::move(templateParameter));
        }
    }
    else
    {
        FunctionDeclarationSymbol* functionDeclarationSymbol = new FunctionDeclarationSymbol(functionDeclaratorNode->GetSpan(), groupName, functionName, specifiers);
        functionDeclarationSymbol->SetProjectName(projectName);
        MapNode(functionDeclaratorNode, functionDeclarationSymbol);
        BeginContainer(functionDeclarationSymbol);
        for (std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
        {
            functionDeclarationSymbol->AddTemplateParameter(std::move(templateParameter));
        }
    }
}

void SymbolTable::EndFunctionDeclaration()
{
    FunctionDeclarationSymbol* functionDeclarationSymbol = static_cast<FunctionDeclarationSymbol*>(container);
    EndContainer();
    container->AddMember(std::unique_ptr<Symbol>(functionDeclarationSymbol));
}

void SymbolTable::AddParameter(ParameterNode* parameterNode, const std::u32string& parameterName)
{
    ParameterSymbol* parameterSymbol = new ParameterSymbol(parameterNode->GetSpan(), parameterName);
    parameterSymbol->SetAccess(Specifier::public_);
    MapNode(parameterNode, parameterSymbol);
    container->AddMember(std::unique_ptr<Symbol>(parameterSymbol));
}

void SymbolTable::BeginDeclarationBlock(Node* blockNode)
{
    DeclarationBlockSymbol* declarationBlock = new DeclarationBlockSymbol(blockNode->GetSpan(), U"block" + ToUtf32(std::to_string(blockNumber++)));
    declarationBlock->SetAccess(Specifier::public_);
    MapNode(blockNode, declarationBlock);
    BeginContainer(declarationBlock);
}

void SymbolTable::EndDeclarationBlock()
{
    DeclarationBlockSymbol* declarationBlock = static_cast<DeclarationBlockSymbol*>(container);
    EndContainer();
    container->AddMember(std::unique_ptr<Symbol>(declarationBlock));
}

void SymbolTable::AddTypedef(TypedefNode* node, const std::u32string& typedefName, const std::u32string& projectName)
{
    TypedefSymbol* typedefSymbol = new TypedefSymbol(node->GetSpan(), typedefName);
    typedefSymbol->SetProjectName(projectName);
    MapNode(node, typedefSymbol);
    container->AddMember(std::unique_ptr<Symbol>(typedefSymbol));
    if (container->IsNamespaceSymbol() && container->Name() == U"")
    {
        NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(container);
        ns->AddProject(projectName);
    }
}

void SymbolTable::AddVariable(Node* node, const std::u32string& variableName, const std::u32string& projectName)
{
    Symbol* symbol = container->GetContainerScope()->Lookup(variableName);
    if (symbol)
    {
        MapNode(node, symbol);
    }
    else
    {
        VariableSymbol* variableSymbol = new VariableSymbol(node->GetSpan(), variableName);
        variableSymbol->SetProjectName(projectName);
        MapNode(node, variableSymbol);
        container->AddMember(std::unique_ptr<Symbol>(variableSymbol));
        if (container->IsNamespaceSymbol() && container->Name() == U"")
        {
            NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(container);
            ns->AddProject(projectName);
        }
    }
}

void SymbolTable::MapNode(Node* node, Symbol* symbol)
{
    nodeSymbolMap[node] = symbol;
}

void SymbolTable::MapIdNodeSequence(Node* node, const std::vector<IdentifierNode*>& idNodeSequence)
{
    idNodeSequenceMap[node] = idNodeSequence;
}

void SymbolTable::MapTemplateIdToTemplateArgumentNodes(TemplateIdNode* templateIdNode, const std::vector<Node*>& templateArgumentNodes)
{
    templateIdTemplateArgumentNodeMap[templateIdNode] = templateArgumentNodes;
}

Symbol* SymbolTable::GetSymbolNothrow(Node* node)
{
    auto it = nodeSymbolMap.find(node);
    if (it != nodeSymbolMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

Symbol* SymbolTable::GetSymbol(Node* node)
{
    Symbol* symbol = GetSymbolNothrow(node);
    if (symbol)
    {
        return symbol;
    }
    else
    {
        throw std::runtime_error("symbol for node not found");
    }
}

const std::vector<IdentifierNode*>& SymbolTable::GetIdNodeSequence(Node* node)
{
    auto it = idNodeSequenceMap.find(node);
    if (it != idNodeSequenceMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("id node sequence for node not found");
    }
}

const std::vector<Node*>& SymbolTable::GetTemplateArgumentNodes(TemplateIdNode* templateIdNode)
{
    auto it = templateIdTemplateArgumentNodeMap.find(templateIdNode);
    if (it != templateIdTemplateArgumentNodeMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("template argument nodes for template id node not found");
    }
}

ContainerScope* SymbolTable::GetContainerScope()
{
    return container->GetContainerScope();
}

TypeSymbol* SymbolTable::GetBoolType()
{
    SimpleTypeNode boolNode(soulng::lexer::Span(), std::vector<SimpleTypeSpecifier>(1, SimpleTypeSpecifier::bool_));
    return MakeSimpleTypeSymbol(boolNode);
}

TypeSymbol* SymbolTable::GetLongType()
{
    SimpleTypeNode longNode(soulng::lexer::Span(), std::vector<SimpleTypeSpecifier>(1, SimpleTypeSpecifier::long_));
    return MakeSimpleTypeSymbol(longNode);
}

TypeSymbol* SymbolTable::GetDoubleType()
{
    SimpleTypeNode doubleNode(soulng::lexer::Span(), std::vector<SimpleTypeSpecifier>(1, SimpleTypeSpecifier::double_));
    return MakeSimpleTypeSymbol(doubleNode);
}

TypeSymbol* SymbolTable::GetIntType()
{
    SimpleTypeNode intNode(soulng::lexer::Span(), std::vector<SimpleTypeSpecifier>(1, SimpleTypeSpecifier::int_));
    return MakeSimpleTypeSymbol(intNode);
}

TypeSymbol* SymbolTable::GetUIntType()
{
    std::vector<SimpleTypeSpecifier> specifiers;
    specifiers.push_back(SimpleTypeSpecifier::unsigned_);
    specifiers.push_back(SimpleTypeSpecifier::int_);
    SimpleTypeNode uintNode(soulng::lexer::Span(), specifiers);
    return MakeSimpleTypeSymbol(uintNode);
}

TypeSymbol* SymbolTable::GetCharType()
{
    SimpleTypeNode charNode(soulng::lexer::Span(), std::vector<SimpleTypeSpecifier>(1, SimpleTypeSpecifier::char_));
    return MakeSimpleTypeSymbol(charNode);
}

TypeSymbol* SymbolTable::GetChar16Type()
{
    SimpleTypeNode char16Node(soulng::lexer::Span(), std::vector<SimpleTypeSpecifier>(1, SimpleTypeSpecifier::char16));
    return MakeSimpleTypeSymbol(char16Node);
}

TypeSymbol* SymbolTable::GetChar32Type()
{
    SimpleTypeNode char32Node(soulng::lexer::Span(), std::vector<SimpleTypeSpecifier>(1, SimpleTypeSpecifier::char32));
    return MakeSimpleTypeSymbol(char32Node);
}

TypeSymbol* SymbolTable::GetVoidType()
{
    SimpleTypeNode voidNode(soulng::lexer::Span(), std::vector<SimpleTypeSpecifier>(1, SimpleTypeSpecifier::void_));
    return MakeSimpleTypeSymbol(voidNode);
}

TypeSymbol* SymbolTable::MakeSimpleTypeSymbol(SimpleTypeNode& simpleTypeNode)
{
    std::u32string id = simpleTypeNode.Id();
    auto it = idTypeMap.find(id);
    if (it != idTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        SimpleTypeSymbol* simpleTypeSymbol = new SimpleTypeSymbol(simpleTypeNode.GetSpan(), simpleTypeNode.Str(), id, simpleTypeNode.Flags());
        simpleTypeSymbol->SetAccess(Specifier::public_);
        idTypeMap[id] = simpleTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(simpleTypeSymbol));
        return simpleTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeElaborateClassTypeSymbol(ClassKey classKey, TypeSymbol* classType)
{
    std::u32string idMaterial = ToString(classKey) + classType->IdStr();
    std::u32string id = U"type_" + ToUtf32(GetSha1MessageDigest(ToUtf8(idMaterial)));
    auto it = idTypeMap.find(id);
    if (it != idTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        ElaborateClassTypeSymbol* elaborateClassTypeSymbol = new ElaborateClassTypeSymbol(classType->GetSpan(), classKey, classType, id);
        idTypeMap[id] = elaborateClassTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(elaborateClassTypeSymbol));
        return elaborateClassTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeDerivedTypeSymbol(std::vector<Derivation>& derivations, TypeSymbol* baseType)
{
    if (baseType->IsDerivedTypeSymbol())
    {
        DerivedTypeSymbol* derivedType = static_cast<DerivedTypeSymbol*>(baseType);
        derivations = UnifyDerivations(derivations, derivedType->Derivations());
        baseType = derivedType->BaseType();
    }
    std::u32string id = MakeDerivedTypeId(derivations, baseType);
    auto it = idTypeMap.find(id);
    if (it != idTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        DerivedTypeSymbol* derivedTypeSymbol = new DerivedTypeSymbol(baseType->GetSpan(), MakeDerivedTypeName(derivations, baseType), baseType, derivations, id);
        derivedTypeSymbol->SetAccess(Specifier::public_);
        idTypeMap[id] = derivedTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(derivedTypeSymbol));
        return derivedTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeExternalTypeSymbol(const Span& span, const std::u32string& name, ClassKey classKey)
{
    std::u32string id = U"type_";
    if (classKey != ClassKey::none)
    {
        id.append(ToString(classKey));
        id.append(1, '_');
    }
    id.append(ToUtf32(GetSha1MessageDigest(ToUtf8(name))));
    auto it = idTypeMap.find(id);
    if (it != idTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        ExternalTypeSymbol* externalTypeSymbol = new ExternalTypeSymbol(span, name, classKey, id);
        externalTypeSymbol->SetAccess(Specifier::public_);
        idTypeMap[id] = externalTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(externalTypeSymbol));
        return externalTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeClassGroupTypeSymbol(ClassGroupSymbol* classGroup)
{
    std::u32string id = classGroup->Id();
    auto it = idTypeMap.find(id);
    if (it != idTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        ClassGroupTypeSymbol* classGroupTypeSymbol = new ClassGroupTypeSymbol(classGroup);
        idTypeMap[id] = classGroupTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(classGroupTypeSymbol));
        return classGroupTypeSymbol;
    }
}

TypeSymbol* SymbolTable::MakeClassTemplateSpecializationSymbol(const Span& span, TypeSymbol* primaryClassTemplate, const std::vector<TypeSymbol*>& templateArguments)
{
    std::u32string id = MakeClassTemplateSpecializationId(primaryClassTemplate, templateArguments);
    auto it = idTypeMap.find(id);
    if (it != idTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        ClassTemplateSpecializationSymbol* classTemplateSpecializationSymbol = new ClassTemplateSpecializationSymbol(span,
            MakeClassTemplateSpecializationName(primaryClassTemplate, templateArguments), primaryClassTemplate, templateArguments, id);
        classTemplateSpecializationSymbol->SetAccess(Specifier::public_);
        idTypeMap[id] = classTemplateSpecializationSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(classTemplateSpecializationSymbol));
        if (gendocMode)
        {
            if (primaryClassTemplate->IsExternalTypeSymbol() && primaryClassTemplate->Name() == U"std::unique_ptr")
            {
                BeginContainer(classTemplateSpecializationSymbol);
                FunctionDeclaratorNode* functionDeclaratorNode = new FunctionDeclaratorNode(span, new IdDeclaratorNode(span, new IdentifierNode(span, U"get")), nullptr, Specifier());
                ownedNodes.push_back(std::unique_ptr<Node>(functionDeclaratorNode));
                std::vector<std::unique_ptr<TypeSymbol>> templateParameters;
                BeginFunction(functionDeclaratorNode, U"get", U"get()", templateParameters, Specifier(), std::u32string());
                FunctionSymbol* functionSymbol = static_cast<FunctionSymbol*>(container);
                std::vector<Derivation> derivations;
                derivations.push_back(Derivation::ptr);
                functionSymbol->SetReturnType(MakeDerivedTypeSymbol(derivations, templateArguments.front()));
                EndFunction(std::u32string());
                EndContainer();
            }
        }
        return classTemplateSpecializationSymbol;
    }
}

TypeSymbol* SymbolTable::MakeIntegerLiteralTypeSymbol(const Span& span, const std::u32string& valueName)
{
    std::u32string id = U"literal_" + valueName;
    auto it = idTypeMap.find(id);
    if (it != idTypeMap.cend())
    {
        return it->second;
    }
    else
    {
        IntegerLiteralTypeSymbol* integerLiteralTypeSymbol = new IntegerLiteralTypeSymbol(span, valueName, id);
        integerLiteralTypeSymbol->SetAccess(Specifier::public_);
        idTypeMap[id] = integerLiteralTypeSymbol;
        types.push_back(std::unique_ptr<TypeSymbol>(integerLiteralTypeSymbol));
        return integerLiteralTypeSymbol;
    }
}

} } // namespace gendoc::cppsym

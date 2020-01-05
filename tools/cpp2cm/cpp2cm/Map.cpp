// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/Map.hpp>
#include <sngcpp/symbols/ClassTemplateSpecializationSymbol.hpp>
#include <sngcpp/symbols/DerivedTypeSymbol.hpp>
#include <sngcpp/symbols/TypedefSymbol.hpp>
#include <sngcpp/symbols/ExternalTypeSymbol.hpp>
#include <sngcm/ast/Identifier.hpp>
#include <sngcm/ast/TypeExpr.hpp>
#include <sngcm/ast/Template.hpp>
#include <sngcm/ast/Expression.hpp>
#include <sngcm/ast/Class.hpp>
#include <soulng/util/Util.hpp>

namespace cpp2cm {

using namespace soulng::util;

std::u32string GetFullName(sngcm::ast::Node* node)
{
    if (!node) return std::u32string();
    std::u32string fullName = GetFullName(node->Parent());
    if (!fullName.empty())
    {
        fullName.append(1, '.');
    }
    if (node->GetNodeType() == sngcm::ast::NodeType::namespaceNode)
    {
        fullName.append(static_cast<sngcm::ast::NamespaceNode*>(node)->Id()->Str());
    }
    else if (node->GetNodeType() == sngcm::ast::NodeType::classNode)
    {
        fullName.append(static_cast<sngcm::ast::ClassNode*>(node)->Id()->Str());
    }
    else
    {
        int x = 0;
    }
    return fullName;
}

sngcm::ast::Node* MakeQualifiedIdNode(const std::u32string& fullName)
{
    sngcm::ast::Node* result = nullptr;
    if (!fullName.empty())
    {
        std::vector<std::u32string> components = Split(fullName, '.');
        while (!components.empty())
        {
            if (result)
            {
                result = new sngcm::ast::DotNode(soulng::lexer::Span(), result, new sngcm::ast::IdentifierNode(soulng::lexer::Span(), components.back()));
            }
            else
            {
                result = new sngcm::ast::IdentifierNode(soulng::lexer::Span(), components.back());
            }
            components.pop_back();
        }
    }
    if (!result)
    {
        result = new sngcm::ast::IdentifierNode(soulng::lexer::Span(), U"NOT_CONVERTED");
    }
    return result;
}

Map::Map() : symbolTable(nullptr), currentContext(nullptr)
{
    InitNameNodeTypeMap();
    InitSimpleTypeMap();
    ClearNamespaceImports();
}

void Map::InitNameNodeTypeMap()
{
    nameNodeTypeMap[U"bool"] = sngcm::ast::NodeType::boolNode;
    nameNodeTypeMap[U"sbyte"] = sngcm::ast::NodeType::sbyteNode;
    nameNodeTypeMap[U"byte"] = sngcm::ast::NodeType::byteNode;
    nameNodeTypeMap[U"short"] = sngcm::ast::NodeType::shortNode;
    nameNodeTypeMap[U"ushort"] = sngcm::ast::NodeType::ushortNode;
    nameNodeTypeMap[U"int"] = sngcm::ast::NodeType::intNode;
    nameNodeTypeMap[U"uint"] = sngcm::ast::NodeType::uintNode;
    nameNodeTypeMap[U"long"] = sngcm::ast::NodeType::longNode;
    nameNodeTypeMap[U"ulong"] = sngcm::ast::NodeType::ulongNode;
    nameNodeTypeMap[U"float"] = sngcm::ast::NodeType::floatNode;
    nameNodeTypeMap[U"double"] = sngcm::ast::NodeType::doubleNode;
    nameNodeTypeMap[U"char"] = sngcm::ast::NodeType::charNode;
    nameNodeTypeMap[U"wchar"] = sngcm::ast::NodeType::wcharNode;
    nameNodeTypeMap[U"uchar"] = sngcm::ast::NodeType::ucharNode;
    nameNodeTypeMap[U"void"] = sngcm::ast::NodeType::voidNode;
}

void Map::InitSimpleTypeMap()
{
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char_] = sngcm::ast::NodeType::charNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char_ | sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::charNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char_ | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::charNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char16] = sngcm::ast::NodeType::wcharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char16 | sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::wcharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char16 | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::wcharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char32] = sngcm::ast::NodeType::ucharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char32 | sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::ucharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::char32 | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::ucharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::wchar] = sngcm::ast::NodeType::ucharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::wchar | sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::ucharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::wchar | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::ucharNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::bool_] = sngcm::ast::NodeType::boolNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::short_] = sngcm::ast::NodeType::shortNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::short_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::shortNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::short_ | sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::shortNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::short_ | sngcpp::ast::SimpleTypeSpecifierFlags::signed_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::shortNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::short_ | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::ushortNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::short_ | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::ushortNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::intNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::intNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::int_ | sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::intNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::uintNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::int_ | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::uintNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::long_] = sngcm::ast::NodeType::longNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::long_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::longNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::long_ | sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::longNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::long_ | sngcpp::ast::SimpleTypeSpecifierFlags::signed_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::longNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::longLong_] = sngcm::ast::NodeType::longNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::longLong_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::longNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::longLong_ | sngcpp::ast::SimpleTypeSpecifierFlags::signed_] = sngcm::ast::NodeType::longNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::longLong_ | sngcpp::ast::SimpleTypeSpecifierFlags::signed_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::longNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::long_ | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::ulongNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::long_ | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::ulongNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::longLong_ | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_] = sngcm::ast::NodeType::ulongNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::longLong_ | sngcpp::ast::SimpleTypeSpecifierFlags::unsigned_ | sngcpp::ast::SimpleTypeSpecifierFlags::int_] = sngcm::ast::NodeType::ulongNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::float_] = sngcm::ast::NodeType::floatNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::double_] = sngcm::ast::NodeType::doubleNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::double_ | sngcpp::ast::SimpleTypeSpecifierFlags::long_] = sngcm::ast::NodeType::doubleNode;
    simpleTypeMap[sngcpp::ast::SimpleTypeSpecifierFlags::void_] = sngcm::ast::NodeType::voidNode;
}

sngcm::ast::Node* Map::CreateNode(sngcm::ast::NodeType nodeType)
{
    if (nodeType != sngcm::ast::NodeType::maxNode)
    {
        return sngcm::ast::NodeFactory::Instance().CreateNode(nodeType, soulng::lexer::Span());
    }
    return nullptr;
}

sngcm::ast::Node* Map::CreateNode(const std::u32string& name)
{
    auto it = nameNodeTypeMap.find(name);
    if (it != nameNodeTypeMap.cend())
    {
        sngcm::ast::NodeType nodeType = it->second;
        return CreateNode(nodeType);
    }
    return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), name);
}

void Map::MapNs(const std::u32string& source, const std::u32string& target)
{
    nsMap[source] = target;
}

std::u32string Map::GetNs(const std::u32string& source) const
{
    auto it = nsMap.find(source);
    if (it != nsMap.cend())
    {
        return it->second;
    }
    return source;
}

void Map::AddSourceXmlDoc(sngxml::dom::Document* sourceXmlDoc, const std::u32string& projectName)
{
    sourceXmlDocs.push_back(sourceXmlDoc);
    projectSourceXmlDocMap[projectName] = sourceXmlDoc;
}

void Map::SetSymbolTable(sngcpp::symbols::SymbolTable* symbolTable_)
{
    symbolTable = symbolTable_;
}

sngcm::ast::NodeType Map::MapSimpleType(sngcpp::ast::SimpleTypeSpecifierFlags flags)
{
    sngcm::ast::NodeType nodeType = sngcm::ast::NodeType::maxNode;
    auto it = simpleTypeMap.find(flags);
    if (it != simpleTypeMap.cend())
    {
        nodeType = it->second;
    }
    return nodeType;
}

sngcm::ast::NodeType Map::MapSimpleType(sngcpp::symbols::SimpleTypeSymbol* simpleTypeSymbol)
{
    return MapSimpleType(simpleTypeSymbol->Flags());
}

sngcm::ast::Node* Map::MakeDerivedType(sngcm::ast::Node* node, const std::vector<sngcpp::symbols::Derivation>& derivations)
{
    bool hasConst = false;
    bool lvalueRef = false;
    bool rvalueRef = false;
    for (auto derivation : derivations)
    {
        switch (derivation)
        {
            case sngcpp::symbols::Derivation::const_: hasConst = true; break;
            case sngcpp::symbols::Derivation::lvalueRef: lvalueRef = true;  break;
            case sngcpp::symbols::Derivation::rvalueRef: rvalueRef = true; break;
            case sngcpp::symbols::Derivation::ptr: node = new sngcm::ast::PointerNode(soulng::lexer::Span(), node); break;
            case sngcpp::symbols::Derivation::base: break;
            default:
            {
                return nullptr;
            }
        }
    }
    if (lvalueRef)
    {
        node = new sngcm::ast::LValueRefNode(soulng::lexer::Span(), node);
    }
    else if (rvalueRef)
    {
        node = new sngcm::ast::RValueRefNode(soulng::lexer::Span(), node);
    }
    if (hasConst)
    {
        node = new sngcm::ast::ConstNode(soulng::lexer::Span(), node); 
    }
    return node;
}

sngcm::ast::IdentifierNode* Map::MapFullTypeName(sngcpp::symbols::TypeSymbol* type)
{
    std::u32string fullTypeName;
    std::u32string fullNamespaceName;
    std::vector<sngcpp::symbols::Symbol*> parents;
    bool nonNamespaceParent = false;
    sngcpp::symbols::Symbol* parent = type->Parent();
    while (parent)
    {
        parents.push_back(parent);
        parent = parent->Parent();
    }
    int n = parents.size();
    for (int i = n - 1; i >= 0; --i)
    {
        sngcpp::symbols::Symbol* parent = parents[i];
        if (parent->IsNamespaceSymbol())
        {
            if (!parent->Name().empty())
            {
                std::u32string mappedNs = GetNs(parent->Name());
                if (!mappedNs.empty())
                {
                    if (!fullTypeName.empty())
                    {
                        fullTypeName.append(1, '.');
                    }
                    fullTypeName.append(mappedNs);
                    if (!fullNamespaceName.empty())
                    {
                        fullNamespaceName.append(1, '.');
                    }
                    fullNamespaceName.append(mappedNs);
                }
            }
        }
        else
        {
            if (!fullTypeName.empty())
            {
                fullTypeName.append(1, '.');
            }
            fullTypeName.append(parent->Name());
            nonNamespaceParent = true;
        }
    }
    std::u32string currentNamespaceName = GetFullName(currentContext->currentNamespace);
    if (!nonNamespaceParent && currentNamespaceName == fullNamespaceName)
    {
        return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), type->Name());
    }
    if (!fullTypeName.empty())
    {
        fullTypeName.append(1, '.');
    }
    fullTypeName.append(type->Name());
    return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), fullTypeName);
}

sngcm::ast::Node* Map::MapType(sngcpp::symbols::TypeSymbol* type, sngxml::dom::Document*& sourceXmlDoc)
{
    if (!sourceXmlDoc)
    {
        auto it = projectSourceXmlDocMap.find(type->ProjectName());
        if (it != projectSourceXmlDocMap.cend())
        {
            sourceXmlDoc = it->second;
        }
    }
    if (type->IsClassTemplateSpecializationSymbol())
    {
        sngcpp::symbols::ClassTemplateSpecializationSymbol* specialization = static_cast<sngcpp::symbols::ClassTemplateSpecializationSymbol*>(type);
        sngcpp::symbols::TypeSymbol* primaryType = specialization->PrimaryClassTemplateSymbol();
        std::unique_ptr<sngcm::ast::Node> primaryNode(MapType(primaryType, sourceXmlDoc));
        if (!primaryNode)
        {
            primaryNode.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), U"NOT_CONVERTED"));
        }
        std::unique_ptr<sngcm::ast::TemplateIdNode> templateIdNode(new sngcm::ast::TemplateIdNode(soulng::lexer::Span(), primaryNode.release()));
        for (const auto& templateArgumentType : specialization->TemplateArgumentSymbols())
        {
            std::unique_ptr<sngcm::ast::Node> templateArgumentNode(MapType(templateArgumentType, sourceXmlDoc));
            if (!templateArgumentNode)
            {
                templateArgumentNode.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), U"NOT_CONVERTED"));
            }
            templateIdNode->AddTemplateArgument(templateArgumentNode.release());
        }
        return templateIdNode.release();
    }
    else if (type->IsClassTypeSymbol())
    {
        sngcpp::symbols::ClassTypeSymbol* classTypeSymbol = static_cast<sngcpp::symbols::ClassTypeSymbol*>(type);
        if (classTypeSymbol->ProjectName() != currentProjectName)
        {
            if (sourceXmlDoc)
            {
                sngxml::dom::Element* element = sourceXmlDoc->GetElementById(classTypeSymbol->Id());
                if (element)
                {
                    std::u32string target = element->GetAttribute(U"target");
                    if (!target.empty())
                    {
                        target = RemoveNamespace(target);
                        return CreateNode(target);
                    }
                }
            }
        }
        sngcm::ast::Node* parentNode = nullptr;
        sngcpp::symbols::Symbol* parent = classTypeSymbol->Parent();
        auto it = currentContext->containerMap.find(parent);
        if (it != currentContext->containerMap.cend())
        {
            parentNode = it->second;
        }
        if (parentNode == currentContext->currentContainerNode)
        {
            return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), classTypeSymbol->Name());
        }
        else if (parentNode == nullptr)
        {
            return MapFullTypeName(classTypeSymbol);
        }
        else if (currentContext->currentContainerNode != nullptr)
        {
            std::u32string fullName = GetFullName(currentContext->currentContainerNode);
            if (!fullName.empty())
            {
                fullName.append(1, '.');
            }
            fullName.append(classTypeSymbol->Name());
            return MakeQualifiedIdNode(fullName);
        }
    }
    else if (type->IsEnumTypeSymbol())
    {
        sngcpp::symbols::EnumTypeSymbol* enumTypeSymbol = static_cast<sngcpp::symbols::EnumTypeSymbol*>(type);
        if (enumTypeSymbol->ProjectName() != currentProjectName)
        {
            if (sourceXmlDoc)
            {
                sngxml::dom::Element* element = sourceXmlDoc->GetElementById(enumTypeSymbol->Id());
                if (element)
                {
                    std::u32string target = element->GetAttribute(U"target");
                    if (!target.empty())
                    {
                        target = RemoveNamespace(target);
                        return CreateNode(target);
                    }
                }
            }
        }
        sngcm::ast::Node* parentNode = nullptr;
        sngcpp::symbols::Symbol* parent = enumTypeSymbol->Parent();
        auto it = currentContext->containerMap.find(parent);
        if (it != currentContext->containerMap.cend())
        {
            parentNode = it->second;
        }
        if (parentNode == currentContext->currentContainerNode)
        {
            return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), enumTypeSymbol->Name());
        }
        else if (parentNode == nullptr)
        {
            return MapFullTypeName(enumTypeSymbol);
        }
        else if (currentContext->currentContainerNode != nullptr)
        {
            std::u32string fullName = GetFullName(currentContext->currentContainerNode);
            if (!fullName.empty())
            {
                fullName.append(1, '.');
            }
            fullName.append(enumTypeSymbol->Name());
            return MakeQualifiedIdNode(fullName);
        }
    }
    else if (type->IsSimpleTypeSymbol())
    {
        sngcpp::symbols::SimpleTypeSymbol* simpleTypeSymbol = static_cast<sngcpp::symbols::SimpleTypeSymbol*>(type);
        sngcm::ast::NodeType nodeType = MapSimpleType(simpleTypeSymbol);
        return CreateNode(nodeType);
    }
    else if (type->IsDerivedTypeSymbol())
    {
        sngcpp::symbols::DerivedTypeSymbol* derivedTypeSymbol = static_cast<sngcpp::symbols::DerivedTypeSymbol*>(type);
        sngcm::ast::Node* node = MapType(derivedTypeSymbol->BaseType(), sourceXmlDoc);
        if (node)
        {
            return MakeDerivedType(node, derivedTypeSymbol->Derivations());
        }
    }
    else if (type->IsExternalTypeSymbol())
    {
        sngcpp::symbols::ExternalTypeSymbol* externalTypeSymbol = static_cast<sngcpp::symbols::ExternalTypeSymbol*>(type);
        if (sourceXmlDoc)
        {
            sngxml::dom::Element* element = sourceXmlDoc->GetElementById(externalTypeSymbol->Id());
            if (element)
            {
                std::u32string target = element->GetAttribute(U"target");
                if (!target.empty())
                {
                    target = RemoveNamespace(target);
                    return CreateNode(target);
                }
            }
        }
    }
    else if (type->IsTypedefSymbol())
    {
        sngcpp::symbols::TypedefSymbol* typedefSymbol = static_cast<sngcpp::symbols::TypedefSymbol*>(type);
        if (sourceXmlDoc)
        {
            std::u32string id = typedefSymbol->Id();
            if (!typedefSymbol->PrimaryId().empty())
            {
                id = typedefSymbol->PrimaryId();
            }
            sngxml::dom::Element* element = sourceXmlDoc->GetElementById(id);
            if (element)
            {
                std::u32string target = element->GetAttribute(U"target");
                if (!target.empty())
                {
                    if (typedefSymbol->Parent()->IsTypeSymbol())
                    {
                        sngxml::dom::Document* sxmldoc = nullptr;
                        sngcm::ast::Node* parentNode = MapType(static_cast<sngcpp::symbols::TypeSymbol*>(typedefSymbol->Parent()), sxmldoc);
                        sngcm::ast::DotNode* dotNode = new sngcm::ast::DotNode(soulng::lexer::Span(), parentNode, static_cast<sngcm::ast::IdentifierNode*>(CreateNode(target)));
                        return dotNode;
                    }
                    target = RemoveNamespace(target);
                    return CreateNode(target);
                }
            }
        }
    }
    else if (type->IsTemplateParameterSymbol())
    {
        return CreateNode(type->Name());
    }
    return nullptr;
}

sngcm::ast::IdentifierNode* Map::MapMemberSymbol(sngcpp::symbols::Symbol* memberSymbol, std::u32string& args)
{
    sngcpp::symbols::Symbol* parent = memberSymbol->Parent();
    if (!parent) return nullptr;
    if (parent->ProjectName() == currentProjectName)
    {
        return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), memberSymbol->Name());
    }
    std::u32string memberId = memberSymbol->Id();
    if (memberSymbol->IsCallableSymbol())
    {
        sngcpp::symbols::CallableSymbol* callableSymbol = static_cast<sngcpp::symbols::CallableSymbol*>(memberSymbol);
        memberId = callableSymbol->FunctionId();
    }
    auto it = projectSourceXmlDocMap.find(parent->ProjectName());
    if (it != projectSourceXmlDocMap.cend())
    {
        sngxml::dom::Document* sourceXmlDoc = it->second;
        sngxml::dom::Element* element = sourceXmlDoc->GetElementById(memberId);
        if (element)
        {
            std::u32string target = element->GetAttribute(U"target");
            if (!target.empty())
            {
                args = element->GetAttribute(U"args");
                target = RemoveNamespace(target);
                return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), target);
            }
        }
    }
    for (sngxml::dom::Document* sourceXmlDoc : sourceXmlDocs)
    {
        sngxml::dom::Element* element = sourceXmlDoc->GetElementById(memberId);
        if (element)
        {
            std::u32string target = element->GetAttribute(U"target");
            if (!target.empty())
            {
                args = element->GetAttribute(U"args");
                target = RemoveNamespace(target);
                return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), target);
            }
        }
    }
    return nullptr;
}

sngcm::ast::IdentifierNode* Map::MapFunctionSymbol(sngcpp::symbols::CallableSymbol* callableSymbol, std::u32string& args)
{
    std::u32string functionId = callableSymbol->FunctionId();
    auto it = projectSourceXmlDocMap.find(callableSymbol->ProjectName());
    if (it != projectSourceXmlDocMap.cend())
    {
        sngxml::dom::Document* sourceXmlDoc = it->second;
        sngxml::dom::Element* element = sourceXmlDoc->GetElementById(functionId);
        if (element)
        {
            std::u32string target = element->GetAttribute(U"target");
            if (!target.empty())
            {
                args = element->GetAttribute(U"args");
                target = RemoveNamespace(target);
                return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), target);
            }
        }
    }
    for (sngxml::dom::Document* sourceXmlDoc : sourceXmlDocs)
    {
        sngxml::dom::Element* element = sourceXmlDoc->GetElementById(functionId);
        if (element)
        {
            std::u32string target = element->GetAttribute(U"target");
            if (!target.empty())
            {
                args = element->GetAttribute(U"args");
                target = RemoveNamespace(target);
                return new sngcm::ast::IdentifierNode(soulng::lexer::Span(), target);
            }
        }
    }
    return nullptr;
}

void Map::ClearNamespaceImports()
{
    namespaceImports.clear();
    namespaceImports.insert(U"System");
    namespaceImports.insert(U"System.Collections");
}

std::u32string Map::RemoveNamespace(const std::u32string& qid)
{
    if (qid.find(':') != std::string::npos)
    {
        std::vector<std::u32string> components = Split(qid, ':');
        std::u32string namespacePart = components.front();
        namespaceImports.insert(namespacePart);
        return components.back();
    }
    std::vector<std::u32string> components = Split(qid, '.');
    if (!components.empty())
    {
        std::u32string namespacePart;
        for (int i = 0; i < components.size() - 1; ++i)
        {
            if (namespacePart.empty())
            {
                namespacePart = components[i];
            }
            else
            {
                namespacePart.append(1, '.').append(components[i]);
            }
        }
        if (!namespacePart.empty())
        {
            namespaceImports.insert(namespacePart);
        }
        return components.back();
    }
    return qid;
}

sngcm::ast::Specifiers MapSpecifiers(sngcpp::ast::Specifier specifiers)
{
    sngcm::ast::Specifiers mappedSpecifiers = sngcm::ast::Specifiers::none;
    if ((specifiers & sngcpp::ast::Specifier::static_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::static_;
    }
    if ((specifiers & sngcpp::ast::Specifier::constExpr) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::constexpr_;
    }
    if ((specifiers & sngcpp::ast::Specifier::const_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::const_;
    }
    if ((specifiers & sngcpp::ast::Specifier::default_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::default_;
    }
    if ((specifiers & sngcpp::ast::Specifier::delete_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::suppress_;
    }
    if ((specifiers & sngcpp::ast::Specifier::explicit_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::explicit_;
    }
    if ((specifiers & sngcpp::ast::Specifier::inline_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::inline_;
    }
    if ((specifiers & sngcpp::ast::Specifier::override_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::override_;
    }
    if ((specifiers & sngcpp::ast::Specifier::private_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::private_;
    }
    if ((specifiers & sngcpp::ast::Specifier::protected_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::protected_;
    }
    if ((specifiers & sngcpp::ast::Specifier::public_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::public_;
    }
    if ((specifiers & sngcpp::ast::Specifier::pure_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::abstract_;
    }
    if ((specifiers & sngcpp::ast::Specifier::virtual_) != sngcpp::ast::Specifier::none)
    {
        mappedSpecifiers = mappedSpecifiers | sngcm::ast::Specifiers::virtual_;
    }
    if ((mappedSpecifiers & sngcm::ast::Specifiers::abstract_) != sngcm::ast::Specifiers::none)
    {
        if ((mappedSpecifiers & sngcm::ast::Specifiers::virtual_) != sngcm::ast::Specifiers::none)
        {
            mappedSpecifiers = mappedSpecifiers & ~sngcm::ast::Specifiers::virtual_;
        }
    }
    return mappedSpecifiers;
}

sngcm::ast::Specifiers MapAccess(sngcpp::symbols::SymbolAccess access)
{
    switch (access)
    {
        case sngcpp::symbols::SymbolAccess::private_: return sngcm::ast::Specifiers::private_;
        case sngcpp::symbols::SymbolAccess::protected_: return sngcm::ast::Specifiers::protected_;
        case sngcpp::symbols::SymbolAccess::public_: return sngcm::ast::Specifiers::public_;
    }
    return sngcm::ast::Specifiers::none;
}

} // namespace cpp2cm

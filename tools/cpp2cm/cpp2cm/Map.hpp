// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_MAP_INCLUDED
#define CPP2CM_CPP2CM_MAP_INCLUDED
#include <cpp2cm/cpp2cm/Context.hpp>
#include <sngcm/ast/Specifier.hpp>
#include <sngcm/ast/Node.hpp>
#include <sngcpp/ast/Specifier.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngxml/dom/Document.hpp>
#include <string>
#include <unordered_map>

namespace cpp2cm {

std::u32string GetFullName(sngcm::ast::Node* node);
sngcm::ast::Node* MakeQualifiedIdNode(const std::u32string& fullName);

class Map
{
public:
    Map();
    void InitNameNodeTypeMap();
    void InitSimpleTypeMap();
    sngcm::ast::Node* CreateNode(const std::u32string& name);
    sngcm::ast::Node* CreateNode(sngcm::ast::NodeType nodeType);
    void MapNs(const std::u32string& source, const std::u32string& target);
    std::u32string GetNs(const std::u32string& source) const;
    void AddSourceXmlDoc(sngxml::dom::Document* sourceXmlDoc, const std::u32string& projectName);
    void SetSymbolTable(sngcpp::symbols::SymbolTable* symbolTable_);
    sngcm::ast::NodeType MapSimpleType(sngcpp::ast::SimpleTypeSpecifierFlags flags);
    sngcm::ast::NodeType MapSimpleType(sngcpp::symbols::SimpleTypeSymbol* simpleTypeSymbol);
    sngcm::ast::Node* MakeDerivedType(sngcm::ast::Node* node, const std::vector<sngcpp::symbols::Derivation>& derivations);
    sngcm::ast::IdentifierNode* MapFullTypeName(sngcpp::symbols::TypeSymbol* type);
    sngcm::ast::Node* MapType(sngcpp::symbols::TypeSymbol* type, sngxml::dom::Document*& sourceXmlDoc);
    sngcm::ast::IdentifierNode* MapMemberSymbol(sngcpp::symbols::Symbol* memberSymbol, std::u32string& args);
    sngcm::ast::IdentifierNode* MapFunctionSymbol(sngcpp::symbols::CallableSymbol* callableSymbol, std::u32string& args);
    std::u32string RemoveNamespace(const std::u32string& qid);
    void ClearNamespaceImports();
    const std::set<std::u32string>& NamespaceImports() const { return namespaceImports; }
    void SetCurrentContext(Context* context) { currentContext = context; }
    void SetCurrentProjectName(const std::u32string& projectName) { currentProjectName = projectName; }
    const std::u32string& CurrentProjectName() const { return currentProjectName; }
private:
    std::unordered_map<std::u32string, std::u32string> nsMap;
    std::vector<sngxml::dom::Document*> sourceXmlDocs;
    sngcpp::symbols::SymbolTable* symbolTable;
    std::unordered_map<std::u32string, sngxml::dom::Document*> projectSourceXmlDocMap;
    std::unordered_map<std::u32string, sngcm::ast::NodeType> nameNodeTypeMap;
    std::unordered_map<sngcpp::ast::SimpleTypeSpecifierFlags, sngcm::ast::NodeType> simpleTypeMap;
    std::set<std::u32string> namespaceImports;
    Context* currentContext;
    std::u32string currentProjectName;
};

sngcm::ast::Specifiers MapSpecifiers(sngcpp::ast::Specifier specifiers);
sngcm::ast::Specifiers MapAccess(sngcpp::symbols::SymbolAccess access);

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_MAP_INCLUDED

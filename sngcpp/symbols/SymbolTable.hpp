// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
#define SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED
#include <sngcpp/symbols/NamespaceSymbol.hpp>
#include <sngcpp/symbols/ClassTypeSymbol.hpp>
#include <sngcpp/symbols/EnumerationSymbol.hpp>
#include <sngcpp/symbols/FunctionSymbol.hpp>
#include <sngcpp/symbols/DeclarationBlockSymbol.hpp>
#include <sngcpp/symbols/SimpleTypeSymbol.hpp>
#include <sngcpp/symbols/DerivedTypeSymbol.hpp>
#include <sngcpp/symbols/RuleSymbol.hpp>
#include <sngcpp/ast/Class.hpp>
#include <sngcpp/ast/Enumeration.hpp>
#include <sngcpp/ast/Function.hpp>
#include <sngcpp/ast/Declaration.hpp>
#include <sngcpp/ast/Declarator.hpp>
#include <sngcpp/ast/SimpleType.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Template.hpp>
#include <sngcpp/ast/TypeExpr.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Element.hpp>
#include <stack>

namespace sngcpp { namespace symbols {

using namespace sngcpp::ast;

class SNGCPP_SYMBOLS_API SymbolTable
{
public:
    SymbolTable();
    std::unique_ptr<sngxml::dom::Document> ToDomDocument();
    std::unique_ptr<sngxml::dom::Element> ToDomElement();
    std::unique_ptr<sngxml::dom::Element> CreateTypesElement();
    void BeginContainer(ContainerSymbol* container_);
    void EndContainer();
    int BeginNameSequence(const std::vector<std::pair<std::u32string, int>>& nameSequence);
    void EndNameSequence(int n);
    void BeginNamespace(const std::u32string& namespaceName, const std::u32string& projectName);
    void EndNamespace();
    void BeginClass(ClassNode* classNode, const std::u32string& className, std::vector<std::unique_ptr<TypeSymbol>>& templateParameters, const std::u32string& projectName);
    void EndClass(const std::u32string& projectName);
    void BeginLambdaExpression(LambdaExpressionNode* lambdaExpressionNode);
    void EndLambdaExpression();
    void BeginGrammar(const Span& span, const std::u32string& grammarName, const std::u32string& projectName);
    void EndGrammar(const std::u32string& projectName);
    RuleSymbol* AddRule(const Span& span, const std::u32string& ruleName);
    void BeginEnumType(EnumTypeNode* enumTypeNode, const std::u32string& enumTypeName, const std::u32string& projectName);
    void EndEnumType(const std::u32string& projectName);
    void AddEnumerator(EnumeratorNode* enumeratorNode, const std::u32string& enumeratorName, const std::u32string& enumeratorValue);
    void BeginFunction(FunctionDeclaratorNode* functionDeclaratorNode, const std::u32string& groupName, const std::u32string& functionName,
        std::vector<std::unique_ptr<TypeSymbol>>& templateParameters, Specifier specifiers, const std::u32string& projectName);
    void EndFunction(const std::u32string& projectName);
    void BeginFunctionDeclaration(FunctionDeclaratorNode* functionDeclaratorNode, const std::u32string& groupName, const std::u32string& functionName,
        std::vector<std::unique_ptr<TypeSymbol>>& templateParameters, Specifier specifiers, const std::u32string& projectName);
    void EndFunctionDeclaration();
    void AddParameter(ParameterNode* parameterNode, const std::u32string& parameterName);
    void BeginDeclarationBlock(Node* blockNode);
    void EndDeclarationBlock();
    void AddTypedef(TypedefNode* node, const std::u32string& typedefName, const std::u32string& projectName);
    void AddVariable(Node* node, const std::u32string& variableName, const std::u32string& projectName);
    void MapNode(Node* node, Symbol* symbol);
    void MapIdNodeSequence(Node* node, const std::vector<IdentifierNode*>& idNodeSequence);
    void MapTemplateIdToTemplateArgumentNodes(TemplateIdNode* templateIdNode, const std::vector<Node*>& templateArgumentNodes);
    Symbol* GetSymbolNothrow(Node* node);
    Symbol* GetSymbol(Node* node);
    const std::vector<IdentifierNode*>& GetIdNodeSequence(Node* node);
    const std::vector<Node*>& GetTemplateArgumentNodes(TemplateIdNode* templateIdNode);
    NamespaceSymbol* GlobalNs() { return &globalNs; }
    ContainerScope* GetContainerScope();
    TypeSymbol* GetBoolType();
    TypeSymbol* GetLongType();
    TypeSymbol* GetDoubleType();
    TypeSymbol* GetIntType();
    TypeSymbol* GetUIntType();
    TypeSymbol* GetCharType();
    TypeSymbol* GetChar16Type();
    TypeSymbol* GetChar32Type();
    TypeSymbol* GetVoidType();
    TypeSymbol* MakeSimpleTypeSymbol(SimpleTypeNode& simpleTypeNode);
    TypeSymbol* MakeElaborateClassTypeSymbol(ClassKey classKey, TypeSymbol* classType);
    TypeSymbol* MakeDerivedTypeSymbol(std::vector<Derivation>& derivations, TypeSymbol* baseType);
    TypeSymbol* MakeExternalTypeSymbol(const Span& span, const std::u32string& name, ClassKey classKey);
    TypeSymbol* MakeClassGroupTypeSymbol(ClassGroupSymbol* classGroup);
    TypeSymbol* MakeClassTemplateSpecializationSymbol(const Span& span, TypeSymbol* primaryClassTemplate, const std::vector<TypeSymbol*>& templateArguments);
    TypeSymbol* MakeIntegerLiteralTypeSymbol(const Span& span, const std::u32string& valueName);
    void SetGendocMode() { gendocMode = true; }
    bool InGendocMode() const { return gendocMode; }
private:
    NamespaceSymbol globalNs;
    ContainerSymbol* container;
    std::stack<ContainerSymbol*> containerStack;
    std::unordered_map<Node*, Symbol*> nodeSymbolMap;
    std::unordered_map<Node*, std::vector<IdentifierNode*>> idNodeSequenceMap;
    std::unordered_map<TemplateIdNode*, std::vector<Node*>> templateIdTemplateArgumentNodeMap;
    int blockNumber;
    std::unordered_map<std::u32string, TypeSymbol*> idTypeMap;
    std::vector<std::unique_ptr<TypeSymbol>> types;
    std::vector<std::unique_ptr<Node>> ownedNodes;
    bool gendocMode;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_TABLE_INCLUDED

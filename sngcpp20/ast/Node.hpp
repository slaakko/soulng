// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_NODE_INCLUDED
#define SNGCPP_AST_NODE_INCLUDED
#include <sngcpp20/ast/AstApi.hpp>
#include <sngcpp20/ast/NodeList.hpp>
#include <soulng/lexer/SourcePos.hpp>
#include <memory>
#include <stdint.h>
#include <string>

namespace sngcpp::ast {

using soulng::lexer::SourcePos;

class Visitor;
class Writer;
class Reader;

enum class NodeType
{
    single, compound, unary, binary, sequence, list
};

AST_API std::string NodeTypeStr(NodeType nodeType);

enum class NodeKind : uint16_t
{
    nullNode,
    translationUnitNode, moduleUnitNode, 
    moduleDeclarationNode, exportDeclarationNode, exportNode, importNode, importDeclarationNode, modulePartitionNode, moduleNode, globalModuleFragmentNode, privateModuleFragmentNode,
    angleHeaderNameNode, quoteHeaderNameNode,
    identifierNode, unnamedNode, colonColonNode, nestedNameSpecifierNode, qualifiedIdNode, identifierListNode, qualifiedModuleIdNode,
    charNode, char8Node, char16Node, char32Node, wcharNode, boolNode, shortNode, intNode, longNode, signedNode, unsignedNode, floatNode, doubleNode, voidNode,
    constNode, volatileNode, lvalueRefNode, rvalueRefNode, ptrNode, cvQualifierSequenceNode, ptrOperatorNode, noexceptSpecifierNode, packDeclaratorIdNode, subscriptDeclaratorNode, invokeDeclaratorNode,
    prefixNode, trailingQualifiersNode, trailingAttributesNode, ptrDeclaratorNode,
    expressionListNode, assignmentInitializerNode, 
    conditionalExprNode, questNode, colonNode, commaNode, binaryExprNode, unaryExprNode, yieldExprNode, throwExprNode,
    assignNode, plusAssignNode, minusAssignNode, mulAssignNode, divAssignNode, modAssignNode, xorAssignNode, andAssignNode, orAssignNode, shiftLeftAssignNode, shiftRightAssignNode,
    disjunctionNode, conjunctionNode, inclusiveOrNode, exclusiveOrNode, andNode, equalNode, notEqualNode, lessNode, greaterNode, lessOrEqualNode, greaterOrEqualNode,
    compareNode, shiftLeftNode, shiftRightNode, plusNode, minusNode, mulNode, divNode, modNode, dotStarNode, arrowStarNode,
    castExprNode, derefNode, addrOfNode, notNode, complementNode, prefixIncNode, prefixDecNode,
    awaitExprNode, sizeOfTypeExprNode, sizeOfPackExpNode, sizeOfUnaryExprNode, alignOfExprNode, noexceptExprNode, 
    foldExprNode, newDeclaratorNode, arrayNewDeclaratorNode, newInitializerNode, ellipsesNode, bracedInitListNode, designatedInitializerNode, designatorNode,
    newExprNode, newPlacementNode, parenNewTypeIdNode, newTypeIdNode, arrayDeletePtrNode, deletePtrNode,
    subscriptExprNode, invokeExprNode, dotNode, templateNode, arrowNode, pairNode, memberExprNode, postfixIncExprNode, postfixDecExprNode, typeIdExprNode,
    dynamicCastNode, staticCastNode, reinterpretCastNode, constCastNode, cppCastExprNode, thisNode, parenExprNode,
    lambdaExpressionNode, lambdaIntroducerNode, lambdaCaptureNode, lambdaDeclaratorNode, lambdaSpecifiersNode, lambdaTemplateParamsNode,
    defaultRefCaptureNode, defaultCopyCaptureNode, byRefCaptureNode, simpleCaptureNode, initCaptureNode, currentObjectCopyCapture, currentObjectByRefCapture,
    integerLiteralNode, floatingLiteralNode, characterLiteralNode, stringLiteralNode, rawStringLiteralNode, booleanLiteralNode, nullPtrLiteralNode, userDefinedLiteralNode, literalOperatorIdNode,
    labeledStatementNode, caseStatmentNode, defaultStatementNode, compoundStatementNode, ifStatementNode, switchStatemeNode, whileStatementNode, doStatementNode,
    rangeForStatementNode, forRangeDeclarationNode, structuredBindingNode, forStatementNode, breakStatementNode, continueStatementNode, returnStatementNode, coReturnStatementNode,
    gotoStatementNode, tryStatementNode, handlerSequenceNode, handlerNode, exceptionDeclarationNode, expressionStatementNode, declarationStatementNode, initConditionNode, semicolonNode,
    templateDeclarationNode, templateHeadNode, templateParameterListNode, typeParameterNode, templateIdNode, typenameNode, deductionGuideNode, explicitInstantiationNode, explicitSpecializationNode,
    declarationSequenceNode, simpleDeclarationNode, usingDeclarationNode, usingNode, usingDeclaratorListNode, usingEnumDeclarationNode, emptyDeclarationNode, namespaceNode, usingDirectiveNode,
    asmDeclarationNode, asmNode, namespaceAliasDefinitionNode, staticAssertDeclarationNode, staticAssertNode, aliasDeclarationNode, definingTypeIdNode, definingTypeSpecifierSequenceNode,
    opaqueEnumDeclarationNode, functionDeclarationNode, linkageSpecificationNode, namespaceDefinitionNode, namespaceBodyNode, attributeDeclarationNode,
    initDeclaratorListNode, initDeclaratorNode, trailingInvokeDeclaratorNode, parenthesizedDeclaratorNode, abstractDeclaratorNode, declSpecifierSequenceNode,
    friendNode, typedefNode, constExprNode, constEvalNode, constInitNode, inlineNode, staticNode, threadLocalNode, externNode, mutableNode, virtualNode, explicitNode, conditionalExplicitNode,
    qualifiedPtrNode,
    typeSpecifierSequenceNode, typenameSpecifierNode, typeIdNode, trailingReturnTypeNode, elaboratedTypeSpecifierNode, declTypeSpecifierNode, placeholderTypeSpecifierNode,
    classSpecifierNode, classHeadNode, baseClauseNode, baseSpecifierListNode, baseSpecifierNode, beginAccessGroupNode, memberDeclarationNode, memberDeclaratorListNode, virtSpecifierSequenceNode,
    constructorNode, constructorInitializerNode, memberInitializerListNode, memberInitializerNode,
    publicNode, protectedNode, privateNode, classNode, structNode, unionNode, overrideNode, finalNode, pureSpecifierNode,
    enumSpecifierNode, enumHeadNode, enumBaseNode, enumClassNode, enumStructNode, enumNode, enumeratorDefinitionNode, enumeratorNode, elaboratedEnumSpecifierNode,
    functionDefinitionNode, functionBodyNode, generatedFunctionBodyNode, defaultNode, deleteNode,
    operatorFnIdNode, operatorNode, newArrayOpNode, newOpNode, deleteArrayOpNode, deleteOpNode, coAwaitOpNode, invokeOpNode, subscriptOpNode,
    conversionFnIdNode, conversionTypeIdNode, conversionDeclaratorNode, destructorIdNode, parameterNode, parameterListNode, noexceptNode, functionTryBlock,
    conceptDefinitionNode, requiresExprNode, requirementBodyNode, simpleRequirementNode, typeRequirementNode, compoundRequirementNode, returnTypeRequirementNode, nestedRequirementNode, 
    typeConstraintNode, requiresClauseNode,
    attributeSpecifierSequenceNode, attributeSpecifierNode, attributeUsingPrefixNode, attrbuteNode, attributeScopedTokenNode, attributeArgumentsNode, balancedTokenSequenceNode, tokenNode,
    lparenNode, rparenNode, lbracketNode, rbracketNode, lbraceNode, rbraceNode, alignmentSpecifierNode,
    max
};

AST_API std::string NodeKindStr(NodeKind nodeKind);

class AST_API Node
{
public:
    Node(NodeKind kind_, const SourcePos& sourcePos_);
    virtual ~Node();
    NodeKind Kind() const { return kind; }
    virtual std::u32string Str() const { return std::u32string(); }
    virtual NodeType Type() const { return NodeType::single; }
    virtual int Count() const { return 0; }
    const SourcePos& GetSourcePos() const { return sourcePos; }
    void SetSourcePos(const SourcePos& sourcePos_) { sourcePos = sourcePos_; }
    virtual void Accept(Visitor& visitor) = 0;
    virtual void Write(Writer& writer);
    virtual void Read(Reader& reader);
    virtual void AddNode(Node* node);
    virtual void Clear();
    Node* Parent() const { return parent; }
    void SetParent(Node* parent_) { parent = parent_; }
private:
    NodeKind kind;
    SourcePos sourcePos;
    Node* parent;
};

class AST_API CompoundNode : public Node
{
public:
    CompoundNode(NodeKind kind_, const SourcePos& sourcePos_);
    NodeType Type() const override { return NodeType::compound; }
};

class AST_API UnaryNode : public Node
{
public:
    UnaryNode(NodeKind kind_, const SourcePos& sourcePos_, Node* child_);
    UnaryNode(const UnaryNode&) = delete;
    UnaryNode& operator=(const UnaryNode&) = delete;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    NodeType Type() const override { return NodeType::unary; }
    int Count() const override { return 1; }
    Node* Child() const { return child.get(); }
private:
    std::unique_ptr<Node> child;
};

class AST_API BinaryNode : public Node
{
public:
    BinaryNode(NodeKind kind_, const SourcePos& sourcePos_, Node* left_, Node* right_);
    BinaryNode(const BinaryNode&) = delete;
    BinaryNode& operator=(const BinaryNode&) = delete;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    NodeType Type() const override { return NodeType::binary; }
    int Count() const override { return 2; }
    Node* Left() const { return left.get(); }
    Node* Right() const { return right.get(); }
private:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

class AST_API SequenceNode : public Node
{
public:
    SequenceNode(NodeKind kind_, const SourcePos& sourcePos_);
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    NodeType Type() const override { return NodeType::sequence; }
    int Count() const override { return nodes.Count(); }
    void AddNode(Node* node) override;
    void Clear() override;
    NodeList<Node>& Nodes() { return nodes; }
private:
    NodeList<Node> nodes;
};

class AST_API ListNode : public Node
{
public:
    ListNode(NodeKind kind_, const SourcePos& sourcePos_);
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    NodeType Type() const override { return NodeType::list; }
    int Count() const override { return nodes.Count(); }
    void AddNode(Node* node) override;
    void Clear() override;
    NodeList<Node>& Nodes() { return nodes; }
    const std::vector<Node*> Items() const { return items; }
private:
    NodeList<Node> nodes;
    std::vector<Node*> items;
};

AST_API Node* CreateNode(NodeKind nodeKind, const SourcePos& sourcePos);
AST_API void NodeInit();
AST_API void NodeDone();

} // namespace sngcpp::ast

#endif // SNGCPP_AST_NODE_INCLUDED

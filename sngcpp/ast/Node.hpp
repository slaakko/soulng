// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_NODE_INCLUDED
#define SNGCPP_AST_NODE_INCLUDED
#include <sngcpp/ast/AstApi.hpp>
#include <soulng/lexer/Span.hpp>
#include <memory>
#include <vector>

namespace sngcpp { namespace ast {

using soulng::lexer::Span;

class Visitor;
class Writer;
class Reader;

enum class NodeType
{
    baseClassSpecifierNode, baseClassSpecifierSequenceNode, forwardClassDeclarationNode, elaborateClassNameNode, classNode, memberAccessDeclarationNode, memberDeclarationNode,
    specialMemberFunctionNode, ctorInitializerNode, memberInitializerNode, memberInitializerSequenceNode, simpleDeclarationNode, aliasDeclarationNode, usingDirectiveNode,
    usingDeclarationNode, typedefNode, declarationSequenceNode, linkageSpecificationNode, idDeclaratorNode, arrayDeclaratorNode, functionDeclaratorNode, functionPtrIdNode,
    memberFunctionPtrIdNode, initDeclaratorNode, assignmentInitializerNode, expressionListInitializerNode, expressionInitializerNode, bracedInitializerListNode,
    enumTypeNode, enumeratorNode, enumeratorSequenceNode, expressionSequenceNode, commaExpressionNode, assignmentExpressionNode, conditionalExpressionNode,
    throwExpressionNode, logicalOrExpressionNode, logicalAndExpressionNode, inclusiveOrExpressionNode, exclusiveOrExpressionNode, andExpressionNode, equalityExpressionNode,
    relationalExpressionNode, shiftExpressionNode, additiveExpressionNode, multiplicativeExpressionNode, pmExpressionNode, castExpressionNode, unaryExpressionNode,
    newExpressionNode, deleteExpressionNode, subscriptExpressionNode, invokeExpressionNode, dotNode, arrowNode, postfixIncNode, postfixDecNode, cppCastExpressionNode,
    typeIdExpressionNode, thisNode, identifierNode, operatorFunctionIdNode, conversionFunctionIdNode, dtorIdNode, nestedIdNode, parenthesizedExprNode, lambdaExpressionNode,
    captureSequenceNode, assignCaptureNode, refCaptureNode, thisCaptureNode, identifierCaptureNode, parameterNode, parameterSequenceNode, functionNode, floatingLiteralNode, integerLiteralNode,
    characterLiteralNode, stringLiteralNode, booleanLiteralNode, nullPtrLiteralNode, namespaceNode, simpleTypeNode, sourceFileNode, sourceFileSequenceNode, labeledStatementNode,
    caseStatementNode, defaultStatementNode, expressionStatementNode, compoundStatementNode, statementSequenceNode, ifStatementNode, switchStatementNode, whileStatementNode,
    doStatementNode, rangeForStatementNode, forStatementNode, breakStatementNode, continueStatementNode, returnStatementNode, gotoStatementNode, declarationStatementNode,
    tryStatementNode, handlerNode, handlerSequenceNode, catchAllNode, typeParameterNode, templateParameterSequenceNode, templateDeclarationNode, templateArgumentSequenceNode,
    templateIdNode, templateArgumentNode, explicitInstantiationNode, explicitSpecializationNode, constNode, volatileNode, pointerNode, rValueRefNode, lValueRefNode, typeExprNode,
    max
};

class Node;

class NodeCreator
{
public:
    virtual ~NodeCreator();
    virtual Node* Create() = 0;
};

class SNGCPP_AST_API Node
{
public:
    Node(NodeType nodeType_);
    Node(NodeType nodeType_, const Span& span_);
    NodeType GetNodeType() const { return nodeType; }
    virtual ~Node();
    virtual void Accept(Visitor& visitor) = 0;
    virtual void Write(Writer& writer);
    virtual void Read(Reader& reader);
    virtual void SetFullSpan();
    const Span& GetSpan() const { return span; }
    void SetSpanStart(int32_t spanStart) { span.start = spanStart; }
    void SetSpanEnd(int32_t spanEnd) { span.end = spanEnd;  }
    virtual bool IsFunctionDeclaratorNode() const { return false; }
    virtual bool IsTemplateArgumentSequenceNode() const { return false; }
    virtual bool IsIdentifierNode() const { return false; }
    virtual bool IsOperatorFunctionIdNode() const { return false; }
    virtual bool IsConversionFunctionIdNode() const { return false; }
    virtual bool IsDtorIdNode() const { return false; }
    virtual bool IsTemplateIdNode() const { return false; }
private:
    NodeType nodeType;
    Span span;
};

class SNGCPP_AST_API UnaryNode : public Node
{
public:
    UnaryNode(NodeType nodeType_);
    UnaryNode(NodeType nodeType_, const Span& span_);
    UnaryNode(NodeType nodeType_, const Span& span_, Node* child_);
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetFullSpan() override;
    Node* Child() { return child.get(); }
    void SetChild(Node* child_) { child.reset(child_); }
    Node* ReleaseChild() { return child.release(); }
private:
    std::unique_ptr<Node> child;
};

class SNGCPP_AST_API BinaryNode : public Node
{
public:
    BinaryNode(NodeType nodeType_);
    BinaryNode(NodeType nodeType_, const Span& span_, Node* left_, Node* right_);
    Node* Left() { return left.get(); }
    Node* Right() { return right.get(); }
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetFullSpan() override;
private:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

class SNGCPP_AST_API NodeFactory
{
public:
    NodeFactory();
    NodeFactory(const NodeFactory&) = delete;
    NodeFactory(NodeFactory&&) = delete;
    NodeFactory& operator=(const NodeFactory&) = delete;
    NodeFactory& operator=(NodeFactory&&) = delete;
    static void Init();
    static void Done();
    static NodeFactory& Instance();
    Node* CreateNode(NodeType nodeType);
private:
    static std::unique_ptr<NodeFactory> instance;
    std::vector<std::unique_ptr<NodeCreator>> creators;
};

SNGCPP_AST_API void NodeInit();
SNGCPP_AST_API void NodeDone();

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_NODE_INCLUDED

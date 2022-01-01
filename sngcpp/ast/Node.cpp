// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Node.hpp>
#include <sngcpp/ast/Class.hpp>
#include <sngcpp/ast/Declaration.hpp>
#include <sngcpp/ast/Enumeration.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Function.hpp>
#include <sngcpp/ast/Namespace.hpp>
#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/ast/Template.hpp>
#include <sngcpp/ast/TypeExpr.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>
#include <algorithm>

namespace sngcpp { namespace ast {

NodeCreator::~NodeCreator()
{
}

template<class T>
class ConcreteNodeCreator : public NodeCreator
{
public:
    Node* Create() override
    {
        return new T();
    }
};

Node::Node(NodeType nodeType_) : nodeType(nodeType_), parent(nullptr)
{
}

Node::Node(NodeType nodeType_, const Span& span_) : nodeType(nodeType_), span(span_), parent(nullptr)
{
}

void Node::Write(Writer& writer)
{
    writer.Write(nodeType);
    writer.Write(span);
}

void Node::Read(Reader& reader)
{
    reader.Read(span);
}

void Node::SetFullSpan()
{
}

Node::~Node()
{
}

UnaryNode::UnaryNode(NodeType nodeType_) : Node(nodeType_)
{
}

UnaryNode::UnaryNode(NodeType nodeType_, const Span& span_) : Node(nodeType_, span_)
{
}

UnaryNode::UnaryNode(NodeType nodeType_, const Span& span_, Node* child_) : Node(nodeType_, span_), child(child_)
{
    if (child)
    {
        child->SetParent(this);
    }
}

void UnaryNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(child != nullptr);
    if (child)
    {
        child->Write(writer);
    }
}

void UnaryNode::Read(Reader& reader)
{
    Node::Read(reader);
    bool hasChild = reader.GetBinaryReader().ReadBool();
    if (hasChild)
    {
        child.reset(reader.ReadNode());
        child->SetParent(this);
    }
}

void UnaryNode::SetFullSpan()
{
    if (child)
    {
        const Span& thisSpan = GetSpan();
        child->SetFullSpan();
        const Span& childSpan = child->GetSpan();
        SetSpanStart(std::min(thisSpan.start, childSpan.start));
        SetSpanEnd(std::max(thisSpan.end, childSpan.end));
    }
}

BinaryNode::BinaryNode(NodeType nodeType_) : Node(nodeType_)
{
}

BinaryNode::BinaryNode(NodeType nodeType_, const Span& span_, Node* left_, Node* right_) : Node(nodeType_, span_), left(left_), right(right_)
{
    if (left)
    {
        left->SetParent(this);
    }
    right->SetParent(this);
}

void BinaryNode::Write(Writer& writer)
{
    Node::Write(writer);
    bool hasLeft = left != nullptr;
    writer.GetBinaryWriter().Write(hasLeft);
    if (hasLeft)
    {
        left->Write(writer);
    }
    right->Write(writer);
}

void BinaryNode::Read(Reader& reader)
{
    Node::Read(reader);
    bool hasLeft = reader.GetBinaryReader().ReadBool();
    if (hasLeft)
    {
        left.reset(reader.ReadNode());
        left->SetParent(this);
    }
    right.reset(reader.ReadNode());
    right->SetParent(this);
}

void BinaryNode::SetFullSpan()
{
    if (!left) return;
    const Span& thisSpan = GetSpan();
    left->SetFullSpan();
    right->SetFullSpan();
    const Span& leftSpan = left->GetSpan();
    const Span& rightSpan = right->GetSpan();
    SetSpanStart(std::min(thisSpan.start, std::min(leftSpan.start, rightSpan.start)));
    SetSpanEnd(std::max(thisSpan.end, std::max(leftSpan.end, rightSpan.end)));
}

std::unique_ptr<NodeFactory> NodeFactory::instance;

void NodeFactory::Init()
{
    instance.reset(new NodeFactory());
}

void NodeFactory::Done()
{
    instance.reset();
}

NodeFactory& NodeFactory::Instance()
{
    return *instance;
}

NodeFactory::NodeFactory()
{
    creators.resize(static_cast<int>(NodeType::max));
    creators[static_cast<int>(NodeType::baseClassSpecifierNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<BaseClassSpecifierNode>());
    creators[static_cast<int>(NodeType::baseClassSpecifierSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<BaseClassSpecifierSequenceNode>());
    creators[static_cast<int>(NodeType::forwardClassDeclarationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ForwardClassDeclarationNode>());
    creators[static_cast<int>(NodeType::elaborateClassNameNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ElaborateClassNameNode>());
    creators[static_cast<int>(NodeType::classNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ClassNode>());
    creators[static_cast<int>(NodeType::memberAccessDeclarationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<MemberAccessDeclarationNode>());
    creators[static_cast<int>(NodeType::memberDeclarationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<MemberDeclarationNode>());
    creators[static_cast<int>(NodeType::specialMemberFunctionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<SpecialMemberFunctionNode>());
    creators[static_cast<int>(NodeType::ctorInitializerNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CtorInitializerNode>());
    creators[static_cast<int>(NodeType::memberInitializerNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<MemberInitializerNode>());
    creators[static_cast<int>(NodeType::memberInitializerSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<MemberInitializerSequenceNode>());
    creators[static_cast<int>(NodeType::simpleDeclarationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<SimpleDeclarationNode>());
    creators[static_cast<int>(NodeType::aliasDeclarationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<AliasDeclarationNode>());
    creators[static_cast<int>(NodeType::usingDirectiveNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<UsingDirectiveNode>());
    creators[static_cast<int>(NodeType::usingDeclarationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<UsingDeclarationNode>());
    creators[static_cast<int>(NodeType::typedefNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TypedefNode>());
    creators[static_cast<int>(NodeType::declarationSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<DeclarationSequenceNode>());
    creators[static_cast<int>(NodeType::linkageSpecificationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<LinkageSpecificationNode>());
    creators[static_cast<int>(NodeType::idDeclaratorNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<IdDeclaratorNode>());
    creators[static_cast<int>(NodeType::arrayDeclaratorNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ArrayDeclaratorNode>());
    creators[static_cast<int>(NodeType::functionDeclaratorNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<FunctionDeclaratorNode>());
    creators[static_cast<int>(NodeType::functionPtrIdNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<FunctionPtrIdNode>());
    creators[static_cast<int>(NodeType::memberFunctionPtrIdNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<MemberFunctionPtrIdNode>());
    creators[static_cast<int>(NodeType::initDeclaratorNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<InitDeclaratorNode>());
    creators[static_cast<int>(NodeType::assignmentInitializerNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<AssignmentInitializerNode>());
    creators[static_cast<int>(NodeType::expressionListInitializerNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ExpressionListInitializerNode>());
    creators[static_cast<int>(NodeType::expressionInitializerNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ExpressionInitializerNode>());
    creators[static_cast<int>(NodeType::bracedInitializerListNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<BracedInitializerListNode>());
    creators[static_cast<int>(NodeType::enumTypeNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<EnumTypeNode>());
    creators[static_cast<int>(NodeType::enumeratorNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<EnumeratorNode>());
    creators[static_cast<int>(NodeType::enumeratorSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<EnumeratorSequenceNode>());
    creators[static_cast<int>(NodeType::expressionSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ExpressionSequenceNode>());
    creators[static_cast<int>(NodeType::commaExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CommaExpressionNode>());
    creators[static_cast<int>(NodeType::assignmentExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<AssignmentExpressionNode>());
    creators[static_cast<int>(NodeType::conditionalExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ConditionalExpressionNode>());
    creators[static_cast<int>(NodeType::throwExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ThrowExpressionNode>());
    creators[static_cast<int>(NodeType::logicalOrExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<LogicalOrExpressionNode>());
    creators[static_cast<int>(NodeType::logicalAndExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<LogicalAndExpressionNode>());
    creators[static_cast<int>(NodeType::inclusiveOrExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<InclusiveOrExpressionNode>());
    creators[static_cast<int>(NodeType::exclusiveOrExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ExclusiveOrExpressionNode>());
    creators[static_cast<int>(NodeType::andExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<AndExpressionNode>());
    creators[static_cast<int>(NodeType::equalityExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<EqualityExpressionNode>());
    creators[static_cast<int>(NodeType::relationalExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<RelationalExpressionNode>());
    creators[static_cast<int>(NodeType::shiftExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ShiftExpressionNode>());
    creators[static_cast<int>(NodeType::additiveExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<AdditiveExpressionNode>());
    creators[static_cast<int>(NodeType::multiplicativeExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<MultiplicativeExpressionNode>());
    creators[static_cast<int>(NodeType::pmExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<PMExpressionNode>());
    creators[static_cast<int>(NodeType::castExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CastExpressionNode>());
    creators[static_cast<int>(NodeType::unaryExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<UnaryExpressionNode>());
    creators[static_cast<int>(NodeType::newExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<NewExpressionNode>());
    creators[static_cast<int>(NodeType::deleteExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<DeleteExpressionNode>());
    creators[static_cast<int>(NodeType::subscriptExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<SubscriptExpressionNode>());
    creators[static_cast<int>(NodeType::invokeExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<InvokeExpressionNode>());
    creators[static_cast<int>(NodeType::dotNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<DotNode>());
    creators[static_cast<int>(NodeType::arrowNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ArrowNode>());
    creators[static_cast<int>(NodeType::postfixIncNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<PostfixIncNode>());
    creators[static_cast<int>(NodeType::postfixDecNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<PostfixDecNode>());
    creators[static_cast<int>(NodeType::cppCastExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CppCastExpressionNode>());
    creators[static_cast<int>(NodeType::typeIdExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TypeIdExpressionNode>());
    creators[static_cast<int>(NodeType::thisNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ThisNode>());
    creators[static_cast<int>(NodeType::identifierNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<IdentifierNode>());
    creators[static_cast<int>(NodeType::operatorFunctionIdNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<OperatorFunctionIdNode>());
    creators[static_cast<int>(NodeType::conversionFunctionIdNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ConversionFunctionIdNode>());
    creators[static_cast<int>(NodeType::dtorIdNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<DtorIdNode>());
    creators[static_cast<int>(NodeType::nestedIdNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<NestedIdNode>());
    creators[static_cast<int>(NodeType::parenthesizedExprNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ParenthesizedExprNode>());
    creators[static_cast<int>(NodeType::lambdaExpressionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<LambdaExpressionNode>());
    creators[static_cast<int>(NodeType::captureSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CaptureSequenceNode>());
    creators[static_cast<int>(NodeType::assignCaptureNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<AssignCaptureNode>());
    creators[static_cast<int>(NodeType::refCaptureNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<RefCaptureNode>());
    creators[static_cast<int>(NodeType::thisCaptureNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ThisCaptureNode>());
    creators[static_cast<int>(NodeType::identifierCaptureNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<IdentifierCaptureNode>());
    creators[static_cast<int>(NodeType::parameterNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ParameterNode>());
    creators[static_cast<int>(NodeType::parameterSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ParameterSequenceNode>());
    creators[static_cast<int>(NodeType::functionNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<FunctionNode>());
    creators[static_cast<int>(NodeType::floatingLiteralNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<FloatingLiteralNode>());
    creators[static_cast<int>(NodeType::integerLiteralNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<IntegerLiteralNode>());
    creators[static_cast<int>(NodeType::characterLiteralNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CharacterLiteralNode>());
    creators[static_cast<int>(NodeType::stringLiteralNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<StringLiteralNode>());
    creators[static_cast<int>(NodeType::booleanLiteralNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<BooleanLiteralNode>());
    creators[static_cast<int>(NodeType::nullPtrLiteralNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<NullPtrLiteralNode>());
    creators[static_cast<int>(NodeType::namespaceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<NamespaceNode>());
    creators[static_cast<int>(NodeType::simpleTypeNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<SimpleTypeNode>());
    creators[static_cast<int>(NodeType::sourceFileNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<SourceFileNode>());
    creators[static_cast<int>(NodeType::sourceFileSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<SourceFileSequenceNode>());
    creators[static_cast<int>(NodeType::labeledStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<LabeledStatementNode>());
    creators[static_cast<int>(NodeType::caseStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CaseStatementNode>());
    creators[static_cast<int>(NodeType::defaultStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<DefaultStatementNode>());
    creators[static_cast<int>(NodeType::expressionStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ExpressionStatementNode>());
    creators[static_cast<int>(NodeType::compoundStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CompoundStatementNode>());
    creators[static_cast<int>(NodeType::statementSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<StatementSequenceNode>());
    creators[static_cast<int>(NodeType::ifStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<IfStatementNode>());
    creators[static_cast<int>(NodeType::switchStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<SwitchStatementNode>());
    creators[static_cast<int>(NodeType::whileStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<WhileStatementNode>());
    creators[static_cast<int>(NodeType::doStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<DoStatementNode>());
    creators[static_cast<int>(NodeType::rangeForStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<RangeForStatementNode>());
    creators[static_cast<int>(NodeType::forStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ForStatementNode>());
    creators[static_cast<int>(NodeType::breakStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<BreakStatementNode>());
    creators[static_cast<int>(NodeType::continueStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ContinueStatementNode>());
    creators[static_cast<int>(NodeType::returnStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ReturnStatementNode>());
    creators[static_cast<int>(NodeType::gotoStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<GotoStatementNode>());
    creators[static_cast<int>(NodeType::declarationStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<DeclarationStatementNode>());
    creators[static_cast<int>(NodeType::tryStatementNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TryStatementNode>());
    creators[static_cast<int>(NodeType::handlerNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<HandlerNode>());
    creators[static_cast<int>(NodeType::handlerSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<HandlerSequenceNode>());
    creators[static_cast<int>(NodeType::catchAllNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<CatchAllNode>());
    creators[static_cast<int>(NodeType::typeParameterNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TypeParameterNode>());
    creators[static_cast<int>(NodeType::templateParameterSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TemplateParameterSequenceNode>());
    creators[static_cast<int>(NodeType::templateDeclarationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TemplateDeclarationNode>());
    creators[static_cast<int>(NodeType::templateArgumentSequenceNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TemplateArgumentSequenceNode>());
    creators[static_cast<int>(NodeType::templateIdNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TemplateIdNode>());
    creators[static_cast<int>(NodeType::templateArgumentNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<TemplateArgumentNode>());
    creators[static_cast<int>(NodeType::explicitInstantiationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ExplicitInstantiationNode>());
    creators[static_cast<int>(NodeType::explicitSpecializationNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ExplicitSpecializationNode>());
    creators[static_cast<int>(NodeType::constNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<ConstNode>());
    creators[static_cast<int>(NodeType::volatileNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<VolatileNode>());
    creators[static_cast<int>(NodeType::pointerNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<PointerNode>());
    creators[static_cast<int>(NodeType::rValueRefNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<RValueRefNode>());
    creators[static_cast<int>(NodeType::lValueRefNode)] = std::unique_ptr<NodeCreator>(new ConcreteNodeCreator<LValueRefNode>());
}

Node* NodeFactory::CreateNode(NodeType nodeType)
{
    NodeCreator* creator = creators[static_cast<int>(nodeType)].get();
    return creator->Create();
}

void NodeInit()
{
    NodeFactory::Init();
}

void NodeDone()
{
    NodeFactory::Done();
}

} } // namespace sngcpp::ast


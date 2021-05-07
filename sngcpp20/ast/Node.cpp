// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Node.hpp>
#include <sngcpp20/ast/Attribute.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <sngcpp20/ast/Concept.hpp>
#include <sngcpp20/ast/Declaration.hpp>
#include <sngcpp20/ast/Enum.hpp>
#include <sngcpp20/ast/Expression.hpp>
#include <sngcpp20/ast/Function.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <sngcpp20/ast/Lambda.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <sngcpp20/ast/Module.hpp>
#include <sngcpp20/ast/Qualifier.hpp>
#include <sngcpp20/ast/SimpleType.hpp>
#include <sngcpp20/ast/Statement.hpp>
#include <sngcpp20/ast/Template.hpp>
#include <sngcpp20/ast/TranslationUnit.hpp>
#include <sngcpp20/ast/Type.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>
#include <stdexcept>

namespace sngcpp::ast {

std::string NodeTypeStr(NodeType nodeType)
{
    switch (nodeType)
    {
        case NodeType::compound: return "compound";
        case NodeType::unary: return "unary";
        case NodeType::binary: return "binary";
        case NodeType::sequence: return "sequence";
        case NodeType::list: return "list";
    }
    return "single";
}

const char* nodeKindStr[] =
{
    "nullNode", 
    "translationUnitNode", "moduleUnitNode",
    "moduleDeclarationNode", "exportDeclarationNode", "exportNode", "importNode", "importDeclarationNode", "modulePartitionNode", "moduleNode", "globalModuleFragmentNode", "privateModuleFragmentNode",
    "angleHeaderNameNode", "quoteHeaderNameNode",
    "identifierNode", "unnamedNode", "colonColonNode", "nestedNameSpecifierNode", "qualifiedIdNode", "identifierListNode", "qualifiedModuleIdNode",
    "charNode", "char8Node", "char16Node", "char32Node", "wcharNode", "boolNode", "shortNode", "intNode", "longNode", "signedNode", "unsignedNode", "floatNode", "doubleNode", "voidNode",
    "constNode", "volatileNode", "lvalueRefNode", "rvalueRefNode", "ptrNode", "cvQualifierSequenceNode", "ptrOperatorNode", "noexceptSpecifierNode", "packDeclaratorIdNode", "arrayDeclaratorNode", 
    "functionDeclaratorNode",
    "prefixNode", "trailingQualifiersNode", "trailingAttributesNode", "ptrDeclaratorNode",
    "expressionListNode", "assignmentInitializerNode",
    "conditionalExprNode", "questNode", "colonNode", "commaNode", "binaryExprNode", "unaryExprNode", "yieldExprNode", "throwExprNode",
    "assignNode", "plusAssignNode", "minusAssignNode", "mulAssignNode", "divAssignNode", "modAssignNode", "xorAssignNode", "andAssignNode", "orAssignNode", "shiftLeftAssignNode", "shiftRightAssignNode",
    "disjunctionNode", "conjunctionNode", "inclusiveOrNode", "exclusiveOrNode", "andNode", "equalNode", "notEqualNode", "lessNode", "greaterNode", "lessOrEqualNode", "greaterOrEqualNode",
    "compareNode", "shiftLeftNode", "shiftRightNode", "plusNode", "minusNode", "mulNode", "divNode", "modNode", "dotStarNode", "arrowStarNode",
    "castExprNode", "derefNode", "addrOfNode", "notNode", "complementNode", "prefixIncNode", "prefixDecNode",
    "awaitExprNode", "sizeOfTypeExprNode", "sizeOfPackExpNode", "sizeOfUnaryExprNode", "alignOfExprNode", "noexceptExprNode",
    "foldExprNode", "newDeclaratorNode", "arrayNewDeclaratorNode", "newInitializerNode", "ellipsesNode", "bracedInitListNode", "designatedInitializerNode", "designatorNode",
    "newExprNode", "newPlacementNode", "parenNewTypeIdNode", "newTypeIdNode", "arrayDeletePtrNode", "deletePtrNode",
    "subscriptExprNode", "invokeExprNode", "dotNode", "templateNode", "arrowNode", "pairNode", "memberExprNode", "postfixIncExprNode", "postfixDecExprNode", "typeIdExprNode",
    "dynamicCastNode", "staticCastNode", "reinterpretCastNode", "constCastNode", "cppCastExprNode", "thisNode", "parenExprNode",
    "lambdaExpressionNode", "lambdaIntroducerNode", "lambdaCaptureNode", "lambdaDeclaratorNode", "lambdaSpecifiersNode", "lambdaTemplateParamsNode",
    "defaultRefCaptureNode", "defaultCopyCaptureNode", "byRefCaptureNode", "simpleCaptureNode", "initCaptureNode", "currentObjectCopyCapture", "currentObjectByRefCapture",
    "integerLiteralNode", "floatingLiteralNode", "characterLiteralNode", "stringLiteralNode", "rawStringLiteralNode", "booleanLiteralNode", "nullPtrLiteralNode", "userDefinedLiteralNode", 
    "literalOperatorIdNode",
    "labeledStatementNode", "caseStatmentNode", "defaultStatementNode", "compoundStatementNode", "ifStatementNode", "switchStatemeNode", "whileStatementNode", "doStatementNode",
    "rangeForStatementNode", "forRangeDeclarationNode", "structuredBindingNode", "forStatementNode", "breakStatementNode", "continueStatementNode", "returnStatementNode", "coReturnStatementNode",
    "gotoStatementNode", "tryStatementNode", "handlerSequenceNode", "handlerNode", "exceptionDeclarationNode", "expressionStatementNode", "declarationStatementNode", "initConditionNode", "semicolonNode",
    "templateDeclarationNode", "templateHeadNode", "templateParameterListNode", "typeParameterNode", "templateIdNode", "typenameNode", "deductionGuideNode", "explicitInstantiationNode", 
    "explicitSpecializationNode",
    "declarationSequenceNode", "simpleDeclarationNode", "usingDeclarationNode", "usingNode", "usingDeclaratorListNode", "usingEnumDeclarationNode", "emptyDeclarationNode", "namespaceNode", 
    "usingDirectiveNode",
    "asmDeclarationNode", "asmNode", "namespaceAliasDefinitionNode", "staticAssertDeclarationNode", "staticAssertNode", "aliasDeclarationNode", "definingTypeIdNode", "definingTypeSpecifierSequenceNode",
    "opaqueEnumDeclarationNode", "functionDeclarationNode", "linkageSpecificationNode", "namespaceDefinitionNode", "namespaceBodyNode", "attributeDeclarationNode",
    "initDeclaratorListNode", "initDeclaratorNode", "trailingFunctionDeclaratorNode", "parenthesizedDeclaratorNode", "abstractDeclaratorNode", "declSpecifierSequenceNode",
    "friendNode", "typedefNode", "constExprNode", "constEvalNode", "constInitNode", "inlineNode", "staticNode", "threadLocalNode", "externNode", "mutableNode", "virtualNode", "explicitNode", 
    "conditionalExplicitNode",
    "qualifiedPtrNode",
    "typeSpecifierSequenceNode", "typenameSpecifierNode", "typeIdNode", "trailingReturnTypeNode", "elaboratedTypeSpecifierNode", "declTypeSpecifierNode", "placeholderTypeSpecifierNode",
    "classSpecifierNode", "classHeadNode", "baseClauseNode", "baseSpecifierListNode", "baseSpecifierNode", "beginAccessGroupNode", "memberDeclarationNode", "memberDeclaratorListNode", 
    "virtSpecifierSequenceNode",
    "constructorNode", "constructorInitializerNode", "memberInitializerListNode", "memberInitializerNode",
    "publicNode", "protectedNode", "privateNode", "classNode", "structNode", "unionNode", "overrideNode", "finalNode", "pureSpecifierNode",
    "enumSpecifierNode", "enumHeadNode", "enumBaseNode", "enumClassNode", "enumStructNode", "enumNode", "enumeratorDefinitionNode", "enumeratorNode", "elaboratedEnumSpecifierNode",
    "functionDefinitionNode", "functionBodyNode", "generatedFunctionBodyNode", "defaultNode", "deleteNode",
    "operatorFnIdNode", "operatorNode", "newArrayOpNode", "newOpNode", "deleteArrayOpNode", "deleteOpNode", "coAwaitOpNode", "invokeOpNode", "subscriptOpNode",
    "conversionFnIdNode", "conversionTypeIdNode", "conversionDeclaratorNode", "destructorIdNode", "parameterNode", "parameterListNode", "noexceptNode", "functionTryBlock",
    "conceptDefinitionNode", "requiresExprNode", "requirementBodyNode", "simpleRequirementNode", "typeRequirementNode", "compoundRequirementNode", "returnTypeRequirementNode", "nestedRequirementNode",
    "typeConstraintNode", "requiresClauseNode",
    "attributeSpecifierSequenceNode", "attributeSpecifierNode", "attributeUsingPrefixNode", "attrbuteNode", "attributeScopedTokenNode", "attributeArgumentsNode", "balancedTokenSequenceNode", 
    "tokenNode",
    "lparenNode", "rparenNode", "lbracketNode", "rbracketNode", "lbraceNode", "rbraceNode", "alignmentSpecifierNode"
};

std::string NodeKindStr(NodeKind nodeKind)
{
    return nodeKindStr[static_cast<int>(nodeKind)];
}

Node::Node(NodeKind kind_, const SourcePos& sourcePos_) : kind(kind_), sourcePos(sourcePos_), parent(nullptr)
{
}

Node::~Node()
{
}

void Node::AddNode(Node* node)
{
    throw std::runtime_error("cannot add node to this kind of node");
}

void Node::Clear()
{
    throw std::runtime_error("cannot clear this kind of node");
}

void Node::Write(Writer& writer)
{
}

void Node::Read(Reader& reader)
{
}

CompoundNode::CompoundNode(NodeKind kind_, const SourcePos& sourcePos_) : Node(kind_, sourcePos_)
{
}

UnaryNode::UnaryNode(NodeKind kind_, const SourcePos& sourcePos_, Node* child_) : Node(kind_, sourcePos_), child(child_)
{
    child->SetParent(this);
}

void UnaryNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(child.get());
}

void UnaryNode::Read(Reader& reader)
{
    Node::Read(reader);
    child.reset(reader.ReadNode());
}

BinaryNode::BinaryNode(NodeKind kind_, const SourcePos& sourcePos_, Node* left_, Node* right_) : Node(kind_, sourcePos_), left(left_), right(right_)
{
    left->SetParent(this);
    right->SetParent(this);
}

void BinaryNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(left.get());
    writer.Write(right.get());
}

void BinaryNode::Read(Reader& reader)
{
    Node::Read(reader);
    left.reset(reader.ReadNode());
    right.reset(reader.ReadNode());
}

SequenceNode::SequenceNode(NodeKind kind_, const SourcePos& sourcePos_) : Node(kind_, sourcePos_)
{
}

void SequenceNode::AddNode(Node* node)
{
    node->SetParent(this);
    nodes.Add(node);
}

void SequenceNode::Clear()
{
    nodes.Clear();
}

void SequenceNode::Write(Writer& writer)
{
    Node::Write(writer);
    uint32_t n = Nodes().Count();
    writer.GetBinaryWriter().WriteULEB128UInt(n);
    for (uint32_t i = 0; i < n; ++i)
    {
        Node* node = nodes[i];
        writer.Write(node);
    }
}

void SequenceNode::Read(Reader& reader)
{
    Node::Read(reader);
    uint32_t n = reader.GetBinaryReader().ReadULEB128UInt();
    for (uint32_t i = 0; i < n; ++i)
    {
        Node* node = reader.ReadNode();
        AddNode(node);
    }
}

ListNode::ListNode(NodeKind kind_, const SourcePos& sourcePos_) : Node(kind_, sourcePos_)
{
}

void ListNode::AddNode(Node* node)
{
    node->SetParent(this);
    nodes.Add(node);
    if (node->Kind() != NodeKind::commaNode)
    {
        items.push_back(node);
    }
}

void ListNode::Clear()
{
    nodes.Clear();
}

void ListNode::Write(Writer& writer)
{
    Node::Write(writer);
    uint32_t n = Nodes().Count();
    writer.GetBinaryWriter().WriteULEB128UInt(n);
    for (uint32_t i = 0; i < n; ++i)
    {
        Node* node = nodes[i];
        writer.Write(node);
    }
}

void ListNode::Read(Reader& reader)
{
    Node::Read(reader);
    uint32_t n = reader.GetBinaryReader().ReadULEB128UInt();
    for (uint32_t i = 0; i < n; ++i)
    {
        Node* node = reader.ReadNode();
        AddNode(node);
    }
}

struct AbstractNodeFactory
{
    virtual Node* CreateNode(const SourcePos& sourcePos) = 0;
};

template<typename T>
concept NodeClass = std::derived_from<T, Node>;

template<NodeClass C>
struct NodeFactory : AbstractNodeFactory
{
    Node* CreateNode(const SourcePos& sourcePos) override
    {
        return new C(sourcePos);
    }
};

class NodeFactoryCollection
{
public:
    static void Init();
    static void Done();
    static NodeFactoryCollection& Instance() { return *instance; }
    Node* CreateNode(NodeKind kind, const SourcePos& sourcePos);
    void Register(NodeKind kind, AbstractNodeFactory* factory);
private:
    NodeFactoryCollection();
    static std::unique_ptr<NodeFactoryCollection> instance;
    std::vector<std::unique_ptr<AbstractNodeFactory>> factories;
};

std::unique_ptr<NodeFactoryCollection> NodeFactoryCollection::instance;

void NodeFactoryCollection::Init()
{
    instance.reset(new NodeFactoryCollection());
}

void NodeFactoryCollection::Done()
{
    instance.reset();
}

NodeFactoryCollection::NodeFactoryCollection()
{
    factories.resize(static_cast<int>(NodeKind::max));
    // Attribute:
    Register(NodeKind::attributeSpecifierSequenceNode, new NodeFactory<AttributeSpecifierSequenceNode>());
    Register(NodeKind::attributeSpecifierNode, new NodeFactory<AttributeSpecifierNode>());
    Register(NodeKind::attributeUsingPrefixNode, new NodeFactory<AttributeUsingPrefixNode>());
    Register(NodeKind::attrbuteNode, new NodeFactory<AttributeNode>());
    Register(NodeKind::attributeScopedTokenNode, new NodeFactory<AttributeScopedTokenNode>());
    Register(NodeKind::attributeArgumentsNode, new NodeFactory<AttributeArgumentsNode>());
    Register(NodeKind::balancedTokenSequenceNode, new NodeFactory<BalancedTokenSequenceNode>());
    Register(NodeKind::tokenNode, new NodeFactory<TokenNode>());
    Register(NodeKind::alignmentSpecifierNode, new NodeFactory<AlignmentSpecifierNode>());
    Register(NodeKind::lparenNode, new NodeFactory<LParenNode>());
    Register(NodeKind::rparenNode, new NodeFactory<RParenNode>());
    Register(NodeKind::lbracketNode, new NodeFactory<LBracketNode>());
    Register(NodeKind::rbracketNode, new NodeFactory<RBracketNode>());
    Register(NodeKind::lbraceNode, new NodeFactory<LBraceNode>());
    Register(NodeKind::rbraceNode, new NodeFactory<RBraceNode>());
    // Class:
    Register(NodeKind::classSpecifierNode, new NodeFactory<ClassSpecifierNode>());
    Register(NodeKind::classHeadNode, new NodeFactory<ClassHeadNode>());
    Register(NodeKind::baseClauseNode, new NodeFactory<BaseClauseNode>());
    Register(NodeKind::baseSpecifierListNode, new NodeFactory<BaseSpecifierListNode>());
    Register(NodeKind::baseSpecifierNode, new NodeFactory<BaseSpecifierNode>());
    Register(NodeKind::beginAccessGroupNode, new NodeFactory<BeginAccessGroupNode>());
    Register(NodeKind::memberDeclarationNode, new NodeFactory<MemberDeclarationNode>());
    Register(NodeKind::memberDeclaratorListNode, new NodeFactory<MemberDeclaratorListNode>());
    Register(NodeKind::constructorNode, new NodeFactory<ConstructorNode>());
    Register(NodeKind::constructorInitializerNode, new NodeFactory<ConstructorInitializerNode>());
    Register(NodeKind::memberInitializerListNode, new NodeFactory<MemberInitializerListNode>());
    Register(NodeKind::memberInitializerNode, new NodeFactory<MemberInitializerNode>());
    Register(NodeKind::virtSpecifierSequenceNode, new NodeFactory<VirtSpecifierSequenceNode>());
    Register(NodeKind::classNode, new NodeFactory<ClassNode>());
    Register(NodeKind::structNode, new NodeFactory<StructNode>());
    Register(NodeKind::unionNode, new NodeFactory<UnionNode>());
    Register(NodeKind::publicNode, new NodeFactory<PublicNode>());
    Register(NodeKind::protectedNode, new NodeFactory<ProtectedNode>());
    Register(NodeKind::privateNode, new NodeFactory<PrivateNode>());
    Register(NodeKind::virtualNode, new NodeFactory<VirtualNode>());
    Register(NodeKind::overrideNode, new NodeFactory<OverrideNode>());
    Register(NodeKind::finalNode, new NodeFactory<FinalNode>());
    Register(NodeKind::pureSpecifierNode, new NodeFactory<PureSpecifierNode>());
    // Concept:
    Register(NodeKind::conceptDefinitionNode, new NodeFactory<ConceptDefinitioNode>());
    Register(NodeKind::requiresExprNode, new NodeFactory<RequiresExprNode>());
    Register(NodeKind::requirementBodyNode, new NodeFactory<RequirementBodyNode>());
    Register(NodeKind::simpleRequirementNode, new NodeFactory<SimpleRequirementNode>());
    Register(NodeKind::typeRequirementNode, new NodeFactory<TypeRequirementNode>());
    Register(NodeKind::compoundRequirementNode, new NodeFactory<CompoundRequirementNode>());
    Register(NodeKind::returnTypeRequirementNode, new NodeFactory<ReturnTypeRequirementNode>());
    Register(NodeKind::nestedRequirementNode, new NodeFactory<NestedRequirementNode>());
    Register(NodeKind::typeConstraintNode, new NodeFactory<TypeConstraintNode>());
    Register(NodeKind::requiresClauseNode, new NodeFactory<RequiresClauseNode>());
    // Declaration:
    Register(NodeKind::declarationSequenceNode, new NodeFactory<DeclarationSequenceNode>());
    Register(NodeKind::simpleDeclarationNode, new NodeFactory<SimpleDeclarationNode>());
    Register(NodeKind::asmDeclarationNode, new NodeFactory<AsmDeclarationNode>());
    Register(NodeKind::asmNode, new NodeFactory<AsmNode>());
    Register(NodeKind::linkageSpecificationNode, new NodeFactory<LinkageSpecificationNode>());
    Register(NodeKind::namespaceDefinitionNode, new NodeFactory<NamespaceDefinitionNode>());
    Register(NodeKind::namespaceBodyNode, new NodeFactory<NamespaceBodyNode>());
    Register(NodeKind::namespaceAliasDefinitionNode, new NodeFactory<NamespaceAliasDefinitionNode>());
    Register(NodeKind::usingDeclarationNode, new NodeFactory<UsingDeclarationNode>());
    Register(NodeKind::usingNode, new NodeFactory<UsingNode>());
    Register(NodeKind::usingDeclaratorListNode, new NodeFactory<UsingDeclaratorListNode>());
    Register(NodeKind::usingEnumDeclarationNode, new NodeFactory<UsingEnumDeclarationNode>());
    Register(NodeKind::usingDirectiveNode, new NodeFactory<UsingDirectiveNode>());
    Register(NodeKind::namespaceNode, new NodeFactory<NamespaceNode>());
    Register(NodeKind::staticAssertDeclarationNode, new NodeFactory<StaticAssertDeclarationNode>());
    Register(NodeKind::staticAssertNode, new NodeFactory<StaticAssertNode>());
    Register(NodeKind::aliasDeclarationNode, new NodeFactory<AliasDeclarationNode>());
    Register(NodeKind::emptyDeclarationNode, new NodeFactory<EmptyDeclarationNode>());
    Register(NodeKind::attributeDeclarationNode, new NodeFactory<AttributeDeclarationNode>());
    Register(NodeKind::initDeclaratorListNode, new NodeFactory<InitDeclaratorListNode>());
    Register(NodeKind::initDeclaratorNode, new NodeFactory<InitDeclaratorNode>());
    Register(NodeKind::trailingFunctionDeclaratorNode, new NodeFactory<TrailingFunctionDeclaratorNode>());
    Register(NodeKind::parenthesizedDeclaratorNode, new NodeFactory<ParenthesizedDeclaratorNode>());
    Register(NodeKind::abstractDeclaratorNode, new NodeFactory<AbstractDeclaratorNode>());
    Register(NodeKind::declSpecifierSequenceNode, new NodeFactory<DeclSpecifierSequenceNode>());
    Register(NodeKind::friendNode, new NodeFactory<FriendNode>());
    Register(NodeKind::typedefNode, new NodeFactory<TypedefNode>());
    Register(NodeKind::constExprNode, new NodeFactory<ConstExprNode>());
    Register(NodeKind::constEvalNode, new NodeFactory<ConstEvalNode>());
    Register(NodeKind::constInitNode, new NodeFactory<ConstInitNode>());
    Register(NodeKind::inlineNode, new NodeFactory<InlineNode>());
    Register(NodeKind::staticNode, new NodeFactory<StaticNode>());
    Register(NodeKind::threadLocalNode, new NodeFactory<ThreadLocalNode>());
    Register(NodeKind::externNode, new NodeFactory<ExternNode>());
    Register(NodeKind::mutableNode, new NodeFactory<MutableNode>());
    Register(NodeKind::explicitNode, new NodeFactory<ExplicitNode>());
    Register(NodeKind::conditionalExplicitNode, new NodeFactory<ConditionalExplicitNode>());
    Register(NodeKind::qualifiedPtrNode, new NodeFactory<QualifiedPtrNode>());
    Register(NodeKind::ptrOperatorNode, new NodeFactory<PtrOperatorNode>());
    Register(NodeKind::ptrDeclaratorNode, new NodeFactory<PtrDeclaratorNode>());
    Register(NodeKind::packDeclaratorIdNode, new NodeFactory<PackDeclaratorIdNode>());
    Register(NodeKind::arrayDeclaratorNode, new NodeFactory<ArrayDeclaratorNode>());
    Register(NodeKind::functionDeclaratorNode, new NodeFactory<FunctionDeclaratorNode>());
    Register(NodeKind::prefixNode, new NodeFactory<PrefixNode>());
    Register(NodeKind::trailingQualifiersNode, new NodeFactory<TrailingQualifiersNode>());
    Register(NodeKind::trailingAttributesNode, new NodeFactory<TrailingAttributesNode>());
    Register(NodeKind::noexceptSpecifierNode, new NodeFactory<NoexceptSpecifierNode>());
    //Enum:
    Register(NodeKind::enumSpecifierNode, new NodeFactory<EnumSpecifierNode>());
    Register(NodeKind::enumHeadNode, new NodeFactory<EnumHeadNode>());
    Register(NodeKind::enumBaseNode, new NodeFactory<EnumBaseNode>());
    Register(NodeKind::enumClassNode, new NodeFactory<EnumClassNode>());
    Register(NodeKind::enumStructNode, new NodeFactory<EnumStructNode>());
    Register(NodeKind::enumNode, new NodeFactory<EnumNode>());
    Register(NodeKind::enumeratorDefinitionNode, new NodeFactory<EnumeratorDefinitionNode>());
    Register(NodeKind::enumeratorNode, new NodeFactory<EnumeratorNode>());
    Register(NodeKind::elaboratedEnumSpecifierNode, new NodeFactory<ElaboratedEnumSpecifierNode>());
    Register(NodeKind::opaqueEnumDeclarationNode, new NodeFactory<OpaqueEnumDeclarationNode>());
    // Expression:
    Register(NodeKind::binaryExprNode, new NodeFactory<BinaryExprNode>());
    Register(NodeKind::unaryExprNode, new NodeFactory<UnaryExprNode>());
    Register(NodeKind::expressionListNode, new NodeFactory<ExpressionListNode>());
    Register(NodeKind::assignmentInitializerNode, new NodeFactory<AssignmentInitNode>());
    Register(NodeKind::yieldExprNode, new NodeFactory<YieldExprNode>());
    Register(NodeKind::throwExprNode, new NodeFactory<ThrowExprNode>());
    Register(NodeKind::conditionalExprNode, new NodeFactory<ConditionalExprNode>());
    Register(NodeKind::colonNode, new NodeFactory<ColonNode>());
    Register(NodeKind::commaNode, new NodeFactory<CommaNode>());
    Register(NodeKind::assignNode, new NodeFactory<AssignNode>());
    Register(NodeKind::plusAssignNode, new NodeFactory<PlusAssignNode>());
    Register(NodeKind::minusAssignNode, new NodeFactory<MinusAssignNode>());
    Register(NodeKind::mulAssignNode, new NodeFactory<MulAssignNode>());
    Register(NodeKind::divAssignNode, new NodeFactory<DivAssignNode>());
    Register(NodeKind::modAssignNode, new NodeFactory<ModAssignNode>());
    Register(NodeKind::xorAssignNode, new NodeFactory<XorAssignNode>());
    Register(NodeKind::andAssignNode, new NodeFactory<AndAssignNode>());
    Register(NodeKind::orAssignNode, new NodeFactory<OrAssignNode>());
    Register(NodeKind::shiftLeftAssignNode, new NodeFactory<ShiftLeftAssignNode>());
    Register(NodeKind::shiftRightAssignNode, new NodeFactory<ShiftRightAssignNode>());
    Register(NodeKind::questNode, new NodeFactory<QuestNode>());
    Register(NodeKind::disjunctionNode, new NodeFactory<DisjunctionNode>());
    Register(NodeKind::conjunctionNode, new NodeFactory<ConjunctionNode>());
    Register(NodeKind::inclusiveOrNode, new NodeFactory<InclusiveOrNode>());
    Register(NodeKind::exclusiveOrNode, new NodeFactory<ExclusiveOrNode>());
    Register(NodeKind::andNode, new NodeFactory<AndNode>());
    Register(NodeKind::equalNode, new NodeFactory<EqualNode>());
    Register(NodeKind::notEqualNode, new NodeFactory<NotEqualNode>());
    Register(NodeKind::lessNode, new NodeFactory<LessNode>());
    Register(NodeKind::greaterNode, new NodeFactory<GreaterNode>());
    Register(NodeKind::lessOrEqualNode, new NodeFactory<LessOrEqualNode>());
    Register(NodeKind::greaterOrEqualNode, new NodeFactory<GreaterOrEqualNode>());
    Register(NodeKind::compareNode, new NodeFactory<CompareNode>());
    Register(NodeKind::shiftLeftNode, new NodeFactory<ShiftLeftNode>());
    Register(NodeKind::shiftRightNode, new NodeFactory<ShiftRightNode>());
    Register(NodeKind::plusNode, new NodeFactory<PlusNode>());
    Register(NodeKind::minusNode, new NodeFactory<MinusNode>());
    Register(NodeKind::mulNode, new NodeFactory<MulNode>());
    Register(NodeKind::divNode, new NodeFactory<DivNode>());
    Register(NodeKind::modNode, new NodeFactory<ModNode>());
    Register(NodeKind::dotStarNode, new NodeFactory<DotStarNode>());
    Register(NodeKind::arrowStarNode, new NodeFactory<ArrowStarNode>());
    Register(NodeKind::castExprNode, new NodeFactory<CastExprNode>());
    Register(NodeKind::derefNode, new NodeFactory<DerefNode>());
    Register(NodeKind::addrOfNode, new NodeFactory<AddrOfNode>());
    Register(NodeKind::notNode, new NodeFactory<NotNode>());
    Register(NodeKind::complementNode, new NodeFactory<ComplementNode>());
    Register(NodeKind::prefixIncNode, new NodeFactory<PrefixIncNode>());
    Register(NodeKind::prefixDecNode, new NodeFactory<PrefixDecNode>());
    Register(NodeKind::awaitExprNode, new NodeFactory<AwaitExprNode>());
    Register(NodeKind::sizeOfTypeExprNode, new NodeFactory<SizeOfTypeExprNode>());
    Register(NodeKind::sizeOfPackExpNode, new NodeFactory<SizeOfPackExprNode>());
    Register(NodeKind::sizeOfUnaryExprNode, new NodeFactory<SizeOfUnaryExprNode>());
    Register(NodeKind::alignOfExprNode, new NodeFactory<AlignOfExprNode>());
    Register(NodeKind::noexceptExprNode, new NodeFactory<NoexceptExprNode>());
    Register(NodeKind::newExprNode, new NodeFactory<NewExprNode>());
    Register(NodeKind::newPlacementNode, new NodeFactory<NewPlacementNode>());
    Register(NodeKind::parenNewTypeIdNode, new NodeFactory<ParenNewTypeIdNode>());
    Register(NodeKind::newTypeIdNode, new NodeFactory<NewTypeIdNode>());
    Register(NodeKind::arrayDeletePtrNode, new NodeFactory<ArrayDeletePtrNode>());
    Register(NodeKind::deletePtrNode, new NodeFactory<DeletePtrNode>());
    Register(NodeKind::subscriptExprNode, new NodeFactory<SubscriptExprNode>());
    Register(NodeKind::invokeExprNode, new NodeFactory<InvokeExprNode>());
    Register(NodeKind::pairNode, new NodeFactory<PairNode>());
    Register(NodeKind::arrowNode, new NodeFactory<ArrowNode>());
    Register(NodeKind::memberExprNode, new NodeFactory<MemberExprNode>());
    Register(NodeKind::postfixIncExprNode, new NodeFactory<PostfixIncExprNode>());
    Register(NodeKind::postfixDecExprNode, new NodeFactory<PostfixDecExprNode>());
    Register(NodeKind::typeIdExprNode, new NodeFactory<TypeIdExprNode>());
    Register(NodeKind::dynamicCastNode, new NodeFactory<DynamicCastNode>());
    Register(NodeKind::staticCastNode, new NodeFactory<StaticCastNode>());
    Register(NodeKind::reinterpretCastNode, new NodeFactory<ReinterpretCastNode>());
    Register(NodeKind::constCastNode, new NodeFactory<ConstCastNode>());
    Register(NodeKind::cppCastExprNode, new NodeFactory<CppCastExprNode>());
    Register(NodeKind::thisNode, new NodeFactory<ThisNode>());
    Register(NodeKind::parenExprNode, new NodeFactory<ParenthesizedExprNode>());
    Register(NodeKind::foldExprNode, new NodeFactory<FoldExprNode>());
    Register(NodeKind::newDeclaratorNode, new NodeFactory<NewDeclaratorNode>());
    Register(NodeKind::arrayNewDeclaratorNode, new NodeFactory<ArrayNewDeclaratorNode>());
    Register(NodeKind::newInitializerNode, new NodeFactory<NewInitializerNode>());
    Register(NodeKind::bracedInitListNode, new NodeFactory<BracedInitListNode>());
    Register(NodeKind::designatedInitializerNode, new NodeFactory<DesignatedInitializerNode>());
    Register(NodeKind::designatorNode, new NodeFactory<DesignatorNode>());
    Register(NodeKind::ellipsesNode, new NodeFactory<EllipsesNode>());
    // Function:
    Register(NodeKind::functionDefinitionNode, new NodeFactory<FunctionDefinitionNode>());
    Register(NodeKind::functionBodyNode, new NodeFactory<FunctionBodyNode>());
    Register(NodeKind::defaultNode, new NodeFactory<DefaultNode>());
    Register(NodeKind::deleteNode, new NodeFactory<DeleteNode>());
    Register(NodeKind::generatedFunctionBodyNode, new NodeFactory<GeneratedFunctionBodyNode>());
    Register(NodeKind::functionDeclarationNode, new NodeFactory<FunctionDeclarationNode>());
    Register(NodeKind::operatorNode, new NodeFactory<OperatorNode>());
    Register(NodeKind::newArrayOpNode, new NodeFactory<NewArrayOpNode>());
    Register(NodeKind::newOpNode, new NodeFactory<NewOpNode>());
    Register(NodeKind::deleteArrayOpNode, new NodeFactory<DeleteArrayOpNode>());
    Register(NodeKind::deleteOpNode, new NodeFactory<DeleteOpNode>());
    Register(NodeKind::coAwaitOpNode, new NodeFactory<CoAwaitOpNode>());
    Register(NodeKind::invokeOpNode, new NodeFactory<InvokeOpNode>());
    Register(NodeKind::subscriptOpNode, new NodeFactory<SubscriptOpNode>());
    Register(NodeKind::operatorFnIdNode, new NodeFactory<OperatorFunctionIdNode>());
    Register(NodeKind::conversionFnIdNode, new NodeFactory<ConversionFunctionIdNode>());
    Register(NodeKind::conversionTypeIdNode, new NodeFactory<ConversionTypeIdNode>());
    Register(NodeKind::conversionDeclaratorNode, new NodeFactory<ConversionDeclaratorNode>());
    Register(NodeKind::destructorIdNode, new NodeFactory<DestructorIdNode>());
    Register(NodeKind::parameterNode, new NodeFactory<ParameterNode>());
    Register(NodeKind::parameterListNode, new NodeFactory<ParameterListNode>());
    Register(NodeKind::noexceptNode, new NodeFactory<NoexceptNode>());
    Register(NodeKind::functionTryBlock, new NodeFactory<FunctionTryBlockNode>());
    // Identifier:
    Register(NodeKind::identifierNode, new NodeFactory<IdentifierNode>());
    Register(NodeKind::colonColonNode, new NodeFactory<ColonColonNode>());
    Register(NodeKind::nestedNameSpecifierNode, new NodeFactory<NestedNameSpecifierNode>());
    Register(NodeKind::qualifiedIdNode, new NodeFactory<QualifiedIdNode>());
    Register(NodeKind::identifierListNode, new NodeFactory<IdentifierListNode>());
    Register(NodeKind::qualifiedModuleIdNode, new NodeFactory<QualifiedModuleIdNode>());
    Register(NodeKind::dotNode, new NodeFactory<DotNode>());
    // Lambda:
    Register(NodeKind::lambdaExpressionNode, new NodeFactory<LambdaExpressionNode>());
    Register(NodeKind::lambdaIntroducerNode, new NodeFactory<LambdaIntroducerNode>());
    Register(NodeKind::lambdaCaptureNode, new NodeFactory<LambdaCaptureNode>());
    Register(NodeKind::defaultRefCaptureNode, new NodeFactory<DefaultRefCaptureNode>());
    Register(NodeKind::simpleCaptureNode, new NodeFactory<SimpleCaptureNode>());
    Register(NodeKind::currentObjectCopyCapture, new NodeFactory<CurrentObjectCopyCapture>());
    Register(NodeKind::currentObjectByRefCapture, new NodeFactory<CurrentObjectByRefCapture>());
    Register(NodeKind::initCaptureNode, new NodeFactory<InitCaptureNode>());
    Register(NodeKind::lambdaDeclaratorNode, new NodeFactory<LambdaDeclaratorNode>());
    Register(NodeKind::lambdaSpecifiersNode, new NodeFactory<LambdaSpecifiersNode>());
    Register(NodeKind::lambdaTemplateParamsNode, new NodeFactory<LambdaTemplateParamsNode>());
    // Literal:
    Register(NodeKind::integerLiteralNode, new NodeFactory<IntegerLiteralNode>());
    Register(NodeKind::floatingLiteralNode, new NodeFactory<FloatingLiteralNode>());
    Register(NodeKind::characterLiteralNode, new NodeFactory<CharacterLiteralNode>());
    Register(NodeKind::stringLiteralNode, new NodeFactory<StringLiteralNode>());
    Register(NodeKind::booleanLiteralNode, new NodeFactory<BooleanLiteralNode>());
    Register(NodeKind::nullPtrLiteralNode, new NodeFactory<NullPtrLiteralNode>());
    Register(NodeKind::userDefinedLiteralNode, new NodeFactory< UserDefinedLiteraNode>());
    Register(NodeKind::literalOperatorIdNode, new NodeFactory<LiteralOperatorIdNode>());
    // Module:
    Register(NodeKind::moduleDeclarationNode, new NodeFactory<ModuleDeclarationNode>());
    Register(NodeKind::exportDeclarationNode, new NodeFactory<ExportDeclarationNode>());
    Register(NodeKind::exportNode, new NodeFactory<ExportNode>());
    Register(NodeKind::importNode, new NodeFactory<ImportNode>());
    Register(NodeKind::importDeclarationNode, new NodeFactory<ImportDeclarationNode>());
    Register(NodeKind::modulePartitionNode, new NodeFactory<ModulePartitionNode>());
    Register(NodeKind::globalModuleFragmentNode, new NodeFactory<GlobalModuleFragmentNode>());
    Register(NodeKind::privateModuleFragmentNode, new NodeFactory<PrivateModuleFragmentNode>());
    // Qualifier:
    Register(NodeKind::constNode, new NodeFactory<ConstNode>());
    Register(NodeKind::volatileNode, new NodeFactory<VolatileNode>());
    Register(NodeKind::lvalueRefNode, new NodeFactory<LvalueRefNode>());
    Register(NodeKind::rvalueRefNode, new NodeFactory<RvalueRefNode>());
    Register(NodeKind::ptrNode, new NodeFactory<PtrNode>());
    Register(NodeKind::cvQualifierSequenceNode, new NodeFactory<CVQualifierSequenceNode>());
    // SimpleType:
    Register(NodeKind::charNode, new NodeFactory<CharNode>());
    Register(NodeKind::char8Node, new NodeFactory<Char8Node>());
    Register(NodeKind::char16Node, new NodeFactory<Char16Node>());
    Register(NodeKind::char32Node, new NodeFactory<Char32Node>());
    Register(NodeKind::wcharNode, new NodeFactory<WCharNode>());
    Register(NodeKind::boolNode, new NodeFactory<BoolNode>());
    Register(NodeKind::shortNode, new NodeFactory<ShortNode>());
    Register(NodeKind::intNode, new NodeFactory<IntNode>());
    Register(NodeKind::longNode, new NodeFactory<LongNode>());
    Register(NodeKind::signedNode, new NodeFactory<SignedNode>());
    Register(NodeKind::unsignedNode, new NodeFactory<UnsignedNode>());
    Register(NodeKind::floatNode, new NodeFactory<FloatNode>());
    Register(NodeKind::doubleNode, new NodeFactory<DoubleNode>());
    Register(NodeKind::voidNode, new NodeFactory<VoidNode>());
    // Statement:
    Register(NodeKind::labeledStatementNode, new NodeFactory<LabeledStatementNode>());
    Register(NodeKind::caseStatmentNode, new NodeFactory<CaseStatementNode>());
    Register(NodeKind::defaultStatementNode, new NodeFactory<DefaultStatementNode>());
    Register(NodeKind::compoundStatementNode, new NodeFactory<CompoundStatementNode>());
    Register(NodeKind::ifStatementNode, new NodeFactory<IfStatementNode>());
    Register(NodeKind::switchStatemeNode, new NodeFactory<SwitchStatementNode>());
    Register(NodeKind::whileStatementNode, new NodeFactory<WhileStatementNode>());
    Register(NodeKind::doStatementNode, new NodeFactory<DoStatementNode>());
    Register(NodeKind::rangeForStatementNode, new NodeFactory<RangeForStatementNode>());
    Register(NodeKind::forRangeDeclarationNode, new NodeFactory<ForRangeDeclarationNode>());
    Register(NodeKind::structuredBindingNode, new NodeFactory<StructuredBindingNode>());
    Register(NodeKind::forStatementNode, new NodeFactory<ForStatementNode>());
    Register(NodeKind::breakStatementNode, new NodeFactory<BreakStatementNode>());
    Register(NodeKind::continueStatementNode, new NodeFactory<ContinueStatementNode>());
    Register(NodeKind::returnStatementNode, new NodeFactory<ReturnStatementNode>());
    Register(NodeKind::coReturnStatementNode, new NodeFactory<CoReturnStatementNode>());
    Register(NodeKind::gotoStatementNode, new NodeFactory<GotoStatementNode>());
    Register(NodeKind::tryStatementNode, new NodeFactory<TryStatementNode>());
    Register(NodeKind::handlerSequenceNode, new NodeFactory<HandlerSequenceNode>());
    Register(NodeKind::handlerNode, new NodeFactory<HandlerNode>());
    Register(NodeKind::exceptionDeclarationNode, new NodeFactory<ExceptionDeclarationNode>());
    Register(NodeKind::expressionStatementNode, new NodeFactory<ExpressionStatementNode>());
    Register(NodeKind::declarationStatementNode, new NodeFactory<DeclarationStatementNode>());
    Register(NodeKind::initConditionNode, new NodeFactory<InitConditionNode>());
    Register(NodeKind::semicolonNode, new NodeFactory<SemicolonNode>());
    // Template:
    Register(NodeKind::templateDeclarationNode, new NodeFactory<TemplateDeclarationNode>());
    Register(NodeKind::templateHeadNode, new NodeFactory<TemplateHeadNode>());
    Register(NodeKind::templateParameterListNode, new NodeFactory<TemplateParameterListNode>());
    Register(NodeKind::typeParameterNode, new NodeFactory<TypeParameterNode>());
    Register(NodeKind::templateIdNode, new NodeFactory<TemplateIdNode>());
    Register(NodeKind::typenameNode, new NodeFactory<TypenameNode>());
    Register(NodeKind::deductionGuideNode, new NodeFactory<DeductionGuideNode>());
    Register(NodeKind::explicitInstantiationNode, new NodeFactory<ExplicitInstantiationNode>());
    Register(NodeKind::templateNode, new NodeFactory<TemplateNode>());
    Register(NodeKind::explicitSpecializationNode, new NodeFactory<ExplicitSpecializationNode>());
    // TranslationUnit:
    Register(NodeKind::translationUnitNode, new NodeFactory<TranslationUnitNode>());
    Register(NodeKind::moduleUnitNode, new NodeFactory<ModuleUnitNode>());
    // Type:
    Register(NodeKind::typeSpecifierSequenceNode, new NodeFactory<TypeSpecifierSequenceNode>());
    Register(NodeKind::typenameSpecifierNode, new NodeFactory<TypenameSpecifierNode>());
    Register(NodeKind::typeIdNode, new NodeFactory<TypeIdNode>());
    Register(NodeKind::definingTypeIdNode, new NodeFactory<DefiningTypeIdNode>());
    Register(NodeKind::definingTypeSpecifierSequenceNode, new NodeFactory<DefiningTypeSpecifierSequenceNode>());
    Register(NodeKind::trailingReturnTypeNode, new NodeFactory<TrailingReturnTypeNode>());
    Register(NodeKind::elaboratedTypeSpecifierNode, new NodeFactory<ElaboratedTypeSpecifierNode>());
    Register(NodeKind::declTypeSpecifierNode, new NodeFactory<DeclTypeSpecifierNode>());
    Register(NodeKind::placeholderTypeSpecifierNode, new NodeFactory<PlaceholderTypeSpecifierNode>());
}

Node* NodeFactoryCollection::CreateNode(NodeKind nodeKind, const SourcePos& sourcePos)
{
    AbstractNodeFactory* factory = factories[static_cast<int>(nodeKind)].get();
    if (factory)
    {
        return factory->CreateNode(sourcePos);
    }
    else
    {
        throw std::runtime_error("factory for node kind '" + NodeKindStr(nodeKind) + "' not registered");
    }
}

void NodeFactoryCollection::Register(NodeKind kind, AbstractNodeFactory* factory)
{
    factories[static_cast<int>(kind)] = std::unique_ptr<AbstractNodeFactory>(factory);
}

Node* CreateNode(NodeKind nodeKind, const SourcePos& sourcePos)
{
    return NodeFactoryCollection::Instance().CreateNode(nodeKind, sourcePos);
}

void NodeInit()
{
    NodeFactoryCollection::Init();
}

void NodeDone()
{
    NodeFactoryCollection::Done();
}

} // namespace sngcpp::ast

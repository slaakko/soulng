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
};

std::string NodeKindStr(NodeKind nodeKind)
{
    return nodeKindStr[static_cast<int>(nodeKind)];
}

Node::Node(NodeKind kind_, const SourcePos& sourcePos_) : kind(kind_), sourcePos(sourcePos_)
{
}

Node::~Node()
{
}

void Node::Accept(Visitor& visitor)
{
    // todo
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
    Register(NodeKind::trailingInvokeDeclaratorNode, new NodeFactory<TrailingInvokeDeclaratorNode>());
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
    Register(NodeKind::subscriptDeclaratorNode, new NodeFactory<SubscriptDeclaratorNode>());
    Register(NodeKind::invokeDeclaratorNode, new NodeFactory<InvokeDeclaratorNode>());
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

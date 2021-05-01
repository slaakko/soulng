// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_DECLARATION_INCLUDED
#define SNGCPP_AST_DECLARATION_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API DeclarationSequenceNode : public SequenceNode
{
public:
    DeclarationSequenceNode(const SourcePos& sourcePos_);
};

class AST_API SimpleDeclarationNode : public CompoundNode
{
public:
    SimpleDeclarationNode(const SourcePos& sourcePos_);
    SimpleDeclarationNode(const SourcePos& sourcePos_, Node* declarationSpecifiers_, Node* initDeclaratorList_, Node* attributes_, Node* semicolon_);
    Node* DeclarationSpecifiers() const { return declarationSpecifiers.get(); }
    Node* InitDeclaratorList() const { return initDeclaratorList.get();  }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> declarationSpecifiers; 
    std::unique_ptr<Node> initDeclaratorList;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
};

class AST_API AsmDeclarationNode : public CompoundNode
{
public:
    AsmDeclarationNode(const SourcePos& sourcePos_);
    AsmDeclarationNode(const SourcePos& sourcePos_, Node* asm__, Node* asmText_, Node* semicolon_, Node* attributes_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    Node* Asm() const { return asm_.get(); }
    Node* AsmText() const { return asmText.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> asm_;
    std::unique_ptr<Node> asmText;
    std::unique_ptr<Node> semicolon;
    std::unique_ptr<Node> attributes;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API AsmNode : public Node
{
public:
    AsmNode(const SourcePos& sourcePos_);
};

class AST_API LinkageSpecificationNode : public CompoundNode
{
public:
    LinkageSpecificationNode(const SourcePos& sourcePos_);
    LinkageSpecificationNode(const SourcePos& sourcePos_, Node* extrn_, Node* linkage_, Node* declarations_, const SourcePos& lbPos_, const SourcePos& rbPos_);
private:
    std::unique_ptr<Node> extrn;
    std::unique_ptr<Node> linkage;
    std::unique_ptr<Node> declarations;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API NamespaceDefinitionNode : public CompoundNode
{
public:
    NamespaceDefinitionNode(const SourcePos& sourcePos_);
    NamespaceDefinitionNode(const SourcePos& sourcePos_, Node* nskw_, Node* nsName_, Node* nsBody_, Node* inln_, Node* attributes_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    Node* Namespace() const { return nskw.get(); }
    Node* NamespaceName() const { return nsName.get(); }
    Node* NamespaceBody() const { return nsBody.get(); }
    Node* Inline() const { return inln.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& LBracePos() const { return lbPos; }
    const SourcePos& RBracePos() const { return rbPos; }
private:
    std::unique_ptr<Node> nskw;
    std::unique_ptr<Node> nsName;
    std::unique_ptr<Node> nsBody;
    std::unique_ptr<Node> inln;
    std::unique_ptr<Node> attributes;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API NamespaceBodyNode : public CompoundNode
{
public:
    NamespaceBodyNode(const SourcePos& sourcePos_);
    NamespaceBodyNode(const SourcePos& sourcePos_, Node* declarations_);
private:
    std::unique_ptr<Node> declarations;
};

class AST_API NamespaceAliasDefinitionNode : public CompoundNode
{
public:
    NamespaceAliasDefinitionNode(const SourcePos& sourcePos_);
    NamespaceAliasDefinitionNode(const SourcePos& sourcePos_, Node* id_, Node* assign_, Node* qns_, Node* semicolon_);
    Node* Id() const { return id.get(); }
    Node* Assign() const { return assign.get(); }
    Node* QualifiedNamespaceSpecifier() const { return qns.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> id;
    std::unique_ptr<Node> assign;
    std::unique_ptr<Node> qns;
    std::unique_ptr<Node> semicolon;
};

class AST_API UsingDeclarationNode : public CompoundNode
{
public:
    UsingDeclarationNode(const SourcePos& sourcePos_);
    UsingDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* declarators_, Node* semicolon_);
    Node* Using() const { return usng.get(); }
    Node* Declarators() const { return declarators.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> usng;
    std::unique_ptr<Node> declarators;
    std::unique_ptr<Node> semicolon;
};

class AST_API UsingNode : public Node
{
public:
    UsingNode(const SourcePos& sourcePos_);
};

class AST_API UsingDeclaratorListNode : public ListNode
{
public:
    UsingDeclaratorListNode(const SourcePos& sourcePos_);
};

class AST_API UsingEnumDeclarationNode : public CompoundNode
{
public:
    UsingEnumDeclarationNode(const SourcePos& sourcePos_);
    UsingEnumDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* ees_, Node* semicolon_);
    Node* Using() const { return usng.get(); }
    Node* ElaboratedEnumSpecifier() const { return ees.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> usng;
    std::unique_ptr<Node> ees;
    std::unique_ptr<Node> semicolon;
};

class AST_API UsingDirectiveNode : public CompoundNode
{
public:
    UsingDirectiveNode(const SourcePos& sourcePos_);
    UsingDirectiveNode(const SourcePos& sourcePos_, Node* usng_, Node* nskw_, Node* id_, Node* semicolon_, Node* attributes_);
    Node* Using() const { return usng.get(); }
    Node* Namespace() const { return nskw.get(); }
    Node* Id() const { return id.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    Node* Attributes() const { return attributes.get(); }
private:
    std::unique_ptr<Node> usng;
    std::unique_ptr<Node> nskw;
    std::unique_ptr<Node> id;
    std::unique_ptr<Node> semicolon;
    std::unique_ptr<Node> attributes;
};

class AST_API NamespaceNode : public Node
{
public:
    NamespaceNode(const SourcePos& sourcePos_);
};

class AST_API StaticAssertDeclarationNode : public CompoundNode
{
public:
    StaticAssertDeclarationNode(const SourcePos& sourcePos_);
    StaticAssertDeclarationNode(const SourcePos& sourcePos_, Node* staticAssert_, Node* constantExpr_, Node* comma_, Node* stringLiteral_, Node* semicolon_, 
        const SourcePos& lpPos_, const SourcePos rpPos_);
    Node* StaticAssert() const { return staticAssert.get(); }
    Node* ConstantExpr() const { return constantExpr.get(); }
    Node* Comma() const { return comma.get(); }
    Node* StringLiteral() const { return stringLiteral.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> staticAssert;
    std::unique_ptr<Node> constantExpr;
    std::unique_ptr<Node> comma;
    std::unique_ptr<Node> stringLiteral;
    std::unique_ptr<Node> semicolon;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API StaticAssertNode : public Node
{
public:
    StaticAssertNode(const SourcePos& sourcePos_);
};

class AST_API AliasDeclarationNode : public CompoundNode
{
public:
    AliasDeclarationNode(const SourcePos& sourcePos_);
    AliasDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* identifier_, Node* assign_, Node* definingTypeId_, Node* attributes_, Node* semicolon_);
    Node* Using() const { return usng.get(); }
    Node* Identifier() const { return identifier.get(); }
    Node* Assign() const { return assign.get(); }
    Node* DefiningTypeId() const { return definingTypeId.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> usng;
    std::unique_ptr<Node> identifier;
    std::unique_ptr<Node> assign;
    std::unique_ptr<Node> definingTypeId;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
};

class AST_API EmptyDeclarationNode : public Node
{
public:
    EmptyDeclarationNode(const SourcePos& sourcePos_);
};

class AST_API AttributeDeclarationNode : public BinaryNode
{
public:
    AttributeDeclarationNode(const SourcePos& sourcePos_);
    AttributeDeclarationNode(const SourcePos& sourcePos_, Node* attributes_, Node* semicolon_);
};

class AST_API InitDeclaratorListNode : public ListNode
{
public:
    InitDeclaratorListNode(const SourcePos& sourcePos_);
};

class AST_API InitDeclaratorNode : public BinaryNode
{
public:
    InitDeclaratorNode(const SourcePos& sourcePos_);
    InitDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, Node* init_);
};

class AST_API TrailingInvokeDeclaratorNode : public CompoundNode
{
public:
    TrailingInvokeDeclaratorNode(const SourcePos& sourcePos_);
    TrailingInvokeDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, Node* params_, Node* trailingReturnType_);
    Node* Declarator() const { return declarator.get(); }
    Node* Parameters() const { return params.get(); }
    Node* TrailingReturnType() const { return trailingReturnType.get(); }
private:
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> params;
    std::unique_ptr<Node> trailingReturnType;
};

class AST_API ParenthesizedDeclaratorNode : public CompoundNode
{
public:
    ParenthesizedDeclaratorNode(const SourcePos& sourcePos_);
    ParenthesizedDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    Node* Declarator() const { return declarator.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> declarator;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API AbstractDeclaratorNode : public Node
{
public:
    AbstractDeclaratorNode(const SourcePos& sourcePos_);
};

class AST_API DeclSpecifierSequenceNode : public SequenceNode
{
public:
    DeclSpecifierSequenceNode(const SourcePos& sourcePos_);
};

class AST_API FriendNode : public Node
{
public:
    FriendNode(const SourcePos& sourcePos_);
};

class AST_API TypedefNode : public Node
{
public:
    TypedefNode(const SourcePos& sourcePos_);
};

class AST_API ConstExprNode : public Node
{
public:
    ConstExprNode(const SourcePos& sourcePos_);
};

class AST_API ConstEvalNode : public Node
{
public:
    ConstEvalNode(const SourcePos& sourcePos_);
};

class AST_API ConstInitNode : public Node
{
public:
    ConstInitNode(const SourcePos& sourcePos_);
};

class AST_API InlineNode : public Node
{
public:
    InlineNode(const SourcePos& sourcePos_);
};

class AST_API StaticNode : public Node
{
public:
    StaticNode(const SourcePos& sourcePos_);
};

class AST_API ThreadLocalNode : public Node
{
public:
    ThreadLocalNode(const SourcePos& sourcePos_);
};

class AST_API ExternNode : public Node
{
public:
    ExternNode(const SourcePos& sourcePos_);
};

class AST_API MutableNode : public Node
{
public:
    MutableNode(const SourcePos& sourcePos_);
};

class AST_API VirtualNode : public Node
{
public:
    VirtualNode(const SourcePos& sourcePos_);
};

class AST_API ExplicitNode : public Node
{
public:
    ExplicitNode(const SourcePos& sourcePos_);
};

class AST_API ConditionalExplicitNode : public UnaryNode
{
public:
    ConditionalExplicitNode(const SourcePos& sourcePos_);
    ConditionalExplicitNode(const SourcePos& sourcePos_, Node* cond_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    Node* Condition() const { return cond.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> cond;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API QualifiedPtrNode : public BinaryNode
{
public:
    QualifiedPtrNode(const SourcePos& sourcePos_);
    QualifiedPtrNode(const SourcePos& sourcePos_, Node* nns_, Node* ptr_);
};

class AST_API PtrOperatorNode : public UnaryNode
{
public:
    PtrOperatorNode(const SourcePos& sourcePos_);
    PtrOperatorNode(const SourcePos& sourcePos_, Node* child_);
};

class AST_API PtrDeclaratorNode : public SequenceNode
{
public:
    PtrDeclaratorNode(const SourcePos& sourcePos_);
};

class AST_API PackDeclaratorIdNode : public BinaryNode
{
public:
    PackDeclaratorIdNode(const SourcePos& sourcePos_);
    PackDeclaratorIdNode(const SourcePos& sourcePos_, Node* ellipses_, Node* idExpr_);
};

class AST_API SubscriptDeclaratorNode : public UnaryNode
{
public:
    SubscriptDeclaratorNode(const SourcePos& sourcePos_);
    SubscriptDeclaratorNode(const SourcePos& sourcePos_, Node* child_, Node* index_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    Node* Index() const { return index.get(); }
    const SourcePos& LBracketPos() const { return lbPos; }
    const SourcePos& RBracketPos() const { return rbPos; }
private:
    std::unique_ptr<Node> index;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API InvokeDeclaratorNode : public UnaryNode
{
public:
    InvokeDeclaratorNode(const SourcePos& sourcePos_);
    InvokeDeclaratorNode(const SourcePos& sourcePos_, Node* child_, Node* parameters_);
    Node* Params() const { return params.get();  }
private:
    std::unique_ptr<Node> params;
};

class AST_API PrefixNode : public BinaryNode
{
public:
    PrefixNode(const SourcePos& sourcePos_);
    PrefixNode(const SourcePos& sourcePos_, Node* prefix_, Node* subject_);
};

class AST_API TrailingQualifiersNode : public SequenceNode
{
public:
    TrailingQualifiersNode(const SourcePos& sourcePos_);
    TrailingQualifiersNode(const SourcePos& sourcePos_, Node* subject_);
    Node* Subject() const { return subject.get(); }
    Node* ReleaseSubject() { return subject.release(); }
private:
    std::unique_ptr<Node> subject;
};

class AST_API TrailingAttributesNode : public BinaryNode
{
public:
    TrailingAttributesNode(const SourcePos& sourcePos_);
    TrailingAttributesNode(const SourcePos& sourcePos_, Node* left_, Node* attributes_);
};

class AST_API NoexceptSpecifierNode : public UnaryNode
{
public:
    NoexceptSpecifierNode(const SourcePos& sourcePos_);
    NoexceptSpecifierNode(const SourcePos& sourcePos_, Node* constantExpr_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_DECLARATION_INCLUDED

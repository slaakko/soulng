// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_EXPRESSION_INCLUDED
#define SNGCPP_AST_EXPRESSION_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API BinaryExprNode : public BinaryNode
{
public:
    BinaryExprNode(const SourcePos& sourcePos_);
    BinaryExprNode(const SourcePos& sourcePos_, Node* op_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Op() const { return op.get(); }
private:
    std::unique_ptr<Node> op;
};

class AST_API UnaryExprNode : public UnaryNode
{
public:
    UnaryExprNode(const SourcePos& sourcePos_);
    UnaryExprNode(const SourcePos& sourcePos_, Node* op_, Node* child_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Op() const { return op.get(); }
private:
    std::unique_ptr<Node> op;
};

class AST_API ExpressionListNode : public ListNode
{
public:
    ExpressionListNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetLParenPos(const SourcePos& lpPos_) { lpPos = lpPos_; }
    void SetRParenPos(const SourcePos& rpPos_) { rpPos = rpPos_; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API AssignmentInitNode : public UnaryNode
{
public:
    AssignmentInitNode(const SourcePos& sourcePos_);
    AssignmentInitNode(const SourcePos& sourcePos_, Node* initializer_);
    void Accept(Visitor& visitor) override;
};

class AST_API YieldExprNode : public UnaryNode
{
public:
    YieldExprNode(const SourcePos& sourcePos_);
    YieldExprNode(const SourcePos& sourcePos_, Node* child_);
    void Accept(Visitor& visitor) override;
};

class AST_API ThrowExprNode : public CompoundNode
{
public:
    ThrowExprNode(const SourcePos& sourcePos_);
    ThrowExprNode(const SourcePos& sourcePos_, Node* exception_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Exception() const { return exception.get(); }
private:
    std::unique_ptr<Node> exception;
};

class AST_API ConditionalExprNode : public CompoundNode
{
public:
    ConditionalExprNode(const SourcePos& sourcePos_);
    ConditionalExprNode(const SourcePos& sourcePos_, Node* condition_, Node* quest_, Node* thenExpr_, Node* colon_, Node* elseExpr_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Condition() const { return condition.get(); }
    Node* Quest() const { return quest.get(); }
    Node* ThenExpr() const { return thenExpr.get(); }
    Node* Colon() const { return colon.get(); }
    Node* ElseExpr() const { return elseExpr.get(); }
private:
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> quest;
    std::unique_ptr<Node> thenExpr;
    std::unique_ptr<Node> colon;
    std::unique_ptr<Node> elseExpr;
};

class AST_API CommaNode : public Node
{
public:
    CommaNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API AssignNode : public Node
{
public:
    AssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API PlusAssignNode : public Node
{
public:
    PlusAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API MinusAssignNode : public Node
{
public:
    MinusAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API MulAssignNode : public Node
{
public:
    MulAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DivAssignNode : public Node
{
public:
    DivAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ModAssignNode : public Node
{
public:
    ModAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API XorAssignNode : public Node
{
public:
    XorAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API AndAssignNode : public Node
{
public:
    AndAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API OrAssignNode : public Node
{
public:
    OrAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ShiftLeftAssignNode : public Node
{
public:
    ShiftLeftAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ShiftRightAssignNode : public Node
{
public:
    ShiftRightAssignNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API QuestNode : public Node
{
public:
    QuestNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ColonNode : public Node
{
public:
    ColonNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DisjunctionNode : public Node
{
public:
    DisjunctionNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ConjunctionNode : public Node
{
public:
    ConjunctionNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API InclusiveOrNode : public Node
{
public:
    InclusiveOrNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ExclusiveOrNode : public Node
{
public:
    ExclusiveOrNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API AndNode : public Node
{
public:
    AndNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API EqualNode : public Node
{
public:
    EqualNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API NotEqualNode : public Node
{
public:
    NotEqualNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API LessNode : public Node
{
public:
    LessNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API GreaterNode : public Node
{
public:
    GreaterNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API LessOrEqualNode : public Node
{
public:
    LessOrEqualNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API GreaterOrEqualNode : public Node
{
public:
    GreaterOrEqualNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API CompareNode : public Node
{
public:
    CompareNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ShiftLeftNode : public Node
{
public:
    ShiftLeftNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ShiftRightNode : public Node
{
public:
    ShiftRightNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API PlusNode : public Node
{
public:
    PlusNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API MinusNode : public Node
{
public:
    MinusNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API MulNode : public Node
{
public:
    MulNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DivNode : public Node
{
public:
    DivNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ModNode : public Node
{
public:
    ModNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DotStarNode : public Node
{
public:
    DotStarNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ArrowStarNode : public Node
{
public:
    ArrowStarNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API CastExprNode : public UnaryNode
{
public:
    CastExprNode(const SourcePos& sourcePos_);
    CastExprNode(const SourcePos& sourcePos_, Node* typeId_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    Node* TypeId() const { return typeId.get(); }
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> typeId;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API DerefNode : public Node
{
public:
    DerefNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API AddrOfNode : public Node
{
public:
    AddrOfNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API NotNode : public Node
{
public:
    NotNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ComplementNode : public Node
{
public:
    ComplementNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API PrefixIncNode : public Node
{
public:
    PrefixIncNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API PrefixDecNode : public Node
{
public:
    PrefixDecNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API AwaitExprNode : public UnaryNode
{
public:
    AwaitExprNode(const SourcePos& sourcePos_);
    AwaitExprNode(const SourcePos& sourcePos_, Node* child_);
    void Accept(Visitor& visitor) override;
};

class AST_API SizeOfTypeExprNode : public UnaryNode
{
public:
    SizeOfTypeExprNode(const SourcePos& sourcePos_);
    SizeOfTypeExprNode(const SourcePos& sourcePos_, Node* typeId_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API SizeOfPackExprNode : public UnaryNode
{
public:
    SizeOfPackExprNode(const SourcePos& sourcePos_);
    SizeOfPackExprNode(const SourcePos& sourcePos_, Node* idNode_, const SourcePos& ellipsisPos_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& EllipsisPos() const { return ellipsisPos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos ellipsisPos;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API SizeOfUnaryExprNode : public UnaryNode
{
public:
    SizeOfUnaryExprNode(const SourcePos& sourcePos_);
    SizeOfUnaryExprNode(const SourcePos& sourcePos_, Node* child_);
    void Accept(Visitor& visitor) override;
};

class AST_API AlignOfExprNode : public UnaryNode
{
public:
    AlignOfExprNode(const SourcePos& sourcePos_);
    AlignOfExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API NoexceptExprNode : public UnaryNode
{
public:
    NoexceptExprNode(const SourcePos& sourcePos_);
    NoexceptExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API NewExprNode : public UnaryNode
{
public:
    NewExprNode(const SourcePos& sourcePos_);
    NewExprNode(const SourcePos& sourcePos_, Node* placement_, Node* child_, Node* initializer_, Node* colonColonHead_, const SourcePos& newPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ColonColonHead() const { return colonColonHead.get(); }
    Node* Placement() const { return placement.get(); }
    Node* Initializer() const { return initializer.get(); }
    const SourcePos& NewPos() const { return newPos; }
private:
    std::unique_ptr<Node> colonColonHead;
    std::unique_ptr<Node> placement;
    std::unique_ptr<Node> initializer;
    SourcePos newPos;
};

class AST_API NewPlacementNode : public ListNode
{
public:
    NewPlacementNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetLParenPos(const SourcePos& lpPos_) { lpPos = lpPos_;  }
    void SetRParenPos(const SourcePos& rpPos_) { rpPos = rpPos_; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API ParenNewTypeIdNode : public UnaryNode
{
public:
    ParenNewTypeIdNode(const SourcePos& sourcePos_);
    ParenNewTypeIdNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API NewTypeIdNode : public CompoundNode
{
public:
    NewTypeIdNode(const SourcePos& sourcePos_);
    NewTypeIdNode(const SourcePos& sourcePos_, Node* typeSpecifierSeq_, Node* newDeclarator_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeSpecifierSeq() const { return typeSpecifierSeq.get(); }
    Node* NewDeclarator() const { return newDeclarator.get(); }
private:
    std::unique_ptr<Node> typeSpecifierSeq;
    std::unique_ptr<Node> newDeclarator;
};

class AST_API ArrayDeletePtrNode : public UnaryNode
{
public:
    ArrayDeletePtrNode(const SourcePos& sourcePos_);
    ArrayDeletePtrNode(const SourcePos& sourcePos_, Node* ptr_, Node* colonColonHead_, const SourcePos& deletePos_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ColonColonHead() const { return colonColonHead.get(); }
    const SourcePos& DeletePos() const { return deletePos; }
    const SourcePos& LBracketPos() const { return lbPos;  }
    const SourcePos& RBracketPos() const { return rbPos; }
private:
    std::unique_ptr<Node> colonColonHead;
    SourcePos deletePos;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API DeletePtrNode : public UnaryNode
{
public:
    DeletePtrNode(const SourcePos& sourcePos_);
    DeletePtrNode(const SourcePos& sourcePos_, Node* ptr_, Node* colonColonHead_, const SourcePos& deletePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ColonColonHead() const { return colonColonHead.get(); }
    const SourcePos& DeletePos() const { return deletePos; }
private:
    std::unique_ptr<Node> colonColonHead;
    SourcePos deletePos;
};

class AST_API SubscriptExprNode : public UnaryNode
{
public:
    SubscriptExprNode(const SourcePos& sourcePos_);
    SubscriptExprNode(const SourcePos& sourcePos_, Node* child_, Node* index_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Index() const { return index.get(); }
    const SourcePos& LBracketPos() const { return lbPos; }
    const SourcePos& RBracketPos() const { return rbPos; }
private:
    std::unique_ptr<Node> index;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API InvokeExprNode : public ListNode
{
public:
    InvokeExprNode(const SourcePos& sourcePos_);
    InvokeExprNode(const SourcePos& sourcePos_, Node* subject_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Subject() const { return subject.get(); }
    void SetLParenPos(const SourcePos& lpPos_) { lpPos = lpPos_; }
    void SetRParenPos(const SourcePos& rpPos_) { rpPos = rpPos_; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> subject;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API PairNode : public BinaryNode
{
public:
    PairNode(const SourcePos& sourcePos_);
    PairNode(const SourcePos& sourcePos_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class AST_API ArrowNode : public Node
{
public:
    ArrowNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API MemberExprNode : public UnaryNode
{
public:
    MemberExprNode(const SourcePos& sourcePos_);
    MemberExprNode(const SourcePos& sourcePos_, Node* child_, Node* op_, Node* id_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Op() const { return op.get(); }
    Node* Id() const { return id.get(); }
private:
    std::unique_ptr<Node> op;
    std::unique_ptr<Node> id;
};

class AST_API PostfixIncExprNode : public UnaryNode
{
public:
    PostfixIncExprNode(const SourcePos& sourcePos_);
    PostfixIncExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& opPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& OpPos() const { return opPos; }
private:
    SourcePos opPos;
};

class AST_API PostfixDecExprNode : public UnaryNode
{
public:
    PostfixDecExprNode(const SourcePos& sourcePos_);
    PostfixDecExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& opPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& OpPos() const { return opPos; }
private:
    SourcePos opPos;
};

class AST_API TypeIdExprNode : public UnaryNode
{
public:
    TypeIdExprNode(const SourcePos& sourcePos_);
    TypeIdExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API DynamicCastNode : public Node
{
public:
    DynamicCastNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API StaticCastNode : public Node
{
public:
    StaticCastNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ReinterpretCastNode : public Node
{
public:
    ReinterpretCastNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ConstCastNode : public Node
{
public:
    ConstCastNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API CppCastExprNode : public UnaryNode
{
public:
    CppCastExprNode(const SourcePos& sourcePos_);
    CppCastExprNode(const SourcePos& sourcePos_, Node* typeId_, Node* child_, Node* op_, const SourcePos& laPos_, const SourcePos& raPos_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeId() const { return typeId.get(); }
    Node* Op() const { return op.get(); }
    const SourcePos& LAnglePos() const { return laPos; }
    const SourcePos& RAnglePos() const { return raPos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> typeId;
    std::unique_ptr<Node> op;
    SourcePos laPos;
    SourcePos raPos;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API ThisNode : public Node
{
public:
    ThisNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ParenthesizedExprNode : public UnaryNode
{
public:
    ParenthesizedExprNode(const SourcePos& sourcePos_);
    ParenthesizedExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API FoldExprNode : public SequenceNode
{
public:
    FoldExprNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetLParenPos(const SourcePos& lpPos_) { lpPos = lpPos_; }
    void SetRParenPos(const SourcePos& rpPos_) { rpPos = rpPos_; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API NewDeclaratorNode : public SequenceNode
{
public:
    NewDeclaratorNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ArrayNewDeclaratorNode : public SequenceNode
{
public:
    ArrayNewDeclaratorNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API NewInitializerNode : public ListNode
{
public:
    NewInitializerNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetLParenPos(const SourcePos& lpPos_) { lpPos = lpPos_; }
    void SetRParenPos(const SourcePos& rpPos_) { rpPos = rpPos_; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API BracedInitListNode : public ListNode
{
public:
    BracedInitListNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DesignatedInitializerNode : public BinaryNode
{
public:
    DesignatedInitializerNode(const SourcePos& sourcePos_);
    DesignatedInitializerNode(const SourcePos& sourcePos_, Node* designator_, Node* initializer_);
    void Accept(Visitor& visitor) override;
};

class AST_API DesignatorNode : public UnaryNode
{
public:
    DesignatorNode(const SourcePos& sourcePos_);
    DesignatorNode(const SourcePos& sourcePos_, Node* identifier_);
    void Accept(Visitor& visitor) override;
};

class AST_API EllipsisNode : public Node
{
public:
    EllipsisNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

} // sngcpp::ast

#endif // SNGCPP_AST_EXPRESSION_INCLUDED

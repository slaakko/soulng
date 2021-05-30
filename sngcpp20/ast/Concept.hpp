// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_CONCEPT_INCLUDED
#define SNGCPP_AST_CONCEPT_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API ConceptDefinitionNode : public CompoundNode
{
public:
    ConceptDefinitionNode(const SourcePos& sourcePos_);
    ConceptDefinitionNode(const SourcePos& sourcePos_, Node* conceptName_, Node* assign_, Node* constraintExpr_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ConceptName() const { return conceptName.get(); }
    Node* Assign() const { return assign.get(); }
    Node* ConstraintExpression() const { return constraintExpr.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> conceptName;
    std::unique_ptr<Node> assign;
    std::unique_ptr<Node> constraintExpr;
    std::unique_ptr<Node> semicolon;
};

class AST_API RequiresExprNode : public CompoundNode
{
public:
    RequiresExprNode(const SourcePos& sourcePos_);
    RequiresExprNode(const SourcePos& sourcePos_, Node* params_, Node* body_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Params() const { return params.get(); }
    Node* Body() const { return body.get(); }
private:
    std::unique_ptr<Node> params;
    std::unique_ptr<Node> body;
};

class AST_API RequirementBodyNode : public SequenceNode
{
public:
    RequirementBodyNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetLBracePos(const SourcePos& lbPos_);
    void SetRBracePos(const SourcePos& rbPos_);
    const SourcePos& LBracePos() const { return lbPos; }
    const SourcePos& RBracePos() const { return rbPos; }
private:
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API SimpleRequirementNode : public BinaryNode
{
public:
    SimpleRequirementNode(const SourcePos& sourcePos_);
    SimpleRequirementNode(const SourcePos& sourcePos_, Node* expr_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
};

class AST_API TypeRequirementNode : public CompoundNode
{
public:
    TypeRequirementNode(const SourcePos& sourcePos_);
    TypeRequirementNode(const SourcePos& sourcePos_, Node* nns_, Node* typeName_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* NestedNameSpecifier() const { return nns.get(); }
    Node* TypeName() const { return typeName.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> nns;
    std::unique_ptr<Node> typeName;
    std::unique_ptr<Node> semicolon;
};

class AST_API CompoundRequirementNode : public CompoundNode
{
public:
    CompoundRequirementNode(const SourcePos& sourcePos_);
    CompoundRequirementNode(const SourcePos& sourcePos_, Node* expr_, Node* noexcept_, Node* returnTypeRequirement_, Node* semicolon_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Expr() const { return expr.get(); }
    Node* NoExcept() const { return noexceptNode.get(); }
    Node* ReturnTypeRequirement() const { return returnTypeRequirement.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& LBracePos() const { return lbPos; }
    const SourcePos& RBracePos() const { return rbPos; }
private:
    std::unique_ptr<Node> expr;
    std::unique_ptr<Node> noexceptNode;
    std::unique_ptr<Node> returnTypeRequirement;
    std::unique_ptr<Node> semicolon;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API ReturnTypeRequirementNode : public UnaryNode
{
public:
    ReturnTypeRequirementNode(const SourcePos& sourcePos_);
    ReturnTypeRequirementNode(const SourcePos& sourcePos_, Node* typeConstraint_);
    void Accept(Visitor& visitor) override;
};

class AST_API NestedRequirementNode : public BinaryNode
{
public:
    NestedRequirementNode(const SourcePos& sourcePos_);
    NestedRequirementNode(const SourcePos& sourcePos_, Node* constraintExpression_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
};

class AST_API TypeConstraintNode : public ListNode
{
public:
    TypeConstraintNode(const SourcePos& sourcePos_);
    TypeConstraintNode(const SourcePos& sourcePos_, Node* conceptName_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetHasTemplateArgumentList() { hasTemplateArgumentList = true; }
    bool HasTemplateArgumentList() const { return hasTemplateArgumentList; }
    Node* ConceptName() const { return conceptName.get(); }
    void SetLAnglePos(const SourcePos& laPos_);
    void SetRAnglePos(const SourcePos& raPos_);
    const SourcePos& LAnglePos() const { return laPos; }
    const SourcePos& RAnglePos() const { return laPos; }
private:
    std::unique_ptr<Node> conceptName;
    bool hasTemplateArgumentList;
    SourcePos laPos;
    SourcePos raPos;
};

class AST_API RequiresClauseNode : public UnaryNode
{
public:
    RequiresClauseNode(const SourcePos& sourcePos_);
    RequiresClauseNode(const SourcePos& sourcePos_, Node* constraintLogicalOrExpr_);
    void Accept(Visitor& visitor) override;
};

} // sngcpp::ast

#endif // SNGCPP_AST_CONCEPT_INCLUDED

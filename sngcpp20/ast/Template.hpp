// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_TEMPLATE_INCLUDED
#define SNGCPP_AST_TEMPLATE_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API TemplateDeclarationNode : public BinaryNode
{
public:
    TemplateDeclarationNode(const SourcePos& sourcePos_);
    TemplateDeclarationNode(const SourcePos& sourcePos_, Node* templateHead_, Node* declaration_);
    void Accept(Visitor& visitor) override;
};

class AST_API TemplateHeadNode : public CompoundNode
{
public:
    TemplateHeadNode(const SourcePos& sourcePos_);
    TemplateHeadNode(const SourcePos& sourcePos_, Node* templateParamList_, Node* requiresClause_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TemplateParamList() const { return templateParamList.get(); }
    Node* RequiresClause() const { return requiresClause.get(); }
private:
    std::unique_ptr<Node> templateParamList;
    std::unique_ptr<Node> requiresClause;
};

class AST_API TemplateParameterListNode : public ListNode
{
public:
    TemplateParameterListNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetLAnglePos(const SourcePos& laPos_) { laPos = laPos_; }
    void SetRAnglePos(const SourcePos& raPos_) { raPos = raPos_; }
    const SourcePos& LAnglePos() const { return laPos; }
    const SourcePos& RAnglePos() const { return raPos; }
private:
    SourcePos laPos;
    SourcePos raPos;
};

class AST_API TypeParameterNode : public CompoundNode
{
public:
    TypeParameterNode(const SourcePos& sourcePos_);
    TypeParameterNode(const SourcePos& sourcePos_, Node* typeConstraint_, Node* identifier_, Node* assign_, Node* typeId_, Node* ellipses_, Node* templateHead_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeConstraint() const { return typeConstraint.get(); }
    Node* Identifier() const { return identifier.get(); }
    Node* Assign() const { return assign.get(); }
    Node* TypeId() const { return typeId.get(); }
    Node* Ellipses() const { return ellipses.get(); }
    Node* TemplateHead() const { return templateHead.get(); }
private:
    std::unique_ptr<Node> typeConstraint;
    std::unique_ptr<Node> identifier;
    std::unique_ptr<Node> assign;
    std::unique_ptr<Node> typeId;
    std::unique_ptr<Node> ellipses;
    std::unique_ptr<Node> templateHead;
};

class AST_API TemplateIdNode : public ListNode
{
public:
    TemplateIdNode(const SourcePos& sourcePos_);
    TemplateIdNode(const SourcePos& sourcePos_, Node* templateName_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TemplateName() const { return templateName.get(); }
    void SetLAnglePos(const SourcePos& laPos_) { laPos = laPos_; }
    void SetRAnglePos(const SourcePos& raPos_) { raPos = raPos_; }
    const SourcePos& LAnglePos() const { return laPos; }
    const SourcePos& RAnglePos() const { return raPos; }
private:
    std::unique_ptr<Node> templateName;
    SourcePos laPos;
    SourcePos raPos;
};

class AST_API TypenameNode : public Node
{
public:
    TypenameNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DeductionGuideNode : public CompoundNode
{
public:
    DeductionGuideNode(const SourcePos& sourcePos_);
    DeductionGuideNode(const SourcePos& sourcePos_, Node* templateName_, Node* params_, Node* arrow_, Node* templateId_, Node* explicitSpecifier_, Node* semicolon_, 
        const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TemplateName() const { return templateName.get(); }
    Node* Parameters() const { return params.get(); }
    Node* Arrow() const { return arrow.get(); }
    Node* TemplateId() const { return templateId.get(); }
    Node* ExplicitSpecifier() const { return explicitSpecifier.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> templateName;
    std::unique_ptr<Node> params;
    std::unique_ptr<Node> arrow;
    std::unique_ptr<Node> templateId;
    std::unique_ptr<Node> explicitSpecifier;
    std::unique_ptr<Node> semicolon;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API ExplicitInstantiationNode : public CompoundNode
{
public:
    ExplicitInstantiationNode(const SourcePos& sourcePos_);
    ExplicitInstantiationNode(const SourcePos& sourcePos_, Node* extrn_, Node* tmp_, Node* declaration_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Extern() const { return extrn.get(); }
    Node* Template() const { return tmp.get(); }
    Node* Declaration() const { return declaration.get(); }
private:
    std::unique_ptr<Node> extrn;
    std::unique_ptr<Node> tmp;
    std::unique_ptr<Node> declaration;
};

class AST_API TemplateNode : public Node
{
public:
    TemplateNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ExplicitSpecializationNode : public CompoundNode
{
public:
    ExplicitSpecializationNode(const SourcePos& sourcePos_);
    ExplicitSpecializationNode(const SourcePos& sourcePos_, Node* tmp_, Node* declaration_, const SourcePos& laPos_, const SourcePos& raPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Template() const { return tmp.get(); }
    Node* Declaration() const { return declaration.get(); }
    const SourcePos& LAnglePos() const { return laPos; }
    const SourcePos& RAnglePos() const { return raPos; }
private:
    std::unique_ptr<Node> tmp;
    std::unique_ptr<Node> declaration;
    SourcePos laPos;
    SourcePos raPos;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_TEMPLATE_INCLUDED

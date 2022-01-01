// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_LAMBDA_INCLUDED
#define SNGCPP_AST_LAMBDA_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API LambdaExpressionNode : public CompoundNode
{
public:
    LambdaExpressionNode(const SourcePos& sourcePos_);
    LambdaExpressionNode(const SourcePos& sourcePos_, Node* introducer_, Node* templateParams_, Node* declarator_, Node* body_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Introducer() const { return introducer.get(); }
    Node* TemplateParams() const { return templateParams.get(); }
    Node* Declarator() const { return declarator.get(); }
    Node* Body() const { return body.get(); }
private:
    std::unique_ptr<Node> introducer;
    std::unique_ptr<Node> templateParams;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> body;
};

class AST_API LambdaIntroducerNode : public CompoundNode
{
public:
    LambdaIntroducerNode(const SourcePos& sourcePos_);
    LambdaIntroducerNode(const SourcePos& sourcePos_, Node* capture_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Capture() const { return capture.get(); }
    const SourcePos& LBracketPos() const { return lbPos; }
    const SourcePos& RBracketPos() const { return rbPos; }
private:
    std::unique_ptr<Node> capture;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API LambdaCaptureNode : public ListNode
{
public:
    LambdaCaptureNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DefaultRefCaptureNode : public Node
{
public:
    DefaultRefCaptureNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API DefaultCopyCaptureNode : public Node
{
public:
    DefaultCopyCaptureNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ByRefCaptureNode : public Node
{
public:
    ByRefCaptureNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API SimpleCaptureNode : public CompoundNode
{
public:
    SimpleCaptureNode(const SourcePos& sourcePos_);
    SimpleCaptureNode(const SourcePos& sourcePos_, Node* identifier_, Node* byRefCapture_, Node* ellipsis_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Identifier() const { return identifier.get(); }
    Node* ByRefCapture() const { return byRefCapture.get(); }
    Node* Ellipsis() const { return ellipsis.get(); }
private:
    std::unique_ptr<Node> identifier;
    std::unique_ptr<Node> byRefCapture;
    std::unique_ptr<Node> ellipsis;
};

class AST_API CurrentObjectCopyCapture : public CompoundNode
{
public:
    CurrentObjectCopyCapture(const SourcePos& sourcePos_);
    CurrentObjectCopyCapture(const SourcePos& sourcePos_, const SourcePos& thisPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& ThisPos() const { return thisPos; }
private:
    SourcePos thisPos;
};

class AST_API CurrentObjectByRefCapture : public CompoundNode
{
public:
    CurrentObjectByRefCapture(const SourcePos& sourcePos_);
    CurrentObjectByRefCapture(const SourcePos& sourcePos_, const SourcePos& thisPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& ThisPos() const { return thisPos; }
private:
    SourcePos thisPos;
};

class AST_API InitCaptureNode : public CompoundNode
{
public:
    InitCaptureNode(const SourcePos& sourcePos_);
    InitCaptureNode(const SourcePos& sourcePos_, Node* identifier_, Node* initializer_, Node* byRefCapture_, Node* ellipsis_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Identifier() const { return identifier.get(); }
    Node* Initializer() const { return initializer.get(); }
    Node* ByRefCapture() const { return byRefCapture.get(); }
    Node* Ellipsis() const { return ellipsis.get(); }
private:
    std::unique_ptr<Node> identifier;
    std::unique_ptr<Node> initializer;
    std::unique_ptr<Node> byRefCapture;
    std::unique_ptr<Node> ellipsis;
};

class AST_API LambdaDeclaratorNode : public CompoundNode
{
public:
    LambdaDeclaratorNode(const SourcePos& sourcePos_);
    LambdaDeclaratorNode(const SourcePos& sourcePos_, Node* parameterList_, Node* specifiers_, Node* requiresClause_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ParameterList() const { return parameterList.get(); }
    Node* Specifiers() const { return specifiers.get(); }
    Node* RequiresClause() const { return requiresClause.get(); }
private:
    std::unique_ptr<Node> parameterList;
    std::unique_ptr<Node> specifiers;
    std::unique_ptr<Node> requiresClause;
};

class AST_API LambdaSpecifiersNode : public CompoundNode
{
public:
    LambdaSpecifiersNode(const SourcePos& sourcePos_);
    LambdaSpecifiersNode(const SourcePos& sourcePos_, Node* declSpecifiers_, Node* noexceptSpecifier_, Node* attributes_, Node* trailingReturnType_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    bool IsEmpty() const;
    Node* DeclSpecifiers() const { return declSpecifiers.get(); }
    Node* NoexceptionSpecifier() const { return noexceptSpecifier.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* TrailingReturnType() const { return trailingReturnType.get(); }
private:
    std::unique_ptr<Node> declSpecifiers;
    std::unique_ptr<Node> noexceptSpecifier;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> trailingReturnType;
};

class AST_API LambdaTemplateParamsNode : public CompoundNode
{
public:
    LambdaTemplateParamsNode(const SourcePos& sourcePos_);
    LambdaTemplateParamsNode(const SourcePos& sourcePos_, Node* templateParams_, Node* requiresClause_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TemplateParams() const { return templateParams.get(); }
    Node* RequiresClause() const { return requiresClause.get(); }
private:
    std::unique_ptr<Node> templateParams;
    std::unique_ptr<Node> requiresClause;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_LAMBDA_INCLUDED

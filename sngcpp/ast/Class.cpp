// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Class.hpp>
#include <sngcpp/ast/Declaration.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

std::u32string ToString(ClassKey classKey)
{
    switch (classKey)
    {
        case ClassKey::class_: return U"class";
        case ClassKey::struct_: return U"struct";
        case ClassKey::union_: return U"union";
        case ClassKey::typename_: return U"typename";
    }
    return std::u32string();
}

BaseClassSpecifierNode::BaseClassSpecifierNode(const Span& span_, Specifier baseSpecifiers_, Node* className_) : 
    Node(span_), baseSpecifiers(baseSpecifiers_), className(className_)
{
}

void BaseClassSpecifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

BaseClassSpecifierSequenceNode::BaseClassSpecifierSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void BaseClassSpecifierSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ForwardClassDeclarationNode::ForwardClassDeclarationNode(const Span& span_, ClassKey classKey_, Node* className_) : Node(span_), classKey(classKey_), className(className_)
{
}

void ForwardClassDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ElaborateClassNameNode::ElaborateClassNameNode(const Span& span_, ClassKey classKey_, Node* className_) : Node(span_), classKey(classKey_), className(className_)
{
}

void ElaborateClassNameNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ClassNode::ClassNode(const Span& span_, ClassKey classKey_, Node* className_, Specifier classVirtSpecifiers_, Node* baseClasses_) : 
    Node(span_), classKey(classKey_), className(className_), classVirtSpecifiers(classVirtSpecifiers_), baseClasses(baseClasses_)
{
}

void ClassNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

Specifier ClassNode::DefaultAccess() const
{
    if (classKey == ClassKey::class_)
    {
        return Specifier::private_;
    }
    else
    {
        return Specifier::public_;
    }
}

void ClassNode::AddDeclaration(const Span& span, Node* declaration)
{
    if (declarations)
    {
        declarations.reset(new DeclarationSequenceNode(span, declarations.release(), declaration));
    }
    else
    {
        declarations.reset(declaration);
    }
}

MemberAccessDeclarationNode::MemberAccessDeclarationNode(const Span& span_, Specifier accessSpecifier_, Node* declaration_, bool explicitAccess_) :
    Node(span_), accessSpecifier(accessSpecifier_), declaration(declaration_), explicitAccess(explicitAccess_)
{
}

void MemberAccessDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MemberDeclarationNode::MemberDeclarationNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_, Node* initializer_) :
    Node(span_), specifiers(specifiers_), typeExpr(typeExpr_), declarator(declarator_), initializer(initializer_)
{
}

void MemberDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SpecialMemberFunctionNode::SpecialMemberFunctionNode(const Span& span_, Specifier specifiers_, Node* declarator_, Node* ctorInitializer_, CompoundStatementNode* functionBody_) :
    Node(span_), specifiers(specifiers_), declarator(declarator_), ctorInitializer(ctorInitializer_), functionBody(functionBody_)
{
}

void SpecialMemberFunctionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CtorInitializerNode::CtorInitializerNode(const Span& span_, Node* memberInitializers_) : UnaryNode(span_, memberInitializers_)
{
}

void CtorInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MemberInitializerNode::MemberInitializerNode(const Span& span_, Node* id_, Node* initializer_) : Node(span_), id(id_), initializer(initializer_)
{
}

void MemberInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MemberInitializerSequenceNode::MemberInitializerSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void MemberInitializerSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast

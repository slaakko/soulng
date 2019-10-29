// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Class.hpp>
#include <sngcpp/ast/Declaration.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

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

BaseClassSpecifierNode::BaseClassSpecifierNode() : Node(NodeType::baseClassSpecifierNode)
{
}

BaseClassSpecifierNode::BaseClassSpecifierNode(const Span& span_, Specifier baseSpecifiers_, Node* className_) : 
    Node(NodeType::baseClassSpecifierNode, span_), baseSpecifiers(baseSpecifiers_), className(className_)
{
}

void BaseClassSpecifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void BaseClassSpecifierNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(baseSpecifiers);
    className->Write(writer);
}

void BaseClassSpecifierNode::Read(Reader& reader)
{
    Node::Read(reader);
    baseSpecifiers = reader.ReadSpecifiers();
    className.reset(reader.ReadNode());
}

BaseClassSpecifierSequenceNode::BaseClassSpecifierSequenceNode() : BinaryNode(NodeType::baseClassSpecifierSequenceNode)
{
}

BaseClassSpecifierSequenceNode::BaseClassSpecifierSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::baseClassSpecifierSequenceNode, span_, left_, right_)
{
}

void BaseClassSpecifierSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ForwardClassDeclarationNode::ForwardClassDeclarationNode() : Node(NodeType::forwardClassDeclarationNode)
{
}

ForwardClassDeclarationNode::ForwardClassDeclarationNode(const Span& span_, ClassKey classKey_, Node* className_) : Node(NodeType::forwardClassDeclarationNode, span_), classKey(classKey_), className(className_)
{
}

void ForwardClassDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ForwardClassDeclarationNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(classKey);
    className->Write(writer);
}

void ForwardClassDeclarationNode::Read(Reader& reader)
{
    Node::Read(reader);
    classKey = reader.ReadClassKey();
    className.reset(reader.ReadNode());
}

ElaborateClassNameNode::ElaborateClassNameNode() : Node(NodeType::elaborateClassNameNode)
{
}

ElaborateClassNameNode::ElaborateClassNameNode(const Span& span_, ClassKey classKey_, Node* className_) : Node(NodeType::elaborateClassNameNode, span_), classKey(classKey_), className(className_)
{
}

void ElaborateClassNameNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ElaborateClassNameNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(classKey);
    className->Write(writer);
}

void ElaborateClassNameNode::Read(Reader& reader)
{
    Node::Read(reader);
    classKey = reader.ReadClassKey();
    className.reset(reader.ReadNode());
}

ClassNode::ClassNode() : Node(NodeType::classNode), classKey(), classVirtSpecifiers()
{
}

ClassNode::ClassNode(const Span& span_, ClassKey classKey_, Node* className_, Specifier classVirtSpecifiers_, Node* baseClasses_) : 
    Node(NodeType::classNode, span_), classKey(classKey_), className(className_), classVirtSpecifiers(classVirtSpecifiers_), baseClasses(baseClasses_)
{
}

void ClassNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ClassNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(classKey);
    className->Write(writer);
    writer.Write(classVirtSpecifiers);
    writer.GetBinaryWriter().Write(baseClasses != nullptr);
    if (baseClasses)
    {
        baseClasses->Write(writer);
    }
    writer.GetBinaryWriter().Write(declarations != nullptr);
    if (declarations)
    {
        declarations->Write(writer);
    }
    writer.Write(openBraceSpan);
    writer.Write(closeBraceSpan);
}

void ClassNode::Read(Reader& reader)
{
    Node::Read(reader);
    classKey = reader.ReadClassKey();
    className.reset(reader.ReadNode());
    classVirtSpecifiers = reader.ReadSpecifiers();
    bool hasBaseClasses = reader.GetBinaryReader().ReadBool();
    if (hasBaseClasses)
    {
        baseClasses.reset(reader.ReadNode());
    }
    bool hasDeclarations = reader.GetBinaryReader().ReadBool();
    if (hasDeclarations)
    {
        declarations.reset(reader.ReadNode());
    }
    reader.Read(openBraceSpan);
    reader.Read(closeBraceSpan);
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

MemberAccessDeclarationNode::MemberAccessDeclarationNode() : Node(NodeType::memberAccessDeclarationNode), accessSpecifier(), explicitAccess()
{
}

MemberAccessDeclarationNode::MemberAccessDeclarationNode(const Span& span_, Specifier accessSpecifier_, Node* declaration_, bool explicitAccess_) :
    Node(NodeType::memberAccessDeclarationNode, span_), accessSpecifier(accessSpecifier_), declaration(declaration_), explicitAccess(explicitAccess_)
{
}

void MemberAccessDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void MemberAccessDeclarationNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(accessSpecifier);
    declaration->Write(writer);
    writer.GetBinaryWriter().Write(explicitAccess);
}

void MemberAccessDeclarationNode::Read(Reader& reader)
{
    Node::Read(reader);
    accessSpecifier = reader.ReadSpecifiers();
    declaration.reset(reader.ReadNode());
    explicitAccess = reader.GetBinaryReader().ReadBool();
}

MemberDeclarationNode::MemberDeclarationNode() : Node(NodeType::memberDeclarationNode), specifiers()
{
}

MemberDeclarationNode::MemberDeclarationNode(const Span& span_, Specifier specifiers_, Node* typeExpr_, Node* declarator_, Node* initializer_) :
    Node(NodeType::memberDeclarationNode, span_), specifiers(specifiers_), typeExpr(typeExpr_), declarator(declarator_), initializer(initializer_)
{
}

void MemberDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void MemberDeclarationNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(specifiers);
    writer.GetBinaryWriter().Write(typeExpr != nullptr);
    if (typeExpr)
    {
        typeExpr->Write(writer);
    }
    declarator->Write(writer);
    writer.GetBinaryWriter().Write(initializer != nullptr);
    if (initializer)
    {
        initializer->Write(writer);
    }
}

void MemberDeclarationNode::Read(Reader& reader)
{
    Node::Read(reader);
    specifiers = reader.ReadSpecifiers();
    bool hasTypeExpr = reader.GetBinaryReader().ReadBool();
    if (hasTypeExpr)
    {
        typeExpr.reset(reader.ReadNode());
    }
    declarator.reset(reader.ReadNode());
    bool hasInitializer = reader.GetBinaryReader().ReadBool();
    if (hasInitializer)
    {
        initializer.reset(reader.ReadNode());
    }
}

SpecialMemberFunctionNode::SpecialMemberFunctionNode() : Node(NodeType::specialMemberFunctionNode), specifiers()
{
}

SpecialMemberFunctionNode::SpecialMemberFunctionNode(const Span& span_, Specifier specifiers_, Node* declarator_, Node* ctorInitializer_, CompoundStatementNode* functionBody_) :
    Node(NodeType::specialMemberFunctionNode, span_), specifiers(specifiers_), declarator(declarator_), ctorInitializer(ctorInitializer_), functionBody(functionBody_)
{
}

void SpecialMemberFunctionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SpecialMemberFunctionNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(specifiers);
    declarator->Write(writer);
    writer.GetBinaryWriter().Write(ctorInitializer != nullptr);
    if (ctorInitializer)
    {
        ctorInitializer->Write(writer);
    }
    writer.GetBinaryWriter().Write(functionBody != nullptr);
    if (functionBody)
    {
        functionBody->Write(writer);
    }
}

void SpecialMemberFunctionNode::Read(Reader& reader)
{
    Node::Read(reader);
    specifiers = reader.ReadSpecifiers();
    declarator.reset(reader.ReadNode());
    bool hasCtorInitializer = reader.GetBinaryReader().ReadBool();
    if (hasCtorInitializer)
    {
        ctorInitializer.reset(reader.ReadNode());
    }
    bool hasFunctionBody = reader.GetBinaryReader().ReadBool();
    if (hasFunctionBody)
    {
        functionBody.reset(reader.ReadCompoundStatementNode());
    }
}

CtorInitializerNode::CtorInitializerNode() : UnaryNode(NodeType::ctorInitializerNode)
{
}

CtorInitializerNode::CtorInitializerNode(const Span& span_, Node* memberInitializers_) : UnaryNode(NodeType::ctorInitializerNode, span_, memberInitializers_)
{
}

void CtorInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MemberInitializerNode::MemberInitializerNode() : Node(NodeType::memberInitializerNode)
{
}

MemberInitializerNode::MemberInitializerNode(const Span& span_, Node* id_, Node* initializer_) : Node(NodeType::memberInitializerNode, span_), id(id_), initializer(initializer_)
{
}

void MemberInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void MemberInitializerNode::Write(Writer& writer)
{
    Node::Write(writer);
    id->Write(writer);
    writer.GetBinaryWriter().Write(initializer != nullptr);
    if (initializer)
    {
        initializer->Write(writer);
    }
}

void MemberInitializerNode::Read(Reader& reader)
{
    Node::Read(reader);
    id.reset(reader.ReadNode());
    bool hasInitializer = reader.GetBinaryReader().ReadBool();
    if (hasInitializer)
    {
        initializer.reset(reader.ReadNode());
    }
}

MemberInitializerSequenceNode::MemberInitializerSequenceNode() : BinaryNode(NodeType::memberInitializerSequenceNode)
{
}

MemberInitializerSequenceNode::MemberInitializerSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::memberInitializerSequenceNode, span_, left_, right_)
{
}

void MemberInitializerSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast

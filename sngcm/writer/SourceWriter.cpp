// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcm/writer/SourceWriter.hpp>
#include <sngcm/ast/Literal.hpp>
#include <sngcm/ast/CompileUnit.hpp>
#include <sngcm/ast/Namespace.hpp>
#include <sngcm/ast/Identifier.hpp>
#include <sngcm/ast/Template.hpp>
#include <sngcm/ast/Attribute.hpp>
#include <sngcm/ast/Function.hpp>
#include <sngcm/ast/Class.hpp>
#include <sngcm/ast/Interface.hpp>
#include <sngcm/ast/Delegate.hpp>
#include <sngcm/ast/Concept.hpp>
#include <sngcm/ast/Typedef.hpp>
#include <sngcm/ast/Constant.hpp>
#include <sngcm/ast/Enumeration.hpp>
#include <sngcm/ast/TypeExpr.hpp>
#include <sngcm/ast/Expression.hpp>
#include <sngcm/ast/GlobalVariable.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>

namespace sngcm { namespace writer {

SourceWriter::SourceWriter(soulng::util::CodeFormatter& formatter_) : formatter(formatter_), omitNewLine(false), omitSemicolon(false)
{
}

void SourceWriter::Visit(sngcm::ast::BoolNode& boolNode)
{
    formatter.Write("bool");
}

void SourceWriter::Visit(sngcm::ast::SByteNode& sbyteNode)
{
    formatter.Write("sbyte");
}

void SourceWriter::Visit(sngcm::ast::ByteNode& byteNode)
{
    formatter.Write("byte");
}

void SourceWriter::Visit(sngcm::ast::ShortNode& shortNode)
{
    formatter.Write("short");
}

void SourceWriter::Visit(sngcm::ast::UShortNode& ushortNode)
{
    formatter.Write("ushort");
}

void SourceWriter::Visit(sngcm::ast::IntNode& intNode)
{
    formatter.Write("int");
}

void SourceWriter::Visit(sngcm::ast::UIntNode& uintNode)
{
    formatter.Write("uint");
}

void SourceWriter::Visit(sngcm::ast::LongNode& longNode)
{
    formatter.Write("long");
}

void SourceWriter::Visit(sngcm::ast::ULongNode& ulongNode)
{
    formatter.Write("ulong");
}

void SourceWriter::Visit(sngcm::ast::FloatNode& floatNode)
{
    formatter.Write("float");
}

void SourceWriter::Visit(sngcm::ast::DoubleNode& doubleNode)
{
    formatter.Write("double");
}

void SourceWriter::Visit(sngcm::ast::CharNode& charNode)
{
    formatter.Write("char");
}

void SourceWriter::Visit(sngcm::ast::WCharNode& wcharNode)
{
    formatter.Write("wchar");
}

void SourceWriter::Visit(sngcm::ast::UCharNode& ucharNode)
{
    formatter.Write("uwchar");
}

void SourceWriter::Visit(sngcm::ast::VoidNode& voidNode)
{
    formatter.Write("void");
}

void SourceWriter::Visit(sngcm::ast::BooleanLiteralNode& booleanLiteralNode)
{
    if (booleanLiteralNode.Value())
    {
        formatter.Write("true");
    }
    else
    {
        formatter.Write("false");
    }
}

void SourceWriter::Visit(sngcm::ast::SByteLiteralNode& sbyteLiteralNode)
{
    formatter.Write(std::to_string(sbyteLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::ByteLiteralNode& byteLiteralNode)
{
    formatter.Write("u" + std::to_string(byteLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::ShortLiteralNode& shortLiteralNode)
{
    formatter.Write(std::to_string(shortLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::UShortLiteralNode& ushortLiteralNode)
{
    formatter.Write("u" + std::to_string(ushortLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::IntLiteralNode& intLiteralNode)
{
    formatter.Write(std::to_string(intLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::UIntLiteralNode& uintLiteralNode)
{
    formatter.Write("u" + std::to_string(uintLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::LongLiteralNode& longLiteralNode)
{
    formatter.Write(std::to_string(longLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::ULongLiteralNode& ulongLiteralNode)
{
    formatter.Write("u" + std::to_string(ulongLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::FloatLiteralNode& floatLiteralNode)
{
    formatter.Write(std::to_string(floatLiteralNode.Value()) + "f");
}

void SourceWriter::Visit(sngcm::ast::DoubleLiteralNode& doubleLiteralNode)
{
    formatter.Write(std::to_string(doubleLiteralNode.Value()));
}

void SourceWriter::Visit(sngcm::ast::CharLiteralNode& charLiteralNode)
{
    formatter.Write("'");
    formatter.Write(soulng::util::CharStr(charLiteralNode.Value()));
    formatter.Write("'");
}

void SourceWriter::Visit(sngcm::ast::WCharLiteralNode& wcharLiteralNode)
{
    formatter.Write("w'");
    formatter.Write(soulng::unicode::ToUtf8(soulng::util::CharStr(char32_t(wcharLiteralNode.Value()))));
    formatter.Write("'");
}

void SourceWriter::Visit(sngcm::ast::UCharLiteralNode& ucharLiteralNode)
{
    formatter.Write("u'");
    formatter.Write(soulng::unicode::ToUtf8(soulng::util::CharStr(ucharLiteralNode.Value())));
    formatter.Write("'");
}

void SourceWriter::Visit(sngcm::ast::StringLiteralNode& stringLiteralNode)
{
    formatter.Write("\"");
    formatter.Write(soulng::util::StringStr(stringLiteralNode.Value()));
    formatter.Write("\"");
}

void SourceWriter::Visit(sngcm::ast::WStringLiteralNode& wstringLiteralNode)
{
    formatter.Write("w\"");
    formatter.Write(soulng::util::StringStr(soulng::unicode::ToUtf8(wstringLiteralNode.Value())));
    formatter.Write("\"");
}

void SourceWriter::Visit(sngcm::ast::UStringLiteralNode& ustringLiteralNode)
{
    formatter.Write("u\"");
    formatter.Write(soulng::util::StringStr(soulng::unicode::ToUtf8(ustringLiteralNode.Value())));
    formatter.Write("\"");
}

void SourceWriter::Visit(sngcm::ast::NullLiteralNode& nullLiteralNode)
{
    formatter.Write("null");
}

void SourceWriter::Visit(sngcm::ast::ArrayLiteralNode& arrayLiteralNode)
{
    formatter.Write("[");
    int n = arrayLiteralNode.Values().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        arrayLiteralNode.Values()[i]->Accept(*this);
    }
    formatter.Write("]");
}

void SourceWriter::Visit(sngcm::ast::StructuredLiteralNode& structuredLiteralNode)
{
    formatter.Write("{");
    int n = structuredLiteralNode.Members().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        structuredLiteralNode.Members()[i]->Accept(*this);
    }
    formatter.Write("}");
}

void SourceWriter::Visit(sngcm::ast::UuidLiteralNode& uuidLiteralNode)
{
    WriteWarning("sngcm::writer::SourceWriter: uuid literals not supported");
}

void SourceWriter::Visit(sngcm::ast::CompileUnitNode& compileUnitNode)
{
    compileUnitNode.GlobalNs()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::NamespaceNode& namespaceNode)
{
    if (!namespaceNode.Id()->Str().empty())
    {
        formatter.Write("namespace ");
        namespaceNode.Id()->Accept(*this);
        formatter.WriteLine();
        formatter.WriteLine("{");
        formatter.IncIndent();
    }
    int n = namespaceNode.Members().Count();
    for (int i = 0; i < n; ++i)
    {
        namespaceNode.Members()[i]->Accept(*this);
        if (i < n - 1)
        {
            sngcm::ast::NodeType nodeType = namespaceNode.Members()[i]->GetNodeType();
            if (nodeType == sngcm::ast::NodeType::aliasNode || nodeType == sngcm::ast::NodeType::namespaceImportNode)
            {
                sngcm::ast::NodeType nextNodeType = namespaceNode.Members()[i + 1]->GetNodeType();
                if (nextNodeType != sngcm::ast::NodeType::aliasNode && nextNodeType != sngcm::ast::NodeType::namespaceImportNode)
                {
                    formatter.WriteLine();
                }
            }
        }
    }
    if (!namespaceNode.Id()->Str().empty())
    {
        formatter.DecIndent();
        formatter.WriteLine("} // namespace " + soulng::unicode::ToUtf8(namespaceNode.Id()->Str()));
    }
}

void SourceWriter::Visit(sngcm::ast::AliasNode& aliasNode)
{
    formatter.Write("using ");
    aliasNode.Id()->Accept(*this);
    formatter.Write(" = ");
    aliasNode.Qid()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::NamespaceImportNode& namespaceImportNode)
{
    formatter.Write("using ");
    namespaceImportNode.Ns()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::IdentifierNode& identifierNode)
{
    formatter.Write(soulng::unicode::ToUtf8(identifierNode.Str()));
}

void SourceWriter::Visit(sngcm::ast::CursorIdNode& cursorIdNode)
{
    WriteWarning("sngcm::writer::SourceWriter: cursor id nodes not supported");
}

void SourceWriter::Visit(sngcm::ast::TemplateIdNode& templateIdNode)
{
    templateIdNode.Primary()->Accept(*this);
    formatter.Write("<");
    int n = templateIdNode.TemplateArguments().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        templateIdNode.TemplateArguments()[i]->Accept(*this);
    }
    formatter.Write(">");
}

void SourceWriter::Visit(sngcm::ast::FunctionNode& functionNode)
{
    sngcm::ast::Attributes* attributes = functionNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (functionNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(functionNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    functionNode.ReturnTypeExpr()->Accept(*this);
    formatter.Write(" ");
    formatter.Write(soulng::unicode::ToUtf8(functionNode.GroupId()));
    int nt = functionNode.TemplateParameters().Count();
    if (nt > 0)
    {
        formatter.Write("<");
        for (int i = 0; i < nt; ++i)
        {
            if (i > 0)
            {
                formatter.Write(", ");
            }
            functionNode.TemplateParameters()[i]->Accept(*this);
        }
        formatter.Write(">");
    }
    formatter.Write("(");
    int np = functionNode.Parameters().Count();
    for (int i = 0; i < np; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        functionNode.Parameters()[i]->Accept(*this);
    }
    formatter.Write(")");
    if (functionNode.WhereConstraint())
    {
        formatter.Write(" ");
        functionNode.WhereConstraint()->Accept(*this);
    }
    if (functionNode.Body())
    {
        formatter.WriteLine();
        functionNode.Body()->Accept(*this);
    }
    else
    {
        formatter.WriteLine(";");
    }
}

void SourceWriter::Visit(sngcm::ast::ClassNode& classNode)
{
    sngcm::ast::Attributes* attributes = classNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (classNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(classNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("class ");
    classNode.Id()->Accept(*this);
    int nt = classNode.TemplateParameters().Count();
    if (nt > 0)
    {
        formatter.Write("<");
        for (int i = 0; i < nt; ++i)
        {
            if (i > 0)
            {
                formatter.Write(", ");
            }
            classNode.TemplateParameters()[i]->Accept(*this);
        }
        formatter.Write(">");
    }
    int nb = classNode.BaseClassOrInterfaces().Count();
    if (nb > 0)
    {
        for (int i = 0; i < nb; ++i)
        {
            if (i > 0)
            {
                formatter.Write(", ");
            }
            classNode.BaseClassOrInterfaces()[i]->Accept(*this);
        }
    }
    if (classNode.WhereConstraint())
    {
        formatter.Write(" ");
        classNode.WhereConstraint()->Accept(*this);
    }
    formatter.WriteLine();
    formatter.WriteLine("{");
    formatter.IncIndent();
    int n = classNode.Members().Count();
    for (int i = 0; i < n; ++i)
    {
        classNode.Members()[i]->Accept(*this);
    }
    formatter.DecIndent();
    formatter.WriteLine("}");
}

void SourceWriter::Visit(sngcm::ast::ThisInitializerNode& thisInitializerNode)
{
    formatter.Write("this(");
    int n = thisInitializerNode.Arguments().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        thisInitializerNode.Arguments()[i]->Accept(*this);
    }
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::BaseInitializerNode& baseInitializerNode)
{
    formatter.Write("base(");
    int n = baseInitializerNode.Arguments().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        baseInitializerNode.Arguments()[i]->Accept(*this);
    }
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::MemberInitializerNode& memberInitializerNode)
{
    memberInitializerNode.MemberId()->Accept(*this);
    formatter.Write("(");
    int n = memberInitializerNode.Arguments().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        memberInitializerNode.Arguments()[i]->Accept(*this);
    }
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::StaticConstructorNode& staticConstructorNode)
{
    sngcm::ast::Attributes* attributes = staticConstructorNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (staticConstructorNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(staticConstructorNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    staticConstructorNode.ClassId()->Accept(*this);
    formatter.Write("()");
    int ni = staticConstructorNode.Initializers().Count();
    if (ni > 0)
    {
        formatter.WriteLine(" :");
        formatter.IncIndent();
        for (int i = 0; i < ni; ++i)
        {
            if (i > 0)
            {
                formatter.Write(", ");
            }
            staticConstructorNode.Initializers()[i]->Accept(*this);
        }
        formatter.DecIndent();
    }
    if (staticConstructorNode.WhereConstraint())
    {
        formatter.WriteLine();
        formatter.IncIndent();
        staticConstructorNode.WhereConstraint()->Accept(*this);
        formatter.DecIndent();
    }
    if (staticConstructorNode.Body())
    {
        formatter.WriteLine();
        staticConstructorNode.Body()->Accept(*this);
    }
    else
    {
        formatter.WriteLine(";");
    }
}

void SourceWriter::Visit(sngcm::ast::ConstructorNode& constructorNode)
{
    sngcm::ast::Attributes* attributes = constructorNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (constructorNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(constructorNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    constructorNode.ClassId()->Accept(*this);
    formatter.Write("(");
    int np = constructorNode.Parameters().Count();
    for (int i = 0; i < np; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        constructorNode.Parameters()[i]->Accept(*this);
    }
    formatter.Write(")");
    int ni = constructorNode.Initializers().Count();
    if (ni > 0)
    {
        formatter.WriteLine(" :");
        formatter.IncIndent();
        for (int i = 0; i < ni; ++i)
        {
            if (i > 0)
            {
                formatter.Write(", ");
            }
            constructorNode.Initializers()[i]->Accept(*this);
        }
        formatter.DecIndent();
    }
    if (constructorNode.WhereConstraint())
    {
        formatter.WriteLine();
        formatter.IncIndent();
        constructorNode.WhereConstraint()->Accept(*this);
        formatter.DecIndent();
    }
    if (constructorNode.Body())
    {
        formatter.WriteLine();
        constructorNode.Body()->Accept(*this);
    }
    else
    {
        formatter.WriteLine(";");
    }
}

void SourceWriter::Visit(sngcm::ast::DestructorNode& destructorNode)
{
    sngcm::ast::Attributes* attributes = destructorNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (destructorNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(destructorNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("~");
    destructorNode.ClassId()->Accept(*this);
    formatter.Write("()");
    if (destructorNode.WhereConstraint())
    {
        formatter.WriteLine();
        formatter.IncIndent();
        destructorNode.WhereConstraint()->Accept(*this);
        formatter.DecIndent();
    }
    if (destructorNode.Body())
    {
        formatter.WriteLine();
        destructorNode.Body()->Accept(*this);
    }
    else
    {
        formatter.WriteLine(";");
    }
}

void SourceWriter::Visit(sngcm::ast::MemberFunctionNode& memberFunctionNode)
{
    sngcm::ast::Attributes* attributes = memberFunctionNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (memberFunctionNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(memberFunctionNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    memberFunctionNode.ReturnTypeExpr()->Accept(*this);
    formatter.Write(" ");
    formatter.Write(soulng::unicode::ToUtf8(memberFunctionNode.GroupId()));
    formatter.Write("(");
    int np = memberFunctionNode.Parameters().Count();
    for (int i = 0; i < np; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        memberFunctionNode.Parameters()[i]->Accept(*this);
    }
    formatter.Write(")");
    if (memberFunctionNode.IsConst())
    {
        formatter.Write(" const");
    }
    if (memberFunctionNode.WhereConstraint())
    {
        formatter.WriteLine();
        formatter.IncIndent();
        memberFunctionNode.WhereConstraint()->Accept(*this);
        formatter.DecIndent();
    }
    if (memberFunctionNode.Body())
    {
        formatter.WriteLine();
        memberFunctionNode.Body()->Accept(*this);
    }
    else
    {
        formatter.WriteLine(";");
    }
}

void SourceWriter::Visit(sngcm::ast::ConversionFunctionNode& conversionFunctionNode)
{
    sngcm::ast::Attributes* attributes = conversionFunctionNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (conversionFunctionNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(conversionFunctionNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("operator ");
    conversionFunctionNode.ReturnTypeExpr()->Accept(*this);
    formatter.Write("()");
    if (conversionFunctionNode.IsConst())
    {
        formatter.Write(" const");
    }
    if (conversionFunctionNode.WhereConstraint())
    {
        formatter.WriteLine();
        formatter.IncIndent();
        conversionFunctionNode.WhereConstraint()->Accept(*this);
        formatter.DecIndent();
    }
    if (conversionFunctionNode.Body())
    {
        formatter.WriteLine();
        conversionFunctionNode.Body()->Accept(*this);
    }
    else
    {
        formatter.WriteLine(";");
    }
}

void SourceWriter::Visit(sngcm::ast::MemberVariableNode& memberVariableNode)
{
    sngcm::ast::Attributes* attributes = memberVariableNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (memberVariableNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(memberVariableNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    memberVariableNode.TypeExpr()->Accept(*this);
    formatter.Write(" ");
    memberVariableNode.Id()->Accept(*this);
    formatter.Write(";");
}

void SourceWriter::Visit(sngcm::ast::InterfaceNode& interfaceNode)
{
    sngcm::ast::Attributes* attributes = interfaceNode.GetAttributes();
    if (attributes)
    {
        attributes->Accept(*this);
        formatter.WriteLine();
    }
    if (interfaceNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(interfaceNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("interface ");
    interfaceNode.Id()->Accept(*this);
    formatter.WriteLine();
    formatter.WriteLine("{");
    formatter.IncIndent();
    int n = interfaceNode.Members().Count();
    for (int i = 0; i < n; ++i)
    {
        interfaceNode.Members()[i]->Accept(*this);
    }
    formatter.DecIndent();
    formatter.WriteLine("}");
}

void SourceWriter::Visit(sngcm::ast::DelegateNode& delegateNode)
{
    if (delegateNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(delegateNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("delegate ");
    delegateNode.ReturnTypeExpr()->Accept(*this);
    formatter.Write(" ");
    delegateNode.Id()->Accept(*this);
    formatter.Write("(");
    int np = delegateNode.Parameters().Count();
    for (int i = 0; i < np; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        delegateNode.Parameters()[i]->Accept(*this);
    }
    formatter.Write(");");
}

void SourceWriter::Visit(sngcm::ast::ClassDelegateNode& classDelegateNode)
{
    if (classDelegateNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(classDelegateNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("class delegate ");
    classDelegateNode.ReturnTypeExpr()->Accept(*this);
    formatter.Write(" ");
    classDelegateNode.Id()->Accept(*this);
    formatter.Write("(");
    int np = classDelegateNode.Parameters().Count();
    for (int i = 0; i < np; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        classDelegateNode.Parameters()[i]->Accept(*this);
    }
    formatter.Write(");");
}

void SourceWriter::Visit(sngcm::ast::ParenthesizedConstraintNode& parenthesizedConstraintNode)
{
    formatter.Write("(");
    parenthesizedConstraintNode.Constraint()->Accept(*this);
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::DisjunctiveConstraintNode& disjunctiveConstraintNode)
{
    disjunctiveConstraintNode.Left()->Accept(*this);
    formatter.Write(" or ");
    disjunctiveConstraintNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ConjunctiveConstraintNode& conjunctiveConstraintNode)
{
    conjunctiveConstraintNode.Left()->Accept(*this);
    formatter.Write(" and ");
    conjunctiveConstraintNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::WhereConstraintNode& whereConstraintNode)
{
    formatter.Write("where ");
    whereConstraintNode.Constraint()->Accept(*this);
    if (whereConstraintNode.Semicolon())
    {
        formatter.WriteLine(";");
    }
}

void SourceWriter::Visit(sngcm::ast::PredicateConstraintNode& predicateConstraintNode)
{
    predicateConstraintNode.InvokeExpr()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::IsConstraintNode& isConstraintNode)
{
    isConstraintNode.TypeExpr()->Accept(*this);
    formatter.Write(" is ");
    isConstraintNode.ConceptOrTypeName()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::MultiParamConstraintNode& multiParamConstraintNode)
{
    multiParamConstraintNode.ConceptId()->Accept(*this);
    formatter.Write("<");
    int n = multiParamConstraintNode.TypeExprs().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        multiParamConstraintNode.TypeExprs()[i]->Accept(*this);
    }
    formatter.Write(">");
}

void SourceWriter::Visit(sngcm::ast::TypeNameConstraintNode& typeNameConstraintNode)
{
    formatter.Write("typename ");
    typeNameConstraintNode.TypeId()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::ConstructorConstraintNode& constructorConstraintNode)
{
    constructorConstraintNode.TypeParamId()->Accept(*this);
    formatter.Write("(");
    int np = constructorConstraintNode.Parameters().Count();
    for (int i = 0; i < np; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        constructorConstraintNode.Parameters()[i]->Accept(*this);
    }
    formatter.WriteLine(");");
}

void SourceWriter::Visit(sngcm::ast::DestructorConstraintNode& destructorConstraintNode)
{
    formatter.Write("~");
    destructorConstraintNode.TypeParamId()->Accept(*this);
    formatter.WriteLine("();");
}

void SourceWriter::Visit(sngcm::ast::MemberFunctionConstraintNode& memberFunctionConstraintNode)
{
    memberFunctionConstraintNode.ReturnTypeExpr()->Accept(*this);
    formatter.Write(" ");
    memberFunctionConstraintNode.TypeParamId()->Accept(*this);
    formatter.Write(".");
    formatter.Write(soulng::unicode::ToUtf8(memberFunctionConstraintNode.GroupId()));
    int np = memberFunctionConstraintNode.Parameters().Count();
    for (int i = 0; i < np; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        memberFunctionConstraintNode.Parameters()[i]->Accept(*this);
    }
    formatter.WriteLine(");");
}

void SourceWriter::Visit(sngcm::ast::FunctionConstraintNode& functionConstraintNode)
{
    functionConstraintNode.ReturnTypeExpr()->Accept(*this);
    formatter.Write(" ");
    formatter.Write(soulng::unicode::ToUtf8(functionConstraintNode.GroupId()));
    int np = functionConstraintNode.Parameters().Count();
    for (int i = 0; i < np; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        functionConstraintNode.Parameters()[i]->Accept(*this);
    }
    formatter.WriteLine(");");
}

void SourceWriter::Visit(sngcm::ast::AxiomStatementNode& axiomStatementNode)
{
    axiomStatementNode.Expression()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::AxiomNode& axiomNode)
{
    formatter.Write("axiom ");
    axiomNode.Id()->Accept(*this);
    int np = axiomNode.Parameters().Count();
    if (np > 0)
    {
        formatter.Write("(");
        for (int i = 0; i < np; ++i)
        {
            if (i > 0)
            {
                formatter.Write(", ");
            }
            axiomNode.Parameters()[i]->Accept(*this);
        }
        formatter.Write(")");
    }
    formatter.WriteLine();
    formatter.WriteLine("{");
    formatter.IncIndent();
    int n = axiomNode.Statements().Count();
    for (int i = 0; i < n; ++i)
    {
        axiomNode.Statements()[i]->Accept(*this);
    }
    formatter.DecIndent();
    formatter.WriteLine("}");
}

void SourceWriter::Visit(sngcm::ast::ConceptIdNode& conceptIdNode)
{
    formatter.Write(" : ");
    conceptIdNode.Id()->Accept(*this);
    formatter.Write("<");
    int n = conceptIdNode.TypeParameters().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        conceptIdNode.TypeParameters()[i]->Accept(*this);
    }
    formatter.Write(">");
}

void SourceWriter::Visit(sngcm::ast::ConceptNode& conceptNode)
{
    if (conceptNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(conceptNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("concept ");
    conceptNode.Id()->Accept(*this);
    formatter.Write("<");
    int n = conceptNode.TypeParameters().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        conceptNode.TypeParameters()[i]->Accept(*this);
    }
    formatter.Write(">");
    if (conceptNode.Refinement())
    {
        conceptNode.Refinement()->Accept(*this);
    }
    formatter.WriteLine();
    int nc = conceptNode.Constraints().Count();
    for (int i = 0; i < nc; ++i)
    {
        sngcm::ast::ConstraintNode* constraintNode = conceptNode.Constraints()[i];
        if (constraintNode->IsHeaderConstraint())
        {
            formatter.IncIndent();
            constraintNode->Accept(*this);
            formatter.DecIndent();
            formatter.WriteLine();
        }
    }
    formatter.WriteLine("{");
    formatter.IncIndent();
    for (int i = 0; i < nc; ++i)
    {
        sngcm::ast::ConstraintNode* constraintNode = conceptNode.Constraints()[i];
        if (constraintNode->IsHeaderConstraint()) continue;
        constraintNode->Accept(*this);
    }
    int na = conceptNode.Axioms().Count();
    for (int i = 0; i < na; ++i)
    {
        conceptNode.Axioms()[i]->Accept(*this);
    }
    formatter.DecIndent();
    formatter.WriteLine("}");
}

void SourceWriter::Visit(sngcm::ast::LabelNode& labelNode)
{
    formatter.Write(soulng::unicode::ToUtf8(labelNode.Label()));
    formatter.Write(": ");
}

void SourceWriter::Visit(sngcm::ast::LabeledStatementNode& labeledStatementNode)
{
    labeledStatementNode.Label()->Accept(*this);
    labeledStatementNode.Stmt()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::CompoundStatementNode& compoundStatementNode)
{
    formatter.WriteLine("{");
    formatter.IncIndent();
    int n = compoundStatementNode.Statements().Count();
    for (int i = 0; i < n; ++i)
    {
        compoundStatementNode.Statements()[i]->Accept(*this);
    }
    formatter.DecIndent();
    formatter.WriteLine("}");
}

void SourceWriter::Visit(sngcm::ast::ReturnStatementNode& returnStatementNode)
{
    formatter.Write("return");
    if (returnStatementNode.Expression())
    {
        formatter.Write(" ");
        returnStatementNode.Expression()->Accept(*this);
    }
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::IfStatementNode& ifStatementNode)
{
    formatter.Write("if (");
    ifStatementNode.Condition()->Accept(*this);
    if (ifStatementNode.ThenS()->GetNodeType() == sngcm::ast::NodeType::compoundStatementNode)
    {
        formatter.WriteLine(")");
    }
    else
    {
        formatter.Write(") ");
    }
    ifStatementNode.ThenS()->Accept(*this);
    if (ifStatementNode.ElseS())
    {
        if (ifStatementNode.ElseS()->GetNodeType() == sngcm::ast::NodeType::compoundStatementNode)
        {
            formatter.WriteLine(" else");
        }
        else
        {
            formatter.Write(" else ");
        }
        ifStatementNode.ElseS()->Accept(*this);
    }
}

void SourceWriter::Visit(sngcm::ast::WhileStatementNode& whileStatementNode)
{
    formatter.Write("while (");
    whileStatementNode.Condition()->Accept(*this);
    if (whileStatementNode.Statement()->GetNodeType() == sngcm::ast::NodeType::compoundStatementNode)
    {
        formatter.WriteLine(")");
    }
    else
    {
        formatter.Write(") ");
    }
    whileStatementNode.Statement()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::DoStatementNode& doStatementNode)
{
    formatter.Write("do");
    if (doStatementNode.Statement()->GetNodeType() == sngcm::ast::NodeType::compoundStatementNode)
    {
        formatter.WriteLine();
    }
    else
    {
        formatter.Write(" ");
    }
    doStatementNode.Statement()->Accept(*this);
    formatter.Write("while (");
    doStatementNode.Condition()->Accept(*this);
    formatter.WriteLine(");");
}

void SourceWriter::Visit(sngcm::ast::ForStatementNode& forStatementNode)
{
    formatter.Write("for (");
    omitNewLine = true;
    forStatementNode.InitS()->Accept(*this);
    omitNewLine = false;
    if (forStatementNode.Condition())
    {
        forStatementNode.Condition()->Accept(*this);
        formatter.Write("; ");
    }
    else
    {
        formatter.Write("; ");
    }
    omitSemicolon = true;
    omitNewLine = true;
    forStatementNode.LoopS()->Accept(*this);
    omitSemicolon = false;
    omitNewLine = false;
    if (forStatementNode.ActionS()->GetNodeType() == sngcm::ast::NodeType::compoundStatementNode)
    {
        formatter.WriteLine(")");
    }
    else
    {
        formatter.Write(") ");
    }
    forStatementNode.ActionS()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::BreakStatementNode& breakStatementNode)
{
    formatter.WriteLine("break;");
}

void SourceWriter::Visit(sngcm::ast::ContinueStatementNode& continueStatementNode)
{
    formatter.WriteLine("continue;");
}

void SourceWriter::Visit(sngcm::ast::GotoStatementNode& gotoStatementNode)
{
    formatter.Write("goto ");
    formatter.Write(soulng::unicode::ToUtf8(gotoStatementNode.Target()));
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::ConstructionStatementNode& constructionStatementNode)
{
    constructionStatementNode.TypeExpr()->Accept(*this);
    formatter.Write(" ");
    constructionStatementNode.Id()->Accept(*this);
    if (constructionStatementNode.Empty())
    {
        formatter.Write(";");
    }
    else if (constructionStatementNode.Assignment())
    {
        formatter.Write(" = ");
        constructionStatementNode.Arguments()[0]->Accept(*this);
        formatter.Write(";");
    }
    else
    {
        formatter.Write("(");
        int n = constructionStatementNode.Arguments().Count();
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                formatter.Write(", ");
            }
            constructionStatementNode.Arguments()[i]->Accept(*this);
        }
        formatter.Write(");");
    }
    if (!omitNewLine)
    {
        formatter.WriteLine();
    }
}

void SourceWriter::Visit(sngcm::ast::DeleteStatementNode& deleteStatementNode)
{
    formatter.Write("delete ");
    deleteStatementNode.Expression()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::DestroyStatementNode& destroyStatementNode)
{
    formatter.Write("destroy ");
    destroyStatementNode.Expression()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::AssignmentStatementNode& assignmentStatementNode)
{
    assignmentStatementNode.TargetExpr()->Accept(*this);
    formatter.Write(" = ");
    assignmentStatementNode.SourceExpr()->Accept(*this);
    if (!omitSemicolon)
    {
        formatter.Write(";");
    }
    if (!omitNewLine)
    {
        formatter.WriteLine();
    }
}

void SourceWriter::Visit(sngcm::ast::ExpressionStatementNode& expressionStatementNode)
{
    expressionStatementNode.Expression()->Accept(*this);
    if (!omitSemicolon)
    {
        formatter.Write(";");
    }
    if (!omitNewLine)
    {
        formatter.WriteLine();
    }
}

void SourceWriter::Visit(sngcm::ast::EmptyStatementNode& emptyStatementNode)
{
    formatter.Write(";");
    if (!omitNewLine)
    {
        formatter.WriteLine();
    }
}

void SourceWriter::Visit(sngcm::ast::RangeForStatementNode& rangeForStatementNode)
{
    formatter.Write("for (");
    rangeForStatementNode.TypeExpr()->Accept(*this);
    formatter.Write(" ");
    rangeForStatementNode.Id()->Accept(*this);
    formatter.Write(" : ");
    rangeForStatementNode.Container()->Accept(*this);
    if (rangeForStatementNode.Action()->GetNodeType() == sngcm::ast::NodeType::compoundStatementNode)
    {
        formatter.WriteLine(")");
    }
    else
    {
        formatter.Write(") ");
    }
    rangeForStatementNode.Action()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::SwitchStatementNode& switchStatementNode)
{
    formatter.Write("switch (");
    switchStatementNode.Condition()->Accept(*this);
    formatter.Write(")");
    formatter.WriteLine("{");
    formatter.IncIndent();
    int n = switchStatementNode.Cases().Count();
    for (int i = 0; i < n; ++i)
    {
        switchStatementNode.Cases()[i]->Accept(*this);
    }
    formatter.DecIndent();
    formatter.WriteLine("}");
}

void SourceWriter::Visit(sngcm::ast::CaseStatementNode& caseStatementNode)
{
    formatter.Write("case ");
    int n = caseStatementNode.CaseExprs().Count();
    for (int i = 0; i < n; ++i)
    {
        caseStatementNode.CaseExprs()[i]->Accept(*this);
        formatter.Write(": ");
    }
    int ns = caseStatementNode.Statements().Count();
    for (int i = 0; i < ns; ++i)
    {
        caseStatementNode.Statements()[i]->Accept(*this);
    }
}

void SourceWriter::Visit(sngcm::ast::DefaultStatementNode& defaultStatementNode)
{
    formatter.Write("default: ");
    int ns = defaultStatementNode.Statements().Count();
    for (int i = 0; i < ns; ++i)
    {
        defaultStatementNode.Statements()[i]->Accept(*this);
    }
}

void SourceWriter::Visit(sngcm::ast::GotoCaseStatementNode& gotoCaseStatementNode)
{
    formatter.Write("goto case ");
    gotoCaseStatementNode.CaseExpr()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::GotoDefaultStatementNode& gotoDefaultStatementNode)
{
    formatter.WriteLine("goto default;");
}

void SourceWriter::Visit(sngcm::ast::ThrowStatementNode& throwStatementNode)
{
    formatter.Write("throw");
    if (throwStatementNode.Expression())
    {
        formatter.Write(" ");
        throwStatementNode.Expression()->Accept(*this);
    }
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::TryStatementNode& tryStatementNode)
{
    formatter.WriteLine("try");
    tryStatementNode.TryBlock()->Accept(*this);
    int n = tryStatementNode.Catches().Count();
    for (int i = 0; i < n; ++i)
    {
        tryStatementNode.Catches()[i]->Accept(*this);
    }
}

void SourceWriter::Visit(sngcm::ast::CatchNode& catchNode)
{
    formatter.Write("catch (");
    catchNode.TypeExpr()->Accept(*this);
    if (catchNode.Id())
    {
        formatter.Write(" ");
        catchNode.Id()->Accept(*this);
    }
    formatter.WriteLine(")");
    catchNode.CatchBlock()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::AssertStatementNode& assertStatementNode)
{
    formatter.Write("#assert ");
    assertStatementNode.AssertExpr()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::ConditionalCompilationPartNode& conditionalCompilationPartNode)
{
    int n = conditionalCompilationPartNode.Statements().Count();
    for (int i = 0; i < n; ++i)
    {
        conditionalCompilationPartNode.Statements()[i]->Accept(*this);
    }
}

void SourceWriter::Visit(sngcm::ast::ConditionalCompilationDisjunctionNode& conditionalCompilationDisjunctionNode)
{
    conditionalCompilationDisjunctionNode.Left()->Accept(*this);
    formatter.Write(" || ");
    conditionalCompilationDisjunctionNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ConditionalCompilationConjunctionNode& conditionalCompilationConjunctionNode)
{
    conditionalCompilationConjunctionNode.Left()->Accept(*this);
    formatter.Write(" && ");
    conditionalCompilationConjunctionNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ConditionalCompilationNotNode& conditionalCompilationNotNode)
{
    formatter.Write("!");
    conditionalCompilationNotNode.Expr()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ConditionalCompilationPrimaryNode& conditionalCompilationPrimaryNode)
{
    formatter.Write(soulng::unicode::ToUtf8(conditionalCompilationPrimaryNode.Symbol()));
}

void SourceWriter::Visit(sngcm::ast::ParenthesizeConditionalCompilationExpressionNode& parenthesizeCondCompExprNode)
{
    formatter.Write("(");
    parenthesizeCondCompExprNode.Expr()->Accept(*this);
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::ConditionalCompilationStatementNode& conditionalCompilationStatementNode)
{
    formatter.Write("#");
    formatter.Write("if (");
    conditionalCompilationStatementNode.IfPart()->Expr()->Accept(*this);
    formatter.WriteLine(")");
    formatter.IncIndent();
    conditionalCompilationStatementNode.IfPart()->Accept(*this);
    formatter.DecIndent();
    int ne = conditionalCompilationStatementNode.ElifParts().Count();
    for (int i = 0; i < ne; ++i)
    {
        formatter.Write("#");
        formatter.Write("elif (");
        conditionalCompilationStatementNode.ElifParts()[i]->Expr()->Accept(*this);
        formatter.WriteLine(")");
        formatter.IncIndent();
        conditionalCompilationStatementNode.ElifParts()[i]->Accept(*this);
        formatter.DecIndent();
    }
    if (conditionalCompilationStatementNode.ElsePart())
    {
        formatter.Write("#");
        formatter.WriteLine("else");
        formatter.IncIndent();
        conditionalCompilationStatementNode.ElsePart()->Accept(*this);
        formatter.DecIndent();
    }
    formatter.WriteLine("#endif");
}

void SourceWriter::Visit(sngcm::ast::TypedefNode& typedefNode)
{
    if (typedefNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(typedefNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("typedef ");
    typedefNode.TypeExpr()->Accept(*this);
    formatter.Write(" ");
    typedefNode.Id()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::ConstantNode& constantNode)
{
    if (constantNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(constantNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("const ");
    constantNode.TypeExpr()->Accept(*this);
    formatter.Write(" ");
    constantNode.Id()->Accept(*this);
    formatter.Write(" = ");
    constantNode.Value()->Accept(*this);
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::EnumTypeNode& enumTypeNode)
{
    if (enumTypeNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(enumTypeNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    formatter.Write("enum ");
    enumTypeNode.Id()->Accept(*this);
    if (enumTypeNode.GetUnderlyingType())
    {
        formatter.Write(" : ");
        enumTypeNode.GetUnderlyingType()->Accept(*this);
    }
    formatter.WriteLine();
    formatter.WriteLine("{");
    formatter.IncIndent();
    int n = enumTypeNode.Constants().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        enumTypeNode.Constants()[i]->Accept(*this);
    }
    formatter.DecIndent();
    formatter.WriteLine("}");
}

void SourceWriter::Visit(sngcm::ast::EnumConstantNode& enumConstantNode)
{
    enumConstantNode.Id()->Accept(*this);
    if (enumConstantNode.HasValue())
    {
        formatter.Write(" = ");
        enumConstantNode.GetValue()->Accept(*this);
    }
}

void SourceWriter::Visit(sngcm::ast::ParameterNode& parameterNode)
{
    parameterNode.TypeExpr()->Accept(*this);
    if (parameterNode.Id())
    {
        formatter.Write(" ");
        parameterNode.Id()->Accept(*this);
    }
}

void SourceWriter::Visit(sngcm::ast::TemplateParameterNode& templateParameterNode)
{
    templateParameterNode.Id()->Accept(*this);
    if (templateParameterNode.DefaultTemplateArgument())
    {
        formatter.Write(" = ");
        templateParameterNode.DefaultTemplateArgument()->Accept(*this);
    }
}

void SourceWriter::Visit(sngcm::ast::ConstNode& constNode)
{
    formatter.Write("const ");
    constNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::LValueRefNode& lvalueRefNode)
{
    lvalueRefNode.Subject()->Accept(*this);
    formatter.Write("&");
}

void SourceWriter::Visit(sngcm::ast::RValueRefNode& rvalueRefNode)
{
    rvalueRefNode.Subject()->Accept(*this);
    formatter.Write("&&");
}

void SourceWriter::Visit(sngcm::ast::PointerNode& pointerNode)
{
    pointerNode.Subject()->Accept(*this);
    formatter.Write("*");
}

void SourceWriter::Visit(sngcm::ast::ArrayNode& arrayNode)
{
    arrayNode.Subject()->Accept(*this);
    formatter.Write("[");
    if (arrayNode.Size())
    {
        arrayNode.Size()->Accept(*this);
    }
    formatter.Write("]");
}

void SourceWriter::Visit(sngcm::ast::DotNode& dotNode)
{
    dotNode.Subject()->Accept(*this);
    formatter.Write(".");
    dotNode.MemberId()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ArrowNode& arrowNode)
{
    arrowNode.Subject()->Accept(*this);
    formatter.Write("->");
    arrowNode.MemberId()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::EquivalenceNode& equivalenceNode)
{
    equivalenceNode.Left()->Accept(*this);
    formatter.Write(" <=> ");
    equivalenceNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ImplicationNode& implicationNode)
{
    implicationNode.Left()->Accept(*this);
    formatter.Write(" => ");
    implicationNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::DisjunctionNode& disjunctionNode)
{
    disjunctionNode.Left()->Accept(*this);
    formatter.Write(" || ");
    disjunctionNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ConjunctionNode& conjunctionNode)
{
    conjunctionNode.Left()->Accept(*this);
    formatter.Write(" && ");
    conjunctionNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::BitOrNode& bitOrNode)
{
    bitOrNode.Left()->Accept(*this);
    formatter.Write(" | ");
    bitOrNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::BitXorNode& bitXorNode)
{
    bitXorNode.Left()->Accept(*this);
    formatter.Write(" ^ ");
    bitXorNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::BitAndNode& bitAndNode)
{
    bitAndNode.Left()->Accept(*this);
    formatter.Write(" & ");
    bitAndNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::EqualNode& equalNode)
{
    equalNode.Left()->Accept(*this);
    formatter.Write(" == ");
    equalNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::NotEqualNode& notEqualNode)
{
    notEqualNode.Left()->Accept(*this);
    formatter.Write(" != ");
    notEqualNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::LessNode& lessNode)
{
    lessNode.Left()->Accept(*this);
    formatter.Write(" < ");
    lessNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::GreaterNode& greaterNode)
{
    greaterNode.Left()->Accept(*this);
    formatter.Write(" > ");
    greaterNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::LessOrEqualNode& lessOrEqualNode)
{
    lessOrEqualNode.Left()->Accept(*this);
    formatter.Write(" <= ");
    lessOrEqualNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::GreaterOrEqualNode& greaterOrEqualNode)
{
    greaterOrEqualNode.Left()->Accept(*this);
    formatter.Write(" >= ");
    greaterOrEqualNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ShiftLeftNode& shiftLeftNode)
{
    shiftLeftNode.Left()->Accept(*this);
    formatter.Write(" << ");
    shiftLeftNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ShiftRightNode& shiftRightNode)
{
    shiftRightNode.Left()->Accept(*this);
    formatter.Write(" >> ");
    shiftRightNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::AddNode& addNode)
{
    addNode.Left()->Accept(*this);
    formatter.Write(" + ");
    addNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::SubNode& subNode)
{
    subNode.Left()->Accept(*this);
    formatter.Write(" - ");
    subNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::MulNode& mulNode)
{
    mulNode.Left()->Accept(*this);
    formatter.Write(" * ");
    mulNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::DivNode& divNode)
{
    divNode.Left()->Accept(*this);
    formatter.Write(" / ");
    divNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::RemNode& remNode)
{
    remNode.Left()->Accept(*this);
    formatter.Write(" % ");
    remNode.Right()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::NotNode& notNode)
{
    formatter.Write("!");
    notNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::UnaryPlusNode& unaryPlusNode)
{
    formatter.Write("+");
    unaryPlusNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::UnaryMinusNode& unaryMinusNode)
{
    formatter.Write("-");
    unaryMinusNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::PrefixIncrementNode& prefixIncrementNode)
{
    formatter.Write("++");
    prefixIncrementNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::PrefixDecrementNode& prefixDecrementNode)
{
    formatter.Write("--");
    prefixDecrementNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::DerefNode& derefNode)
{
    formatter.Write("*");
    derefNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::AddrOfNode& addrOfNode)
{
    formatter.Write("&");
    addrOfNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::ComplementNode& complementNode)
{
    formatter.Write("~");
    complementNode.Subject()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::IsNode& isNode)
{
    isNode.Expr()->Accept(*this);
    formatter.Write(" is ");
    isNode.TargetTypeExpr()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::AsNode& asNode)
{
    asNode.Expr()->Accept(*this);
    formatter.Write(" as ");
    asNode.TargetTypeExpr()->Accept(*this);
}

void SourceWriter::Visit(sngcm::ast::IndexingNode& indexingNode)
{
    indexingNode.Subject()->Accept(*this);
    formatter.Write("[");
    indexingNode.Index()->Accept(*this);
    formatter.Write("]");
}

void SourceWriter::Visit(sngcm::ast::InvokeNode& invokeNode)
{
    invokeNode.Subject()->Accept(*this);
    formatter.Write("(");
    int n = invokeNode.Arguments().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        invokeNode.Arguments()[i]->Accept(*this);
    }
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::PostfixIncrementNode& postfixIncrementNode)
{
    postfixIncrementNode.Subject()->Accept(*this);
    formatter.Write("++");
}

void SourceWriter::Visit(sngcm::ast::PostfixDecrementNode& postfixDecrementNode)
{
    postfixDecrementNode.Subject()->Accept(*this);
    formatter.Write("--");
}

void SourceWriter::Visit(sngcm::ast::SizeOfNode& sizeOfNode)
{
    formatter.Write("sizeof(");
    sizeOfNode.Expression()->Accept(*this);
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::TypeNameNode& typeNameNode)
{
    formatter.Write("typename(");
    typeNameNode.Expression()->Accept(*this);
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::TypeIdNode& typeIdNode)
{
    formatter.Write("typeid(");
    typeIdNode.Expression()->Accept(*this);
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::CastNode& castNode)
{
    formatter.Write("cast<");
    castNode.TargetTypeExpr()->Accept(*this);
    formatter.Write(">(");
    castNode.SourceExpr()->Accept(*this);
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::ConstructNode& constructNode)
{
    formatter.Write("construct<");
    constructNode.TypeExpr()->Accept(*this);
    formatter.Write(">(");
    int n = constructNode.Arguments().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        constructNode.Arguments()[i]->Accept(*this);
    }
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::NewNode& newNode)
{
    formatter.Write("new ");
    newNode.TypeExpr()->Accept(*this);
    formatter.Write("(");
    int n = newNode.Arguments().Count();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        newNode.Arguments()[i]->Accept(*this);
    }
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::ThisNode& thisNode)
{
    formatter.Write("this");
}

void SourceWriter::Visit(sngcm::ast::BaseNode& baseNode)
{
    formatter.Write("base");
}

void SourceWriter::Visit(sngcm::ast::ParenthesizedExpressionNode& parenthesizedExpressionNode)
{
    formatter.Write("(");
    parenthesizedExpressionNode.Subject()->Accept(*this);
    formatter.Write(")");
}

void SourceWriter::Visit(sngcm::ast::GlobalVariableNode& globalVariableNode)
{
    if (globalVariableNode.GetSpecifiers() != sngcm::ast::Specifiers::none)
    {
        formatter.Write(sngcm::ast::SpecifierStr(globalVariableNode.GetSpecifiers()));
        formatter.Write(" ");
    }
    globalVariableNode.TypeExpr()->Accept(*this);
    formatter.Write(" ");
    globalVariableNode.Id()->Accept(*this);
    if (globalVariableNode.Initializer())
    {
        formatter.Write(" = ");
        globalVariableNode.Initializer()->Accept(*this);
    }
    formatter.WriteLine(";");
}

void SourceWriter::Visit(sngcm::ast::Attribute& attribute)
{
    formatter.Write(soulng::unicode::ToUtf8(attribute.Name()));
    if (!attribute.Value().empty())
    {
        formatter.Write("=");
        formatter.Write("\"" + soulng::util::StringStr(soulng::unicode::ToUtf8(attribute.Value())) + "\"");
    }
}

void SourceWriter::Visit(sngcm::ast::Attributes& attributes)
{
    formatter.Write("[");
    int n = attributes.GetAttributes().size();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            formatter.Write(", ");
        }
        attributes.GetAttributes()[i]->Accept(*this);
    }
    formatter.Write("]");
}

void SourceWriter::WriteWarning(const std::string& message)
{
    std::cerr << message << std::endl;
}

} } // sngcm::writer

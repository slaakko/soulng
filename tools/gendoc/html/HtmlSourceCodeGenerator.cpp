// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <gendoc/html/HtmlSourceCodeGenerator.hpp>
#include <sngcpp/symbols/ClassTemplateSpecializationSymbol.hpp>
#include <sngcpp/symbols/ExternalTypeSymbol.hpp>
#include <sngcpp/ast/Class.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/TypeExpr.hpp>
#include <sngcpp/ast/Template.hpp>
#include <sngcpp/parser/SourceLineParser.hpp>
#include <sngxml/dom/CharacterData.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Util.hpp>
#include <fstream>

namespace gendoc { namespace html {

using namespace sngcpp::ast;
using namespace soulng::util;
using namespace soulng::unicode;

HtmlSourceCodeGenerator::HtmlSourceCodeGenerator(const std::u32string& projectName_, const std::vector<std::u32string>& inputLines_, int numDigits_,
    const std::string& styleDirName_, const std::string& styleFileName_, SymbolTable& symbolTable_, int inlineCodeLimit_,
    std::unordered_map<std::u32string, std::unique_ptr<sngxml::dom::Element>>& inlineCodeMap_,
    HtmlContentFilePathResolver* contentFilePathResolver_) :
    projectName(projectName_), symbolTable(symbolTable_), currentFunction(nullptr), invokeSymbol(nullptr), inputLines(inputLines_), numDigits(numDigits_),
    currentSourceLineNumber(1), styleFilePath(Path::Combine(Path::Combine("../..", styleDirName_), styleFileName_)), contentDirPath(".."),
    lineStarts(nullptr), firstBaseClass(false), firstParam(false), firstTemplateParameter(false), firstTemplateArgument(false),
    firstMemberInitializer(false), firstInitializer(false), firstEnumerator(false), rangeForDeclaration(false), blockLevel(0),
    currentAccess(Specifier::private_), inlineCodeLimit(inlineCodeLimit_), inlineCodeOffset(0), inlineCodeMap(inlineCodeMap_), skip(false),
    contentFilePathResolver(contentFilePathResolver_)
{
    htmlElement.reset(new sngxml::dom::Element(U"html"));
}

void HtmlSourceCodeGenerator::WriteDocument()
{
    std::ofstream htmlFile(htmlFilePath);
    CodeFormatter formatter(htmlFile);
    formatter.SetIndentSize(1);
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(bodyElement.release()));
    htmlSourceFileDocument.AppendChild(std::unique_ptr<sngxml::dom::Node>(htmlElement.release()));
    htmlSourceFileDocument.Write(formatter);
}

void HtmlSourceCodeGenerator::Visit(SourceFileNode& sourceFileNode)
{
    lineStarts = sourceFileNode.LineStarts();
    htmlFilePath = sourceFileNode.HtmlSourceFilePath();
    std::unique_ptr<sngxml::dom::Element> headElement(new sngxml::dom::Element(U"head"));
    std::unique_ptr<sngxml::dom::Element> metaElement(new sngxml::dom::Element(U"meta"));
    metaElement->SetAttribute(U"charset", U"utf-8");
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(metaElement.release()));
    std::unique_ptr<sngxml::dom::Element> titleElement(new sngxml::dom::Element(U"title"));
    titleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(sourceFileNode.ProjectName() + U"/" + ToUtf32(sourceFileNode.RelativeSourceFilePath()))));
    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"link"));
    linkElement->SetAttribute(U"rel", U"stylesheet");
    linkElement->SetAttribute(U"type", U"text/css");
    std::u32string relativeStyleFilePath = ToUtf32(styleFilePath);
    linkElement->SetAttribute(U"href", relativeStyleFilePath);
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(headElement.release()));
    bodyElement.reset(new sngxml::dom::Element(U"body"));
    sourceFileNode.GlobalNs()->Accept(*this);
    if (lineElement)
    {
        CloseLine();
    }
    WriteRestOfInput();
}

std::u32string HtmlSourceCodeGenerator::MakeSymbolRef(Symbol* symbol)
{
    if (!symbol) return std::u32string();
    if (symbol->IsParentSymbol())
    {
        if (symbol->IsClassTemplateSpecializationSymbol())
        {
            ClassTemplateSpecializationSymbol* specialization = static_cast<ClassTemplateSpecializationSymbol*>(symbol);
            return MakeSymbolRef(specialization->PrimaryClassTemplateSymbol());
        }
        else if (symbol->IsNamespaceSymbol())
        {
            if (symbol->ProjectName() == projectName)
            {
                return ToUtf32(Path::Combine(contentDirPath, ToUtf8(symbol->Id()) + ".html"));
            }
            else
            {
                NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(symbol);
                if (ns->HasProject(projectName))
                {
                    return ToUtf32(Path::Combine(contentDirPath, ToUtf8(symbol->Id()) + ".html"));
                }
                else
                {
                    std::u32string project = ns->FirstProject();
                    if (project.empty()) return std::u32string();
                    return ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, project, contentDirPath, symbol->Id()));
                }
            }
        }
        else
        {
            return ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, symbol->ProjectName(), contentDirPath, symbol->Id()));
        }
    }
    else if (symbol->IsFunctionGroupSymbol() || symbol->IsClassGroupSymbol() || !symbol->Parent() ||
        symbol->Parent()->IsDeclarationBlockSymbol() || symbol->Parent()->IsFunctionSymbol())
    {
        return std::u32string();
    }
    else
    {
        return MakeSymbolRef(symbol->Parent()) + U"#" + symbol->Id();
    }
}

std::u32string HtmlSourceCodeGenerator::MakeInlineSymbolRef(Symbol* symbol)
{
    if (!symbol) return std::u32string();
    if (symbol->IsParentSymbol())
    {
        if (symbol->IsClassTemplateSpecializationSymbol())
        {
            ClassTemplateSpecializationSymbol* specialization = static_cast<ClassTemplateSpecializationSymbol*>(symbol);
            return MakeInlineSymbolRef(specialization->PrimaryClassTemplateSymbol());
        }
        else if (symbol->IsNamespaceSymbol())
        {
            if (symbol->ProjectName() == projectName)
            {
                return ToUtf32(Path::Combine(".", ToUtf8(symbol->Id()) + ".html"));
            }
            else
            {
                NamespaceSymbol* ns = static_cast<NamespaceSymbol*>(symbol);
                if (ns->HasProject(projectName))
                {
                    return ToUtf32(Path::Combine(".", ToUtf8(symbol->Id()) + ".html"));
                }
                else
                {
                    std::u32string project = ns->FirstProject();
                    if (project.empty()) return std::u32string();
                    return ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, project, ".", symbol->Id()));
                }
            }
        }
        else
        {
            return ToUtf32(contentFilePathResolver->ResolveContentFilePath(projectName, symbol->ProjectName(), ".", symbol->Id()));
        }
    }
    else if (symbol->IsFunctionGroupSymbol() || symbol->IsClassGroupSymbol() || !symbol->Parent() ||
        symbol->Parent()->IsDeclarationBlockSymbol() || symbol->Parent()->IsFunctionSymbol())
    {
        return std::u32string();
    }
    else
    {
        return MakeInlineSymbolRef(symbol->Parent()) + U"#" + symbol->Id();
    }
}

void HtmlSourceCodeGenerator::WriteId(IdentifierNode* id, Symbol* symbol, bool writeType)
{
    MoveTo(id->GetSpan());
    if (symbol)
    {
        if (symbol->IsClassGroupSymbol())
        {
            ClassGroupSymbol* group = static_cast<ClassGroupSymbol*>(symbol);
            symbol = group->GetClass(0);
        }
        else if (symbol->IsFunctionDeclarationSymbol())
        {
            FunctionDeclarationSymbol* functionDeclarationSymbol = static_cast<FunctionDeclarationSymbol*>(symbol);
            if (functionDeclarationSymbol->FunctionDefinition())
            {
                symbol = functionDeclarationSymbol->FunctionDefinition();
            }
            else
            {
                symbol = nullptr;
            }
        }
        writer.WriteLink(id->Identifier(), MakeSymbolRef(symbol));
        writer.WriteInlineLink(id->Identifier(), MakeInlineSymbolRef(symbol));
    }
    else if (writeType)
    {
        writer.WriteType(id->Identifier());
    }
    else
    {
        if (id->IsDtorIdNode())
        {
            writer.WriteOther(U"~");
            writer.WriteIdentifier(id->Identifier());
        }
        else if (id->IsOperatorFunctionIdNode())
        {
            OperatorFunctionIdNode* operatorFunctionIdNode = static_cast<OperatorFunctionIdNode*>(id);
            writer.WriteKeyword(U"operator");
            writer.WriteOther(operatorFunctionIdNode->OpStr());
        }
        else if (id->IsConversionFunctionIdNode())
        {
            writer.WriteKeyword(U"operator");
            writer.WriteSpace(1);
        }
        else
        {
            writer.WriteIdentifier(id->Identifier());
        }
    }
}

void HtmlSourceCodeGenerator::WriteIdSequence(bool writeType, Symbol* terminalSymbol)
{
    if (invokeSymbol && terminalSymbol && invokeSymbol != terminalSymbol &&
        (terminalSymbol->IsClassGroupSymbol() || terminalSymbol->IsClassTypeSymbol() || terminalSymbol->IsFunctionGroupSymbol())) return;
    int n = idSequence.size();
    if (n > 0)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            if (idSequence[i].first)
            {
                WriteId(idSequence[i].first, idSequence[i].second, false);
            }
            writer.WriteOther(U"::");
        }
        if (!terminalSymbol)
        {
            terminalSymbol = idSequence.back().second;
        }
        WriteId(idSequence.back().first, terminalSymbol, writeType);
        idSequence.clear();
    }
}

void HtmlSourceCodeGenerator::WriteType(TypeSymbol* type, const std::vector<IdentifierNode*>& idNodeSequence, TypeExprNode* typeExprNode)
{
    int n = idNodeSequence.size();
    if (type->IsExternalTypeSymbol())
    {
        ExternalTypeSymbol* externalTypeSymbol = static_cast<ExternalTypeSymbol*>(type);
        if (externalTypeSymbol->GetClassKey() != ClassKey::none)
        {
            writer.WriteKeyword(ToString(externalTypeSymbol->GetClassKey()));
            writer.WriteSpace(1);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            IdentifierNode* idNode = idNodeSequence[i];
            if (idNode)
            {
                writer.WriteIdentifier(idNode->Identifier());
            }
            writer.WriteOther(U"::");
        }
        if (n > 0)
        {
            writer.WriteType(idNodeSequence.back()->Identifier());
        }
        else
        {
            writer.WriteType(type->Name());
        }
    }
    else if (type->IsSimpleTypeSymbol())
    {
        SimpleTypeSymbol* simpleTypeSymbol = static_cast<SimpleTypeSymbol*>(type);
        std::vector<std::u32string> components = Split(simpleTypeSymbol->Name(), ' ');
        bool first = true;
        for (const std::u32string& component : components)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                writer.WriteSpace(1);
            }
            writer.WriteKeyword(component);
        }
    }
    else if (type->IsDerivedTypeSymbol())
    {
        DerivedTypeSymbol* derivedTypeSymbol = static_cast<DerivedTypeSymbol*>(type);
        for (Derivation derivation : derivedTypeSymbol->Derivations())
        {
            switch (derivation)
            {
            case Derivation::const_:
            {
                writer.WriteKeyword(U"const ");
                break;
            }
            case Derivation::volatile_:
            {
                writer.WriteKeyword(U"volatile ");
                break;
            }
            case Derivation::ptr:
            {
                writer.WriteOther(U"*");
                break;
            }
            case Derivation::lvalueRef:
            {
                writer.WriteOther(U"&");
                break;
            }
            case Derivation::rvalueRef:
            {
                writer.WriteOther(U"&&");
                break;
            }
            case Derivation::base:
            {
                TypeSymbol* baseType = derivedTypeSymbol->BaseType();
                WriteType(baseType, idNodeSequence, typeExprNode);
                break;
            }
            }
        }
    }
    else if (type->IsClassTemplateSpecializationSymbol())
    {
        ClassTemplateSpecializationSymbol* classTemplateSpecializationSymbol = static_cast<ClassTemplateSpecializationSymbol*>(type);
        TypeSymbol* primaryType = classTemplateSpecializationSymbol->PrimaryClassTemplateSymbol();
        TemplateIdNode* templateIdNode = classTemplateSpecializationSymbol->GetTemplateIdNode();
        if (typeExprNode)
        {
            TemplateIdNode* tinode = symbolTable.GetTemplateIdNodeForTypeExprNode(typeExprNode);
            if (tinode)
            {
                templateIdNode = tinode;
            }
        }
        WriteType(primaryType, symbolTable.GetIdNodeSequence(templateIdNode), typeExprNode);
        writer.WriteOther(U"<");
        int n = classTemplateSpecializationSymbol->TemplateArgumentSymbols().size();
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                writer.WriteOther(U", ");
            }
            TypeSymbol* templateArgumentSymbol = classTemplateSpecializationSymbol->TemplateArgumentSymbols()[i];
            Node* templateArgumentNode = classTemplateSpecializationSymbol->TemplateArgumentNodes()[i];
            Node* tanode = symbolTable.GetTemplateArgumentNodeForTypeExprNode(typeExprNode);
            if (tanode)
            {
                templateArgumentNode = tanode;
            }
            WriteType(templateArgumentSymbol, symbolTable.GetIdNodeSequence(templateArgumentNode), typeExprNode);
        }
        writer.WriteOther(U">");
    }
    else if (type->IsElaborateClassTypeSymbol())
    {
        ElaborateClassTypeSymbol* elaborateClassTypeSymbol = static_cast<ElaborateClassTypeSymbol*>(type);
        writer.WriteKeyword(ToString(elaborateClassTypeSymbol->GetClassKey()));
        writer.WriteSpace(1);
        WriteType(elaborateClassTypeSymbol->GetClassType(), idNodeSequence, typeExprNode);
    }
    else
    {
        for (int i = 0; i < n - 1; ++i)
        {
            IdentifierNode* idNode = idNodeSequence[i];
            writer.WriteIdentifier(idNode->Identifier());
            writer.WriteOther(U"::");
        }
        writer.WriteLink(type->Name(), MakeSymbolRef(type));
        writer.WriteInlineLink(type->Name(), MakeInlineSymbolRef(type));
    }
}

void HtmlSourceCodeGenerator::MoveTo(const Span& span)
{
    int lineNumber = span.line;
    while (lineNumber > currentSourceLineNumber)
    {
        if (!lineElement)
        {
            UseInputLine();
        }
        else
        {
            CloseLine();
        }
    }
    if (!lineElement)
    {
        OpenLine();
    }
    if (inlineCodeElement && !inlineLineElement)
    {
        OpenInlineLine();
    }
    writer.MoveTo(span);
}

void HtmlSourceCodeGenerator::OpenLine()
{
    lineElement.reset(new sngxml::dom::Element(U"span"));
    writer.SetLineElement(lineElement.get());
    lineElement->SetAttribute(U"class", U"code");
    lineElement->SetAttribute(U"xml:space", U"preserve");
    lineElement->SetAttribute(U"id", ToUtf32(std::to_string(currentSourceLineNumber)));
    std::u32string lineNumberText = FormatNumber(currentSourceLineNumber, numDigits);
    writer.WriteLineNumberKind(lineNumberText, WriteKind::line);
    writer.WriteSpaceKind(1, WriteKind::line);
    if (lineStarts->size() < currentSourceLineNumber)
    {
        throw std::runtime_error("invalid line starts vector");
    }
    int lineStart = (*lineStarts)[currentSourceLineNumber - 1];
    writer.SetCurrentPos(lineStart);
}

void HtmlSourceCodeGenerator::OpenInlineLine()
{
    inlineLineElement.reset(new sngxml::dom::Element(U"span"));
    inlineLineElement->SetAttribute(U"class", U"code");
    inlineLineElement->SetAttribute(U"xml:space", U"preserve");
    writer.SetInlineLineElement(inlineLineElement.get());
    std::u32string lineNumberText = FormatNumber(currentSourceLineNumber, numDigits);
    writer.WriteLineNumberKind(lineNumberText, WriteKind::inlineLine);
    writer.WriteSpaceKind(1, WriteKind::inlineLine);
    if (lineStarts->size() < currentSourceLineNumber)
    {
        throw std::runtime_error("invalid line starts vector");
    }
    int inlineLineStart = (*lineStarts)[currentSourceLineNumber - 1] + inlineCodeOffset;
    writer.SetInlineCurrentPos(inlineLineStart);
}

void HtmlSourceCodeGenerator::CloseLine()
{
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(lineElement.release()));
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
    if (inlineCodeElement && inlineLineElement)
    {
        inlineCodeElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(inlineLineElement.release()));
        inlineCodeElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
        writer.SetInlineLineElement(nullptr);
    }
    ++currentSourceLineNumber;
}

void HtmlSourceCodeGenerator::UseInputLine()
{
    const std::u32string& line = inputLines[currentSourceLineNumber - 1];
    OpenLine();
    ParseSourceLine(line, writer);
    CloseLine();
}

void HtmlSourceCodeGenerator::WriteRestOfInput()
{
    int n = inputLines.size();
    while (currentSourceLineNumber <= n)
    {
        UseInputLine();
    }
}

void HtmlSourceCodeGenerator::WriteSpecifiers(Specifier specifiers)
{
    if (specifiers != Specifier::none)
    {
        std::u32string specifierStr = SpecifierStr(specifiers);
        std::vector<std::u32string> s = Split(specifierStr, ' ');
        if (!s.empty())
        {
            bool first = true;
            for (const std::u32string& sp : s)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    writer.WriteOther(U", ");
                }
                if (sp == U"pure")
                {
                    writer.WriteOther(U"= 0");
                }
                else if (sp == U"default" || sp == U"delete")
                {
                    writer.WriteOther(U" = ");
                    writer.WriteKeyword(sp);
                }
                else
                {
                    writer.WriteKeyword(sp);
                }
            }
        }
    }
}

void HtmlSourceCodeGenerator::WriteAccess(const Span& span, Specifier access)
{
    MoveTo(span);
    std::u32string accessStr = SpecifierStr(access & Specifier::access);
    writer.WriteKeyword(accessStr);
    writer.WriteOther(U":");
}

void HtmlSourceCodeGenerator::Visit(NamespaceNode& namespaceNode)
{
    if (namespaceNode.Child())
    {
        namespaceNode.Child()->Accept(*this);
    }
}

void HtmlSourceCodeGenerator::Visit(SimpleDeclarationNode& simpleDeclarationNode)
{
    MoveTo(simpleDeclarationNode.GetSpan());
    Specifier declSpecifiers = simpleDeclarationNode.Specifiers() & DeclSpecifierMask();
    WriteSpecifiers(declSpecifiers);
    simpleDeclarationNode.TypeExpr()->Accept(*this);
    if (simpleDeclarationNode.Declarator())
    {
        simpleDeclarationNode.Declarator()->Accept(*this);
    }
    if (!rangeForDeclaration)
    {
        writer.WriteOther(U";");
    }
}

void HtmlSourceCodeGenerator::Visit(AliasDeclarationNode& aliasDeclarationNode)
{
    MoveTo(aliasDeclarationNode.GetSpan());
    writer.WriteKeyword(U"using ");
    writer.WriteIdentifier(aliasDeclarationNode.Id());
    writer.WriteOther(U" = ");
    aliasDeclarationNode.TypeExpr()->Accept(*this);
    writer.WriteOther(U";");
}

void HtmlSourceCodeGenerator::Visit(DeclarationSequenceNode& declarationSequenceNode)
{
    declarationSequenceNode.Left()->Accept(*this);
    declarationSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode)
{
    MoveTo(forwardClassDeclarationNode.GetSpan());
    writer.WriteKeyword(ToString(forwardClassDeclarationNode.GetClassKey()));
    writer.WriteSpace(1);
    idSequence.clear();
    forwardClassDeclarationNode.ClassName()->Accept(*this);
    WriteIdSequence(true, symbolTable.GetSymbolNothrow(forwardClassDeclarationNode.ClassName()));
    writer.WriteOther(U";");
}

void HtmlSourceCodeGenerator::Visit(ElaborateClassNameNode& elaborateClassNameNode)
{
    MoveTo(elaborateClassNameNode.GetSpan());
    writer.WriteKeyword(ToString(elaborateClassNameNode.GetClassKey()));
    writer.WriteSpace(1);
    idSequence.clear();
    elaborateClassNameNode.ClassName()->Accept(*this);
    WriteIdSequence(true, symbolTable.GetSymbolNothrow(&elaborateClassNameNode));
}

void HtmlSourceCodeGenerator::Visit(ClassNode& classNode)
{
    MoveTo(classNode.GetSpan());
    writer.WriteKeyword(ToString(classNode.GetClassKey()));
    writer.WriteSpace(1);
    idSequence.clear();
    classNode.ClassName()->Accept(*this);
    WriteIdSequence(true, symbolTable.GetSymbolNothrow(&classNode));
    WriteSpecifiers(classNode.ClassVirtSpecifiers());
    writer.WriteSpace(1);
    if (classNode.BaseClasses())
    {
        firstBaseClass = true;
        classNode.BaseClasses()->Accept(*this);
    }
    MoveTo(classNode.OpenBraceSpan());
    writer.WriteOther(U"{");
    if (classNode.Declarations())
    {
        currentAccess = Specifier::none;
        classNode.Declarations()->Accept(*this);
    }
    MoveTo(classNode.CloseBraceSpan());
    writer.WriteOther(U"};");
}

void HtmlSourceCodeGenerator::Visit(BaseClassSpecifierNode& baseClassSpecifierNode)
{
    if (firstBaseClass)
    {
        firstBaseClass = false;
        writer.WriteOther(U": ");
    }
    else
    {
        writer.WriteOther(U", ");
    }
    MoveTo(baseClassSpecifierNode.GetSpan());
    WriteSpecifiers(baseClassSpecifierNode.BaseSpecifiers());
    writer.WriteSpace(1);
    Symbol* symbol = symbolTable.GetSymbol(&baseClassSpecifierNode);
    if (symbol && symbol->IsTypeSymbol() && !symbol->IsClassTemplateSpecializationSymbol())
    {
        TypeSymbol* type = static_cast<TypeSymbol*>(symbol);
        std::vector<IdentifierNode*> idNodeSequence = symbolTable.GetIdNodeSequence(baseClassSpecifierNode.ClassName());
        WriteType(type, idNodeSequence, nullptr);
    }
    else
    {
        idSequence.clear();
        baseClassSpecifierNode.ClassName()->Accept(*this);
        WriteIdSequence(true, symbolTable.GetSymbolNothrow(&baseClassSpecifierNode));
    }
}

void HtmlSourceCodeGenerator::Visit(BaseClassSpecifierSequenceNode& baseClassSpecifierSequenceNode)
{
    baseClassSpecifierSequenceNode.Left()->Accept(*this);
    baseClassSpecifierSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode)
{
    if (currentAccess != memberAccessDeclarationNode.AccessSpecifier())
    {
        if (memberAccessDeclarationNode.ExplicitAccess())
        {
            WriteAccess(memberAccessDeclarationNode.GetSpan(), memberAccessDeclarationNode.AccessSpecifier());
        }
        currentAccess = memberAccessDeclarationNode.AccessSpecifier();
    }
    if (memberAccessDeclarationNode.Declaration())
    {
        memberAccessDeclarationNode.Declaration()->Accept(*this);
    }
}

void HtmlSourceCodeGenerator::Visit(MemberDeclarationNode& memberDeclarationNode)
{
    MoveTo(memberDeclarationNode.GetSpan());
    WriteSpecifiers(memberDeclarationNode.Specifiers() & DeclSpecifierMask());
    if (memberDeclarationNode.TypeExpr())
    {
        memberDeclarationNode.TypeExpr()->Accept(*this);
    }
    memberDeclarationNode.Declarator()->Accept(*this);
    Specifier virtPureSpecifiers = memberDeclarationNode.Specifiers() & VirtPureSpecifierMask();
    if (virtPureSpecifiers != Specifier::none)
    {
        writer.WriteSpace(1);
        WriteSpecifiers(virtPureSpecifiers);
    }
    if (memberDeclarationNode.Initializer())
    {
        memberDeclarationNode.Initializer()->Accept(*this);
    }
    writer.WriteOther(U";");
}

void HtmlSourceCodeGenerator::Visit(FloatingLiteralNode& floatingLiteralNode)
{
    MoveTo(floatingLiteralNode.GetSpan());
    writer.WriteOther(floatingLiteralNode.Rep());
}

void HtmlSourceCodeGenerator::Visit(IntegerLiteralNode& integerLiteralNode)
{
    MoveTo(integerLiteralNode.GetSpan());
    writer.WriteOther(integerLiteralNode.Rep());
}

void HtmlSourceCodeGenerator::Visit(CharacterLiteralNode& characterLiteralNode)
{
    MoveTo(characterLiteralNode.GetSpan());
    writer.WriteString(characterLiteralNode.Rep());
}

void HtmlSourceCodeGenerator::Visit(StringLiteralNode& stringLiteralNode)
{
    MoveTo(stringLiteralNode.GetSpan());
    writer.WriteString(stringLiteralNode.Rep());
}

void HtmlSourceCodeGenerator::Visit(BooleanLiteralNode& booleanLiteralNode)
{
    MoveTo(booleanLiteralNode.GetSpan());
    writer.WriteKeyword(booleanLiteralNode.Rep());
}

void HtmlSourceCodeGenerator::Visit(NullPtrLiteralNode& nullPtrLiteralNode)
{
    MoveTo(nullPtrLiteralNode.GetSpan());
    writer.WriteKeyword(nullPtrLiteralNode.Rep());
}

void HtmlSourceCodeGenerator::Visit(FunctionNode& functionNode)
{
    if ((functionNode.Specifiers() & (Specifier::delete_ | Specifier::default_)) != Specifier::none) return;
    FunctionSymbol* prevFunction = currentFunction;
    Symbol* symbol = symbolTable.GetSymbolNothrow(&functionNode);
    if (symbol && symbol->IsFunctionSymbol())
    {
        currentFunction = static_cast<FunctionSymbol*>(symbol);
    }
    MoveTo(functionNode.GetSpan());
    WriteSpecifiers(functionNode.Specifiers() & DeclSpecifierMask());
    if (functionNode.TypeExpr())
    {
        functionNode.TypeExpr()->Accept(*this);
    }
    functionNode.Declarator()->Accept(*this);
    Specifier virtPureSpecifiers = functionNode.Specifiers() & VirtPureSpecifierMask();
    if (virtPureSpecifiers != Specifier::none)
    {
        writer.WriteSpace(1);
        WriteSpecifiers(virtPureSpecifiers);
    }
    if (functionNode.Body())
    {
        blockLevel = 0;
        functionNode.Body()->Accept(*this);
        if (inlineCodeElement)
        {
            if (inlineLineElement)
            {
                inlineCodeElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(inlineLineElement.release()));
                writer.SetInlineLineElement(nullptr);
            }
            Symbol* symbol = symbolTable.GetSymbolNothrow(&functionNode);
            if (symbol)
            {
                inlineCodeMap[symbol->Id()] = std::move(inlineCodeElement);
            }
            else
            {
                inlineCodeElement.reset();
            }
        }
    }
    else
    {
        Specifier defaultOrDeleteSpecifier = functionNode.Specifiers() & DefaultDeleteSpecifierMask();
        if (defaultOrDeleteSpecifier != Specifier::none)
        {
            if (virtPureSpecifiers != Specifier::none)
            {
                writer.WriteSpace(1);
            }
            WriteSpecifiers(defaultOrDeleteSpecifier);
            writer.WriteOther(U";");
        }
    }
    currentFunction = prevFunction;
}

void HtmlSourceCodeGenerator::Visit(SpecialMemberFunctionNode& specialMemberFunctionNode)
{
    if ((specialMemberFunctionNode.Specifiers() & (Specifier::delete_ | Specifier::default_)) != Specifier::none) return;
    FunctionSymbol* prevFunction = currentFunction;
    Symbol* symbol = symbolTable.GetSymbolNothrow(&specialMemberFunctionNode);
    if (symbol && symbol->IsFunctionSymbol())
    {
        currentFunction = static_cast<FunctionSymbol*>(symbol);
    }
    MoveTo(specialMemberFunctionNode.GetSpan());
    WriteSpecifiers(specialMemberFunctionNode.Specifiers() & DeclSpecifierMask());
    specialMemberFunctionNode.Declarator()->Accept(*this);
    blockLevel = 0;
    if (specialMemberFunctionNode.CtorInitializer())
    {
        int firstLineNumber = specialMemberFunctionNode.CtorInitializer()->GetSpan().line;
        int lastLineNumber = specialMemberFunctionNode.FunctionBody()->EndBraceSpan().line;
        if (lastLineNumber - firstLineNumber + 1 <= inlineCodeLimit)
        {
            inlineCodeElement.reset(new sngxml::dom::Element(U"span"));
            inlineCodeElement->SetAttribute(U"class", U"code");
            inlineCodeOffset = specialMemberFunctionNode.CtorInitializer()->GetSpan().start - (*lineStarts)[firstLineNumber - 1];
        }
        blockLevel = 1;
        specialMemberFunctionNode.CtorInitializer()->Accept(*this);
    }
    if (specialMemberFunctionNode.FunctionBody())
    {
        if (inlineCodeElement)
        {
            inlineCodeOffset = specialMemberFunctionNode.FunctionBody()->GetSpan().start - (*lineStarts)[specialMemberFunctionNode.FunctionBody()->GetSpan().line - 1];
        }
        specialMemberFunctionNode.FunctionBody()->Accept(*this);
        if (inlineCodeElement)
        {
            if (inlineLineElement)
            {
                inlineCodeElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(inlineLineElement.release()));
                writer.SetInlineLineElement(nullptr);
            }
            Symbol* symbol = symbolTable.GetSymbolNothrow(&specialMemberFunctionNode);
            if (symbol)
            {
                inlineCodeMap[symbol->Id()] = std::move(inlineCodeElement);
            }
            else
            {
                inlineCodeElement.reset();
            }
        }
    }
    else
    {
        Specifier defaultOrDeleteSpecifier = specialMemberFunctionNode.Specifiers() & DefaultDeleteSpecifierMask();
        if (defaultOrDeleteSpecifier != Specifier::none)
        {
            WriteSpecifiers(defaultOrDeleteSpecifier);
            writer.WriteOther(U";");
        }
    }
    currentFunction = prevFunction;
}

void HtmlSourceCodeGenerator::Visit(LabeledStatementNode& labeledStatementNode)
{
    MoveTo(labeledStatementNode.GetSpan());
    writer.WriteIdentifier(labeledStatementNode.Label());
    writer.WriteOther(U":");
    labeledStatementNode.Child()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(CaseStatementNode& caseStatementNode)
{
    MoveTo(caseStatementNode.GetSpan());
    writer.WriteKeyword(U"case");
    idSequence.clear();
    caseStatementNode.CaseExpr()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(&caseStatementNode));
    writer.WriteOther(U":");
    caseStatementNode.Child()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(DefaultStatementNode& defaultStatementNode)
{
    MoveTo(defaultStatementNode.GetSpan());
    writer.WriteKeyword(U"default");
    writer.WriteOther(U":");
    defaultStatementNode.Child()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(ExpressionStatementNode& expressionStatementNode)
{
    MoveTo(expressionStatementNode.GetSpan());
    if (expressionStatementNode.Child())
    {
        idSequence.clear();
        firstInitializer = true;
        expressionStatementNode.Child()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(&expressionStatementNode));
    }
    writer.WriteOther(U";");
}

void HtmlSourceCodeGenerator::Visit(CompoundStatementNode& compoundStatementNode)
{
    if (blockLevel == 0)
    {
        int firstLineNumber = compoundStatementNode.GetSpan().line;
        int lastLineNumber = compoundStatementNode.EndBraceSpan().line;
        if (lastLineNumber - firstLineNumber + 1 <= inlineCodeLimit)
        {
            inlineCodeElement.reset(new sngxml::dom::Element(U"span"));
            inlineCodeElement->SetAttribute(U"class", U"code");
            inlineCodeOffset = compoundStatementNode.GetSpan().start - (*lineStarts)[firstLineNumber - 1];
        }
        else
        {
            inlineCodeElement.reset();
        }
    }
    MoveTo(compoundStatementNode.GetSpan());
    writer.WriteOther(U"{");
    if (compoundStatementNode.Child())
    {
        ++blockLevel;
        compoundStatementNode.Child()->Accept(*this);
        --blockLevel;
    }
    MoveTo(compoundStatementNode.EndBraceSpan());
    writer.WriteOther(U"}");
}

void HtmlSourceCodeGenerator::Visit(StatementSequenceNode& statementSequenceNode)
{
    statementSequenceNode.Left()->Accept(*this);
    statementSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(IfStatementNode& ifStatementNode)
{
    MoveTo(ifStatementNode.GetSpan());
    writer.WriteKeyword(U"if ");
    writer.WriteOther(U"(");
    idSequence.clear();
    ifStatementNode.Condition()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(ifStatementNode.Condition()));
    writer.WriteOther(U")");
    ifStatementNode.ThenS()->Accept(*this);
    if (ifStatementNode.ElseS())
    {
        MoveTo(ifStatementNode.ElseSpan());
        writer.WriteKeyword(U"else");
        ifStatementNode.ElseS()->Accept(*this);
    }
}

void HtmlSourceCodeGenerator::Visit(SwitchStatementNode& switchStatementNode)
{
    MoveTo(switchStatementNode.GetSpan());
    writer.WriteKeyword(U"switch ");
    writer.WriteOther(U"(");
    idSequence.clear();
    switchStatementNode.Condition()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(switchStatementNode.Condition()));
    writer.WriteOther(U")");
    switchStatementNode.Statement()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(WhileStatementNode& whileStatementNode)
{
    MoveTo(whileStatementNode.GetSpan());
    writer.WriteKeyword(U"while ");
    writer.WriteOther(U"(");
    idSequence.clear();
    whileStatementNode.Condition()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(whileStatementNode.Condition()));
    writer.WriteOther(U")");
    whileStatementNode.Statement()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(DoStatementNode& doStatementNode)
{
    MoveTo(doStatementNode.GetSpan());
    writer.WriteKeyword(U"do");
    doStatementNode.Statement()->Accept(*this);
    MoveTo(doStatementNode.WhileSpan());
    writer.WriteKeyword(U"while");
    writer.WriteSpace(1);
    writer.WriteOther(U"(");
    idSequence.clear();
    doStatementNode.Condition()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(doStatementNode.Condition()));
    writer.WriteOther(U");");
}

void HtmlSourceCodeGenerator::Visit(RangeForStatementNode& rangeForStatementNode)
{
    MoveTo(rangeForStatementNode.GetSpan());
    writer.WriteKeyword(U"for ");
    writer.WriteOther(U"(");
    bool prevRangeForDeclaration = rangeForDeclaration;
    rangeForDeclaration = true;
    rangeForStatementNode.ForRangeDeclaration()->Accept(*this);
    rangeForDeclaration = prevRangeForDeclaration;
    writer.WriteOther(U" : ");
    idSequence.clear();
    rangeForStatementNode.ForRangeInitializer()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(rangeForStatementNode.ForRangeInitializer()));
    writer.WriteOther(U")");
    rangeForStatementNode.Statement()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(ForStatementNode& forStatementNode)
{
    MoveTo(forStatementNode.GetSpan());
    writer.WriteKeyword(U"for ");
    writer.WriteOther(U"(");
    if (forStatementNode.InitS())
    {
        forStatementNode.InitS()->Accept(*this);
    }
    else
    {
        writer.WriteOther(U";");
    }
    if (forStatementNode.Condition())
    {
        idSequence.clear();
        forStatementNode.Condition()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(forStatementNode.Condition()));
    }
    writer.WriteOther(U";");
    if (forStatementNode.LoopExpr())
    {
        idSequence.clear();
        forStatementNode.LoopExpr()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(forStatementNode.LoopExpr()));
    }
    writer.WriteOther(U")");
    forStatementNode.ActionS()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(BreakStatementNode& breakStatementNode)
{
    MoveTo(breakStatementNode.GetSpan());
    writer.WriteKeyword(U"break");
    writer.WriteOther(U";");
}

void HtmlSourceCodeGenerator::Visit(ContinueStatementNode& continueStatementNode)
{
    MoveTo(continueStatementNode.GetSpan());
    writer.WriteKeyword(U"continue");
    writer.WriteOther(U";");
}

void HtmlSourceCodeGenerator::Visit(ReturnStatementNode& returnStatementNode)
{
    MoveTo(returnStatementNode.GetSpan());
    writer.WriteKeyword(U"return");
    if (returnStatementNode.ReturnExpr())
    {
        idSequence.clear();
        returnStatementNode.ReturnExpr()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(returnStatementNode.ReturnExpr()));
    }
    writer.WriteOther(U";");
}

void HtmlSourceCodeGenerator::Visit(GotoStatementNode& gotoStatementNode)
{
    MoveTo(gotoStatementNode.GetSpan());
    writer.WriteKeyword(U"goto");
    writer.WriteSpace(1);
    writer.WriteIdentifier(gotoStatementNode.Target());
    writer.WriteOther(U";");
}

void HtmlSourceCodeGenerator::Visit(DeclarationStatementNode& declarationStatementNode)
{
    MoveTo(declarationStatementNode.GetSpan());
    declarationStatementNode.Child()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(TryStatementNode& tryStatementNode)
{
    MoveTo(tryStatementNode.GetSpan());
    writer.WriteKeyword(U"try");
    tryStatementNode.TryBlock()->Accept(*this);
    tryStatementNode.Handlers()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(HandlerNode& handlerNode)
{
    MoveTo(handlerNode.GetSpan());
    writer.WriteKeyword(U"catch ");
    writer.WriteOther(U"(");
    handlerNode.ExceptionDeclaration()->Accept(*this);
    writer.WriteOther(U")");
    handlerNode.CatchBlock()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(HandlerSequenceNode& handlerSequenceNode)
{
    handlerSequenceNode.Left()->Accept(*this);
    handlerSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(CatchAllNode& catchAllNode)
{
    MoveTo(catchAllNode.GetSpan());
    writer.WriteOther(U"...");
}

void HtmlSourceCodeGenerator::Visit(CtorInitializerNode& ctorInitializerNode)
{
    MoveTo(ctorInitializerNode.GetSpan());
    writer.WriteOther(U":");
    firstMemberInitializer = true;
    ctorInitializerNode.Child()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(ExpressionListInitializerNode& expressionListInitializer)
{
    MoveTo(expressionListInitializer.GetSpan());
    writer.WriteOther(U"(");
    if (expressionListInitializer.Child())
    {
        firstInitializer = true;
        expressionListInitializer.Child()->Accept(*this);
    }
    writer.WriteOther(U")");
}

void HtmlSourceCodeGenerator::Visit(ExpressionInitializerNode& expressionInitializerNode)
{
    if (firstInitializer)
    {
        firstInitializer = false;
    }
    else
    {
        writer.WriteOther(U", ");
    }
    MoveTo(expressionInitializerNode.GetSpan());
    idSequence.clear();
    expressionInitializerNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(expressionInitializerNode.Child()));
}

void HtmlSourceCodeGenerator::Visit(EnumTypeNode& enumTypeNode)
{
    MoveTo(enumTypeNode.GetSpan());
    EnumKey enumKey = enumTypeNode.GetEnumKey();
    writer.WriteKeyword(ToString(enumKey));
    writer.WriteSpace(1);
    idSequence.clear();
    enumTypeNode.EnumName()->Accept(*this);
    WriteIdSequence(true, symbolTable.GetSymbolNothrow(&enumTypeNode));
    if (enumTypeNode.EnumBase())
    {
        writer.WriteOther(U" : ");
        enumTypeNode.EnumBase()->Accept(*this);
        writer.WriteSpace(1);
    }
    MoveTo(enumTypeNode.OpenBraceSpan());
    writer.WriteOther(U"{");
    if (enumTypeNode.Enumerators())
    {
        firstEnumerator = true;
        enumTypeNode.Enumerators()->Accept(*this);
    }
    MoveTo(enumTypeNode.CloseBraceSpan());
    writer.WriteOther(U"};");
}

void HtmlSourceCodeGenerator::Visit(EnumeratorNode& enumeratorNode)
{
    if (firstEnumerator)
    {
        firstEnumerator = false;
    }
    else
    {
        writer.WriteOther(U", ");
    }
    MoveTo(enumeratorNode.GetSpan());
    writer.WriteIdentifier(enumeratorNode.Enumerator());
    if (enumeratorNode.Value())
    {
        MoveTo(enumeratorNode.AssignmentSignSpan());
        writer.WriteOther(U"=");
        MoveTo(enumeratorNode.Value()->GetSpan());
        writer.WriteOther(enumeratorNode.ValueStr());
    }
}

void HtmlSourceCodeGenerator::Visit(EnumeratorSequenceNode& enumeratorSequenceNode)
{
    enumeratorSequenceNode.Left()->Accept(*this);
    enumeratorSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(AssignmentInitializerNode& assignmentInitializerNode)
{
    MoveTo(assignmentInitializerNode.GetSpan());
    writer.WriteOther(U"=");
    idSequence.clear();
    firstInitializer = true;
    assignmentInitializerNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(assignmentInitializerNode.Child()));
}

void HtmlSourceCodeGenerator::Visit(BracedInitializerListNode& bracedInitializerListNode)
{
    MoveTo(bracedInitializerListNode.GetSpan());
    writer.WriteOther(U"{");
    if (bracedInitializerListNode.Child())
    {
        bool prevFirstInitializer = firstInitializer;
        firstInitializer = true;
        bracedInitializerListNode.Child()->Accept(*this);
        firstInitializer = prevFirstInitializer;
    }
    MoveTo(bracedInitializerListNode.EndBraceSpan());
    writer.WriteOther(U"}");
}

void HtmlSourceCodeGenerator::Visit(MemberInitializerNode& memberInitializerNode)
{
    if (firstMemberInitializer)
    {
        firstMemberInitializer = false;
    }
    else
    {
        writer.WriteOther(U", ");
    }
    MoveTo(memberInitializerNode.GetSpan());
    Symbol* symbol = symbolTable.GetSymbolNothrow(memberInitializerNode.Id());
    if (symbol && symbol->IsTypeSymbol())
    {
        TypeSymbol* type = static_cast<TypeSymbol*>(symbol);
        std::vector<IdentifierNode*> idNodeSequence = symbolTable.GetIdNodeSequence(memberInitializerNode.Id());
        WriteType(type, idNodeSequence, nullptr);
    }
    else
    {
        idSequence.clear();
        memberInitializerNode.Id()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(memberInitializerNode.Id()));
    }
    memberInitializerNode.Initializer()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode)
{
    memberInitializerSequenceNode.Left()->Accept(*this);
    memberInitializerSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(FunctionDeclaratorNode& functionDeclaratorNode)
{
    MoveTo(functionDeclaratorNode.GetSpan());
    skip = false;
    functionDeclaratorNode.Declarator()->Accept(*this);
    if (!skip)
    {
        writer.WriteOther(U"(");
        if (functionDeclaratorNode.Parameters())
        {
            firstParam = true;
            functionDeclaratorNode.Parameters()->Accept(*this);
        }
        writer.WriteOther(U")");
        if (functionDeclaratorNode.CVSpecifiers() != Specifier::none)
        {
            writer.WriteSpace(1);
            WriteSpecifiers(functionDeclaratorNode.CVSpecifiers());
        }
    }
}

void HtmlSourceCodeGenerator::Visit(FunctionPtrIdNode& functionPtrIdNode)
{
    MoveTo(functionPtrIdNode.GetSpan());
    writer.WriteOther(U"(*");
    writer.WriteIdentifier(functionPtrIdNode.Id());
    writer.WriteOther(U")");
    skip = true;
}

void HtmlSourceCodeGenerator::Visit(MemberFunctionPtrIdNode& memberFunctionPtrIdNode)
{
    MoveTo(memberFunctionPtrIdNode.GetSpan());
    writer.WriteOther(U"(");
    idSequence.clear();
    memberFunctionPtrIdNode.ClassNameNode()->Accept(*this);
    WriteIdSequence(true, symbolTable.GetSymbolNothrow(memberFunctionPtrIdNode.ClassNameNode()));
    writer.WriteOther(U"::*");
    writer.WriteIdentifier(memberFunctionPtrIdNode.Id());
    writer.WriteOther(U")");
    skip = true;
}

void HtmlSourceCodeGenerator::Visit(ArrayDeclaratorNode& arrayDeclaratorNode)
{
    MoveTo(arrayDeclaratorNode.GetSpan());
    arrayDeclaratorNode.Declarator()->Accept(*this);
    writer.WriteOther(U"[");
    if (arrayDeclaratorNode.Size())
    {
        idSequence.clear();
        arrayDeclaratorNode.Size()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(arrayDeclaratorNode.Size()));
    }
    writer.WriteOther(U"]");
}

void HtmlSourceCodeGenerator::Visit(InitDeclaratorNode& initDeclaratorNode)
{
    MoveTo(initDeclaratorNode.GetSpan());
    initDeclaratorNode.Declarator()->Accept(*this);
    initDeclaratorNode.Initializer()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(IdDeclaratorNode& idDeclaratorNode)
{
    MoveTo(idDeclaratorNode.GetSpan());
    idSequence.clear();
    idDeclaratorNode.IdNode()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(idDeclaratorNode.IdNode()));
}

void HtmlSourceCodeGenerator::Visit(ParameterNode& parameterNode)
{
    if (firstParam)
    {
        firstParam = false;
    }
    else
    {
        writer.WriteOther(U", ");
    }
    MoveTo(parameterNode.GetSpan());
    parameterNode.TypeExpr()->Accept(*this);
    if (parameterNode.Declarator())
    {
        parameterNode.Declarator()->Accept(*this);
    }
}

void HtmlSourceCodeGenerator::Visit(ParameterSequenceNode& parameterSequenceNode)
{
    parameterSequenceNode.Left()->Accept(*this);
    parameterSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(TypeExprNode& typeExprNode)
{
    MoveTo(typeExprNode.GetSpan());
    Symbol* symbol = symbolTable.GetSymbol(&typeExprNode);
    if (symbol->IsPseudoTypeSymbol())
    {
        typeExprNode.Child()->Accept(*this);
    }
    else if (symbol->IsTypeSymbol())
    {
        TypeSymbol* typeSymbol = static_cast<TypeSymbol*>(symbol);
        std::vector<IdentifierNode*> idNodeSequence = symbolTable.GetIdNodeSequence(&typeExprNode);
        WriteType(typeSymbol, idNodeSequence, &typeExprNode);
    }
    else
    {
        throw std::runtime_error("type symbol expected");
    }
}

void HtmlSourceCodeGenerator::Visit(SimpleTypeNode& simpleTypeNode)
{
    MoveTo(simpleTypeNode.GetSpan());
    std::u32string str = simpleTypeNode.Str();
    std::vector<std::u32string> s = Split(str, ' ');
    bool first = true;
    for (const std::u32string& sp : s)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            writer.WriteSpace(1);
        }
        writer.WriteKeyword(sp);
    }
}

void HtmlSourceCodeGenerator::Visit(TypeParameterNode& typeParameterNode)
{
    MoveTo(typeParameterNode.GetSpan());
    if (typeParameterNode.TypenameUsed())
    {
        writer.WriteKeyword(U"typename");
    }
    else
    {
        writer.WriteKeyword(U"class");
    }
    writer.WriteSpace(1);
    writer.WriteIdentifier(typeParameterNode.Id());
    if (typeParameterNode.DefaultTemplateParameter())
    {
        writer.WriteOther(U" = ");
        idSequence.clear();
        typeParameterNode.DefaultTemplateParameter()->Accept(*this);
        WriteIdSequence(true, symbolTable.GetSymbolNothrow(typeParameterNode.DefaultTemplateParameter()));
    }
}

void HtmlSourceCodeGenerator::Visit(TemplateParameterSequenceNode& templateParameterSequenceNode)
{
    templateParameterSequenceNode.Left()->Accept(*this);
    templateParameterSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(TemplateDeclarationNode& templateDeclarationNode)
{
    MoveTo(templateDeclarationNode.GetSpan());
    writer.WriteKeyword(U"template");
    writer.WriteOther(U"<");
    if (templateDeclarationNode.TemplateParameters())
    {
        firstTemplateParameter = true;
        templateDeclarationNode.TemplateParameters()->Accept(*this);
    }
    writer.WriteOther(U">");
    templateDeclarationNode.Declaration()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode)
{
    MoveTo(templateArgumentSequenceNode.GetSpan());
    templateArgumentSequenceNode.Left()->Accept(*this);
    templateArgumentSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(TemplateIdNode& templateIdNode)
{
    MoveTo(templateIdNode.GetSpan());
    templateIdNode.Id()->Accept(*this);
    WriteIdSequence(true, symbolTable.GetSymbolNothrow(&templateIdNode));
    writer.WriteOther(U"<");
    if (templateIdNode.TemplateArguments())
    {
        firstTemplateArgument = true;
        templateIdNode.TemplateArguments()->Accept(*this);
    }
    writer.WriteOther(U">");
}

void HtmlSourceCodeGenerator::Visit(TemplateArgumentNode& templateArgumentNode)
{
    if (firstTemplateArgument)
    {
        firstTemplateArgument = false;
    }
    else
    {
        writer.WriteOther(U", ");
    }
    MoveTo(templateArgumentNode.GetSpan());
    templateArgumentNode.Arg()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(IdentifierNode& identifierNode)
{
    idSequence.push_back(std::make_pair(&identifierNode, symbolTable.GetSymbolNothrow(&identifierNode)));
}

void HtmlSourceCodeGenerator::Visit(NestedIdNode& nestedIdNode)
{
    if (nestedIdNode.Left())
    {
        nestedIdNode.Left()->Accept(*this);
        if (nestedIdNode.Left()->IsTemplateIdNode())
        {
            writer.WriteOther(U"::");
        }
    }
    else
    {
        idSequence.push_back(std::make_pair(nullptr, nullptr));
    }
    nestedIdNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(OperatorFunctionIdNode& operatorFunctionIdNode)
{
    idSequence.push_back(std::make_pair(&operatorFunctionIdNode, symbolTable.GetSymbolNothrow(&operatorFunctionIdNode)));
}

void HtmlSourceCodeGenerator::Visit(ConversionFunctionIdNode& conversionFunctionIdNode)
{
    idSequence.push_back(std::make_pair(&conversionFunctionIdNode, symbolTable.GetSymbolNothrow(&conversionFunctionIdNode)));
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(&conversionFunctionIdNode));
    conversionFunctionIdNode.TypeExpr()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(DtorIdNode& dtorIdNode)
{
    idSequence.push_back(std::make_pair(&dtorIdNode, symbolTable.GetSymbolNothrow(&dtorIdNode)));
}

void HtmlSourceCodeGenerator::Visit(ExpressionSequenceNode& expressionSequenceNode)
{
    expressionSequenceNode.Left()->Accept(*this);
    expressionSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(CommaExpressionNode& commaExpressionNode)
{
    MoveTo(commaExpressionNode.GetSpan());
    idSequence.clear();
    commaExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(commaExpressionNode.Left()));
    writer.WriteOther(U", ");
    idSequence.clear();
    commaExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(commaExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(AssignmentExpressionNode& assignmentExpressionNode)
{
    MoveTo(assignmentExpressionNode.GetSpan());
    idSequence.clear();
    assignmentExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(assignmentExpressionNode.Left()));
    writer.WriteOther(OpStr(assignmentExpressionNode.Op()));
    idSequence.clear();
    firstInitializer = true;
    assignmentExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(assignmentExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(ConditionalExpressionNode& conditionalExpressionNode)
{
    MoveTo(conditionalExpressionNode.GetSpan());
    idSequence.clear();
    conditionalExpressionNode.Condition()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(conditionalExpressionNode.Condition()));
    writer.WriteOther(U" ? ");
    idSequence.clear();
    conditionalExpressionNode.ThenExpr()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(conditionalExpressionNode.ThenExpr()));
    writer.WriteOther(U" : ");
    idSequence.clear();
    conditionalExpressionNode.ElseExpr()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(conditionalExpressionNode.ElseExpr()));
}

void HtmlSourceCodeGenerator::Visit(ThrowExpressionNode& throwExpressionNode)
{
    MoveTo(throwExpressionNode.GetSpan());
    writer.WriteKeyword(U"throw ");
    if (throwExpressionNode.Child())
    {
        idSequence.clear();
        throwExpressionNode.Child()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(throwExpressionNode.Child()));
    }
}

void HtmlSourceCodeGenerator::Visit(LogicalOrExpressionNode& logicalOrExpressionNode)
{
    MoveTo(logicalOrExpressionNode.GetSpan());
    idSequence.clear();
    logicalOrExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(logicalOrExpressionNode.Left()));
    writer.WriteOther(U" || ");
    idSequence.clear();
    logicalOrExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(logicalOrExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(LogicalAndExpressionNode& logicalAndExpressionNode)
{
    MoveTo(logicalAndExpressionNode.GetSpan());
    idSequence.clear();
    logicalAndExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(logicalAndExpressionNode.Left()));
    writer.WriteOther(U" && ");
    idSequence.clear();
    logicalAndExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(logicalAndExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(InclusiveOrExpressionNode& inclusiveOrExpressionNode)
{
    MoveTo(inclusiveOrExpressionNode.GetSpan());
    idSequence.clear();
    inclusiveOrExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(inclusiveOrExpressionNode.Left()));
    writer.WriteOther(U" | ");
    idSequence.clear();
    inclusiveOrExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(inclusiveOrExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(ExclusiveOrExpressionNode& exclusiveOrExpressionNode)
{
    MoveTo(exclusiveOrExpressionNode.GetSpan());
    idSequence.clear();
    exclusiveOrExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(exclusiveOrExpressionNode.Left()));
    writer.WriteOther(U" ^ ");
    idSequence.clear();
    exclusiveOrExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(exclusiveOrExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(AndExpressionNode& andExpressionNode)
{
    MoveTo(andExpressionNode.GetSpan());
    idSequence.clear();
    andExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(andExpressionNode.Left()));
    writer.WriteOther(U" & ");
    idSequence.clear();
    andExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(andExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(EqualityExpressionNode& equalityExpressionNode)
{
    MoveTo(equalityExpressionNode.GetSpan());
    idSequence.clear();
    equalityExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(equalityExpressionNode.Left()));
    writer.WriteOther(OpStr(equalityExpressionNode.Op()));
    idSequence.clear();
    equalityExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(equalityExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(RelationalExpressionNode& relationalExpressionNode)
{
    MoveTo(relationalExpressionNode.GetSpan());
    idSequence.clear();
    relationalExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(relationalExpressionNode.Left()));
    writer.WriteOther(OpStr(relationalExpressionNode.Op()));
    idSequence.clear();
    relationalExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(relationalExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(ShiftExpressionNode& shiftExpressionNode)
{
    MoveTo(shiftExpressionNode.GetSpan());
    idSequence.clear();
    shiftExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(shiftExpressionNode.Left()));
    writer.WriteOther(OpStr(shiftExpressionNode.Op()));
    idSequence.clear();
    shiftExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(shiftExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(AdditiveExpressionNode& additiveExpressionNode)
{
    MoveTo(additiveExpressionNode.GetSpan());
    idSequence.clear();
    additiveExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(additiveExpressionNode.Left()));
    writer.WriteOther(OpStr(additiveExpressionNode.Op()));
    idSequence.clear();
    additiveExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(additiveExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(MultiplicativeExpressionNode& multiplicativeExpressionNode)
{
    MoveTo(multiplicativeExpressionNode.GetSpan());
    idSequence.clear();
    multiplicativeExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(multiplicativeExpressionNode.Left()));
    writer.WriteOther(OpStr(multiplicativeExpressionNode.Op()));
    idSequence.clear();
    multiplicativeExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(multiplicativeExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(PMExpressionNode& pmExpressionNode)
{
    MoveTo(pmExpressionNode.GetSpan());
    idSequence.clear();
    pmExpressionNode.Left()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(pmExpressionNode.Left()));
    writer.WriteOther(OpStr(pmExpressionNode.Op()));
    idSequence.clear();
    pmExpressionNode.Right()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(pmExpressionNode.Right()));
}

void HtmlSourceCodeGenerator::Visit(CastExpressionNode& castExpressionNode)
{
    MoveTo(castExpressionNode.GetSpan());
    writer.WriteOther(U"(");
    castExpressionNode.TypeExpr()->Accept(*this);
    writer.WriteOther(U")");
    idSequence.clear();
    castExpressionNode.Expr()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(castExpressionNode.Expr()));
}

void HtmlSourceCodeGenerator::Visit(UnaryExpressionNode& unaryExpressionNode)
{
    MoveTo(unaryExpressionNode.GetSpan());
    writer.WriteOther(OpStr(unaryExpressionNode.Op()));
    idSequence.clear();
    unaryExpressionNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(unaryExpressionNode.Child()));
}

void HtmlSourceCodeGenerator::Visit(NewExpressionNode& newExpressionNode)
{
    MoveTo(newExpressionNode.GetSpan());
    writer.WriteKeyword(U"new ");
    if (newExpressionNode.Placement())
    {
        writer.WriteOther(U"(");
        firstInitializer = true;
        newExpressionNode.Placement()->Accept(*this);
        writer.WriteOther(U")");
    }
    newExpressionNode.TypeExpr()->Accept(*this);
    writer.WriteOther(U"(");
    if (newExpressionNode.Initializer())
    {
        firstInitializer = true;
        idSequence.clear();
        newExpressionNode.Initializer()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(newExpressionNode.Initializer()));
    }
    writer.WriteOther(U")");
}

void HtmlSourceCodeGenerator::Visit(DeleteExpressionNode& deleteExpressionNode)
{
    MoveTo(deleteExpressionNode.GetSpan());
    writer.WriteKeyword(U"delete");
    if (deleteExpressionNode.Array())
    {
        writer.WriteOther(U"[]");
    }
    writer.WriteSpace(1);
    idSequence.clear();
    deleteExpressionNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(deleteExpressionNode.Child()));
}

void HtmlSourceCodeGenerator::Visit(SubscriptExpressionNode& subscriptExpressionNode)
{
    MoveTo(subscriptExpressionNode.GetSpan());
    idSequence.clear();
    subscriptExpressionNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(subscriptExpressionNode.Child()));
    writer.WriteOther(U"[");
    idSequence.clear();
    subscriptExpressionNode.Index()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(subscriptExpressionNode.Index()));
    writer.WriteOther(U"]");
}

void HtmlSourceCodeGenerator::Visit(InvokeExpressionNode& invokeExpressionNode)
{
    MoveTo(invokeExpressionNode.GetSpan());
    idSequence.clear();
    Symbol* prevInvokeSymbol = invokeSymbol;
    invokeSymbol = symbolTable.GetSymbolNothrow(&invokeExpressionNode);
    invokeExpressionNode.Child()->Accept(*this);
    WriteIdSequence(false, invokeSymbol);
    invokeSymbol = prevInvokeSymbol;
    writer.WriteOther(U"(");
    if (invokeExpressionNode.Arguments())
    {
        firstInitializer = true;
        idSequence.clear();
        invokeExpressionNode.Arguments()->Accept(*this);
        WriteIdSequence(false, symbolTable.GetSymbolNothrow(invokeExpressionNode.Arguments()));
    }
    writer.WriteOther(U")");
}

void HtmlSourceCodeGenerator::Visit(DotNode& dotNode)
{
    MoveTo(dotNode.GetSpan());
    idSequence.clear();
    dotNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(dotNode.Child()));
    writer.WriteOther(U".");
    idSequence.clear();
    dotNode.Id()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(dotNode.Id()));
}

void HtmlSourceCodeGenerator::Visit(ArrowNode& arrowNode)
{
    MoveTo(arrowNode.GetSpan());
    idSequence.clear();
    arrowNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(arrowNode.Child()));
    writer.WriteOther(U"->");
    idSequence.clear();
    arrowNode.Id()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(arrowNode.Id()));
}

void HtmlSourceCodeGenerator::Visit(PostfixIncNode& postfixIncNode)
{
    MoveTo(postfixIncNode.GetSpan());
    idSequence.clear();
    postfixIncNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(postfixIncNode.Child()));
    writer.WriteOther(U"++");
}

void HtmlSourceCodeGenerator::Visit(PostfixDecNode& postfixDecNode)
{
    MoveTo(postfixDecNode.GetSpan());
    idSequence.clear();
    postfixDecNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(postfixDecNode.Child()));
    writer.WriteOther(U"--");
}

void HtmlSourceCodeGenerator::Visit(CppCastExpressionNode& cppCastExpressionNode)
{
    MoveTo(cppCastExpressionNode.GetSpan());
    writer.WriteKeyword(OpStr(cppCastExpressionNode.Op()));
    writer.WriteOther(U"<");
    cppCastExpressionNode.TypeExpr()->Accept(*this);
    writer.WriteOther(U">");
    writer.WriteOther(U"(");
    idSequence.clear();
    firstInitializer = true;
    cppCastExpressionNode.Expr()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(cppCastExpressionNode.Expr()));
    writer.WriteOther(U")");
}

void HtmlSourceCodeGenerator::Visit(TypeIdExpressionNode& typeIdExpressionNode)
{
    MoveTo(typeIdExpressionNode.GetSpan());
    writer.WriteKeyword(U"typeid");
    writer.WriteOther(U" (");
    idSequence.clear();
    typeIdExpressionNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(typeIdExpressionNode.Child()));
    writer.WriteOther(U")");
}

void HtmlSourceCodeGenerator::Visit(ThisNode& thisNode)
{
    MoveTo(thisNode.GetSpan());
    writer.WriteKeyword(U"this");
}

void HtmlSourceCodeGenerator::Visit(ParenthesizedExprNode& parenthesizedExprNode)
{
    MoveTo(parenthesizedExprNode.GetSpan());
    writer.WriteOther(U"(");
    idSequence.clear();
    parenthesizedExprNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(parenthesizedExprNode.Child()));
    writer.WriteOther(U")");
}

void HtmlSourceCodeGenerator::Visit(LambdaExpressionNode& lambdaExpressionNode)
{
    MoveTo(lambdaExpressionNode.GetSpan());
    writer.WriteOther(U"[");
    if (lambdaExpressionNode.Captures())
    {
        lambdaExpressionNode.Captures()->Accept(*this);
    }
    writer.WriteOther(U"]");
    if (lambdaExpressionNode.Parameters())
    {
        firstParam = true;
        writer.WriteOther(U"(");
        lambdaExpressionNode.Parameters()->Accept(*this);
        writer.WriteOther(U")");
    }
    lambdaExpressionNode.Body()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(CaptureSequenceNode& captureSequenceNode)
{
    captureSequenceNode.Left()->Accept(*this);
    captureSequenceNode.Right()->Accept(*this);
}

void HtmlSourceCodeGenerator::Visit(AssignCaptureNode& assignCaptureNode)
{
    MoveTo(assignCaptureNode.GetSpan());
    writer.WriteOther(U"=");
}

void HtmlSourceCodeGenerator::Visit(RefCaptureNode& refCaptureNode)
{
    MoveTo(refCaptureNode.GetSpan());
    writer.WriteOther(U"&");
}

void HtmlSourceCodeGenerator::Visit(ThisCaptureNode& thisCaptureNode)
{
    MoveTo(thisCaptureNode.GetSpan());
    writer.WriteKeyword(U"this");
}

void HtmlSourceCodeGenerator::Visit(IdentifierCaptureNode& identifierCaptureNode)
{
    MoveTo(identifierCaptureNode.GetSpan());
    idSequence.clear();
    identifierCaptureNode.Child()->Accept(*this);
    WriteIdSequence(false, symbolTable.GetSymbolNothrow(identifierCaptureNode.Child()));
}

} } // namespace gendoc::html

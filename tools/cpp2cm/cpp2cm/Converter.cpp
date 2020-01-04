// =================================
// Copyright () 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/Converter.hpp>
#include <cpp2cm/cpp2cm/Args.hpp>
#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/ast/Class.hpp>
#include <sngcpp/ast/Namespace.hpp>
#include <sngcpp/symbols/ParameterSymbol.hpp>
#include <sngcpp/symbols/VariableSymbol.hpp>
#include <sngcpp/symbols/ClassTemplateSpecializationSymbol.hpp>
#include <sngcm/ast/SourceWriter.hpp>
#include <sngcm/ast/CompileUnit.hpp>
#include <sngcm/ast/Identifier.hpp>
#include <sngcm/ast/Function.hpp>
#include <sngcm/ast/Class.hpp>
#include <sngcm/ast/Literal.hpp>
#include <sngcm/ast/Expression.hpp>
#include <sngcm/ast/TypeExpr.hpp>
#include <sngcm/ast/GlobalVariable.hpp>
#include <sngcm/ast/Comment.hpp>
#include <sngcm/ast/Constant.hpp>
#include <sngcm/ast/Enumeration.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <fstream>
#include <iostream>

namespace cpp2cm {

const char* Cpp2CmVersion()
{
    return "1.0.0";
}

using namespace soulng::util;
using namespace soulng::unicode;
using soulng::lexer::Span;

// boolNode, sbyteNode, byteNode, shortNode, ushortNode, intNode, uintNode, longNode, ulongNode, floatNode, doubleNode, charNode, wcharNode, ucharNode, voidNode

sngcm::ast::NodeType commonType[15][15] =
{
    // bool
    {
        sngcm::ast::NodeType::boolNode, sngcm::ast::NodeType::sbyteNode, sngcm::ast::NodeType::byteNode, sngcm::ast::NodeType::shortNode,
        sngcm::ast::NodeType::ushortNode, sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::uintNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // sbyte
    {
        sngcm::ast::NodeType::sbyteNode, sngcm::ast::NodeType::sbyteNode, sngcm::ast::NodeType::shortNode, sngcm::ast::NodeType::shortNode,
        sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // byte
    {
        sngcm::ast::NodeType::byteNode, sngcm::ast::NodeType::shortNode, sngcm::ast::NodeType::byteNode, sngcm::ast::NodeType::shortNode,
        sngcm::ast::NodeType::ushortNode, sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::uintNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // short
    {
        sngcm::ast::NodeType::shortNode, sngcm::ast::NodeType::shortNode, sngcm::ast::NodeType::shortNode, sngcm::ast::NodeType::shortNode,
        sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // ushort
    {
        sngcm::ast::NodeType::ushortNode, sngcm::ast::NodeType::ushortNode, sngcm::ast::NodeType::ushortNode, sngcm::ast::NodeType::intNode,
        sngcm::ast::NodeType::ushortNode, sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::uintNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // int
    {
        sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::intNode,
        sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::intNode, sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // uint
    {
        sngcm::ast::NodeType::uintNode, sngcm::ast::NodeType::uintNode, sngcm::ast::NodeType::uintNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::uintNode, sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::uintNode, sngcm::ast::NodeType::ulongNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // long
    {
        sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode, sngcm::ast::NodeType::longNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // ulong
    {
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::ulongNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::ulongNode,
        sngcm::ast::NodeType::ulongNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // float
    {
        sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::floatNode,
        sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::floatNode,
        sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::floatNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // double
    {
        sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::doubleNode,
        sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::doubleNode,
        sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::doubleNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // char
    {
        sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode, sngcm::ast::NodeType::charNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // wchar
    {
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::wcharNode,
        sngcm::ast::NodeType::wcharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // uchar
    {
        sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode,
        sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode,
        sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode,
        sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::ucharNode, sngcm::ast::NodeType::voidNode
    },
    // void
    {
        sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode,
        sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode,
        sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode,
        sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode, sngcm::ast::NodeType::voidNode
    }
};

// boolNode, sbyteNode, byteNode, shortNode, ushortNode, intNode, uintNode, longNode, ulongNode, floatNode, doubleNode, charNode, wcharNode, ucharNode, voidNode

std::vector<sngcpp::symbols::SimpleTypeSpecifier> GetSimpleTypeSpecifiers(sngcm::ast::NodeType nodeType) 
{
    std::vector<sngcpp::symbols::SimpleTypeSpecifier> specifiers;
    switch (nodeType)
    {
        case sngcm::ast::NodeType::boolNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::bool_); break;
        case sngcm::ast::NodeType::sbyteNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::short_); break;
        case sngcm::ast::NodeType::byteNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::unsigned_); specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::short_); break;
        case sngcm::ast::NodeType::shortNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::short_); break;
        case sngcm::ast::NodeType::ushortNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::unsigned_); specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::short_); break;
        case sngcm::ast::NodeType::intNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::int_); break;
        case sngcm::ast::NodeType::uintNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::unsigned_); specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::int_); break;
        case sngcm::ast::NodeType::longNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::long_); break;
        case sngcm::ast::NodeType::ulongNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::unsigned_); specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::long_); break;
        case sngcm::ast::NodeType::floatNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::float_); break;
        case sngcm::ast::NodeType::doubleNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::double_); break;
        case sngcm::ast::NodeType::charNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::char_); break;
        case sngcm::ast::NodeType::wcharNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::char16); break;
        case sngcm::ast::NodeType::ucharNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::char32); break;
        case sngcm::ast::NodeType::voidNode: specifiers.push_back(sngcpp::symbols::SimpleTypeSpecifier::void_); break;
    }
    return specifiers;
};

Converter::Converter(bool verbose_, const std::string& targetDir_, sngcpp::symbols::SymbolTable& symbolTable_, Map& map_,
    const std::set<std::u32string>& excludedClasses_, const std::set<std::u32string>& excludedFunctions_, NothrowList& nothrowList_) :
    verbose(verbose_), targetDir(targetDir_), symbolTable(symbolTable_), currentCompileUnit(nullptr), currentNamespace(nullptr), currentContext(nullptr), currentContainerNode(nullptr), map(map_),
    addToNodes(false), type(nullptr), currentClassType(nullptr), currentEnumType(nullptr), assignment(false), empty(false), inFunctionBody(false),
    assignmentStatement(false), rangeFor(false), catchDecl(false), statementContainer(StatementContainer::statements),
    calledFunction(nullptr), excludedClasses(excludedClasses_), excludedFunctions(excludedFunctions_), parentCaseStatementNode(nullptr),
    nothrowList(nothrowList_), nothrowFileItem(Item::Type::file, U"", false), nothrowClassItem(Item::Type::class_, U"", false), nothrowFunctionItem(Item::Type::function, U"", false)
{
}

void Converter::Write()
{
    for (const auto& cu : compileUnits)
    {
        sngcm::ast::CombineNamespaces(*cu);
        sngcm::ast::ArrangeClassMembers(*cu);
        InsertNamespaceImports(cu.get());
        std::ofstream sourceFile(cu->FilePath());
        soulng::util::CodeFormatter formatter(sourceFile);
        sngcm::ast::SourceWriter writer(formatter);
        cu->Accept(writer);
        std::u32string fileName = ToUtf32(Path::GetFileName(cu->FilePath()));
        sourceFiles.Add(new SourceFile(fileName, cu->FilePath()));
    }
}

void Converter::InsertNamespaceImports(sngcm::ast::CompileUnitNode* cu)
{
    Context* context = &contextMap[cu];
    int index = 0;
    for (const auto& namespaceImport : context->namespaceImports)
    {
        cu->GlobalNs()->Members().Insert(index, new sngcm::ast::NamespaceImportNode(soulng::lexer::Span(), new sngcm::ast::IdentifierNode(soulng::lexer::Span(), namespaceImport)));
        ++index;
    }
}

void Converter::AddToContainer(int line, sngcm::ast::Node* node)
{
    switch (currentContainerNode->GetNodeType())
    {
        case sngcm::ast::NodeType::namespaceNode:
        {
            sngcm::ast::NamespaceNode* ns = static_cast<sngcm::ast::NamespaceNode*>(currentContainerNode);
            ns->AddMember(node);
            break;
        }
        case sngcm::ast::NodeType::classNode:
        {
            sngcm::ast::ClassNode* cls = static_cast<sngcm::ast::ClassNode*>(currentContainerNode);
            cls->AddMember(node);
            break;
        }
        default: 
        {
            WriteWarning(line, ": converter.AddToContainer: namespace or class container expected");
            delete node;
            return;
        }
    }
}

void Converter::AddStatement(int line, sngcm::ast::StatementNode* statement)
{
    switch (statementContainer)
    {
        case StatementContainer::statements:
        {
            statementNodes.push_back(std::unique_ptr< sngcm::ast::StatementNode>(statement));
            break;
        }
        case StatementContainer::latestCase:
        {
            if (caseStatementNodes.empty())
            {
                WriteWarning(line, "no case active");
                statementNodes.push_back(std::unique_ptr< sngcm::ast::StatementNode>(statement));
            }
            else
            {
                caseStatementNodes.back()->AddStatement(statement);
            }
            break;
        }
        case StatementContainer::latestDefault:
        {
            if (!defaultStatement)
            {
                WriteWarning(line, "no default active");
                statementNodes.push_back(std::unique_ptr< sngcm::ast::StatementNode>(statement));
            }
            else
            {
                defaultStatement->AddStatement(statement);
            }
            break;
        }
    }
}

void Converter::WriteWarning(int line, const std::string& message)
{
    std::cerr << "warning: " << currentSourceFileName << ":" << line << ": " << message << std::endl;
}

void Converter::ConvertIdExpr(sngcpp::ast::Node* idExprNode)
{
    mappedSymbolSequence.clear();
    node.reset();
    idExprNode->Accept(*this);
    if (!node)
    {
        if (!mappedSymbolSequence.empty())
        {
            sngcpp::symbols::Symbol* symbol = mappedSymbolSequence.back();
            if (symbol)
            {
                if (symbol->IsParameterSymbol())
                {
                    node.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name()));
                }
                else if (symbol->IsVariableSymbol())
                {
                    node.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name()));
                }
                else if (symbol->IsEnumeratorSymbol())
                {
                    node.reset(new sngcm::ast::DotNode(soulng::lexer::Span(),
                        new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Parent()->Name()), new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name())));
                }
                else if (symbol->IsClassGroupSymbol())
                {
                    if (currentClassType)
                    {
                        sngcpp::symbols::ClassGroupSymbol* classGroupSymbol = static_cast<sngcpp::symbols::ClassGroupSymbol*>(symbol);
                        sngcpp::symbols::ClassTypeSymbol* classTypeSymbol = classGroupSymbol->GetClass(0);
                        if (currentClassType == classTypeSymbol)
                        {
                            node.reset(new sngcm::ast::ThisNode(soulng::lexer::Span()));
                        }
                        else if (currentClassType->BaseClasses().size() == 1 && currentClassType->BaseClasses().front() == classTypeSymbol)
                        {
                            node.reset(new sngcm::ast::BaseNode(soulng::lexer::Span()));
                        }
                    }
                }
                else if (symbol->IsTypeSymbol())
                {
                    sngcpp::symbols::TypeSymbol* typeSymbol = static_cast<sngcpp::symbols::TypeSymbol*>(symbol);
                    sngxml::dom::Document* sourceXmlDoc = nullptr;
                    node.reset(map.MapType(typeSymbol, sourceXmlDoc));
                    type = typeSymbol;
                }
                else
                {
                    int x = 0;
                }
            }
        }
    }
    if (!node)
    {
        NotConverted(idExprNode->GetSpan().line, "id expression not converted");
    }
}

void Converter::ConvertExpression(sngcpp::ast::Node* exprNode)
{
    mappedSymbolSequence.clear();
    node.reset();
    if (exprNode->GetNodeType() == sngcpp::ast::NodeType::expressionInitializerNode)
    {
        sngcpp::ast::ExpressionInitializerNode* initializerNode = static_cast<sngcpp::ast::ExpressionInitializerNode*>(exprNode);
        ConvertExpression(initializerNode->Child());
        return;
    }
    else if (exprNode->GetNodeType() == sngcpp::ast::NodeType::assignmentInitializerNode)
    {
        sngcpp::ast::AssignmentInitializerNode* initializerNode = static_cast<sngcpp::ast::AssignmentInitializerNode*>(exprNode);
        ConvertExpression(initializerNode->Child());
        assignment = true;
        return;
    }
    exprNode->Accept(*this);
    if (!node)
    {
        if (!mappedSymbolSequence.empty())
        {
            sngcpp::symbols::Symbol* symbol = mappedSymbolSequence.back();
            if (symbol)
            {
                if (symbol->IsParameterSymbol())
                {
                    node.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name()));
                    type = symbol->GetType();
                }
                else if (symbol->IsVariableSymbol())
                {
                    node.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name()));
                    type = symbol->GetType();
                }
                else if (symbol->IsEnumeratorSymbol())
                {
                    node.reset(new sngcm::ast::DotNode(soulng::lexer::Span(),
                        new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Parent()->Name()), new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name())));
                    type = symbol->GetType();
                }
                else if (symbol->IsFunctionGroupSymbol())
                {
                    bool mapped = false;
                    if (calledFunction)
                    {
                        node.reset(map.MapFunctionSymbol(calledFunction, args));
                        if (node)
                        {
                            mapped = true;
                            if (calledFunction->ReturnType())
                            {
                                type = calledFunction->ReturnType();
                            }
                            else
                            {
                                type = nullptr;
                            }
                        }
                    }
                    if (!mapped)
                    {
                        if (calledFunction)
                        {
                            if (calledFunction->IsFunctionSymbol())
                            {
                                sngcpp::symbols::FunctionSymbol* calledFunctionSymbol = static_cast<sngcpp::symbols::FunctionSymbol*>(calledFunction);
                                if (calledFunctionSymbol->Parent()->IsClassTypeSymbol() &&
                                    (calledFunctionSymbol->Specifiers() & sngcpp::ast::Specifier::static_) != sngcpp::ast::Specifier::none)
                                {
                                    node.reset(new sngcm::ast::DotNode(soulng::lexer::Span(),
                                        new sngcm::ast::IdentifierNode(soulng::lexer::Span(), calledFunctionSymbol->Parent()->Name()),
                                        new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name())));
                                    if (calledFunction->ReturnType())
                                    {
                                        type = calledFunction->ReturnType();
                                    }
                                    mapped = true;
                                }
                            }
                        }
                        if (!mapped)
                        {
                            node.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name()));
                            type = nullptr;
                        }
                    }
                }
                else if (symbol->IsTypeSymbol())
                {
                    sngcpp::symbols::TypeSymbol* typeSymbol = static_cast<sngcpp::symbols::TypeSymbol*>(symbol);
                    sngxml::dom::Document* sourceXmlDoc = nullptr;
                    node.reset(map.MapType(typeSymbol, sourceXmlDoc));
                    type = typeSymbol;
                }
                else if (symbol->IsClassGroupSymbol())
                {
                    sngcpp::symbols::ClassGroupSymbol* classGroupSymbol = static_cast<sngcpp::symbols::ClassGroupSymbol*>(symbol);
                    sngcpp::symbols::ClassTypeSymbol* classTypeSymbol = classGroupSymbol->GetClass(0);
                    sngxml::dom::Document* sourceXmlDoc = nullptr;
                    node.reset(map.MapType(classTypeSymbol, sourceXmlDoc));
                    type = classTypeSymbol;
                }
                else
                {
                    int x = 0;
                }
            }
        }
    }
    if (!node)
    {
        NotConverted(exprNode->GetSpan().line, "expression not converted");
    }
    if (addToNodes)
    {
        if (node->GetNodeType() != sngcm::ast::NodeType::emptyStatementNode)
        {
            nodes.Add(node.release());
        }
        node.reset(new sngcm::ast::EmptyStatementNode(soulng::lexer::Span()));
    }
}

void Converter::NotConverted(int line, const std::string& message)
{
    WriteWarning(line, message);
    node.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), U"NOT_CONVERTED"));
    type = nullptr;
}

void Converter::ConvertBooleanExpression(sngcpp::ast::Node* exprNode)
{
    ConvertExpression(exprNode);
    if (node)
    {
        sngcm::ast::NodeType nodeType = node->GetNodeType();
        sngcpp::symbols::TypeSymbol* typeToConvert = type;
        if (typeToConvert)
        {
            if (typeToConvert->IsDerivedTypeSymbol())
            {
                sngcpp::symbols::DerivedTypeSymbol* derivedType = static_cast<sngcpp::symbols::DerivedTypeSymbol*>(type);
                for (sngcpp::symbols::Derivation derivation : derivedType->Derivations())
                {
                    if (derivation == sngcpp::symbols::Derivation::ptr)
                    {
                        node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                            soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::NullLiteralNode(soulng::lexer::Span()))));
                        return;
                    }
                }
                typeToConvert = derivedType->BaseType();
            }
            if (typeToConvert->IsSimpleTypeSymbol())
            {
                nodeType = map.MapSimpleType(static_cast<sngcpp::symbols::SimpleTypeSymbol*>(typeToConvert));
            }
            else if (typeToConvert->IsClassTemplateSpecializationSymbol())
            {
                sngcpp::symbols::ClassTemplateSpecializationSymbol* specialization = static_cast<sngcpp::symbols::ClassTemplateSpecializationSymbol*>(typeToConvert);
                if (specialization->PrimaryClassTemplateSymbol()->FullName() == U"std::unique_ptr" || specialization->PrimaryClassTemplateSymbol()->FullName() == U"std::shared_ptr")
                {
                    node.reset(new sngcm::ast::NotNode(soulng::lexer::Span(),
                        new sngcm::ast::InvokeNode(soulng::lexer::Span(), new sngcm::ast::DotNode(soulng::lexer::Span(), node.release(),
                            new sngcm::ast::IdentifierNode(soulng::lexer::Span(), U"IsNull")))));
                    return;
                }
            }
        }
        switch (nodeType)
        {
            case sngcm::ast::NodeType::sbyteNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::SByteLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::byteNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::ByteLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::shortNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::ShortLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::ushortNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::UShortLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::intNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::IntLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::uintNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::UIntLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::longNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::LongLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::ulongNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::ULongLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::floatNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::FloatLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::doubleNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::DoubleLiteralNode(soulng::lexer::Span(), 0))));
                break;
            }
            case sngcm::ast::NodeType::charNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::CharLiteralNode(soulng::lexer::Span(), '\0'))));
                break;
            }
            case sngcm::ast::NodeType::wcharNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::WCharLiteralNode(soulng::lexer::Span(), '\0'))));
                break;
            }
            case sngcm::ast::NodeType::ucharNode:
            {
                node.reset(new sngcm::ast::ParenthesizedExpressionNode(
                    soulng::lexer::Span(), new sngcm::ast::NotEqualNode(soulng::lexer::Span(), node.release(), new sngcm::ast::UCharLiteralNode(soulng::lexer::Span(), '\0'))));
                break;
            }
        }
    }
}

sngcm::ast::NodeList<sngcm::ast::Node> Converter::ConvertExpressionList(sngcpp::ast::Node* expressions)
{
    if (expressions)
    {
        bool prevAddToNodes = addToNodes;
        addToNodes = true;
        sngcm::ast::NodeList<sngcm::ast::Node> prevNodes = std::move(nodes);
        if (expressions->GetNodeType() == sngcpp::ast::NodeType::expressionSequenceNode ||
            expressions->GetNodeType() == sngcpp::ast::NodeType::memberInitializerSequenceNode ||
            expressions->GetNodeType() == sngcpp::ast::NodeType::expressionListInitializerNode)
        {
            expressions->Accept(*this);
        }
        else
        {
            ConvertExpression(expressions);
        }
        sngcm::ast::NodeList<sngcm::ast::Node> convertedNodes = std::move(nodes);
        nodes = std::move(prevNodes);
        addToNodes = prevAddToNodes;
        return convertedNodes;
    }
    else
    {
        return sngcm::ast::NodeList<sngcm::ast::Node>();
    }
}

void Converter::ConvertTypeExpression(sngcpp::ast::Node* typeExprNode)
{
    mappedSymbolSequence.clear();
    node.reset();
    typeExprNode->Accept(*this);
    if (!node)
    {
        if (!mappedSymbolSequence.empty())
        {
            sngcpp::symbols::Symbol* symbol = mappedSymbolSequence.back();
            if (symbol)
            {
                if (symbol->IsClassGroupSymbol())
                {
                    sngcpp::symbols::ClassGroupSymbol* classGroup = static_cast<sngcpp::symbols::ClassGroupSymbol*>(symbol);
                    if (currentClassType && classGroup->Name() == currentClassType->Name())
                    {
                        symbol = currentClassType; 
                    }
                    else
                    {
                        symbol = classGroup->GetClass(0);
                    }
                }
                if (symbol && symbol->IsTypeSymbol())
                {
                    sngcpp::symbols::TypeSymbol* typeSymbol = static_cast<sngcpp::symbols::TypeSymbol*>(symbol);
                    sngxml::dom::Document* sourceXmlDoc = nullptr;
                    sngcm::ast::Node* typeNode = map.MapType(typeSymbol, sourceXmlDoc);
                    if (typeNode)
                    {
                        node.reset(typeNode);
                        type = typeSymbol;
                    }
                }
            }
        }
    }
    if (!node)
    {
        NotConverted(typeExprNode->GetSpan().line, "type not mapped");
    }
}

sngcpp::symbols::TypeSymbol* Converter::MakeCommonType(sngcpp::symbols::TypeSymbol* leftType, sngcpp::symbols::TypeSymbol* rightType)
{
    if (leftType == nullptr)
    {
        return rightType;
    }
    if (rightType == nullptr)
    {
        return leftType;
    }
    if (leftType == rightType)
    {
        return leftType;
    }
    if (leftType->IsSimpleTypeSymbol() && rightType->IsSimpleTypeSymbol())
    {
        sngcpp::symbols::SimpleTypeSymbol* leftSimpleType = static_cast<sngcpp::symbols::SimpleTypeSymbol*>(leftType);
        sngcpp::symbols::SimpleTypeSymbol* rightSimpleType = static_cast<sngcpp::symbols::SimpleTypeSymbol*>(rightType);
        sngcm::ast::NodeType leftNodeType = map.MapSimpleType(leftSimpleType);
        sngcm::ast::NodeType rightNodeType = map.MapSimpleType(rightSimpleType);
        sngcm::ast::NodeType commonNodeType = commonType[static_cast<int>(leftNodeType)][static_cast<int>(rightNodeType)];
        std::vector<sngcpp::symbols::SimpleTypeSpecifier> specifiers = GetSimpleTypeSpecifiers(commonNodeType);
        sngcpp::ast::SimpleTypeNode simpleTypeNode(soulng::lexer::Span(), specifiers);
        return symbolTable.MakeSimpleTypeSymbol(simpleTypeNode);
    }
    return leftType;
}

sngcpp::symbols::TypeSymbol* Converter::AddPointer(sngcpp::symbols::TypeSymbol* pointeeType)
{
    if (!pointeeType) return nullptr;
    std::vector<sngcpp::symbols::Derivation> derivations;
    if (pointeeType->IsDerivedTypeSymbol())
    {
        sngcpp::symbols::DerivedTypeSymbol* derivedType = static_cast<sngcpp::symbols::DerivedTypeSymbol*>(pointeeType);
        derivations = derivedType->Derivations();
    }
    derivations.push_back(sngcpp::symbols::Derivation::ptr);
    return symbolTable.MakeDerivedTypeSymbol(derivations, pointeeType->BaseType());
}

sngcpp::symbols::TypeSymbol* Converter::RemovePointer(sngcpp::symbols::TypeSymbol* ptrType)
{
    if (!ptrType) return nullptr;
    if (ptrType->IsDerivedTypeSymbol())
    {
        sngcpp::symbols::DerivedTypeSymbol* derivedType = static_cast<sngcpp::symbols::DerivedTypeSymbol*>(ptrType);
        std::vector<sngcpp::symbols::Derivation> derivations = derivedType->Derivations();
        int n = derivations.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (derivations[i] == sngcpp::symbols::Derivation::ptr)
            {
                derivations.erase(derivations.begin() + i);
                if (derivations.empty())
                {
                    return ptrType->BaseType();
                }
                else
                {
                    return symbolTable.MakeDerivedTypeSymbol(derivations, ptrType->BaseType());
                }
            }
        }
    }
    return ptrType;
}

sngcpp::symbols::TypeSymbol* Converter::MakeElementType(sngcpp::symbols::TypeSymbol* arrayType)
{
    // todo
    return nullptr;
}

void Converter::Visit(sngcpp::ast::BaseClassSpecifierNode& baseClassSpecifierNode)
{
    ConvertTypeExpression(baseClassSpecifierNode.ClassName());
}

void Converter::Visit(sngcpp::ast::BaseClassSpecifierSequenceNode& baseClassSpecifierSequenceNode)
{
    baseClassSpecifierSequenceNode.Left()->Accept(*this);
    baseClassSpecifierSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::ForwardClassDeclarationNode& forwardClassDeclarationNode)
{
}

void Converter::Visit(sngcpp::ast::ElaborateClassNameNode& elaborateClassNameNode)
{
    elaborateClassNameNode.ClassName()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::ClassNode& classNode)
{
    sngcpp::symbols::ClassTypeSymbol* prevClassTypeSymbol = currentClassType;
    sngcpp::symbols::ClassTypeSymbol* prevContextClassTypeSymbol = currentContext->currentClassTypeSymbol;
    sngcm::ast::Node* prevContainer = currentContainerNode;
    sngcm::ast::Node* classContainer = prevContainer;
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&classNode);
    if (symbol)
    {
        if (symbol->IsClassTypeSymbol())
        {
            sngcpp::symbols::ClassTypeSymbol* classTypeSymbol = static_cast<sngcpp::symbols::ClassTypeSymbol*>(symbol);
            nothrowClassItem = Item(Item::Type::class_, classTypeSymbol->Name(), nothrowFileItem.include);
            nothrowList.ApplyTo(nothrowClassItem);
            if (nothrowList.Verbose())
            {
                if (nothrowClassItem.include)
                {
                    std::cout << "info: " << ToUtf8(classTypeSymbol->Name()) << ": nothrow=true" << std::endl;
                }
                else
                {
                    std::cout << "info: " << ToUtf8(classTypeSymbol->Name()) << ": nothrow=false" << std::endl;
                }
            }
            if (excludedClasses.find(classTypeSymbol->FullName()) != excludedClasses.cend())
            {
                if (verbose)
                {
                    std::cout << "info: class " << ToUtf8(classTypeSymbol->FullName()) << " excluded" << std::endl;
                }
            }
            else
            {
                currentClassType = classTypeSymbol;
                currentContext->currentClassTypeSymbol = classTypeSymbol;
                auto it = currentContext->containerMap.find(classTypeSymbol->Parent());
                if (it != currentContext->containerMap.cend())
                {
                    classContainer = it->second;
                    currentContext->currentContainerNode = classContainer;
                }
                cls.reset(new sngcm::ast::ClassNode(soulng::lexer::Span(), MapSpecifiers(classNode.ClassVirtSpecifiers()) | MapAccess(classTypeSymbol->Access()),
                    new sngcm::ast::IdentifierNode(soulng::lexer::Span(), classTypeSymbol->Name()), nullptr));
                classMap[classTypeSymbol] = cls.get();
                if (classTypeSymbol->IsAbstract())
                {
                    cls->SetSpecifiers(cls->GetSpecifiers() | sngcm::ast::Specifiers::abstract_);
                }
                if (!templateParameterNodes.empty())
                {
                    for (auto& templateParameterNode : templateParameterNodes)
                    {
                        cls->AddTemplateParameter(templateParameterNode.release());
                    }
                }
                currentContainerNode = cls.get();
                currentContext->containerMap[classTypeSymbol] = currentContainerNode;
                for (const auto& baseClass : classTypeSymbol->BaseClasses())
                {
                    if (baseClass->IsClassTypeSymbol())
                    {
                        if (cls->BaseClassOrInterfaces().Count() == 0)
                        {
                            sngcpp::symbols::ClassTypeSymbol* baseClassType = static_cast<sngcpp::symbols::ClassTypeSymbol*>(baseClass);
                            sngxml::dom::Document* sourceXmlDoc = nullptr;
                            std::unique_ptr<sngcm::ast::Node> typeNode;
                            typeNode.reset(map.MapType(baseClassType, sourceXmlDoc));
                            if (!typeNode)
                            {
                                NotConverted(classNode.GetSpan().line, "base class not converted");
                                typeNode.reset(node.release());
                            }
                            cls->AddBaseClassOrInterface(typeNode.release());
                        }
                        else
                        {
                            NotConverted(classNode.GetSpan().line, "base class not converted");
                        }
                    }
                    else
                    {
                        NotConverted(classNode.GetSpan().line, "base class not converted");
                    }
                }
                classNode.Declarations()->Accept(*this);
                currentContainerNode = classContainer;
                AddToContainer(classNode.GetSpan().line, cls.release());
            }
            currentContainerNode = prevContainer;
        }
        else
        {
            currentContainerNode = prevContainer;
            NotConverted(classNode.GetSpan().line, "class not converted");
        }
    }
    else
    {
        currentContainerNode = prevContainer;
        NotConverted(classNode.GetSpan().line, "class not converted");
    }
    currentClassType = prevClassTypeSymbol;
    currentContext->currentClassTypeSymbol = prevContextClassTypeSymbol;
}

void Converter::Visit(sngcpp::ast::MemberAccessDeclarationNode& memberAccessDeclarationNode)
{
    memberAccessDeclarationNode.Declaration()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::MemberDeclarationNode& memberDeclarationNode)
{
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&memberDeclarationNode);
    if (symbol)
    {
        if (symbol->IsVariableSymbol())
        {
            sngcpp::symbols::VariableSymbol* variableSymbol = static_cast<sngcpp::symbols::VariableSymbol*>(symbol);
            sngcpp::symbols::TypeSymbol* typeSymbol = variableSymbol->GetType();
            sngxml::dom::Document* sourceXmlDoc = nullptr;
            std::unique_ptr<sngcm::ast::Node> typeNode(map.MapType(typeSymbol, sourceXmlDoc));
            if (!typeNode)
            {
                NotConverted(memberDeclarationNode.GetSpan().line, "type not converted");
                typeNode.reset(node.release());
            }
            if (variableSymbol->Parent()->IsClassTypeSymbol())
            {
                node.reset(new sngcm::ast::MemberVariableNode(soulng::lexer::Span(), MapSpecifiers(variableSymbol->Specifiers()) | MapAccess(variableSymbol->Access()), typeNode.release(),
                    new sngcm::ast::IdentifierNode(soulng::lexer::Span(), variableSymbol->Name()), nullptr));
            }
            else
            {
                node.reset(new sngcm::ast::GlobalVariableNode(soulng::lexer::Span(), MapSpecifiers(variableSymbol->Specifiers()) | MapAccess(variableSymbol->Access()), typeNode.release(),
                    new sngcm::ast::IdentifierNode(soulng::lexer::Span(), variableSymbol->Name()), currentCompileUnit));
            }
        }
        sngcm::ast::Node* prevContainer = currentContainerNode;
        sngcm::ast::Node* variableContainer = currentContainerNode;
        auto it = currentContext->containerMap.find(symbol->Parent());
        if (it != currentContext->containerMap.cend())
        {
            variableContainer = it->second;
            currentContainerNode = variableContainer;
        }
        currentContainerNode = variableContainer;
        AddToContainer(memberDeclarationNode.GetSpan().line, node.release());
        currentContainerNode = prevContainer;
    }
    else
    {
        mappedSymbolSequence.clear();
        memberDeclarationNode.Declarator()->Accept(*this);
        if (!mappedSymbolSequence.empty())
        {
            sngcpp::symbols::Symbol* symbol = mappedSymbolSequence.back();
            if (symbol->IsFunctionSymbol())
            {
                sngcpp::symbols::FunctionSymbol* functionSymbol = static_cast<sngcpp::symbols::FunctionSymbol*>(symbol);
                if ((functionSymbol->Specifiers() & sngcpp::symbols::Specifier::pure_) != sngcpp::symbols::Specifier::none)
                {
                    sngcpp::symbols::TypeSymbol* returnTypeSymbol = functionSymbol->ReturnType();
                    sngxml::dom::Document* sourceXmlDoc = nullptr;
                    std::unique_ptr<sngcm::ast::Node> returnTypeNode(map.MapType(returnTypeSymbol, sourceXmlDoc));
                    if (!returnTypeNode)
                    {
                        NotConverted(memberDeclarationNode.GetSpan().line, "type not converted");
                        returnTypeNode.reset(node.release());
                    }
                    sngcm::ast::Specifiers functionSpecifiers = MapSpecifiers(functionSymbol->Specifiers());
                    functionSpecifiers = functionSpecifiers | MapAccess(functionSymbol->Access());
                    sngcm::ast::MemberFunctionNode* memberFunctionNode = new sngcm::ast::MemberFunctionNode(soulng::lexer::Span(), functionSpecifiers, returnTypeNode.release(),
                        functionSymbol->GroupName(), nullptr);
                    for (auto& parameterNode : parameterNodes)
                    {
                        memberFunctionNode->AddParameter(parameterNode.release());
                    }
                    AddToContainer(memberDeclarationNode.GetSpan().line, memberFunctionNode);
                }
            }
        }
    }
}

void Converter::Visit(sngcpp::ast::SpecialMemberFunctionNode& specialMemberFunctionNode)
{
    Item prevClassItem = nothrowClassItem;
    sngcpp::symbols::ClassTypeSymbol* prevClassType = currentClassType;
    sngcm::ast::Node* prevContainer = currentContainerNode;
    sngcm::ast::Node* memberFunctionContainer = prevContainer;
    sngcm::ast::Specifiers memberFunctionSpecifiers = MapSpecifiers(specialMemberFunctionNode.Specifiers());
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&specialMemberFunctionNode);
    mappedSymbolSequence.clear();
    specialMemberFunctionNode.Declarator()->Accept(*this);
    if (mappedSymbolSequence.empty())
    {
        WriteWarning(specialMemberFunctionNode.GetSpan().line, "constructor/destructor name not mapped");
    }
    if (!symbol)
    {
        symbol = mappedSymbolSequence.back();
    }
    if (symbol)
    {
        bool found = false;
        if (symbol->Parent()->IsClassTypeSymbol())
        {
            sngcpp::symbols::ClassTypeSymbol* cls = static_cast<sngcpp::symbols::ClassTypeSymbol*>(symbol->Parent());
            nothrowClassItem = Item(Item::Type::class_, cls->Name(), nothrowFileItem.include);
            nothrowList.ApplyTo(nothrowClassItem);
            if (nothrowList.Verbose())
            {
                if (nothrowClassItem.include)
                {
                    std::cout << "info: " << ToUtf8(cls->Name()) << ": nothrow=true" << std::endl;
                }
                else
                {
                    std::cout << "info: " << ToUtf8(cls->Name()) << ": nothrow=false" << std::endl;
                }
            }
            nothrowFunctionItem = Item(Item::Type::function, symbol->Name(), nothrowClassItem.include);
            auto cit = classMap.find(cls);
            if (cit != classMap.end())
            {
                memberFunctionContainer = cit->second;
                currentContainerNode = memberFunctionContainer;
                found = true;
            }
        }
        if (!found)
        {
            nothrowFunctionItem = Item(Item::Type::function, symbol->Name(), false);
            auto it = currentContext->containerMap.find(symbol->Parent());
            if (it != currentContext->containerMap.cend())
            {
                memberFunctionContainer = it->second;
                currentContainerNode = memberFunctionContainer;
            }
        }
        if (symbol->IsConstructorSymbol())
        {
            sngcpp::symbols::ConstructorSymbol* constructorSymbol = static_cast<sngcpp::symbols::ConstructorSymbol*>(symbol);
            memberFunctionSpecifiers = memberFunctionSpecifiers | MapSpecifiers(constructorSymbol->Specifiers()) | MapAccess(symbol->Access());
            nothrowList.ApplyTo(nothrowFunctionItem);
            if (nothrowFunctionItem.include)
            {
                memberFunctionSpecifiers = memberFunctionSpecifiers | sngcm::ast::Specifiers::nothrow_;
            }
            node.reset(new sngcm::ast::ConstructorNode(soulng::lexer::Span(), memberFunctionSpecifiers, nullptr));
        }
        else if (symbol->IsDestructorSymbol())
        {
            sngcpp::symbols::DestructorSymbol* destructorSymbol = static_cast<sngcpp::symbols::DestructorSymbol*>(symbol);
            memberFunctionSpecifiers = memberFunctionSpecifiers | MapSpecifiers(destructorSymbol->Specifiers()) | MapAccess(symbol->Access());
            nothrowList.ApplyTo(nothrowFunctionItem);
            node.reset(new sngcm::ast::DestructorNode(soulng::lexer::Span(), memberFunctionSpecifiers, nullptr));
        }
        else
        {
            currentContainerNode = prevContainer;
            currentClassType = prevClassType;
            WriteWarning(specialMemberFunctionNode.GetSpan().line, "constructor/destructor not created");
            return;
        }
        if (nothrowList.Verbose())
        {
            if (nothrowFunctionItem.include)
            {
                std::cout << "info: " << ToUtf8(symbol->Name()) << ": nothrow=true" << std::endl;
            }
            else
            {
                std::cout << "info: " << ToUtf8(symbol->Name()) << ": nothrow=false" << std::endl;
            }
        }
        std::unique_ptr<sngcm::ast::FunctionNode> functionNode(static_cast<sngcm::ast::FunctionNode*>(node.release()));
        sngcm::ast::ConstructorNode* constructorNode = nullptr;
        if (symbol->IsConstructorSymbol())
        {
            constructorNode = static_cast<sngcm::ast::ConstructorNode*>(functionNode.get());
            constructorNode->SetClassId(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Parent()->Name()));
            for (auto& parameterNode : parameterNodes)
            {
                constructorNode->AddParameter(parameterNode.release());
            }
        }
        else if (symbol->IsDestructorSymbol())
        {
            sngcm::ast::DestructorNode* destructorNode = static_cast<sngcm::ast::DestructorNode*>(functionNode.get());
            destructorNode->SetClassId(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Parent()->Name()));
        }
        if (!currentClassType && symbol->Parent()->IsClassTypeSymbol())
        {
            currentClassType = static_cast<sngcpp::symbols::ClassTypeSymbol*>(symbol->Parent());
        }
        if (specialMemberFunctionNode.CtorInitializer() && constructorNode)
        {
            specialMemberFunctionNode.CtorInitializer()->Accept(*this);
            int n = nodes.Count();
            for (int i = 0; i < n; ++i)
            {
                constructorNode->AddInitializer(static_cast<sngcm::ast::InitializerNode*>(nodes.Release(i)));
            }
        }
        if (specialMemberFunctionNode.FunctionBody())
        {
            statementNodes.clear();
            bool prevFunctionBody = inFunctionBody;
            inFunctionBody = true;
            specialMemberFunctionNode.FunctionBody()->Accept(*this);
            inFunctionBody = prevFunctionBody;
            if (statementNodes.size() == 1)
            {
                functionNode->SetBody(static_cast<sngcm::ast::CompoundStatementNode*>(statementNodes.front().release()));
            }
            else
            {
                WriteWarning(specialMemberFunctionNode.GetSpan().line, "function body expected");
            }
        }
        currentContainerNode = memberFunctionContainer;
        AddToContainer(specialMemberFunctionNode.GetSpan().line, functionNode.release());
    }
    currentContainerNode = prevContainer;
    currentClassType = prevClassType;
    nothrowClassItem = prevClassItem;
}

void Converter::Visit(sngcpp::ast::CtorInitializerNode& ctorInitializerNode)
{
    sngcm::ast::NodeList<sngcm::ast::Node> initializers = ConvertExpressionList(ctorInitializerNode.Child());
    nodes.Clear();
    int n = initializers.Count();
    for (int i = 0; i < n; ++i)
    {
        nodes.Add(initializers.Release(i));
    }
}

void Converter::Visit(sngcpp::ast::MemberInitializerNode& memberInitializerNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertIdExpr(memberInitializerNode.Id());
    std::unique_ptr<sngcm::ast::Node> inode = std::move(node);
    sngcm::ast::NodeList<sngcm::ast::Node> args = ConvertExpressionList(memberInitializerNode.Initializer());
    sngcm::ast::InitializerNode* initializer = nullptr;
    if (inode->GetNodeType() == sngcm::ast::NodeType::baseNode)
    {
        initializer = new sngcm::ast::BaseInitializerNode(soulng::lexer::Span());
    }
    else if (inode->GetNodeType() == sngcm::ast::NodeType::identifierNode)
    {
        initializer = new sngcm::ast::MemberInitializerNode(soulng::lexer::Span(), static_cast<sngcm::ast::IdentifierNode*>(inode.release()));
    }
    if (initializer)
    {
        int n = args.Count();
        for (int i = 0; i < n; ++i)
        {
            initializer->AddArgument(args.Release(i));
        }
    }
    node.reset(initializer);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::MemberInitializerSequenceNode& memberInitializerSequenceNode)
{
    ConvertExpression(memberInitializerSequenceNode.Left());
    ConvertExpression(memberInitializerSequenceNode.Right());
}

void Converter::Visit(sngcpp::ast::SourceFileNode& sourceFileNode)
{
    std::string sourceFileName = Path::GetFileNameWithoutExtension(sourceFileNode.SourceFilePath());
    currentSourceFileName = Path::GetFileName(sourceFileNode.SourceFilePath());
    nothrowFileItem = Item(Item::Type::file, ToUtf32(currentSourceFileName), false);
    nothrowList.ApplyTo(nothrowFileItem);
    if (nothrowList.Verbose())
    {
        if (nothrowFileItem.include)
        {
            std::cout << "info: " << currentSourceFileName << ": nothrow=true" << std::endl;
        }
        else
        {
            std::cout << "info: " << currentSourceFileName << ": nothrow=false" << std::endl;
        }
    }
    sourceFileName.append(".cm");
    auto it = compileUnitMap.find(sourceFileName);
    if (it == compileUnitMap.cend())
    {
        std::string sourceFilePath = GetFullPath(Path::Combine(targetDir, sourceFileName));
        currentCompileUnit = new sngcm::ast::CompileUnitNode(Span(), sourceFilePath);
        std::string comment = "this file has been semiautomatically generated from '" + sourceFileNode.SourceFilePath() + "' using cpp2cm version " + Cpp2CmVersion();
        currentCompileUnit->GlobalNs()->Members().Insert(0, new sngcm::ast::CommentNode(soulng::lexer::Span(), ToUtf32(comment)));
        currentContext = &contextMap[currentCompileUnit];
        map.SetCurrentContext(currentContext);
        compileUnits.push_back(std::unique_ptr<sngcm::ast::CompileUnitNode>(currentCompileUnit));
        compileUnitMap[sourceFileName] = currentCompileUnit;
    }
    else
    {
        currentCompileUnit = it->second;
        std::string comment = "this file has been semiautomatically generated from '" + sourceFileNode.SourceFilePath() + "' using cpp2cm version " + Cpp2CmVersion();
        currentCompileUnit->GlobalNs()->Members().Insert(1, new sngcm::ast::CommentNode(soulng::lexer::Span(), ToUtf32(comment)));
        currentContext = &contextMap[currentCompileUnit];
        map.SetCurrentContext(currentContext);
    }
    map.ClearNamespaceImports();
    sourceFileNode.GlobalNs()->Accept(*this);
    for (const auto& namespaceImport : map.NamespaceImports())
    {
        currentContext->namespaceImports.insert(namespaceImport);
    }
}

void Converter::Visit(sngcpp::ast::SourceFileSequenceNode& sourceFileSequenceNode)
{
    sourceFileSequenceNode.Left()->Accept(*this);
    sourceFileSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::SimpleDeclarationNode& simpleDeclarationNode)
{
    if (simpleDeclarationNode.Declarator()->IsFunctionDeclaratorNode()) return;
    bool converted = false;
    bool prevAssignment = assignment;
    bool prevEmpty = empty;
    assignment = false;
    empty = false;
    if (!inFunctionBody)
    {
        sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&simpleDeclarationNode);
        if (symbol && symbol->IsVariableSymbol())
        {
            sngcpp::symbols::VariableSymbol* variableSymbol = static_cast<sngcpp::symbols::VariableSymbol*>(symbol);
            sngcpp::symbols::TypeSymbol* type = variableSymbol->GetType();
            if (type->IsDerivedTypeSymbol() && type->BaseType()->IsSimpleTypeSymbol())
            {
                sngcpp::symbols::DerivedTypeSymbol* derivedType = static_cast<sngcpp::symbols::DerivedTypeSymbol*>(type);
                if (derivedType->Derivations().size() == 2 &&
                    derivedType->Derivations().front() == sngcpp::symbols::Derivation::const_ &&
                    derivedType->Derivations().back() == sngcpp::symbols::Derivation::base)
                {
                    std::unique_ptr<sngcm::ast::Node> typeNode;
                    sngxml::dom::Document* sourceXmlDoc = nullptr;
                    typeNode.reset(map.MapType(type->BaseType(), sourceXmlDoc));
                    if (typeNode)
                    {
                        std::unique_ptr<sngcm::ast::Node> valueNode;
                        simpleDeclarationNode.Declarator()->Accept(*this);
                        if (assignment)
                        {
                            valueNode.reset(initializer.release());
                        }
                        if (valueNode)
                        {
                            node.reset(new sngcm::ast::ConstantNode(soulng::lexer::Span(), MapSpecifiers(simpleDeclarationNode.Specifiers()) | MapAccess(variableSymbol->Access()),
                                typeNode.release(), new sngcm::ast::IdentifierNode(soulng::lexer::Span(), variableSymbol->Name()),
                                valueNode.release()));
                            AddToContainer(simpleDeclarationNode.GetSpan().line, node.release());
                            converted = true;
                        }
                    }
                }
            }
        }
    }
    if (!converted)
    {
        ConvertTypeExpression(simpleDeclarationNode.TypeExpr());
        std::unique_ptr<sngcm::ast::Node> typeNode = std::move(node);
        sngcpp::symbols::TypeSymbol* typeSymbol = type;
        nodes.Clear();
        if (simpleDeclarationNode.Declarator())
        {
            simpleDeclarationNode.Declarator()->Accept(*this);
        }
        if (!declarator && !mappedSymbolSequence.empty())
        {
            sngcpp::symbols::Symbol* symbol = mappedSymbolSequence.back();
            if (symbol)
            {
                declarator.reset(new sngcm::ast::IdentifierNode(soulng::lexer::Span(), symbol->Name()));
                empty = true;
            }
        }
        if (catchDecl)
        {
            catchType.reset(typeNode.release());
            catchId.reset(static_cast<sngcm::ast::IdentifierNode*>(declarator.release()));
            converted = true;
        }
        if (typeNode && declarator && declarator->GetNodeType() == sngcm::ast::NodeType::identifierNode)
        {
            if (inFunctionBody)
            {
                if (rangeFor)
                {
                    rangeForType.reset(typeNode.release());
                    rangeForId.reset(static_cast<sngcm::ast::IdentifierNode*>(declarator.release()));
                    converted = true;
                }
                else
                {
                    sngcm::ast::ConstructionStatementNode* constructionStatement = new sngcm::ast::ConstructionStatementNode(soulng::lexer::Span(), typeNode.release(),
                        static_cast<sngcm::ast::IdentifierNode*>(declarator.release()));
                    if (assignment)
                    {
                        if (initializer)
                        {
                            constructionStatement->AddArgument(initializer.release());
                            constructionStatement->SetAssignment();
                        }
                        else
                        {
                            WriteWarning(simpleDeclarationNode.GetSpan().line, "assignment flag set for simple declaration with no initializer");
                        }
                    }
                    else
                    {
                        int n = nodes.Count();
                        for (int i = 0; i < n; ++i)
                        {
                            constructionStatement->AddArgument(nodes.Release(i));
                        }
                        if (empty)
                        {
                            if (n == 0)
                            {
                                constructionStatement->SetEmpty();
                            }
                            else
                            {
                                WriteWarning(simpleDeclarationNode.GetSpan().line, "empty flag set for simple declaration conflicts with number of arguments (" + std::to_string(n) + ")");
                            }
                        }
                    }
                    AddStatement(simpleDeclarationNode.GetSpan().line, constructionStatement);
                    converted = true;
                }
            }
        }
        else if (!converted && inFunctionBody && typeNode)
        {
            sngcm::ast::ConstructionStatementNode* constructionStatement = new sngcm::ast::ConstructionStatementNode(soulng::lexer::Span(), typeNode.release(),
                new sngcm::ast::IdentifierNode(soulng::lexer::Span(), U"NOT_CONVERTED"));
            AddStatement(simpleDeclarationNode.GetSpan().line, constructionStatement);
            converted = true;
        }
    }
    if (!converted)
    {
        NotConverted(simpleDeclarationNode.GetSpan().line, "simple declaration not converted");
    }
    assignment = prevAssignment;
    empty = prevEmpty;
}

void Converter::Visit(sngcpp::ast::AliasDeclarationNode& aliasDeclarationNode)
{
    NotConverted(aliasDeclarationNode.GetSpan().line, "alias declaration not converted");
}

void Converter::Visit(sngcpp::ast::UsingDirectiveNode& usingDirectiveNode)
{
    NotConverted(usingDirectiveNode.GetSpan().line, "using directive not converted");
}

void Converter::Visit(sngcpp::ast::UsingDeclarationNode& usingDeclarationNode)
{
    NotConverted(usingDeclarationNode.GetSpan().line, "using declaration not converted");
}

void Converter::Visit(sngcpp::ast::TypedefNode& typedefNode)
{
    NotConverted(typedefNode.GetSpan().line, "typedef not converted");
}

void Converter::Visit(sngcpp::ast::DeclarationSequenceNode& declarationSequenceNode)
{
    declarationSequenceNode.Left()->Accept(*this);
    declarationSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::LinkageSpecificationNode& linkageSpecificationNode)
{
    NotConverted(linkageSpecificationNode.GetSpan().line, "linkage specification not converted");
}

void Converter::Visit(sngcpp::ast::IdDeclaratorNode& idDeclaratorNode)
{
    mappedSymbolSequence.clear();
    idDeclaratorNode.IdNode()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::ArrayDeclaratorNode& arrayDeclaratorNode)
{
    NotConverted(arrayDeclaratorNode.GetSpan().line, "array declarator not converted");
}

void Converter::Visit(sngcpp::ast::FunctionDeclaratorNode& functionDeclaratorNode)
{
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&functionDeclaratorNode);
    if (symbol)
    {
        if (symbol->IsCallableSymbol())
        {
            sngcpp::symbols::CallableSymbol* functionSymbol = static_cast<sngcpp::symbols::CallableSymbol*>(symbol);
            parameterNodes.clear();
            for (sngcpp::symbols::ParameterSymbol* parameterSymbol : functionSymbol->Parameters())
            {
                sngxml::dom::Document* sourceXmlDoc = nullptr;
                std::unique_ptr<sngcm::ast::Node> typeNode(map.MapType(parameterSymbol->GetType(), sourceXmlDoc));
                if (!typeNode)
                {
                    NotConverted(functionDeclaratorNode.GetSpan().line, "type not converted");
                    typeNode.reset(node.release());
                }
                sngcm::ast::IdentifierNode* idNode = new sngcm::ast::IdentifierNode(soulng::lexer::Span(), parameterSymbol->Name());
                std::unique_ptr<sngcm::ast::ParameterNode> paramNode(new sngcm::ast::ParameterNode(soulng::lexer::Span(), typeNode.release(), idNode));
                parameterNodes.push_back(std::move(paramNode));
            }
            mappedSymbolSequence.push_back(functionSymbol);
            return;
        }
    }
    functionDeclaratorNode.Declarator()->Accept(*this);
    parameterNodes.clear();
    if (functionDeclaratorNode.Parameters())
    {
        functionDeclaratorNode.Parameters()->Accept(*this);
    }
}

void Converter::Visit(sngcpp::ast::FunctionPtrIdNode& functionPtrIdNode)
{
    NotConverted(functionPtrIdNode.GetSpan().line, "function ptr id not converted");
    // todo
    int x = 0;
}

void Converter::Visit(sngcpp::ast::MemberFunctionPtrIdNode& memberFunctionPtrIdNode)
{
    NotConverted(memberFunctionPtrIdNode.GetSpan().line, "member function ptr id not converted");
    // todo
    int x = 0;
}

void Converter::Visit(sngcpp::ast::InitDeclaratorNode& initDeclaratorNode)
{
    declarator.reset();
    ConvertExpression(initDeclaratorNode.Declarator());
    declarator = std::move(node);
    initializer.reset();
    if (initDeclaratorNode.Initializer())
    {
        ConvertExpression(initDeclaratorNode.Initializer());
        initializer = std::move(node);
    }
    else
    {
        empty = true;
    }
}

void Converter::Visit(sngcpp::ast::AssignmentInitializerNode& assignmentInitializerNode)
{
    assignmentInitializerNode.Child()->Accept(*this);
    nodes.Clear();
    nodes.Add(node.release());
    assignment = true;
}

void Converter::Visit(sngcpp::ast::ExpressionListInitializerNode& expressionListInitializerNode)
{
    sngcm::ast::NodeList<sngcm::ast::Node> initializers = ConvertExpressionList(expressionListInitializerNode.Child());
    nodes.Clear();
    int n = initializers.Count();
    for (int i = 0; i < n; ++i)
    {
        nodes.Add(initializers.Release(i));
    }
}

void Converter::Visit(sngcpp::ast::ExpressionInitializerNode& expressionInitializerNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(expressionInitializerNode.Child());
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::BracedInitializerListNode& bracedInitializerListNode)
{
    sngcm::ast::NodeList<sngcm::ast::Node> initializers = ConvertExpressionList(bracedInitializerListNode.Child());
    nodes.Clear();
    int n = initializers.Count();
    for (int i = 0; i < n; ++i)
    {
        nodes.Add(initializers.Release(i));
    }
}

void Converter::Visit(sngcpp::ast::EnumTypeNode& enumTypeNode)
{
    sngcm::ast::EnumTypeNode* prevEnumType = currentEnumType;
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&enumTypeNode);
    if (symbol && symbol->IsEnumTypeSymbol())
    {
        sngcpp::symbols::EnumTypeSymbol* enumTypeSymbol = static_cast<sngcpp::symbols::EnumTypeSymbol*>(symbol);
        sngcm::ast::Specifiers enumTypeSpecifiers = sngcm::ast::Specifiers::none;
        std::unique_ptr<sngcm::ast::EnumTypeNode> enumeratedTypeNode(new sngcm::ast::EnumTypeNode(soulng::lexer::Span(), enumTypeSpecifiers | MapAccess(enumTypeSymbol->Access()),
            new sngcm::ast::IdentifierNode(soulng::lexer::Span(), enumTypeSymbol->Name())));
        if (enumTypeSymbol->BaseType())
        {
            sngxml::dom::Document* sourceXmlDoc = nullptr;
            std::unique_ptr<sngcm::ast::Node> typeNode(map.MapType(enumTypeSymbol->BaseType(), sourceXmlDoc));
            if (!typeNode)
            {
                NotConverted(enumTypeNode.GetSpan().line, "enum type underlying type not converted");
                typeNode.reset(node.release());
            }
            enumeratedTypeNode->SetUnderlyingType(typeNode.release());
        }
        currentEnumType = enumeratedTypeNode.get();
        enumTypeNode.Enumerators()->Accept(*this);
        AddToContainer(enumTypeNode.GetSpan().line, enumeratedTypeNode.release());
    }
    else
    {
        NotConverted(enumTypeNode.GetSpan().line, "enum type not converted");
    }
    currentEnumType = prevEnumType;
}

void Converter::Visit(sngcpp::ast::EnumeratorNode& enumeratorNode)
{
    bool hasValue = false;
    std::unique_ptr<sngcm::ast::Node> value;
    if (enumeratorNode.Value())
    {
        ConvertExpression(enumeratorNode.Value());
        value.reset(node.release());
        hasValue = true;
    }
    std::unique_ptr<sngcm::ast::EnumConstantNode> enumConstant(new sngcm::ast::EnumConstantNode(soulng::lexer::Span(), new sngcm::ast::IdentifierNode(soulng::lexer::Span(),
        enumeratorNode.Enumerator()), value.release()));
    if (hasValue)
    {
        enumConstant->SetHasValue();
    }
    currentEnumType->AddConstant(enumConstant.release());
}

void Converter::Visit(sngcpp::ast::EnumeratorSequenceNode& enumeratorSequenceNode)
{
    enumeratorSequenceNode.Left()->Accept(*this);
    enumeratorSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::ExpressionSequenceNode& expressionSequenceNode)
{
    ConvertExpression(expressionSequenceNode.Left());
    ConvertExpression(expressionSequenceNode.Right());
}

void Converter::Visit(sngcpp::ast::CommaExpressionNode& commaExpressionNode)
{
    NotConverted(commaExpressionNode.GetSpan().line, "comma expression not converted");
    // todo
    int x = 0;
}

void Converter::Visit(sngcpp::ast::AssignmentExpressionNode& assignmentExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(assignmentExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> target = std::move(node);
    ConvertExpression(assignmentExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    ConvertExpression(assignmentExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    std::unique_ptr<sngcm::ast::Node> source;
    switch (assignmentExpressionNode.Op())
    {
        case sngcpp::ast::Operator::assign: source.reset(right.release()); break;
        case sngcpp::ast::Operator::mulAssign: source.reset(new sngcm::ast::MulNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::divAssign: source.reset(new sngcm::ast::DivNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::remAssign: source.reset(new sngcm::ast::RemNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::addAssign: source.reset(new sngcm::ast::AddNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::subAssign: source.reset(new sngcm::ast::SubNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::shiftRightAssign: source.reset(new sngcm::ast::ShiftRightNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::shiftLeftAssign: source.reset(new sngcm::ast::ShiftLeftNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::andAssign: source.reset(new sngcm::ast::BitAndNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::xorAssign: source.reset(new sngcm::ast::BitXorNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::orAssign: source.reset(new sngcm::ast::BitOrNode(soulng::lexer::Span(), left.release(), right.release())); break;
        default:
        {
            NotConverted(assignmentExpressionNode.GetSpan().line, "assignment operator expected");
        }
    }
    sngcm::ast::AssignmentStatementNode* stmt = new sngcm::ast::AssignmentStatementNode(soulng::lexer::Span(), target.release(), source.release());
    AddStatement(assignmentExpressionNode.GetSpan().line, stmt);
    node.reset(new sngcm::ast::EmptyStatementNode(soulng::lexer::Span()));
    assignmentStatement = true;
    type = nullptr;
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::ConditionalExpressionNode& conditionalExpressionNode)
{
    NotConverted(conditionalExpressionNode.GetSpan().line, "conditional expression not converted");
    // todo
    int x = 0;
}

void Converter::Visit(sngcpp::ast::ThrowExpressionNode& throwExpressionNode)
{
    std::unique_ptr<sngcm::ast::Node> exception;
    if (throwExpressionNode.Child())
    {
        ConvertExpression(throwExpressionNode.Child());
        exception.reset(node.release());
    }
    AddStatement(throwExpressionNode.GetSpan().line, new sngcm::ast::ThrowStatementNode(soulng::lexer::Span(), exception.release()));
    node.reset(new sngcm::ast::EmptyStatementNode(soulng::lexer::Span()));
    type = nullptr;
}

void Converter::Visit(sngcpp::ast::LogicalOrExpressionNode& logicalOrExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertBooleanExpression(logicalOrExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    ConvertBooleanExpression(logicalOrExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    node.reset(new sngcm::ast::DisjunctionNode(soulng::lexer::Span(), left.release(), right.release()));
    type = symbolTable.GetBoolType();
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::LogicalAndExpressionNode& logicalAndExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertBooleanExpression(logicalAndExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    ConvertBooleanExpression(logicalAndExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    node.reset(new sngcm::ast::ConjunctionNode(soulng::lexer::Span(), left.release(), right.release()));
    type = symbolTable.GetBoolType();
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::InclusiveOrExpressionNode& inclusiveOrExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(inclusiveOrExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    sngcpp::symbols::TypeSymbol* leftType = type;
    ConvertExpression(inclusiveOrExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    sngcpp::symbols::TypeSymbol* rightType = type;
    node.reset(new sngcm::ast::BitOrNode(soulng::lexer::Span(), left.release(), right.release()));
    type = MakeCommonType(leftType, rightType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::ExclusiveOrExpressionNode& exclusiveOrExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(exclusiveOrExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    sngcpp::symbols::TypeSymbol* leftType = type;
    ConvertExpression(exclusiveOrExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    sngcpp::symbols::TypeSymbol* rightType = type;
    node.reset(new sngcm::ast::BitXorNode(soulng::lexer::Span(), left.release(), right.release()));
    type = MakeCommonType(leftType, rightType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::AndExpressionNode& andExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(andExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    sngcpp::symbols::TypeSymbol* leftType = type;
    ConvertExpression(andExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    sngcpp::symbols::TypeSymbol* rightType = type;
    node.reset(new sngcm::ast::BitAndNode(soulng::lexer::Span(), left.release(), right.release()));
    type = MakeCommonType(leftType, rightType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::EqualityExpressionNode& equalityExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(equalityExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    ConvertExpression(equalityExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    switch (equalityExpressionNode.Op())
    {
        case sngcpp::ast::Operator::equal: node.reset(new sngcm::ast::EqualNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::notEqual : node.reset(new sngcm::ast::NotEqualNode(soulng::lexer::Span(), left.release(), right.release())); break;
        default:
        {
            WriteWarning(equalityExpressionNode.GetSpan().line, "equality operator expected");
            node.reset();
            break;
        }
    }
    type = symbolTable.GetBoolType();
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::RelationalExpressionNode& relationalExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(relationalExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    ConvertExpression(relationalExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    switch (relationalExpressionNode.Op())
    {
        case sngcpp::ast::Operator::less: node.reset(new sngcm::ast::LessNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::greater: node.reset(new sngcm::ast::GreaterNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::lessOrEqual: node.reset(new sngcm::ast::LessOrEqualNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::greaterOrEqual: node.reset(new sngcm::ast::GreaterOrEqualNode(soulng::lexer::Span(), left.release(), right.release())); break;
        default:
        {
            WriteWarning(relationalExpressionNode.GetSpan().line, "relational operator expected");
            node.reset();
            break;
        }
    }
    type = symbolTable.GetBoolType();
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::ShiftExpressionNode& shiftExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(shiftExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    sngcpp::symbols::TypeSymbol* leftType = type;
    ConvertExpression(shiftExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    sngcpp::symbols::TypeSymbol* rightType = type;
    switch (shiftExpressionNode.Op())
    {
        case sngcpp::ast::Operator::shiftLeft: node.reset(new sngcm::ast::ShiftLeftNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::shiftRight: node.reset(new sngcm::ast::ShiftRightNode(soulng::lexer::Span(), left.release(), right.release())); break;
        default:
        {
            NotConverted(shiftExpressionNode.GetSpan().line, "shift operator expected");
            break;
        }
    }
    type = MakeCommonType(leftType, rightType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::AdditiveExpressionNode& additiveExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(additiveExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    sngcpp::symbols::TypeSymbol* leftType = type;
    ConvertExpression(additiveExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    sngcpp::symbols::TypeSymbol* rightType = type;
    switch (additiveExpressionNode.Op())
    {
        case sngcpp::ast::Operator::add: node.reset(new sngcm::ast::AddNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::sub: node.reset(new sngcm::ast::SubNode(soulng::lexer::Span(), left.release(), right.release())); break;
        default:
        {
            NotConverted(additiveExpressionNode.GetSpan().line, "additive operator expected");
            break;
        }
    }
    type = MakeCommonType(leftType, rightType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::MultiplicativeExpressionNode& multiplicativeExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(multiplicativeExpressionNode.Left());
    std::unique_ptr<sngcm::ast::Node> left = std::move(node);
    sngcpp::symbols::TypeSymbol* leftType = type;
    ConvertExpression(multiplicativeExpressionNode.Right());
    std::unique_ptr<sngcm::ast::Node> right = std::move(node);
    sngcpp::symbols::TypeSymbol* rightType = type;
    switch (multiplicativeExpressionNode.Op())
    {
        case sngcpp::ast::Operator::mul : node.reset(new sngcm::ast::MulNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::div: node.reset(new sngcm::ast::DivNode(soulng::lexer::Span(), left.release(), right.release())); break;
        case sngcpp::ast::Operator::rem : node.reset(new sngcm::ast::RemNode(soulng::lexer::Span(), left.release(), right.release())); break;
        default:
        {
            NotConverted(multiplicativeExpressionNode.GetSpan().line, "multiplicative operator expected");
            break;
        }
    }
    type = MakeCommonType(leftType, rightType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::PMExpressionNode& pmExpressionNode)
{
    NotConverted(pmExpressionNode.GetSpan().line, "pointer-to-member expression not converted");
    // todo
    int x = 0;
    type = nullptr;
}

void Converter::Visit(sngcpp::ast::CastExpressionNode& castExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertTypeExpression(castExpressionNode.TypeExpr());
    std::unique_ptr<sngcm::ast::Node> typeNode = std::move(node);
    sngcpp::symbols::TypeSymbol* targetType = type;
    ConvertExpression(castExpressionNode.Expr());
    node.reset(new sngcm::ast::CastNode(soulng::lexer::Span(), typeNode.release(), node.release()));
    type = targetType;
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::UnaryExpressionNode& unaryExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    if (unaryExpressionNode.Op() == sngcpp::ast::Operator::not_)
    {
        ConvertBooleanExpression(unaryExpressionNode.Child());
    }
    else
    {
        ConvertExpression(unaryExpressionNode.Child());
    }
    std::unique_ptr<sngcm::ast::Node> operand = std::move(node);
    switch (unaryExpressionNode.Op())
    {
        case sngcpp::ast::Operator::inc: node.reset(new sngcm::ast::PrefixIncrementNode(soulng::lexer::Span(), operand.release())); break;
        case sngcpp::ast::Operator::dec: node.reset(new sngcm::ast::PrefixDecrementNode(soulng::lexer::Span(), operand.release())); break;
        case sngcpp::ast::Operator::deref:
        {
            node.reset(new sngcm::ast::DerefNode(soulng::lexer::Span(), operand.release()));
            type = RemovePointer(type);
            break;
        }
        case sngcpp::ast::Operator::addrOf:
        {
            node.reset(new sngcm::ast::AddrOfNode(soulng::lexer::Span(), operand.release()));
            type = AddPointer(type);
            break;
        }
        case sngcpp::ast::Operator::unaryPlus: node.reset(new sngcm::ast::UnaryPlusNode(soulng::lexer::Span(), operand.release())); break;
        case sngcpp::ast::Operator::unaryMinus: node.reset(new sngcm::ast::UnaryMinusNode(soulng::lexer::Span(), operand.release())); break;
        case sngcpp::ast::Operator::not_:
        {
            node.reset(new sngcm::ast::NotNode(soulng::lexer::Span(), operand.release()));
            type = symbolTable.GetBoolType();
            break;
        }
        case sngcpp::ast::Operator::complement: node.reset(new sngcm::ast::ComplementNode(soulng::lexer::Span(), operand.release())); break;
        case sngcpp::ast::Operator::sizeOf:
        {
            node.reset(new sngcm::ast::SizeOfNode(soulng::lexer::Span(), operand.release()));
            type = symbolTable.GetLongType();
            break;
        }
        case sngcpp::ast::Operator::alignOf:
        {
            NotConverted(unaryExpressionNode.GetSpan().line, "align-of expression not converted");
            break;
        }
        default:
        {
            NotConverted(unaryExpressionNode.GetSpan().line, "unary operator expected");
            node.reset();
            type = nullptr;
            break;
        }
    }
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::NewExpressionNode& newExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    if (newExpressionNode.Placement())
    {
        NotConverted(newExpressionNode.GetSpan().line, "placement not converted");
    }
    ConvertTypeExpression(newExpressionNode.TypeExpr());
    std::unique_ptr<sngcm::ast::Node> typeNode = std::move(node);
    sngcpp::symbols::TypeSymbol* pointeeType = type;
    sngcm::ast::NodeList<sngcm::ast::Node> args;
    if (newExpressionNode.Initializer())
    {
        args = ConvertExpressionList(newExpressionNode.Initializer());
    }
    sngcm::ast::NewNode* newNode = new sngcm::ast::NewNode(soulng::lexer::Span(), typeNode.release());
    int n = args.Count();
    for (int i = 0; i < n; ++i)
    {
        newNode->AddArgument(args.Release(i));
    }
    node.reset(newNode);
    type = AddPointer(pointeeType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::DeleteExpressionNode& deleteExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    if (deleteExpressionNode.Array())
    {
        WriteWarning(deleteExpressionNode.GetSpan().line, "delete array not converted");
        deleteExpressionNode.Child()->Accept(*this);
    }
    else
    {
        ConvertExpression(deleteExpressionNode.Child());
        std::unique_ptr<sngcm::ast::Node> ptr = std::move(node);
        AddStatement(deleteExpressionNode.GetSpan().line, new sngcm::ast::DeleteStatementNode(soulng::lexer::Span(), ptr.release()));
        node.reset(new sngcm::ast::EmptyStatementNode(soulng::lexer::Span()));
    }
    type = nullptr;
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::SubscriptExpressionNode& subscriptExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(subscriptExpressionNode.Child());
    std::unique_ptr<sngcm::ast::Node> subject = std::move(node);
    sngcpp::symbols::TypeSymbol* subjectType = type;
    ConvertExpression(subscriptExpressionNode.Index());
    std::unique_ptr<sngcm::ast::Node> index = std::move(node);
    node.reset(new sngcm::ast::IndexingNode(soulng::lexer::Span(), subject.release(), index.release()));
    type = MakeElementType(subjectType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::InvokeExpressionNode& invokeExpressionNode)
{
    std::u32string callArgs;
    std::u32string prevArgs = args;
    args.clear();
    sngcpp::symbols::CallableSymbol* prevFunctionSymbol = calledFunction;
    calledFunction = nullptr;
    sngcpp::symbols::CallableSymbol* primaryCalledFunction = nullptr;
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&invokeExpressionNode);
    if (symbol && symbol->IsCallableSymbol())
    {
        calledFunction = static_cast<sngcpp::symbols::CallableSymbol*>(symbol);
        primaryCalledFunction = calledFunction;
    }
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(invokeExpressionNode.Child());
    if (calledFunction && args.empty())
    {
        std::unique_ptr<sngcm::ast::IdentifierNode> idNode(map.MapFunctionSymbol(calledFunction, args));
    }
    calledFunction = prevFunctionSymbol;
    callArgs = args;
    std::vector<int> argIndeces;
    if (!callArgs.empty())
    {
        argIndeces = ParseArgs(callArgs);
    }
    args = prevArgs;
    std::unique_ptr<sngcm::ast::Node> subject = std::move(node);
    sngcpp::symbols::TypeSymbol* subjectType = type;
    sngcm::ast::NodeList<sngcm::ast::Node> args = ConvertExpressionList(invokeExpressionNode.Arguments());
    sngcm::ast::InvokeNode* invoke = new sngcm::ast::InvokeNode(soulng::lexer::Span(), subject.release());
    int n = args.Count();
    for (int i = 0; i < n; ++i)
    {
        int index = i;
        if (i < argIndeces.size())
        {
            index = argIndeces[i];
        }
        invoke->AddArgument(args.Release(index));
    }
    node.reset(invoke);
    type = nullptr;
    if (primaryCalledFunction)
    {
        if (primaryCalledFunction->ReturnType())
        {
            type = primaryCalledFunction->ReturnType();
        }
    }
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::DotNode& dotNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(dotNode.Child());
    std::unique_ptr<sngcm::ast::Node> subject = std::move(node);
    sngcpp::symbols::TypeSymbol* subjectType = type;
    dotNode.Id()->Accept(*this);
    std::unique_ptr<sngcm::ast::Node> member = std::move(node);
    sngcpp::symbols::TypeSymbol* memberType = type;
    sngcpp::symbols::Symbol* parent = nullptr;
    if (!mappedSymbolSequence.empty())
    {
        sngcpp::symbols::Symbol* symbol = mappedSymbolSequence.back();
        if (symbol)
        {
            parent = symbol->Parent();
            if (symbol->IsFunctionGroupSymbol() && calledFunction)
            {
                symbol = calledFunction;
            }
            sngcm::ast::IdentifierNode* idNode = map.MapMemberSymbol(symbol, args);
            if (idNode)
            {
                node.reset(new sngcm::ast::DotNode(soulng::lexer::Span(), subject.release(), idNode));
            }
        }
    }
    if (!node)
    {
        if (dotNode.Id()->IsIdentifierNode())
        {
            node.reset(new sngcm::ast::DotNode(soulng::lexer::Span(), subject.release(),
                new sngcm::ast::IdentifierNode(soulng::lexer::Span(), static_cast<sngcpp::ast::IdentifierNode*>(dotNode.Id())->Identifier())));
        }
        else
        {
            node.reset(new sngcm::ast::DotNode(soulng::lexer::Span(), subject.release(),
                new sngcm::ast::IdentifierNode(soulng::lexer::Span(), ToUtf32(member->ToString()))));
        }
    }
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::ArrowNode& arrowNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(arrowNode.Child());
    std::unique_ptr<sngcm::ast::Node> subject = std::move(node);
    sngcpp::symbols::TypeSymbol* subjectType = type;
    arrowNode.Id()->Accept(*this);
    std::unique_ptr<sngcm::ast::Node> member = std::move(node);
    sngcpp::symbols::TypeSymbol* memberType = type;
    sngcpp::symbols::Symbol* parent = nullptr;
    if (!mappedSymbolSequence.empty())
    {
        sngcpp::symbols::Symbol* symbol = mappedSymbolSequence.back();
        if (symbol)
        {
            parent = symbol->Parent();
            sngcm::ast::IdentifierNode* idNode = map.MapMemberSymbol(symbol, args);
            if (idNode)
            {
                node.reset(new sngcm::ast::ArrowNode(soulng::lexer::Span(), subject.release(), idNode));
            }
        }
    }
    if (!node)
    {
        if (arrowNode.Id()->IsIdentifierNode())
        {
            node.reset(new sngcm::ast::ArrowNode(soulng::lexer::Span(), subject.release(),
                new sngcm::ast::IdentifierNode(soulng::lexer::Span(), static_cast<sngcpp::ast::IdentifierNode*>(arrowNode.Id())->Identifier())));
        }
        else
        {
            node.reset(new sngcm::ast::ArrowNode(soulng::lexer::Span(), subject.release(),
                new sngcm::ast::IdentifierNode(soulng::lexer::Span(), ToUtf32(member->ToString()))));
        }
    }
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::PostfixIncNode& postfixIncNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(postfixIncNode.Child());
    std::unique_ptr<sngcm::ast::Node> operand = std::move(node);
    node.reset(new sngcm::ast::PostfixIncrementNode(soulng::lexer::Span(), operand.release()));
    type = nullptr;
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::PostfixDecNode& postfixDecNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(postfixDecNode.Child());
    std::unique_ptr<sngcm::ast::Node> operand = std::move(node);
    node.reset(new sngcm::ast::PostfixIncrementNode(soulng::lexer::Span(), operand.release()));
    type = nullptr;
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::CppCastExpressionNode& cppCastExpressionNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertTypeExpression(cppCastExpressionNode.TypeExpr());
    std::unique_ptr<sngcm::ast::Node> typeNode = std::move(node);
    sngcpp::symbols::TypeSymbol* targetType = type;
    ConvertExpression(cppCastExpressionNode.Expr());
    std::unique_ptr<sngcm::ast::Node> exprNode = std::move(node);
    switch (cppCastExpressionNode.Op())
    {
        case sngcpp::ast::Operator::staticCast:
        {
            node.reset(new sngcm::ast::CastNode(soulng::lexer::Span(), typeNode.release(), exprNode.release()));
            break;
        }
        case sngcpp::ast::Operator::constCast:
        {
            WriteWarning(cppCastExpressionNode.GetSpan().line, "const_cast");
            node.reset(new sngcm::ast::CastNode(soulng::lexer::Span(), typeNode.release(), exprNode.release()));
            break;
        }
        case sngcpp::ast::Operator::dynamicCast:
        {
            NotConverted(cppCastExpressionNode.GetSpan().line, "dynamic_cast not converted");
            break;
        }
        case sngcpp::ast::Operator::reinterpretCast:
        {
            WriteWarning(cppCastExpressionNode.GetSpan().line, "reinterpret_cast");
            node.reset(new sngcm::ast::CastNode(soulng::lexer::Span(), typeNode.release(), exprNode.release()));
            break;
        }
        default:
        {
            NotConverted(cppCastExpressionNode.GetSpan().line, "cast operator expected");
            break;
        }
    }
    type = targetType;
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::TypeIdExpressionNode& typeIdExpressionNode)
{
    NotConverted(typeIdExpressionNode.GetSpan().line, "type id expression not converted");
    // todo
    int x = 0;
}

void Converter::Visit(sngcpp::ast::ThisNode& thisNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    node.reset(new sngcm::ast::ThisNode(soulng::lexer::Span()));
    type = AddPointer(currentClassType);
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::ParenthesizedExprNode& parenthesizedExprNode)
{
    bool prevAddToNodes = addToNodes;
    addToNodes = false;
    ConvertExpression(parenthesizedExprNode.Child());
    std::unique_ptr<sngcm::ast::Node> exprNode = std::move(node);
    node.reset(new sngcm::ast::ParenthesizedExpressionNode(soulng::lexer::Span(), exprNode.release()));
    addToNodes = prevAddToNodes;
}

void Converter::Visit(sngcpp::ast::LambdaExpressionNode& lambdaExpressionNode)
{
    NotConverted(lambdaExpressionNode.GetSpan().line, "lambda not converted");
    type = nullptr;
}

void Converter::Visit(sngcpp::ast::IdentifierNode& identifierNode)
{
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&identifierNode);
    mappedSymbolSequence.push_back(symbol);
    if (symbol)
    {
        type = symbol->GetType();
    }
    else
    {
        type = nullptr;
    }
}

void Converter::Visit(sngcpp::ast::OperatorFunctionIdNode& operatorFunctionIdNode)
{
    NotConverted(operatorFunctionIdNode.GetSpan().line, "operator function id not converted");
    // todo
    int x = 0;
    type = nullptr;
}

void Converter::Visit(sngcpp::ast::ConversionFunctionIdNode& conversionFunctionIdNode)
{
    NotConverted(conversionFunctionIdNode.GetSpan().line, "conversion function id not converted");
    // todo
    int x = 0;
    type = nullptr;
}

void Converter::Visit(sngcpp::ast::DtorIdNode& dDtorIdNode)
{
    NotConverted(dDtorIdNode.GetSpan().line, "destructor id not converted");
    // todo
    int x = 0;
    type = nullptr;
}

void Converter::Visit(sngcpp::ast::NestedIdNode& nestedIdNode)
{
    nestedIdNode.Left()->Accept(*this);
    std::unique_ptr<sngcm::ast::Node> left(node.release());
    nestedIdNode.Right()->Accept(*this);
    if (left && !node)
    {
        if (!mappedSymbolSequence.empty())
        {
            sngcpp::symbols::Symbol* symbol = mappedSymbolSequence.back();
            if (symbol)
            {
                sngcm::ast::IdentifierNode* memberId = map.MapMemberSymbol(symbol, args);
                if (memberId)
                {
                    node.reset(new sngcm::ast::DotNode(soulng::lexer::Span(), left.release(), memberId));
                }
            }
        }
    }
    else if (calledFunction)
    {
        if (mappedSymbolSequence.size() == 2 && mappedSymbolSequence.front() && mappedSymbolSequence.back())
        {
            if (mappedSymbolSequence.front()->IsClassGroupSymbol() && mappedSymbolSequence.back()->IsFunctionGroupSymbol())
            {
                sngcpp::symbols::ClassGroupSymbol* classGroup = static_cast<sngcpp::symbols::ClassGroupSymbol*>(mappedSymbolSequence.front());
                sngcpp::symbols::FunctionGroupSymbol* functionGroup = static_cast<sngcpp::symbols::FunctionGroupSymbol*>(mappedSymbolSequence.back());
                if (calledFunction->Name() == functionGroup->Name())
                {
                    if (currentClassType)
                    {
                        if (currentClassType->Name() == classGroup->Name())
                        {
                            node.reset(new sngcm::ast::ArrowNode(soulng::lexer::Span(), new sngcm::ast::ThisNode(soulng::lexer::Span()),
                                new sngcm::ast::IdentifierNode(soulng::lexer::Span(), functionGroup->Name())));
                        }
                        else if (currentClassType->BaseClasses().size() == 1 && currentClassType->BaseClasses().front()->Name() == classGroup->Name())
                        {
                            node.reset(new sngcm::ast::ArrowNode(soulng::lexer::Span(), new sngcm::ast::BaseNode(soulng::lexer::Span()),
                                new sngcm::ast::IdentifierNode(soulng::lexer::Span(), functionGroup->Name())));
                        }
                    }
                }
            }
        }
    }
}

void Converter::Visit(sngcpp::ast::ParameterNode& parameterNode)
{
    ConvertTypeExpression(parameterNode.TypeExpr());
    std::unique_ptr<sngcm::ast::Node> typeNode(node.release());
    if (parameterNode.Declarator())
    {
        mappedSymbolSequence.clear();
        parameterNode.Declarator()->Accept(*this);
    }
    sngcm::ast::IdentifierNode* idNode = static_cast<sngcm::ast::IdentifierNode*>(node.release());
    std::unique_ptr<sngcm::ast::ParameterNode> paramNode(new sngcm::ast::ParameterNode(soulng::lexer::Span(), typeNode.release(), idNode));
    parameterNodes.push_back(std::move(paramNode));
    type = nullptr;
}

void Converter::Visit(sngcpp::ast::ParameterSequenceNode& parameterSequenceNode)
{
    parameterSequenceNode.Left()->Accept(*this);
    parameterSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::FunctionNode& functionNode) 
{
    Item prevClassItem = nothrowClassItem;
    sngcpp::symbols::ClassTypeSymbol* prevClassType = currentClassType;
    sngcm::ast::Node* prevContainer = currentContainerNode;
    sngcm::ast::Node* functionContainer = prevContainer;
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&functionNode);
    if (excludedFunctions.find(symbol->FullName()) != excludedFunctions.cend())
    {
        if (verbose)
        {
            std::cout << "info: function " << ToUtf8(symbol->FullName()) << " excluded" << std::endl;
        }
    }
    else
    {
        sngcm::ast::Specifiers functionSpecifiers = MapSpecifiers(functionNode.Specifiers());
        std::unique_ptr<sngcm::ast::Node> typeNode;
        sngcpp::symbols::TypeSymbol* returnType = nullptr;
        if (functionNode.TypeExpr()) 
        {
            ConvertTypeExpression(functionNode.TypeExpr());
            typeNode = std::move(node);
            returnType = type;
        }
        mappedSymbolSequence.clear();
        functionNode.Declarator()->Accept(*this);
        if (mappedSymbolSequence.empty())
        {
            WriteWarning(functionNode.GetSpan().line, "function name not mapped");
        }
        if (!symbol)
        {
            symbol = mappedSymbolSequence.back();
        }
        if (!symbol)
        {
            currentContainerNode = prevContainer;
            currentClassType = prevClassType;
            WriteWarning(functionNode.GetSpan().line, "function name not mapped");
            return;
        }
        bool found = false;
        if (symbol->Parent()->IsClassTypeSymbol())
        {
            sngcpp::symbols::ClassTypeSymbol* classType = static_cast<sngcpp::symbols::ClassTypeSymbol*>(symbol->Parent());
            nothrowClassItem = Item(Item::Type::class_, classType->Name(), nothrowFileItem.include);
            nothrowList.ApplyTo(nothrowClassItem);
            if (nothrowList.Verbose())
            {
                if (nothrowClassItem.include)
                {
                    std::cout << "info: " << ToUtf8(classType->Name()) << ": nothrow=true" << std::endl;
                }
                else
                {
                    std::cout << "info: " << ToUtf8(classType->Name()) << ": nothrow=false" << std::endl;
                }
            }
            nothrowFunctionItem = Item(Item::Type::function, symbol->Name(), nothrowClassItem.include);
            auto cit = classMap.find(classType);
            if (cit != classMap.cend())
            {
                functionContainer = cit->second;
                currentContainerNode = functionContainer;
                found = true;
            }
        }
        else
        {
            nothrowFunctionItem = Item(Item::Type::function, symbol->Name(), nothrowFileItem.include);
        }
        if (!found)
        {
            auto it = currentContext->containerMap.find(symbol->Parent());
            if (it != currentContext->containerMap.cend())
            {
                functionContainer = it->second;
                currentContainerNode = functionContainer;
            }
        }
        if (symbol->IsFunctionSymbol())
        {
            nothrowList.ApplyTo(nothrowFunctionItem);
            if (nothrowList.Verbose())
            {
                if (nothrowFunctionItem.include)
                {
                    std::cout << "info: " << ToUtf8(symbol->Name()) << ": nothrow=true" << std::endl;
                }
                else
                {
                    std::cout << "info: " << ToUtf8(symbol->Name()) << ": nothrow=false" << std::endl;
                }
            }
            sngcpp::symbols::FunctionSymbol* functionSymbol = static_cast<sngcpp::symbols::FunctionSymbol*>(symbol);
            bool memberFunction = functionSymbol->Parent()->IsClassTypeSymbol();
            if (!currentClassType && memberFunction)
            {
                currentClassType = static_cast<sngcpp::symbols::ClassTypeSymbol*>(functionSymbol->Parent());
            }
            functionSpecifiers = functionSpecifiers | MapSpecifiers(functionSymbol->Specifiers());
            functionSpecifiers = functionSpecifiers | MapAccess(symbol->Access());
            if (nothrowFunctionItem.include)
            {
                functionSpecifiers = functionSpecifiers | sngcm::ast::Specifiers::nothrow_;
            }
            if (!memberFunction)
            {
                node.reset(new sngcm::ast::FunctionNode(soulng::lexer::Span(), functionSpecifiers, typeNode.release(), symbol->Name(), nullptr));
            }
            else
            {
                node.reset(new sngcm::ast::MemberFunctionNode(soulng::lexer::Span(), functionSpecifiers, typeNode.release(), symbol->Name(), nullptr));
            }
        }
        else
        {
            currentContainerNode = prevContainer;
            currentClassType = prevClassType;
            WriteWarning(functionNode.GetSpan().line, "function not created");
            return;
        }
        std::unique_ptr<sngcm::ast::FunctionNode> funNode(static_cast<sngcm::ast::FunctionNode*>(node.release()));
        for (auto& parameterNode : parameterNodes)
        {
            funNode->AddParameter(parameterNode.release());
        }
        if (functionNode.Body())
        {
            statementNodes.clear();
            bool prevFunctionBody = inFunctionBody;
            inFunctionBody = true;
            functionNode.Body()->Accept(*this);
            inFunctionBody = prevFunctionBody;
            if (statementNodes.size() == 1)
            {
                funNode->SetBody(static_cast<sngcm::ast::CompoundStatementNode*>(statementNodes.front().release()));
            }
            else
            {
                WriteWarning(functionNode.GetSpan().line, "function body expected");
            }
        }
        currentContainerNode = functionContainer;
        AddToContainer(functionNode.GetSpan().line, funNode.release());
    }
    currentContainerNode = prevContainer;
    currentClassType = prevClassType;
    nothrowClassItem = prevClassItem;
}

void Converter::Visit(sngcpp::ast::FloatingLiteralNode& floatingLiteralNode)
{
    node.reset(new sngcm::ast::DoubleLiteralNode(soulng::lexer::Span(), floatingLiteralNode.Value()));
    type = symbolTable.GetDoubleType();
}

void Converter::Visit(sngcpp::ast::IntegerLiteralNode& integerLiteralNode)
{
    if (integerLiteralNode.GetSuffix() == sngcpp::ast::Suffix::u)
    {
        node.reset(new sngcm::ast::UIntLiteralNode(soulng::lexer::Span(), integerLiteralNode.Value()));
        type = symbolTable.GetUIntType();
    }
    else
    {
        node.reset(new sngcm::ast::IntLiteralNode(soulng::lexer::Span(), integerLiteralNode.Value()));
        type = symbolTable.GetIntType();
    }
}

void Converter::Visit(sngcpp::ast::CharacterLiteralNode& characterLiteralNode)
{
    node.reset(new sngcm::ast::CharLiteralNode(soulng::lexer::Span(), characterLiteralNode.Chr()));
    type = symbolTable.GetCharType();
}

void Converter::Visit(sngcpp::ast::StringLiteralNode& stringLiteralNode)
{
    if (stringLiteralNode.EncodigPrefix() == U"U")
    {
        node.reset(new sngcm::ast::UStringLiteralNode(soulng::lexer::Span(), stringLiteralNode.Chars()));
        type = AddPointer(symbolTable.GetChar32Type());
    }
    else if (stringLiteralNode.EncodigPrefix() == U"u")
    {
        node.reset(new sngcm::ast::WStringLiteralNode(soulng::lexer::Span(), ToUtf16(stringLiteralNode.Chars())));
        type = AddPointer(symbolTable.GetChar16Type());
    }
    else
    {
        node.reset(new sngcm::ast::StringLiteralNode(soulng::lexer::Span(), ToUtf8(stringLiteralNode.Chars())));
        type = AddPointer(symbolTable.GetCharType());
    }
}

void Converter::Visit(sngcpp::ast::BooleanLiteralNode& booleanLiteralNode)
{
    node.reset(new sngcm::ast::BooleanLiteralNode(soulng::lexer::Span(), booleanLiteralNode.Value()));
    type = symbolTable.GetBoolType();
}

void Converter::Visit(sngcpp::ast::NullPtrLiteralNode& nullPtrLiteralNode)
{
    node.reset(new sngcm::ast::NullLiteralNode(soulng::lexer::Span()));
    type = AddPointer(symbolTable.GetVoidType());
}

void Converter::Visit(sngcpp::ast::NamespaceNode& namespaceNode)
{
    bool nsCreated = false;
    sngcm::ast::NamespaceNode* prevNs = currentNamespace;
    if (!namespaceNode.NamespaceName().empty())
    {
        std::u32string nsName = map.GetNs(namespaceNode.NamespaceName());
        auto it = currentContext->nsmap.find(nsName);
        if (it == currentContext->nsmap.cend())
        {
            currentNamespace = new sngcm::ast::NamespaceNode(Span(), new sngcm::ast::IdentifierNode(Span(), nsName));
            currentNamespace->SetParent(prevNs);
            currentContext->nsmap[nsName] = currentNamespace;
            currentContext->currentNamespace = currentNamespace;
            nsCreated = true;
        }
        else
        {
            currentNamespace = it->second;
            currentContext->currentNamespace = currentNamespace;
        }
    }
    else
    {
        currentNamespace = currentCompileUnit->GlobalNs();
        currentContext->currentNamespace = currentNamespace;
    }
    sngcm::ast::Node* prevContainerNode = currentContainerNode;
    currentContainerNode = currentNamespace;
    currentContext->currentContainerNode = currentContainerNode;
    if (namespaceNode.Child())
    {
        namespaceNode.Child()->Accept(*this);
    }
    if (prevNs && currentNamespace != currentCompileUnit->GlobalNs())
    {
        if (nsCreated)
        {
            prevNs->AddMember(currentNamespace);
        }
    }
    currentContainerNode = prevContainerNode;
    currentNamespace = prevNs;
    currentContext->currentNamespace = prevNs;
}

void Converter::Visit(sngcpp::ast::SimpleTypeNode& simpleTypeNode)
{
    sngcm::ast::NodeType nodeType = map.MapSimpleType(simpleTypeNode.Flags());
    node.reset(map.CreateNode(nodeType));
    type = symbolTable.MakeSimpleTypeSymbol(simpleTypeNode);
    if (!node)
    {
        NotConverted(simpleTypeNode.GetSpan().line, "simple type not converted");
    }
}

void Converter::Visit(sngcpp::ast::LabeledStatementNode& labeledStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    labeledStatementNode.Child()->Accept(*this);
    sngcm::ast::StatementNode* stmt = statementNodes.back().release();
    statementNodes.pop_back();
    statementContainer = prevContainer;
    AddStatement(labeledStatementNode.GetSpan().line, new sngcm::ast::LabeledStatementNode(soulng::lexer::Span(), stmt));
}

void Converter::Visit(sngcpp::ast::CaseStatementNode& caseStatementNode)
{
    statementContainer = StatementContainer::statements;
    std::unique_ptr<sngcm::ast::CaseStatementNode> caseStmt(new sngcm::ast::CaseStatementNode(soulng::lexer::Span()));
    ConvertExpression(caseStatementNode.CaseExpr());
    std::unique_ptr<sngcm::ast::Node> caseExprNode = std::move(node);
    if (parentCaseStatementNode != nullptr)
    {
        parentCaseStatementNode->AddCaseExpr(caseExprNode.release());
        caseStatementNode.Child()->Accept(*this);
    }
    else
    {
        caseStmt->AddCaseExpr(caseExprNode.release());
        parentCaseStatementNode = caseStmt.get();
        int start = statementNodes.size();
        caseStatementNode.Child()->Accept(*this);
        for (int i = start; i < statementNodes.size(); ++i)
        {
            caseStmt->AddStatement(statementNodes[i].release());
        }
        statementNodes.erase(statementNodes.begin() + start, statementNodes.end());
        parentCaseStatementNode = nullptr;
        caseStatementNodes.push_back(std::move(caseStmt));
    }
    statementContainer = StatementContainer::latestCase;
}

void Converter::Visit(sngcpp::ast::DefaultStatementNode& defaultStatementNode)
{
    statementContainer = StatementContainer::statements;
    int start = statementNodes.size();
    defaultStatementNode.Child()->Accept(*this);
    sngcm::ast::DefaultStatementNode* defaultStmt = new sngcm::ast::DefaultStatementNode(soulng::lexer::Span());
    for (int i = start; i < statementNodes.size(); ++i)
    {
        defaultStmt->AddStatement(statementNodes[i].release());
    }
    statementNodes.erase(statementNodes.begin() + start, statementNodes.end());
    defaultStatement.reset(defaultStmt);
    statementContainer = StatementContainer::latestDefault;
}

void Converter::Visit(sngcpp::ast::ExpressionStatementNode& expressionStatementNode)
{
    bool prevAssignmentStatement = assignmentStatement;
    std::unique_ptr<sngcm::ast::Node> exprNode;
    if (expressionStatementNode.Child())
    {
        ConvertExpression(expressionStatementNode.Child());
        if (!assignmentStatement)
        {
            exprNode = std::move(node);
        }
    }
    if (exprNode)
    {
        if (!exprNode->IsStatementNode())
        {
            AddStatement(expressionStatementNode.GetSpan().line, new sngcm::ast::ExpressionStatementNode(soulng::lexer::Span(), exprNode.release()));
        }
    }
    else if (!assignmentStatement)
    {
        AddStatement(expressionStatementNode.GetSpan().line, new sngcm::ast::EmptyStatementNode(soulng::lexer::Span()));
    }
    assignmentStatement = prevAssignmentStatement;
}

void Converter::Visit(sngcpp::ast::CompoundStatementNode& compoundStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    std::unique_ptr<sngcm::ast::CompoundStatementNode> compoundStmt(new sngcm::ast::CompoundStatementNode(soulng::lexer::Span()));
    if (compoundStatementNode.Child())
    {
        std::vector<std::unique_ptr<sngcm::ast::StatementNode>> prevStatementNodes = std::move(statementNodes);
        statementNodes.clear();
        compoundStatementNode.Child()->Accept(*this);
        for (auto& statementNode : statementNodes)
        {
            compoundStmt->AddStatement(statementNode.release());
        }
        statementNodes = std::move(prevStatementNodes);
    }
    statementContainer = prevContainer;
    AddStatement(compoundStatementNode.GetSpan().line, compoundStmt.release());
}

void Converter::Visit(sngcpp::ast::StatementSequenceNode& statementSequenceNode)
{
    statementSequenceNode.Left()->Accept(*this);
    statementSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::IfStatementNode& ifStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    ConvertBooleanExpression(ifStatementNode.Condition());
    std::unique_ptr<sngcm::ast::Node> conditionNode = std::move(node);
    ifStatementNode.ThenS()->Accept(*this);
    sngcm::ast::StatementNode* thenS = statementNodes.back().release();
    statementNodes.pop_back();
    sngcm::ast::StatementNode* elseS = nullptr;
    if (ifStatementNode.ElseS())
    {
        ifStatementNode.ElseS()->Accept(*this);
        elseS = statementNodes.back().release();
        statementNodes.pop_back();
    }
    statementContainer = prevContainer;
    AddStatement(ifStatementNode.GetSpan().line, new sngcm::ast::IfStatementNode(soulng::lexer::Span(), conditionNode.release(), thenS, elseS));
}

void Converter::Visit(sngcpp::ast::SwitchStatementNode& switchStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    ConvertExpression(switchStatementNode.Condition());
    std::unique_ptr<sngcm::ast::Node> conditionNode = std::move(node);
    std::vector<std::unique_ptr<sngcm::ast::CaseStatementNode>> prevCaseStatementNodes = std::move(caseStatementNodes);
    std::unique_ptr<sngcm::ast::DefaultStatementNode> prevDefaultStatementNode = std::move(defaultStatement);
    sngcm::ast::CaseStatementNode* prevCaseStatementNode = parentCaseStatementNode;
    parentCaseStatementNode = nullptr;
    switchStatementNode.Statement()->Accept(*this);
    parentCaseStatementNode = prevCaseStatementNode;
    sngcm::ast::StatementNode* stmt = statementNodes.back().release();
    statementNodes.pop_back();
    sngcm::ast::SwitchStatementNode* switchStatement = new sngcm::ast::SwitchStatementNode(soulng::lexer::Span(), conditionNode.release());
    for (auto& caseStmt : caseStatementNodes)
    {
        switchStatement->AddCase(caseStmt.release());
    }
    if (defaultStatement)
    {
        switchStatement->SetDefault(defaultStatement.release());
    }
    caseStatementNodes.clear();
    defaultStatement.reset();
    caseStatementNodes = std::move(prevCaseStatementNodes);
    defaultStatement = std::move(prevDefaultStatementNode);
    statementContainer = prevContainer;
    AddStatement(switchStatementNode.GetSpan().line, switchStatement);
}

void Converter::Visit(sngcpp::ast::WhileStatementNode& whileStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    ConvertBooleanExpression(whileStatementNode.Condition());
    std::unique_ptr<sngcm::ast::Node> conditionNode = std::move(node);
    whileStatementNode.Statement()->Accept(*this);
    sngcm::ast::StatementNode* stmt = statementNodes.back().release();
    statementNodes.pop_back();
    statementContainer = prevContainer;
    AddStatement(whileStatementNode.GetSpan().line, new sngcm::ast::WhileStatementNode(soulng::lexer::Span(), conditionNode.release(), stmt));
}

void Converter::Visit(sngcpp::ast::DoStatementNode& doStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    doStatementNode.Statement()->Accept(*this);
    sngcm::ast::StatementNode* stmt = statementNodes.back().release();
    statementNodes.pop_back();
    ConvertBooleanExpression(doStatementNode.Condition());
    std::unique_ptr<sngcm::ast::Node> conditionNode = std::move(node);
    statementContainer = prevContainer;
    AddStatement(doStatementNode.GetSpan().line, new sngcm::ast::DoStatementNode(soulng::lexer::Span(), stmt, conditionNode.release()));
}

void Converter::Visit(sngcpp::ast::RangeForStatementNode& rangeForStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    bool prevRangeFor = rangeFor;
    rangeFor = true;
    rangeForStatementNode.ForRangeDeclaration()->Accept(*this);
    std::unique_ptr<sngcm::ast::Node> typeNode = std::move(rangeForType);
    if (!typeNode)
    {
        NotConverted(rangeForStatementNode.GetSpan().line, "range for type not converted");
        typeNode = std::move(node);
    }
    std::unique_ptr<sngcm::ast::IdentifierNode> idNode = std::move(rangeForId);
    if (!idNode)
    {
        NotConverted(rangeForStatementNode.GetSpan().line, "range for id not converted");
        idNode.reset(static_cast<sngcm::ast::IdentifierNode*>(node.release()));
    }
    ConvertExpression(rangeForStatementNode.ForRangeInitializer());
    rangeFor = prevRangeFor;
    std::unique_ptr<sngcm::ast::Node> container = std::move(node);
    rangeForStatementNode.Statement()->Accept(*this);
    std::unique_ptr<sngcm::ast::StatementNode> action = std::move(statementNodes.back());
    statementNodes.pop_back();
    statementContainer = prevContainer;
    AddStatement(rangeForStatementNode.GetSpan().line, new sngcm::ast::RangeForStatementNode(soulng::lexer::Span(), typeNode.release(), idNode.release(), container.release(), action.release()));
}

void Converter::Visit(sngcpp::ast::ForStatementNode& forStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    forStatementNode.InitS()->Accept(*this);
    std::unique_ptr<sngcm::ast::StatementNode> initS(statementNodes.back().release());
    statementNodes.pop_back();
    ConvertBooleanExpression(forStatementNode.Condition());
    std::unique_ptr<sngcm::ast::Node> cond = std::move(node);
    bool prevAssingmentStatement = assignmentStatement;
    assignmentStatement = false;
    ConvertExpression(forStatementNode.LoopExpr());
    std::unique_ptr<sngcm::ast::StatementNode> loopS;
    if (!assignmentStatement)
    {
        std::unique_ptr<sngcm::ast::Node> loopExpr = std::move(node);
        loopS.reset(new sngcm::ast::ExpressionStatementNode(soulng::lexer::Span(), loopExpr.release()));
    }
    else
    {
        loopS = std::move(statementNodes.back());
        statementNodes.pop_back();
    }
    assignmentStatement = prevAssingmentStatement;
    forStatementNode.ActionS()->Accept(*this);
    std::unique_ptr<sngcm::ast::StatementNode> actionS(statementNodes.back().release());
    statementNodes.pop_back();
    statementContainer = prevContainer;
    AddStatement(forStatementNode.GetSpan().line, new sngcm::ast::ForStatementNode(soulng::lexer::Span(), initS.release(), cond.release(), loopS.release(), actionS.release()));
}

void Converter::Visit(sngcpp::ast::BreakStatementNode& breakStatementNode)
{
    AddStatement(breakStatementNode.GetSpan().line, new sngcm::ast::BreakStatementNode(soulng::lexer::Span()));
}

void Converter::Visit(sngcpp::ast::ContinueStatementNode& continueStatementNode)
{
    AddStatement(continueStatementNode.GetSpan().line, new sngcm::ast::ContinueStatementNode(soulng::lexer::Span()));
}

void Converter::Visit(sngcpp::ast::ReturnStatementNode& returnStatementNode)
{
    std::unique_ptr<sngcm::ast::Node> returnExprNode;
    if (returnStatementNode.ReturnExpr())
    {
        ConvertExpression(returnStatementNode.ReturnExpr());
        returnExprNode = std::move(node);
    }
    AddStatement(returnStatementNode.GetSpan().line, new sngcm::ast::ReturnStatementNode(soulng::lexer::Span(), returnExprNode.release()));
}

void Converter::Visit(sngcpp::ast::GotoStatementNode& gotoStatementNode)
{
    AddStatement(gotoStatementNode.GetSpan().line, new sngcm::ast::GotoStatementNode(soulng::lexer::Span(), gotoStatementNode.Target()));
}

void Converter::Visit(sngcpp::ast::DeclarationStatementNode& declarationStatementNode)
{
    declarationStatementNode.Child()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::TryStatementNode& tryStatementNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    tryStatementNode.TryBlock()->Accept(*this);
    sngcm::ast::CompoundStatementNode* tryBlock = static_cast<sngcm::ast::CompoundStatementNode*>(statementNodes.back().release());
    statementNodes.pop_back();
    catchNodes.clear();
    tryStatementNode.Handlers()->Accept(*this);
    std::unique_ptr<sngcm::ast::TryStatementNode> tryStatement(new sngcm::ast::TryStatementNode(soulng::lexer::Span(), tryBlock));
    for (std::unique_ptr<sngcm::ast::CatchNode>& catchNode : catchNodes)
    {
        tryStatement->AddCatch(catchNode.release());
    }
    statementContainer = prevContainer;
    AddStatement(tryStatementNode.GetSpan().line, tryStatement.release());
}

void Converter::Visit(sngcpp::ast::HandlerNode& handlerNode)
{
    StatementContainer prevContainer = statementContainer;
    statementContainer = StatementContainer::statements;
    std::unique_ptr<sngcm::ast::Node> typeExpr;
    std::unique_ptr<sngcm::ast::IdentifierNode> id;
    bool prevCatchDecl = catchDecl;
    catchDecl = true;
    handlerNode.ExceptionDeclaration()->Accept(*this);
    typeExpr = std::move(catchType);
    id = std::move(catchId);
    catchDecl = prevCatchDecl;
    handlerNode.CatchBlock()->Accept(*this);
    sngcm::ast::CompoundStatementNode* catchBlock = static_cast<sngcm::ast::CompoundStatementNode*>(statementNodes.back().release());
    statementNodes.pop_back();
    std::unique_ptr<sngcm::ast::CatchNode> catchNode(new sngcm::ast::CatchNode(soulng::lexer::Span(), typeExpr.release(), id.release(), catchBlock));
    catchNodes.push_back(std::move(catchNode));
    statementContainer = prevContainer;
}

void Converter::Visit(sngcpp::ast::HandlerSequenceNode& handlerSequenceNode)
{
    handlerSequenceNode.Left()->Accept(*this);
    handlerSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::CatchAllNode& catchAllNode)
{
    NotConverted(catchAllNode.GetSpan().line, "catch all not converted");
}

void Converter::Visit(sngcpp::ast::TypeParameterNode& typeParameterNode)
{
    templateParameterNodes.push_back(std::unique_ptr<sngcm::ast::TemplateParameterNode>(
        new sngcm::ast::TemplateParameterNode(soulng::lexer::Span(), new sngcm::ast::IdentifierNode(soulng::lexer::Span(), typeParameterNode.Id()), nullptr)));
}

void Converter::Visit(sngcpp::ast::TemplateParameterSequenceNode& templateParameterSequenceNode)
{
    templateParameterSequenceNode.Left()->Accept(*this);
    templateParameterSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::TemplateDeclarationNode& templateDeclarationNode)
{
    std::vector<std::unique_ptr<sngcm::ast::TemplateParameterNode>> prevTemplateParameterNodes = std::move(templateParameterNodes);
    templateParameterNodes.clear();
    templateDeclarationNode.TemplateParameters()->Accept(*this);
    templateDeclarationNode.Declaration()->Accept(*this);
    templateParameterNodes = std::move(prevTemplateParameterNodes);
}

void Converter::Visit(sngcpp::ast::TemplateArgumentSequenceNode& templateArgumentSequenceNode)
{
    templateArgumentSequenceNode.Left()->Accept(*this);
    templateArgumentSequenceNode.Right()->Accept(*this);
}

void Converter::Visit(sngcpp::ast::TemplateIdNode& templateIdNode)
{
    sngcpp::symbols::Symbol* symbol = symbolTable.GetSymbolNothrow(&templateIdNode);;
    if (symbol)
    {
        if (symbol->IsClassTemplateSpecializationSymbol())
        {
            type = static_cast<sngcpp::symbols::ClassTemplateSpecializationSymbol*>(symbol);
            sngxml::dom::Document* sourceXmlDoc = nullptr;
            node.reset(map.MapType(type, sourceXmlDoc));
        }
    }
    if (!node)
    {
        NotConverted(templateIdNode.GetSpan().line, "template id converted");
    }
}

void Converter::Visit(sngcpp::ast::TemplateArgumentNode& templateArgumentNode)
{
    NotConverted(templateArgumentNode.GetSpan().line, "template argument not converted");
}

void Converter::Visit(sngcpp::ast::ExplicitInstantiationNode& explicitInstantiationNode)
{
    NotConverted(explicitInstantiationNode.GetSpan().line, "explicit instantiation not converted");
}

void Converter::Visit(sngcpp::ast::ExplicitSpecializationNode& explicitSpecializationNode)
{
    NotConverted(explicitSpecializationNode.GetSpan().line, "explicit specialization not converted");
}

void Converter::Visit(sngcpp::ast::ConstNode& constNode)
{
    ConvertTypeExpression(constNode.Child());
    node.reset(new sngcm::ast::ConstNode(soulng::lexer::Span(), node.release()));
}

void Converter::Visit(sngcpp::ast::VolatileNode& volatileNode)
{
    NotConverted(volatileNode.GetSpan().line, "volatile not converted");
}

void Converter::Visit(sngcpp::ast::PointerNode& pointerNode)
{
    ConvertTypeExpression(pointerNode.Child());
    node.reset(new sngcm::ast::PointerNode(soulng::lexer::Span(), node.release()));
    type = AddPointer(type);
}

void Converter::Visit(sngcpp::ast::RValueRefNode& rValueRefNode)
{
    ConvertTypeExpression(rValueRefNode.Child());
    node.reset(new sngcm::ast::RValueRefNode(soulng::lexer::Span(), node.release()));
}

void Converter::Visit(sngcpp::ast::LValueRefNode& lValueRefNode)
{
    ConvertTypeExpression(lValueRefNode.Child());
    node.reset(new sngcm::ast::LValueRefNode(soulng::lexer::Span(), node.release()));
}

} // namespace cpp2cm

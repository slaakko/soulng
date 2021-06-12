// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_DECLARATION_PROCESSOR_INCLUDED
#define SNGCPP_SYMBOLS_DECLARATION_PROCESSOR_INCLUDED
#include <sngcpp20/symbols/Declaration.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/ast/Function.hpp>
#include <sngcpp20/symbols/Context.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

SYMBOLS_API void ProcessSimpleDeclaration(Node* declaration, Context* context);
SYMBOLS_API void ProcessMemberDeclaration(Node* memberDeclaration, Context* context);
SYMBOLS_API void BeginFunctionDefinition(Node* declSpecifierSeq, Node* declarator, Context* context);
SYMBOLS_API void EndFunctionDefinition(Context* context);
SYMBOLS_API void RemoveFunctionDefinition(Context* context);
SYMBOLS_API void ProcessAliasDeclaration(Node* usingNode, Context* context);
SYMBOLS_API ParameterSymbol* ProcessParameter(ParameterNode* parameterNode, Context* context);
SYMBOLS_API void CheckDuplicateSpecifier(DeclarationFlags flags, DeclarationFlags flag, const std::string& specifierStr, const SourcePos& sourcePos, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_DECLARATION_PROCESSOR_INCLUDED

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

enum class FunctionKind
{
    regular, constructor, destructor, operatorFn, conversionFn
};

struct SYMBOLS_API Id
{
    Id() : idNode(nullptr), templateArguments(), functionKind(FunctionKind::regular), returnType(nullptr) {}
    Id(Node* idNode_, const std::vector<Symbol*>& templateArguments_) : idNode(idNode_), templateArguments(templateArguments_), functionKind(FunctionKind::regular), returnType(nullptr) {}
    std::u32string functionName;
    Node* idNode;
    std::vector<Symbol*> templateArguments;
    FunctionKind functionKind;
    TypeSymbol* returnType;
};

SYMBOLS_API void ProcessSimpleDeclaration(Node* declaration, Context* context);
SYMBOLS_API void ProcessMemberDeclaration(Node* memberDeclaration, Context* context);
SYMBOLS_API bool BeginFunctionDefinition(Node* declSpecifierSeq, Node* declarator, Context* context);
SYMBOLS_API void EndFunctionDefinition(Context* context);
SYMBOLS_API bool ContainsFunctionDeclarator(Node* declarator);
SYMBOLS_API Id GetFunctionName(Node* declarator, Context* context);
SYMBOLS_API void RemoveFunctionDefinition(Context* context);
SYMBOLS_API void ProcessAliasDeclaration(Node* usingNode, Context* context);
SYMBOLS_API ParameterSymbol* ProcessParameter(ParameterNode* parameterNode, Context* context);
SYMBOLS_API void ProcessParenthesizedDeclarator(Node* declarator, Symbol* baseTypeOrValue, bool alias, bool param, Context* context);
SYMBOLS_API void CheckDuplicateSpecifier(DeclarationFlags flags, DeclarationFlags flag, const std::string& specifierStr, const SourcePos& sourcePos, Context* context);
SYMBOLS_API TypeSymbol* ProcessTypeSpecifierSequence(Node* typeSpecifierSequence, Context* context);
SYMBOLS_API Symbol* ProcessTypeIdOrValue(Node* typeIdNode, Context* context);
SYMBOLS_API TypeSymbol* ProcessTypeTemplateId(Node* templateIdNode, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_DECLARATION_PROCESSOR_INCLUDED

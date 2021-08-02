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

enum class DeclarationKind : int
{
    none,
    classDeclaration = 1 << 0,
    enumDeclaration = 1 << 1,
    aliasDeclararation = 1 << 2,
    objectDeclaration = 1 << 3,
    functionDeclaration = 1 << 4,
    parameter = 1 << 5,
    skip = 1 << 6
};

inline DeclarationKind operator|(DeclarationKind left, DeclarationKind right)
{
    return DeclarationKind(int(left) | int(right));
}

inline DeclarationKind operator&(DeclarationKind left, DeclarationKind right)
{
    return DeclarationKind(int(left) & int(right));
}

inline DeclarationKind operator~(DeclarationKind operand)
{
    return DeclarationKind(~int(operand));
}

struct SYMBOLS_API Id
{
    Id() : idNode(nullptr), functionKind(FunctionKind::regular) {}
    Id(Node* idNode_, const std::vector<Symbol*>& templateArguments_) : idNode(idNode_), functionKind(FunctionKind::regular), templateArguments(templateArguments_) {}
    std::u32string functionName;
    Node* idNode;
    FunctionKind functionKind;
    std::vector<Symbol*> templateArguments;
};

SYMBOLS_API void ProcessSimpleDeclaration(Node* declaration, Context* context);
SYMBOLS_API void ProcessMemberDeclaration(Node* memberDeclaration, Context* context);
SYMBOLS_API bool BeginFunctionDefinition(Node* declSpecifierSeq, Node* declarator, Context* context);
SYMBOLS_API void EndFunctionDefinition(Context* context);
SYMBOLS_API bool ContainsFunctionDeclarator(Node* declarator);
SYMBOLS_API void RemoveFunctionDefinition(Context* context);
SYMBOLS_API void ProcessAliasDeclaration(Node* usingNode, Context* context);
SYMBOLS_API ParameterSymbol* ProcessParameter(ParameterNode* parameterNode, Context* context);
SYMBOLS_API std::pair<Id, DeclarationKind> ProcessParenthesizedDeclarator(Node* declarator, Symbol* baseTypeOrValue, bool alias, bool param, bool function, Context* context);
SYMBOLS_API void CheckDuplicateSpecifier(DeclarationFlags flags, DeclarationFlags flag, const std::string& specifierStr, const SourcePos& sourcePos, Context* context);
SYMBOLS_API TypeSymbol* ProcessTypeSpecifierSequence(Node* typeSpecifierSequence, Context* context);
SYMBOLS_API Symbol* ProcessTypeIdOrValue(Node* typeIdNode, Context* context);
SYMBOLS_API TypeSymbol* ProcessTypeTemplateId(Node* templateIdNode, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_DECLARATION_PROCESSOR_INCLUDED

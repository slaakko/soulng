// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/FunctionSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/FunctionGroupSymbol.hpp>

namespace sngcpp::symbols {

FunctionSymbol::FunctionSymbol(const std::u32string& name_, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters_, bool definition_) : 
    ContainerSymbol(name_), returnType(nullptr), parameters(std::move(parameters_)), definition(definition_)
{
    GetScope()->SetKind(ScopeKind::functionScope);
}

bool FunctionSymbol::IsValidDeclarationScope(ScopeKind scopeKind) const
{
    switch (scopeKind)
    {
        case ScopeKind::namespaceScope: return true;
        case ScopeKind::classScope: return true;
    }
    return false;
}

void FunctionSymbol::AddToGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context)
{
    FunctionGroupSymbol* functionGroup = containerSymbol->GetOrInsertFunctionGroup(Name(), sourcePos, context);
    functionGroup->AddFunction(this);
}

void FunctionSymbol::RemoveFromGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context)
{
    FunctionGroupSymbol* functionGroup = containerSymbol->GetOrInsertFunctionGroup(Name(), sourcePos, context);
    functionGroup->RemoveFunction(this);
}

} // sngcpp::symbols

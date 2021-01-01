// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/VirtualBinder.hpp>
#include <sngcpp/symbols/ParameterSymbol.hpp>

namespace sngcpp { namespace binder {

bool Overrides(sngcpp::symbols::FunctionSymbol* derivedFun, sngcpp::symbols::FunctionSymbol* baseFun)
{
    if (derivedFun == baseFun) return false;
    if (derivedFun->Arity() != baseFun->Arity()) return false;
    if (derivedFun->Name() != baseFun->Name()) return false;
    int n = derivedFun->Arity();
    for (int i = 0; i < n; ++i)
    {
        sngcpp::symbols::ParameterSymbol* derivedParam = derivedFun->Parameters()[i];
        sngcpp::symbols::ParameterSymbol* baseParam = baseFun->Parameters()[i];
        sngcpp::symbols::TypeSymbol* derivedType = derivedParam->GetType();
        sngcpp::symbols::TypeSymbol* baseType = baseParam->GetType();
        if (derivedType->Id() != baseType->Id()) return false;
    }
    return true;
}

void ResolveOverrideSets(sngcpp::symbols::FunctionSymbol* derivedFun, sngcpp::symbols::ClassTypeSymbol* parentClass)
{
    for (sngcpp::symbols::TypeSymbol* baseClassType : parentClass->BaseClasses())
    {
        if (baseClassType->IsClassTypeSymbol())
        {
            sngcpp::symbols::ClassTypeSymbol* baseClass = static_cast<sngcpp::symbols::ClassTypeSymbol*>(baseClassType);
            for (sngcpp::symbols::FunctionSymbol* baseFun : baseClass->VirtualFunctions())
            {
                if (Overrides(derivedFun, baseFun))
                {
                    derivedFun->AddOverridden(baseFun);
                    baseFun->AddOverride(derivedFun);
                }
            }
            ResolveOverrideSets(derivedFun, baseClass);
        }
    }
}

void CollectPureVirtualFunctions(sngcpp::symbols::ClassTypeSymbol* cls, std::unordered_set<sngcpp::symbols::FunctionSymbol*>& pureVirtualFunctions)
{
    for (sngcpp::symbols::TypeSymbol* baseClassType : cls->BaseClasses())
    {
        if (baseClassType->IsClassTypeSymbol())
        {
            sngcpp::symbols::ClassTypeSymbol* baseClass = static_cast<sngcpp::symbols::ClassTypeSymbol*>(baseClassType);
            CollectPureVirtualFunctions(baseClass, pureVirtualFunctions);
        }
    }
    for (sngcpp::symbols::FunctionSymbol* virtualFun : cls->VirtualFunctions())
    {
        if (virtualFun->IsPureVirtual())
        {
            pureVirtualFunctions.insert(virtualFun);
        }
    }
}

void AddOverriddenPureVirtualFunctions(sngcpp::symbols::ClassTypeSymbol* cls, std::unordered_set<sngcpp::symbols::FunctionSymbol*>& pureVirtualFunctions,
    std::unordered_set<sngcpp::symbols::FunctionSymbol*>& overriddenPureVirtuals)
{
    for (sngcpp::symbols::TypeSymbol* baseClassType : cls->BaseClasses())
    {
        if (baseClassType->IsClassTypeSymbol())
        {
            sngcpp::symbols::ClassTypeSymbol* baseClass = static_cast<sngcpp::symbols::ClassTypeSymbol*>(baseClassType);
            AddOverriddenPureVirtualFunctions(baseClass, pureVirtualFunctions, overriddenPureVirtuals);
        }
    }
    for (sngcpp::symbols::FunctionSymbol* pureVirtualFunction : pureVirtualFunctions)
    {
        for (sngcpp::symbols::FunctionSymbol* virtualFun : cls->VirtualFunctions())
        {
            if (Overrides(virtualFun, pureVirtualFunction))
            {
                overriddenPureVirtuals.insert(pureVirtualFunction);
            }
        }
    }
}

void ResolveOverrideSets(sngcpp::symbols::ClassTypeSymbol* cls)
{
    std::unordered_set<sngcpp::symbols::FunctionSymbol*> pureVirtualFunctions;
    CollectPureVirtualFunctions(cls, pureVirtualFunctions);
    std::unordered_set<sngcpp::symbols::FunctionSymbol*> overriddenPureVirtuals;
    AddOverriddenPureVirtualFunctions(cls, pureVirtualFunctions, overriddenPureVirtuals);
    for (sngcpp::symbols::FunctionSymbol* overriddenPureVirtual : overriddenPureVirtuals)
    {
        pureVirtualFunctions.erase(overriddenPureVirtual);
    }
    if (!pureVirtualFunctions.empty())
    {
        cls->SetAbstract();
    }
    for (sngcpp::symbols::FunctionSymbol* derivedFun : cls->VirtualFunctions())
    {
        ResolveOverrideSets(derivedFun, cls);
    }
}

void ResolveOverrideSets(const std::unordered_set<sngcpp::symbols::ClassTypeSymbol*>& classes)
{
    for (sngcpp::symbols::ClassTypeSymbol* cls : classes)
    {
        ResolveOverrideSets(cls);
    }
}

} } // namespace sngcpp::binder

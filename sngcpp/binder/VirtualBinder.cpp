// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/VirtualBinder.hpp>
#include <sngcpp/symbols/ParameterSymbol.hpp>

namespace sngcpp { namespace binder {

bool Overrides(FunctionSymbol* derivedFun, FunctionSymbol* baseFun)
{
    if (derivedFun == baseFun) return false;
    if (derivedFun->Arity() != baseFun->Arity()) return false;
    if (derivedFun->Name() != baseFun->Name()) return false;
    int n = derivedFun->Arity();
    for (int i = 0; i < n; ++i)
    {
        ParameterSymbol* derivedParam = derivedFun->Parameters()[i];
        ParameterSymbol* baseParam = baseFun->Parameters()[i];
        TypeSymbol* derivedType = derivedParam->GetType();
        TypeSymbol* baseType = baseParam->GetType();
        if (derivedType->Id() != baseType->Id()) return false;
    }
    return true;
}

void ResolveOverrideSets(FunctionSymbol* derivedFun, ClassTypeSymbol* parentClass)
{
    for (TypeSymbol* baseClassType : parentClass->BaseClasses())
    {
        if (baseClassType->IsClassTypeSymbol())
        {
            ClassTypeSymbol* baseClass = static_cast<ClassTypeSymbol*>(baseClassType);
            for (FunctionSymbol* baseFun : baseClass->VirtualFunctions())
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

void CollectPureVirtualFunctions(ClassTypeSymbol* cls, std::unordered_set<FunctionSymbol*>& pureVirtualFunctions)
{
    for (TypeSymbol* baseClassType : cls->BaseClasses())
    {
        if (baseClassType->IsClassTypeSymbol())
        {
            ClassTypeSymbol* baseClass = static_cast<ClassTypeSymbol*>(baseClassType);
            CollectPureVirtualFunctions(baseClass, pureVirtualFunctions);
        }
    }
    for (FunctionSymbol* virtualFun : cls->VirtualFunctions())
    {
        if (virtualFun->IsPureVirtual())
        {
            pureVirtualFunctions.insert(virtualFun);
        }
    }
}

void AddOverriddenPureVirtualFunctions(ClassTypeSymbol* cls, std::unordered_set<FunctionSymbol*>& pureVirtualFunctions,
    std::unordered_set<FunctionSymbol*>& overriddenPureVirtuals)
{
    for (TypeSymbol* baseClassType : cls->BaseClasses())
    {
        if (baseClassType->IsClassTypeSymbol())
        {
            ClassTypeSymbol* baseClass = static_cast<ClassTypeSymbol*>(baseClassType);
            AddOverriddenPureVirtualFunctions(baseClass, pureVirtualFunctions, overriddenPureVirtuals);
        }
    }
    for (FunctionSymbol* pureVirtualFunction : pureVirtualFunctions)
    {
        for (FunctionSymbol* virtualFun : cls->VirtualFunctions())
        {
            if (Overrides(virtualFun, pureVirtualFunction))
            {
                overriddenPureVirtuals.insert(pureVirtualFunction);
            }
        }
    }
}

void ResolveOverrideSets(ClassTypeSymbol* cls)
{
    std::unordered_set<FunctionSymbol*> pureVirtualFunctions;
    CollectPureVirtualFunctions(cls, pureVirtualFunctions);
    std::unordered_set<FunctionSymbol*> overriddenPureVirtuals;
    AddOverriddenPureVirtualFunctions(cls, pureVirtualFunctions, overriddenPureVirtuals);
    for (FunctionSymbol* overriddenPureVirtual : overriddenPureVirtuals)
    {
        pureVirtualFunctions.erase(overriddenPureVirtual);
    }
    if (!pureVirtualFunctions.empty())
    {
        cls->SetAbstract();
    }
    for (FunctionSymbol* derivedFun : cls->VirtualFunctions())
    {
        ResolveOverrideSets(derivedFun, cls);
    }
}

void ResolveOverrideSets(const std::unordered_set<ClassTypeSymbol*>& classes)
{
    for (ClassTypeSymbol* cls : classes)
    {
        ResolveOverrideSets(cls);
    }
}

} } // namespace sngcpp::binder

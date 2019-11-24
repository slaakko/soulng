// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/ClassTypeSymbol.hpp>
#include <sngcpp/symbols/TemplateSymbol.hpp>
#include <soulng/util/Unicode.hpp>
#include <algorithm>

namespace sngcpp { namespace symbols {

using namespace soulng::unicode;

ClassTypeSymbol::ClassTypeSymbol(const Span& span_, const std::u32string& name_, ClassKey classKey_) : TypeSymbol(span_, name_), classKey(classKey_), isAbstract(false)
{
}

bool ClassTypeSymbol::HasBaseClass(TypeSymbol* type, int& distance)
{
    int n = baseClasses.size();
    for (int i = 0; i < n; ++i)
    {
        TypeSymbol* baseClass = baseClasses[i];
        if (baseClass == type)
        {
            ++distance;
            return true;
        }
        if (baseClass->HasBaseClass(type, distance))
        {
            ++distance;
            return true;
        }
    }
    return false;
}

int ClassTypeSymbol::MatchValue(TypeSymbol* argumentType)
{
    int parentMatchValue = TypeSymbol::MatchValue(argumentType);
    if (parentMatchValue == std::numeric_limits<int>::max())
    {
        return parentMatchValue; // exact match
    }
    if (argumentType != nullptr)
    {
        int distance = 1;
        if (argumentType->BaseType()->HasBaseClass(this, distance))
        {
            return distance;
        }
    }
    if (parentMatchValue > 0)
    {
        return parentMatchValue;
    }
    return 0;
}

void ClassTypeSymbol::AddTemplateParameter(std::unique_ptr<TypeSymbol>&& templateParameter)
{
    std::unique_ptr<TypeSymbol> templateParam = std::move(templateParameter);
    GetContainerScope()->Install(templateParam.get());
    templateParameters.push_back(std::move(templateParam));
}

ContainerSymbol* ClassTypeSymbol::GetBase(int i) const
{
    return baseClasses[i];
}

void ClassTypeSymbol::AddBaseClass(TypeSymbol* baseClass)
{
    baseClasses.push_back(baseClass);
}

void ClassTypeSymbol::AddDerivedClass(TypeSymbol* derivedClass)
{
    derivedClasses.push_back(derivedClass);
}

std::u32string ClassTypeSymbol::IdStr()
{
    std::u32string idStr = FullName();
    for (const std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
    {
        idStr.append(1, '_').append(templateParameter->Name());
    }
    return idStr;
}

std::u32string ClassTypeSymbol::KindStr()
{
    return ToString(classKey);
}

std::unique_ptr<sngxml::dom::Element> ClassTypeSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> classElement(new sngxml::dom::Element(U"class"));
    classElement->SetAttribute(U"key", sngcpp::ast::ToString(classKey));
    if (!templateParameters.empty())
    {
        std::unique_ptr<sngxml::dom::Element> templateParametersElement(new sngxml::dom::Element(U"templateParameters"));
        for (const std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
        {
            std::unique_ptr<sngxml::dom::Element> templateParameterElement = templateParameter->ToDomElement();
            templateParametersElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(templateParameterElement.release()));
        }
        classElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(templateParametersElement.release()));
    }
    if (!baseClasses.empty())
    {
        std::unique_ptr<sngxml::dom::Element> baseClassesElement(new sngxml::dom::Element(U"baseClasses"));
        std::sort(baseClasses.begin(), baseClasses.end(), ByName());
        for (TypeSymbol* baseClass : baseClasses)
        {
            std::unique_ptr<sngxml::dom::Element> baseClassElement(new sngxml::dom::Element(U"baseClass"));
            baseClassElement->SetAttribute(U"baseClassId", baseClass->Id());
            baseClassesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(baseClassElement.release()));
        }
        classElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(baseClassesElement.release()));
    }
    if (!derivedClasses.empty())
    {
        std::unique_ptr<sngxml::dom::Element> derivedClassesElement(new sngxml::dom::Element(U"derivedClasses"));
        std::sort(derivedClasses.begin(), derivedClasses.end(), ByName());
        for (TypeSymbol* derivedClass : derivedClasses)
        {
            std::unique_ptr<sngxml::dom::Element> derivedClassElement(new sngxml::dom::Element(U"derivedClass"));
            derivedClassElement->SetAttribute(U"derivedClassId", derivedClass->Id());
            derivedClassesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(derivedClassElement.release()));
        }
        classElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(derivedClassesElement.release()));
    }
    if (GetSpan().Valid())
    {
        classElement->SetAttribute(U"definitionFile", ToUtf32(fileName));
        classElement->SetAttribute(U"definitionLine", ToUtf32(std::to_string(GetSpan().line)));
        classElement->SetAttribute(U"definitionFileId", fileId);
    }
    if (isAbstract)
    {
        classElement->SetAttribute(U"abstract", U"true");
    }
    return classElement;
}

void ClassTypeSymbol::AddVirtualFunction(FunctionSymbol* virtualFunction)
{
    virtualFunctions.push_back(virtualFunction);
}

ElaborateClassTypeSymbol::ElaborateClassTypeSymbol(const Span& span_, ClassKey classKey_, TypeSymbol* classType_, const std::u32string& id_) :
    TypeSymbol(span_, classType_->Name()), classKey(classKey_), classType(classType_), id(id_)
{
}

std::unique_ptr<sngxml::dom::Element> ElaborateClassTypeSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> elaborateClassElement(new sngxml::dom::Element(U"elaborate_class"));
    return elaborateClassElement;
}

ClassGroupSymbol::ClassGroupSymbol(const Span& span_, const std::u32string& name_) : Symbol(span_, name_)
{
}

void ClassGroupSymbol::AddClass(std::unique_ptr<ClassTypeSymbol>&& cls)
{
    cls->SetParent(Parent());
    arityClassMap[cls->Arity()] = cls.get();
    classes.push_back(std::move(cls));
}

ClassTypeSymbol* ClassGroupSymbol::GetClass(int arity) const
{
    auto it = arityClassMap.find(arity);
    if (it != arityClassMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

std::unique_ptr<sngxml::dom::Element> ClassGroupSymbol::CreateElement()
{
    return std::unique_ptr<sngxml::dom::Element>(new sngxml::dom::Element(U"class_group"));
}

ClassGroupTypeSymbol::ClassGroupTypeSymbol(ClassGroupSymbol* classGroup_) : TypeSymbol(classGroup_->GetSpan(), classGroup_->Name()), classGroup(classGroup_)
{
}

} } // namespace sngcpp::symbols

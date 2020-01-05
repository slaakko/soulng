// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/ContainerSymbol.hpp>
#include <sngcpp/symbols/FunctionSymbol.hpp>
#include <sngcpp/symbols/ClassTypeSymbol.hpp>
#include <sngcpp/symbols/NamespaceSymbol.hpp>
#include <sngcpp/symbols/EnumerationSymbol.hpp>
#include <sngcpp/symbols/TypedefSymbol.hpp>
#include <sngcpp/symbols/VariableSymbol.hpp>
#include <sngcpp/symbols/GrammarSymbol.hpp>
#include <soulng/util/Unicode.hpp>
#include <algorithm>

namespace sngcpp { namespace symbols {

using namespace soulng::unicode;

ContainerSymbol::ContainerSymbol(const Span& span_, const std::u32string& name_) : Symbol(span_, name_), containerScope(this)
{
}

void ContainerSymbol::AddMember(std::unique_ptr<Symbol>&& member)
{
    if (member->IsInstallSymbol())
    {
        containerScope.Install(member.get());
        member->SetParent(this);
        members.push_back(std::move(member));
    }
    else
    {
        if (member->IsFunctionSymbol())
        {
            FunctionSymbol* functionSymbol = static_cast<FunctionSymbol*>(member.get());
            FunctionGroupSymbol* functionGroup = MakeFunctionGroupSymbol(member->GetSpan(), functionSymbol->GroupName());
            functionGroup->AddFunction(std::unique_ptr<FunctionSymbol>(static_cast<FunctionSymbol*>(member.release())));
        }
        else if (member->IsFunctionDeclarationSymbol())
        {
            FunctionDeclarationSymbol* functionDeclarationSymbol = static_cast<FunctionDeclarationSymbol*>(member.get());
            FunctionGroupSymbol* functionGroup = MakeFunctionGroupSymbol(member->GetSpan(), functionDeclarationSymbol->GroupName());
            functionGroup->AddFunctionDeclaration(std::unique_ptr<FunctionDeclarationSymbol>(static_cast<FunctionDeclarationSymbol*>(member.release())));
        }
        else if (member->IsClassTypeSymbol())
        {
            ClassGroupSymbol* classGroup = MakeClassGroupSymbol(member->GetSpan(), member->Name());
            classGroup->AddClass(std::unique_ptr<ClassTypeSymbol>(static_cast<ClassTypeSymbol*>(member.release())));
        }
        else
        {
            throw std::runtime_error("function or class type symbol expected");
        }
    }
}

FunctionGroupSymbol* ContainerSymbol::MakeFunctionGroupSymbol(const Span& span_, const std::u32string& groupName)
{
    Symbol* symbol = containerScope.Lookup(groupName);
    if (!symbol)
    {
        FunctionGroupSymbol* functionGroupSymbol = new FunctionGroupSymbol(span_, groupName);
        AddMember(std::unique_ptr<Symbol>(functionGroupSymbol));
        return functionGroupSymbol;
    }
    else if (symbol->IsFunctionGroupSymbol())
    {
        return static_cast<FunctionGroupSymbol*>(symbol);
    }
    else
    {
        throw std::runtime_error("symbol '" + ToUtf8(groupName) + "' conflicts with function group of the same name");
    }
}

ClassGroupSymbol* ContainerSymbol::MakeClassGroupSymbol(const Span& span_, const std::u32string& groupName)
{
    Symbol* symbol = containerScope.Lookup(groupName);
    if (!symbol)
    {
        ClassGroupSymbol* classGroupSymbol = new ClassGroupSymbol(span_, groupName);
        AddMember(std::unique_ptr<Symbol>(classGroupSymbol));
        return classGroupSymbol;
    }
    else if (symbol->IsClassGroupSymbol())
    {
        return static_cast<ClassGroupSymbol*>(symbol);
    }
    else
    {
        throw std::runtime_error("symbol '" + ToUtf8(groupName) + "' conflicts with class group of the same name");
    }
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::Namespaces()
{
    std::unique_ptr<sngxml::dom::Element> namespacesElement;
    std::vector<NamespaceSymbol*> namespaces;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsNamespaceSymbol())
        {
            namespaces.push_back(static_cast<NamespaceSymbol*>(member.get()));
        }
    }
    if (!namespaces.empty())
    {
        namespacesElement.reset(new sngxml::dom::Element(U"namespaces"));
        std::sort(namespaces.begin(), namespaces.end(), ByName());
        for (NamespaceSymbol* ns : namespaces)
        {
            std::unique_ptr<sngxml::dom::Element> namespaceElement = ns->ToDomElement();
            namespacesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(namespaceElement.release()));
        }
    }
    return namespacesElement;
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::Classes()
{
    std::unique_ptr<sngxml::dom::Element> classesElement;
    std::vector<ClassTypeSymbol*> classes;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsClassGroupSymbol())
        {
            ClassGroupSymbol* classGroup = static_cast<ClassGroupSymbol*>(member.get());
            for (const std::unique_ptr<ClassTypeSymbol>& cls : classGroup->Classes())
            {
                classes.push_back(cls.get());
            }
        }
    }
    if (!classes.empty())
    {
        classesElement.reset(new sngxml::dom::Element(U"classes"));
        std::sort(classes.begin(), classes.end(), ByName());
        for (ClassTypeSymbol* cls : classes)
        {
            std::unique_ptr<sngxml::dom::Element> classElement = cls->ToDomElement();
            classesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(classElement.release()));
        }
    }
    return classesElement;
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::Constructors()
{
    std::unique_ptr<sngxml::dom::Element> constructorsElement;
    std::vector<ConstructorSymbol*> constructors;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsFunctionGroupSymbol())
        {
            FunctionGroupSymbol* functionroup = static_cast<FunctionGroupSymbol*>(member.get());
            for (const std::unique_ptr<FunctionSymbol>& function : functionroup->Functions())
            {
                if (function->IsConstructorSymbol())
                {
                    constructors.push_back(static_cast<ConstructorSymbol*>(function.get()));
                }
            }
        }
    }
    if (!constructors.empty())
    {
        constructorsElement.reset(new sngxml::dom::Element(U"constructors"));
        std::sort(constructors.begin(), constructors.end(), ByName());
        for (ConstructorSymbol* constructor : constructors)
        {
            std::unique_ptr<sngxml::dom::Element> constructorElement = constructor->ToDomElement();
            constructorsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(constructorElement.release()));
        }
    }
    return constructorsElement;
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::Functions()
{
    std::unique_ptr<sngxml::dom::Element> functionsElement;
    std::vector<FunctionSymbol*> functions;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsFunctionGroupSymbol())
        {
            FunctionGroupSymbol* functionGroup = static_cast<FunctionGroupSymbol*>(member.get());
            for (const std::unique_ptr<FunctionSymbol>& function : functionGroup->Functions())
            {
                if (function->IsFunctionSymbol() && !function->IsConstructorSymbol())
                {
                    functions.push_back(function.get());
                }
            }
        }
    }
    if (!functions.empty())
    {
        functionsElement.reset(new sngxml::dom::Element(U"functions"));
        std::sort(functions.begin(), functions.end(), ByName());
        for (FunctionSymbol* function : functions)
        {
            std::unique_ptr<sngxml::dom::Element> functionElement = function->ToDomElement();
            functionsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(functionElement.release()));
        }
    }
    return functionsElement;
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::EnumTypes()
{
    std::unique_ptr<sngxml::dom::Element> enumTypesElement;
    std::vector<EnumTypeSymbol*> enumTypes;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsEnumTypeSymbol())
        {
            EnumTypeSymbol* enumType = static_cast<EnumTypeSymbol*>(member.get());
            enumTypes.push_back(enumType);
        }
    }
    if (!enumTypes.empty())
    {
        enumTypesElement.reset(new sngxml::dom::Element(U"enumTypes"));
        std::sort(enumTypes.begin(), enumTypes.end(), ByName());
        for (EnumTypeSymbol* enumType : enumTypes)
        {
            std::unique_ptr<sngxml::dom::Element> enumTypeElement = enumType->ToDomElement();
            enumTypesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(enumTypeElement.release()));
        }
    }
    return enumTypesElement;
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::Enumerators()
{
    std::unique_ptr<sngxml::dom::Element> enumeratorsElement;
    std::vector<EnumeratorSymbol*> enumerators;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsEnumeratorSymbol())
        {
            EnumeratorSymbol* enumerator = static_cast<EnumeratorSymbol*>(member.get());
            enumerators.push_back(enumerator);
        }
    }
    if (!enumerators.empty())
    {
        enumeratorsElement.reset(new sngxml::dom::Element(U"enumerators"));
        for (EnumeratorSymbol* enumerator : enumerators)
        {
            std::unique_ptr<sngxml::dom::Element> enumeratorElement = enumerator->ToDomElement();
            enumeratorsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(enumeratorElement.release()));
        }
    }
    return enumeratorsElement;
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::Typedefs()
{
    std::unique_ptr<sngxml::dom::Element> typedefsElement;
    std::vector<TypedefSymbol*> typedefs;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsTypedefSymbol())
        {
            TypedefSymbol* typedef_ = static_cast<TypedefSymbol*>(member.get());
            typedefs.push_back(typedef_);
        }
    }
    if (!typedefs.empty())
    {
        typedefsElement.reset(new sngxml::dom::Element(U"typedefs"));
        std::sort(typedefs.begin(), typedefs.end(), ByName());
        for (TypedefSymbol* typedef_ : typedefs)
        {
            std::unique_ptr<sngxml::dom::Element> typedefElement = typedef_->ToDomElement();
            typedefsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(typedefElement.release()));
        }
    }
    return typedefsElement;
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::Variables()
{
    std::unique_ptr<sngxml::dom::Element> variablesElement;
    std::vector<VariableSymbol*> variables;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsVariableSymbol())
        {
            VariableSymbol* variable = static_cast<VariableSymbol*>(member.get());
            variables.push_back(variable);
        }
    }
    if (!variables.empty())
    {
        variablesElement.reset(new sngxml::dom::Element(U"variables"));
        std::sort(variables.begin(), variables.end(), ByName());
        for (VariableSymbol* variable : variables)
        {
            std::unique_ptr<sngxml::dom::Element> variableElement = variable->ToDomElement();
            variablesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(variableElement.release()));
        }
    }
    return variablesElement;
}

std::unique_ptr<sngxml::dom::Element> ContainerSymbol::Grammars()
{
    std::unique_ptr<sngxml::dom::Element> grammarsElement;
    std::vector<GrammarSymbol*> grammars;
    for (const std::unique_ptr<Symbol>& member : members)
    {
        if (member->IsGrammarSymbol())
        {
            GrammarSymbol* grammar = static_cast<GrammarSymbol*>(member.get());
            grammars.push_back(grammar);
        }
    }
    if (!grammars.empty())
    {
        grammarsElement.reset(new sngxml::dom::Element(U"grammars"));
        std::sort(grammars.begin(), grammars.end(), ByName());
        for (GrammarSymbol* grammar : grammars)
        {
            std::unique_ptr<sngxml::dom::Element> grammarElement = grammar->ToDomElement();
            grammarsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(grammarElement.release()));
        }
    }
    return grammarsElement;
}

} } // namespace sngcpp::symbols

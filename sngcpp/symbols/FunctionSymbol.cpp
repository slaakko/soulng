// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/FunctionSymbol.hpp>
#include <sngcpp/symbols/ParameterSymbol.hpp>
#include <sngcpp/symbols/TemplateSymbol.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Sha1.hpp>
#include <algorithm>

namespace sngcpp { namespace symbols {

using namespace soulng::unicode;

CallableSymbol::CallableSymbol(const Span& span_, const std::u32string& name_) : ContainerSymbol(span_, name_)
{
}

FunctionDeclarationSymbol::FunctionDeclarationSymbol(const Span& span_, const std::u32string& groupName_, const std::u32string& name_, Specifier specifiers_) :
    CallableSymbol(span_, name_), groupName(groupName_), specifiers(specifiers_), functionGroup(nullptr), returnType(nullptr), functionDefinition(nullptr)
{
}

void FunctionDeclarationSymbol::AddTemplateParameter(std::unique_ptr<TypeSymbol>&& templateParameter)
{
    templateParameters.push_back(std::move(templateParameter));
}

std::u32string FunctionDeclarationSymbol::IdStr()
{
    std::u32string idStr = FullName();
    for (const std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
    {
        idStr.append(1, '_').append(templateParameter->Name());
    }
    for (ParameterSymbol* parameter : parameters)
    {
        idStr.append(1, '.').append(parameter->GetType()->Id());
    }
    if ((specifiers & Specifier::const_) != Specifier::none)
    {
        idStr.append(U".const");
    }
    if ((specifiers & Specifier::constExpr) != Specifier::none)
    {
        idStr.append(U".constExpr");
    }
    return idStr;
}

std::u32string FunctionDeclarationSymbol::FunctionId()
{
    std::u32string functionId = FunctionKind();
    functionId.append(1, '_').append(SimpleName()).append(1, '_').append(ToUtf32(GetSha1MessageDigest(ToUtf8(IdStr()))));
    return functionId;
}

std::unique_ptr<sngxml::dom::Element> FunctionDeclarationSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> functionElement(new sngxml::dom::Element(U"function_declaration"));
    return functionElement;
}

void FunctionDeclarationSymbol::AddMember(std::unique_ptr<Symbol>&& member)
{
    Symbol* symbol = member.get();
    if (symbol->IsParameterSymbol())
    {
        parameters.push_back(static_cast<ParameterSymbol*>(symbol));
    }
    ContainerSymbol::AddMember(std::move(member));
}

void FunctionDeclarationSymbol::AddSpecifiers(Specifier specifiers_)
{
    specifiers = specifiers | specifiers_;
}

ConstructorDeclarationSymbol::ConstructorDeclarationSymbol(const Span& span_, const std::u32string& name_, Specifier specifiers_) :
    FunctionDeclarationSymbol(span_, U"constructor", name_, specifiers_)
{
}

std::unique_ptr<sngxml::dom::Element> ConstructorDeclarationSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> constructorDeclarationElement(new sngxml::dom::Element(U"constructor_declaration"));
    return constructorDeclarationElement;
}

FunctionSymbol::FunctionSymbol(const Span& span_, const std::u32string& groupName_, const std::u32string& name_, Specifier specifiers_) :
    CallableSymbol(span_, name_), index(0), groupName(groupName_), returnType(nullptr), specifiers(specifiers_), functionGroup(nullptr),
    declarationSpan()
{
}

void FunctionSymbol::AddMember(std::unique_ptr<Symbol>&& member)
{
    Symbol* symbol = member.get();
    if (symbol->IsParameterSymbol())
    {
        parameters.push_back(static_cast<ParameterSymbol*>(symbol));
    }
    ContainerSymbol::AddMember(std::move(member));
}

void FunctionSymbol::AddTemplateParameter(std::unique_ptr<TypeSymbol>&& templateParameter)
{
    templateParameters.push_back(std::move(templateParameter));
}

std::u32string FunctionSymbol::IdStr()
{
    std::u32string idStr = FullName();
    for (const std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
    {
        idStr.append(1, '_').append(templateParameter->Name());
    }
    for (ParameterSymbol* parameter : parameters)
    {
        idStr.append(1, '.').append(parameter->GetType()->Id());
    }
    if ((specifiers & Specifier::const_) != Specifier::none)
    {
        idStr.append(U".const");
    }
    if ((specifiers & Specifier::constExpr) != Specifier::none)
    {
        idStr.append(U".constExpr");
    }
    return idStr;
}

std::unique_ptr<sngxml::dom::Element> FunctionSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> functionElement(new sngxml::dom::Element(U"function"));
    if (!templateParameters.empty())
    {
        std::unique_ptr<sngxml::dom::Element> templateParametersElement(new sngxml::dom::Element(U"templateParameters"));
        for (const std::unique_ptr<TypeSymbol>& templateParameter : templateParameters)
        {
            std::unique_ptr<sngxml::dom::Element> templateParameterElement = templateParameter->ToDomElement();
            templateParametersElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(templateParameterElement.release()));
        }
        functionElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(templateParametersElement.release()));
    }
    if (!parameters.empty())
    {
        std::unique_ptr<sngxml::dom::Element> parametersElement(new sngxml::dom::Element(U"parameters"));
        for (ParameterSymbol* parameter : parameters)
        {
            std::unique_ptr<sngxml::dom::Element> parameterElement = parameter->ToDomElement();
            parametersElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(parameterElement.release()));
        }
        functionElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(parametersElement.release()));
    }
    if (returnType)
    {
        functionElement->SetAttribute(U"returnType", returnType->Id());
    }
    if (specifiers != Specifier::none)
    {
        functionElement->SetAttribute(U"specifiers", SpecifierStr(specifiers));
    }
    if (GetSpan().Valid())
    {
        functionElement->SetAttribute(U"definitionFile", ToUtf32(fileName));
        functionElement->SetAttribute(U"definitionLine", ToUtf32(std::to_string(GetSpan().line)));
        functionElement->SetAttribute(U"definitionFileId", fileId);
    }
    if (declarationSpan.Valid())
    {
        functionElement->SetAttribute(U"declarationFile", ToUtf32(declarationFileName));
        functionElement->SetAttribute(U"declarationLine", ToUtf32(std::to_string(declarationSpan.line)));
        functionElement->SetAttribute(U"declarationFileId", declarationFileId);
    }
    if (!overrides.empty())
    {
        std::unique_ptr<sngxml::dom::Element> overridesElement(new sngxml::dom::Element(U"overrides"));
        for (FunctionSymbol* override_ : overrides)
        {
            std::unique_ptr<sngxml::dom::Element> overrideElement(new sngxml::dom::Element(U"override"));
            overrideElement->SetAttribute(U"functionId", override_->Id());
            overridesElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(overrideElement.release()));
        }
        functionElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(overridesElement.release()));
    }
    if (!overridden.empty())
    {
        std::unique_ptr<sngxml::dom::Element> overriddenFunctionsElement(new sngxml::dom::Element(U"overriddenFunctions"));
        for (FunctionSymbol* overridden_ : overridden)
        {
            std::unique_ptr<sngxml::dom::Element> overriddenFunctionElement(new sngxml::dom::Element(U"overriddenFunction"));
            overriddenFunctionElement->SetAttribute(U"functionId", overridden_->Id());
            overriddenFunctionsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(overriddenFunctionElement.release()));
        }
        functionElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(overriddenFunctionsElement.release()));
    }
    if (!calls.empty())
    {
        std::unique_ptr<sngxml::dom::Element> callsElement(new sngxml::dom::Element(U"calls"));
        for (FunctionSymbol* function : calls)
        {
            std::unique_ptr<sngxml::dom::Element> callElement(new sngxml::dom::Element(U"call"));
            callElement->SetAttribute(U"functionId", function->Id());
            callsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(callElement.release()));
        }
        functionElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(callsElement.release()));
    }
    if (!calledBy.empty())
    {
        std::unique_ptr<sngxml::dom::Element> calledByFunctionsElement(new sngxml::dom::Element(U"calledByFunctions"));
        for (FunctionSymbol* function : calledBy)
        {
            std::unique_ptr<sngxml::dom::Element> calledByFunctionElement(new sngxml::dom::Element(U"calledByFunction"));
            calledByFunctionElement->SetAttribute(U"functionId", function->Id());
            calledByFunctionsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(calledByFunctionElement.release()));
        }
        functionElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(calledByFunctionsElement.release()));
    }
    return functionElement;
}

bool FunctionSymbol::NameBefore(Symbol* that)
{
    if (ContainerSymbol::NameBefore(that)) return true;
    if (that->IsFunctionSymbol())
    {
        FunctionSymbol* functionSymbolThat = static_cast<FunctionSymbol*>(that);
        if (functionSymbolThat->ContainerSymbol::NameBefore(this)) return false;
        int np = parameters.size();
        int nt = functionSymbolThat->parameters.size();
        int n = std::min(np, nt);
        for (int i = 0; i < n; ++i)
        {
            ParameterSymbol* p = parameters[i];
            ParameterSymbol* t = functionSymbolThat->parameters[i];
            TypeSymbol* pType = p->GetType();
            TypeSymbol* tType = t->GetType();
            if (pType->NameBefore(tType)) return true;
            if (tType->NameBefore(pType)) return false;
        }
        if (np < nt) return true;
        if (nt < np) return false;
    }
    return false;
}

void FunctionSymbol::AddSpecifiers(Specifier specifiers_)
{
    specifiers = specifiers | specifiers_;
}

void FunctionSymbol::AddOverride(FunctionSymbol* override_)
{
    overrides.insert(override_);
}

void FunctionSymbol::AddOverridden(FunctionSymbol* overridden_)
{
    overridden.insert(overridden_);
}

void FunctionSymbol::AddToCalls(FunctionSymbol* function)
{
    calls.insert(function);
}

void FunctionSymbol::AddToCalledBy(FunctionSymbol* function)
{
    calledBy.insert(function);
}

ConstructorSymbol::ConstructorSymbol(const Span& span_, const std::u32string& name_, Specifier specifiers_) : FunctionSymbol(span_, U"constructor", name_, specifiers_)
{
}

std::unique_ptr<sngxml::dom::Element> ConstructorSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> constructorElement(new sngxml::dom::Element(U"constructor"));
    if (!Parameters().empty())
    {
        std::unique_ptr<sngxml::dom::Element> parametersElement(new sngxml::dom::Element(U"parameters"));
        for (ParameterSymbol* parameter : Parameters())
        {
            std::unique_ptr<sngxml::dom::Element> parameterElement = parameter->ToDomElement();
            parametersElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(parameterElement.release()));
        }
        constructorElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(parametersElement.release()));
    }
    if (Specifiers() != Specifier::none)
    {
        constructorElement->SetAttribute(U"specifiers", SpecifierStr(Specifiers()));
    }
    if (GetSpan().Valid())
    {
        constructorElement->SetAttribute(U"definitionFile", ToUtf32(FileName()));
        constructorElement->SetAttribute(U"definitionLine", ToUtf32(std::to_string(GetSpan().line)));
        constructorElement->SetAttribute(U"definitionFileId", FileId());
    }
    if (DeclarationSpan().Valid())
    {
        constructorElement->SetAttribute(U"declarationFile", ToUtf32(DeclarationFileName()));
        constructorElement->SetAttribute(U"declarationLine", ToUtf32(std::to_string(DeclarationSpan().line)));
        constructorElement->SetAttribute(U"declarationFileId", DeclarationFileId());
    }
    return constructorElement;
}

DestructorSymbol::DestructorSymbol(const Span& span_, const std::u32string& name_, Specifier specifiers_) : FunctionSymbol(span_, U"destructor", name_, specifiers_)
{
}

std::unique_ptr<sngxml::dom::Element> DestructorSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> destructorElement(new sngxml::dom::Element(U"destructor"));
    if (Specifiers() != Specifier::none)
    {
        destructorElement->SetAttribute(U"specifiers", SpecifierStr(Specifiers()));
    }
    if (GetSpan().Valid())
    {
        destructorElement->SetAttribute(U"definitionFile", ToUtf32(FileName()));
        destructorElement->SetAttribute(U"definitionLine", ToUtf32(std::to_string(GetSpan().line)));
        destructorElement->SetAttribute(U"definitionFileId", FileId());
    }
    if (DeclarationSpan().Valid())
    {
        destructorElement->SetAttribute(U"declarationFile", ToUtf32(DeclarationFileName()));
        destructorElement->SetAttribute(U"declarationLine", ToUtf32(std::to_string(DeclarationSpan().line)));
        destructorElement->SetAttribute(U"declarationFileId", DeclarationFileId());
    }
    return destructorElement;
}

FunctionGroupSymbol::FunctionGroupSymbol(const Span& span_, const std::u32string& name_) : Symbol(span_, name_)
{
}

void FunctionGroupSymbol::AddFunction(std::unique_ptr<FunctionSymbol>&& function)
{
    function->SetIndex(functions.size());
    function->SetParent(Parent());
    function->SetFunctionGroup(this);
    functions.push_back(std::move(function));
}

void FunctionGroupSymbol::AddFunctionDeclaration(std::unique_ptr<FunctionDeclarationSymbol>&& functionDeclaration)
{
    functionDeclaration->SetParent(Parent());
    functionDeclaration->SetFunctionGroup(this);
    functionDeclarations.push_back(std::move(functionDeclaration));
}

FunctionDeclarationSymbol* FunctionGroupSymbol::GetFunctionDeclaration(const std::vector<ParameterSymbol*>& parameters, Specifier specifiers)
{
    FunctionDeclarationSymbol* functionDeclarationSymbol = nullptr;
    for (const std::unique_ptr<FunctionDeclarationSymbol>& functionDeclaration : functionDeclarations)
    {
        int n = functionDeclaration->Arity();
        if (n == parameters.size())
        {
            bool match = true;
            bool declarationConst = (functionDeclaration->Specifiers() & Specifier::const_) != Specifier::none;
            bool const_ = (specifiers & Specifier::const_) != Specifier::none;
            if (declarationConst != const_)
            {
                match = false;
            }
            else
            {
                for (int i = 0; i < n; ++i)
                {
                    ParameterSymbol* declarationParameter = functionDeclaration->Parameters()[i];
                    ParameterSymbol* parameter = parameters[i];
                    if (!declarationParameter->GetType() || declarationParameter->GetType()->Id() != parameter->GetType()->Id())
                    {
                        match = false;
                        break;
                    }
                }
            }
            if (match)
            {
                if (functionDeclarationSymbol)
                {
                    throw std::runtime_error("already has match");
                }
                functionDeclarationSymbol = functionDeclaration.get();
            }
        }
    }
    return functionDeclarationSymbol;
}

std::unique_ptr<sngxml::dom::Element> FunctionGroupSymbol::CreateElement()
{
    return std::unique_ptr<sngxml::dom::Element>(new sngxml::dom::Element(U"function_group"));
}

struct FunctionMatch
{
    FunctionMatch() : matchValues() {}
    std::vector<int> matchValues;
};

struct BetterFunctionMatch
{
    BetterFunctionMatch(bool subjectIsConst_) : subjectIsConst(subjectIsConst_)
    {
    }
    bool operator()(const std::pair<CallableSymbol*, FunctionMatch>& left, const std::pair<CallableSymbol*, FunctionMatch>& right) const
    {
        int arity = left.second.matchValues.size();
        if (arity != right.second.matchValues.size())
        {
            throw std::runtime_error("wrong arity");
        }
        int betterLeftMatchValues = 0;
        int betterRightMatchValues = 0;
        for (int i = 0; i < arity; ++i)
        {
            int leftMatchValue = left.second.matchValues[i];
            int rightMatchValue = right.second.matchValues[i];
            if (leftMatchValue > rightMatchValue)
            {
                ++betterLeftMatchValues;
            }
            else if (rightMatchValue > leftMatchValue)
            {
                ++betterRightMatchValues;
            }
        }
        if (betterLeftMatchValues > betterRightMatchValues)
        {
            return true;
        }
        else if (betterRightMatchValues > betterLeftMatchValues)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < arity; ++i)
            {
                int leftMatchValue = left.second.matchValues[i];
                int rightMatchValue = right.second.matchValues[i];
                // todo?
            }
            if (left.first->IsConst() && !right.first->IsConst() && subjectIsConst)
            {
                return true;
            }
            else if (left.first->IsConst() && !right.first->IsConst() && !subjectIsConst)
            {
                return false;
            }
            else if (right.first->IsConst() && !left.first->IsConst() && subjectIsConst)
            {
                return false;
            }
            else if (right.first->IsConst() && !left.first->IsConst() && !subjectIsConst)
            {
                return true;
            }
        }
        return false;
    }
    bool subjectIsConst;
};

CallableSymbol* FunctionGroupSymbol::ResolveOverload(const std::vector<Symbol*>& argumentSymbols, bool subjectIsConst)
{
    int arity = argumentSymbols.size();
    std::vector<CallableSymbol*> viableFunctions;
    for (const std::unique_ptr<FunctionSymbol>& function : functions)
    {
        if (function->Arity() == arity)
        {
            viableFunctions.push_back(function.get());
        }
    }
    if (viableFunctions.empty())
    {
        for (const std::unique_ptr<FunctionDeclarationSymbol>& functionDeclaration : functionDeclarations)
        {
            if (functionDeclaration->Arity() == arity)
            {
                viableFunctions.push_back(functionDeclaration.get());
            }
        }
    }
    if (viableFunctions.empty())
    {
        return nullptr;
    }
    else if (viableFunctions.size() == 1)
    {
        return viableFunctions.front();
    }
    else
    {
        std::vector<std::pair<CallableSymbol*, FunctionMatch>> functionMatches;
        int n = viableFunctions.size();
        for (int i = 0; i < n; ++i)
        {
            CallableSymbol* viableFunction = viableFunctions[i];
            FunctionMatch functionMatch;
            for (int i = 0; i < arity; ++i)
            {
                ParameterSymbol* parameter = viableFunction->Parameters()[i];
                TypeSymbol* parameterType = parameter->GetType();
                Symbol* argumentSymbol = argumentSymbols[i];
                TypeSymbol* argumentType = nullptr;
                if (argumentSymbol)
                {
                    argumentType = argumentSymbol->GetType();
                }
                int matchValue = parameterType->MatchValue(argumentType);
                functionMatch.matchValues.push_back(matchValue);
            }
            functionMatches.push_back(std::make_pair(viableFunction, functionMatch));
        }
        std::sort(functionMatches.begin(), functionMatches.end(), BetterFunctionMatch(subjectIsConst));
        if (BetterFunctionMatch(subjectIsConst)(functionMatches[0], functionMatches[1]))
        {
            CallableSymbol* bestMatch = functionMatches[0].first;
            return bestMatch;
        }
        return nullptr;
    }
}

} } // namespace sngcpp::symbols

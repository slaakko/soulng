// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/ParameterSymbol.hpp>
#include <sngcpp/symbols/FunctionSymbol.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp { namespace symbols {

using namespace soulng::unicode;

ParameterSymbol::ParameterSymbol(const Span& span_, const std::u32string& name_) : Symbol(span_, name_), type(nullptr)
{
}

std::u32string ParameterSymbol::IdStr()
{
    std::u32string idStr = Symbol::IdStr();
    if (Parent()->IsFunctionSymbol())
    {
        FunctionSymbol* function = static_cast<FunctionSymbol*>(Parent());
        std::u32string functionIndexStr = ToUtf32(std::to_string(function->Index()));
        idStr.append(1, '.').append(functionIndexStr);
    }
    else
    {
        throw std::runtime_error("function symbol expected");
    }
    return idStr;
}

std::unique_ptr<sngxml::dom::Element> ParameterSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> parameterElement(new sngxml::dom::Element(U"parameter"));
    parameterElement->SetAttribute(U"type", type->Id());
    return parameterElement;
}

} } // namespace sngcpp::symbols

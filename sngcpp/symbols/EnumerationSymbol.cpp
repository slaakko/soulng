// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/EnumerationSymbol.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp { namespace symbols {

using namespace soulng::unicode;

EnumTypeSymbol::EnumTypeSymbol(const Span& span_, const std::u32string& name_, EnumKey enumKey_) : TypeSymbol(span_, name_), enumKey(enumKey_), baseType(nullptr)
{
}

std::unique_ptr<sngxml::dom::Element> EnumTypeSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> enumTypeElement(new sngxml::dom::Element(U"enumType"));
    enumTypeElement->SetAttribute(U"key", ToString(enumKey));
    if (baseType)
    {
        enumTypeElement->SetAttribute(U"baseType", baseType->Id());
    }
    if (GetSpan().Valid())
    {
        enumTypeElement->SetAttribute(U"definitionFile", ToUtf32(fileName));
        enumTypeElement->SetAttribute(U"definitionLine", ToUtf32(std::to_string(GetSpan().line)));
        enumTypeElement->SetAttribute(U"definitionFileId", fileId);
    }
    return enumTypeElement;
}

EnumeratorSymbol::EnumeratorSymbol(const Span& span_, const std::u32string& name_, const std::u32string& value_) : Symbol(span_, name_), value(value_)
{
}

std::unique_ptr<sngxml::dom::Element> EnumeratorSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> enumeratorElement(new sngxml::dom::Element(U"enumerator"));
    enumeratorElement->SetAttribute(U"value", value);
    return enumeratorElement;
}

} } // namespace sngcpp::symbols

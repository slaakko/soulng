// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngxml/serialization/XmlExport.hpp>
#include <soulng/util/TextUtils.hpp>

namespace sngxml { namespace xmlser {

std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& value, const std::string& fieldName)
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    element->SetAttribute(U"value", ToUtf32(value));
    return element;
}

std::unique_ptr<sngxml::dom::Element> ToXml(const std::u16string& value, const std::string& fieldName)
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    element->SetAttribute(U"value", ToUtf32(value));
    return element;
}

std::unique_ptr<sngxml::dom::Element> ToXml(const std::u32string& value, const std::string& fieldName)
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    element->SetAttribute(U"value", value);
    return element;
}

std::unique_ptr<sngxml::dom::Element> ToXml(const uuid& value, const std::string& fieldName)
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    std::string s;
    for (uint8_t x : value)
    {
        s.append(ToHexString(x));
    }
    element->SetAttribute(U"value", ToUtf32(s));
    return element;
}

std::unique_ptr<sngxml::dom::Element> ToXml(const date& value, const std::string& fieldName)
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    element->SetAttribute(U"value", ToUtf32(ToString(value)));
    return element;
}

std::unique_ptr<sngxml::dom::Element> ToXml(const datetime& value, const std::string& fieldName)
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    element->SetAttribute(U"value", ToUtf32(ToString(value)));
    return element;
}

std::unique_ptr<sngxml::dom::Element> ToXml(const time_point& value, const std::string& fieldName)
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    element->SetAttribute(U"value", ToUtf32(ToString(value)));
    return element;
}

std::unique_ptr<sngxml::dom::Element> ToXml(const duration& value, const std::string& fieldName)
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    element->SetAttribute(U"value", ToUtf32(ToString(value)));
    return element;
}

std::string MakeClassNameStr(const std::string& typeName)
{
    std::string::size_type spacePos = typeName.find(' ');
    return typeName.substr(spacePos + 1);
}

} } // namespace sngxml::xmlser
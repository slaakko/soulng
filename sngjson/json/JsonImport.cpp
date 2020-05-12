// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngjson/json/JsonImport.hpp>
#include <soulng/util/Json.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngjson { namespace json {

void FromJson(soulng::util::JsonValue* value, int& field)
{
    if (value->Type() == soulng::util::JsonValueType::number)
    {
        soulng::util::JsonNumber* number = static_cast<soulng::util::JsonNumber*>(value);
        field = static_cast<int>(number->Value());
    }
}

void FromJson(soulng::util::JsonValue* value, double& field)
{
    if (value->Type() == soulng::util::JsonValueType::number)
    {
        soulng::util::JsonNumber* number = static_cast<soulng::util::JsonNumber*>(value);
        field = number->Value();
    }
}

void FromJson(soulng::util::JsonValue* value, bool& field)
{
    if (value->Type() == soulng::util::JsonValueType::boolean)
    {
        soulng::util::JsonBool* b = static_cast<soulng::util::JsonBool*>(value);
        field = b->Value();
    }
}

void FromJson(soulng::util::JsonValue* value, std::string& field)
{
    if (value->Type() == soulng::util::JsonValueType::string)
    {
        soulng::util::JsonString* s = static_cast<soulng::util::JsonString*>(value);
        field = soulng::unicode::ToUtf8(s->Value());
    }
}

void FromJson(soulng::util::JsonValue* value, std::u16string& field)
{
    if (value->Type() == soulng::util::JsonValueType::string)
    {
        soulng::util::JsonString* s = static_cast<soulng::util::JsonString*>(value);
        field = soulng::unicode::ToUtf16(s->Value());
    }
}

void FromJson(soulng::util::JsonValue* value, std::u32string& field)
{
    if (value->Type() == soulng::util::JsonValueType::string)
    {
        soulng::util::JsonString* s = static_cast<soulng::util::JsonString*>(value);
        field = s->Value();
    }
}

} } // sngjson::json


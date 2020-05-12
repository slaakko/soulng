// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGJSON_JSON_IMPORT_INCLUDED
#define SNGJSON_JSON_IMPORT_INCLUDED
#include <sngjson/json/JsonApi.hpp>
#include <soulng/util/Json.hpp>
#include <string>
#include <vector>

namespace sngjson { namespace json {

void FromJson(soulng::util::JsonValue* value, int& field);
void FromJson(soulng::util::JsonValue* value, double& field);
void FromJson(soulng::util::JsonValue* value, bool& field);
void FromJson(soulng::util::JsonValue* value, std::string& field);
void FromJson(soulng::util::JsonValue* value, std::u16string& field);
void FromJson(soulng::util::JsonValue* value, std::u32string& field);

template<typename T>
SNGJSON_JSON_API void FromJson(soulng::util::JsonValue* value, std::vector<T>& field)
{
    if (value->Type() == soulng::util::JsonValueType::array)
    {
        soulng::util::JsonArray* a = static_cast<soulng::util::JsonArray*>(value);
        int n = a->Count();
        for (int i = 0; i < n; ++i)
        {
            soulng::util::JsonValue* itemValue = (*a)[i];
            T item;
            FromJson(itemValue, item);
            field.push_back(item);
        }
    }
}

template<typename T>
concept JsonConstructible = requires(T t, soulng::util::JsonValue* value) { t(value); };

template<typename T>
    requires JsonConstructible<T>
SNGJSON_JSON_API
void FromJson(soulng::util::JsonValue* value, std::vector<T>& field)
{
    if (value->Type() == soulng::util::JsonValueType::array)
    {
        soulng::util::JsonArray* a = static_cast<soulng::util::JsonArray*>(value);
        int n = a->Count();
        for (int i = 0; i < n; ++i)
        {
            soulng::util::JsonValue* itemValue = (*a)[i];
            T item(itemValue);
            field.push_back(item);
        }
    }
}

template<typename T>
    requires JsonConstructible<T>
SNGJSON_JSON_API
void FromJson(soulng::util::JsonValue* value, T& field)
{
    field = T(value);
}

} } // sngjson::json

#endif // SNGJSON_JSON_IMPORT_INCLUDED

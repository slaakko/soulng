// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGJSON_JSON_API_INCLUDED
#define SNGJSON_JSON_API_INCLUDED

#ifdef _WIN32

#ifdef SNGJSON_JSON_EXPORTS
#define SNGJSON_JSON_API __declspec(dllexport)
#else
#define SNGJSON_JSON_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngjson.lib")
#else
#pragma comment(lib, "sngjsond.lib")
#endif

#endif

#else

#define SNGJSON_JSON_API

#endif

#endif // SNGJSON_JSON_API_INCLUDED

// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSER_API_INCLUDED
#define SOULNG_PARSER_API_INCLUDED

#ifndef NDEBUG
#define SOULNG_PARSER_DEBUG_SUPPORT
#endif

#ifdef _WIN32

#ifdef SOULNG_PARSER_EXPORTS
#define SOULNG_PARSER_API __declspec(dllexport)
#else

#define SOULNG_PARSER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngparser.lib")
#else
#pragma comment(lib, "sngparserd.lib")
#endif

#endif

#else

#define SOULNG_PARSER_API

#endif

#endif // SOULNG_PARSER_API_INCLUDED

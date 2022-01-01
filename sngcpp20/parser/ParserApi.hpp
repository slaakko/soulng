// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef PARSER_API_INCLUDED
#define PARSER_API_INCLUDED

#ifdef _WIN32

#ifdef PARSER_EXPORTS
#define PARSER_API __declspec(dllexport)
#else
#define PARSER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpp20_parser.lib")
#else
#pragma comment(lib, "sngcpp20_parserd.lib")
#endif

#endif

#else

#define PARSER_API

#endif

#endif // PARSER_API_INCLUDED

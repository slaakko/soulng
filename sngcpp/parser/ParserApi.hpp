// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PARSER_API_INCLUDED
#define SNGCPP_PARSER_API_INCLUDED

#ifdef _WIN32

#ifdef SNGCPP_PARSER_EXPORTS
#define SNGCPP_PARSER_API __declspec(dllexport)
#else
#define SNGCPP_PARSER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcppparser.lib")
#else
#pragma comment(lib, "sngcppparserd.lib")
#endif

#endif

#else

#define SNGCPP_PARSER_API

#endif

#endif // SNGCPP_PARSER_API_INCLUDED

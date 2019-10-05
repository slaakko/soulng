// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_API_INCLUDED
#define SNGCPP_AST_API_INCLUDED

#ifdef _WIN32

#ifdef SNGCPP_AST_EXPORTS
#define SNGCPP_AST_API __declspec(dllexport)
#else
#define SNGCPP_AST_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcppast.lib")
#else
#pragma comment(lib, "sngcppastd.lib")
#endif

#endif

#else

#define SNGCPP_AST_API

#endif

#endif // SNGCPP_AST_API_INCLUDED

// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_API_INCLUDED
#define SNGCPP_AST_API_INCLUDED

#ifdef _WIN32

#ifdef AST_EXPORTS
#define AST_API __declspec(dllexport)
#else
#define AST_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpp20_ast.lib")
#else
#pragma comment(lib, "sngcpp20_astd.lib")
#endif

#endif

#else

#define AST_API

#endif

#endif // SNGCPP_AST_API_INCLUDED


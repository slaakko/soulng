// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_AST_API_INCLUDED
#define CMAJOR_AST_API_INCLUDED

#ifdef _WIN32

#ifdef CMAJOR_AST_EXPORTS
#define CMAJOR_AST_API __declspec(dllexport)
#else
#define CMAJOR_AST_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "cmajorast.lib")
#else
#pragma comment(lib, "cmajorastd.lib")
#endif

#endif

#else

#define CMAJOR_AST_API

#endif

#endif // CMAJOR_AST_API_INCLUDED

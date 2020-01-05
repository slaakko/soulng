// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_LEXER_API_INCLUDED
#define SNGCPP_LEXER_API_INCLUDED

#ifdef _WIN32

#ifdef SNGCPP_LEXER_EXPORTS
#define SNGCPP_LEXER_API __declspec(dllexport)
#else
#define SNGCPP_LEXER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpplexer.lib")
#else
#pragma comment(lib, "sngcpplexerd.lib")
#endif

#endif

#else

#define SNGCPP_LEXER_API

#endif

#endif // SNGCPP_LEXER_API_INCLUDED

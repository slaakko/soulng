// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef LEXER_API_INCLUDED
#define LEXER_API_INCLUDED

#ifdef _WIN32

#ifdef LEXER_EXPORTS
#define LEXER_API __declspec(dllexport)
#else
#define LEXER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpp20_lexer.lib")
#else
#pragma comment(lib, "sngcpp20_lexerd.lib")
#endif

#endif

#else

#define LEXER_API

#endif

#endif // LEXER_API_INCLUDED

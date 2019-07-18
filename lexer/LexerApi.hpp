// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_API_INCLUDED
#define SOULNG_LEXER_API_INCLUDED

#ifdef _WIN32

#ifdef LEXER_EXPORTS
#define LEXER_API __declspec(dllexport)
#else
#define LEXER_API __declspec(dllimport)
#endif

#else

#define LEXER_API

#endif

#endif // SOULNG_LEXER_API_INCLUDED

// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_LEXER_API_INCLUDED
#define CMAJOR_LEXER_API_INCLUDED

#ifdef _WIN32

#ifdef CMAJOR_LEXER_EXPORTS
#define CMAJOR_LEXER_API __declspec(dllexport)
#else

#define CMAJOR_LEXER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "cmajorlexer.lib")
#else
#pragma comment(lib, "cmajorlexerd.lib")
#endif

#endif

#else

#define CMAJOR_LEXER_API

#endif

#endif // CMAJOR_LEXER_API_INCLUDED


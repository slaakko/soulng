// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_LEXER_API_INCLUDED
#define CMAJOR_LEXER_API_INCLUDED

#ifdef _WIN32

#ifdef CMAJORLEXER_EXPORTS
#define CMAJOR_LEXER_API __declspec(dllexport)
#else
#define CMAJOR_LEXER_API __declspec(dllimport)
#endif

#else

#define CMAJOR_LEXER_API

#endif

#endif // CMAJOR_LEXER_API_INCLUDED


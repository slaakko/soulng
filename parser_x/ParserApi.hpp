// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSER_API_INCLUDED
#define SOULNG_PARSER_API_INCLUDED

#ifdef _WIN32

#ifdef PARSER_EXPORTS
#define PARSER_API __declspec(dllexport)
#else
#define PARSER_API __declspec(dllimport)
#endif

#else

#define PARSER_API

#endif

#endif // SOULNG_PARSER_API_INCLUDED

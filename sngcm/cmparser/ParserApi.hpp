// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCM_PARSER_API_INCLUDED
#define SNGCM_PARSER_API_INCLUDED

#ifdef _WIN32

#ifdef SNGCM_PARSER_EXPORTS
#define SNGCM_PARSER_API __declspec(dllexport)
#else

#define SNGCM_PARSER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcmparser.lib")
#else
#pragma comment(lib, "sngcmparserd.lib")
#endif

#endif

#else

#define SNGCM_PARSER_API

#endif

#endif // SNGCM_PARSER_API_INCLUDED

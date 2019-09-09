// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_PARSER_API_INCLUDED
#define CMAJOR_PARSER_API_INCLUDED

#ifdef _WIN32

#ifdef CMAJOR_PARSER_EXPORTS
#define CMAJOR_PARSER_API __declspec(dllexport)
#else

#define CMAJOR_PARSER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "cmajorparser.lib")
#else
#pragma comment(lib, "cmajorparserd.lib")
#endif

#endif

#else

#define CMAJOR_PARSER_API

#endif

#endif // CMAJOR_PARSER_API_INCLUDED

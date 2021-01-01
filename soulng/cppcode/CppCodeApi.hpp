// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CPPCODE_API_INCLUDED
#define SOULNG_CPPCODE_API_INCLUDED

#ifdef _WIN32

#ifdef CPPCODE_EXPORTS
#define CPPCODE_API __declspec(dllexport)
#else
#define CPPCODE_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcppcode.lib")
#else
#pragma comment(lib, "sngcppcoded.lib")
#endif

#endif

#else

#define CPPCODE_API

#endif

#endif // SOULNG_CPPCODE_API_INCLUDED

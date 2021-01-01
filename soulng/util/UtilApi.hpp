// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_UTIL_API_INCLUDED
#define SOULNG_UTIL_API_INCLUDED

#ifdef _WIN32

#ifdef UTIL_EXPORTS
#define UTIL_API __declspec(dllexport)
#else
#define UTIL_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngutil.lib")
#else
#pragma comment(lib, "sngutild.lib")
#endif

#endif

#else

#define UTIL_API

#endif

#endif // SOULNG_UTIL_API_INCLUDED

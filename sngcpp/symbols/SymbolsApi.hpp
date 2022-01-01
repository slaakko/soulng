// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_API_INCLUDED
#define SNGCPP_SYMBOLS_API_INCLUDED

#ifdef _WIN32

#ifdef SNGCPP_SYMBOLS_EXPORTS
#define SNGCPP_SYMBOLS_API __declspec(dllexport)
#else
#define SNGCPP_SYMBOLS_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcppsymbols.lib")
#else
#pragma comment(lib, "sngcppsymbolsd.lib")
#endif

#endif

#else

#define SNGCPP_SYMBOLS_API

#endif

#endif // SNGCPP_SYMBOLS_API_INCLUDED

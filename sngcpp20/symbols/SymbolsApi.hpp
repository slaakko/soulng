// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_API_INCLUDED
#define SNGCPP_SYMBOLS_API_INCLUDED

#ifdef _WIN32

#ifdef SYMBOLS_EXPORTS
#define SYMBOLS_API __declspec(dllexport)
#else
#define SYMBOLS_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpp20_symbols.lib")
#else
#pragma comment(lib, "sngcpp20_symbolsd.lib")
#endif

#endif

#else

#define SYMBOLS_API

#endif

#endif // SNGCPP_SYMBOLS_API_INCLUDED



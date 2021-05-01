// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_API_INCLUDED
#define SNGCPP_PP_API_INCLUDED

#ifdef _WIN32

#ifdef PP_EXPORTS
#define PP_API __declspec(dllexport)
#else
#define PP_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpp20_pp.lib")
#else
#pragma comment(lib, "sngcpp20_ppd.lib")
#endif

#endif

#else

#define PP_API

#endif

#endif // SNGCPP_PP_API_INCLUDED

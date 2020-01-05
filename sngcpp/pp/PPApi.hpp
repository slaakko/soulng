// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_API_INCLUDED
#define SNGCPP_PP_API_INCLUDED

#ifdef _WIN32

#ifdef SNGCPP_PP_EXPORTS
#define SNGCPP_PP_API __declspec(dllexport)
#else
#define SNGCPP_PP_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpppp.lib")
#else
#pragma comment(lib, "sngcppppd.lib")
#endif

#endif

#else

#define SNGCPP_PP_API

#endif

#endif // SNGCPP_PP_API_INCLUDED

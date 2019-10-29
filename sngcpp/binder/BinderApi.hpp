// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_BINDER_API_INCLUDED
#define SNGCPP_BINDER_API_INCLUDED

#ifdef _WIN32

#ifdef SNGCPP_BINDER_EXPORTS
#define SNGCPP_BINDER_API __declspec(dllexport)
#else
#define SNGCPP_BINDER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcppbinder.lib")
#else
#pragma comment(lib, "sngcppbinderd.lib")
#endif

#endif

#else

#define SNGCPP_BINDER_API

#endif

#endif // SNGCPP_BINDER_API_INCLUDED

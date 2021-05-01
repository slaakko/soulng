// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PROJECT_API_INCLUDED
#define SNGCPP_PROJECT_API_INCLUDED

#ifdef _WIN32

#ifdef PROJECT_EXPORTS
#define PROJECT_API __declspec(dllexport)
#else
#define PROJECT_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpp20_project.lib")
#else
#pragma comment(lib, "sngcpp20_projectd.lib")
#endif

#endif

#else

#define PROJECT_API

#endif

#endif // SNGCPP_PROJECT_API_INCLUDED

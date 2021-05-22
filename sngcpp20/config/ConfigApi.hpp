// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_CONFIG_API_INCLUDED
#define SNGCPP_CONFIG_API_INCLUDED

#ifdef _WIN32

#ifdef CONFIG_EXPORTS
#define CONFIG_API __declspec(dllexport)
#else
#define CONFIG_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpp20_config.lib")
#else
#pragma comment(lib, "sngcpp20_configd.lib")
#endif

#endif

#else

#define CONFIG_API

#endif

#endif // SNGCPP_CONFIG_API_INCLUDED

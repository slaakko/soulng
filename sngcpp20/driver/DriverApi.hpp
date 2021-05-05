// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_DRIVER_API_INCLUDED
#define SNGCPP_DRIVER_API_INCLUDED

#ifdef _WIN32

#ifdef DRIVER_EXPORTS
#define DRIVER_API __declspec(dllexport)
#else
#define DRIVER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcpp20_driver.lib")
#else
#pragma comment(lib, "sngcpp20_driverd.lib")
#endif

#endif

#else

#define DRIVER_API

#endif

#endif // SNGCPP_DRIVER_API_INCLUDED

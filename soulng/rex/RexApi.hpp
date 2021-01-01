// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_REX_API_INCLUDED
#define SOULNG_REX_API_INCLUDED

#ifdef _WIN32

#ifdef SOULNG_REX_EXPORTS
#define SOULNG_REX_API __declspec(dllexport)
#else
#define SOULNG_REX_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngrex.lib")
#else
#pragma comment(lib, "sngrexd.lib")
#endif

#endif

#else

#define SOULNG_REX_API

#endif

#endif // SOULNG_REX_API_INCLUDED

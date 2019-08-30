// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CODEDOM_API_INCLUDED
#define SOULNG_CODEDOM_API_INCLUDED

#ifdef _WIN32

#ifdef CODEDOM_EXPORTS
#define CODEDOM_API __declspec(dllexport)
#else
#define CODEDOM_API __declspec(dllimport)
#endif

#else

#define CODEDOM_API

#endif

#endif // SOULNG_CODEDOM_API_INCLUDED

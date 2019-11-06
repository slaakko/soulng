// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCM_WRITER_API_INCLUDED
#define SNGCM_WRITER_API_INCLUDED

#ifdef _WIN32

#ifdef SNGCM_WRITER_EXPORTS
#define SNGCM_WRITER_API __declspec(dllexport)
#else
#define SNGCM_WRITER_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngcmwriter.lib")
#else
#pragma comment(lib, "sngcmwriterd.lib")
#endif

#endif

#else

#define SNGCM_WRITER_API

#endif

#endif // SNGCM_WRITER_API_INCLUDED

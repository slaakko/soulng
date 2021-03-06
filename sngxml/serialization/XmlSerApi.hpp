// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGXML_SERIALIZATION_API_INCLUDED
#define SNGXML_SERIALIZATION_API_INCLUDED

#ifdef _WIN32

#ifdef SNGXML_SERIALIZATION_EXPORTS
#define SNGXML_SERIALIZATION_API __declspec(dllexport)
#else
#define SNGXML_SERIALIZATION_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "sngxmlser.lib")
#else
#pragma comment(lib, "sngxmlserd.lib")
#endif

#endif

#else

#define SNGXML_SERIALIZATION_API

#endif

#endif // SNGXML_SERIALIZATION_API_INCLUDED

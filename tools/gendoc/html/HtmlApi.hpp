// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_HTML_API_INCLUDED
#define GENDOC_HTML_API_INCLUDED

#ifdef _WIN32

#ifdef GENDOC_HTML_EXPORTS
#define GENDOC_HTML_API __declspec(dllexport)
#else
#define GENDOC_HTML_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "gendochtml.lib")
#else
#pragma comment(lib, "gendochtmld.lib")
#endif

#endif

#else

#define GENDOC_HTML_API

#endif

#endif // GENDOC_HTML_API_INCLUDED

#ifndef QUERY_API_INCLUDED
#define QUERY_API_INCLUDED

#ifdef QUERY_EXPORTS
#define QUERY_API __declspec(dllexport)
#else
#define QUERY_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "soulng_library_query.lib")
#else
#pragma comment(lib, "soulng_library_queryd.lib")
#endif

#endif

#endif // QUERY_API_INCLUDED

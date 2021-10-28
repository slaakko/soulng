#ifndef LIBRARY_XML_API_INCLUDED
#define LIBRARY_XML_API_INCLUDED

#ifdef LIBRARY_XML_EXPORTS
#define LIBRARY_XML_API __declspec(dllexport)
#else
#define LIBRARY_XML_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "soulng_library_library_xml.lib")
#else
#pragma comment(lib, "soulng_library_library_xmld.lib")
#endif

#endif

#endif // LIBRARY_XML_API_INCLUDED


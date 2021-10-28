#ifndef MESSAGE_XML_API_INCLUDED
#define MESSAGE_XML_API_INCLUDED

#ifdef MESSAGE_XML_EXPORTS
#define MESSAGE_XML_API __declspec(dllexport)
#else
#define MESSAGE_XML_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "soulng_library_message_xml.lib")
#else
#pragma comment(lib, "soulng_library_message_xmld.lib")
#endif

#endif 

#endif // MESSAGE_XML_API_INCLUDED

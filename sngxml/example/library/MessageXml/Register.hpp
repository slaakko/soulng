#ifndef MESSAGE_XML_REGISTER_INCLUDED
#define MESSAGE_XML_REGISTER_INCLUDED
#include <MessageXml/Api.hpp>

namespace message_xml {

const int helloLibraryRequestClassId = 100;
const int helloLibraryReplyClassId = 101;
const int initLibraryRequestClassId = 102;
const int initLibraryReplyClassId = 103;
const int stopLibraryRequestClassId = 104;
const int stopLibraryReplyClassId = 105;
const int queryRequestClassId = 106;
const int queryReplyClassId = 107;

MESSAGE_XML_API void Register();

} // message_xml

#endif // MESSAGE_XML_REGISTER_INCLUDED

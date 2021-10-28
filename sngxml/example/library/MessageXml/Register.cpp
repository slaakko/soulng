#include <MessageXml/Register.hpp>
#include <MessageXml/LibraryMessage.hpp>
#include <MessageXml/ServerMessage.hpp>

namespace message_xml {

void Register()
{
    HelloLibraryRequest::Register(helloLibraryRequestClassId);
    HelloLibraryReply::Register(helloLibraryReplyClassId);
    InitLibraryRequest::Register(initLibraryRequestClassId);
    InitLibraryReply::Register(initLibraryReplyClassId);
    StopLibraryRequest::Register(stopLibraryRequestClassId);
    StopLibraryReply::Register(stopLibraryReplyClassId);
    QueryRequest::Register(queryRequestClassId);
    QueryReply::Register(queryReplyClassId);
}

} // message_xml
#ifndef MESSAGE_XML_FACTORY_INCLUDED
#define MESSAGE_XML_FACTORY_INCLUDED
#include <MessageXml/LibraryMessage.hpp>
#include <MessageXml/ServerMessage.hpp>
#include <LibraryXml/Library.hpp>

namespace message_xml {

MESSAGE_XML_API HelloLibraryRequest* MakeHelloLibraryRequest(const std::string& libraryName);
MESSAGE_XML_API HelloLibraryReply* MakeHelloLibraryReply(const std::string& libraryName);
MESSAGE_XML_API InitLibraryRequest* MakeInitLibraryRequest(library_xml::Library* library);
MESSAGE_XML_API InitLibraryReply* MakeInitLibraryReply(const std::string& libraryName);
MESSAGE_XML_API StopLibraryRequest* MakeStopLibraryRequest();
MESSAGE_XML_API StopLibraryReply* MakeStopLibraryReply();
MESSAGE_XML_API QueryRequest* MakeQueryRequest(QueryExprNode* queryExpr);
MESSAGE_XML_API QueryReply* MakeQueryReply();

} // message_xml

#endif // MESSAGE_XML_FACTORY_INCLUDED


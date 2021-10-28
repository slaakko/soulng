#include <MessageXml/Factory.hpp>

namespace message_xml {

HelloLibraryRequest* MakeHelloLibraryRequest(const std::string& libraryName)
{
    HelloLibraryRequest* request = new HelloLibraryRequest();
    request->SetRandomObjectId();
    request->libraryName = libraryName;
    return request;
}

HelloLibraryReply* MakeHelloLibraryReply(const std::string& libraryName)
{
    HelloLibraryReply* reply = new HelloLibraryReply();
    reply->SetRandomObjectId();
    reply->libraryName = libraryName;
    return reply;
}

InitLibraryRequest* MakeInitLibraryRequest(library_xml::Library* library)
{
    InitLibraryRequest* request = new InitLibraryRequest();
    request->SetRandomObjectId();
    request->library = library;
    return request;
}

InitLibraryReply* MakeInitLibraryReply(const std::string& libraryName)
{
    InitLibraryReply* reply = new InitLibraryReply();
    reply->SetRandomObjectId();
    reply->libraryName = libraryName;
    return reply;
}

StopLibraryRequest* MakeStopLibraryRequest()
{
    StopLibraryRequest* request = new StopLibraryRequest();
    request->SetRandomObjectId();
    return request;
}

StopLibraryReply* MakeStopLibraryReply()
{
    StopLibraryReply* reply = new StopLibraryReply();
    reply->SetRandomObjectId();
    return reply;
}

QueryRequest* MakeQueryRequest(QueryExprNode* queryExpr)
{
    QueryRequest* request = new QueryRequest();
    request->SetRandomObjectId();
    request->query.Reset(queryExpr);
    return request;
}

QueryReply* MakeQueryReply()
{
    QueryReply* reply = new QueryReply();
    reply->SetRandomObjectId();
    return reply;
}

} // message_xml

#include <Server/ServerThread.hpp>
#include <Server/Server.hpp>
#include <MessageXml/Register.hpp>
#include <sngxml/serialization/XmlBundle.hpp>
#include <sngxml/serialization/XmlContainer.hpp>

namespace server {

ServerThread::ServerThread(TcpSocket&& socket_) : socket(std::move(socket_)), exiting(false), depth(-1)
{
}

void ServerThread::Run()
{
    while (!exiting)
    {
        std::string requestXml = soulng::util::ReadStr(socket);
        std::unique_ptr<sngxml::xmlser::XmlBundle> requestBundle = sngxml::xmlser::ToXmlBundle(requestXml);
        if (requestBundle)
        {
            depth = -1;
            sngxml::xmlser::XmlSerializable* requestSerializable(requestBundle->Root());
            message_xml::unique_xml_ptr<sngxml::xmlser::XmlSerializable> reply(ProcessRequest(requestSerializable));
            sngxml::xmlser::XmlContainer newContainer;
            sngxml::xmlser::XmlContainer* container = reply->Container();
            if (!container)
            {
                newContainer.Add(reply.Get());
                container = &newContainer;
            }
            std::unique_ptr<sngxml::xmlser::XmlBundle> replyBundle = container->CreateBundle(reply.Get(), sngxml::xmlser::XmlBundleKind::deep, depth);
            std::string replyXml = replyBundle->ToXmlString();
            soulng::util::Write(socket, replyXml);
        }
    }
}

sngxml::xmlser::XmlSerializable* ServerThread::ProcessRequest(sngxml::xmlser::XmlSerializable* requestSerializable)
{
    int requestClassId = requestSerializable->ClassId();
    switch (requestClassId)
    {
        case message_xml::queryRequestClassId:
        {
            message_xml::QueryRequest* queryRequest = static_cast<message_xml::QueryRequest*>(requestSerializable);
            return ProcessRequest(queryRequest);
        }
        default:
        {
            throw std::runtime_error("ServerThread: unknown request id " + std::to_string(requestClassId) + " received");
        }
    }
    return nullptr;
}

sngxml::xmlser::XmlSerializable* ServerThread::ProcessRequest(message_xml::QueryRequest* queryRequest)
{
    SendQueryToLibraries(queryRequest, &replyQueue);
    depth = 1;
    int n = LibraryClientCount();
    std::unique_ptr<message_xml::QueryReply> queryReply(new message_xml::QueryReply());
    queryReply->SetRandomObjectId();
    for (int i = 0; i < n; ++i)
    {
        message_xml::QueueItem item = replyQueue.Get();
        if (item.msg)
        {
            if (item.msg->ClassId() == message_xml::queryReplyClassId)
            {
                message_xml::QueryReply* libraryClientReply = static_cast<message_xml::QueryReply*>(item.msg);
                for (const message_xml::xml_ptr<library_xml::Object>& object : libraryClientReply->objects)
                {
                    queryReply->objects.push_back(object);
                }
                queryReply->count = queryReply->count + libraryClientReply->count;
                for (const std::string& error : libraryClientReply->errors)
                {
                    if (!error.empty())
                    {
                        queryReply->errors.push_back(error);
                    }
                }
            }
        }
    }
    return queryReply.release();
}

ServerThread* MakeServerThread(TcpSocket&& socket)
{
    return new ServerThread(std::move(socket));
}

void RunServerThread(ServerThread* serverThread)
{
    try
    {
        serverThread->Run();
    }
    catch (...)
    {
    }
}

std::thread StartServerThread(ServerThread* serverThread)
{
    return std::thread(RunServerThread, serverThread);
}

} // server


#include <Library/LibraryThread.hpp>
#include <Library/Library.hpp>
#include <LibraryXml/Query.hpp>
#include <MessageXml/Register.hpp>
#include <MessageXml/Factory.hpp>
#include <sngxml/serialization/XmlBundle.hpp>
#include <thread>
#include <iostream>

namespace library {

LibraryThread::LibraryThread(Library* library_, TcpSocket&& socket_) : library(library_), socket(std::move(socket_)), exiting(false), saveBundle(false), depth(-1)
{
}

void LibraryThread::Run()
{
    try
    {
        while (!exiting)
        {
            std::string requestStr = soulng::util::ReadStr(socket);
            std::unique_ptr<sngxml::xmlser::XmlBundle> requestBundle = sngxml::xmlser::ToXmlBundle(requestStr);
            sngxml::xmlser::XmlSerializable* serializable = requestBundle->Root();
            saveBundle = false;
            depth = -1;
            std::unique_ptr<sngxml::xmlser::XmlSerializable> reply = ProcessRequest(serializable);
            if (saveBundle)
            {
                library->AddBundle(std::move(requestBundle));
            }
            sngxml::xmlser::XmlContainer container;
            container.Add(reply.get());
            std::unique_ptr<sngxml::xmlser::XmlBundle> replyBundle = container.CreateBundle(reply.get(), sngxml::xmlser::XmlBundleKind::deep, depth);
            std::string replyStr = replyBundle->ToXmlString();
            soulng::util::Write(socket, replyStr);
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    library->Exit();
}

std::unique_ptr<sngxml::xmlser::XmlSerializable> LibraryThread::ProcessRequest(sngxml::xmlser::XmlSerializable* request)
{
    switch (request->ClassId())
    {
        case message_xml::helloLibraryRequestClassId: 
        {
            message_xml::HelloLibraryRequest* helloLibraryRequest = static_cast<message_xml::HelloLibraryRequest*>(request);
            return ProcessRequest(helloLibraryRequest);
        }
        case message_xml::initLibraryRequestClassId:
        {
            message_xml::InitLibraryRequest* initLibraryRequest = static_cast<message_xml::InitLibraryRequest*>(request);
            return ProcessRequest(initLibraryRequest);
        }
        case message_xml::queryRequestClassId:
        {
            message_xml::QueryRequest* queryRequest = static_cast<message_xml::QueryRequest*>(request);
            return ProcessRequest(queryRequest);
        }
        case message_xml::stopLibraryRequestClassId:
        {
            message_xml::StopLibraryRequest* stopLibraryRequest = static_cast<message_xml::StopLibraryRequest*>(request);
            return ProcessRequest(stopLibraryRequest);
        }
        default:
        {
            throw std::runtime_error("LibraryThread: unknown request id " + std::to_string(request->ClassId()) + " received");
        }
    }
    return std::unique_ptr<sngxml::xmlser::XmlSerializable>();
}

std::unique_ptr<sngxml::xmlser::XmlSerializable> LibraryThread::ProcessRequest(message_xml::HelloLibraryRequest* request)
{
    library->SetName(request->libraryName);
    return std::unique_ptr<sngxml::xmlser::XmlSerializable>(message_xml::MakeHelloLibraryReply(request->libraryName));
}

std::unique_ptr<sngxml::xmlser::XmlSerializable> LibraryThread::ProcessRequest(message_xml::InitLibraryRequest* request)
{
    saveBundle = true;
    library->SetLibraryXml(request->library.Get());
    return std::unique_ptr<sngxml::xmlser::XmlSerializable>(message_xml::MakeInitLibraryReply(library->Name()));
}

std::unique_ptr<sngxml::xmlser::XmlSerializable> LibraryThread::ProcessRequest(message_xml::QueryRequest* request)
{
    depth = 1;
    library_xml::Library* lib = library->GetLibraryXml();
    library_xml::unique_xml_ptr<library_xml::QueryResult> result = library_xml::Execute(request->query.Get(), lib);
    message_xml::unique_xml_ptr<message_xml::QueryReply> reply(message_xml::MakeQueryReply());
    reply->objects = result->objects;
    reply->count = result->count;
    reply->errors.push_back(result->error);
    return std::unique_ptr<sngxml::xmlser::XmlSerializable>(reply.Release());
}

std::unique_ptr<sngxml::xmlser::XmlSerializable> LibraryThread::ProcessRequest(message_xml::StopLibraryRequest* request)
{
    exiting = true;
    return std::unique_ptr<sngxml::xmlser::XmlSerializable>(message_xml::MakeStopLibraryReply());
}

LibraryThread* MakeLibraryThread(Library* library, TcpSocket&& socket)
{
    return new LibraryThread(library, std::move(socket));
}

void RunLibraryThread(LibraryThread* libraryThread)
{
    try
    {
        libraryThread->Run();
    }
    catch (...)
    {
    }
}

std::thread StartLibraryThread(LibraryThread* libraryThread)
{
    return std::thread(RunLibraryThread, libraryThread);
}

} // library

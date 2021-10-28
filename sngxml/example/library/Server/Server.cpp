#include <Server/ServerThread.hpp>
#include <Server/ServerThread.hpp>
#include <Server/LibraryClient.hpp>
#include <MessageXml/LibraryMessage.hpp>
#include <Config/Config.hpp>
#include <soulng/util/Socket.hpp>
#include <memory>
#include <thread>
#include <iostream>

const bool test = false;

using namespace soulng::util;

namespace server {

class Server
{
public:
    static void Init();
    static void Done();
    static Server& Instance() { return *instance; }
    void SetWaitSeconds(int waitSeconds_) { waitSeconds = waitSeconds_; }
    void Start(int port_);
    void Stop();
    void Run();
    void SendQueryToLibraries(message_xml::QueryRequest* request, message_xml::Queue* replyQueue);
    int LibraryClientCount() const { return libraryClients.size();  }
private:
    Server();
    void StartLibraryClients();
    void Serve();
    void StopLibraryClients();
    void Join();
    static std::unique_ptr<Server> instance;
    std::thread thread;
    int port;
    int waitSeconds;
    TcpSocket socket;
    bool exiting;
    std::vector<std::unique_ptr<ServerThread>> serverThreads;
    std::vector<std::unique_ptr<LibraryClient>> libraryClients;
    std::vector<std::thread> threads;
};

std::unique_ptr<Server> Server::instance;

void Server::Init()
{
    instance.reset(new Server());
}

void Server::Done()
{
    instance.reset();
}

Server::Server() : port(-1), exiting(false), waitSeconds(1)
{
}

void Server::Run()
{
    StartLibraryClients();
    Serve();
    StopLibraryClients();
    Join();
}

void Server::StartLibraryClients()
{
    int libraryPort = port + 1;
    std::vector<std::string> librarieNames = config::GetLibraries();
    int n = librarieNames.size();
    if (test)
    {
        n = std::min(1, n);
    }
    for (int i = 0; i < n; ++i)
    {
        const std::string& libraryName = librarieNames[i];
        std::unique_ptr<LibraryClient> libraryClient(new LibraryClient(libraryName, libraryPort++, waitSeconds));
        LibraryClient* client = libraryClient.get();
        libraryClients.push_back(std::move(libraryClient));
        threads.push_back(StartLibraryClient(client));
    }
    message_xml::Queue helloReplyQueue;
    for (auto& libraryClient : libraryClients)
    {
        libraryClient->Hello(&helloReplyQueue);
    }
    for (int i = 0; i < n; ++i)
    {
        message_xml::QueueItem reply = helloReplyQueue.Get();
        if (reply.client)
        {
            message_xml::HelloLibraryReply* replyMsg = sngxml::xmlser::XmlCast<message_xml::HelloLibraryReply>(reply.msg);
            if (replyMsg)
            {
                std::cout << replyMsg->libraryName << " running" << std::endl;
            }
            reply.client->Release(reply.msg);
        }
    }
    std::cout << "libraries running" << std::endl;
    message_xml::Queue initReplyQueue;
    for (auto& libraryClient : libraryClients)
    {
        libraryClient->Init(&initReplyQueue);
    }
    for (int i = 0; i < n; ++i)
    {
        message_xml::QueueItem reply = initReplyQueue.Get();
        if (reply.client)
        {
            message_xml::InitLibraryReply* replyMsg = sngxml::xmlser::XmlCast<message_xml::InitLibraryReply>(reply.msg);
            if (replyMsg)
            {
                std::cout << replyMsg->libraryName << " initialized" << std::endl;
            }
            reply.client->Release(reply.msg);
        }
    }
    std::cout << "libraries initialized" << std::endl;
}

void Server::Serve()
{
    try
    {
        socket.Bind(port);
        socket.Listen(10);
        while (!exiting)
        {
            TcpSocket client = socket.Accept();
            if (!exiting)
            {
                ServerThread* serverThread = MakeServerThread(std::move(client));
                serverThreads.push_back(std::unique_ptr<ServerThread>(serverThread));
                threads.push_back(std::move(StartServerThread(serverThread)));
            }
        }
    }
    catch (const std::exception&)
    {
    }
}


void Server::StopLibraryClients()
{
    std::cout << "stopping libraries..." << std::endl;
    for (auto& libraryClient : libraryClients)
    {
        libraryClient->Exit();
    }
}

void Server::Join()
{
    for (std::thread& thread : threads)
    {
        try
        {
            thread.join();
        }
        catch (...)
        {
        }
    }
}

void Server::SendQueryToLibraries(message_xml::QueryRequest* request, message_xml::Queue* replyQueue)
{
    for (auto& libraryClient : libraryClients)
    {
        libraryClient->PutRequest(request, -1, nullptr, replyQueue);
    }
}

void RunServer()
{
    Server::Instance().Run();
}

void Server::Start(int port_)
{
    port = port_;
    thread = std::thread(RunServer);
}

void Server::Stop()
{
    std::cout << "exiting..." << std::endl;
    try
    {
        exiting = true;
        TcpSocket client("127.0.0.1", std::to_string(port));
        thread.join();
    }
    catch (const std::exception&)
    {
    }
    std::cout << "exit." << std::endl;
}

void SendQueryToLibraries(message_xml::QueryRequest* request, message_xml::Queue* replyQueue)
{
    Server::Instance().SendQueryToLibraries(request, replyQueue);
}

int LibraryClientCount()
{
    return Server::Instance().LibraryClientCount();
}

void SetWaitSeconds(int waitSeconds)
{
    Server::Instance().SetWaitSeconds(waitSeconds);
}

void StartServer(int port)
{
    Server::Instance().Start(port);
}

void StopServer()
{
    Server::Instance().Stop();
}

void InitServer()
{
    Server::Init();
}

void DoneServer()
{
    Server::Done();
}

} // server

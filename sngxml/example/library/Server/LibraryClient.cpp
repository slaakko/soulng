#include <Server/LibraryClient.hpp>
#include <Config/Config.hpp>
#include <MessageXml/Register.hpp>
#include <MessageXml/Factory.hpp>
#include <sngxml/serialization/XmlContainer.hpp>
#include <sngxml/serialization/XmlBundle.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/MappedInputFile.hpp>

namespace server {

BundleComponent::BundleComponent(sngxml::xmlser::XmlBundle* bundle_) : bundle(bundle_)
{
}

LibraryClient::LibraryClient(const std::string& libraryName_, int port_, int waitSeconds_) : exiting(false), libraryName(libraryName_), port(port_), bundles(this), waitSeconds(waitSeconds_)
{
}

void LibraryClient::Run()
{
    Start();
    Connect();
    Serve();
}

void LibraryClient::Start()
{
    std::string processStartCommand = config::BinDirectoryPath();
#ifdef NDEBUG
    processStartCommand = soulng::util::Path::Combine(processStartCommand, "soulng_library_library.exe");
#else
    processStartCommand = soulng::util::Path::Combine(processStartCommand, "soulng_library_libraryd.exe");
#endif     
    processStartCommand.append(" --port ").append(std::to_string(port));
    clientProcess.reset(new soulng::util::Process(processStartCommand, soulng::util::Process::Redirections::none));
    std::this_thread::sleep_for(std::chrono::seconds{ waitSeconds });
}

void LibraryClient::Connect()
{
    socket.Connect("127.0.0.1", std::to_string(port));
}

void LibraryClient::Hello(message_xml::Queue* replyQueue)
{
    PutRequest(message_xml::MakeHelloLibraryRequest(libraryName), -1, nullptr, replyQueue);
}

void LibraryClient::Init(message_xml::Queue* replyQueue)
{
    std::string libraryFilePath = config::GetLibraryFilePath(libraryName);
    std::string xmlStr = soulng::util::ReadFile(libraryFilePath);
    std::unique_ptr<sngxml::xmlser::XmlBundle> xmlBundle = sngxml::xmlser::ToXmlBundle(xmlStr);
    sngxml::xmlser::XmlBundle* bundle = xmlBundle.get();
    library_xml::Library* library = sngxml::xmlser::XmlCast<library_xml::Library>(bundle->Root());
    if (library)
    {
        std::lock_guard<std::mutex> lock(mtx);
        BundleComponent* component = new BundleComponent(xmlBundle.release());
        bundles.AddChild(component);
        PutRequest(message_xml::MakeInitLibraryRequest(library), -1, component, replyQueue);
    }
    else
    {
        throw std::runtime_error("library expected");
    }
}

void LibraryClient::Serve()
{
    while (!exiting)
    {
        message_xml::QueueItem request = requestQueue.Get();
        if (request.msg)
        {
            sngxml::xmlser::XmlSerializable* reply = Transact(request.msg, request.depth);
            if (request.replyQueue)
            {
                request.replyQueue->Put(message_xml::QueueItem(reply, -1, this, nullptr, nullptr));
            }
            else
            {
                Release(reply);
            }
            if (request.component)
            {
                std::lock_guard<std::mutex> lock(mtx);
                bundles.RemoveChild(request.component);
            }
        }
    }
}

void LibraryClient::SendRequest(sngxml::xmlser::XmlSerializable* request, int depth)
{
    sngxml::xmlser::XmlContainer container; 
    container.Add(request);
    std::unique_ptr<sngxml::xmlser::XmlBundle> bundle = container.CreateBundle(request, sngxml::xmlser::XmlBundleKind::deep, depth);
    std::string requestStr = bundle->ToXmlString();
    soulng::util::Write(socket, requestStr);
}

sngxml::xmlser::XmlSerializable* LibraryClient::ReceiveReply()
{
    std::string replyStr = soulng::util::ReadStr(socket);
    std::unique_ptr<sngxml::xmlser::XmlBundle> xmlBundle = sngxml::xmlser::ToXmlBundle(replyStr);
    sngxml::xmlser::XmlBundle* bundle = xmlBundle.get();
    std::lock_guard<std::mutex> lock(mtx);
    BundleComponent* component = new BundleComponent(xmlBundle.release());
    bundles.AddChild(component);
    sngxml::xmlser::XmlSerializable* root = bundle->Root();
    bundleMap[root] = component;
    return root;
}

void LibraryClient::Release(sngxml::xmlser::XmlSerializable* msg)
{
    std::lock_guard<std::mutex> lock(mtx);
    auto it = bundleMap.find(msg);
    if (it != bundleMap.cend())
    {
        soulng::util::Component* bundleComponent = it->second;
        if (bundleComponent)
        {
            bundles.RemoveChild(bundleComponent);
        }
        bundleMap.erase(msg);
    }
}


sngxml::xmlser::XmlSerializable* LibraryClient::Transact(sngxml::xmlser::XmlSerializable* request, int depth)
{
    SendRequest(request, depth);
    return ReceiveReply();
}

void LibraryClient::PutRequest(sngxml::xmlser::XmlSerializable* request, int depth, soulng::util::Component* bundleComponent, message_xml::Queue* replyQueue)
{
    requestQueue.Put(message_xml::QueueItem(request, depth, this, bundleComponent, replyQueue));
}

void LibraryClient::Exit()
{
    message_xml::Queue stopReplyQueue;
    PutRequest(message_xml::MakeStopLibraryRequest(), -1, nullptr, &stopReplyQueue);
    message_xml::QueueItem reply = stopReplyQueue.Get();
    std::this_thread::sleep_for(std::chrono::seconds{ waitSeconds });
    exiting = true;
    requestQueue.Exit();
    replyQueue.Exit();
}

void RunLibraryClient(LibraryClient* client)
{
    try
    {
        client->Run();
    }
    catch (...)
    {
    }
}

std::thread StartLibraryClient(LibraryClient* client)
{
    return std::thread(RunLibraryClient, client);
}

} // server

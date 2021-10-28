#ifndef SERVER_LIBRARY_CLIENT
#define SERVER_LIBRARY_CLIENT
#include <MessageXml/Queue.hpp>
#include <sngxml/serialization/XmlSerializable.hpp>
#include <sngxml/serialization/XmlBundle.hpp>
#include <soulng/util/SynchronizedQueue.hpp>
#include <soulng/util/Socket.hpp>
#include <soulng/util/Component.hpp>
#include <soulng/util/Container.hpp>
#include <soulng/util/Process.hpp>
#include <thread>
#include <mutex>
#include <unordered_map>

namespace server {

using soulng::util::TcpSocket;

class BundleComponent : public soulng::util::Component
{
public:
    BundleComponent(sngxml::xmlser::XmlBundle* bundle_);
private:
    std::unique_ptr<sngxml::xmlser::XmlBundle> bundle;
};

class LibraryClient : public message_xml::Client, public soulng::util::Component
{
public:
    LibraryClient(const std::string& libraryName_, int port_, int waitSeconds_);
    void Run();
    void Exit();
    void Hello(message_xml::Queue* replyQueue);
    void Init(message_xml::Queue* replyQueue);
    void PutRequest(sngxml::xmlser::XmlSerializable* request, int depth, soulng::util::Component* bundleCoponent, message_xml::Queue* replyQueue);
    void Release(sngxml::xmlser::XmlSerializable* msg) override;
private:
    void Start();
    void Connect();
    void Serve();
    void SendRequest(sngxml::xmlser::XmlSerializable* request, int depth);
    sngxml::xmlser::XmlSerializable* ReceiveReply();
    sngxml::xmlser::XmlSerializable* Transact(sngxml::xmlser::XmlSerializable* request, int depth);
    int port;
    std::string libraryName;
    TcpSocket socket;
    bool exiting;
    int waitSeconds;
    std::mutex mtx;
    message_xml::Queue requestQueue;
    message_xml::Queue replyQueue;
    soulng::util::Container bundles;
    std::unordered_map<sngxml::xmlser::XmlSerializable*, soulng::util::Component*> bundleMap;
    std::unique_ptr<soulng::util::Process> clientProcess;
};

std::thread StartLibraryClient(LibraryClient* client);

} // server

#endif // SERVER_LIBRARY_CLIENT

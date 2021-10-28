#ifndef SERVER_SERVER_THREAD
#define SERVER_SERVER_THREAD
#include <MessageXml/ServerMessage.hpp>
#include <MessageXml/Queue.hpp>
#include <sngxml/serialization/XmlSerializable.hpp>
#include <soulng/util/Socket.hpp>
#include <thread>

namespace server {

using soulng::util::TcpSocket;

class ServerThread
{
public:
    ServerThread(TcpSocket&& socket_);
    void Run();
private:
    sngxml::xmlser::XmlSerializable* ProcessRequest(sngxml::xmlser::XmlSerializable* requestSerializable);
    sngxml::xmlser::XmlSerializable* ProcessRequest(message_xml::QueryRequest* queryRequest);
    TcpSocket socket;
    bool exiting;
    int depth;
    message_xml::Queue replyQueue;
};

ServerThread* MakeServerThread(TcpSocket&& socket);

std::thread StartServerThread(ServerThread* serverThread);

} // server

#endif // SERVER_SERVER_THREAD

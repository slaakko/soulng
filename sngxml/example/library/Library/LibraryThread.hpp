#ifndef LIBRARY_LIBRARY_THREAD
#define LIBRARY_LIBRARY_THREAD
#include <MessageXml/LibraryMessage.hpp>
#include <MessageXml/ServerMessage.hpp>
#include <sngxml/serialization/XmlSerializable.hpp>
#include <soulng/util/Socket.hpp>
#include <thread>

namespace library {

using soulng::util::TcpSocket;

class Library;

class LibraryThread
{
public:
    LibraryThread(Library* library_, TcpSocket&& socket_);
    void Run();
private:
    std::unique_ptr<sngxml::xmlser::XmlSerializable> ProcessRequest(sngxml::xmlser::XmlSerializable* request);
    std::unique_ptr<sngxml::xmlser::XmlSerializable> ProcessRequest(message_xml::HelloLibraryRequest* request);
    std::unique_ptr<sngxml::xmlser::XmlSerializable> ProcessRequest(message_xml::InitLibraryRequest* request);
    std::unique_ptr<sngxml::xmlser::XmlSerializable> ProcessRequest(message_xml::QueryRequest* request);
    std::unique_ptr<sngxml::xmlser::XmlSerializable> ProcessRequest(message_xml::StopLibraryRequest* request);
    Library* library;
    TcpSocket socket;
    bool exiting;
    bool saveBundle;
    int depth;
};

LibraryThread* MakeLibraryThread(Library* library, TcpSocket&& socket);

std::thread StartLibraryThread(LibraryThread* libraryThread);

} // library

#endif // LIBRARY_LIBRARY_THREAD

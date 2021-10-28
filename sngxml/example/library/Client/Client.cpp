#include <Client/Client.hpp>
#include <Query/QueryExprParser.hpp>
#include <MessageXml/Factory.hpp>
#include <soulng/util/Socket.hpp>
#include <soulng/util/TextUtils.hpp>
#include <iostream>

namespace client {

using soulng::util::TcpSocket;

class Client
{
public:
    void Run(int port, bool verbose);
private:
    TcpSocket socket;
    std::unique_ptr<sngxml::xmlser::XmlBundle> replyBundle;
};

void Client::Run(int port, bool verbose)
{
    if (verbose)
    {
        std::cout << "connecting port " << port << "..." << std::endl;
    }
    try
    {
        socket.Connect("127.0.0.1", std::to_string(port));
    }
    catch (const std::exception& ex)
    {
        throw std::runtime_error("could not connect to server, run 'soulng_library_server' first: " + soulng::util::PlatformStringToUtf8(ex.what()));
    }
    if (verbose)
    {
        std::cout << "connected" << std::endl;
    }
    while (true)
    {
        // enter a query e.g. "get book where book.name='Design Patterns'":
        std::cout << "> ";
        std::string line;
        std::getline(std::cin, line);
        if (line == "exit")
        {
            break;
        }
        sngxml::xmlser::XmlContainer container;
        std::unique_ptr<query::QueryExprNode> expr = query::ParseQuery(line, container);
        std::unique_ptr<message_xml::QueryRequest> request(message_xml::MakeQueryRequest(expr.get()));
        container.Add(request.get());
        std::unique_ptr<sngxml::xmlser::XmlBundle> bundle = container.CreateBundle(request.get(), sngxml::xmlser::XmlBundleKind::deep);
        std::string xmlStr = bundle->ToXmlString();
        std::cout << xmlStr << std::endl;
        soulng::util::Write(socket, xmlStr);
        std::string replyXmlStr = soulng::util::ReadStr(socket);
        std::cout << replyXmlStr << std::endl;
        replyBundle = sngxml::xmlser::ToXmlBundle(replyXmlStr);
    }
}

void RunClient(int port, bool verbose)
{
    Client c;
    c.Run(port, verbose);
}

} // client
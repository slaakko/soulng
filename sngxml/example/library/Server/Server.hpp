#ifndef SERVER_SERVER_INCLUDED
#define SERVER_SERVER_INCLUDED
#include <MessageXml/ServerMessage.hpp>
#include <MessageXml/Queue.hpp>

namespace server {

void SetWaitSeconds(int waitSeconds);
void StartServer(int port);
void StopServer();
void InitServer();
void DoneServer();
void SendQueryToLibraries(message_xml::QueryRequest* request, message_xml::Queue* replyQueue);
int LibraryClientCount();
} // server

#endif // SERVER_SERVER_INCLUDED

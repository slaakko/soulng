#include <MessageXml/Queue.hpp>

namespace message_xml {

Client::~Client()
{
}

QueueItem::QueueItem() : msg(), depth(-1), client(nullptr), component(nullptr), replyQueue(nullptr)
{
}

QueueItem::QueueItem(sngxml::xmlser::XmlSerializable* msg_, int depth_, Client* client_, soulng::util::Component* component_, Queue* replyQueue_) : 
    msg(msg_), depth(depth_), client(client_), component(component_), replyQueue(replyQueue_)
{
}

} // message_xml

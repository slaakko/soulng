#ifndef MESSAGE_XML_QUEUE_INCLUDED
#define MESSAGE_XML_QUEUE_INCLUDED
#include <MessageXml/Api.hpp>
#include <sngxml/serialization/XmlSerializable.hpp>
#include <soulng/util/SynchronizedQueue.hpp>
#include <soulng/util/Component.hpp>

namespace message_xml {

struct QueueItem;

using Queue = soulng::util::SynchronizedQueue<QueueItem>;

class MESSAGE_XML_API Client
{
public:
    virtual ~Client();
    virtual void Release(sngxml::xmlser::XmlSerializable* msg) = 0;
};

struct MESSAGE_XML_API QueueItem
{
    QueueItem();
    QueueItem(sngxml::xmlser::XmlSerializable* msg_, int depth_, Client* client_, soulng::util::Component* component_, Queue* replyQueue_);
    sngxml::xmlser::XmlSerializable* msg;
    int depth;
    Client* client;
    soulng::util::Component* component;
    Queue* replyQueue;
};

} // message_xml

#endif // LIBRARY_XML_QUEUE_INCLUDED

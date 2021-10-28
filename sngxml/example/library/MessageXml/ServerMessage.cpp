#include "ServerMessage.hpp"
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace message_xml {

using namespace soulng::unicode;

int QueryRequest::classId = -1;

QueryRequest::QueryRequest()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), query(), dataPtr(nullptr), isOwned(false)
{
}

void* QueryRequest::Create()
{
    return new QueryRequest();
}

void QueryRequest::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<QueryRequest>(classId, &QueryRequest::Create);
}

std::string QueryRequest::StaticClassName()
{
    return "QueryRequest";
}

std::string QueryRequest::ClassName() const
{
    return "QueryRequest";
}

void QueryRequest::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "query", query);
}

std::vector<sngxml::xmlser::XmlPtrBase*> QueryRequest::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    ptrs.push_back(const_cast<xml_ptr<QueryExprNode>*>(&query)); 
    return ptrs;
}

void QueryRequest::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

QueryRequest::~QueryRequest()
{
}

std::unique_ptr<sngxml::dom::Element> QueryRequest::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> QueryRequest::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(query, "query", ctx).release()));
    return element;
}

int QueryReply::classId = -1;

QueryReply::QueryReply()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), objects(), count(), errors(), dataPtr(nullptr), isOwned(false)
{
}

void* QueryReply::Create()
{
    return new QueryReply();
}

void QueryReply::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<QueryReply>(classId, &QueryReply::Create);
}

std::string QueryReply::StaticClassName()
{
    return "QueryReply";
}

std::string QueryReply::ClassName() const
{
    return "QueryReply";
}

void QueryReply::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "objects", objects);
    sngxml::xmlser::FromXml(element, "count", count);
    sngxml::xmlser::FromXml(element, "errors", errors);
}

std::vector<sngxml::xmlser::XmlPtrBase*> QueryReply::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    for (const auto& ptr : objects)
    {
        ptrs.push_back(const_cast<xml_ptr<Object>*>(&ptr));
    }
    return ptrs;
}

void QueryReply::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

QueryReply::~QueryReply()
{
}

std::unique_ptr<sngxml::dom::Element> QueryReply::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> QueryReply::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(objects, "objects", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(count, "count", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(errors, "errors", ctx).release()));
    return element;
}


} // namespace message_xml

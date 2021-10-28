#include "QueryResult.hpp"
#include <LibraryXml/Object.hpp>
#include <LibraryXml/Library.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace library_xml {

using namespace soulng::unicode;

int QueryResult::classId = -1;

QueryResult::QueryResult()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), objects(), count(), error(), dataPtr(nullptr), isOwned(false)
{
}

void* QueryResult::Create()
{
    return new QueryResult();
}

void QueryResult::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<QueryResult>(classId, &QueryResult::Create);
}

std::string QueryResult::StaticClassName()
{
    return "QueryResult";
}

std::string QueryResult::ClassName() const
{
    return "QueryResult";
}

void QueryResult::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "objects", objects);
    sngxml::xmlser::FromXml(element, "count", count);
    sngxml::xmlser::FromXml(element, "error", error);
}

std::vector<sngxml::xmlser::XmlPtrBase*> QueryResult::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    for (const auto& ptr : objects)
    {
        ptrs.push_back(const_cast<xml_ptr<Object>*>(&ptr));
    }
    return ptrs;
}

void QueryResult::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

QueryResult::~QueryResult()
{
}

std::unique_ptr<sngxml::dom::Element> QueryResult::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> QueryResult::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(objects, "objects", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(count, "count", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(error, "error", ctx).release()));
    return element;
}


} // namespace library_xml

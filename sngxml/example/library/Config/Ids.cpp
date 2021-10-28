#include "Ids.hpp"
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

int Ids::classId = -1;

Ids::Ids()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), ids(), dataPtr(nullptr), isOwned(false)
{
}

void* Ids::Create()
{
    return new Ids();
}

void Ids::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Ids>(classId, &Ids::Create);
}

std::string Ids::StaticClassName()
{
    return "Ids";
}

std::string Ids::ClassName() const
{
    return "Ids";
}

void Ids::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "ids", ids);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Ids::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void Ids::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Ids::~Ids()
{
}

std::unique_ptr<sngxml::dom::Element> Ids::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Ids::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(ids, "ids", ctx).release()));
    return element;
}

uuid Ids::Get(int index)
{
    while (index >= ids.size())
    {
        boost::uuids::uuid id = boost::uuids::random_generator()();
        ids.push_back(id);
    }
    return ids[index];
}

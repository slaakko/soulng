#include "Configuration.hpp"
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

int Configuration::classId = -1;

Configuration::Configuration()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), serverPortNumber(), libraries(), dataPtr(nullptr), isOwned(false)
{
}

void* Configuration::Create()
{
    return new Configuration();
}

void Configuration::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Configuration>(classId, &Configuration::Create);
}

std::string Configuration::StaticClassName()
{
    return "Configuration";
}

std::string Configuration::ClassName() const
{
    return "Configuration";
}

void Configuration::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "serverPortNumber", serverPortNumber);
    sngxml::xmlser::FromXml(element, "libraries", libraries);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Configuration::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void Configuration::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Configuration::~Configuration()
{
}

std::unique_ptr<sngxml::dom::Element> Configuration::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Configuration::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(serverPortNumber, "serverPortNumber", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(libraries, "libraries", ctx).release()));
    return element;
}


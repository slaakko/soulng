#include "Object.hpp"
#include <LibraryXml/Library.hpp>
#include <soulng/util/Unicode.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace library_xml {

using namespace soulng::unicode;

int Object::classId = -1;

Object::Object()
     : QueryTarget(), objectId(boost::uuids::nil_uuid()), container(nullptr), library(), dataPtr(nullptr), isOwned(false)
{
}

void* Object::Create()
{
    return new Object();
}

void Object::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Object>(classId, &Object::Create);
}

std::string Object::StaticClassName()
{
    return "Object";
}

std::string Object::ClassName() const
{
    return "Object";
}

void Object::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "library", library);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Object::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    ptrs.push_back(const_cast<xml_ptr<Library>*>(&library)); 
    return ptrs;
}

void Object::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Object::~Object()
{
}

std::unique_ptr<sngxml::dom::Element> Object::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Object::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(library, "library", ctx).release()));
    return element;
}

std::string Object::QueryClassName() const
{
    return "object";
}

void Object::Member(query::QueryContext& context, const std::u32string& memberId) const
{
    if (memberId == U"library")
    {
        context.Stack().Push(new query::TargetQueryValue(library.Get()));
    }
    else
    {
        QueryTarget::Member(context, memberId);
    }
}

} // namespace library_xml

#include "person.hpp"
#include <group.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

int Person::classId = -1;

Person::Person()
     : Author(), groups()
{
}

void* Person::Create()
{
    return new Person();
}

void Person::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Person>(classId, &Person::Create);
}

std::string Person::StaticClassName()
{
    return "Person";
}

std::string Person::ClassName() const
{
    return "Person";
}

void Person::FromXml(sngxml::dom::Element* element)
{
    Author::FromXml(element);
    sngxml::xmlser::FromXml(element, "groups", groups);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Person::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Author::GetPtrs();
    for (const auto& ptr : groups)
    {
        ptrs.push_back(const_cast<xml_ptr<Group>*>(&ptr));
    }
    return ptrs;
}

void Person::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Person::~Person()
{
}

std::unique_ptr<sngxml::dom::Element> Person::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Person::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = Author::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(groups, "groups", ctx).release()));
    return element;
}

void Person::AddGroup(Group* group)
{
    groups.push_back(xml_ptr<Group>(group));
}

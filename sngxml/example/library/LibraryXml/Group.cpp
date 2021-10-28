#include "Group.hpp"
#include <LibraryXml/Person.hpp>
#include <LibraryXml/Record.hpp>
#include <LibraryXml/Library.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace library_xml {

using namespace soulng::unicode;

int Group::classId = -1;

Group::Group()
     : Author(), members()
{
}

void* Group::Create()
{
    return new Group();
}

void Group::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Group>(classId, &Group::Create);
}

std::string Group::StaticClassName()
{
    return "Group";
}

std::string Group::ClassName() const
{
    return "Group";
}

void Group::FromXml(sngxml::dom::Element* element)
{
    Author::FromXml(element);
    sngxml::xmlser::FromXml(element, "members", members);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Group::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Author::GetPtrs();
    for (const auto& ptr : members)
    {
        ptrs.push_back(const_cast<xml_ptr<Person>*>(&ptr));
    }
    return ptrs;
}

void Group::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Group::~Group()
{
}

std::unique_ptr<sngxml::dom::Element> Group::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Group::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = Author::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(members, "members", ctx).release()));
    return element;
}

std::string Group::QueryClassName() const 
{
    return "group";
}

void Group::Select(query::QueryContext& context, const std::u32string& cls) const
{
    context.Stack().Push(new query::BooleanQueryValue(cls == U"group"));
}

void Group::Member(query::QueryContext& context, const std::u32string& memberId) const 
{
    if (memberId == U"members")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Person>& member : members)
        {
            list.push_back(member.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else
    {
        QueryTarget::Member(context, memberId);
    }
}

void Group::AddMember(Person* member)
{
    member->AddGroup(this);
    members.push_back(xml_ptr<Person>(member));
}

} // namespace library_xml

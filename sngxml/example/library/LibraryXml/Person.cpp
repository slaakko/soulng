#include "Person.hpp"
#include <LibraryXml/Book.hpp>
#include <LibraryXml/Film.hpp>
#include <LibraryXml/Group.hpp>
#include <LibraryXml/Record.hpp>
#include <LibraryXml/Piece.hpp>
#include <LibraryXml/Library.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace library_xml {

using namespace soulng::unicode;

int Person::classId = -1;

Person::Person()
     : Author(), dateOfBirth(), groups()
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
    sngxml::xmlser::FromXml(element, "dateOfBirth", dateOfBirth);
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
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(dateOfBirth, "dateOfBirth", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(groups, "groups", ctx).release()));
    return element;
}

std::string Person::QueryClassName() const 
{
    return "person";
}

void Person::Select(query::QueryContext& context, const std::u32string& cls)  const
{
    context.Stack().Push(new query::BooleanQueryValue(cls == U"person"));
}

void Person::Member(query::QueryContext& context, const std::u32string& memberId) const 
{
    if (memberId == U"dateOfBirth")
    {
        context.Stack().Push(new query::DateQueryValue(dateOfBirth));
    }
    else if (memberId == U"groups")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Group>& group : groups)
        {
            list.push_back(group.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else
    {
        Author::Member(context, memberId);
    }
}

void Person::AddBook(Book* book)
{
    AddArtwork(book);
}

void Person::AddFile(Film* film)
{
    AddArtwork(film);
}

void Person::AddPiece(Piece* piece)
{
    AddArtwork(piece);
}

void Person::AddRecord(Record* record)
{
    AddArtwork(record);
}

void Person::AddGroup(Group* group)
{
    groups.push_back(xml_ptr<Group>(group));
}

std::vector<Group*> Person::Groups() const
{
    std::vector<Group*> g;
    for (const xml_ptr<Group>& group : groups)
    {
        g.push_back(group.Get());
    }
    return g;
}

} // namespace library_xml

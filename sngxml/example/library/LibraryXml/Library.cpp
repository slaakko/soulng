#include "Library.hpp"
#include <LibraryXml/Artwork.hpp>
#include <LibraryXml/Author.hpp>
#include <LibraryXml/Book.hpp>
#include <LibraryXml/Film.hpp>
#include <LibraryXml/Group.hpp>
#include <LibraryXml/Person.hpp>
#include <LibraryXml/Piece.hpp>
#include <LibraryXml/Record.hpp>
#include <stdexcept>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace library_xml {

using namespace soulng::unicode;

int Library::classId = -1;

Library::Library()
     : Object(), Component(), name(), objects(), books(), films(), pieces(), records(), people(), groups()
{
}

void* Library::Create()
{
    return new Library();
}

void Library::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Library>(classId, &Library::Create);
}

std::string Library::StaticClassName()
{
    return "Library";
}

std::string Library::ClassName() const
{
    return "Library";
}

void Library::FromXml(sngxml::dom::Element* element)
{
    Object::FromXml(element);
    sngxml::xmlser::FromXml(element, "name", name);
    sngxml::xmlser::FromXml(element, "objects", objects);
    sngxml::xmlser::FromXml(element, "books", books);
    sngxml::xmlser::FromXml(element, "films", films);
    sngxml::xmlser::FromXml(element, "pieces", pieces);
    sngxml::xmlser::FromXml(element, "records", records);
    sngxml::xmlser::FromXml(element, "people", people);
    sngxml::xmlser::FromXml(element, "groups", groups);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Library::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Object::GetPtrs();
    for (const auto& ptr : objects)
    {
        ptrs.push_back(const_cast<xml_ptr<Object>*>(&ptr));
    }
    for (const auto& ptr : books)
    {
        ptrs.push_back(const_cast<xml_ptr<Book>*>(&ptr));
    }
    for (const auto& ptr : films)
    {
        ptrs.push_back(const_cast<xml_ptr<Film>*>(&ptr));
    }
    for (const auto& ptr : pieces)
    {
        ptrs.push_back(const_cast<xml_ptr<Piece>*>(&ptr));
    }
    for (const auto& ptr : records)
    {
        ptrs.push_back(const_cast<xml_ptr<Record>*>(&ptr));
    }
    for (const auto& ptr : people)
    {
        ptrs.push_back(const_cast<xml_ptr<Person>*>(&ptr));
    }
    for (const auto& ptr : groups)
    {
        ptrs.push_back(const_cast<xml_ptr<Group>*>(&ptr));
    }
    return ptrs;
}

void Library::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Library::~Library()
{
}

std::unique_ptr<sngxml::dom::Element> Library::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Library::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = Object::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(name, "name", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(objects, "objects", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(books, "books", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(films, "films", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(pieces, "pieces", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(records, "records", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(people, "people", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(groups, "groups", ctx).release()));
    return element;
}

std::string Library::QueryClassName() const 
{
    return "library";
}

void Library::Member(query::QueryContext& context, const std::u32string& memberId) const
{
    if (memberId == U"name")
    {
        context.Stack().Push(new query::StringQueryValue(soulng::unicode::ToUtf32(name)));
    }
    else if (memberId == U"objects")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Object>& object : objects)
        {
            list.push_back(object.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else if (memberId == U"books")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Book>& book : books)
        {
            list.push_back(book.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else if (memberId == U"films")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Film>& film : films)
        {
            list.push_back(film.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else if (memberId == U"pieces")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Piece>& piece : pieces)
        {
            list.push_back(piece.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else if (memberId == U"records")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Record>& record : records)
        {
            list.push_back(record.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else if (memberId == U"people")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Person>& person : people)
        {
            list.push_back(person.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
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
        Object::Member(context, memberId);
    }
}

void Library::Select(query::QueryContext& context, const std::u32string& cls) const
{
    context.Stack().Push(new query::BooleanQueryValue(cls == U"library"));
}

void Library::Add(Book* book)
{
    xmlContainer.Add(book);
    books.push_back(xml_ptr<Book>(book));
    Author* author = book->GetAuthor();
    if (author)
    {
        author->AddArtwork(book);
    }
    xmlContainer.AddOrReplace(author);
    objectContainer->AddChild(book);
    book->SetLibrary(this);
    objects.push_back(xml_ptr<Object>(book));
}

Book* Library::GetBook(const uuid& id) const
{
    XmlSerializable* s = xmlContainer.Get(id);
    if (s)
    {
        if (Book* book = dynamic_cast<Book*>(s))
        {
            return book;
        }
        else
        {
            throw std::runtime_error("book expected");
        }
    }
    throw std::runtime_error("book not found");
}

void Library::Add(Film* film)
{
    xmlContainer.Add(film);
    films.push_back(xml_ptr<Film>(film));
    Author* author = film->GetAuthor();
    if (author)
    {
        author->AddArtwork(film);
    }
    xmlContainer.AddOrReplace(author);
    objectContainer->AddChild(film);
    film->SetLibrary(this);
    objects.push_back(xml_ptr<Object>(film));
}

Film* Library::GetFilm(const uuid& id) const
{
    XmlSerializable* s = xmlContainer.Get(id);
    if (s)
    {
        if (Film* film = dynamic_cast<Film*>(s))
        {
            return film;
        }
        else
        {
            throw std::runtime_error("film expected");
        }
    }
    throw std::runtime_error("film not found");
}

void Library::Add(Record* record)
{
    xmlContainer.Add(record);
    records.push_back(xml_ptr<Record>(record));
    Author* author = record->GetAuthor();
    if (author)
    {
        author->AddArtwork(record);
    }
    xmlContainer.AddOrReplace(author);
    for (const auto& ptr : record->pieces)
    {
        xmlContainer.AddOrReplace(ptr.Get());
    }
    objectContainer->AddChild(record);
    record->SetLibrary(this);
    objects.push_back(xml_ptr<Object>(record));
}

Record* Library::GetRecord(const uuid& id) const
{
    XmlSerializable* s = xmlContainer.Get(id);
    if (s)
    {
        if (Record* record = dynamic_cast<Record*>(s))
        {
            return record;
        }
        else
        {
            throw std::runtime_error("record expected");
        }
    }
    throw std::runtime_error("record not found");
}

void Library::Add(Piece* piece)
{
    xmlContainer.Add(piece);
    pieces.push_back(xml_ptr<Piece>(piece));
    Author* author = piece->GetAuthor();
    if (author)
    {
        author->AddArtwork(piece);
    }
    xmlContainer.AddOrReplace(author);
    objectContainer->AddChild(piece);
    piece->SetLibrary(this);
    objects.push_back(xml_ptr<Object>(piece));
}

Piece* Library::GetPiece(const uuid& id) const
{
    XmlSerializable* s = xmlContainer.Get(id);
    if (s)
    {
        if (Piece* piece = dynamic_cast<Piece*>(s))
        {
            return piece;
        }
        else
        {
            throw std::runtime_error("piece expected");
        }
    }
    throw std::runtime_error("piece not found");
}

void Library::Add(Person* person)
{
    xmlContainer.Add(person);
    people.push_back(xml_ptr<Person>(person));
    for (const auto& ptr : person->artworks)
    {
        xmlContainer.AddOrReplace(ptr.Get());
    }
    objectContainer->AddChild(person);
    person->SetLibrary(this);
    objects.push_back(xml_ptr<Object>(person));
}

Person* Library::GetPerson(const uuid& id) const
{
    XmlSerializable* s = xmlContainer.Get(id);
    if (s)
    {
        if (Person* person = dynamic_cast<Person*>(s))
        {
            return person;
        }
        else
        {
            throw std::runtime_error("person expected");
        }
    }
    throw std::runtime_error("person not found");
}

void Library::Add(Group* group)
{
    xmlContainer.Add(group);
    groups.push_back(xml_ptr<Group>(group));
    for (const auto& ptr : group->members)
    {
        xmlContainer.AddOrReplace(ptr.Get());
    }
    for (const auto& ptr : group->artworks)
    {
        xmlContainer.AddOrReplace(ptr.Get());
    }
    objectContainer->AddChild(group);
    group->SetLibrary(this);
    objects.push_back(xml_ptr<Object>(group));
}

Group* Library::GetGroup(const uuid& id) const
{
    XmlSerializable* s = xmlContainer.Get(id);
    if (s)
    {
        if (Group* group = dynamic_cast<Group*>(s))
        {
            return group;
        }
        else
        {
            throw std::runtime_error("group expected");
        }
    }
    throw std::runtime_error("group not found");
}

} // namespace library_xml

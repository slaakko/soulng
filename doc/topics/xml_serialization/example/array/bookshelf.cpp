#include "bookshelf.hpp"
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

int Bookshelf::classId = -1;

Bookshelf::Bookshelf()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), books(), dataPtr(nullptr), isOwned(false)
{
}

void* Bookshelf::Create()
{
    return new Bookshelf();
}

void Bookshelf::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Bookshelf>(classId, &Bookshelf::Create);
}

std::string Bookshelf::StaticClassName()
{
    return "Bookshelf";
}

std::string Bookshelf::ClassName() const
{
    return "Bookshelf";
}

void Bookshelf::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "books", books);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Bookshelf::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void Bookshelf::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Bookshelf::~Bookshelf()
{
}

std::unique_ptr<sngxml::dom::Element> Bookshelf::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Bookshelf::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(books, "books", ctx).release()));
    return element;
}

void Bookshelf::AddBook(const Book& book)
{
    books.push_back(book);
}

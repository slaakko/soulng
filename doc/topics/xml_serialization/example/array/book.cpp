#include "book.hpp"
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

int Book::classId = -1;

Book::Book()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), name(), isbn(), author(), published(), publisher(), price(), color(), dataPtr(nullptr), isOwned(false)
{
}

void* Book::Create()
{
    return new Book();
}

void Book::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Book>(classId, &Book::Create);
}

std::string Book::StaticClassName()
{
    return "Book";
}

std::string Book::ClassName() const
{
    return "Book";
}

void Book::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "name", name);
    sngxml::xmlser::FromXml(element, "isbn", isbn);
    sngxml::xmlser::FromXml(element, "author", author);
    sngxml::xmlser::FromXml(element, "published", published);
    sngxml::xmlser::FromXml(element, "publisher", publisher);
    sngxml::xmlser::FromXml(element, "price", price);
    sngxml::xmlser::FromXml(element, "color", color);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Book::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void Book::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Book::~Book()
{
}

std::unique_ptr<sngxml::dom::Element> Book::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Book::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(name, "name", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(isbn, "isbn", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(author, "author", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(published, "published", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(publisher, "publisher", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(price, "price", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(color, "color", ctx).release()));
    return element;
}


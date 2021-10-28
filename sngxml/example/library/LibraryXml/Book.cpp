#include "Book.hpp"
#include <LibraryXml/Author.hpp>
#include <LibraryXml/Library.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace library_xml {

using namespace soulng::unicode;

int Book::classId = -1;

Book::Book()
     : Artwork()
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
    Artwork::FromXml(element);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Book::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Artwork::GetPtrs();
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
    std::unique_ptr<sngxml::dom::Element> element = Artwork::ToXml(fieldName, ctx);
    return element;
}

std::string Book::QueryClassName() const 
{
    return "book";
}

void Book::Select(query::QueryContext& context, const std::u32string& cls)  const
{
    context.Stack().Push(new query::BooleanQueryValue(cls == U"book"));
}

} // namespace library_xml

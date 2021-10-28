#include "Artwork.hpp"
#include <LibraryXml/Author.hpp>
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

int Artwork::classId = -1;

Artwork::Artwork()
     : Object(), Component(), name(), created(), author()
{
}

void* Artwork::Create()
{
    return new Artwork();
}

void Artwork::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Artwork>(classId, &Artwork::Create);
}

std::string Artwork::StaticClassName()
{
    return "Artwork";
}

std::string Artwork::ClassName() const
{
    return "Artwork";
}

void Artwork::FromXml(sngxml::dom::Element* element)
{
    Object::FromXml(element);
    sngxml::xmlser::FromXml(element, "name", name);
    sngxml::xmlser::FromXml(element, "created", created);
    sngxml::xmlser::FromXml(element, "author", author);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Artwork::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Object::GetPtrs();
    ptrs.push_back(const_cast<xml_ptr<Author>*>(&author)); 
    return ptrs;
}

void Artwork::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Artwork::~Artwork()
{
}

std::unique_ptr<sngxml::dom::Element> Artwork::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Artwork::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = Object::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(name, "name", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(created, "created", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(author, "author", ctx).release()));
    return element;
}

std::string Artwork::QueryClassName() const
{
    return "artwork";
}

void Artwork::Member(query::QueryContext& context, const std::u32string& memberId) const
{
    if (memberId == U"name")
    {
        context.Stack().Push(new query::StringQueryValue(soulng::unicode::ToUtf32(name)));
    }
    else if (memberId == U"created")
    {
        context.Stack().Push(new query::DateQueryValue(created));
    }
    else if (memberId == U"author")
    {
        context.Stack().Push(new query::TargetQueryValue(author.Get()));
    }
    else
    {
        Object::Member(context, memberId);
    }
}

} // namespace library_xml

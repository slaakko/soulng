#include "Author.hpp"
#include <LibraryXml/Artwork.hpp>
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

int Author::classId = -1;

Author::Author()
     : Object(), Component(), name(), artworks()
{
}

void* Author::Create()
{
    return new Author();
}

void Author::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Author>(classId, &Author::Create);
}

std::string Author::StaticClassName()
{
    return "Author";
}

std::string Author::ClassName() const
{
    return "Author";
}

void Author::FromXml(sngxml::dom::Element* element)
{
    Object::FromXml(element);
    sngxml::xmlser::FromXml(element, "name", name);
    sngxml::xmlser::FromXml(element, "artworks", artworks);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Author::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Object::GetPtrs();
    for (const auto& ptr : artworks)
    {
        ptrs.push_back(const_cast<xml_ptr<Artwork>*>(&ptr));
    }
    return ptrs;
}

void Author::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Author::~Author()
{
}

std::unique_ptr<sngxml::dom::Element> Author::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Author::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = Object::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(name, "name", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(artworks, "artworks", ctx).release()));
    return element;
}

std::string Author::QueryClassName() const
{
    return "author";
}

void Author::Member(query::QueryContext& context, const std::u32string& memberId) const
{
    if (memberId == U"name")
    {
        context.Stack().Push(new query::StringQueryValue(soulng::unicode::ToUtf32(name)));
    }
    else if (memberId == U"artworks")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Artwork>& artwork : artworks)
        {
            list.push_back(artwork.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else
    {
        Object::Member(context, memberId);
    }
}

void Author::AddArtwork(Artwork* artwork)
{
    artwork->SetAuthor(this);
    for (const xml_ptr<Artwork>& a : artworks)
    {
        if (a.Get() == artwork) return;
    }
    artworks.push_back(xml_ptr<Artwork>(artwork));
}

std::vector<Artwork*> Author::GetArtworks() const
{
    std::vector<Artwork*> a;
    for (const xml_ptr<Artwork>& artwork : artworks)
    {
        a.push_back(artwork.Get());
    }
    return a;
}

} // namespace library_xml

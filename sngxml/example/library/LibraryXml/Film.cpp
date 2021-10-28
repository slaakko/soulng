#include "Film.hpp"
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

int Film::classId = -1;

Film::Film()
     : Artwork()
{
}

void* Film::Create()
{
    return new Film();
}

void Film::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Film>(classId, &Film::Create);
}

std::string Film::StaticClassName()
{
    return "Film";
}

std::string Film::ClassName() const
{
    return "Film";
}

void Film::FromXml(sngxml::dom::Element* element)
{
    Artwork::FromXml(element);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Film::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Artwork::GetPtrs();
    return ptrs;
}

void Film::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Film::~Film()
{
}

std::unique_ptr<sngxml::dom::Element> Film::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Film::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = Artwork::ToXml(fieldName, ctx);
    return element;
}

std::string Film::QueryClassName() const 
{
    return "film";
}

void Film::Select(query::QueryContext& context, const std::u32string& cls)  const
{
    context.Stack().Push(new query::BooleanQueryValue(cls == U"film"));
}

} // namespace library_xml

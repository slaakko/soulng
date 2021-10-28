#include "Piece.hpp"
#include <LibraryXml/Author.hpp>
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

int Piece::classId = -1;

Piece::Piece()
     : Artwork(), records()
{
}

void* Piece::Create()
{
    return new Piece();
}

void Piece::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Piece>(classId, &Piece::Create);
}

std::string Piece::StaticClassName()
{
    return "Piece";
}

std::string Piece::ClassName() const
{
    return "Piece";
}

void Piece::FromXml(sngxml::dom::Element* element)
{
    Artwork::FromXml(element);
    sngxml::xmlser::FromXml(element, "records", records);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Piece::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Artwork::GetPtrs();
    for (const auto& ptr : records)
    {
        ptrs.push_back(const_cast<xml_ptr<Record>*>(&ptr));
    }
    return ptrs;
}

void Piece::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Piece::~Piece()
{
}

std::unique_ptr<sngxml::dom::Element> Piece::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Piece::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = Artwork::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(records, "records", ctx).release()));
    return element;
}

std::string Piece::QueryClassName() const 
{
    return "piece";
}

void Piece::Select(query::QueryContext& context, const std::u32string& cls)  const
{
    context.Stack().Push(new query::BooleanQueryValue(cls == U"piece"));
}

void Piece::Member(query::QueryContext& context, const std::u32string& memberId) const 
{
    if (memberId == U"records")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Record>& record : records)
        {
            list.push_back(record.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else
    {
        Artwork::Member(context, memberId);
    }
}

void Piece::AddRecord(Record* record)
{
    records.push_back(xml_ptr<Record>(record));
}
std::vector<Record*> Piece::GetRecords() const
{
    std::vector<Record*> r;
    for (const xml_ptr<Record>& record : records)
    {
        r.push_back(record.Get());
    }
    return r;
}

} // namespace library_xml

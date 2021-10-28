#include "Record.hpp"
#include <LibraryXml/Piece.hpp>
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

int Record::classId = -1;

Record::Record()
     : Artwork(), pieces()
{
}

void* Record::Create()
{
    return new Record();
}

void Record::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<Record>(classId, &Record::Create);
}

std::string Record::StaticClassName()
{
    return "Record";
}

std::string Record::ClassName() const
{
    return "Record";
}

void Record::FromXml(sngxml::dom::Element* element)
{
    Artwork::FromXml(element);
    sngxml::xmlser::FromXml(element, "pieces", pieces);
}

std::vector<sngxml::xmlser::XmlPtrBase*> Record::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = Artwork::GetPtrs();
    for (const auto& ptr : pieces)
    {
        ptrs.push_back(const_cast<xml_ptr<Piece>*>(&ptr));
    }
    return ptrs;
}

void Record::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

Record::~Record()
{
}

std::unique_ptr<sngxml::dom::Element> Record::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> Record::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = Artwork::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(pieces, "pieces", ctx).release()));
    return element;
}

std::string Record::QueryClassName() const 
{
    return "record";
}

void Record::Select(query::QueryContext& context, const std::u32string& cls)  const
{
    context.Stack().Push(new query::BooleanQueryValue(cls == U"record"));
}

void Record::Member(query::QueryContext& context, const std::u32string& memberId) const 
{
    if (memberId == U"pieces")
    {
        std::vector<QueryTarget*> list;
        for (const xml_ptr<Piece>& piece : pieces)
        {
            list.push_back(piece.Get());
        }
        context.Stack().Push(new query::ListQueryValue(list));
    }
    else
    {
        Artwork::Member(context, memberId);
    }
}

void Record::AddPiece(Piece* piece)
{
    piece->AddRecord(this);
    pieces.push_back(xml_ptr<Piece>(piece));
}

} // namespace library_xml

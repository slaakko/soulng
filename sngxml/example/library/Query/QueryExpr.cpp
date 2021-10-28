#include "QueryExpr.hpp"
#include <soulng/rex/Nfa.hpp>
#include <soulng/rex/Match.hpp>
#include <Query/QueryTarget.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace query {

using namespace soulng::unicode;

int QueryExprNode::classId = -1;

QueryExprNode::QueryExprNode()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), kind(), dataPtr(nullptr), isOwned(false)
{
}

void* QueryExprNode::Create()
{
    return new QueryExprNode();
}

void QueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<QueryExprNode>(classId, &QueryExprNode::Create);
}

std::string QueryExprNode::StaticClassName()
{
    return "QueryExprNode";
}

std::string QueryExprNode::ClassName() const
{
    return "QueryExprNode";
}

void QueryExprNode::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "kind", kind);
}

std::vector<sngxml::xmlser::XmlPtrBase*> QueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void QueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

QueryExprNode::~QueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> QueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> QueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(kind, "kind", ctx).release()));
    return element;
}

int UnaryQueryExprNode::classId = -1;

UnaryQueryExprNode::UnaryQueryExprNode()
     : QueryExprNode(), child()
{
}

void* UnaryQueryExprNode::Create()
{
    return new UnaryQueryExprNode();
}

void UnaryQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<UnaryQueryExprNode>(classId, &UnaryQueryExprNode::Create);
}

std::string UnaryQueryExprNode::StaticClassName()
{
    return "UnaryQueryExprNode";
}

std::string UnaryQueryExprNode::ClassName() const
{
    return "UnaryQueryExprNode";
}

void UnaryQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    QueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "child", child);
}

std::vector<sngxml::xmlser::XmlPtrBase*> UnaryQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = QueryExprNode::GetPtrs();
    ptrs.push_back(const_cast<unique_xml_ptr<QueryExprNode>*>(&child)); 
    return ptrs;
}

void UnaryQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

UnaryQueryExprNode::~UnaryQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> UnaryQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> UnaryQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = QueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(child, "child", ctx).release()));
    return element;
}

int BinaryQueryExprNode::classId = -1;

BinaryQueryExprNode::BinaryQueryExprNode()
     : QueryExprNode(), left(), right()
{
}

void* BinaryQueryExprNode::Create()
{
    return new BinaryQueryExprNode();
}

void BinaryQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<BinaryQueryExprNode>(classId, &BinaryQueryExprNode::Create);
}

std::string BinaryQueryExprNode::StaticClassName()
{
    return "BinaryQueryExprNode";
}

std::string BinaryQueryExprNode::ClassName() const
{
    return "BinaryQueryExprNode";
}

void BinaryQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    QueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "left", left);
    sngxml::xmlser::FromXml(element, "right", right);
}

std::vector<sngxml::xmlser::XmlPtrBase*> BinaryQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = QueryExprNode::GetPtrs();
    ptrs.push_back(const_cast<unique_xml_ptr<QueryExprNode>*>(&left)); 
    ptrs.push_back(const_cast<unique_xml_ptr<QueryExprNode>*>(&right)); 
    return ptrs;
}

void BinaryQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

BinaryQueryExprNode::~BinaryQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> BinaryQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> BinaryQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = QueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(left, "left", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(right, "right", ctx).release()));
    return element;
}

int StringConversionQueryExprNode::classId = -1;

StringConversionQueryExprNode::StringConversionQueryExprNode()
     : UnaryQueryExprNode()
{
}

void* StringConversionQueryExprNode::Create()
{
    return new StringConversionQueryExprNode();
}

void StringConversionQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<StringConversionQueryExprNode>(classId, &StringConversionQueryExprNode::Create);
}

std::string StringConversionQueryExprNode::StaticClassName()
{
    return "StringConversionQueryExprNode";
}

std::string StringConversionQueryExprNode::ClassName() const
{
    return "StringConversionQueryExprNode";
}

void StringConversionQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    UnaryQueryExprNode::FromXml(element);
}

std::vector<sngxml::xmlser::XmlPtrBase*> StringConversionQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = UnaryQueryExprNode::GetPtrs();
    return ptrs;
}

void StringConversionQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

StringConversionQueryExprNode::~StringConversionQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> StringConversionQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> StringConversionQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = UnaryQueryExprNode::ToXml(fieldName, ctx);
    return element;
}

int GetQueryExprNode::classId = -1;

GetQueryExprNode::GetQueryExprNode()
     : QueryExprNode(), cls(), cond()
{
}

void* GetQueryExprNode::Create()
{
    return new GetQueryExprNode();
}

void GetQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<GetQueryExprNode>(classId, &GetQueryExprNode::Create);
}

std::string GetQueryExprNode::StaticClassName()
{
    return "GetQueryExprNode";
}

std::string GetQueryExprNode::ClassName() const
{
    return "GetQueryExprNode";
}

void GetQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    QueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "cls", cls);
    sngxml::xmlser::FromXml(element, "cond", cond);
}

std::vector<sngxml::xmlser::XmlPtrBase*> GetQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = QueryExprNode::GetPtrs();
    ptrs.push_back(const_cast<unique_xml_ptr<QueryExprNode>*>(&cond)); 
    return ptrs;
}

void GetQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

GetQueryExprNode::~GetQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> GetQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> GetQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = QueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(cls, "cls", ctx).release()));
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(cond, "cond", ctx).release()));
    return element;
}

int OrQueryExprNode::classId = -1;

OrQueryExprNode::OrQueryExprNode()
     : BinaryQueryExprNode()
{
}

void* OrQueryExprNode::Create()
{
    return new OrQueryExprNode();
}

void OrQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<OrQueryExprNode>(classId, &OrQueryExprNode::Create);
}

std::string OrQueryExprNode::StaticClassName()
{
    return "OrQueryExprNode";
}

std::string OrQueryExprNode::ClassName() const
{
    return "OrQueryExprNode";
}

void OrQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    BinaryQueryExprNode::FromXml(element);
}

std::vector<sngxml::xmlser::XmlPtrBase*> OrQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = BinaryQueryExprNode::GetPtrs();
    return ptrs;
}

void OrQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

OrQueryExprNode::~OrQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> OrQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> OrQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = BinaryQueryExprNode::ToXml(fieldName, ctx);
    return element;
}

int AndQueryExprNode::classId = -1;

AndQueryExprNode::AndQueryExprNode()
     : BinaryQueryExprNode()
{
}

void* AndQueryExprNode::Create()
{
    return new AndQueryExprNode();
}

void AndQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<AndQueryExprNode>(classId, &AndQueryExprNode::Create);
}

std::string AndQueryExprNode::StaticClassName()
{
    return "AndQueryExprNode";
}

std::string AndQueryExprNode::ClassName() const
{
    return "AndQueryExprNode";
}

void AndQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    BinaryQueryExprNode::FromXml(element);
}

std::vector<sngxml::xmlser::XmlPtrBase*> AndQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = BinaryQueryExprNode::GetPtrs();
    return ptrs;
}

void AndQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

AndQueryExprNode::~AndQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> AndQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> AndQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = BinaryQueryExprNode::ToXml(fieldName, ctx);
    return element;
}

int MatchQueryExprNode::classId = -1;

MatchQueryExprNode::MatchQueryExprNode()
     : BinaryQueryExprNode()
{
}

void* MatchQueryExprNode::Create()
{
    return new MatchQueryExprNode();
}

void MatchQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<MatchQueryExprNode>(classId, &MatchQueryExprNode::Create);
}

std::string MatchQueryExprNode::StaticClassName()
{
    return "MatchQueryExprNode";
}

std::string MatchQueryExprNode::ClassName() const
{
    return "MatchQueryExprNode";
}

void MatchQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    BinaryQueryExprNode::FromXml(element);
}

std::vector<sngxml::xmlser::XmlPtrBase*> MatchQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = BinaryQueryExprNode::GetPtrs();
    return ptrs;
}

void MatchQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

MatchQueryExprNode::~MatchQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> MatchQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> MatchQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = BinaryQueryExprNode::ToXml(fieldName, ctx);
    return element;
}

int RelationalQueryExprNode::classId = -1;

RelationalQueryExprNode::RelationalQueryExprNode()
     : BinaryQueryExprNode(), op()
{
}

void* RelationalQueryExprNode::Create()
{
    return new RelationalQueryExprNode();
}

void RelationalQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<RelationalQueryExprNode>(classId, &RelationalQueryExprNode::Create);
}

std::string RelationalQueryExprNode::StaticClassName()
{
    return "RelationalQueryExprNode";
}

std::string RelationalQueryExprNode::ClassName() const
{
    return "RelationalQueryExprNode";
}

void RelationalQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    BinaryQueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "op", op);
}

std::vector<sngxml::xmlser::XmlPtrBase*> RelationalQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = BinaryQueryExprNode::GetPtrs();
    return ptrs;
}

void RelationalQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

RelationalQueryExprNode::~RelationalQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> RelationalQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> RelationalQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = BinaryQueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(op, "op", ctx).release()));
    return element;
}

int NotQueryExprNode::classId = -1;

NotQueryExprNode::NotQueryExprNode()
     : UnaryQueryExprNode()
{
}

void* NotQueryExprNode::Create()
{
    return new NotQueryExprNode();
}

void NotQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<NotQueryExprNode>(classId, &NotQueryExprNode::Create);
}

std::string NotQueryExprNode::StaticClassName()
{
    return "NotQueryExprNode";
}

std::string NotQueryExprNode::ClassName() const
{
    return "NotQueryExprNode";
}

void NotQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    UnaryQueryExprNode::FromXml(element);
}

std::vector<sngxml::xmlser::XmlPtrBase*> NotQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = UnaryQueryExprNode::GetPtrs();
    return ptrs;
}

void NotQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

NotQueryExprNode::~NotQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> NotQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> NotQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = UnaryQueryExprNode::ToXml(fieldName, ctx);
    return element;
}

int MemberSelectionQueryExprNode::classId = -1;

MemberSelectionQueryExprNode::MemberSelectionQueryExprNode()
     : UnaryQueryExprNode(), id()
{
}

void* MemberSelectionQueryExprNode::Create()
{
    return new MemberSelectionQueryExprNode();
}

void MemberSelectionQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<MemberSelectionQueryExprNode>(classId, &MemberSelectionQueryExprNode::Create);
}

std::string MemberSelectionQueryExprNode::StaticClassName()
{
    return "MemberSelectionQueryExprNode";
}

std::string MemberSelectionQueryExprNode::ClassName() const
{
    return "MemberSelectionQueryExprNode";
}

void MemberSelectionQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    UnaryQueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "id", id);
}

std::vector<sngxml::xmlser::XmlPtrBase*> MemberSelectionQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = UnaryQueryExprNode::GetPtrs();
    return ptrs;
}

void MemberSelectionQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

MemberSelectionQueryExprNode::~MemberSelectionQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> MemberSelectionQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> MemberSelectionQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = UnaryQueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(id, "id", ctx).release()));
    return element;
}

int ParenthesizedQueryExprNode::classId = -1;

ParenthesizedQueryExprNode::ParenthesizedQueryExprNode()
     : UnaryQueryExprNode()
{
}

void* ParenthesizedQueryExprNode::Create()
{
    return new ParenthesizedQueryExprNode();
}

void ParenthesizedQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<ParenthesizedQueryExprNode>(classId, &ParenthesizedQueryExprNode::Create);
}

std::string ParenthesizedQueryExprNode::StaticClassName()
{
    return "ParenthesizedQueryExprNode";
}

std::string ParenthesizedQueryExprNode::ClassName() const
{
    return "ParenthesizedQueryExprNode";
}

void ParenthesizedQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    UnaryQueryExprNode::FromXml(element);
}

std::vector<sngxml::xmlser::XmlPtrBase*> ParenthesizedQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = UnaryQueryExprNode::GetPtrs();
    return ptrs;
}

void ParenthesizedQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

ParenthesizedQueryExprNode::~ParenthesizedQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> ParenthesizedQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> ParenthesizedQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = UnaryQueryExprNode::ToXml(fieldName, ctx);
    return element;
}

int BooleanLiteralQueryExprNode::classId = -1;

BooleanLiteralQueryExprNode::BooleanLiteralQueryExprNode()
     : QueryExprNode(), value()
{
}

void* BooleanLiteralQueryExprNode::Create()
{
    return new BooleanLiteralQueryExprNode();
}

void BooleanLiteralQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<BooleanLiteralQueryExprNode>(classId, &BooleanLiteralQueryExprNode::Create);
}

std::string BooleanLiteralQueryExprNode::StaticClassName()
{
    return "BooleanLiteralQueryExprNode";
}

std::string BooleanLiteralQueryExprNode::ClassName() const
{
    return "BooleanLiteralQueryExprNode";
}

void BooleanLiteralQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    QueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "value", value);
}

std::vector<sngxml::xmlser::XmlPtrBase*> BooleanLiteralQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = QueryExprNode::GetPtrs();
    return ptrs;
}

void BooleanLiteralQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

BooleanLiteralQueryExprNode::~BooleanLiteralQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> BooleanLiteralQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> BooleanLiteralQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = QueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(value, "value", ctx).release()));
    return element;
}

int IntegerLiteralQueryExprNode::classId = -1;

IntegerLiteralQueryExprNode::IntegerLiteralQueryExprNode()
     : QueryExprNode(), value()
{
}

void* IntegerLiteralQueryExprNode::Create()
{
    return new IntegerLiteralQueryExprNode();
}

void IntegerLiteralQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<IntegerLiteralQueryExprNode>(classId, &IntegerLiteralQueryExprNode::Create);
}

std::string IntegerLiteralQueryExprNode::StaticClassName()
{
    return "IntegerLiteralQueryExprNode";
}

std::string IntegerLiteralQueryExprNode::ClassName() const
{
    return "IntegerLiteralQueryExprNode";
}

void IntegerLiteralQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    QueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "value", value);
}

std::vector<sngxml::xmlser::XmlPtrBase*> IntegerLiteralQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = QueryExprNode::GetPtrs();
    return ptrs;
}

void IntegerLiteralQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

IntegerLiteralQueryExprNode::~IntegerLiteralQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> IntegerLiteralQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> IntegerLiteralQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = QueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(value, "value", ctx).release()));
    return element;
}

int StringLiteralQueryExprNode::classId = -1;

StringLiteralQueryExprNode::StringLiteralQueryExprNode()
     : QueryExprNode(), value()
{
}

void* StringLiteralQueryExprNode::Create()
{
    return new StringLiteralQueryExprNode();
}

void StringLiteralQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<StringLiteralQueryExprNode>(classId, &StringLiteralQueryExprNode::Create);
}

std::string StringLiteralQueryExprNode::StaticClassName()
{
    return "StringLiteralQueryExprNode";
}

std::string StringLiteralQueryExprNode::ClassName() const
{
    return "StringLiteralQueryExprNode";
}

void StringLiteralQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    QueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "value", value);
}

std::vector<sngxml::xmlser::XmlPtrBase*> StringLiteralQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = QueryExprNode::GetPtrs();
    return ptrs;
}

void StringLiteralQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

StringLiteralQueryExprNode::~StringLiteralQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> StringLiteralQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> StringLiteralQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = QueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(value, "value", ctx).release()));
    return element;
}

int IdentifierQueryExprNode::classId = -1;

IdentifierQueryExprNode::IdentifierQueryExprNode()
     : QueryExprNode(), value()
{
}

void* IdentifierQueryExprNode::Create()
{
    return new IdentifierQueryExprNode();
}

void IdentifierQueryExprNode::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<IdentifierQueryExprNode>(classId, &IdentifierQueryExprNode::Create);
}

std::string IdentifierQueryExprNode::StaticClassName()
{
    return "IdentifierQueryExprNode";
}

std::string IdentifierQueryExprNode::ClassName() const
{
    return "IdentifierQueryExprNode";
}

void IdentifierQueryExprNode::FromXml(sngxml::dom::Element* element)
{
    QueryExprNode::FromXml(element);
    sngxml::xmlser::FromXml(element, "value", value);
}

std::vector<sngxml::xmlser::XmlPtrBase*> IdentifierQueryExprNode::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs = QueryExprNode::GetPtrs();
    return ptrs;
}

void IdentifierQueryExprNode::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

IdentifierQueryExprNode::~IdentifierQueryExprNode()
{
}

std::unique_ptr<sngxml::dom::Element> IdentifierQueryExprNode::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> IdentifierQueryExprNode::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element = QueryExprNode::ToXml(fieldName, ctx);
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(value, "value", ctx).release()));
    return element;
}

using namespace soulng::unicode;

template<class T>
bool Compare(QueryValue* left, QueryValue* right, Operator op)
{
    T* l = static_cast<T*>(left);
    T* r = static_cast<T*>(right);
    switch (op)
    {
        case Operator::eq: return l->Value() == r->Value();
        case Operator::ne: return l->Value() != r->Value();
        case Operator::lt: return l->Value() < r->Value();
        case Operator::gt: return l->Value() > r->Value();
        case Operator::le: return l->Value() <= r->Value();
        case Operator::ge: return l->Value() >= r->Value();
    }
    throw std::runtime_error("unknown operator");
}

void StringConversionQueryExprNode::Evaluate(QueryContext& context) 
{
    Child()->Evaluate(context);
    std::unique_ptr<QueryValue> child = context.Stack().Pop();
    std::u32string strValue;
    switch (child->Kind())
    {
        case QueryValueKind::boolean: strValue = static_cast<BooleanQueryValue*>(child.get())->Value() ? U"true" : U"false"; break;
        case QueryValueKind::integer: strValue = ToUtf32(std::to_string(static_cast<IntegerQueryValue*>(child.get())->Value())); break;
        case QueryValueKind::string: strValue = static_cast<StringQueryValue*>(child.get())->Value(); break;
        case QueryValueKind::date: strValue = ToUtf32(static_cast<DateQueryValue*>(child.get())->Value().ToString()); break;
        default: throw std::runtime_error("invalid string conversion operand type: " + QueryValueKindStr(child->Kind()));
    }
    context.Stack().Push(new StringQueryValue(strValue));
}

void GetQueryExprNode::Evaluate(QueryContext& context)
{
    std::unique_ptr<QueryValue> value = context.Stack().Pop();
    if (value->Kind() == QueryValueKind::target)
    {
        TargetQueryValue* target = static_cast<TargetQueryValue*>(value.get());
        target->Value()->Member(context, U"objects");
        std::unique_ptr<QueryValue> objectsValue = context.Stack().Pop();
        if (objectsValue->Kind() == QueryValueKind::list)
        {
            ListQueryValue* list = static_cast<ListQueryValue*>(objectsValue.get());
            std::vector<QueryTarget*> result;
            for (QueryTarget* object : list->Value())
            {
                Select(object, context, result);
            }
            context.Stack().Push(new ListQueryValue(result));
        }
    }
}

void GetQueryExprNode::Select(QueryTarget* object, QueryContext& context, std::vector<QueryTarget*>& result)
{
    object->Select(context, cls);
    std::unique_ptr<QueryValue> value = context.Stack().Pop();
    if (value->Kind() == QueryValueKind::boolean)
    {
        BooleanQueryValue* booleanValue = static_cast<BooleanQueryValue*>(value.get());
        if (booleanValue->Value())
        {
            context.SetVariable(cls, object);
            bool select = true;
            if (cond.Get())
            {
                cond->Evaluate(context);
                std::unique_ptr<QueryValue> value = context.Stack().Pop();
                if (value->Kind() == QueryValueKind::boolean)
                {
                    BooleanQueryValue* booleanValue = static_cast<BooleanQueryValue*>(value.get());
                    select = booleanValue->Value();
                }
                else
                {
                    throw std::runtime_error("boolean result expected");
                }
            }
            if (select)
            {
                result.push_back(object);
            }
        }
    }
    else
    {
        throw std::runtime_error("boolean result expected");
    }
}

void OrQueryExprNode::Evaluate(QueryContext& context)
{
    Left()->Evaluate(context);
    std::unique_ptr<QueryValue> left = context.Stack().Pop();
    if (left->Kind() == QueryValueKind::boolean)
    {
        BooleanQueryValue* leftValue = static_cast<BooleanQueryValue*>(left.get());
        if (leftValue->Value())
        {
            context.Stack().Push(new BooleanQueryValue(true));
        }
        else
        {
            Right()->Evaluate(context);
            std::unique_ptr<QueryValue> right = context.Stack().Pop();
            if (right->Kind() == QueryValueKind::boolean)
            {
                BooleanQueryValue* rightValue = static_cast<BooleanQueryValue*>(right.get());
                context.Stack().Push(new BooleanQueryValue(rightValue->Value()));
            }
            else
            {
                throw std::runtime_error("boolean expression expected");
            }
        }
    }
    else
    {
        throw std::runtime_error("boolean expression expected");
    }
}

void AndQueryExprNode::Evaluate(QueryContext& context)
{
    Left()->Evaluate(context);
    std::unique_ptr<QueryValue> left = context.Stack().Pop();
    if (left->Kind() == QueryValueKind::boolean)
    {
        BooleanQueryValue* leftValue = static_cast<BooleanQueryValue*>(left.get());
        if (!leftValue->Value())
        {
            context.Stack().Push(new BooleanQueryValue(false));
        }
        else
        {
            Right()->Evaluate(context);
            std::unique_ptr<QueryValue> right = context.Stack().Pop();
            if (right->Kind() == QueryValueKind::boolean)
            {
                BooleanQueryValue* rightValue = static_cast<BooleanQueryValue*>(right.get());
                context.Stack().Push(new BooleanQueryValue(rightValue->Value()));
            }
            else
            {
                throw std::runtime_error("boolean expression expected");
            }
        }
    }
    else
    {
        throw std::runtime_error("boolean expression expected");
    }
}

void MatchQueryExprNode::Evaluate(QueryContext& context)
{
    if (Right()->Kind() == QueryExprNodeKind::stringLiteral)
    {
        StringLiteralQueryExprNode* slit = static_cast<StringLiteralQueryExprNode*>(Right());
        soulng::rex::Nfa nfa = soulng::rex::CompileFilePattern(context.RexContext(), slit->Value());
        context.Stack().Push(new BooleanQueryValue(soulng::rex::PatternMatch(slit->Value(), nfa)));
    }
    else
    {
        throw std::runtime_error("right of match must be a string literal");
    }
}

void RelationalQueryExprNode::Evaluate(QueryContext& context)
{
    Left()->Evaluate(context);
    std::unique_ptr<QueryValue> left = context.Stack().Pop();
    Right()->Evaluate(context);
    std::unique_ptr<QueryValue> right = context.Stack().Pop();
    if (left->Kind() == QueryValueKind::boolean && right->Kind() == QueryValueKind::boolean)
    {
        context.Stack().Push(new BooleanQueryValue(Compare<BooleanQueryValue>(left.get(), right.get(), op)));
    }
    else if (left->Kind() == QueryValueKind::integer && right->Kind() == QueryValueKind::integer)
    {
        context.Stack().Push(new BooleanQueryValue(Compare<IntegerQueryValue>(left.get(), right.get(), op)));
    }
    else if (left->Kind() == QueryValueKind::string && right->Kind() == QueryValueKind::string)
    {
        context.Stack().Push(new BooleanQueryValue(Compare<StringQueryValue>(left.get(), right.get(), op)));
    }
    else if (left->Kind() == QueryValueKind::date && right->Kind() == QueryValueKind::date)
    {
        context.Stack().Push(new BooleanQueryValue(Compare<DateQueryValue>(left.get(), right.get(), op)));
    }
    else if (left->Kind() == QueryValueKind::list && right->Kind() == QueryValueKind::list)
    {
        context.Stack().Push(new BooleanQueryValue(Compare<ListQueryValue>(left.get(), right.get(), op)));
    }
    else
    {
        throw std::runtime_error("invalid comparison argument types: " + QueryValueKindStr(left->Kind()) + " and " + QueryValueKindStr(right->Kind()));
    }
}

void NotQueryExprNode::Evaluate(QueryContext& context)
{
    Child()->Evaluate(context);
    std::unique_ptr<QueryValue> child = context.Stack().Pop();
    if (child->Kind() == QueryValueKind::boolean)
    {
        context.Stack().Push(new BooleanQueryValue(!static_cast<BooleanQueryValue*>(child.get())->Value()));
    }
    else
    {
        throw std::runtime_error("invalid 'not' expression argument type");
    }
}

void MemberSelectionQueryExprNode::Evaluate(QueryContext& context)
{
    Child()->Evaluate(context);
    std::unique_ptr<QueryValue> child = context.Stack().Pop();
    if (child->Kind() == QueryValueKind::target)
    {
        TargetQueryValue* targetValue = static_cast<TargetQueryValue*>(child.get());
        QueryTarget* target = targetValue->Value();
        target->Member(context, id);
    }
    else if (child->Kind() == QueryValueKind::list)
    {
        if (id == U"count")
        {
            ListQueryValue* listValue = static_cast<ListQueryValue*>(child.get());
            context.Stack().Push(new IntegerQueryValue(listValue->Value().size()));
        }
        else
        {
            throw std::runtime_error("count expected when selecting a list");
        }
    }
    else
    {
        throw std::runtime_error("target or list expected");
    }
}

void ParenthesizedQueryExprNode::Evaluate(QueryContext& context)
{
    Child()->Evaluate(context);
}

void BooleanLiteralQueryExprNode::Evaluate(QueryContext& context)
{
    context.Stack().Push(new BooleanQueryValue(value));
}

void IntegerLiteralQueryExprNode::Evaluate(QueryContext& context)
{
    context.Stack().Push(new IntegerQueryValue(value));
}

void StringLiteralQueryExprNode::Evaluate(QueryContext& context)
{
    context.Stack().Push(new StringQueryValue(value));
}

void IdentifierQueryExprNode::Evaluate(QueryContext& context)
{
    QueryTarget* target = context.GetVariable(value);
    if (target)
    {
        context.Stack().Push(new TargetQueryValue(target));
    }
    else
    {
        throw std::runtime_error("variable '" + ToUtf8(value) + "' not found");
    }
}

} // namespace query

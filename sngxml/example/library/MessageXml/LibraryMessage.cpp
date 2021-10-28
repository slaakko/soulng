#include "LibraryMessage.hpp"
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sngxml/serialization/XmlExport.hpp>
#include <sngxml/serialization/XmlImport.hpp>
#include <soulng/util/Unicode.hpp>

using namespace soulng::unicode;

namespace message_xml {

using namespace soulng::unicode;

int HelloLibraryRequest::classId = -1;

HelloLibraryRequest::HelloLibraryRequest()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), libraryName(), dataPtr(nullptr), isOwned(false)
{
}

void* HelloLibraryRequest::Create()
{
    return new HelloLibraryRequest();
}

void HelloLibraryRequest::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<HelloLibraryRequest>(classId, &HelloLibraryRequest::Create);
}

std::string HelloLibraryRequest::StaticClassName()
{
    return "HelloLibraryRequest";
}

std::string HelloLibraryRequest::ClassName() const
{
    return "HelloLibraryRequest";
}

void HelloLibraryRequest::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "libraryName", libraryName);
}

std::vector<sngxml::xmlser::XmlPtrBase*> HelloLibraryRequest::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void HelloLibraryRequest::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

HelloLibraryRequest::~HelloLibraryRequest()
{
}

std::unique_ptr<sngxml::dom::Element> HelloLibraryRequest::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> HelloLibraryRequest::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(libraryName, "libraryName", ctx).release()));
    return element;
}

int HelloLibraryReply::classId = -1;

HelloLibraryReply::HelloLibraryReply()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), libraryName(), dataPtr(nullptr), isOwned(false)
{
}

void* HelloLibraryReply::Create()
{
    return new HelloLibraryReply();
}

void HelloLibraryReply::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<HelloLibraryReply>(classId, &HelloLibraryReply::Create);
}

std::string HelloLibraryReply::StaticClassName()
{
    return "HelloLibraryReply";
}

std::string HelloLibraryReply::ClassName() const
{
    return "HelloLibraryReply";
}

void HelloLibraryReply::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "libraryName", libraryName);
}

std::vector<sngxml::xmlser::XmlPtrBase*> HelloLibraryReply::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void HelloLibraryReply::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

HelloLibraryReply::~HelloLibraryReply()
{
}

std::unique_ptr<sngxml::dom::Element> HelloLibraryReply::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> HelloLibraryReply::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(libraryName, "libraryName", ctx).release()));
    return element;
}

int InitLibraryRequest::classId = -1;

InitLibraryRequest::InitLibraryRequest()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), library(), dataPtr(nullptr), isOwned(false)
{
}

void* InitLibraryRequest::Create()
{
    return new InitLibraryRequest();
}

void InitLibraryRequest::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<InitLibraryRequest>(classId, &InitLibraryRequest::Create);
}

std::string InitLibraryRequest::StaticClassName()
{
    return "InitLibraryRequest";
}

std::string InitLibraryRequest::ClassName() const
{
    return "InitLibraryRequest";
}

void InitLibraryRequest::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "library", library);
}

std::vector<sngxml::xmlser::XmlPtrBase*> InitLibraryRequest::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    ptrs.push_back(const_cast<xml_ptr<Library>*>(&library)); 
    return ptrs;
}

void InitLibraryRequest::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

InitLibraryRequest::~InitLibraryRequest()
{
}

std::unique_ptr<sngxml::dom::Element> InitLibraryRequest::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> InitLibraryRequest::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(library, "library", ctx).release()));
    return element;
}

int InitLibraryReply::classId = -1;

InitLibraryReply::InitLibraryReply()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), libraryName(), dataPtr(nullptr), isOwned(false)
{
}

void* InitLibraryReply::Create()
{
    return new InitLibraryReply();
}

void InitLibraryReply::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<InitLibraryReply>(classId, &InitLibraryReply::Create);
}

std::string InitLibraryReply::StaticClassName()
{
    return "InitLibraryReply";
}

std::string InitLibraryReply::ClassName() const
{
    return "InitLibraryReply";
}

void InitLibraryReply::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
    sngxml::xmlser::FromXml(element, "libraryName", libraryName);
}

std::vector<sngxml::xmlser::XmlPtrBase*> InitLibraryReply::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void InitLibraryReply::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

InitLibraryReply::~InitLibraryReply()
{
}

std::unique_ptr<sngxml::dom::Element> InitLibraryReply::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> InitLibraryReply::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    element->AppendChild(std::unique_ptr<sngxml::dom::Node>(sngxml::xmlser::ToXml(libraryName, "libraryName", ctx).release()));
    return element;
}

int StopLibraryRequest::classId = -1;

StopLibraryRequest::StopLibraryRequest()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), dataPtr(nullptr), isOwned(false)
{
}

void* StopLibraryRequest::Create()
{
    return new StopLibraryRequest();
}

void StopLibraryRequest::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<StopLibraryRequest>(classId, &StopLibraryRequest::Create);
}

std::string StopLibraryRequest::StaticClassName()
{
    return "StopLibraryRequest";
}

std::string StopLibraryRequest::ClassName() const
{
    return "StopLibraryRequest";
}

void StopLibraryRequest::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
}

std::vector<sngxml::xmlser::XmlPtrBase*> StopLibraryRequest::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void StopLibraryRequest::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

StopLibraryRequest::~StopLibraryRequest()
{
}

std::unique_ptr<sngxml::dom::Element> StopLibraryRequest::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> StopLibraryRequest::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    return element;
}

int StopLibraryReply::classId = -1;

StopLibraryReply::StopLibraryReply()
     : objectId(boost::uuids::nil_uuid()), container(nullptr), dataPtr(nullptr), isOwned(false)
{
}

void* StopLibraryReply::Create()
{
    return new StopLibraryReply();
}

void StopLibraryReply::Register(int classId_)
{
    classId = classId_;
    sngxml::xmlser::XmlRegister<StopLibraryReply>(classId, &StopLibraryReply::Create);
}

std::string StopLibraryReply::StaticClassName()
{
    return "StopLibraryReply";
}

std::string StopLibraryReply::ClassName() const
{
    return "StopLibraryReply";
}

void StopLibraryReply::FromXml(sngxml::dom::Element* element)
{
    std::u32string objectIdAttr = element->GetAttribute(U"objectId");
    if (!objectIdAttr.empty())
    {
        objectId = boost::lexical_cast<boost::uuids::uuid>(ToUtf8(objectIdAttr));
    }
}

std::vector<sngxml::xmlser::XmlPtrBase*> StopLibraryReply::GetPtrs() const
{
    std::vector<sngxml::xmlser::XmlPtrBase*> ptrs;
    return ptrs;
}

void StopLibraryReply::SetObjectXmlAttributes(sngxml::dom::Element* element) const
{
    element->SetAttribute(U"classId", ToUtf32(std::to_string(classId)));
    element->SetAttribute(U"objectId", ToUtf32(boost::uuids::to_string(ObjectId())));
    element->SetAttribute(U"className", ToUtf32(ClassName()));
}

StopLibraryReply::~StopLibraryReply()
{
}

std::unique_ptr<sngxml::dom::Element> StopLibraryReply::ToXml(const std::string& fieldName) const
{
    sngxml::xmlser::XmlSerializationContext ctx;
    return ToXml(fieldName, ctx);
}

std::unique_ptr<sngxml::dom::Element> StopLibraryReply::ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const
{
    std::unique_ptr<sngxml::dom::Element> element(new sngxml::dom::Element(ToUtf32(fieldName)));
    if (!ctx.GetFlag(sngxml::xmlser::XmlSerializationFlags::suppressMetadata))
    {
        SetObjectXmlAttributes(element.get());
    }
    return element;
}


} // namespace message_xml

#ifndef OBJECT_HPP_73A8DFC9E0D5D75C9461E31045A7DB61CBC85E5C
#define OBJECT_HPP_73A8DFC9E0D5D75C9461E31045A7DB61CBC85E5C
#include <LibraryXml/Api.hpp>
#include <Query/QueryTarget.hpp>
#include <sngxml/serialization/XmlPtr.hpp>
#include <soulng/util/Time.hpp>
#include <chrono>
#include <memory>
#include <stdint.h>

namespace library_xml {

using date = soulng::util::Date;
using datetime = soulng::util::DateTime;
using timestamp = soulng::util::Timestamp;
using time_point = std::chrono::steady_clock::time_point;
using duration = std::chrono::steady_clock::duration;
using uuid = boost::uuids::uuid;
template<class T> using xml_ptr = sngxml::xmlser::XmlPtr<T>;
template<class T> using unique_xml_ptr = sngxml::xmlser::UniqueXmlPtr<T>;

class Library;

using QueryTarget = query::QueryTarget;

class LIBRARY_XML_API Object : public QueryTarget, public sngxml::xmlser::XmlSerializable
{
public:
    Object();
    Object(const Object&) = delete;
    Object(Object&&) = delete;
    Object& operator=(const Object&) = delete;
    Object& operator=(Object&&) = delete;
    virtual ~Object();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    const boost::uuids::uuid& ObjectId() const override { return objectId; }
    void SetObjectId(const boost::uuids::uuid& objectId_) override { objectId = objectId_; }
    int ClassId() const override { return classId; }
    bool IsOwned() const override { return isOwned; }
    void SetOwned() override { isOwned = true; }
    void ResetOwned() override { isOwned = false; }
    std::string ClassName() const override;
    sngxml::xmlser::XmlContainer* Container() const override { return container; }
    void SetContainer(sngxml::xmlser::XmlContainer* container_) override { container = container_; }
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    virtual void SetObjectXmlAttributes(sngxml::dom::Element* element) const;
public:
    std::string QueryClassName() const override;
    void Member(query::QueryContext& context, const std::u32string& memberId) const override;
    void SetLibrary(Library* library_)
    {
        library.Reset(library_);
    }
    Library* GetLibrary() const
    {
        return library.Get();
    }
    xml_ptr<Library> library;
    void* dataPtr;
private:
    static int classId;
    boost::uuids::uuid objectId;
    sngxml::xmlser::XmlContainer* container;
    bool isOwned;
};

} // namespace  library_xml


#endif // OBJECT_HPP_73A8DFC9E0D5D75C9461E31045A7DB61CBC85E5C

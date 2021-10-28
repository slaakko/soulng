#ifndef GROUP_HPP_D99E9B5DB806AD1AD7F1B580F355E233F766D33E
#define GROUP_HPP_D99E9B5DB806AD1AD7F1B580F355E233F766D33E
#include <LibraryXml/Author.hpp>
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

class Person;

class Record;

class LIBRARY_XML_API Group : public Author
{
public:
    Group();
    Group(const Group&) = delete;
    Group(Group&&) = delete;
    Group& operator=(const Group&) = delete;
    Group& operator=(Group&&) = delete;
    virtual ~Group();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    std::string QueryClassName() const override;
    void Select(query::QueryContext& context, const std::u32string& cls) const override;
    void Member(query::QueryContext& context, const std::u32string& memberId) const override;
    void AddMember(Person* member);
    std::vector<xml_ptr<Person>> members;
private:
    static int classId;
};

} // namespace  library_xml


#endif // GROUP_HPP_D99E9B5DB806AD1AD7F1B580F355E233F766D33E

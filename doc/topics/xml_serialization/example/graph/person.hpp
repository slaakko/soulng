#ifndef PERSON_HPP_255048259C60FFEEEA987C4AFBC204AB94B81A3C
#define PERSON_HPP_255048259C60FFEEEA987C4AFBC204AB94B81A3C
#include <author.hpp>
#include <sngxml/serialization/XmlPtr.hpp>
#include <soulng/util/Time.hpp>
#include <chrono>
#include <memory>
#include <stdint.h>

using date = soulng::util::Date;
using datetime = soulng::util::DateTime;
using timestamp = soulng::util::Timestamp;
using time_point = std::chrono::steady_clock::time_point;
using duration = std::chrono::steady_clock::duration;
using uuid = boost::uuids::uuid;
template<class T> using xml_ptr = sngxml::xmlser::XmlPtr<T>;
template<class T> using unique_xml_ptr = sngxml::xmlser::UniqueXmlPtr<T>;

class Group;

class Person : public Author
{
public:
    Person();
    Person(const Person&) = delete;
    Person(Person&&) = delete;
    Person& operator=(const Person&) = delete;
    Person& operator=(Person&&) = delete;
    virtual ~Person();
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
    void AddGroup(Group* group);
    std::vector<xml_ptr<Group>> groups;
private:
    static int classId;
};

#endif // PERSON_HPP_255048259C60FFEEEA987C4AFBC204AB94B81A3C

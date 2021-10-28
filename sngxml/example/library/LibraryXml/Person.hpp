#ifndef PERSON_HPP_E777E994AC3676FEBB237590B6977CE003771AA3
#define PERSON_HPP_E777E994AC3676FEBB237590B6977CE003771AA3
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

class Group;

class Book;

class Film;

class Piece;

class Record;

class LIBRARY_XML_API Person : public Author
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
    std::string QueryClassName() const override;
    void Select(query::QueryContext& context, const std::u32string& cls) const override;
    void Member(query::QueryContext& context, const std::u32string& memberId) const override;
    void AddBook(Book* book);
    void AddFile(Film* film);
    void AddPiece(Piece* piece);
    void AddRecord(Record* record);
    void AddGroup(Group* group);
    std::vector<Group*> Groups() const;
    date dateOfBirth;
    std::vector<xml_ptr<Group>> groups;
private:
    static int classId;
};

} // namespace  library_xml


#endif // PERSON_HPP_E777E994AC3676FEBB237590B6977CE003771AA3

#ifndef LIBRARY_HPP_CFDAB82F9C69D71823AC76CB46CA4D010DE7B6CF
#define LIBRARY_HPP_CFDAB82F9C69D71823AC76CB46CA4D010DE7B6CF
#include <LibraryXml/Object.hpp>
#include <sngxml/serialization/XmlContainer.hpp>
#include <sngxml/serialization/XmlBundle.hpp>
#include <soulng/util/Component.hpp>
#include <soulng/util/Container.hpp>
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

class Book;

class Film;

class Piece;

class Record;

class Author;

class Person;

class Group;

using Component = soulng::util::Component;

class LIBRARY_XML_API Library : public Object, public Component
{
public:
    Library();
    Library(const Library&) = delete;
    Library(Library&&) = delete;
    Library& operator=(const Library&) = delete;
    Library& operator=(Library&&) = delete;
    virtual ~Library();
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
    void Add(Book* book);
    Book* GetBook(const uuid& id) const;
    void Add(Film* film);
    Film* GetFilm(const uuid& id) const;
    void Add(Piece* piece);
    Piece* GetPiece(const uuid& id) const;
    void Add(Record* record);
    Record* GetRecord(const uuid& id) const;
    void Add(Person* person);
    Person* GetPerson(const uuid& id) const;
    void Add(Group* group);
    Group* GetGroup(const uuid& id) const;
    sngxml::xmlser::XmlContainer xmlContainer;
    std::unique_ptr<soulng::util::Container> objectContainer;
    std::string name;
    std::vector<xml_ptr<Object>> objects;
    std::vector<xml_ptr<Book>> books;
    std::vector<xml_ptr<Film>> films;
    std::vector<xml_ptr<Piece>> pieces;
    std::vector<xml_ptr<Record>> records;
    std::vector<xml_ptr<Person>> people;
    std::vector<xml_ptr<Group>> groups;
private:
    static int classId;
};

} // namespace  library_xml


#endif // LIBRARY_HPP_CFDAB82F9C69D71823AC76CB46CA4D010DE7B6CF

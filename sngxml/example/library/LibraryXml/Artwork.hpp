#ifndef ARTWORK_HPP_EFAA079667AA0D7FDF050E66048FDD763ED9E6C2
#define ARTWORK_HPP_EFAA079667AA0D7FDF050E66048FDD763ED9E6C2
#include <LibraryXml/Object.hpp>
#include <soulng/util/Component.hpp>
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

class Author;

class Library;

using Component = soulng::util::Component;

class LIBRARY_XML_API Artwork : public Object, public Component
{
public:
    Artwork();
    Artwork(const Artwork&) = delete;
    Artwork(Artwork&&) = delete;
    Artwork& operator=(const Artwork&) = delete;
    Artwork& operator=(Artwork&&) = delete;
    virtual ~Artwork();
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
    void Member(query::QueryContext& context, const std::u32string& memberId) const override;
    void SetAuthor(Author* author_)
    {
        author.Reset(author_);
    }
    Author* GetAuthor() const
    {
        return author.Get();
    }
    std::string name;
    date created;
    xml_ptr<Author> author;
private:
    static int classId;
};

} // namespace  library_xml


#endif // ARTWORK_HPP_EFAA079667AA0D7FDF050E66048FDD763ED9E6C2

#ifndef AUTHOR_HPP_A4E50406C901BEF9D898A0ABB1F108EB9110AAA2
#define AUTHOR_HPP_A4E50406C901BEF9D898A0ABB1F108EB9110AAA2
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

class Artwork;

class Library;

using Component = soulng::util::Component;

class LIBRARY_XML_API Author : public Object, public Component
{
public:
    Author();
    Author(const Author&) = delete;
    Author(Author&&) = delete;
    Author& operator=(const Author&) = delete;
    Author& operator=(Author&&) = delete;
    virtual ~Author();
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
    void AddArtwork(Artwork* artwork);
    std::vector<Artwork*> GetArtworks() const;
    std::string name;
    std::vector<xml_ptr<Artwork>> artworks;
private:
    static int classId;
};

} // namespace  library_xml


#endif // AUTHOR_HPP_A4E50406C901BEF9D898A0ABB1F108EB9110AAA2

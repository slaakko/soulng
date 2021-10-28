#ifndef PIECE_HPP_53A69965E0B93DCE0A138779D23717AB8A14A5CF
#define PIECE_HPP_53A69965E0B93DCE0A138779D23717AB8A14A5CF
#include <LibraryXml/Artwork.hpp>
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

class Record;

class LIBRARY_XML_API Piece : public Artwork
{
public:
    Piece();
    Piece(const Piece&) = delete;
    Piece(Piece&&) = delete;
    Piece& operator=(const Piece&) = delete;
    Piece& operator=(Piece&&) = delete;
    virtual ~Piece();
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
    void AddRecord(Record* record);
    std::vector<Record*> GetRecords() const;
    std::vector<xml_ptr<Record>> records;
private:
    static int classId;
};

} // namespace  library_xml


#endif // PIECE_HPP_53A69965E0B93DCE0A138779D23717AB8A14A5CF

#ifndef RECORD_HPP_DA7617913FA8097903C4C1685D0C5119D5156415
#define RECORD_HPP_DA7617913FA8097903C4C1685D0C5119D5156415
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

class Piece;

class LIBRARY_XML_API Record : public Artwork
{
public:
    Record();
    Record(const Record&) = delete;
    Record(Record&&) = delete;
    Record& operator=(const Record&) = delete;
    Record& operator=(Record&&) = delete;
    virtual ~Record();
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
    void AddPiece(Piece* piece);
    std::vector<xml_ptr<Piece>> pieces;
private:
    static int classId;
};

} // namespace  library_xml


#endif // RECORD_HPP_DA7617913FA8097903C4C1685D0C5119D5156415

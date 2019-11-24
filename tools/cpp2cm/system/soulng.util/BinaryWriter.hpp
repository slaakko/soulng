namespace soulng { namespace util {

class BinaryWriter
{
public:
    void Write(bool);
    void Write(uint8_t);
    void Write(int8_t);
    void Write(uint16_t);
    void Write(int16_t);
    void Write(uint32_t);
    void Write(int32_t);
    void Write(uint64_t);
    void Write(int64_t);
    void Write(float);
    void Write(double);
    void Write(char);
    void Write(char16_t);
    void Write(char32_t);
    void Write(const std::string&);
    void Write(const std::u16string&);
    void Write(const std::u32string&);
    void WriteULEB128UInt(uint32_t);
    void WriteULEB128ULong(uint64_t);
    void WriteSLEB128Int(int32_t);
    void WriteSLEB128Long(int64_t);
    void Write(const boost::uuids::uuid&);
    uint32_t Pos() const;
    void Seek(uint32_t);
};
    
} } // namespace soulng::util

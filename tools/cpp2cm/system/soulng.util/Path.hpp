namespace soulng { namespace util {
    
std::string GetFullPath(const std::string&);
    
class Path
{
public:
    static std::string ChangeExtension(const std::string&, const std::string&);
    static std::string Combine(const std::string&, const std::string&);
    static std::string GetDirectoryName(const std::string&);
    static std::string GetExtension(const std::string&);
    static std::string GetFileName(const std::string&);
    static bool HasExtension(const std::string&);
    static bool IsAbsolute(const std::string&);
    static bool IsRelative(const std::string&);
    static std::string GetFileNameWithoutExtension(const std::string&);
    static std::string MakeCanonical(const std::string&);
};    
        
} }

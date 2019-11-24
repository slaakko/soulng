namespace soulng { namespace util {

class CodeFormatter
{
public:
    int Indent() const;
    int IndentSize() const;
    void SetIndentSize(int);
    int CurrentIndent() const;
    void Write(const std::string&);
    void WriteLine(const std::string&);
    void NewLine();
    void WriteLine();
    void IncIndent();
    void DecIndent();
    int Line() const;
    void SetLine(int);
    bool Start() const;
    void SetStart();
    void ResetStart();
    void SetStartText(const std::string&);
    const std::string& StartText() const;
    bool PreserveSpace() const;
    void SetPreserveSpace(bool);
};
    
} } // namespace soulng::util

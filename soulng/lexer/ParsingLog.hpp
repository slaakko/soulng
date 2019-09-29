// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_PARSING_LOG_INCLUDED
#define SOULNG_LEXER_PARSING_LOG_INCLUDED
#include <soulng/lexer/LexerApi.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <string>

namespace soulng { namespace lexer {

class SOULNG_LEXER_API ParsingLog
{
public:
    ParsingLog();
    ParsingLog(int maxLineLength_);
    virtual ~ParsingLog();
    virtual void IncIndent() = 0;
    virtual void DecIndent() = 0;
    virtual void WriteBeginRule(const std::u32string& ruleName) = 0;
    virtual void WriteEndRule(const std::u32string& ruleName) = 0;
    virtual void WriteTry(const std::u32string& s) = 0;
    virtual void WriteSuccess(const std::u32string& match) = 0;
    virtual void WriteFail() = 0;
    virtual int MaxLineLength() const { return maxLineLength; }
private:
    int maxLineLength;
};

class SOULNG_LEXER_API XmlParsingLog : public ParsingLog
{
public:
    XmlParsingLog(std::ostream& stream_);
    XmlParsingLog(std::ostream& stream_, int maxLineLength_);
    void IncIndent() override { formatter.IncIndent(); }
    void DecIndent() override { formatter.DecIndent(); }
    void WriteBeginRule(const std::u32string& ruleName) override { Write(U"<" + ruleName + U">"); }
    void WriteEndRule(const std::u32string& ruleName) override { Write(U"</" + ruleName + U">"); }
    void WriteTry(const std::u32string& s) override { WriteElement(U"try", s); }
    void WriteSuccess(const std::u32string& match) override { WriteElement(U"success", match); }
    void WriteFail() override { Write(U"<fail/>"); }
    void WriteElement(const std::u32string& elementName, const std::u32string& elementContent);
    void Write(const std::u32string& s);
    soulng::util::CodeFormatter& Formatter() { return formatter; }
private:
    soulng::util::CodeFormatter formatter;
};

SOULNG_LEXER_API std::u32string XmlHexEscape(char32_t c);
SOULNG_LEXER_API std::u32string XmlCharStr(char32_t c);
SOULNG_LEXER_API std::u32string XmlEscape(const std::u32string& s);

} } // namespace soulng::lexer

#endif //  SOULNG_LEXER_PARSING_LOG_INCLUDED

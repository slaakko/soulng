// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_HTML_SOURCE_CODE_WRITER_INCLUDED
#define GENDOC_HTML_SOURCE_CODE_WRITER_INCLUDED
#include <gendoc/html/HtmlApi.hpp>
#include <sngcpp/ast/SourceCodeWriter.hpp>
#include <sngcpp/ast/Node.hpp>
#include <sngxml/dom/Element.hpp>

namespace gendoc { namespace html {

using namespace sngcpp::ast;

enum class WriteKind : uint8_t
{
    none = 0,
    line = 1 << 0,
    inlineLine = 1 << 1,
    both = line | inlineLine
};

GENDOC_HTML_API inline WriteKind operator|(WriteKind left, WriteKind right)
{
    return WriteKind(uint8_t(left) | uint8_t(right));
}

GENDOC_HTML_API inline WriteKind operator&(WriteKind left, WriteKind right)
{
    return WriteKind(uint8_t(left) & uint8_t(right));
}

class GENDOC_HTML_API HtmlSourceCodeWriter : public sngcpp::ast::SourceCodeWriter
{
public:
    HtmlSourceCodeWriter();
    void SetLineElement(sngxml::dom::Element* lineElement_) { lineElement = lineElement_; }
    void SetInlineLineElement(sngxml::dom::Element* inlineLineElement_) { inlineLineElement = inlineLineElement_; }
    void SetCurrentPos(int currentPos_) { currentPos = currentPos_; }
    void SetInlineCurrentPos(int inlineCurrentPos_) { inlineCurrentPos = inlineCurrentPos_; }
    void MoveTo(const Span& span);
    void WriteLineNumber(const std::u32string& lineNumber) override;
    void WriteLineNumberKind(const std::u32string& lineNumber, WriteKind kind);
    void WriteLineComment(const std::u32string& comment) override;
    void WriteBlockComment(const std::u32string& comment) override;
    void WriteKeyword(const std::u32string& keyword) override;
    void WriteIdentifier(const std::u32string& identifier) override;
    void WriteLink(const std::u32string& identifier, const std::u32string& ref) override;
    void WriteInlineLink(const std::u32string& identifier, const std::u32string& ref);
    void WriteType(const std::u32string& type) override;
    void WritePP(const std::u32string& pp) override;
    void WriteChar(const std::u32string& chars) override;
    void WriteString(const std::u32string& string) override;
    void WriteSpace(int numSpaces) override;
    void WriteSpaces(const std::u32string& spaces) override;
    void WriteSpaceKind(int numSpaces, WriteKind kind);
    void WriteNumber(const std::u32string& number) override;
    void WriteOther(const std::u32string& other) override;
private:
    sngxml::dom::Element* lineElement;
    sngxml::dom::Element* inlineLineElement;
    int currentPos;
    int inlineCurrentPos;
    void WriteToElement(sngxml::dom::Element* element, const std::u32string& text);
};

} } // namespace gendoc::html

#endif // GENDOC_HTML_SOURCE_CODE_WRITER_INCLUDED

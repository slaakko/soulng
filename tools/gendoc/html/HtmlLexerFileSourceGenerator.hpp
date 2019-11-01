// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_HTML_LEXER_FILE_SOURCE_GENERATOR_INCLUDED
#define GENDOC_HTML_LEXER_FILE_SOURCE_GENERATOR_INCLUDED
#include <gendoc/html/HtmlSourceCodeWriter.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/SourceFile.hpp>

namespace gendoc { namespace html {

class GENDOC_HTML_API HtmlLexerFileSourceGenerator : public sngcpp::ast::Visitor
{
public:
    HtmlLexerFileSourceGenerator(const std::u32string& projectName_, const std::vector<std::u32string>& inputLines_, int numDigits_, const std::string& styleDirName_, const std::string& styleFileName_);
    void Visit(SourceFileNode& sourceFileNode) override;
    void OpenLine();
    void CloseLine();
private:
    std::u32string projectName;
    const std::vector<std::u32string>& inputLines;
    int numDigits;
    std::string styleFilePath;
    HtmlSourceCodeWriter writer;
    sngxml::dom::Document htmlSourceFileDocument;
    std::unique_ptr<sngxml::dom::Element> htmlElement;
    std::unique_ptr<sngxml::dom::Element> bodyElement;
    std::unique_ptr<sngxml::dom::Element> lineElement;
    int currentSourceLineNumber;
};

} } // namespace gendoc::html

#endif // GENDOC_HTML_LEXER_FILE_SOURFCE_GENERATOR_INCLUDED

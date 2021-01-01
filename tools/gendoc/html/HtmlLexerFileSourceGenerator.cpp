// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <gendoc/html/HtmlLexerFileSourceGenerator.hpp>
#include <gendoc/html/LexerFileSourceLineParser.hpp>
#include <sngxml/dom/CharacterData.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>
#include <fstream>

namespace gendoc { namespace html {

using namespace soulng::util;
using namespace soulng::unicode;

HtmlLexerFileSourceGenerator::HtmlLexerFileSourceGenerator(const std::u32string& projectName_, const std::vector<std::u32string>& inputLines_, int numDigits_, const std::string& styleDirName_,
    const std::string& styleFileName_) :
    projectName(projectName_), inputLines(inputLines_), numDigits(numDigits_), styleFilePath(Path::Combine(Path::Combine("../..", styleDirName_), styleFileName_))
{
    htmlElement.reset(new sngxml::dom::Element(U"html"));
}

void HtmlLexerFileSourceGenerator::Visit(SourceFileNode& sourceFileNode)
{
    std::unique_ptr<sngxml::dom::Element> headElement(new sngxml::dom::Element(U"head"));
    std::unique_ptr<sngxml::dom::Element> metaElement(new sngxml::dom::Element(U"meta"));
    metaElement->SetAttribute(U"charset", U"utf-8");
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(metaElement.release()));
    std::unique_ptr<sngxml::dom::Element> titleElement(new sngxml::dom::Element(U"title"));
    titleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(sourceFileNode.ProjectName() + U"/" + ToUtf32(sourceFileNode.RelativeSourceFilePath()))));
    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"link"));
    linkElement->SetAttribute(U"rel", U"stylesheet");
    linkElement->SetAttribute(U"type", U"text/css");
    std::u32string relativeStyleFilePath = ToUtf32(styleFilePath);
    linkElement->SetAttribute(U"href", relativeStyleFilePath);
    headElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(linkElement.release()));
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(headElement.release()));
    bodyElement.reset(new sngxml::dom::Element(U"body"));
    currentSourceLineNumber = 1;
    for (const auto& line : inputLines)
    {
        OpenLine();
        ParseLexerFileSourceLine(line, writer);
        CloseLine();
    }
    std::ofstream htmlFile(sourceFileNode.HtmlSourceFilePath());
    CodeFormatter formatter(htmlFile);
    formatter.SetIndentSize(1);
    htmlElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(bodyElement.release()));
    htmlSourceFileDocument.AppendChild(std::unique_ptr<sngxml::dom::Node>(htmlElement.release()));
    htmlSourceFileDocument.Write(formatter);
}

void HtmlLexerFileSourceGenerator::OpenLine()
{
    lineElement.reset(new sngxml::dom::Element(U"span"));
    writer.SetLineElement(lineElement.get());
    lineElement->SetAttribute(U"class", U"code");
    lineElement->SetAttribute(U"xml:space", U"preserve");
    lineElement->SetAttribute(U"id", ToUtf32(std::to_string(currentSourceLineNumber)));
    std::u32string lineNumberText = FormatNumber(currentSourceLineNumber, numDigits);
    writer.WriteLineNumberKind(lineNumberText, WriteKind::line);
    writer.WriteSpaceKind(1, WriteKind::line);
}

void HtmlLexerFileSourceGenerator::CloseLine()
{
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(lineElement.release()));
    bodyElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Element(U"br")));
    ++currentSourceLineNumber;
}

} } // namespace gendoc::html

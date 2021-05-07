// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/driver/Interface.hpp>
#include <sngcpp20/pp/Evaluator.hpp>
#include <sngcpp20/pp/PP.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/parser/TranslationUnitParser.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/SourceCodePrinterVisitor.hpp>
#include <sngcpp20/ast/XmlGeneratorVisitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <soulng/lexer/XmlParsingLog.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>
#include <fstream>

namespace sngcpp::driver {

using namespace sngcpp::pp;
using namespace sngcpp::symbols;
using namespace soulng::lexer;
using namespace soulng::util;
using namespace soulng::unicode;

ParseResult::ParseResult()
{
}

ParseResult::ParseResult(std::unique_ptr<std::u32string>&& preprocessedSourceText_, std::unique_ptr<Node>&& translationUnitNode_) : 
    preprocessedSourceText(std::move(preprocessedSourceText_)), translationUnitNode(std::move(translationUnitNode_))
{
}

std::unique_ptr<std::u32string> Preprocess(const std::string& sourceFileName)
{
    EvaluationContext evaluationContext;
    PP pp(evaluationContext);
    Preprocess(GetFullPath(sourceFileName), &pp);
    return std::unique_ptr<std::u32string>(new std::u32string(std::move(pp.text)));
}

ParseResult Parse(std::unique_ptr<std::u32string>&& preprocessedSourceText, ParseOptions& options)
{
    CppLexer lexer(preprocessedSourceText->c_str(), preprocessedSourceText->c_str() + preprocessedSourceText->length(), options.fileName, options.fileIndex);
    std::ostream* stream = &std::cout;
    std::ofstream fstream;
    if (!options.logFilePath.empty())
    {
        fstream.open(options.logFilePath);
        stream = &fstream;
    }
    XmlParsingLog log(*stream);
    if (options.log)
    {
        lexer.SetLog(&log);
    }
    SymbolTable symbolTable;
    Context ctx;
    ctx.SetSymbolTable(&symbolTable);
    ctx.SetLexer(&lexer);
    return ParseResult(std::move(preprocessedSourceText), TranslationUnitParser::Parse(lexer, &ctx));
}

ParseResult Parse(const std::string& sourceFileName, ParseOptions& options)
{
    options.fileName = GetFullPath(sourceFileName);
    return Parse(Preprocess(options.fileName), options);
}

void WriteSourceCode(Node* translationUnitNode, std::ostream& stream)
{
    SourceCodePrinterVisitor visitor(stream);
    if (translationUnitNode)
    {
        translationUnitNode->Accept(visitor);
    }
}

void WriteSourceCode(Node* translationUnitNode, const std::string& fileName)
{
    std::ofstream file(fileName);
    WriteSourceCode(translationUnitNode, file);
}

void WriteXml(Node* translationUnitNode, std::ostream& stream)
{
    if (translationUnitNode)
    {
        XmlGeneratorVisitor visitor;
        translationUnitNode->Accept(visitor);
        std::unique_ptr<sngxml::dom::Element> translationUnitElement = visitor.GetElement();
        CodeFormatter formatter(stream);
        formatter.SetIndentSize(1);
        translationUnitElement->Write(formatter);
    }
}

void WriteXml(Node* translationUnitNode, const std::string& fileName)
{
    std::ofstream file(fileName);
    WriteXml(translationUnitNode, file);
}

void WriteBinary(Node* translationUnitNode, const std::string& fileName)
{
    Writer writer(fileName);
    writer.Write(translationUnitNode);
}

} // sngcpp::driver

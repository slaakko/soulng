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
#include <sngcpp20/ast/Reader.hpp>
#include <soulng/lexer/XmlParsingLog.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Util.hpp>
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

ParseResult::ParseResult(std::unique_ptr<PPResult>&& ppResult_, std::unique_ptr<Node>&& translationUnitNode_) :
    ppResult(std::move(ppResult_)), translationUnitNode(std::move(translationUnitNode_))
{
}

ParseResult::ParseResult(const std::string& error_) : error(error_)
{
}

std::unique_ptr<PPResult> Preprocess(const std::string& sourceFileName, const Configuration& configuration, bool printMacros)
{
    EvaluationContext evaluationContext;
    PP pp(evaluationContext);
    for (const auto& definePair : configuration.Defines())
    {
        const std::u32string& name = definePair.first;
        const std::u32string& value = definePair.second;
        pp.DefineObjectMacro(name, value);
    }
    for (const auto& includePath : configuration.Includes())
    {
        pp.AddIncludePath(includePath);
    }
    std::unique_ptr<PPResult> result = Preprocess(GetFullPath(sourceFileName), &pp);
    if (pp.IsMacroDefined(pp.SNGCPPMSVCModeMacroName()))
    {
        result->SetMSVCMode();
    }
    if (printMacros)
    {
        pp.PrintMacros();
    }
    return result;
}

ParseResult Parse(std::unique_ptr<PPResult>&& ppResult, ParseOptions& options)
{
    if (!ppResult) return ParseResult();
    Lexeme resultText = ppResult->ResultText();
    CppLexer lexer(resultText.begin, resultText.end, options.fileName, options.fileIndex);
    lexer.SetLineMapper(ppResult->GetLineMapper());
    lexer.SetFlag(LexerFlags::farthestError);
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
    if (ppResult->MSVCMode())
    {
        ctx.SetFlag(ContextFlags::msvcMode);
    }
    ctx.SetSymbolTable(&symbolTable);
    ctx.SetLexer(&lexer);
    if (options.throwFlag)
    {
        return ParseResult(std::move(ppResult), TranslationUnitParser::Parse(lexer, &ctx));
    }
    else
    {
        try
        {
            return ParseResult(std::move(ppResult), TranslationUnitParser::Parse(lexer, &ctx));
        }
        catch (const std::exception& ex)
        {
            return ParseResult(ex.what());
        }
    }
}

ParseResult Parse(const std::string& sourceFileName, ParseOptions& options, const Configuration& configuration, bool printMacros)
{
    options.fileName = GetFullPath(sourceFileName);
    return Parse(Preprocess(options.fileName, configuration, printMacros), options);
}

void WriteSourceCode(Node* translationUnitNode, std::ostream& stream)
{
    SourceCodePrinterVisitor visitor(stream);
    if (translationUnitNode)
    {
        translationUnitNode->Accept(visitor);
    }
    stream << std::endl;
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

std::unique_ptr<Node> ReadBinary(const std::string& fileName)
{
    Reader reader(fileName);
    std::unique_ptr<Node> node(reader.ReadNode());
    return node;
}

} // sngcpp::driver

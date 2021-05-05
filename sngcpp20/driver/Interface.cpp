// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/driver/Interface.hpp>
#include <sngcpp20/pp/Evaluator.hpp>
#include <sngcpp20/pp/PP.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/parser/TranslationUnitParser.hpp>
#include <soulng/lexer/XmlParsingLog.hpp>
#include <soulng/util/Path.hpp>
#include <iostream>
#include <fstream>

namespace sngcpp::driver {

using namespace sngcpp::pp;
using namespace sngcpp::par;
using namespace soulng::lexer;
using namespace soulng::util;

std::u32string Preprocess(const std::string& sourceFileName)
{
    EvaluationContext evaluationContext;
    PP pp(evaluationContext);
    Preprocess(GetFullPath(sourceFileName), &pp);
    return std::move(pp.text);
}

std::unique_ptr<Node> Parse(const std::u32string& sourceFileContent, ParseOptions& options)
{
    CppLexer lexer(sourceFileContent, options.fileName, options.fileIndex);
    std::ostream* stream = &std::cout;
    std::ofstream fstream;
    if (options.logFilePath.empty())
    {
        fstream.open(options.logFilePath);
        stream = &fstream;
    }
    XmlParsingLog log(*stream);
    if (options.log)
    {
        lexer.SetLog(&log);
    }
    Context ctx;
    return TranslationUnitParser::Parse(lexer, &ctx);
}

std::unique_ptr<Node> Parse(const std::string& sourceFileName, ParseOptions& options)
{
    options.fileName = GetFullPath(sourceFileName);
    return Parse(Preprocess(options.fileName), options);
}

} // sngcpp::driver

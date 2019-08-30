// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsergen/ParserFileGrammar.hpp>
#include <soulng/parsergen/ProjectFileGrammar.hpp>
#include <soulng/parsergen/Domain.hpp>
#include <soulng/parsergen/CodeGeneratorVisitor.hpp>
#include <soulng/parsergen/LinkerVisitor.hpp>
#include <soulng/codedom/InitDone.hpp>
#include <soulng/parsing/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>
#include <stdexcept>

using namespace soulng::util;
using namespace soulng::unicode;

struct InitDone
{
    InitDone()
    {
        soulng::util::Init();
        soulng::codedom::Init();
        soulng::parsing::Init();
    }
    ~InitDone()
    {
        soulng::parsing::Done();
        soulng::codedom::Done();
        soulng::util::Done();
    }
};

void PrintUsage()
{
    std::cout << "parsergen [options] <file.spg>" << std::endl;
}

int main(int argc, const char** argv)
{
    InitDone initDone;
    try
    {
        soulng::parsergen::ParserFileGrammar* parserFileGrammar = soulng::parsergen::ParserFileGrammar::Create();
        soulng::parsergen::ProjectFileGrammar* projectFileGrammar = soulng::parsergen::ProjectFileGrammar::Create();
        bool verbose = false;
        std::string fileName;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (StartsWith(arg, "--"))
            {
                if (arg == "--help")
                {
                    PrintUsage();
                    return 1;
                }
                else if (arg == "--verbose")
                {
                    verbose = true;
                }
                else
                {
                    throw std::runtime_error("unknown option '" + arg + "'");
                }
            }
            else if (StartsWith(arg, "-"))
            {
                std::string options = arg.substr(1);
                if (options.empty())
                {
                    throw std::runtime_error("unknown option '-" + arg + "'");
                }
                else
                {
                    for (char o : options)
                    {
                        if (o == '-h')
                        {
                            PrintUsage();
                            return 1;
                        }
                        else if (o == '-v')
                        {
                            verbose = true;
                        }
                        else
                        {
                            throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                        }
                    }
                }
            }
            else
            {
                fileName = GetFullPath(argv[i]);
            }
        }
        if (fileName.empty())
        {
            PrintUsage();
            return 1;
        }
        soulng::util::MappedInputFile file(fileName);
        std::string s(file.Begin(), file.End());
        std::u32string content = soulng::unicode::ToUtf32(s);
        soulng::parsergen::Domain domain;
        std::vector<std::unique_ptr<soulng::parsergen::ParserFile>> parserFiles;
        std::unique_ptr<soulng::parsergen::ProjectFile> projectFile(projectFileGrammar->Parse(content.c_str(), content.c_str() + content.length(), 0, fileName));
        for (const auto& sourceFileName : projectFile->SourceFiles())
        {
            std::string sourceFilePath = GetFullPath(Path::Combine(projectFile->BasePath(), ToUtf8(sourceFileName)));
            soulng::util::MappedInputFile file(sourceFilePath);
            std::string s(file.Begin(), file.End());
            std::u32string content = soulng::unicode::ToUtf32(s);
            std::unique_ptr<soulng::parsergen::ParserFile> parserFile(parserFileGrammar->Parse(content.c_str(), content.c_str() + content.length(), 0, sourceFilePath));
            domain.AddParserFile(parserFile.get());
            parserFiles.push_back(std::move(parserFile));
        }
        soulng::parsergen::LinkerVisitor linkerVisitor;
        domain.Accept(linkerVisitor);
        soulng::parsergen::CodeGeneratorVisitor codeGeneratorVisitor(verbose);
        domain.Accept(codeGeneratorVisitor);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

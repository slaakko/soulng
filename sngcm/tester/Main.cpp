#include <sngcm/ast/InitDone.hpp>
#include <sngcm/ast/Identifier.hpp>
#include <sngcm/writer/SourceWriter.hpp>
#include <sngcm/lexer/CmajorLexer.hpp>
#include <sngcm/lexer/ContainerFileLexer.hpp>
#include <sngcm/parser/CompileUnit.hpp>
#include <sngcm/parser/ProjectFile.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

struct InitDone
{
    InitDone()
    {
        soulng::util::Init();
        sngcm::ast::Init();
    }
    ~InitDone()
    {
        sngcm::ast::Done();
        soulng::util::Done();
    }
};

void PrintUsage()
{
    std::cout << "usage: sngcmtester [options] (file.cmp | file.cm)" << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "--help | -h:" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--out | -o:" << std::endl;
    std::cout << "  Write source to .out.cm file." << std::endl;
}

int main(int argc, const char** argv)
{
    InitDone initDone;
    try
    {
        if (argc < 2)
        {
            PrintUsage();
            return 1;
        }
        std::vector<std::string> args;
        bool out = false;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (soulng::util::StartsWith(arg, "--"))
            {
                if (arg == "--help")
                {
                    PrintUsage();
                    return 1;
                }
                else if (arg == "--out")
                {
                    out = true;
                }
                else
                {
                    throw std::runtime_error("unknown argument '" + arg + "'");
                }
            }
            else if (soulng::util::StartsWith(arg, "-"))
            {
                std::string options = arg.substr(1);
                for (char o : options)
                {
                    if (o == 'h')
                    {
                        PrintUsage();
                        return 1;
                    }
                    else if (o == 'o')
                    {
                        out = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown argument '" + arg + "'");
                    }
                }
            }
            else
            {
                args.push_back(arg);
            }
        }
        for (int i = 0; i < args.size(); ++i)
        {
            std::string fileName = soulng::util::GetFullPath(args[i]);
            std::cout << "> " << fileName << std::endl;
            if (soulng::util::EndsWith(fileName, ".cm"))
            {
                std::u32string content = soulng::unicode::ToUtf32(soulng::util::ReadFile(fileName));
                CmajorLexer lexer(content, fileName, i);
                ParsingContext ctx;
                std::unique_ptr<sngcm::ast::CompileUnitNode> compileUnit = CompileUnitParser::Parse(lexer, &ctx);
                if (out)
                {
                    std::string outFilePath = soulng::util::Path::ChangeExtension(fileName, ".out.cm");
                    std::ofstream outFile(outFilePath);
                    soulng::util::CodeFormatter formatter(outFile);
                    sngcm::writer::SourceWriter writer(formatter);
                    compileUnit->Accept(writer);
                    std::cout << "==> " << outFilePath << std::endl;
                }
            }
            else if (soulng::util::EndsWith(fileName, ".cmp"))
            {
                std::u32string content = soulng::unicode::ToUtf32(soulng::util::ReadFile(fileName));
                ContainerFileLexer lexer(content, fileName, i);
                std::unique_ptr<sngcm::ast::Project> project = ProjectFileParser::Parse(lexer, "debug", sngcm::ast::BackEnd::llvm);
                project->ResolveDeclarations();
                int index = 0;
                for (const auto& sourceFilePath : project->SourceFilePaths())
                {
                    std::cout << "> " << sourceFilePath << std::endl;
                    std::u32string content = soulng::unicode::ToUtf32(soulng::util::ReadFile(sourceFilePath));
                    CmajorLexer lexer(content, sourceFilePath, index);
                    ParsingContext ctx;
                    std::unique_ptr<sngcm::ast::CompileUnitNode> compileUnit = CompileUnitParser::Parse(lexer, &ctx);
                    if (out)
                    {
                        std::string outFilePath = soulng::util::Path::ChangeExtension(sourceFilePath, ".out.cm");
                        std::ofstream outFile(outFilePath);
                        soulng::util::CodeFormatter formatter(outFile);
                        sngcm::writer::SourceWriter writer(formatter);
                        compileUnit->Accept(writer);
                        std::cout << "==> " << outFilePath << std::endl;
                    }
                }
            }
        }
        return 0;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}

#include <cmajor/ast/InitDone.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/ContainerFileLexer.hpp>
#include <cmajor/parser/CompileUnit.hpp>
#include <cmajor/parser/ProjectFile.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/TextUtils.hpp>
#include <stdexcept>
#include <iostream>
#include <string>

struct InitDone
{
    InitDone()
    {
        soulng::util::Init();
        cmajor::ast::Init();
    }
    ~InitDone()
    {
        cmajor::ast::Done();
        soulng::util::Done();
    }
};

void PrintUsage()
{
    std::cout << "usage: cmajortester (file.cmp | file.cm)" << std::endl;
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
                std::unique_ptr<cmajor::ast::CompileUnitNode> compileUnit = CompileUnitParser::Parse(lexer, &ctx);
            }
            else if (soulng::util::EndsWith(fileName, ".cmp"))
            {
                std::u32string content = soulng::unicode::ToUtf32(soulng::util::ReadFile(fileName));
                ContainerFileLexer lexer(content, fileName, i);
                std::unique_ptr<cmajor::ast::Project> project = ProjectFileParser::Parse(lexer, "debug", cmajor::ast::BackEnd::llvm);
                project->ResolveDeclarations();
                int index = 0;
                for (const auto& sourceFilePath : project->SourceFilePaths())
                {
                    std::cout << "> " << sourceFilePath << std::endl;
                    std::u32string content = soulng::unicode::ToUtf32(soulng::util::ReadFile(sourceFilePath));
                    CmajorLexer lexer(content, sourceFilePath, index);
                    ParsingContext ctx;
                    std::unique_ptr<cmajor::ast::CompileUnitNode> compileUnit = CompileUnitParser::Parse(lexer, &ctx);
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

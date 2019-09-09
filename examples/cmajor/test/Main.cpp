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
    std::cout << "usage: cmajortest (file.cmp | file.cm)" << std::endl;
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
        for (int i = 1; i < argc; ++i)
        {
            std::string fileName = soulng::util::GetFullPath(argv[i]);
            std::cout << "> " << fileName << std::endl;
            if (soulng::util::EndsWith(fileName, ".cm"))
            { 
                std::u32string content = soulng::unicode::ToUtf32(soulng::util::ReadFile(fileName));
                CmajorLexer lexer(content, fileName, i - 1);
                ParsingContext ctx;
                std::unique_ptr<cmajor::ast::CompileUnitNode> compileUnit = CompileUnitParser::Parse(lexer, &ctx);
            }
            else if (soulng::util::EndsWith(fileName, ".cmp"))
            {
                std::u32string content = soulng::unicode::ToUtf32(soulng::util::ReadFile(fileName));
                ContainerFileLexer lexer(content, fileName, i - 1);
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
                    ++index;
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

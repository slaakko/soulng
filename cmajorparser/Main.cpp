#include <soulng/cmajorlexer/CmajorLexer.hpp>
#include <soulng/cmajorlexer/ContainerFileLexer.hpp>
#include <soulng/cmajorparser/CompileUnit.hpp>
#include <soulng/cmajorparser/ProjectFile.hpp>
#include <soulng/lexer/Comment.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>
#include <stdexcept>
#include <iostream>
#include <string>

int main(int argc, const char** argv)
{
    try
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string fileName = soulng::util::GetFullPath(argv[i]);
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
                    std::u32string content = soulng::unicode::ToUtf32(soulng::util::ReadFile(sourceFilePath));
                    soulng::lexer::RemoveComments(content);
                    CmajorLexer lexer(content, sourceFilePath, index);
                    ParsingContext ctx;
                    std::unique_ptr<cmajor::ast::CompileUnitNode> compileUnit = CompileUnitParser::Parse(lexer, &ctx);
                    ++index;
                }
            }
            int x = 0;
        }
        return 0;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}

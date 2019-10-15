#include <sngcpp/lexer/CppLexer.hpp>
#include <soulng/lexer/XmlParsingLog.hpp>
#include <sngcpp/parser/SourceFile.hpp>
#include <sngcpp/pp/InitDone.hpp>
#include <sngcpp/pp/PP.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <iostream>
#include <stdexcept>

using namespace soulng::util;
using namespace sngcpp::pp;
using namespace soulng::lexer;

void PrintUsage()
{
    std::cout << "sngcpp parser tester" << std::endl;
    std::cout << "usage: sngcppparsertester [options] { file.cpp | file.hpp }" << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "--help | -h" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--verbose | -v" << std::endl;
    std::cout << "  Be verbose." << std::endl;
    std::cout << "--root DIR" << std::endl;
    std::cout << "  Set root directory to DIR." << std::endl;
    std::cout << "--include PATH" << std::endl;
    std::cout << "  Set include path to PATH." << std::endl;
    std::cout << "--debug | -d" << std::endl;
    std::cout << "  Debug parsing." << std::endl;
}

struct Initializer
{
    Initializer()
    {
        soulng::util::Init();
        sngcpp::pp::Init();
    }
    ~Initializer()
    {
        sngcpp::pp::Done();
        soulng::util::Done();
    }
};

int main(int argc, const char** argv)
{
    Initializer initializer;
    try
    {
        bool verbose = false;
        bool debug = false;
        std::string root;
        std::string includePath;
        std::vector<std::string> fileNames;
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
                else if (arg == "--root")
                {
                    ++i;
                    if (i < argc)
                    {
                        arg = argv[i];
                        root = GetFullPath(arg);
                    }
                    else
                    {
                        throw std::runtime_error("argument expected");
                    }
                }
                else if (arg == "--include")
                {
                    ++i;
                    if (i < argc)
                    {
                        arg = argv[i];
                        includePath = GetFullPath(arg);
                    }
                    else
                    {
                        throw std::runtime_error("argument expected");
                    }
                }
                else if (arg == "--debug")
                {
                    debug = true;
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
                    throw std::runtime_error("unknown option '" + arg + "'");
                }
                for (char o : options)
                {
                    if (o == 'h')
                    {
                        PrintUsage();
                        return 1;
                    }
                    else if (o == 'v')
                    {
                        verbose = true;
                    }
                    else if (o == 'd')
                    {
                        debug = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            {
                fileNames.push_back(GetFullPath(arg));
            }
        }
        EvaluationContext evaluationContext;
        std::vector<std::unique_ptr<SourceFileNode>> sourceFiles;
        int fileIndex = 0;
        for (const std::string& fileName : fileNames)
        {
            if (verbose)
            {
                std::cout << "> " << fileName << std::endl;
            }
            PP pp(evaluationContext);
            if (!root.empty())
            {
                pp.root = root;
                pp.rootMode = true;
            }
            if (!includePath.empty())
            {
                pp.includePath = Split(includePath, ';');
            }
            pp.Define(sngcpp::pp::ndebug);
            if (verbose)
            {
                pp.verbose = true;
            }
            Preprocess(fileName, &pp);
            std::unique_ptr<std::u32string> content(new std::u32string(std::move(pp.text)));
            XmlParsingLog log(std::cerr);
            CppLexer lexer(content->c_str(), content->c_str() + content->length(), fileName, fileIndex);
            lexer.SetSeparatorChar('\n');
            if (debug)
            {
                lexer.SetLog(&log);
            }
            std::unique_ptr<SourceFileNode> sourceFile(new SourceFileNode(lexer.GetSpan(), fileName, Path::GetFileName(fileName), U""));
            sourceFile->SetSourceFileIndex(fileIndex);
            SourceFileParser::Parse(lexer, sourceFile.get());
            sourceFile->SetContent(std::move(content));
            sourceFile->SetHeaderFilePaths(std::move(pp.headerFilePaths));
            sourceFiles.push_back(std::move(sourceFile));
            ++fileIndex;
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

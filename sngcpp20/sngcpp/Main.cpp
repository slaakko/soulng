// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/project/Project.hpp>
#include <sngcpp20/driver/Interface.hpp>
#include <sngcpp20/parser/ClassParser.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/InitDone.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/ast/InitDone.hpp>
#include <sngcpp20/config/Config.hpp>
#include <sngcpp20/pp/InitDone.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Element.hpp>
#include <soulng/rex/Context.hpp>
#include <soulng/rex/Nfa.hpp>
#include <soulng/rex/Match.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Util.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace sngcpp::project;
using namespace sngcpp::driver;
using namespace sngcpp::symbols;
using namespace soulng::rex;
using namespace soulng::util;
using namespace soulng::unicode;

const char* Version()
{
    return "4.0.0";
}


void PrintHelp()
{
    std::cout << "sngcpp version " << Version() << std::endl;
    std::cout << std::endl;
    std::cout << "sngcpp is a C++20 parser testing program." << std::endl;
    std::cout << "It parses C++ source and header files, and writes output in " << std::endl;
    std::cout << "varying formats to output files or to the standard output." << std::endl;
    std::cout << std::endl;
    std::cout << "Usage: sngcpp [options] [ PATH... ]" << std::endl;
    std::cout << std::endl;
    std::cout << "Each PATH can be a source file path, source file mask or a directory path." << std::endl;
    std::cout << "If PATH is an existing source file path or a source file mask, " << std::endl;
    std::cout << "for example foo.cpp or *.h, sngcpp parsers the specified file(s) and writes outputs in formats that" << std::endl;
    std::cout << "depend on the given options." << std::endl;
    std::cout << "In this case an optional destination directory path can be given." << std::endl;
    std::cout << "If there is no directory path, current directory is set as the destination directory." << std::endl;
    std::cout << std::endl;
    std::cout << "If there are no file paths or file masks, first directory PATH should contains a 'sngcpp.xml' project file to process," << std::endl;
    std::cout << "and an optional second directory PATH is set as the destination directory for generated files (if any). " << std::endl;
    std::cout << "If there is no second directory PATH, current working directory is set as the destination directory." << std::endl;
    std::cout << "The 'sngcpp.xml' project file contains a source directory path and source file names to process." << std::endl;
    std::cout << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << std::endl;
    std::cout << "--verbose | -v" << std::endl;
    std::cout << "  be verbose" << std::endl;
    std::cout << std::endl;
    std::cout << "--help | -h" << std::endl;
    std::cout << "  print help and exit" << std::endl;
    std::cout << std::endl;
    std::cout << "--out | -o" << std::endl;
    std::cout << "  write outputs to file.EXT.OUT " << std::endl;
    std::cout << "  by default writes output to stdout" << std::endl;
    std::cout << "  EXT = source file extension (e.g. hpp or cpp)" << std::endl;
    std::cout << "  OUT = pp for preprocessing output" << std::endl;
    std::cout << "  OUT = par for parsed output" << std::endl;
    std::cout << "  OUT = xml for XML output" << std::endl;
    std::cout << "  OUT = bin for binary AST output" << std::endl;
    std::cout << "  OUT = log for parsing log" << std::endl;
    std::cout << std::endl;
    std::cout << "--pp | -e" << std::endl;
    std::cout << "  generate preprocessing output" << std::endl;
    std::cout << std::endl;
    std::cout << "--print-macros | -i" << std::endl;
    std::cout << "  print macro definitions after preprocessing" << std::endl;
    std::cout << std::endl;
    std::cout << "--par | -p" << std::endl;
    std::cout << "  generate parsed output" << std::endl;
    std::cout << std::endl;
    std::cout << "--xml | -x" << std::endl;
    std::cout << "  generate XML output" << std::endl;
    std::cout << std::endl;
    std::cout << "--bin | -b" << std::endl;
    std::cout << "  generate binary AST to FILE.EXT.bin" << std::endl;
    std::cout << std::endl;
    std::cout << "--log | -l" << std::endl;
    std::cout << "  generate parsing log" << std::endl;
    std::cout << std::endl;
    std::cout << "--all | -a" << std::endl;
    std::cout << "  generate all except log" << std::endl;
    std::cout << std::endl;
    std::cout << "--test | -t" << std::endl;
    std::cout << "  compare generated files in destination directory to generated files in source directory and generate a HTML report." << std::endl;
    std::cout << std::endl;
    std::cout << "--makeconfig [CONFIG] | -g [CONFIG]" << std::endl;
    std::cout << "  make configuration XML file CONFIG.config.xml and write it to current directory" << std::endl;
    std::cout << "  if no CONFIG name is given, make default sngcpp.config.xml and write it to current directory" << std::endl;
    std::cout << std::endl;
    std::cout << "--config=CONFIG | -c=CONFIG" << std::endl;
    std::cout << "  use CONFIG configuration" << std::endl;
    std::cout << std::endl;
    std::cout << "--makeproject | -m  [--patterns=PATTERNS | -P=PATTERNS] [--recursive | -r]" << std::endl;
    std::cout << "  make project XML file sngcpp.xml from contents of first directory PATH" << std::endl;
    std::cout << "  write the project file to second directory PATH, or to current directory if there is no second directory PATH" << std::endl;
    std::cout << "  if no  directory PATH given, make project XML from contents of current directory" << std::endl;
    std::cout << "  PATTERNS is source file patterns to process separated by semicolons" << std::endl;
    std::cout << "  PATTERNS is by default \"*.c;*.h;*.cpp;*.hpp;*.cxx;*.hxx;*.ixx\"" << std::endl;
    std::cout << std::endl;
    std::cout << "If sole directory PATH is given, process project file 'sngcpp.xml' in that directory and " << std::endl;
    std::cout << "write outputs (if any) to the current working directory." << std::endl;
    std::cout << "If two directory PATHs are given, process project file 'sngcpp.xml' in the first directory and " << std::endl;
    std::cout << "write outputs to the second directory." << std::endl;
    std::cout << std::endl;
    std::cout << "If no PATHs are given, process 'sngcpp.xml' in the current directory." << std::endl;
    std::cout << std::endl;
}

void TestClassParse()
{
    std::u32string content(U"class Foo{};\n}");
    CppLexer lexer(content, "", 0);
    ++lexer;
    lexer.SetLine(1);
    SymbolTable symbolTable;
    sngcpp::symbols::Context context;
    context.SetSymbolTable(&symbolTable);
    ClassParser::ClassSpecifier(lexer, &context);
    //TranslationUnitParser::TranslationUnit(lexer, &context);
}

enum class Options : int
{
    none = 0, 
    preprocess = 1 << 0, 
    parse = 1 << 1, 
    xml = 1 << 2, 
    bin = 1 << 3, 
    log = 1 << 4, 
    all = preprocess | parse | xml | bin,
    printMacros = 1 << 5,
    preprocessOptions = preprocess | printMacros
};

inline Options operator|(Options left, Options right)
{
    return Options(int(left) | int(right));
}

inline Options operator&(Options left, Options right)
{
    return Options(int(left) & int(right));
}

inline Options operator~(Options opts)
{
    return Options(~int(opts));
}

bool CompareFiles(const std::string& outFilePath, const std::string& compareFilePath, sngxml::dom::Element* testResult)
{
    std::unique_ptr<sngxml::dom::Element> compareResultElement(new sngxml::dom::Element(U"compareResult"));
    compareResultElement->SetAttribute(U"file", ToUtf32(Path::GetFileName(outFilePath)));
    bool result = FileContentsEqual(outFilePath, compareFilePath);
    if (result)
    {
        compareResultElement->SetAttribute(U"pass", U"true");
    }
    else if (!boost::filesystem::exists(compareFilePath))
    {
        compareResultElement->SetAttribute(U"pass", U"false");
        compareResultElement->SetAttribute(U"reason", U"source file does not exist");
    }
    else if (!boost::filesystem::exists(outFilePath))
    {
        compareResultElement->SetAttribute(U"pass", U"false");
        compareResultElement->SetAttribute(U"reason", U"target file does not exist");
    }
    else
    {
        compareResultElement->SetAttribute(U"pass", U"false");
        compareResultElement->SetAttribute(U"reason", U"source and target files differ");
    }
    testResult->AppendChild(std::unique_ptr<sngxml::dom::Node>(compareResultElement.release()));
    return result;
}

std::unique_ptr<PPResult> Preprocess(const std::string& filePath, std::ostream& stream, const std::string& outFilePath, bool verbose, int level, Options options, const Configuration& configuration)
{
    if (verbose)
    {
        std::cout << std::string(level, '>') << "pp> " << Path::GetFileName(filePath) << std::endl;
    }
    std::unique_ptr<PPResult> result = Preprocess(filePath, configuration, (options & Options::printMacros) != Options::none);
    if (result)
    {
        Lexeme resultText = result->ResultText();
        stream << ToUtf8(resultText.ToString()) << std::endl;
        if (verbose)
        {
            if (!outFilePath.empty())
            {
                std::cout << "==> " << outFilePath << std::endl;
            }
        }
    }
    return result;
}

ParseResult Parse(std::unique_ptr<PPResult>&& ppResult, const std::string& filePath, ParseOptions parseOptions, Options options, const Configuration& configuration, 
    bool verbose, int level)
{
    if (verbose)
    {
        std::cout << std::string(level, '>') << "p> " << Path::GetFileName(filePath) << std::endl;
    }
    if (!ppResult)
    {
        return Parse(filePath, parseOptions, configuration, (options & Options::printMacros) != Options::none);
    }
    else
    {
        return Parse(std::move(ppResult), parseOptions);
    }
}

void WriteError(const std::string& error, std::ostream& stream, const std::string& outFilePath, const std::string& compareFilePath, bool verbose)
{
    stream << error << std::endl;
    if (verbose)
    {
        if (!outFilePath.empty())
        {
            std::cout << "==> " << outFilePath << std::endl;
        }
    }
}

void WriteSourceCode(Node* translationUnit, std::ostream& stream, const std::string& outFilePath, bool verbose)
{
    WriteSourceCode(translationUnit, stream);
    if (verbose)
    {
        if (!outFilePath.empty())
        {
            std::cout << "==> " << outFilePath << std::endl;
        }
    }
}

void WriteXml(Node* translationUnit, std::ostream& stream, const std::string& outFilePath, bool verbose)
{
    WriteXml(translationUnit, stream);
    if (verbose)
    {
        if (!outFilePath.empty())
        {
            std::cout << "==> " << outFilePath << std::endl;
        }
    }
}

void WriteBinary(Node* translationUnit, const std::string& outFilePath, bool verbose)
{
    WriteBinary(translationUnit, outFilePath);
    if (verbose)
    {
        if (!outFilePath.empty())
        {
            std::cout << "==> " << outFilePath << std::endl;
        }
    }
    std::unique_ptr<Node> readTranslationUnit = ReadBinary(outFilePath);
    std::string txtFilePath = outFilePath + ".txt";
    WriteSourceCode(readTranslationUnit.get(), txtFilePath);
}

bool ProcessFile(const std::string& filePath, const std::string destDir, Options options, bool out, bool verbose, int level, sngxml::dom::Element* testResult, const Configuration& configuration)
{
    std::unique_ptr<sngxml::dom::Element> fileResult;
    if (testResult)
    {
        fileResult.reset(new sngxml::dom::Element(U"fileResult"));
    }
    int outputCount = 0;
    int failCount = 0;
    bool processingResult = true;
    std::ostream* stream = &std::cout;
    std::unique_ptr<PPResult> ppResult;
    if ((options & Options::preprocess) != Options::none)
    {
        ++outputCount;
        std::string compareFilePath = filePath + ".pp";
        std::string outFilePath;
        {
            std::ofstream fstream;
            if (out)
            {
                outFilePath = Path::Combine(destDir, Path::GetFileName(filePath) + ".pp");
                fstream.open(outFilePath);
                stream = &fstream;
            }
            ppResult = Preprocess(filePath, *stream, outFilePath, verbose, level, options, configuration);
        }
        if (fileResult && !outFilePath.empty() && !compareFilePath.empty())
        {
            if (!CompareFiles(outFilePath, compareFilePath, fileResult.get()))
            {
                processingResult = false;
                ++failCount;
            }
        }
    }
    ParseOptions parseOptions;
    if ((options & ~Options::preprocessOptions) != Options::none)
    {
        parseOptions.FileName(filePath);
        parseOptions.Throw(false);
        if ((options & Options::log) != Options::none)
        {
            parseOptions.Log(true);
            if (out)
            {
                parseOptions.LogFilePath(Path::Combine(destDir, Path::GetFileName(filePath) + ".log"));
            }
        }
        ParseResult result = Parse(std::move(ppResult), filePath, parseOptions, options, configuration, verbose, level);
        if (!result.error.empty())
        {
            ++outputCount;
            std::string compareFilePath = filePath + ".error";
            std::string outFilePath;
            {
                std::ofstream fstream;
                if (out)
                {
                    outFilePath = Path::Combine(destDir, Path::GetFileName(filePath) + ".error");
                    fstream.open(outFilePath);
                    stream = &fstream;
                }
                WriteError(result.error, *stream, outFilePath, compareFilePath, verbose);
            }
            if (fileResult && !outFilePath.empty() && !compareFilePath.empty())
            {
                if (!CompareFiles(outFilePath, compareFilePath, fileResult.get()))
                {
                    processingResult = false;
                    ++failCount;
                }
            }
        }
        else
        {
            if ((options & Options::parse) != Options::none)
            {
                ++outputCount;
                std::string compareFilePath = filePath + ".par";
                std::string outFilePath;
                {
                    std::ofstream fstream;
                    if (out)
                    {
                        outFilePath = Path::Combine(destDir, Path::GetFileName(filePath) + ".par");
                        fstream.open(outFilePath);
                        stream = &fstream;
                    }
                    WriteSourceCode(result.translationUnitNode.get(), *stream, outFilePath, verbose);
                }
                if (fileResult && !outFilePath.empty() && !compareFilePath.empty())
                {
                    if (!CompareFiles(outFilePath, compareFilePath, fileResult.get()))
                    {
                        processingResult = false;
                        ++failCount;
                    }
                }
            }
            if ((options & Options::xml) != Options::none)
            {
                ++outputCount;
                std::string compareFilePath = filePath + ".xml";
                std::string outFilePath;
                {
                    std::ofstream fstream;
                    if (out)
                    {
                        outFilePath = Path::Combine(destDir, Path::GetFileName(filePath) + ".xml");
                        fstream.open(outFilePath);
                        stream = &fstream;
                    }
                    WriteXml(result.translationUnitNode.get(), *stream, outFilePath, verbose);
                }
                if (fileResult && !outFilePath.empty() && !compareFilePath.empty())
                {
                    if (!CompareFiles(outFilePath, compareFilePath, fileResult.get()))
                    {
                        processingResult = false;
                        ++failCount;
                    }
                }
            }
            if ((options & Options::bin) != Options::none)
            {
                ++outputCount;
                std::string compareFilePath = filePath + ".bin";
                std::string outFilePath = Path::Combine(destDir, Path::GetFileName(filePath) + ".bin");
                WriteBinary(result.translationUnitNode.get(), outFilePath, verbose);
                if (fileResult && !outFilePath.empty() && !compareFilePath.empty())
                {
                    if (!CompareFiles(outFilePath, compareFilePath, fileResult.get()))
                    {
                        processingResult = false;
                        ++failCount;
                    }
                }
            }
        }
    }
    if (fileResult)
    {
        fileResult->SetAttribute(U"outputCount", ToUtf32(std::to_string(outputCount)));
        if (processingResult)
        {
            fileResult->SetAttribute(U"pass", U"true");
        }
        else
        {
            fileResult->SetAttribute(U"pass", U"false");
            fileResult->SetAttribute(U"failCount", ToUtf32(std::to_string(failCount)));
        }
        testResult->AppendChild(std::unique_ptr<sngxml::dom::Node>(fileResult.release()));
    }
    return processingResult;
}

bool ProcessProject(const Project& project, Options options, bool out, bool verbose, int level, sngxml::dom::Element* testResult, const Configuration& configuration)
{
    std::unique_ptr<sngxml::dom::Element> projectResult;
    if (testResult)
    {
        projectResult.reset(new sngxml::dom::Element(U"projectResult"));
    }
    bool processingResult = true;
    int childCount = 0;
    int fileCount = 0;
    int failCount = 0;
    if (verbose)
    {
        std::cout << std::string(level, '>') << "> " << project.Name() << std::endl;
    }
    for (const std::unique_ptr<Project>& childProject : project.ChildProjects())
    {
        ++childCount;
        if (!ProcessProject(*childProject, options, out, verbose, level + 1, projectResult.get(), configuration))
        {
            ++failCount;
        }
    }
    for (const File& file : project.Files())
    {
        ++fileCount;
        if (!ProcessFile(file.path, project.DirPath(), options, out, verbose, level + 1, projectResult.get(), configuration))
        {
            processingResult = false;
            ++failCount;
        }
    }
    if (verbose)
    {
        std::cout << std::string(level, '<') << "< " << project.Name() << std::endl;
    }
    if (projectResult)
    {
        projectResult->SetAttribute(U"childCount", ToUtf32(std::to_string(childCount)));
        projectResult->SetAttribute(U"fileCount", ToUtf32(std::to_string(fileCount)));
        if (processingResult)
        {
            projectResult->SetAttribute(U"pass", U"true");
        }
        else
        {
            projectResult->SetAttribute(U"pass", U"false");
            projectResult->SetAttribute(U"failCount", ToUtf32(std::to_string(failCount)));
        }
        testResult->AppendChild(std::unique_ptr<sngxml::dom::Node>(projectResult.release()));
    }
    return processingResult;
}

struct InitDone
{
    InitDone()
    {
        soulng::util::Init();
        sngxml::xpath::Init();
        sngcpp::ast::Init();
        sngcpp::symbols::Init();
        sngcpp::pp::Init();
    }
    ~InitDone()
    {
        sngcpp::pp::Done();
        sngcpp::symbols::Done();
        sngcpp::ast::Done();
        sngxml::xpath::Done();
        soulng::util::Done();
    }
};

int main(int argc, const char** argv)
{
    InitDone initDone;
    try
    {
        std::string config;
        std::string patterns = "*.c;*.h;*.cpp;*.hpp;*.cxx;*.hxx;*.ixx";
        std::vector<std::string> paths;
        bool preprocess = false;
        bool makeProject = false;
        bool verbose = false;
        bool recursive = false;
        bool out = false;
        bool test = false;
        Options options = Options::none;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (arg.starts_with("--"))
            {
                if (arg.find('=') != std::string::npos)
                {
                    std::vector<std::string> components = Split(arg, '=');
                    if (components.size() == 2)
                    {
                        if (components[0] == "--patterns")
                        {
                            patterns = components[1];
                        }
                        else if (components[0] == "--config")
                        {
                            config = components[1];
                        }
                        else
                        {
                            throw std::runtime_error("unknown option '" + arg + "'");
                        }
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '" + arg + "'");
                    }
                }
                else
                {
                    if (arg == "--all")
                    {
                        options = Options::all;
                    }
                    else if (arg == "--pp")
                    {
                        options = options | Options::preprocess;
                    }
                    else if (arg == "--print-macros")
                    {
                        options = options | Options::printMacros;
                    }
                    else if (arg == "--par")
                    {
                        options = options | Options::parse;
                    }
                    else if (arg == "--xml")
                    {
                        options = options | Options::xml;
                    }
                    else if (arg == "--bin")
                    {
                        options = options | Options::bin;
                    }
                    else if (arg == "--log")
                    {
                        options = options | Options::log;
                    }
                    else if (arg == "--test")
                    {
                        test = true;
                    }
                    else if (arg == "--makeproject")
                    {
                        makeProject = true;
                    }
                    else if (arg == "--verbose")
                    {
                        verbose = true;
                    }
                    else if (arg == "--recursive")
                    {
                        recursive = true;
                    }
                    else if (arg == "--out")
                    {
                        out = true;
                    }
                    else if (arg == "--help")
                    {
                        PrintHelp();
                        return 1;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '" + arg + "'");
                    }
                }
            }
            else if (arg.starts_with("-"))
            {
                if (arg.find('=') != std::string::npos)
                {
                    std::vector<std::string> components = Split(arg, '=');
                    if (components.size() == 2)
                    {
                        if (components[0] == "-P")
                        {
                            patterns = components[1];
                        }
                        else if (components[0] == "-c")
                        {
                            config = components[1];
                        }
                        else
                        {
                            throw std::runtime_error("unknown option '" + arg + "'");
                        }
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '" + arg + "'");
                    }
                }
                else
                {
                    std::string optstr = arg.substr(1);
                    for (char o : optstr)
                    {
                        switch (o)
                        {
                            case 'm':
                            {
                                makeProject = true;
                                break;
                            }
                            case 'a':
                            {
                                options = Options::all;
                                break;
                            }
                            case 'e':
                            {
                                options = options | Options::preprocess;
                                break;
                            }
                            case 'i':
                            {
                                options = options | Options::printMacros;
                                break;
                            }
                            case 'p':
                            {
                                options = options | Options::parse;
                                break;
                            }
                            case 'x':
                            {
                                options = options | Options::xml;
                                break;
                            }
                            case 'b':
                            {
                                options = options | Options::bin;
                                break;
                            }
                            case 'l':
                            {
                                options = options | Options::log;
                                break;
                            }
                            case 't':
                            {
                                test = true;
                                break;
                            }
                            case 'v':
                            {
                                verbose = true;
                                break;
                            }
                            case 'h':
                            {
                                PrintHelp();
                                return 1;
                            }
                            case 'r':
                            {
                                recursive = true;
                                break;
                            }
                            case 'o':
                            {
                                out = true;
                                break;
                            }
                            default:
                            {
                                throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                            }
                        }
                    }
                }
            }
            else
            {
                paths.push_back(GetFullPath(arg));
            }
        }
        if (paths.empty())
        {
            paths.push_back(GetFullPath("."));
        }
        soulng::rex::Context context;
        std::vector<std::string> filePaths;
        std::vector<std::string> dirPaths;
        for (const std::string& path : paths)
        {
            if (boost::filesystem::exists(path))
            {
                if (boost::filesystem::is_directory(path))
                {
                    dirPaths.push_back(path);
                }
                else
                {
                    filePaths.push_back(path);
                }
            }
            else
            {
                std::string dir = Path::GetDirectoryName(path);
                if (!dir.empty())
                {
                    if (boost::filesystem::exists(dir))
                    {
                        std::string fileMask = Path::GetFileName(path);
                        std::vector<std::string> fileNames;
                        boost::filesystem::directory_iterator it(dir);
                        while (it != boost::filesystem::directory_iterator())
                        {
                            boost::filesystem::directory_entry entry(*it);
                            std::string filePath = GetFullPath(entry.path().generic_string());
                            std::string fileName = Path::GetFileName(filePath);
                            if (FilePatternMatch(ToUtf32(fileName), ToUtf32(fileMask)))
                            {
                                filePaths.push_back(Path::Combine(dir, fileName));
                            }
                            ++it;
                        }
                    }
                    else
                    {
                        throw std::runtime_error("directory '" + dir + "' not found");
                    }
                }
                else
                {
                    throw std::runtime_error("path '" + path + "' not found");
                }
            }
        }
        if (makeProject)
        {
            std::string sourceDir;
            if (!dirPaths.empty())
            {
                sourceDir = dirPaths.front();
            }
            std::string projectDir;
            if (dirPaths.size() > 1)
            {
                projectDir = dirPaths[1];
            }
            MakeProjectFile(sourceDir, projectDir, patterns, 0, recursive, verbose);
        }
        else
        {
            Configuration configuration(config);
            if (options == Options::none)
            {
                options = Options::parse;
            }
            if (!filePaths.empty())
            {
                std::string destDir;
                if (dirPaths.empty())
                {
                    destDir = GetFullPath(".");
                }
                else
                {
                    destDir = dirPaths.front();
                }
                for (const std::string& filePath : filePaths)
                {
                    ProcessFile(filePath, destDir, options, out, verbose, 0, nullptr, configuration);
                }
            }
            else
            {
                std::string projectDir;
                std::string destDir;
                if (dirPaths.empty())
                {
                    projectDir = GetFullPath(".");
                    destDir = projectDir;
                }
                else
                {
                    projectDir = dirPaths.front();
                }
                Project project(projectDir, verbose);
                ProcessProject(project, options, out, verbose, 0, nullptr, configuration);
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

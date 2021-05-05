// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/project/Project.hpp>
#include <sngcpp20/driver/Interface.hpp>
#include <sngcpp20/parser/ClassParser.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <soulng/rex/Context.hpp>
#include <soulng/rex/Nfa.hpp>
#include <soulng/rex/Match.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace sngcpp::project;
using namespace sngcpp::driver;
using namespace sngcpp::symbols;
using namespace sngcpp::par;
using namespace soulng::rex;
using namespace soulng::util;
using namespace soulng::unicode;

void PrintHelp()
{
    std::cout << "sngcpp [options] [ { SOURCEFILES } | DIRPATH ]" << std::endl;
    std::cout << std::endl;
    std::cout << "SOURCEFILES consists of source files to process" << std::endl;
    std::cout << "For example: foo.cpp or *.h" << std::endl;
    std::cout << std::endl;
    std::cout << "DIRPATH is path to a directory that contains sngcpp.xml project file to process" << std::endl;
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
    std::cout << "--makeconfig [CONFIG] | -g [CONFIG]" << std::endl;
    std::cout << "  make configuration XML file CONFIG.config.xml and write it to current directory" << std::endl;
    std::cout << "  if no CONFIG name is given, make default sngcpp.config.xml and write it to current directory" << std::endl;
    std::cout << std::endl;
    std::cout << "--config=CONFIG | -c=CONFIG" << std::endl;
    std::cout << "  use CONFIG configuration" << std::endl;
    std::cout << std::endl;
    std::cout << "--makeproject | -m  [--patterns=PATTERNS | -t=PATTERNS]" << std::endl;
    std::cout << "  make project XML file sngcpp.xml from contents of DIRPATH and write it to current directory" << std::endl;
    std::cout << "  if no DIRPATH given, make project XML from contents of current directory" << std::endl;
    std::cout << "  PATTERNS is source file patterns to process separated by semicolons" << std::endl;
    std::cout << "  PATTERNS is by default \"*.cpp;*.hpp;*.ixx\"" << std::endl;
    std::cout << std::endl;
    std::cout << "if sole DIRPATH is given, process project file sngcpp.xml in that directory" << std::endl;
    std::cout << std::endl;
    std::cout << "if no SOURCEFILES and no DIRPATH is given, process sngcpp.xml in the current directory" << std::endl;
    std::cout << std::endl;
}

void TestClassParse()
{
    std::u32string content(U"class Foo{};\n}");
    CppLexer lexer(content, "", 0);
    ++lexer;
    lexer.SetLine(1);
    SymbolTable symbolTable;
    sngcpp::par::Context context;
    context.SetSymbolTable(&symbolTable);
    ClassParser::ClassSpecifier(lexer, &context);
    //TranslationUnitParser::TranslationUnit(lexer, &context);
}
int main(int argc, const char** argv)
{
    try
    {
        std::string patterns = "*.c;*.h;*.cpp;*.hpp;*.cxx;*.hxx;*.ixx";
        std::vector<std::string> paths;
        bool preprocess = false;
        bool makeProject = false;
        bool verbose = false;
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
                    if (arg == "--pp")
                    {
                        preprocess = true;
                    }
                    else if (arg == "--makeproject")
                    {
                        makeProject = true;
                    }
                    else if (arg == "--verbose")
                    {
                        verbose = true;
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
                        if (components[0] == "-t")
                        {
                            patterns = components[1];
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
                    std::string options = arg.substr(1);
                    for (char o : options)
                    {
                        switch (o)
                        {
                            case 'm':
                            {
                                makeProject = true;
                                break;
                            }
                            case 'e':
                            {
                                preprocess = true;
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
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

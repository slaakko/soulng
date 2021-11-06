#include <minixml.hpp>
#include <rules.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/lexer/TrivialLexer.hpp>
#include <iostream>

using namespace soulng::unicode;
using namespace soulng::util;

int main()
{
    try
    {
        std::string fileName = "C:/work/soulng/doc/topics/farthest_error/minixml/philosophers.xml";
        std::string file = ReadFile(fileName);
        std::u32string content = ToUtf32(file);
        TrivialLexer lexer(content, fileName, 0);
        lexer.SetFlag(soulng::lexer::LexerFlags::farthestError);
        lexer.SetRuleNameVecPtr(GetRuleNameVecPtr());
        minixml::Parse(lexer);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

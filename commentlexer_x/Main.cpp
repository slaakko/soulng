#include <soulng/commentlexer/CommentLexer.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>

using namespace soulng::lexer;
using namespace soulng::unicode;

int main()
{
    std::string s = "/* foo */ foo\n // bar\n bar";
    std::u32string content = ToUtf32(s);
    CommentLexer lexer(content, "foo.cm", 0);
    ++lexer;
    int tokenId = *lexer;
    while (tokenId != END)
    {
        ++lexer;
        tokenId = *lexer;
    }
}

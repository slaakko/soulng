// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/slg/RegularExpressionParser.hpp>
#include <soulng/slg/RegExLexer.hpp>
#include <soulng/slg/RegExParser.hpp>
#include <soulng/slg/LexerContext.hpp>
#include <stdexcept>

namespace soulng { namespace slg {

Nfa RegularExpressionParser::Parse(const std::u32string& expression, LexerContext* lexerContext, int line)
{
    try
    {
        RegExLexer lexer(expression, lexerContext->FileName(), 0);
        return RegExParser::Parse(lexer, lexerContext);
    }
    catch (const std::exception& ex)
    {
        throw std::runtime_error("error parsing regular expression at " + lexerContext->FileName() + ":" + std::to_string(line) + ": " + ex.what());
    }
}

} } // namespace soulng::slg

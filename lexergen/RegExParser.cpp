// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexergen/RegExParser.hpp>

namespace soulng { namespace lexergen {

RegExParser::RegExParser() : grammar(RegExGrammar::Create())
{
}

Nfa RegExParser::Parse(const std::u32string& expression, LexerContext* lexerContext)
{
    return grammar->Parse(expression.c_str(), expression.c_str() + expression.length(), 0, lexerContext->FileName(), lexerContext);
}

} } // namespace soulng::lexergen

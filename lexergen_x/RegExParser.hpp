// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXERGEN_REGEX_PARSER_INCLUDED
#define SOULNG_LEXERGEN_REGEX_PARSER_INCLUDED
#include <soulng/lexergen/RegEx.hpp>

namespace soulng { namespace lexergen {

class RegExParser : public Parser
{
public:
    RegExParser();
    Nfa Parse(const std::u32string& expression, LexerContext* lexerContext) override;
private:
    soulng::lexergen::RegExGrammar* grammar;
};

} } // namespace soulng::lexergen

#endif // SOULNG_LEXERGEN_REGEX_PARSER_INCLUDED

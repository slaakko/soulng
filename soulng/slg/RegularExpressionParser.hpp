// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_REGEX_PARSER_INCLUDED
#define SOULNG_SLG_REGEX_PARSER_INCLUDED
#include <soulng/slg/Model.hpp>

namespace soulng { namespace slg {

class RegularExpressionParser : public Parser
{
public:
    Nfa Parse(const std::u32string& expression, LexerContext* lexerContext, int line) override;
};

} } // namespace soulng::slg

#endif // SOULNG_SLG_REGEX_PARSER_INCLUDED

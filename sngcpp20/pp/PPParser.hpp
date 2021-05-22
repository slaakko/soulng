// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_PARSER_INCLUDED
#define SNGCPP_PP_PARSER_INCLUDED
#include <sngcpp20/pp/PPLexer.hpp>

namespace sngcpp::pp {

class PP;

PP_API void ParseControlLine(PPLexer& lexer);
PP_API std::string ParseAngleHeaderName(const soulng::lexer::Token& headerNameToken, PP* pp);
PP_API std::string ParseQuoteHeaderName(const soulng::lexer::Token& headerNameToken, PP* pp);
PP_API bool ParseReplacementList(PPLexer& lexer, std::vector<Token>& replacementList);

} // namespace sngcpp::pp

#endif // SNGCPP_PP_PARSER_INCLUDED

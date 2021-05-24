// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_UTIL_INCLUDED
#define SNGCPP_PP_UTIL_INCLUDED
#include <sngcpp20/pp/PPLexer.hpp>

namespace sngcpp::pp {

class PP;

PP_API bool IsPPLine(const Lexeme& line);
PP_API int GetNumberOfNewLines(const Lexeme& lexeme);
PP_API std::vector<Token> TrimTextTokens(const std::vector<Token>& tokens);
PP_API std::vector<Token> RemoveWhiteSpace(const std::vector<Token>& tokens);
PP_API Token Stringize(const std::vector<Token>& tokens, PP* pp);
PP_API std::vector<Token> ConcatenateTokens(const std::vector<Token>& tokens, PP* pp);
PP_API bool ContainsHash(const std::vector<Token>& tokens);
PP_API bool ContainsHashHash(const std::vector<Token>& tokens);
PP_API bool IsMSPragma(const std::vector<Token>& tokens, const Lexeme& mspragmaLexeme, std::vector<Token>& pragmaTokens, int& newLines);

} // namespace sngcpp::pp

#endif // SNGCPP_PP_UTIL_INCLUDED

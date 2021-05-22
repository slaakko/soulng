// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_SCAN_INCLUDED
#define SNGCPP_PP_SCAN_INCLUDED
#include <sngcpp20/pp/PPApi.hpp>
#include <soulng/lexer/Lexer.hpp>

namespace sngcpp::pp {

PP_API bool ScanRawStringLiteral(soulng::lexer::Lexer& lexer, soulng::lexer::Token& token);
PP_API bool ScanBlockComment(soulng::lexer::Lexer& lexer, soulng::lexer::Token& token);
PP_API bool ScanLineCommentWithoutNewLine(soulng::lexer::Lexer& lexer, soulng::lexer::Token& token);

} // namespace sngcpp::pp

#endif // SNGCPP_PP_SCAN_INCLUDED

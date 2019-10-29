// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/parser/SourceLineParser.hpp>
#include <sngcpp/lexer/CppTokenLexer.hpp>
#include <sngcpp/lexer/CppTokenLexerTokens.hpp>

void ParseSourceLine(const std::u32string& sourceLine, sngcpp::ast::SourceCodeWriter& sourceCodeWriter)
{
    using namespace CppTokenLexerTokens;

    std::u32string line(sourceLine);
    line.append(U"\n");
    CppTokenLexer lexer(line, "", 0);
    lexer.SetSeparatorChar('\n');
    lexer.writer = &sourceCodeWriter;
    ++lexer;
    int i = 0;
    while (*lexer != END)
    {
        switch (*lexer)
        {
            case WS: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteSpaces(token.match.ToString()); break; }
            case LINECOMMENT: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteLineComment(token.match.ToString()); return; }
            case BLOCKCOMMENT: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteBlockComment(token.match.ToString()); break; }
            case KEYWORD: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteKeyword(token.match.ToString()); break; }
            case ID: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteIdentifier(token.match.ToString()); break; }
            case CHARLIT: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteChar(token.match.ToString()); break; }
            case STRINGLIT: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteString(token.match.ToString()); break; }
            case NUMBER: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteNumber(token.match.ToString()); break; }
            case PP: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WritePP(token.match.ToString()); break; }
            case OTHER: { soulng::lexer::Token token = lexer.GetToken(i); sourceCodeWriter.WriteOther(token.match.ToString()); break; }
        }
        ++lexer;
        ++i;
    }
}

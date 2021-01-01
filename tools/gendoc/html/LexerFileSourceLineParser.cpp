// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <gendoc/html/LexerFileSourceLineParser.hpp>
#include <gendoc/html/LexerFileTokenLexerTokens.hpp>
#include <gendoc/html/LexerFileTokenLexer.hpp>

void ParseLexerFileSourceLine(const std::u32string& sourceLine, sngcpp::ast::SourceCodeWriter& sourceCodeWriter)
{
    using namespace LexerFileTokenLexerTokens;

    std::u32string line(sourceLine);
    line.append(U"\n");
    LexerFileTokenLexer lexer(line, "", 0);
    lexer.SetSeparatorChar('\n');
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

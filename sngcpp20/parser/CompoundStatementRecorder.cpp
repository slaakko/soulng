// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/parser/CompoundStatementRecorder.hpp>
#include <sngcpp20/parser/StatementParser.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <soulng/lexer/Lexer.hpp>

namespace sngcpp::par {

using namespace CppTokens;

soulng::lexer::LexerPosPair RecordCompoundStatement(CppLexer& lexer)
{
    int64_t start = lexer.GetPos();
    int braceCount = 0;
    while (*lexer != END)
    {
        if (*lexer == LBRACE)
        {
            ++braceCount;
        }
        else if (*lexer == RBRACE)
        {
            if (braceCount > 0)
            {
                --braceCount;
                if (braceCount == 0)
                {
                    ++lexer;
                    int64_t end = lexer.GetPos();
                    return soulng::lexer::LexerPosPair(start, end);
                }
            }
            else
            {
                lexer.SetPos(start);
                return soulng::lexer::LexerPosPair();
            }
        }
        else if (braceCount == 0)
        {
            lexer.SetPos(start);
            return soulng::lexer::LexerPosPair();
        }
        ++lexer;
    }
    lexer.SetPos(start);
    return soulng::lexer::LexerPosPair();
}

void PushSavedCompoundStatementNode(CompoundStatementNode* node, sngcpp::symbols::Context* context)
{
    context->PushNode(node);
}

void PopSavedCompoundStatementNode(sngcpp::symbols::Context* context)
{
    context->PopNode();
}

CompoundStatementNode* GetSavedCompoundStatementNode(sngcpp::symbols::Context* context)
{
    Node* n = context->GetNode();
    if (n && n->Kind() == NodeKind::compoundStatementNode)
    {
        return static_cast<CompoundStatementNode*>(n);
    }
    else
    {
        throw std::runtime_error("context has no compound statement node");
    }
}

void RecordedParse(CompoundStatementNode* node, sngcpp::symbols::Context* context)
{
    context->PushSetFlag(sngcpp::symbols::ContextFlags::parseSavedMemberFunctionBody);
    PushSavedCompoundStatementNode(node, context);
    StatementParser::CompoundStatement(*static_cast<CppLexer*>(context->GetLexer()), context);
    PopSavedCompoundStatementNode(context);
    context->PopFlags();
}

} // namespace sngcpp::par

// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/parser/CompoundStatementRecorder.hpp>

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

void PushSavedCompoundStatementNode(CompoundStatementNode* node, Context* context)
{
    context->PushNode(node);
}

void PopSavedCompoundStatementNode(Context* context)
{
    context->PopNode();
}

CompoundStatementNode* GetSavedCompoundStatementNode(Context* context)
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


} // namespace sngcpp::par

// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <soulng/lexer/Lexer.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

Context::Context() : flags(ContextFlags::none), bottomUpFlags(ContextFlags::none), node(nullptr), symbolTable(nullptr), lexer(nullptr)
{
}

void Context::PushFlags()
{
    flagStack.push(flags);
}

void Context::PopFlags()
{
    flags = flagStack.top();
    flagStack.pop();
}

void Context::PushSetFlag(ContextFlags flag)
{
    PushFlags();
    flags = flags | flag;
}

void Context::PushResetFlag(ContextFlags flag)
{
    PushFlags();
    flags = flags & ~flag;
}

void Context::ResetBottomUpFlags()
{
    bottomUpFlags = ContextFlags::none;
}

void Context::PushNode(sngcpp::ast::Node* node_)
{
    nodeStack.push(node);
    node = node_;
}

void Context::PopNode()
{
    node = nodeStack.top();
    nodeStack.pop();
}

std::string MappedFileName(Context* context, const soulng::lexer::SourcePos& sourcePos)
{
    soulng::lexer::Lexer* lexer = context->GetLexer();
    if (lexer)
    {
        return lexer->MappedFileName(sourcePos);
    }
    else
    {
        return std::string();
    }
}

std::string MappedFileLine(Context* context, const SourcePos& sourcePos)
{
    soulng::lexer::Lexer* lexer = context->GetLexer();
    if (lexer)
    {
        return lexer->MappedFileLine(sourcePos);
    }
    else
    {
        return std::string();
    }
}

std::string MappedErrorLines(Context* context, const soulng::lexer::SourcePos& sourcePos)
{
    soulng::lexer::Lexer* lexer = context->GetLexer();
    if (lexer)
    {
        soulng::lexer::Token token = lexer->GetToken(sourcePos.pos);
        return lexer->MappedErrorLines(token);
    }
    else
    {
        return std::string();
    }
}

int MappedLineNumber(Context* context, const soulng::lexer::SourcePos& sourcePos)
{
    soulng::lexer::Lexer* lexer = context->GetLexer();
    if (lexer)
    {
        return lexer->MappedLineNumber(sourcePos);
    }
    else
    {
        return sourcePos.line;
    }
}

} // namespace sngcpp::symbols

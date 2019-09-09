#ifndef DELEGATE_HPP
#define DELEGATE_HPP
#include <soulng/cmajorast/Delegate.hpp>
#include <soulng/cmajorparser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Delegate.parser' using soulng parser generator spg version 1.0.0

class CmajorLexer;

struct DelegateParser
{
    static soulng::parser::Match Delegate(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ClassDelegate(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // DELEGATE_HPP

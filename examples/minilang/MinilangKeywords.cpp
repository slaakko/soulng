
// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/Minilang.lexer' using soulng lexer generator slg version 1.0.0

#include "MinilangKeywords.hpp"
#include "MinilangTokens.hpp"

namespace MinilangKeywords
{
    using namespace MinilangTokens;

    Keyword keywords[] =
    {
        {U"if", IF}, 
        {U"else", ELSE}, 
        {U"while", WHILE}, 
        {U"return", RETURN}, 
        {U"int", INT}, 
        {U"bool", BOOL}, 
        {U"void", VOID}, 
        {U"true", TRUE}, 
        {U"false", FALSE},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

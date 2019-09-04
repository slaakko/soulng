
// this file has been automatically generated from 'D:/work/soulng/cmajorlexer/ContainerFileLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <soulng/cmajorlexer/ContainerFileKeywords.hpp>
#include <soulng/cmajorlexer/ContainerFileTokens.hpp>

namespace ContainerFileKeywords
{
    using namespace ContainerFileTokens;

    Keyword keywords[] =
    {
        {U"project", PROJECT}, 
        {U"solution", SOLUTION}, 
        {U"reference", REFERENCE}, 
        {U"source", SOURCE}, 
        {U"text", TEXT}, 
        {U"target", TARGET}, 
        {U"program", PROGRAM}, 
        {U"library", LIBRARY}, 
        {U"unittest", UNITTEST}, 
        {U"activeProject", ACTIVEPROJECT},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

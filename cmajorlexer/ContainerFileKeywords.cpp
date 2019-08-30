#include <soulng/cmajorlexer/ContainerFileKeywords.hpp>
#include <soulng/cmajorlexer/ContainerFileTokens.hpp>

namespace ContainerFileKeywords
{
    using namespace ContainerFileTokens;

    static Keyword keywords[] =
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

    static KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}

#ifndef ProjectFileLexer_HPP
#define ProjectFileLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/tools/sng2html/sng2html/ProjectFileLexer.lexer' using soulng lexer generator slg version 3.0.0

#include <sng2html/sng2html/TokenValueParsers.hpp>
#include <soulng/lexer/Lexer.hpp>

class ProjectFileLexer : public soulng::lexer::Lexer
{
public:
    ProjectFileLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    ProjectFileLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    std::string filePath;
private:
    int GetTokenId(int statementIndex);
};
#endif

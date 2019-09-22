#ifndef ProjectFileLexer_HPP
#define ProjectFileLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/ProjectFileLexer.lexer' using soulng lexer generator slg version 1.1.0

#include <soulng/spg/TokenValueParsers.hpp>
#include <soulng/lexer/Lexer.hpp>

class ProjectFileLexer : public soulng::lexer::Lexer
{
public:
    ProjectFileLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    std::string filePath;
private:
    int GetTokenId(int statementIndex);
};
#endif

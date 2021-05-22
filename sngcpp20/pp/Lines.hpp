// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_LINES_INCLUDED
#define SNGCPP_PP_LINES_INCLUDED
#include <sngcpp20/pp/PPApi.hpp>
#include <soulng/lexer/Lexeme.hpp>
#include <soulng/lexer/SourcePos.hpp>
#include <vector>
#include <map>
#include <memory>

namespace sngcpp::pp {

using namespace soulng::lexer;

class PP;

class PP_API Lines
{
public:
    Lines();
    void Add(const Lexeme& line);
    int Count() const { return lines.size(); }
    const Lexeme& operator[](int index) const { return lines[index]; }
    void SetEnd(const char32_t* end_) { end = end_; }
    const char32_t* End() const { return end; }
private:
    std::vector<Lexeme> lines;
    const char32_t* end;
};

class PP_API LogicalPhysicalMapping
{
public:
    LogicalPhysicalMapping();
    void Map(const SourcePos& logicalLocation, int physicalLine);
    SourcePos GetMappedPos(const SourcePos& sourcePos) const;
    const Lines& PhysicalLines() const { return physicalLines; }
    const Lines& LogicalLines() const { return logicalLines; }
    void SetPhysicalLines(Lines&& physicalLines_) { physicalLines = std::move(physicalLines_); }
    void SetLogicalLines(Lines&& logicalLines_) { logicalLines = std::move(logicalLines_); }
private:
    Lines physicalLines;
    Lines logicalLines;
    std::map<SourcePos, int> map;
};

PP_API std::unique_ptr<LogicalPhysicalMapping> MapLines(const Lexeme& fileContent, PP* pp);

} // namespace sngcpp::pp

#endif // SNGCPP_PP_LINES_INCLUDED

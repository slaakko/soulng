// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/Lines.hpp>
#include <sngcpp20/pp/PP.hpp>

namespace sngcpp::pp {

Lines::Lines() : end(nullptr)
{
}

void Lines::Add(const Lexeme& line)
{
    lines.push_back(line);
}

LogicalPhysicalMapping::LogicalPhysicalMapping()
{
}

void LogicalPhysicalMapping::Map(const SourcePos& logicalLocation, int physicalLine)
{
    map[logicalLocation] = physicalLine;
}

SourcePos LogicalPhysicalMapping::GetMappedPos(const SourcePos& sourcePos) const
{
    auto it = map.lower_bound(sourcePos);
    if (it != map.cend())
    {
        while (it != map.cbegin() && it->first > sourcePos)
        {
            --it;
        }
    }
    if (it != map.cend())
    {
        int line = it->second;
        int col = std::max(1, sourcePos.col - it->first.col);
        return SourcePos(-1, line, col);
    }
    else
    {
        return SourcePos();
    }
}

std::unique_ptr<LogicalPhysicalMapping> MapLines(const Lexeme& fileContent, PP* pp)
{
    std::unique_ptr<LogicalPhysicalMapping> mapping(new LogicalPhysicalMapping());
    Lines physicalLines;
    Lines logicalLines;
    std::u32string resultStr;
    std::vector<int> physicalLineStartIndeces;
    std::vector<int> logicalLineStartIndeces;
    const char32_t* p = fileContent.begin;
    const char32_t* e = fileContent.end;
    int physicalLineNumber = 1;
    SourcePos logicalPos(-1, 1, 1);
    if (p == e)
    {
        resultStr.append(1, '\n');
        physicalLineStartIndeces.push_back(0);
        logicalLineStartIndeces.push_back(0);
    }
    int state = 0;
    bool startOfPhysicalLine = true;
    bool startOfLogicalLine = true;
    int physicalIndex = 0;
    int logicalIndex = 0;
    bool first = true;
    while (p != e)
    {
        if (startOfLogicalLine)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                ++logicalPos.line;
            }
            logicalPos.col = 1;
        }
        if (startOfPhysicalLine || startOfLogicalLine)
        {
            mapping->Map(logicalPos, physicalLineNumber);
        }
        if (startOfPhysicalLine)
        {
            physicalLineStartIndeces.push_back(physicalIndex);
            ++physicalLineNumber;
            startOfPhysicalLine = false;
        }
        if (startOfLogicalLine)
        {
            logicalLineStartIndeces.push_back(logicalIndex);
            startOfLogicalLine = false;
        }
        switch (state)
        {
            case 0:
            {
                switch (*p)
                {
                    case '\r':
                    {
                        ++physicalIndex;
                        break;
                    }
                    case '\n':
                    {
                        startOfPhysicalLine = true;
                        startOfLogicalLine = true;
                        resultStr.append(1, '\n');
                        ++physicalIndex;
                        ++logicalIndex;
                        break;
                    }
                    case '\\':
                    {
                        ++physicalIndex;
                        state = 1;
                        break;
                    }
                    default:
                    {
                        ++logicalPos.col;
                        resultStr.append(1, *p);
                        ++physicalIndex;
                        ++logicalIndex;
                        break;
                    }
                }
                break;
            }
            case 1:
            {
                switch (*p)
                {
                    case '\r':
                    {
                        ++physicalIndex;
                        break;
                    }
                    case '\n':
                    {
                        ++physicalIndex;
                        startOfPhysicalLine = true;
                        state = 0;
                        break;
                    }
                    case '\\':
                    {
                        ++logicalPos.col;
                        resultStr.append(1, '\\');
                        ++physicalIndex;
                        ++logicalIndex;
                        break;
                    }
                    default:
                    {
                        resultStr.append(1, '\\');
                        ++physicalIndex;
                        ++logicalIndex;
                        ++logicalPos.col;
                        resultStr.append(1, *p);
                        ++physicalIndex;
                        ++logicalIndex;
                        ++logicalPos.col;
                        state = 0;
                        break;
                    }
                }
                break;
            }
        }
        ++p;
    }
    if (startOfLogicalLine)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            ++logicalPos.line;
        }
        logicalPos.col = 1;
    }
    if (startOfPhysicalLine || startOfLogicalLine)
    {
        mapping->Map(logicalPos, physicalLineNumber);
    }
    if (resultStr.back() != '\n')
    {
        resultStr.append(1, '\n');
    }
    int physicalStrLength = fileContent.end - fileContent.begin;
    int np = physicalLineStartIndeces.size();
    for (int i = 0; i < np; ++i)
    {
        int lineStartIndex = physicalLineStartIndeces[i];
        int lineEndIndex = physicalStrLength;
        if (i != np - 1)
        {
            lineEndIndex = physicalLineStartIndeces[i + 1];
        }
        Lexeme line = Lexeme(fileContent.begin + lineStartIndex, fileContent.begin + lineEndIndex);
        physicalLines.Add(line);
    }
    physicalLines.SetEnd(fileContent.end);
    int resultStrLength = resultStr.length();
    Lexeme resultLexeme = pp->StringsRef().Install(std::move(resultStr));
    int nl = logicalLineStartIndeces.size();
    for (int i = 0; i < nl; ++i)
    {
        int lineStartIndex = logicalLineStartIndeces[i];
        int lineEndIndex = resultStrLength;
        if (i < nl - 1)
        {
            lineEndIndex = logicalLineStartIndeces[i + 1];
        }
        Lexeme line = Lexeme(resultLexeme.begin + lineStartIndex, resultLexeme.begin + lineEndIndex);
        logicalLines.Add(line);
    }
    logicalLines.SetEnd(resultLexeme.end);
    mapping->SetLogicalLines(std::move(logicalLines));
    mapping->SetPhysicalLines(std::move(physicalLines));
    return mapping;
}

} // namespace sngcpp::pp

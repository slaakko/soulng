// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_EXCEPTION_INCLUDED
#define SNGCPP_SYMBOLS_EXCEPTION_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <soulng/lexer/SourcePos.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

using namespace soulng::lexer;

class SYMBOLS_API ErrorContext
{
public:
    ErrorContext(Context* context_, const SourcePos& sourcePos_);
    const std::string& FileName() const { return fileName; }
    const SourcePos& GetSourcePos() const { return sourcePos; }
    const std::string& GetErrorLines() const { return errorLines; }
private:
    std::string fileName;
    SourcePos sourcePos;
    std::string errorLines;
};

class SYMBOLS_API Exception : public std::runtime_error
{
public:
    Exception(const std::string& message_, const SourcePos& sourcePos_, Context* context_);
    const std::string& Message() const { return message; }
    const ErrorContext& GetErrorContext() const { return errorContext; }
private:
    std::string message;
    ErrorContext errorContext;
};

class SYMBOLS_API ErrorSymbol : public TypeSymbol
{
public:
    ErrorSymbol(int errorIndex_);
    std::string SymbolKindStr() const override { return "error symbol"; }
    int ErrorIndex() const { return errorIndex; }
private:
    int errorIndex;
};

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_EXCEPTION_INCLUDED


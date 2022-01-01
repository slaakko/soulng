// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Exception.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

ErrorContext::ErrorContext(Context* context_, const SourcePos& sourcePos_) : 
    fileName(MappedFileName(context_, sourcePos_)), sourcePos(sourcePos_), errorLines(MappedErrorLines(context_, sourcePos))
{
    sourcePos.pos = -1;
    sourcePos.line = MappedLineNumber(context_, sourcePos);
}

Exception::Exception(const std::string& message_, const SourcePos& sourcePos_, Context* context_) : 
    std::runtime_error("error: " + message_ + ": " + MappedFileLine(context_, sourcePos_) + ":\n" + MappedErrorLines(context_, sourcePos_)), 
    message(message_), errorContext(ErrorContext(context_, sourcePos_))
{
}

ErrorSymbol::ErrorSymbol(int errorIndex_) : TypeSymbol(U"error<" + ToUtf32(std::to_string(errorIndex_)) + U">", SymbolKind::errorSymbol), errorIndex(errorIndex_)
{
}

} // sngcpp::symbols

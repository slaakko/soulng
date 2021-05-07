// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Exception.hpp>

namespace sngcpp::symbols {

ErrorContext::ErrorContext(Context* context_, const SourcePos& sourcePos_) : fileName(GetFileName(context_)), sourcePos(sourcePos_), errorLines(ErrorLines(context_, sourcePos))
{
}

Exception::Exception(const std::string& message_, const SourcePos& sourcePos_, Context* context_) : 
    std::runtime_error("error: " + message_ + ": " + GetFileName(context_) + ":" + std::to_string(sourcePos_.line) + ":\n" + ErrorLines(context_, sourcePos_)), 
    message(message_), errorContext(ErrorContext(context_, sourcePos_))
{
}

} // sngcpp::symbols

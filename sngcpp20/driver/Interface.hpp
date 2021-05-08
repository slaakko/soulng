// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_DRIVER_INTERFACE_INCLUDED
#define SNGCPP_DRIVER_INTERFACE_INCLUDED
#include <sngcpp20/driver/DriverApi.hpp>
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::driver {

using namespace sngcpp::ast;

struct DRIVER_API ParseOptions
{
    ParseOptions() : fileIndex(0), log(false), throwFlag(true)
    {
    }
    ParseOptions& Defaults()
    {
        return *this;
    }
    ParseOptions& FileName(const std::string& fileName_)
    {
        fileName = fileName_;
        return *this;
    }
    ParseOptions& FileIndex(int fileIndex_)
    {
        fileIndex = fileIndex_; 
        return *this;
    }
    ParseOptions& Log(bool log_)
    {
        log = log_;
        return *this;
    }
    ParseOptions& LogFilePath(const std::string& logFilePath_)
    {
        logFilePath = logFilePath_;
        return *this;
    }
    ParseOptions& Throw(bool throw_)
    {
        throwFlag = throw_;
        return *this;
    }
    std::string fileName;
    int fileIndex;
    bool log;
    std::string logFilePath;
    bool throwFlag;
};

DRIVER_API std::unique_ptr<std::u32string> Preprocess(const std::string& sourceFileName);

struct DRIVER_API ParseResult
{
    ParseResult();
    ParseResult(std::unique_ptr<std::u32string>&& preprocessedSourceText_, std::unique_ptr<Node>&& translationUnitNode_);
    ParseResult(const std::string& error_);
    std::unique_ptr<std::u32string> preprocessedSourceText;
    std::unique_ptr<Node> translationUnitNode;
    std::string error;
};

DRIVER_API ParseResult Parse(std::unique_ptr<std::u32string>&& preprocessedSourceText, ParseOptions& options);
DRIVER_API ParseResult Parse(const std::string& sourceFileName, ParseOptions& options);
DRIVER_API void WriteSourceCode(Node* translationUnitNode, std::ostream& stream);
DRIVER_API void WriteSourceCode(Node* translationUnitNode, const std::string& fileName);
DRIVER_API void WriteXml(Node* translationUnitNode, std::ostream& stream);
DRIVER_API void WriteXml(Node* translationUnitNode, const std::string& fileName);
DRIVER_API void WriteBinary(Node* translationUnitNode, const std::string& fileName);
DRIVER_API std::unique_ptr<Node> ReadBinary(const std::string& fileName);

} // sngcpp::driver

#endif // SNGCPP_DRIVER_INTERFACE_INCLUDED

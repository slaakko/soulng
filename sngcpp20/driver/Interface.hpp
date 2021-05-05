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
    ParseOptions() : fileIndex(0), log(false)
    {
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
    std::string fileName;
    int fileIndex;
    bool log;
    std::string logFilePath;
};

DRIVER_API std::u32string Preprocess(const std::string& sourceFileName);
DRIVER_API std::unique_ptr<Node> Parse(const std::u32string& sourceFileContent, ParseOptions& options);
DRIVER_API std::unique_ptr<Node> Parse(const std::string& sourceFileName, ParseOptions& options);

} // sngcpp::driver

#endif // SNGCPP_DRIVER_INTERFACE_INCLUDED

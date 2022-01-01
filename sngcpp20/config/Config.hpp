// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_CONFIG_CONFIG_INCLUDED
#define SNGCPP_CONFIG_CONFIG_INCLUDED
#include <sngcpp20/config/ConfigApi.hpp>
#include <map>
#include <string>
#include <vector>

namespace sngcpp::config {

CONFIG_API std::string SoulngConfigDir();

struct CONFIG_API Config
{
    Config();
    Config(const std::string& name_, const std::string& file_);
    std::string name;
    std::string file;
};

class CONFIG_API Configuration
{
public:
    Configuration(const std::string& configName);
    const std::map<std::u32string, std::u32string>& Defines() const { return defines; }
    const std::vector<std::string>& Includes() const { return includes; }
    const std::string& Name() const { return name; }
private:
    void ReadConfigFile(const std::string& filePath);
    void ReadDefines(const std::string& filePath);
    std::map<std::string, Config> configMap;
    std::map<std::u32string, std::u32string> defines;
    std::vector<std::string> includes;
    std::string name;
};

CONFIG_API void MakeConfig(const std::string& configName, bool verbose);

} // namespace sngcpp::config

#endif // SNGCPP_CONFIG_CONFIG_INCLUDED

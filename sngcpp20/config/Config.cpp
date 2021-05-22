// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/config/Config.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Element.hpp>
#include <sngxml/dom/Parser.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <boost/filesystem.hpp>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

namespace sngcpp::config {

using namespace soulng::util;
using namespace soulng::unicode;

Config::Config()
{
}

Config::Config(const std::string& name_, const std::string& file_) : name(name_), file(file_)
{
}

std::string SoulngConfigDir()
{
    const char* soulngRootEnv = getenv("SOULNG_ROOT");
    std::string soulngRootDir = soulngRootEnv;
    if (!soulngRootEnv || !*soulngRootEnv || soulngRootDir.empty())
    {
        throw std::runtime_error("please set 'SOULNG_ROOT' environment variable to contain /path/to/soulng directory");
    }
    std::string configDir = GetFullPath(Path::Combine(soulngRootDir, "config"));
    boost::filesystem::create_directories(configDir);
    return configDir;
}

Configuration::Configuration(const std::string& configName)
{
    std::string configDir = SoulngConfigDir();
    std::string sngcppConfigXmlFilePath = Path::Combine(configDir, "sngcpp.config.xml");
    if (boost::filesystem::exists(sngcppConfigXmlFilePath))
    {
        std::unique_ptr<sngxml::dom::Document> doc = sngxml::dom::ReadDocument(sngcppConfigXmlFilePath);
        std::unique_ptr<sngxml::xpath::XPathObject> configurationObject = sngxml::xpath::Evaluate(U"/configurations/configuration", doc.get());
        if (configurationObject)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(configurationObject.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string nameAttribute = element->GetAttribute(U"name");
                    if (nameAttribute.empty())
                    {
                        throw std::runtime_error("'configuration' element has no 'name' attribute in '" + sngcppConfigXmlFilePath + "'");
                    }
                    std::u32string fileAttribute = element->GetAttribute(U"file");
                    if (fileAttribute.empty())
                    {
                        throw std::runtime_error("'configuration' element has no 'file' attribute in '" + sngcppConfigXmlFilePath + "'");
                    }
                    Config config(ToUtf8(nameAttribute), ToUtf8(fileAttribute));
                    configMap[config.name] = config;
                }
            }
        }
        std::string defaultConfigName = configName;
        if (defaultConfigName.empty())
        {
            defaultConfigName = "vc";
            std::unique_ptr<sngxml::xpath::XPathObject> defaultObject = sngxml::xpath::Evaluate(U"/configurations/default", doc.get());
            if (defaultObject)
            {
                if (defaultObject->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                {
                    sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(defaultObject.get());
                    int n = nodeSet->Length();
                    if (n == 1)
                    {
                        for (int i = 0; i < n; ++i)
                        {
                            sngxml::dom::Node* node = (*nodeSet)[i];
                            if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                            {
                                sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                                std::u32string configurationAttribute = element->GetAttribute(U"configuration");
                                if (configurationAttribute.empty())
                                {
                                    throw std::runtime_error("'default' element has no 'configuration' attribute in '" + sngcppConfigXmlFilePath + "'");
                                }
                                else
                                {
                                    defaultConfigName = ToUtf8(configurationAttribute);
                                }
                            }
                        }
                    }
                    else
                    {
                        throw std::runtime_error("one 'default' element expected in '" + sngcppConfigXmlFilePath + "'");
                    }
                }
                else
                {
                    throw std::runtime_error("node set expected in '" + sngcppConfigXmlFilePath + "'");
                }
            }
        }
        Config& config = configMap[defaultConfigName];
        if (config.name.empty() || config.file.empty())
        {
            throw std::runtime_error("configuration '" + defaultConfigName + "' not found");
        }
        std::string configFilePath = Path::Combine(Path::GetDirectoryName(sngcppConfigXmlFilePath), config.file);
        ReadConfigFile(configFilePath);
    }
    else
    {
        throw std::runtime_error("'sngcpp.config.xml' not found from '" + configDir + "'");
    }
}

void Configuration::ReadConfigFile(const std::string& filePath)
{
    std::unique_ptr<sngxml::dom::Document> configDoc = sngxml::dom::ReadDocument(filePath);
    std::unique_ptr<sngxml::xpath::XPathObject> configurationObject = sngxml::xpath::Evaluate(U"/configuration", configDoc.get());
    if (configurationObject)
    {
        if (configurationObject->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(configurationObject.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string nameAttribute = element->GetAttribute(U"name");
                    if (!nameAttribute.empty())
                    {
                        name = ToUtf8(nameAttribute);
                    }
                }
            }
        }
    }
    std::unique_ptr<sngxml::xpath::XPathObject> defineObject = sngxml::xpath::Evaluate(U"/configuration/defines/define", configDoc.get());
    if (defineObject)
    {
        if (defineObject->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(defineObject.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string fileAttribute = element->GetAttribute(U"file");
                    if (fileAttribute.empty())
                    {
                        throw std::runtime_error("'define' element has no 'file' attribute in '" + filePath + "'");
                    }
                    std::string defineFilePath = Path::Combine(Path::GetDirectoryName(filePath), ToUtf8(fileAttribute));
                    ReadDefines(defineFilePath);
                }
            }
        }
        else
        {
            throw std::runtime_error("node set expected in '" + filePath + "'");
        }
    }
    std::unique_ptr<sngxml::xpath::XPathObject> includeObject = sngxml::xpath::Evaluate(U"/configuration/includes/include", configDoc.get());
    if (includeObject)
    {
        if (includeObject->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(includeObject.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string includePathAttribute = element->GetAttribute(U"path");
                    if (!includePathAttribute.empty())
                    {
                        std::string includePath = GetFullPath(ToUtf8(includePathAttribute));
                        if (!boost::filesystem::exists(includePath))
                        {
                            std::cerr << "warning: include path '" + includePath + "' does not exist, see '" + filePath + "'" << std::endl;
                        }
                        includes.push_back(includePath);
                    }
                    else
                    {
                        throw std::runtime_error("'include' element has no 'path' attribute in '" + filePath + "'");
                    }
                }
            }
        }
        else
        {
            throw std::runtime_error("node set expected in '" + filePath + "'");
        }
    }
}

void Configuration::ReadDefines(const std::string& filePath)
{
    std::unique_ptr<sngxml::dom::Document> defineDoc = sngxml::dom::ReadDocument(filePath);
    std::unique_ptr<sngxml::xpath::XPathObject> defineObject = sngxml::xpath::Evaluate(U"/defines/define", defineDoc.get());
    if (defineObject)
    {
        if (defineObject->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(defineObject.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string name = element->GetAttribute(U"name");
                    if (!name.empty())
                    {
                        std::u32string value = element->GetAttribute(U"value");
                        if (!value.empty())
                        {
                            defines[name] = value;
                        }
                        else
                        {
                            throw std::runtime_error("'define' element has no 'value' attribute in '" + filePath + "'");
                        }
                    }
                    else
                    {
                        throw std::runtime_error("'define' element has no 'name' attribute in '" + filePath + "'");
                    }
                }
            }
        }
        else
        {
            throw std::runtime_error("node set expected in '" + filePath + "'");
        }
    }
}

} // namespace sngcpp::config

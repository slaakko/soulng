#include <Config/Config.hpp>
#include <Config/Configuration.hpp>
#include <Config/Ids.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Parser.hpp>
#include <soulng/util/Path.hpp>
#include <boost/filesystem.hpp>
#include <fstream>

namespace config {

using namespace soulng::util;

const int defaultServerPortNumber = 55000;

Configuration* LoadConfiguration(const std::string& configFilePath)
{
    std::unique_ptr<Configuration> configuration(new Configuration());
    std::unique_ptr<sngxml::dom::Document> configurationDoc = sngxml::dom::ReadDocument(configFilePath);
    configuration->FromXml(configurationDoc->DocumentElement());
    return configuration.release();
}

void SaveConfiguration(Configuration* configuration, const std::string& configFilePath)
{
    sngxml::dom::Document configurationDoc;
    configurationDoc.AppendChild(std::unique_ptr<sngxml::dom::Node>(configuration->ToXml("configuration")));
    std::ofstream configFile(configFilePath);
    CodeFormatter formatter(configFile);
    formatter.SetIndentSize(1);
    configurationDoc.Write(formatter);
}

Configuration* MakeConfiguration()
{
    Configuration* configuration = new Configuration();
    configuration->serverPortNumber = defaultServerPortNumber;
    return configuration;
}

Ids* LoadIds(const std::string& idsFilePath)
{
    std::unique_ptr<Ids> ids(new Ids());
    std::unique_ptr<sngxml::dom::Document> idsDoc = sngxml::dom::ReadDocument(idsFilePath);
    ids->FromXml(idsDoc->DocumentElement());
    return ids.release();
}
        
void SaveIds(Ids* ids, const std::string& idsFilePath)
{
    sngxml::dom::Document idsDoc;
    idsDoc.AppendChild(std::unique_ptr<sngxml::dom::Node>(ids->ToXml("ids")));
    std::ofstream idsFile(idsFilePath);
    CodeFormatter formatter(idsFile);
    formatter.SetIndentSize(1);
    idsDoc.Write(formatter);
}

Ids* MakeIds()
{
    Ids* ids = new Ids();
    return ids;
}

std::string SoulngRoot()
{
    std::string soulngRoot;
    char* soulngRootEnv = std::getenv("SOULNG_ROOT");
    if (soulngRootEnv && *soulngRootEnv)
    {
        soulngRoot = GetFullPath(soulngRootEnv);
    }
    else
    {
        throw std::runtime_error("SOULNG_ROOT environment variable not found, please set it to contain /path/to/soulng directory");
    }
    return soulngRoot;
}

std::string LibraryRoot()
{
    std::string soulngRoot = SoulngRoot();
    return Path::Combine(Path::Combine(Path::Combine(soulngRoot, "sngxml"), "example"), "library");
}

std::string ConfigFilePath()
{
    return Path::Combine(Path::Combine(LibraryRoot(), "Data"), "Library.config.xml");
}

std::string IdsFilePath()
{
    return Path::Combine(Path::Combine(LibraryRoot(), "Data"), "ids.xml");
}

class Config
{
public:
    static void Init();
    static void Done();
    static Config& Instance() { return *instance; }
    Configuration* GetConfiguration() const { return configuration.get(); }
    Ids* GetIds() const { return ids.get(); }
private:
    Config();
    static std::unique_ptr<Config> instance;
    std::unique_ptr<Configuration> configuration; 
    std::unique_ptr<Ids> ids;
};

std::unique_ptr<Config> Config::instance;

void Config::Init()
{
    instance.reset(new Config());
}

void Config::Done()
{
    instance.reset();
}

Config::Config()
{
    std::string configFilePath = ConfigFilePath();
    if (!boost::filesystem::exists(configFilePath))
    {
        configuration.reset(MakeConfiguration());
        SaveConfiguration(configuration.get(), configFilePath);
    }
    configuration.reset(LoadConfiguration(configFilePath));
    std::string idsFilePath = IdsFilePath();
    if (!boost::filesystem::exists(idsFilePath))
    {
        ids.reset(MakeIds());
        SaveIds(ids.get(), idsFilePath);
    }
    ids.reset(LoadIds(idsFilePath));
}

int GetServerPortNumber()
{
    return Config::Instance().GetConfiguration()->serverPortNumber;
}

void ClearLibraries()
{
    Configuration* configuration = Config::Instance().GetConfiguration();
    configuration->libraries.clear();
}

std::vector<std::string> GetLibraries()
{
    Configuration* configuration = Config::Instance().GetConfiguration();
    return configuration->libraries;
}

void AddLibrary(const std::string& library)
{
    Configuration* configuration = Config::Instance().GetConfiguration();
    configuration->libraries.push_back(library);
}

void SaveIds()
{
    SaveIds(Config::Instance().GetIds(), IdsFilePath());
}

boost::uuids::uuid GetId(int index)
{
    return Config::Instance().GetIds()->Get(index);
}

std::string DataDirectoryPath()
{
    return Path::Combine(LibraryRoot(), "Data");
}

std::string GetLibraryFilePath(const std::string& libraryName)
{
    return Path::Combine(DataDirectoryPath(), libraryName + ".bundle.xml");
}

std::string BinDirectoryPath()
{
    return Path::Combine(SoulngRoot(), "bin");
}

void SaveConfiguration()
{
    SaveConfiguration(Config::Instance().GetConfiguration(), ConfigFilePath());
}

void InitConfig()
{
    Config::Init();
}

void DoneConfig()
{
    Config::Done();
}

} // config

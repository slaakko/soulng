#ifndef CONFIG_CONFIG_INCLUDED
#define CONFIG_CONFIG_INCLUDED
#include <Config/Api.hpp>
#include <string>
#include <vector>
#include <boost/uuid/uuid.hpp>

namespace config {

CONFIG_API int GetServerPortNumber();
CONFIG_API void ClearLibraries();
CONFIG_API std::vector<std::string> GetLibraries();
CONFIG_API void AddLibrary(const std::string& library);
CONFIG_API std::string DataDirectoryPath();
CONFIG_API std::string GetLibraryFilePath(const std::string& libraryName);
CONFIG_API std::string BinDirectoryPath();
CONFIG_API boost::uuids::uuid GetId(int index);
CONFIG_API void SaveIds();
CONFIG_API void SaveConfiguration();

CONFIG_API void InitConfig();
CONFIG_API void DoneConfig();

} // config

#endif // CONFIG_CONFIG_INCLUDED

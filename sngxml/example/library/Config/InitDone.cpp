#include <Config/InitDone.hpp>
#include <Config/Config.hpp>

namespace config
{
    void Init()
    {
        InitConfig();
    }

    void Done()
    {
        DoneConfig();
    }
}
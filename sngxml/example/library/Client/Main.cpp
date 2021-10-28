#include <LibraryXml/Register.hpp>
#include <MessageXml/Register.hpp>
#include <Query/Register.hpp>
#include <Config/Config.hpp>
#include <Config/InitDone.hpp>
#include <Client/Client.hpp>
#include <sngxml/serialization/InitDone.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Unicode.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

void Init()
{
    soulng::util::Init();
    sngxml::xpath::Init();
    sngxml::xmlser::Init();
    config::Init();
}

int main(int argc, const char** argv)
{
    try
    {
        Init();
        library_xml::Register();
        message_xml::Register();
        query::Register();
        int port = config::GetServerPortNumber();
        bool prevWasPort = false;
        bool verbose = false;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (arg.starts_with("--"))
            {
                if (arg == "--port")
                {
                    prevWasPort = true;
                }
                else if (arg == "--verbose")
                {
                    verbose = true;
                }
                else
                {
                    throw std::runtime_error("unknown option '" + arg + "'");
                }
            }
            else if (arg.starts_with("-"))
            {
                std::string options(arg.substr(1));
                for (char o : options)
                {
                    switch (o)
                    {
                        case 'p': prevWasPort = true; break;
                        case 'v': verbose = true; break;
                        default:
                        {
                            throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                        }
                    }
                }
            }
            else
            {
                if (prevWasPort)
                {
                    port = boost::lexical_cast<int>(arg);
                    prevWasPort = false;
                }
            }
        }
        client::RunClient(port, verbose);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

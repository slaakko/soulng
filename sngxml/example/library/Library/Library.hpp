#ifndef LIBRARY_LIBRARY_INCLUDED
#define LIBRARY_LIBRARY_INCLUDED
#include <LibraryXml/Library.hpp>
#include <sngxml/serialization/XmlBundle.hpp>
#include <soulng/util/Socket.hpp>
#include <thread>
#include <memory>

namespace library {

class LibraryThread;

using soulng::util::TcpSocket;

class Library
{
public:
    static void Init();
    static void Done();
    static Library& Instance() { return *instance; }
    void Run(int port);
    void Exit();
    void SetName(const std::string& name_);
    const std::string& Name() const { return name; }
    void AddBundle(std::unique_ptr<sngxml::xmlser::XmlBundle>&& bundle);
    void SetLibraryXml(library_xml::Library* library_);
    library_xml::Library* GetLibraryXml() const { return library; }
private:
    Library();
    static std::unique_ptr<Library> instance;
    TcpSocket socket;
    bool exiting;
    std::vector<std::unique_ptr<LibraryThread>> libraryThreads;
    std::vector<std::thread> threads;
    std::vector<std::unique_ptr<sngxml::xmlser::XmlBundle>> bundles;
    int port;
    std::string name;
    library_xml::Library* library;
};

void RunLibrary(int port);
void InitLibrary();
void DoneLibrary();

} // library

#endif // LIBRARY_LIBRARY_INCLUDED

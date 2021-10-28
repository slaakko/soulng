#include <Library/Library.hpp>
#include <Library/LibraryThread.hpp>

namespace library {

using namespace soulng::util;

std::unique_ptr<Library> Library::instance;

void Library::Init()
{
    instance.reset(new Library());
}

void Library::Done()
{
    instance.reset();
}

Library::Library() : exiting(false), port(-1), library(nullptr)
{
}

void Library::SetName(const std::string& name_)
{
    name = name_;
}

void Library::AddBundle(std::unique_ptr<sngxml::xmlser::XmlBundle>&& bundle)
{
    bundles.push_back(std::move(bundle));
}

void Library::SetLibraryXml(library_xml::Library* library_)
{
    library = library_;
}

void Library::Run(int port)
{
    this->port = port;
    socket.Bind(port);
    socket.Listen(10);
    while (!exiting)
    {
        TcpSocket client = socket.Accept();
        if (!exiting)
        {
            std::unique_ptr<LibraryThread> libraryThreadPtr(new LibraryThread(this, std::move(client)));
            LibraryThread* libraryThread = libraryThreadPtr.get();
            libraryThreads.push_back(std::move(libraryThreadPtr));
            threads.push_back(std::move(StartLibraryThread(libraryThread)));
        }
    }
    for (std::thread& thread : threads)
    {
        thread.join();
    }
}

void Library::Exit()
{
    exiting = true;
    TcpSocket client("127.0.0.1", std::to_string(port));
}

void RunLibrary(int port)
{
    Library::Instance().Run(port);
}

void InitLibrary()
{
    Library::Init();
}

void DoneLibrary()
{
    Library::Done();
}

} // library

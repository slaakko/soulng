#include <iostream>
#include <example/sort.hpp>

int main(int argc, const char** argv)
{
    std::vector<std::string> args;
    int n = argc;
    for (int i = 1; i < n; ++i)
    {
        std::cout << "arg " << i << " " << argv[i] << std::endl;
        args.push_back(argv[i]);
    }
    example_ns::sort(args);
    std::cout << "sorted:" << std::endl;
    for (int i = 0; i < args.size(); ++i)
    {
        std::cout << args[i] << std::endl;
    }
    return 0;
}

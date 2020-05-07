#include <example/sort.hpp>
#include <algorithm>

namespace example_ns
{
    void sort(std::vector<std::string>& v)
    {
        std::sort(v.begin(), v.end());
    }
}

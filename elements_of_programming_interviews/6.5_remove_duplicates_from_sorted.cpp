
#include <pretty_output/include/print.hpp>

#include <vector>
#include <iostream>

auto remove_duplicates(std::vector<int> v)
{
    v.erase(std::unique(v.begin(), v.end())
           ,v.end());
    return v;
}

int main()
{
    auto const v = std::vector<int>{1,1,2,2,3,4,4,5};
    println(std::cout, remove_duplicates(v));
    return 0;
}

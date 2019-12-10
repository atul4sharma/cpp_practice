
#include <pretty_output/include/print.hpp>

#include <vector>
#include <iostream>

int main()
{
    auto const v = std::vector<int>{1,2,3,4,5};
    println(std::cout, v);
    return 0;
}

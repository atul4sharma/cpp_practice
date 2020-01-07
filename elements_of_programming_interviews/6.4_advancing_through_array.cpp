
#include <pretty_output/include/print.hpp>

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>



auto is_possible(std::vector<int> const & v)
    -> bool
{
    auto const last_index     = static_cast<int>(v.size()) - 1;
    auto       farther_so_far = 0;
    for(auto i = 0;
        i <= farther_so_far && farther_so_far < last_index;
        ++i)
    {
        farther_so_far = std::max(farther_so_far, i + v[i] );
    }

    return farther_so_far >= last_index;
}

int main()
{
    {
        auto const v = std::vector<int>{1,2,3,4,5};
        println(print(std::cout << "vector -> ", v) << " -> ", is_possible(v) ? "true" : "false");
    }
    {
        auto const v = std::vector<int>{2,4,1,1,0,2,3};
        println(print(std::cout << "vector -> ", v) << " -> ", is_possible(v) ? "true" : "false");
    }
    {
        auto const v = std::vector<int>{3,3,1,0,2,0,1};
        println(print(std::cout << "vector -> ", v) << " -> ", is_possible(v) ? "true" : "false");
    }
    {
        auto const v = std::vector<int>{3,2,0,0,2,0,1};
        println(print(std::cout << "vector -> ", v) << " -> ", is_possible(v) ? "true" : "false");
    }
    return 0;
}

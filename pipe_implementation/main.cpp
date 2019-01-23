
#include "pipe.hpp"

#include <iostream>
#include <algorithm>
#include <vector>

int func(int, int)
{
    return int{};
}

int main()
{
    auto v = std::vector<int>{23,123,1,4123,12,44235,34,46,4564};
    auto const pipe_var = pipe_t<int>{func, [] () {}};
    pipe_var.print_all_types();
    return 0; 
}


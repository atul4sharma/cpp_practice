
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>

#include "pretty_output/print.hpp"


int main()
{
    //auto const v = std::vector<int>{1, 2, 3, 4, 5, 6};
    auto const v = std::vector<std::pair<int, int>> {
         {1, 1}
        ,{2, 2}
        ,{3, 3}
    };
    println(std::cout, v);

    auto const m = std::map<int, int>{{1,1}, {2,4}, {3,9}, {4,16}};
    //println(std::cout, m);
    //std::copy(begin(m), end(m), std::ostream_iterator<decltype(*(begin(m)))>(std::cout, ", "));

    auto const p = std::pair<int const, int>(1,2);
    // std::cout << p << "\n";
    println(std::cout, p);
    return 0;
}


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
    auto const v = std::vector<std::vector<int>>{
                                                  {1,2,3,4}
                                                 ,{5,6,7,8}
                                                 ,{9,10,11,12}
                                                };
    println(std::cout, v);

    auto const m = std::map<int, int> {
                                        {1, 1}
                                       ,{2, 4}
                                       ,{3, 9}
                                       ,{4, 16}
                                      };
    println(std::cout, m);

    return 0;
}

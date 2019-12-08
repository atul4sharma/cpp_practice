
#include <pretty_output/include/print.hpp>

#include <ctime>
#include <array>
#include <random>
#include <numeric>
#include <iostream>
#include <algorithm>

auto plus_one(std::vector<int> & v)
{
    if( v.empty() )
        return 1;

    int carry = 0;
    for(auto counter = v.size() - 1; counter >= 0; --counter)
    {
        if( ++(v[counter]) == 10 ) 
        {
            v[counter] = 0;
            carry = 1;
        }
        else
        {
            return 0;
        }
    }
    return carry;
}

int main()
{
    auto v = std::vector<int>{99};
    std::cout << "Original number -> ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ""));
    std::cout << "\n";
    auto carry = plus_one(v);
    if( carry )
        v.insert(v.begin(), carry);
    std::cout << "Modified number -> ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ""));
    std::cout << "\n";
    std::cout << std::endl;

}

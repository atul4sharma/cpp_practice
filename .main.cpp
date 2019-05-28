
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>

template <typename T>
auto operator << (std::ostream & out, std::vector<T> const & v)
    -> std::ostream &
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, ", "));
    return out;
}


int main()
{
    // auto v = std::vector<int>{};
    return 0;
}

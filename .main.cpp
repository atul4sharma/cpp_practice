
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>

template <typename T, typename U>
auto operator << (std::ostream & out, std::pair<T, U> const & item)
    -> std::ostream &
{
    out << "(" << item.first << ", " << item.second << ")";
    return out;
}

template <typename T, typename U>
auto operator << (std::ostream & out, std::map<T, U> const & v)
    -> std::ostream &
{
    std::cout << "{";
    for(auto const & item : v)
        std::cout << item << ", ";
    std::cout << "}";
    return out;
}

template <typename T>
auto operator << (std::ostream & out, std::vector<T> const & v)
    -> std::ostream &
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    return out;
}


int main()
{
    // auto v = std::vector<int>{};
    return 0;
}

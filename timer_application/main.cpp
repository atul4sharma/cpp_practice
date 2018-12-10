#include <algorithm>
#include <chrono>
#include <vector>
#include <iostream>

struct timer
{
    ~timer()
    {
        auto t_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::fixed << "Wall clock time passed: "
                                << std::chrono::duration<double, std::milli>(t_end_time - _t_start_time).count()
                                << " ms\n";
    }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> _t_start_time{std::chrono::high_resolution_clock::now()};
};

template <typename FwdIterator>
auto minmaxelement(FwdIterator first, FwdIterator last)
    -> std::pair<FwdIterator, FwdIterator>
{
    if( first == last )
        return std::make_pair(last, last);

    auto result = std::make_pair(first, first);
    
    while( ++first != last )
    {
        if( *(first) < *(result.first) )
        {
            result.first = first;
        }
        else 
        {
            if( *(result.second) < *(first) )
            {
                result.second = first;
            }
            else if( not(*(first) < *(result.second)) )
            {
                result.second = first;
            }
        }
    }
    return result;
}

int main()
{
    std::vector<std::size_t> v(100000000);
    std::iota(v.begin(), v.end(), 0);
    std::random_shuffle(v.begin(), v.end());
    std::vector<std::size_t> v2{v};
    {
        auto t = timer{};
        auto val = std::minmax_element(v2.begin(), v2.end());
        std::cout << "std::min -> " << *(val.first) << " std::max -> " << *(val.second) << " :: ";
    }
    {
        auto t = timer{};
        auto val = minmaxelement(v.begin(), v.end());
        std::cout << "___::min -> " << *(val.first) << " ___::max -> " << *(val.second) << " :: ";
    }
    return 0;
}


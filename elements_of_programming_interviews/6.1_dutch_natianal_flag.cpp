
#include <pretty_output/include/print.hpp>

#include <ctime>
#include <vector>
#include <random>
#include <numeric>
#include <iostream>
#include <algorithm>

enum class color { red, white, blue };

auto to_string(color const item)
    -> std::string
{
    switch(item)
    {
        case color::red   : return "RED";
        case color::white : return "WHITE";
        case color::blue  : return "BLUE";
    }
    return std::string{};
}

inline auto random_vector()
{
    auto v = std::vector<color>{};
    std::srand(std::time(0));
    auto random_index = std::rand() % static_cast<int>(10) + 1;
    v.insert(v.begin(), random_index, color::red);
    random_index = std::rand() % static_cast<int>(5) + 1;
    v.insert(v.begin(), random_index, color::white);
    random_index = std::rand() % static_cast<int>(5) + 1;
    v.insert(v.begin(), random_index, color::blue);

    std::random_shuffle(v.begin(), v.end());
    return v;
}

template <typename Iterator>
auto partition_color(Iterator first, Iterator last)
{
    std::partition(std::partition(first
                                 ,last
                                 ,[](auto const item) { return item < color::white;})
                  ,last
                  ,[](auto const item) { return item == color::white;});
}

int main()
{
    auto v = random_vector();

    println(std::cout << "Before parition => ", v);
    partition_color(v.begin(), v.end());
    println(std::cout << "After parition  => ", v);

}


#include <pretty_output/include/print.hpp>

#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>

inline auto random_vector(int const limit)
{
    auto v = std::vector<int>(limit);
    std::iota(v.begin(), v.end(), 1);
    std::srand(std::time(0));
    auto random_index = std::rand() % static_cast<int>(v.size() - 1);
    v.insert(v.end(), 4, *(v.begin() + random_index));
    random_index = std::rand() % static_cast<int>(v.size() - 2);
    v.insert(v.end(), 2, *(v.begin() + random_index));

    std::random_shuffle(v.begin(), v.end());
    return v;
}

auto countsort(std::vector<int> const & numbers)
{
    auto const max_element = std::max_element(numbers.begin(), numbers.end());
    auto       counter     = std::vector<unsigned int>(*max_element + 1, 0);

    std::for_each(numbers.cbegin()
                 ,numbers.cend()
                 ,[&counter] (int const num) {
                    counter[num] += 1;
                 });
    //println(std::cout << "counter vector => ", counter);

    for( auto i = 1; i < static_cast<int>(counter.size()); ++i )
        counter[i] += counter[i-1];

    //println(std::cout << "aggregated vector => ", counter);

    auto sorted_numbers = std::vector<int>(numbers.size(), 0);
    for(auto i = static_cast<int>(numbers.size()) - 1; i >= 0; --i)
    {
        sorted_numbers[ counter[ numbers[i] ] - 1 ] = numbers[i];
        counter[ numbers[i] ] -= 1;
    }
    return sorted_numbers;
}

int main()
{
    auto v = random_vector(20);
    //auto v = std::vector<int>(10);
    println(std::cout << "Random vector => ", v);
    auto res = countsort(v);
    println(std::cout << "Sorted vector => ", res);

}

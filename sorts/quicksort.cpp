
#include <pretty_output/include/print.hpp>

#include <ctime>
#include <vector>
#include <random>
#include <numeric>
#include <iostream>
#include <algorithm>

inline auto random_vector()
{
    auto v = std::vector<int>(10);
    std::iota(v.begin(), v.end(), 1);
    std::srand(std::time(0));
    auto random_index = std::rand() % static_cast<int>(v.size() - 1);
    v.insert(v.end(), 4, *(v.begin() + random_index));
    random_index = std::rand() % static_cast<int>(v.size() - 2);
    v.insert(v.end(), 2, *(v.begin() + random_index));

    std::random_shuffle(v.begin(), v.end());
    return v;
}

template <typename Iterator>
auto quicksort(Iterator first, Iterator last)
{
    if( first == last or std::next(first) == last )
        return;

    auto const pivot = *first;
    auto partition_point = std::partition(std::next(first), last, [&pivot](auto const & item) { return item < pivot;});
    std::iter_swap(first, std::prev(partition_point));
    quicksort(first, std::prev(partition_point));
    quicksort(partition_point, last);
}

int main()
{
    auto v = random_vector();

    println(std::cout << "Before sort => ", v);
    quicksort(v.begin(), v.end());
    println(std::cout << "After sort  => ", v);

}

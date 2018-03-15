
#include <boost/type_index.hpp>

#include <iostream>
#include <vector>
#include <array>

template<typename T>
auto printFunction(T&& sequence)
    -> void
{
    std::cout << boost::typeindex::type_id_with_cvr<decltype(sequence)>().pretty_name() << "\n";
    for(auto x : sequence)
    {
        std::cout << x << ", ";
    }
    std::cout << "\ntype of iterator returned by begin() : " 
              << boost::typeindex::type_id_with_cvr<decltype(sequence.begin())>().pretty_name() << "\n";
    std::cout << "\n\n";

}

int main()
{
    std::array<double, 5> num_array{1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double>   num_vector{1.0, 2.0, 3.0, 4.0, 5.0};

    printFunction(num_array);
    printFunction(num_vector);

    return 0;
}

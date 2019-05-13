
#include "fvector.hpp"

#include <iostream>

int main()
{
    auto v1 = fvector_int{10};

    for(std::size_t i = 0; i < 10; ++i)
        v1[i] = i + 1;

    std::cout << "Vector 1 => " << v1 << "\n";

    auto const v2 = v1;
    std::cout << "Vector 2 => " << v2 << "\n";
    std::cout << std::boolalpha << "(v1 == v2) => " << (v1 == v2) << "\n";

    auto v3 = fvector_int{};
    v3 = v2;
    std::cout << "Vector 3 => " << v3 << "\n";

    std::cout << std::boolalpha << "(v2 != v3) => " << (v2 != v3) << "\n";

    return 0;
}


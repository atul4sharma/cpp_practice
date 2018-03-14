

#include <bar.hpp>

#include <iostream>

bar foo()
{
    auto const & x = bar{};
    std::cout << "BP1\n";
    return x;
}

int main()
{
    auto const & x = foo();
    std::cout << "BP2\n";
}

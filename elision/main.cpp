

#include <bar.hpp>

#include <iostream>

Bar foo()
{
    auto const & x = Bar{};
    std::cout << "BP1\n";
    return x;
}

int main()
{
    auto const & x = foo();
    std::cout << "BP2\n";
}

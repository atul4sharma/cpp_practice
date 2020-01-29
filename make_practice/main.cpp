
#include "foo.hpp"

#include <iostream>

int main()
{
    std::cout << foo{}.statement() << "\n";

    std::cout << std::endl;
    return 0;
}

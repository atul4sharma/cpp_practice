
#include "foo.hpp"
#include "bar.hpp"

#include <iostream>

int main()
{
    std::cout << "foo: " << foo() << '\n';
    std::cout << "bar: " << bar() << '\n';

    return 0;
}

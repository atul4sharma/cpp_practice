
#include "foo.hpp"
#include "bar.hpp"

#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    std::cout << foo() << '\n';
    std::cout << bar() << '\n';

    std::cout << "Sleeping for 30 seconds\n";
    std::this_thread::sleep_for(std::chrono::seconds{30});

    return 0;
}



#include <iostream>


auto fibonacci(std::size_t const n)
    -> std::size_t
{
    if( n <= 1)
        return n;

    auto i = std::size_t{1};

    std::size_t a = 0;
    std::size_t b = 1;
    std::size_t c{};

    while(i < n)
    {
        c = a + b;
        a = b;
        b = c;
        ++i;
    }
    
    return c;
}


int main()
{
    std::cout << fibonacci(60) << "\n";
}

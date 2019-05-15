

#include <iostream>


auto fibonacci(std::size_t const n)
    -> std::size_t
{
    if( n <= 1)
        return n;

    return fibonacci(n-1) + fibonacci(n-2);
}


int main()
{
    std::cout << fibonacci(60) << "\n";
}

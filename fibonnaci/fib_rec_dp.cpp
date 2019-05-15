
#include <iostream>
#include <vector>

auto fibonacci_impl(std::vector<std::size_t> & fib, std::size_t const n)
    -> std::size_t
{
    if( n <= 1 )
        return fib.at(n);

    if( fib.at(n) != 0 )
    {
        return fib.at(n);
    }
    else
    {
        fib.at(n) = fibonacci_impl(fib, n-1) + fibonacci_impl(fib, n-2);
        return fib.at(n);
    }
}

auto fibonacci(std::size_t const n)
    -> std::size_t
{
    auto fib = std::vector<std::size_t>(n+1, 0);
    fib[1] = 1;
    return fibonacci_impl(fib, n);
}


int main()
{
    std::cout << fibonacci(40) << "\n";
}


#include <array>
#include <cmath>
#include <limits>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

#if 1
auto generate_primes()
{
    //auto constexpr max = std::numeric_limits<int>::max();
    auto constexpr max = 100000;
    auto is_prime = std::vector<bool>(max, true);
    is_prime[0] = false;
    is_prime[1] = false;

    int constexpr root = std::sqrt(max);
    for(int i = 2; i <= root; ++i) 
    {
        if( is_prime[i] )
        {
            for( int j = 2 * i; j < max ; j += i)
            {
                //std::cout << j * i << ", ";
                is_prime[j] = false;
            }
        }
    }

    auto const primes = [&is_prime] ()
    {
        auto primes_ = std::vector<int>{};
        primes_.reserve(is_prime.size()); // Just a hunch
        for(auto i = 0; i < static_cast<int>(is_prime.size()); ++i)
        {
            if( is_prime[i] )
                primes_.emplace_back(i);
        }
        return primes_;
    }();
    return primes;
}

auto is_prime(int x)
{
    auto const primes = generate_primes();
    //std::cout << "\nPrimes : ";
    //std::copy(primes.begin(), primes.end(), std::ostream_iterator<int>(std::cout, ", "));
    auto iter = std::lower_bound(primes.begin(), primes.end(), x);
    if( iter != primes.end() && *iter == x)
        return true;
    return false;
}
#endif

int main(int argc, char ** argv)
{
    int const a = std::stoi(argv[1]);

    std::cout << a << ( is_prime(a) ? " is " : " is not " ) << "prime\n";
    return 0;
}

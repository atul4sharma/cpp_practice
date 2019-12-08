
#include <iostream>

auto swap_bits(long a, int i, int j)
{
    if( (( a >> i) & 1) != ((a >> j) & 1) )
    {
        auto bitmask = (1L << i) | (1L << j);
        a ^= bitmask;
    }
    return a;
}

int main(int argc, char ** argv)
{
    if( argc > 3 )
        std::cout << swap_bits(std::stol(argv[1]), std::stoi(argv[2]), std::stoi(argv[3])) << "\n";
    else
        std::cout << "Please pass commandline argument\n";
    return 0;
}

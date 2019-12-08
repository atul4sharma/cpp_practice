
#include <iostream>
#include <string>

bool parity(unsigned long a)
{
    a ^= a >> 32;
    a ^= a >> 16;
    a ^= a >> 8;
    a ^= a >> 4;
    a ^= a >> 2;
    a ^= a >> 1;
    return a & 0x1;
}

int main(int argc, char ** argv)
{
    unsigned long a = std::stoi(argv[1]);
    std::cout << (parity(a) ? 1 : 0) << "\n";

    return 0;
}

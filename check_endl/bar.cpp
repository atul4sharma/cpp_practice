#include "bar.hpp"

#include <iostream>

int check_address(ManipFunc func)
{
    if(func == static_cast<ManipFunc>(std::endl)) {
        std::cout << "std::endl was passed\n";
    } else {
        std::cout << "std::endl was not passed\n";
    }
    return 0;
}

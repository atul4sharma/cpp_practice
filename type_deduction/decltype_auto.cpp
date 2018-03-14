#include <iostream>
#include <typeinfo>
#include <typestring.hpp>

auto func(int x, double y)
    -> std::string
{
    return "empty";
}

int main()
{
    int x = 20;
    int const y = x;
    int const & z = 25;

    // compiles with c++14
    //decltype(auto) a = z;
//    std::cout << "a : "  << type_name<decltype(a)>()    << "\n";
    std::cout << "func " << type_name<decltype(func)>() << "\n";
    return 0;
}

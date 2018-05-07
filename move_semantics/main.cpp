#include <iostream>
#include <elision/bar.hpp>

using elision::bar;

void func(bar const & obj)
{
    std::cout << "const bar : " << &obj << "\n";
}

void func(bar && obj)
{
    std::cout << "rvalue bar : " << &obj << "\n";
}

int main()
{
    bar ob1{};
    std::cout << "bp1\n";
    func(ob1);
    std::cout << "bp2\n";
    func(bar{});
    std::cout << "bp3\n";
    func(std::move(ob1));
    std::cout << "bp4\n";
    std::cout << "ob.x " << ob1.x() << "\n";
    std::cout << "end\n";
    
    return 0;
}

#include <bar.hpp>
#include <iostream>

struct foo
{
    bar _member;

    foo()
    {
        std::cout << "Object foo [" << this << "] created via default constructor \n";
    }
    ~foo()
    {
        std::cout << "foo [" << this << "] destroyed\n";
    }
#if 1
    foo(bar const & bar_obj) 
        : _member(bar_obj)
    {
        std::cout << "Object foo [" << this << "] created via parameterised const reference \n";
    }
#else
    foo(bar bar_obj)
        : _member(std::move(bar_obj))
    {
        std::cout << "Object foo [" << this << "] via by parameterised by value \n";
    }
#endif
};

int main()
{
    bar bar_obj{};
    std::cout << "BP1\n";
    auto const object = foo(bar_obj); 
    std::cout << "BP2\n";
}

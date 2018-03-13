#include <bar.hpp>
#include <iostream>

struct Foo
{
    Bar _member;

    Foo()
    {
        std::cout << "Object Foo [" << this << "] created via default constructor \n";
    }
    ~Foo()
    {
        std::cout << "Foo [" << this << "] destroyed\n";
    }
#if 1
    Foo(Bar const & bar_obj) 
        : _member(bar_obj)
    {
        std::cout << "Object Foo [" << this << "] created via parameterised const reference \n";
    }
#else
    Foo(Bar bar_obj)
        : _member(std::move(bar_obj))
    {
        std::cout << "Object Foo [" << this << "] via by parameterised by value \n";
    }
#endif
};

int main()
{
    Bar bar_obj{};
    std::cout << "BP1\n";
    auto const object = Foo(bar_obj); 
    std::cout << "BP2\n";
}

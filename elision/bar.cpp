#include <bar.hpp>

#include <iostream>

bar::bar()
{
    std::cout << "Object bar [" << this << "] created via default constructor\n";
}

bar::bar(bar const & rhs)
{
    std::cout << "Object bar [" << &rhs << "] ==> [" << this << "] created via copy constructor\n";
}

bar & bar::operator = (bar const & rhs)
{
    std::cout << "Object bar [" << &rhs << "] ==> [" << this << "] created via copy assignment operator\n";
    return *this;
}

bar::~bar()
{
    std::cout << "Object bar [" << this << "] destroyed\n";
}
    
#if 1
bar::bar(bar && rhs)
{
    std::cout << "Object bar [" << &rhs << "] ==> [" << this << "] move constructed\n";
}

bar & bar::operator = (bar && rhs)
{
    std::cout << "Object bar [" << &rhs << "] ==> [" << this << "] constructed via move assignment\n";
    return *this;
}
#endif


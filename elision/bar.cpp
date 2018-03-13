#include <bar.hpp>

#include <iostream>

Bar::Bar()
{
    std::cout << "Object Bar [" << this << "] created via default constructor\n";
}

Bar::Bar(Bar const & rhs)
{
    std::cout << "Object Bar [" << this << "] created via copy constructor\n";
}

Bar & Bar::operator = (Bar const & rhs)
{
    std::cout << "Object Bar [" << this << "] created via copy assignment operator\n";
    return *this;
}

Bar::~Bar()
{
    std::cout << "Object Bar [" << this << "] destroyed\n";
}
    
#if 1
Bar::Bar(Bar && lhs)
{
    std::cout << "Object Bar [" << this << "] move constructed\n";
}

Bar & Bar::operator = (Bar && rhs)
{
    std::cout << "Object Bar [" << this << "] constructed via move assignment\n";
    return *this;
}
#endif


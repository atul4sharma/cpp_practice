#include <bar.hpp>

#include <string>
#include <iostream>
namespace elision
{
    bool DEBUG = true;

    bar::bar()
    {
        if( DEBUG == true )
            std::cout << "Object bar [" << this << "] created via default constructor\n";
    }

    bar::bar(bar const & rhs)
    {
        if( DEBUG == true )
            std::cout << "Object bar [" << &rhs << "] ==> [" << this << "] created via copy constructor\n";
    }

    bar & bar::operator = (bar const & rhs)
    {
        if( DEBUG == true )
            std::cout << "Object bar [" << &rhs << "] ==> [" << this << "] created via copy assignment operator\n";
        return *this;
    }

    bar::~bar()
    {
        if( DEBUG == true )
            std::cout << "Object bar [" << this << "] destroyed\n";
    }

    bar::bar(int const & x, double const & y)
    {
        if( DEBUG == true )
            std::cout << "Object bar [" << this << "] created via parameterised constructor (int, double) = (" << x << ", " << y << ")\n";
    }

    bar::bar(std::string const & val)
    {
        if( DEBUG == true )
            std::cout << "Object bar [" << this << "] created via parameterised constructor (string) = (" << val << ")\n";
        
    }
#if 0
    bar::bar(std::initializer_list<std::string> const & sequence)
    {
        if( DEBUG == true )
        {
            std::cout << "Object bar [" << this << "] created via parameterised constructor std::initializer_list<std::string> = (";
            for(auto & item : sequence)
            {
                std::cout << item << ", ";
            }
            std::cout << ")\n";
        }
    }

    bar::bar(std::initializer_list<int> const & sequence)
    {
        if( DEBUG == true )
        {
            std::cout << "Object bar [" << this << "] created via parameterised constructor std::initializer_list<int> = (";
            for(auto & item : sequence)
            {
                std::cout << item << ", ";
            }
            std::cout << ")\n";
        }
    }
#endif

#if 1
    bar::bar(bar && rhs)
    {
        if( DEBUG == true )
            std::cout << "Object bar [" << &rhs << "] ==> [" << this << "] move constructed\n";
    }

    bar & bar::operator = (bar && rhs)
    {
        if( DEBUG == true )
            std::cout << "Object bar [" << &rhs << "] ==> [" << this << "] constructed via move assignment\n";
        return *this;
    }
#endif

    void bar::doSomething() const
    {
        std::cout << "This function do something \n";
    }
}

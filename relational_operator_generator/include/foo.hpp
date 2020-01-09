
#pragma once

#include <include/relational_operator_generator.hpp>


struct foo : rel_op_generator<foo>
{
    int _x;

    foo(int x):_x(std::move(x)){}

    friend auto operator < (foo const & lt
                           ,foo const & rt)
        -> bool
    {
        return lt._x < rt._x;
    }

    friend auto operator == (foo const & lt
                            ,foo const & rt)
        -> bool
    {
        return lt._x == rt._x;
    }
};

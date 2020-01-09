
#pragma once

#include <include/relational_operator_generator.hpp>


struct bar : rel_op_generator<bar>
{
    int _x;

    bar(int x):_x(std::move(x)){}

    friend auto operator < (bar const & lt
                           ,bar const & rt)
        -> bool
    {
        return lt._x < rt._x;
    }
};

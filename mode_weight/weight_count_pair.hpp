
#pragma once

#include <utility>
#include <iostream>

using weight = int;
using count  = int;

struct weight_count_pair
{
    public:
        explicit weight_count_pair(weight w_val, count c_val)
            :_w_val{w_val}
            ,_c_val{c_val}
        {}
    
        weight_count_pair(weight w_val)
            :weight_count_pair(w_val, 1)
        {}

        void increment_count()
        {
            ++_c_val;
        }
    
        friend auto operator==(weight_count_pair const & a, weight_count_pair const & b)
            -> bool;

        friend auto operator<(weight_count_pair const & a, weight_count_pair const & b)
            -> bool;

        friend auto operator<<(std::ostream & out, weight_count_pair const & l)
            -> std::ostream &;

        auto w_val() const
            -> weight
        {
            return _w_val;
        }
    private:
        weight _w_val;
        count  _c_val;
};

auto operator==(weight_count_pair const & a, weight_count_pair const & b)
    -> bool
{
    return a._w_val == b._w_val;
}

auto operator<(weight_count_pair const & a, weight_count_pair const & b)
    -> bool
{
    return a._c_val < b._c_val;
}

auto operator<<(std::ostream & out, weight_count_pair const & val)
    -> std::ostream &
{
    out << "(" << val._w_val << "," << val._c_val << ")" ;
    return out;
}

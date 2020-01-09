
#pragma once


#include <utility>

template <typename Derived>
struct equality_op
{
#if 1
    friend auto operator == (Derived const & lhs
                            ,Derived const & rhs)
        -> bool
    {
        return !(lhs < rhs) && !(rhs < lhs);
    }
#endif

    friend auto operator != (Derived const & lhs
                            ,Derived const & rhs)
        -> bool
    {
        return !(lhs == rhs);
    }
};


template <typename Derived>
struct rel_op_generator : equality_op<Derived>
{

    friend auto operator > (Derived const & lhs
                           ,Derived const & rhs)
        -> bool
    {
        return rhs < lhs;
    }

    friend auto operator >= (Derived const & lhs
                            ,Derived const & rhs)
        -> bool
    {
        return !(lhs < rhs);
    }

    friend auto operator <= (Derived const & lhs
                            ,Derived const & rhs)
        -> bool
    {
        return !(lhs > rhs);
    }

};


#pragma once



#include <boost/type_index.hpp>
#include <boost/any.hpp>

template <typename Function>
struct erased_type
{

    using value_type = Function;

    explicit erased_type(Function && f)
        :_any_var(f)
    {}

    private:
        boost::any _any_var;
};

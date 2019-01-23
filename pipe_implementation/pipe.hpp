

#pragma once

#include "function.hpp"
#include "erased_type.hpp"

#include <boost/type_index.hpp>
#include <boost/any.hpp>
#include <boost/variant.hpp>

#include <vector>
#include <iostream>

template <typename DataType>
struct pipe_t
{
        template <typename ...T>
        pipe_t(T&&... f)
        {
            pipe_t_impl(std::forward<T>(f)...);
        }
        
        template <typename T, typename ...U>
        auto pipe_t_impl(T && f, U&&... f_pack)
            -> void
        {
            std::cout << "Type deduced => " << boost::typeindex::type_id<decltype(f)>().pretty_name() << "\n";
            auto const function_object = toFunction(std::forward<T>(f));
            std::cout << "Type deduced(decorated) => " << boost::typeindex::type_id<decltype(function_object)>().pretty_name() << "\n";
            _functions_to_apply<decltype(f)>.push_back(f);
            pipe_t_impl(std::forward<U>(f_pack)...);
        }
    
        auto pipe_t_impl()
            -> void
        {}

        auto print_all_types() const
            -> void
        {
#if 0
            for(auto const & item : _functions_to_apply)
            {
                std::cout << boost::typeindex::type_id<decltype(item)>().pretty_name() << "\n";
            }
#endif
        }
    
    private:
        template <typename T>
        static std::vector<T> _functions_to_apply;
    
};


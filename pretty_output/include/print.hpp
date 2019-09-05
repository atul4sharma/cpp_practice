
#pragma once

#include "overload_selector.hpp"

#include <tuple>
#if __cplusplus < 201402
    #include "integer_sequence.hpp"
    using meta::integer_sequence;
    using meta::make_index_sequence;
#else
    using std::integer_sequence;
    using std::make_index_sequence;
#endif

template <typename T>
auto print(std::ostream &, T const &)
    -> std::ostream &;

template <typename Item>
auto print_impl(std::ostream & out, Item const & item, meta::_1st_preference)
    -> decltype( out << item, out)
{
    out << item;
    return out;
}

template <typename Container>
auto print_impl(std::ostream & out, Container const & iterable, meta::_2nd_preference)
    -> decltype(iterable.begin(), out)
{
    auto is_delim = false;
    using std::begin; using std::end;
    out << "{";
    for(auto const & item : iterable)
    {
        if( is_delim )
            out << ", ";
        print(out, item);
        if( not is_delim )
            is_delim = true;
    }
    out << "}";
    return out;
}

template <typename Range, typename Int, Int ... ints>
auto print_indexable_impl(std::ostream & out, Range const & range, integer_sequence<Int, ints...>)
    -> std::ostream &
{
    out << "(";
    (int[]){0, (print((out << ((ints == 0) ? "":", "), out)
                     ,std::get<ints>(range)), 0)...};
    out << ")";
    return out;
}

template <typename Range>
auto print_indexable(std::ostream & out, Range const & range)
    -> std::ostream &
{
    return print_indexable_impl(out, range, make_index_sequence<std::tuple_size<Range>::value>{});
}

template <typename Container>
auto print_impl(std::ostream & out, Container const & item, meta::_2nd_preference)
    -> decltype(std::tuple_size<Container>::value , out)
{
   return print_indexable(out, item);
}

template <typename T>
auto print(std::ostream & out, T const & item)
    -> std::ostream &
{
    return print_impl(out, item, meta::overload_selector{});
}


template <typename T>
auto println(std::ostream & out, T && item)
    -> std::ostream &
{
    print(out, std::forward<decltype(item)>(item));
    out << "\n";
    return out;
}

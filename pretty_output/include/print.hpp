
#pragma once

#include "overload_selector.hpp"

#include <memory>
#include <string>
#include <tuple>
#include <iostream>
#include <iterator>
#include <algorithm>

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
    using std::begin; using std::end; using std::next;
    out << "{";
    if( begin(iterable) != end(iterable) )
    {
        print(out, *(begin(iterable)));
        std::for_each(next(begin(iterable))
                     ,end(iterable)
                     ,[&out](decltype(*begin(iterable)) const & item)
                            {
                                 print((out << ", ", out), item);
                            }
                     );
    }
    out << "}";
    return out;
}

namespace {
    template <typename Range, typename Int, Int ... ints>
    auto print_indexable_impl(std::ostream & out, Range const & range, integer_sequence<Int, ints...>)
        -> std::ostream &
    {
        out << "(";
        (int[]){(print((out << ((ints == 0) ? "":", "), out)
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
}

template <typename T, typename D>
auto print_impl(std::ostream & out, std::unique_ptr<T, D> const & ptr, meta::_1st_preference)
    -> std::ostream &
{
    // TODO : Try to print some other valuable information here 
    return print(out, *ptr);
}

template <typename Container>
auto print_impl(std::ostream & out, Container const & item, meta::_2nd_preference)
    -> decltype(std::tuple_size<Container>::value , out)
{
   return print_indexable(out, item);
}

template <typename CustomObject>
auto print_impl(std::ostream & out, CustomObject const & object, meta::_3rd_preference)
    -> decltype(to_string(object), out)
{
    return print(out, to_string(object));
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

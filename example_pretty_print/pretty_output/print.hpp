
#pragma once

#include "overload_selector.hpp"

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
auto print_impl(std::ostream & out, Container const & iterable, meta::_1st_preference)
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

#if 1
template <typename Container
         ,typename _ = typename Container::first_type>
auto print_impl(std::ostream & out, Container const & item, meta::_1st_preference)
    -> std::ostream &
{
    out << "("; print(out, item.first); out << ", "; print(out, item.second); out << ")";
    return out;
}
#endif

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


#pragma once

#include <boost/range/iterator_range.hpp>
#include <boost/iterator/transform_iterator.hpp>

#include <utility>

template <typename AssociativeContainer>
auto keys(AssociativeContainer const & c)
{
    auto const get_first = [](decltype(*c.begin()) const & item)
    {
        return std::get<0>(item);
    };
    return boost::make_iterator_range(boost::make_transform_iterator(c.begin(), get_first)
                                     ,boost::make_transform_iterator(c.end()  , get_first));
}

template <typename AssociativeContainer>
auto values(AssociativeContainer const & c)
{
    auto const get_second = [](decltype(*c.begin()) const & item)
    {
        return std::get<1>(item);
    };
    return boost::make_iterator_range(boost::make_transform_iterator(c.begin(), get_second)
                                     ,boost::make_transform_iterator(c.end()  , get_second));
}

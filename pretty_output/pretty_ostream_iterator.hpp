#pragma once

#include "overload_selector.hpp"

#include <iostream>
#include <iterator>
#include <type_traits>

// This works similar to ostream_iterator, but doesn't print a delimiter after the final item
template<typename T, typename TChar = char, typename TCharTraits = std::char_traits<TChar> >
class pretty_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
{
    public:
        using char_type    = TChar;
        using traits_type  = TCharTraits;
        using ostream_type = std::basic_ostream<TChar, TCharTraits>;

        pretty_ostream_iterator(ostream_type &stream, const char_type *delim = NULL)
            : _stream(&stream), _delim(delim), _insertDelim(false)
        {
        }

        pretty_ostream_iterator<T, TChar, TCharTraits>& operator=(const T &value)
        {
            if( _delim != NULL )
            {
                // Don't insert a delimiter if this is the first time the function is called
                if( _insertDelim )
                    (*_stream) << _delim;
                else
                    _insertDelim = true;
            }
            (*_stream) << value;
            return *this;
        }

        pretty_ostream_iterator<T, TChar, TCharTraits>& operator*() { return *this; }

        pretty_ostream_iterator<T, TChar, TCharTraits>& operator++() { return *this; }

        pretty_ostream_iterator<T, TChar, TCharTraits>& operator++(int) { return *this; }

    private:
        ostream_type    *_stream;
        const char_type *_delim;
        bool             _insertDelim;
};


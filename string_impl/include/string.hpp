
#pragma once

#include <memory>
#include <cstring>
#include <cstdlib>
#include <iostream>

namespace utils
{
    struct string
    {
        string()  = default;

        ~string() = default;

        string(char const * str);

        string(std::size_t length);

        string(string const & other);

        auto operator = (string other) -> string &;

        auto c_str() const             -> char const *;

        auto c_str()                   -> char *;

        auto size() const              -> std::size_t;

        friend auto operator << (std::ostream       & out
                                ,string       const & row)
            -> std::ostream &;

        friend auto operator == (string const & lhs
                                ,string const & rhs)
            -> bool;

        friend auto operator <  (string const & lhs
                                ,string const & rhs)
            -> bool;

        friend auto operator +=(string & lt, string const & rt)
            -> string &;

        private:
            std::size_t             m_length;
            std::unique_ptr<char[]> m_str;
    };

    auto operator << (std::ostream       & out
                     ,string       const & row)
        -> std::ostream &;

    auto operator == (string const & lhs
                     ,string const & rhs)
        -> bool;

    auto operator <  (string const & lhs
                     ,string const & rhs)
        -> bool;

    auto operator >  (string const & lhs
                     ,string const & rhs)
        -> bool;

    auto operator != (string const & lhs
                     ,string const & rhs)
        -> bool;

    auto operator +=(string & lt, string const & rt)
        -> string &;

    auto operator +(string lt, string const & rt)
        -> string;

}

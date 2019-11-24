
#include <include/string.hpp>

namespace utils
{
    string::string(char const * str)
        :m_length{std::strlen(str)}
    {
        m_str = std::make_unique<char[]>(this->size() + 1);
        std::strcpy(m_str.get(), str);
    }

    string::string(std::size_t length)
        :m_length{length}
    {
        m_str = std::make_unique<char[]>(this->size());
    }

    string::string(string const & other)
        : string(other.c_str())
    {}

    auto string::operator = (string other)
        -> string &
    {
        m_str.swap(other.m_str);
        return *this;
    }

    auto string::c_str() const
        -> char const *
    {
        return m_str.get();
    }

    auto string::c_str()
        -> char *
    {
        return m_str.get();
    }

    auto string::size() const 
        -> std::size_t
    {
        return m_length;
    }

    // Free functions
    auto operator << (std::ostream       & out
                     ,string       const & row)
        -> std::ostream &
    {
        out << row.c_str();
        return out;
    }

    auto operator == (string const & lhs
                     ,string const & rhs)
        -> bool
    {
        return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
    }

    auto operator != (string const & lhs
                     ,string const & rhs)
        -> bool
    {
        return not(lhs == rhs);
    }

    auto operator < (string const & lhs
                    ,string const & rhs)
        -> bool
    {
        return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
    }

    auto operator > (string const & lhs
                    ,string const & rhs)
        -> bool
    {
        return rhs < lhs;
    }

    auto operator += (string       & lt
                     ,string const & rt)
        -> string &
    {
        string temp{lt.size() + rt.size() + 1};
        std::strcpy(temp.c_str(), lt.c_str());
        std::strcat(temp.c_str(), rt.c_str());
        lt = temp;
        return lt;
    }

    auto operator + (string         lt
                    ,string const & rt)
        -> string
    {
        lt += rt;
        return lt;
    }

}


#pragma once

#include "loader_interface.hpp"

#include <boost/tokenizer.hpp>

#include <iostream>
#include <string>
#include <vector>

struct security_list : bulk_inserter<security_list>, file_reader<security_list>, execute_proc<security_list>
{
    explicit security_list() = default;

    explicit security_list(std::string a, std::string b, std::string c)
        :_a{a}, _b{b}, _c{c}
    {}
    
    auto proc_query(std::string const & gtt_table) const
        -> std::string const
    {
        return std::string{ "select * from " + gtt_table };
    }
    
    std::string _a;
    std::string _b;
    std::string _c;
};

inline std::ostream & operator<< ( std::ostream & os, security_list const & obj)
{
    os << obj._a << ", " << obj._b << ", " << obj._c;
    return os;
}

#if 1
auto row_to_construct(security_list const &, std::string const & file_line)
    -> security_list
{
    boost::char_separator<char> sep(",");
    boost::tokenizer<boost::char_separator<char>> tokens(file_line, sep);
    std::vector<std::string> v{tokens.begin(), tokens.end()};
    return security_list{v.at(0), v.at(1), v.at(2)};
}
#endif


auto bulk_insert(/*db_executor & db
            ,*/security_list              const &
              ,std::vector<security_list> const & result
              ,std::string                const & gtt_table
              ,std::size_t                const & batch_size
              ,db_log_info                const & log_info
              ,bool                               was_loaded)
    -> void
{
    std::cout << "Object of security_list : \n"
              << "gtt_table  => " << gtt_table  << "\n"
              << "batch_size => " << batch_size << "\n"
              << "db_info    => " << log_info   << "\n"
              << "was_loaded => " << was_loaded << "\n";
    std::cout << std::endl;
}

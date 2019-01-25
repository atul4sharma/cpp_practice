
#pragma once

#include "loader_interface.hpp"

#include <boost/tokenizer.hpp>

#include <iostream>
#include <string>
#include <vector>

struct security_list : bulk_inserter<security_list>, file_reader<security_list>, execute_proc<security_list>
{
    explicit security_list(std::string a, std::string b, std::string c)
        :_a(a), _b(b), _c(c)
    {}
    
#if 1
	// REQUIRED: delegating constructor that would convert vector(obtained by tokenizer) to the struct format
    explicit security_list(std::vector<std::string> const & row)
        :security_list(row.at(0), row.at(1), row.at(2))
    {}
#endif
    
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

template <>
auto row_to_construct<security_list>(std::string const & file_line)
    -> security_list
{
    boost::char_separator<char> sep(",");
    boost::tokenizer<boost::char_separator<char>> tokens(file_line, sep);
    std::vector<std::string> v{tokens.begin(), tokens.end()};
    return security_list{v.at(0), v.at(1), v.at(2)};
}

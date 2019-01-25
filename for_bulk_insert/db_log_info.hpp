
#pragma once

#include <string>
#include <iostream>

struct db_log_info
{
    explicit db_log_info(std::string price_date
                        ,std::string invocation_id
                        ,std::string run_id)
        :_price_date   {std::move(price_date)}
        ,_invocation_id{std::move(invocation_id)}
        ,_run_id       {std::move(run_id)}
    {}

    friend std::ostream & operator<<(std::ostream & os, db_log_info const & obj);

    private:
        std::string _price_date;
        std::string _invocation_id;
        std::string _run_id;
    
};


inline std::ostream & operator<<(std::ostream & os, db_log_info const & obj)
{
    os << "price_date["    << obj._price_date    << "]\t"
       << "invocation_id[" << obj._invocation_id << "]\t"
       << "run_id["        << obj._run_id        << "]";
    return os;
}

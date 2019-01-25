
#pragma once

#include "db_log_info.hpp"

#include <iostream>
#include <string>
#include <vector>


template <typename construct_type>
struct file_reader
{
    auto read_file(std::string const & file_path)
        -> std::vector<construct_type>
    {
        auto result = std::vector<construct_type>{};
        (void)file_path;
        // will beread from file 
        std::cout << "file [" << file_path << "] shall be read here\n";
        std::string row{"id1,id2,id3"};
        auto const &item = row_to_construct(static_cast<construct_type&>(*this), row);
        std::cout << "emplacing back => [" << item << "]\n\n";
        result.emplace_back(item);
        return result;
    }
};

template <typename construct_type>
struct bulk_inserter
{
    template <typename ...rest_of_the_parameter>
    auto load_data(/*db_executor & db
                ,*/std::vector<construct_type> const & result
                  ,std::string                 const & gtt_table
                  ,std::size_t                 const & batch_size
                  ,db_log_info                 const & log_info
                  ,rest_of_the_parameter &&...         arg_pack)
        -> void
    {
        // static_cast<construct_type&>(*this).bulk_insert(/*db, */result, gtt_table, batch_size, price_date, invocation_id, run_id, std::forward<rest_of_the_parameter>(arg_pack)...);
       bulk_insert(/*db, */static_cast<construct_type&>(*this), result, gtt_table, batch_size, log_info, std::forward<rest_of_the_parameter>(arg_pack)...);
    }
};

template <typename construct_type>
struct execute_proc
{
    auto execute(/*db_executor &db
                ,*/std::string const & gtt_table)
        -> void
    {
        auto const & query = static_cast<construct_type&>(*this).proc_query(gtt_table);
        std::cout << "will execute query : " << query << "\n";
        //db.execute(query);
    }
};


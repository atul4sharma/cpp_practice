#include <iostream>
#include <string>
#include <vector>

template <typename construct_type>
struct file_reader
{
    auto read_file(std::string const & file_path) const
        -> std::vector<construct_type>
    {
        auto result = std::vector<construct_type>{};
        (void)file_path;
        // will beread from file 
        auto const & row = std::vector<std::string>{"id1", "id2", "id3"};
        result.emplace_back(row);
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
                  ,std::string                 const & price_date
                  ,std::string                 const & invocation_id
                  ,std::string                 const & run_id
                  ,rest_of_the_parameter &&...         arg_pack)
        -> void
    {
        static_cast<construct_type&>(*this).bulk_insert(/*db, */result, gtt_table, batch_size, price_date, invocation_id, run_id, std::forward<rest_of_the_parameter>(arg_pack)...);
    }
};

struct security_list : bulk_inserter<security_list>, file_reader<security_list>
{
    explicit security_list(std::string a, std::string b, std::string c)
        :_a(a), _b(b), _c(c)
    {}
    
	// REQUIRED: delegating constructor that would convert vector(obtained by tokenizer) to the struct format
    explicit security_list(std::vector<std::string> const & row)
        :security_list(row.at(0), row.at(1), row.at(2))
    {}
    
    void bulk_insert(/*db_executor & db
				,*/std::vector<security_list> const & result
                  ,std::string                 const & gtt_table
                  ,std::size_t                 const & batch_size
                  ,std::string                 const & price_date
                  ,std::string                 const & invocation_id
                  ,std::string                 const & run_id
                  ,bool                                was_loaded) const
    {
        // bulk_string loading logic here
        std::cout << "here it should bulk insert data specific to the struct itself \n";
		std::cout << "gtt_table     => " << gtt_table     << "\n"
				  << "batch_size    => " << batch_size    << "\n"
				  << "price_date    => " << price_date    << "\n"
 				  << "invocation_id => " << invocation_id << "\n"
				  << "run_id        => " << run_id        << "\n"
                  << "was_loaded    => " << was_loaded    << "\n";
    }
    
    std::string _a;
    std::string _b;
    std::string _c;
};

std::ostream & operator<< ( std::ostream & os, security_list const & obj)
{
    os << obj._a << ", " << obj._b << ", " << obj._c;
    return os;
}

int main()
{
    auto const obj = security_list{"one", "two", "three"};
    std::cout << obj << "\n";
    
    std::vector<std::string> color{"red", "yellow", "blue"};
    auto const obj2 = security_list{color};
    std::cout << obj2 << "\n";
    
    auto obj3 = security_list{color};
    
    auto const result_rows = obj3.read_file("somefile");
    
    for(auto const & item : result_rows)
    {
        std::cout << item << "\n";
    }

/*
				   std::vector<security_list>  const & result
                  ,std::string                 const & gtt_table
                  ,std::size_t                 const & batch_size
                  ,std::string                 const & price_date
                  ,std::string                 const & invocation_id
                  ,std::string                 const & run_id
                  ,bool                                was_loaded)
*/	
    
	obj3.load_data(result_rows, "gtt_table_val", 20000, "price_date_val", "invocation_id_val", "run_id_val", true);
    
}

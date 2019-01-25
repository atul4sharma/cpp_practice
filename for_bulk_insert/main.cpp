#include "security_list_struct.hpp"

#include <iostream>
#include <string>
#include <vector>


int main()
{
    std::vector<std::string> color{"red", "yellow", "blue"};
#if 0
    auto const obj = security_list{"one", "two", "three"};
    std::cout << obj << "\n";
    
    auto const obj2 = security_list{color};
    std::cout << obj2 << "\n";
#endif 

    auto obj3 = security_list{color};
    
    auto const result_rows = obj3.read_file("somefile");
    
#if 0
    for(auto const & item : result_rows)
    {
        std::cout << item << "\n";
    }
#endif

/*
				   std::vector<security_list>  const & result
                  ,std::string                 const & gtt_table
                  ,std::size_t                 const & batch_size
                  ,std::string                 const & price_date
                  ,std::string                 const & invocation_id
                  ,std::string                 const & run_id
                  ,bool                                was_loaded)
*/	
    
	obj3.load_data(/*db,*/ result_rows, "gtt_table_val", 20000, "price_date_val", "invocation_id_val", "run_id_val", true);
	obj3.execute(/*db,*/ "gtt_table_val");
    
}

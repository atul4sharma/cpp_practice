
#include <elision/bar.hpp>

#include <iostream>
#include <string>
#include <vector>

auto add_to_vector(std::vector<elision::bar> & v, elision::bar const & obj)
    -> void
{
    std::cout << "\n--------------------------------------------------------------------------------\n";
    v.push_back(obj);
    std::cout << "********************************************************************************\n\n";
}

auto add_to_vector_copy_and_move(std::vector<elision::bar> & v, elision::bar obj)
    -> void
{
    std::cout << "\n--------------------------------------------------------------------------------\n";
    v.push_back(std::move(obj));
    std::cout << "********************************************************************************\n\n";
}


int main()
{
    auto const val = std::string{"test_run_statement"};
    auto && v = std::vector<elision::bar>{};
    auto && temp_obj = elision::bar{val};

#if 1
    std::cout << "const & \n";
    add_to_vector(v, temp_obj);
    add_to_vector(v, elision::bar{val});
#else
    std::cout << "copy and move \n";
    add_to_vector_copy_and_move(v, temp_obj);
    add_to_vector_copy_and_move(v, elision::bar{val});
#endif


    return 0;
}

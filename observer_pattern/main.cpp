#include <iostream>

#include <third_party.hpp>
#include <user.hpp>
#include <country_enum.hpp>

#include <memory>
#include <iostream>


int main()
{
    third_party server_obj{};

    auto register_user = [&server_obj] (std::string          const & user_name, 
                                        std::vector<country> const & c_list)
    {
        std::cout << "Adding user " << user_name << "\n";

        auto ptr = std::make_shared<user>(c_list);
        server_obj.add_user(ptr);

        std::cout << "USER " << user_name << " added\n\n";
        return ptr;
    };

    auto zeeshan = register_user("zeeshan", std::vector<country>{country::EUR, country::AUS});

    auto atul    = register_user("atul"   , std::vector<country>{country::EUR, country::IND});

    server_obj.update_price("bogie", 23423423);

    server_obj.update_price("muni", 222);

    server_obj.add_stock(stock{"new", country::AUS, 123});

    return 0;
}

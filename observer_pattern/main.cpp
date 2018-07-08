#include <iostream>

#include <third_party.hpp>
#include <user.hpp>
#include <country_enum.hpp>

#include <memory>
#include <iostream>


int main()
{
    std::cout << "Main\n";
    third_party server_obj{};

    auto country_list_for_zeeshan = std::vector<country>{country::EUR, country::AUS};
    auto country_list_for_atul    = std::vector<country>{country::EUR, country::IND};

    auto zeeshan = std::make_shared<user>(country_list_for_zeeshan);

    auto atul    = std::make_shared<user>(country_list_for_atul);

    server_obj.add_user(zeeshan);
    std::cout << "Added zeeshan\n\n";
    
    server_obj.add_user(atul);
    std::cout << "Added atul\n\n";

    server_obj.update_price("bogie", 23423423);
    server_obj.update_price("muni", 222);

    server_obj.add_stock(stock{"new", country::AUS, 123});

    return 0;
}

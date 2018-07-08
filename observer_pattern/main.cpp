#include <iostream>

#include <third_party.hpp>
#include <user.hpp>
#include <country_enum.hpp>


#include <iostream>


int main()
{
    std::cout << "Main\n";
    third_party server_obj{};

    user zeeshan{std::vector<country>{country::EUR, country::AUS}};

    user atul{std::vector<country>{country::EUR, country::IND}};

    server_obj.add_user(&zeeshan);
    std::cout << "Added zeeshan\n\n";
    
    server_obj.add_user(&atul);
    std::cout << "Added atul\n\n";

    server_obj.update_price("bogie", 23423423);
    server_obj.update_price("muni", 222);

    server_obj.add_stock(stock{"new", country::AUS, 123});

    return 0;
}


#include <server.hpp>
#include <stock.hpp>
#include <third_party.hpp>

#include <iostream>


void third_party::update_price(std::string const & id,
                               size_t      const & cost)
{
    server::notify(id, cost);
}

void third_party::add_stock(stock const & item)
{
    server::add_stock(item);
}

void third_party::remove_stock(stock const & item)
{
    server::remove_stock(item);
}

void third_party::add_country(abstract_user       * usr, 
                              country       const & code)
{
    server::add_country(usr, code);
}

void third_party::remove_country(abstract_user       * usr,
                                 country       const & code)
{
    server::remove_country(usr, code);
}

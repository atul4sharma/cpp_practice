#pragma once

#include <server.hpp>
#include <stock.hpp>

#include <iostream>

class third_party : public server
{
    public:

        void update_price(std::string const & id,
                          size_t      const & cost);

        void add_stock   (stock const & item);

        void remove_stock(stock const & item);

        void add_country   (abstract_user       * usr, 
                            country       const & code);

        void remove_country(abstract_user       * usr,
                            country       const & code);

};


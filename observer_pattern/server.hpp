#pragma once

#include <user.hpp>
#include <stock.hpp>
#include <country_enum.hpp>


#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

class server
{
    public:
        server()
        {
            _all_stocks.emplace_back(stock{"muni" , country::IND, 300});
            _all_stocks.emplace_back(stock{"bogie", country::AUS, 4300});
            _all_stocks.emplace_back(stock{"fixed", country::EUR, 3030});
            _all_stocks.emplace_back(stock{"mortg", country::USA, 3035});
        }

        void add_user   (std::shared_ptr<abstract_user> usr);

        void remove_user(std::shared_ptr<abstract_user> usr);

        void notify     (std::string const & id,
                         size_t      const & cost);
    protected:
        void add_stock(stock const & item);

        void remove_stock(stock const & item);

        void add_country   (std::shared_ptr<abstract_user>         usr,
                            country                        const & code);

        void remove_country(std::shared_ptr<abstract_user>         usr,
                            country                        const & code);

    private:
        void notify_stock_addition(stock const & item);

        void notify_stock_removal (stock const & item);

        std::vector<std::shared_ptr<abstract_user>> _registered_users;
        std::vector<stock>                          _all_stocks;
        
};


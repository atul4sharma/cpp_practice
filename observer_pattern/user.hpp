#pragma once

#include <abstract_user.hpp>
#include <country_enum.hpp>
#include <stock.hpp>

#include <iostream>
#include <vector>
#include <unordered_map>


class user : public abstract_user
{
    public:
        user() = default;

        user(std::vector<country> const & list);

        void add_stock   (stock const & item)              override;

        void remove_stock(stock const & item)              override;

        void update_stock_price(std::string const & id,
                                size_t      const & price) override;

        std::unordered_map<std::string, stock> stock_list();

        std::vector<country> interested_countries()         override;

        void interested_stocks();


    private:
        void add_country   (country const & code);

        void remove_country(country const & code);

        std::unordered_map<std::string, stock> _stock_list;
        std::vector<country>                   _interested_countries{country::IND};

};
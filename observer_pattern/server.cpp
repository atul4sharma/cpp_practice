
#include <server.hpp>

#include <iostream>
#include <unordered_map>
#include <algorithm>

void server::add_user(std::shared_ptr<abstract_user> usr)
{
    _registered_users.push_back(usr);

    // update stock list for usr
    for(auto const & item : _all_stocks)
    {
        auto countries  = usr->interested_countries();
        auto exist_iter = std::find(std::begin(countries), 
                                    std::end  (countries),
                                    item.country_code());
        if(exist_iter != std::end(countries))
        {
            usr->add_stock(item);
        }
    }

}

void server::remove_user(std::shared_ptr<abstract_user> usr)
{
    auto iter = std::find(std::begin(_registered_users),
                          std::end  (_registered_users),
                          usr);

    if(iter != std::end(_registered_users))
    {
        _registered_users.erase(iter);
    }
    else
    {
        std::cout << "User not registered. \n";
    }
    
}

void server::notify(std::string const & id,
                    size_t      const & cost)
{
    for(auto const & usr : _registered_users)
    {
        usr->update_stock_price(id, cost);
    }

}

void server::add_stock(stock const & item)
{
    _all_stocks.emplace_back(item);
    notify_stock_addition(item);

}

void server::remove_stock(stock const & item)
{
    auto iter = std::find(std::begin(_all_stocks),
                          std::end  (_all_stocks),
                          item);
    if(iter != std::end(_all_stocks))
    {
        _all_stocks.erase(iter);
        notify_stock_removal(*iter);
    }
}


void server::add_country(std::shared_ptr<abstract_user>         usr,
                         country                        const & code)
{
    auto interested_countries = usr->interested_countries();
    interested_countries.push_back(code);
}

void server::remove_country(std::shared_ptr<abstract_user>         usr,
                            country                        const & code)
{
    auto interested_countries = usr->interested_countries();
    auto iter = std::find(std::begin(interested_countries),
                          std::end  (interested_countries),
                          code);
    if(iter != std::end(interested_countries))
    {
        interested_countries.erase(iter);
    }

}


void server::notify_stock_addition(stock const & item)
{
    for(auto const & usr : _registered_users)
    {
        auto interested_countries = usr->interested_countries();
        auto iter = std::find(std::begin(interested_countries),
                              std::end  (interested_countries),
                              item.country_code());
        if(iter != std::end(interested_countries))
        {
            usr->add_stock(item);
        }
    }
}

void server::notify_stock_removal(stock const & item)
{
    for(auto const & usr : _registered_users)
    {
        auto interested_countries = usr->interested_countries();
        auto iter = std::find(std::begin(interested_countries),
                              std::end  (interested_countries),
                              item.country_code());
        if(iter != std::end(interested_countries))
        {
            usr->remove_stock(item);
        }
    }
}



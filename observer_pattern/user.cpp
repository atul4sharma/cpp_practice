
#include <abstract_user.hpp>
#include <country_enum.hpp>
#include <stock.hpp>
#include <user.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

user::user(std::string          const & user_name,
           std::vector<country> const & list)
          :_user_name(user_name)
          ,_interested_countries(list)
{
}

void user::add_stock(stock const & item)
{
    auto status = _stock_list.insert({item.id(), item});
    if(status.second)
    {
        std::cout << "New stock added\n";
        interested_stocks();
    }
    else
    {
        std::cout << "Could not insert stock \n";
    }
}


void user::remove_stock(stock const & item)
{
    _stock_list.erase(item.id());
}


void user::update_stock_price(std::string const & id,
                              size_t      const & price)
{
    try
    {
        auto stock_to_update = _stock_list.at(id);
        stock_to_update.price(price);
        std::cout << _user_name << " : " << id << " updated price : " << stock_to_update.price() << "\n";
    }
    catch(std::exception const & e)
    {
        // non interested stocks from users' perspective
    }
}

void user::add_country(country const & code)
{
   _interested_countries.emplace_back(code);
}

void user::remove_country(country const & code)
{
    auto iter = std::find(std::begin(_interested_countries),
                          std::end  (_interested_countries),
                          code); 
    if(iter != std::end(_interested_countries))
    {
        _interested_countries.erase(iter);
    }

}

void user::interested_stocks()
{
    std::cout << "object => " << _user_name << " is interested in stocks : ";
    for(auto const & item : _stock_list)
    {
        std::cout << item.first << ", ";
    }
    std::cout << std::endl;

}

std::vector<country> user::interested_countries() const
{
    return _interested_countries;
}



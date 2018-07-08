#pragma once

#include <country_enum.hpp>
#include <iostream>
#include <string>


struct stock
{

    stock() = default;

    explicit stock(std::string const & id,
                   country             code,
                   size_t      const & cost)
                 :_id{id},
                  _country_code{code},
                  _price{cost}
    {}

    std::string id()           const { return _id; }
    country     country_code() const { return _country_code; }
    size_t      price()        const { return _price; }

    void        price(size_t p)      { _price = p; }

    bool        operator==(stock const & item)
    {
        if( _id == item.id() && _country_code == item.country_code() && _price == item.price() )
            return true;
        else
            return false;
    }


    
    private:
        std::string _id;
        country     _country_code;
        size_t      _price;

};
    

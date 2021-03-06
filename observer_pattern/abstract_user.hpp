#pragma once

#include <stock.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <memory>

class abstract_user : public std::enable_shared_from_this<abstract_user>
{
	public:
		virtual void add_stock(stock const & item)                 = 0;

		virtual void remove_stock(stock const & item)              = 0;

		virtual void update_stock_price(std::string const & id,
						                size_t      const & price) = 0;
	
		virtual std::vector<country> interested_countries() const  = 0;

};

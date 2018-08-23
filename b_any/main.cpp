#include <iostream>
#include <string>
#include <vector>

#include <boost/any.hpp>

struct abc
{
    abc() {   std::cout << "default constructor called\n";    }
    
    abc(std::string const & x) 
        : _item(x)   {   std::cout << "parameterised constructor called\n";  }
    
    operator std::string() const
    {
        return _item;
    }
    
    friend std::ostream & operator << (std::ostream & os, abc const & val);
    
    std::string _item;
};

std::ostream & operator << (std::ostream & os, abc const & val)
{
    os << "value inside abc is => " << val._item << "\n";
    return os;
}

int main()
{
    std::string const & x{"string_value"};
    
    //std::string const & abc_to_string = abc{"new_string"};
    //std::cout << "this is the abc_to_string \'" << abc_to_string << "\'\n";

    boost::any var{abc{x}};
    //boost::any var{x};

    std::cout << var.type().name() << "\n";
    try
    {
        auto const value = boost::any_cast<std::string>(var);
        std::cout << value << "\n";
    }
    catch(boost::bad_any_cast const & e)
    {
        std::cout << e.what() << "\n";
    }


	return 0;
}


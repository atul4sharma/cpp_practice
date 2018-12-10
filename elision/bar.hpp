//This class is just used to check the flow of the program
#pragma once

#include <iostream>
#include <string>
#include <initializer_list>

namespace elision
{
    extern bool DEBUG;
    class bar
    {
        public:
            // Default constructor
            bar();

            // Copy constructor
            bar(bar const & rhs);

            // Copy assignment operator
            bar & operator = (bar const & rhs);

            // Destructor
            virtual ~bar();

            // Parameterised constructor
            bar(int const &, double const &);
            
            // Parameterised constructor string
            bar(std::string const &);

#if 0
            // Parameterised initializer_list constructor std::string
            bar(std::initializer_list<std::string> const &);

            // Parameterised initializer_list constructor int
            bar(std::initializer_list<int> const &);
#endif
#if 1
            // Move constructor
            bar(bar && rhs);

            // Move assignment operator
            bar & operator = (bar && rhs);
#endif

            int x() const
            {return _x;}

            void x(int x)
            {_x = x;}

            void print_address() const
            {
	            std::cerr << "\n" << __LINE__ << "\n";
                std::cout << "address : " << this << "\n";
            }

            virtual void doSomething() const;
        private:
            int _x = 10;

    };
}

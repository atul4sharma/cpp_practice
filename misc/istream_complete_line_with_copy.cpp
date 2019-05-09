
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>


namespace
{
    struct Line : public std::string
    {
        friend std::istream & operator >> (std::istream & in, Line & data)
        {
            std::getline(in, data);
            return in;
        }
    };
}

int main()
{
    auto && second_file = std::ifstream{"group_two.txt"};
    std::copy(std::istream_iterator<Line>(second_file)
             ,std::istream_iterator<Line>()
             ,std::ostream_iterator<Line>(std::cout, "\n"));
    return 0;
    
}

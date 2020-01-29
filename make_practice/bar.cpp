
#include "bar.hpp"

auto bar::statement() const
    -> std::string
{
    return std::string{"bar_string"};
}

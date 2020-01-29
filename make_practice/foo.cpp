
#include "foo.hpp"

auto foo::statement() const
    -> std::string
{
    return std::string{"foo_string"};
}

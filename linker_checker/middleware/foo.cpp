
#include <middleware/foo.hpp>

#include <services/bar.hpp>
#include <iostream>

namespace middleware
{
    auto foo()
        -> int
    {
        std::cout << "middleware::foo()\n";
        return services::bar_function(20);
    }

}

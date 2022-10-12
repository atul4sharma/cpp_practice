
#include <cassert>
#include <iostream>
#include "ci_string.h"

int main()
{
    auto const a = ci_string{"Hello"};
    auto const b = ci_string{"HElLo"};
    auto const c = ci_string{"hello"};

    assert(a == b);
    assert(b == c);
    assert(a == c);

    return 0;
}

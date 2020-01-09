

#include <include/foo.hpp>
#include <include/bar.hpp>

#include <catch/catch.hpp>


TEST_CASE("Checking with struct with operator <, operator == defined", "[foo]")
{

    auto const a = foo{10};
    auto const b = foo{20};

    CHECK(a < b);
    CHECK_FALSE(a > b);

    CHECK_FALSE(a == b);
    CHECK(a != b);

    CHECK(a <= b);
    CHECK_FALSE(a >= b);
}

TEST_CASE("Checking with just struct with operator < defined", "[bar]")
{
    auto const a = bar{10};
    auto const b = bar{20};

    CHECK(a < b);
    CHECK_FALSE(a > b);

    CHECK_FALSE(a == b);
    CHECK(a != b);

    CHECK(a <= b);
    CHECK_FALSE(a >= b);
}

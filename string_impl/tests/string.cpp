

#include <include/string.hpp>

#include <catch/catch.hpp>

#include <memory>
#include <iostream>

TEST_CASE("check equality", "[comparison]")
{
    CHECK( utils::string{"fun"} == utils::string{"fun"});
    CHECK_FALSE( utils::string{"fun"} == utils::string{"FUN"});
}

TEST_CASE("check in-equality", "[comparison]")
{
    CHECK( utils::string{"fun"} != utils::string{"funny"});
}

TEST_CASE("check less than", "[comparison]")
{
    CHECK( utils::string{"fun"} < utils::string{"funny"});
}

TEST_CASE("check greater than", "[comparison]")
{
    CHECK( utils::string{"fun"} < utils::string{"funny"});
}

TEST_CASE("copy construction", "[construction]")
{
    auto const foo_string = utils::string{"foo"};
    CHECK( foo_string == utils::string{"foo"} );
}

TEST_CASE("construction from length", "[construction]")
{
    CHECK_NOTHROW( utils::string{20} );
}

TEST_CASE("copy assignment operator", "[assignment]")
{
    auto const foo_string = utils::string{"foo"};
    auto && empty_string  = utils::string{};
    empty_string = foo_string;
    CHECK( empty_string == foo_string);
}

TEST_CASE("printing string", "[print]")
{
    auto const foo_string = utils::string{"This is a line"};
    CHECK_NOTHROW( std::cout << foo_string << "\n" );
}

TEST_CASE("check size", "[size]")
{
    auto const first_name = utils::string{"atul"};
    auto last_name = utils::string{"sharma"};
    CHECK( first_name.size() == 4 );
    CHECK( last_name.size() == 6 );
}

TEST_CASE("operator +=", "[modification]")
{
    auto name = utils::string{"Atul"};
    name += utils::string{"Sharma"};

    CHECK( name == utils::string{"AtulSharma"} );
}


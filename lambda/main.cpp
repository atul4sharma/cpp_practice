#include <iostream>
#include <vector>
#include <random>
#include <functional>

//Just a random function
auto generate_random(int start, int end) 
    -> int
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(start, end);
    return uniform_dist(e1);
};

//Overload for the random function
auto generate_random()
    -> int
{
    return generate_random(1, 3000);
};

int main()
{
    auto divisor = 2;

    std::vector<int> v;
    auto loop_count = generate_random(1, 20);

    // lambda function that captures divisor by reference
    auto filter = [&divisor](int value) -> int{
        return value/divisor;
    };

    for(auto i = 0; i < loop_count; ++i)
        v.emplace_back(filter(generate_random()));

    auto counter =  0;
    for( auto const & item : v )
        std::cout << ++counter << " : " << item << "\n";

//lambda function that init captures value // Works with -std=c++14
//    auto divisible_by_two = [value = generate_random()](){
//    auto divisible_by_two = [value = 300](){
    auto divisible_by_two = [](int value){
        std::cout << "number is " << value << " : ";
        return value % 2 == 0;
    };

//    std::cout << std::boolalpha << divisible_by_two() << "\n";
    std::cout << std::boolalpha << divisible_by_two(generate_random()) << "\n";

// std::bind function provides the ability to emulate the init capture for lambda to emulate move construct
    auto func = std::bind(divisible_by_two, generate_random());
    std::cout << std::boolalpha << func() << "\n";

    std::vector<std::function<int(int)>> v2;
    v2.emplace_back( [divisor](int value){
            return value/divisor;
            } );


    return 0;
}

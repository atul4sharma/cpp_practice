#include <iostream>
#include <vector>
#include <random>

auto generate_random(int start, int end) 
    -> int
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(start, end);
    return uniform_dist(e1);
};

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

    auto filter = [&divisor](int value) -> int{
        return value/divisor;
    };

    for(auto i = 0; i < loop_count; ++i)
        v.emplace_back(filter(generate_random()));

    auto counter =  0;
    for( auto const & item : v )
        std::cout << ++counter << " : " << item << "\n";

//    auto divisible_by_two = [value = generate_random()](){
//    auto divisible_by_two = [value = 300](){
    auto divisible_by_two = [](int value){
        std::cout << "number is " << value << " : ";
        return value % 2 == 0;
    };

//    std::cout << std::boolalpha << divisible_by_two() << "\n";
    std::cout << std::boolalpha << divisible_by_two(generate_random()) << "\n";


    return 0;
}

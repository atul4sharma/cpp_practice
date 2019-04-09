
#include "p_queue.hpp"
#include "weight_count_pair.hpp"

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

int main()
{
	
	auto const v = std::vector<weight>{50,60,60,34,56,57,89,78,66,90,90,56,56,72,75};

	auto students_weight = p_queue{v};
	std::cout << students_weight << "\n";

	std::cout << "Average weight is: " << students_weight.average_weight() << "\n";
    
	return 0;
}


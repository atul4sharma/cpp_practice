#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

int left_special_value(std::vector<int> const & v, int index)
{
    auto iter = std::next(v.begin(), index);
    auto riter = std::reverse_iterator<decltype(iter)>{iter};
    auto const ind_val = v[index];
    auto const elem = std::find_if(riter, v.rend(), [v,ind_val](int const a){return a > ind_val;});
    if(elem == v.rend())
    {
        return 0;
    }
        
    auto const val = std::distance(elem, v.rend());
    return val-1;
}

int right_special_value(std::vector<int> const & v, int index)
{
    auto iter = v.begin() + index + 1;
    auto const ind_val = v[index];
    auto const elem = std::find_first_of(iter, v.end(), iter, v.end(), [v,ind_val](int const a, int const _){return a > ind_val; });
    if(elem==v.end())
    {
        return 0;
    }
    auto const val = std::distance(v.begin(), elem);
    return val;
}


int maxSpecialProduct(std::vector<int> &A) {
    
    std::vector<int> special_product{};
    
    for(std::size_t i = 0; i < A.size(); ++i)
    {
        std::cout << "index => " << i << "----> ";
        std::cout << "\nlsv[" << left_special_value(A,i) << "] rsv["<<right_special_value(A,i) << "]";
        special_product.push_back(left_special_value(A, i) * right_special_value(A, i));
        std::cout << "sp => " << special_product[i] << "\n";
    }
    
    auto const item = std::max_element(special_product.begin(), special_product.end());
    return *item;
}


int main()
{
    std::vector<int> A{0,4,4,2,4,4};
    std::cout << "maxproduct => " << maxSpecialProduct(A) << "\n";
}




#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


template <typename ForwardIter, typename Comparator
         ,typename _ = typename std::enable_if<std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<ForwardIter>::iterator_category>::value>::type
         >
auto selection_sort(ForwardIter    first
                   ,ForwardIter    last
                   ,Comparator  && comp)
    -> void
{
    while(first != last)
    {
        auto minimum = std::min_element(first, last, std::forward<Comparator>(comp));
        std::iter_swap(first, minimum);
        ++first;
    }
}

template <typename ForwardIter>
auto selection_sort(ForwardIter first
                   ,ForwardIter last)
    -> void
{
    return selection_sort(first, last, std::less<decltype(*first)>{});
}

int main()
{
    auto v = std::vector<int>{2,124,1,41,3432,4534,5,56756,757,756856,3};
    std::cout << "Original range : ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));    
    selection_sort(v.begin(), v.end(), std::greater<int>{});
    std::cout << "\nAfter sorting  : ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));    
    std::cout << "\n";
}

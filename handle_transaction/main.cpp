
#include <pretty_output/include/print.hpp>

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#define CURRENCY \
    MEMBER(INR) \
    MEMBER(USD) \
    MEMBER(EUR)


#ifndef MEMBER
#define MEMBER(x) x,
enum class currency
{
    CURRENCY
};
#endif

#undef MEMBER
#define MEMBER(x) #x,
inline auto to_string(currency const item)
{
    static std::vector<char const *> const str_equivalent = {
        CURRENCY
    };
    return str_equivalent.at(static_cast<std::underlying_type<decltype(item)>::type>(item));
}

struct amount
{
    long double value;
    currency    curr;

    amount(long double value, currency curr)
        :value{std::move(value)}
        ,curr {std::move(curr) }
    {}

    friend auto operator+=(amount & current, amount const & new_tran)
        -> amount &;

    friend auto operator << (std::ostream & os, amount const & item)
        -> std::ostream &;
};

inline auto operator+=(amount & current, amount const & new_tran)
    -> amount &
{
    if( current.curr == new_tran.curr )
    {
        current.value += new_tran.value;
    }
    else
    {
        // TODO : Try to make this conversion a function for all the available currency
        if( (current.curr == currency::INR) and (new_tran.curr == currency::USD) )
        {
            current.value += new_tran.value * 72;
        }
        else if( (current.curr == currency::USD) and (new_tran.curr == currency::INR) )
        {
            current.value += new_tran.value * (1 / 72);
        }
    }
    return current;
}

inline auto operator + (amount lt, amount const & rt)
    -> amount
{
    lt += rt;
    return lt;
}

inline auto operator << (std::ostream & os, amount const & item)
    -> std::ostream &
{
    os << item.value << " " << to_string(item.curr);
    return os;
}


struct passbook_info
{
    public:
        auto add_transaction(amount item)
        {
            _transactions.emplace_back(std::move(item));
        }
        
        auto add_transactions(std::vector<amount> transactions)
        {
            std::move(transactions.begin(), transactions.end(), std::back_inserter(_transactions));
        }

        auto print_passbook() const 
        {
            println(std::cout << "Transactions => ", _transactions);
            auto temp = std::vector<amount>{};
            std::partial_sum(_transactions.begin(), _transactions.end(), std::back_inserter(temp));
            println(std::cout << "Passbook     => ", temp);
        }

    private:
        std::vector<amount> _transactions{};

};

int main()
{
    auto account_holder = passbook_info{};
    account_holder.add_transactions(std::vector<amount>{
                                                         { 5000, currency::INR}
                                                        ,{-1000, currency::INR}
                                                        ,{  100, currency::USD}
                                                        ,{ 2000, currency::INR}
                                                       });
    account_holder.print_passbook();
    
    return 0;
}

#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

#include <boost/type_index.hpp>
#include <boost/any.hpp>

//https://stackoverflow.com/questions/39173519/template-type-deduction-with-stdfunction
template<typename T>
struct Function
    : public Function<decltype(&T::operator())>
{
};

template <typename ReturnType, typename... Args>
struct Function<ReturnType(Args...)>
{
  using type = std::function<ReturnType(Args...)>;
};

template <typename ReturnType, typename... Args>
struct Function<ReturnType(*)(Args...)>
{
  using type = std::function<ReturnType(Args...)>;
};


template <typename Class, typename ReturnType, typename... Args>
struct Function<ReturnType(Class::*)(Args...) const>
{
  using type = std::function<ReturnType(Args...)>;
};

template <typename F>
auto toFunction(F f ) 
    -> typename Function<F>::type
{
  return {f};
}

template <typename DataType>
struct pipe_t
{
		template <typename ...T>
	    pipe_t(T... f)
	    {
			pipe_t_impl(f...);
		}
		
		template <typename T, typename ...U>
		auto pipe_t_impl(T f, U... f_pack)
			-> void
		{
			auto const function_object = toFunction(f);
			std::cout << "Type deduced => " << boost::typeindex::type_id<decltype(function_object)>().pretty_name() << "\n";
			_functions_to_apply.push_back(function_object);
			pipe_t_impl(f_pack...);
		}
	
		auto pipe_t_impl()
			-> void
		{}

		auto print_all_types() const
			-> void
		{
			for(std::size_t i = 0 ; i < _functions_to_apply.size(); ++i)
			{
				std::cout << "stored type[" << i << "] => " 
						  << boost::typeindex::type_id<decltype(_functions_to_apply[i])>().pretty_name() << "\n";
			}
				
		}
	
	private:
		std::vector<boost::any> _functions_to_apply;
    
};

int func(int, int)
{
    return int{};
}

int main()
{
	auto v = std::vector<int>{23,123,1,4123,12,44235,34,46,4564};
    auto const pipe_var = pipe_t<int>{func, func};
	pipe_var.print_all_types();
	

//    std::cout << boost::typeindex::type_id<decltype(var)>().pretty_name() << "\n";
   return 0; 
}


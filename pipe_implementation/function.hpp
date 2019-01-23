
#pragma once

#include <functional>

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
auto toFunction(F f) 
    -> typename Function<F>::type
{
  return {f};
}



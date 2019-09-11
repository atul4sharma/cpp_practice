#pragma once

#include <string>

struct foo
{
    public:
        explicit foo() = default;

        explicit foo(int a)
            :_a(std::move(a))
        {}

        auto to_string() const -> std::string { return std::to_string(_a); }

    private:
        int _a{0};
};

auto to_string(foo const & item)
    -> std::string
{
    return item.to_string();
}

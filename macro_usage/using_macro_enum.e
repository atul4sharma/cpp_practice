# 1 "using_macro_enum.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "using_macro_enum.cpp"







enum class colors : std::size_t
{
    red, green, blue,
};






std::string to_string(colors const name)
{
    static const char * str_equivalent[] =
    {
        "red", "green", "blue",
    };

    return str_equivalent[static_cast<std::underlying_type<colors>::type>(name)];
}




int main()
{
    return 0;
}

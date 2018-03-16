#define colors_enum\
    func(red)\
    func(green)\
    func(blue)

#define func(x) x,

enum class colors : std::size_t
{
    colors_enum
};

#undef func

#define func(x) #x, 


std::string to_string(colors const name)
{
    static const char * str_equivalent[] = 
    {
        colors_enum
    };

    return str_equivalent[static_cast<std::underlying_type<colors>::type>(name)];
}

#undef func
#undef colors_enum

int main()
{
    return 0;
}

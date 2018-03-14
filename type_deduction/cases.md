
template<typename T>
void func(ParamType param)
{}

------------------------------------------------------

when ParamType is reference or pointer

ie func(T& param)

|passed data | type of param | type of T |
|lvalue      | lvalue        | int       |
|const lvalue| const lvalue  | const lvalue|
|const lvalue ref| const lvalue|const lvalue|


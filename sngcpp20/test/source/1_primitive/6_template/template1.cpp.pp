template <typename _Ty>
struct __vcrt_va_list_is_reference<_Ty&>
{
    enum : bool { __the_value = true };
};


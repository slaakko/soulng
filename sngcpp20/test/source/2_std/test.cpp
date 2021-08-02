template <class _Ty>
struct _Identity {
    using type = _Ty;
};

template <class _Ty>
using _Identity_t = typename _Identity<_Ty>::type;

template<class T, class U>
struct pair
{
	using first_type = T;
	using second_type = U;
	template<class Me = pair, bool, int = 0>
    constexpr pair& operator=(_Identity_t<const Me&> _Right) noexcept
	{
        first  = _Right.first;
        second = _Right.second;
        return *this;
    }
	T first;
	U second;
};

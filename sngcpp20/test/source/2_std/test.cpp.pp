 template <bool>
struct _Select {      template <class _Ty1, class>
    using _Apply = _Ty1;
};

template <>
struct _Select<false> {
    template <class, class _Ty2>
    using _Apply = _Ty2;
};

template <>
struct _Make_signed2<4> {
    template <class _Ty>
    using _Apply =          typename _Select<is_same_v<_Ty, long> || is_same_v<_Ty, unsigned long>>::template _Apply<long, int>;
};



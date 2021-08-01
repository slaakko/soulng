template <class _Ty1, class _Ty2>
concept _Same_impl =      is_same_v<_Ty1, _Ty2>;

template <class _Ty1, class _Ty2>
concept same_as = _Same_impl<_Ty1, _Ty2> && _Same_impl<_Ty2, _Ty1>;

template <class _Derived, class _Base>
concept derived_from = __is_base_of(_Base, _Derived)
    && __is_convertible_to(const volatile _Derived*, const volatile _Base*);

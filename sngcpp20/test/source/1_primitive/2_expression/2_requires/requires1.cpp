template<typename T>
concept R = requires(T i)
{
    typename T::type;
    {*i} -> std::convertible_to<const typename T::type&>;
};

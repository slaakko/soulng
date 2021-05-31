template <typename T> concept C = requires(T x)
{
    {*x} -> std::same_as<typename T::inner>;
};


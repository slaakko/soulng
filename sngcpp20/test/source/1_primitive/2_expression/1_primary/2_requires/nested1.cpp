template <typename U> concept C = sizeof(U) == 1;

template <typename T> concept D = requires(T t)
{
    requires C<decltype(+t)>;
};

template <typename T> concept C = requires(T x)
{
    { x++ };
};

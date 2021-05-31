template <typename T>
concept C = requires(T x)
{
    { g(x) } noexcept;
};

namespace std
{
    template<class T, class U>
    class pair
    {
    public:
        pair(const T&, const U&);
        T first;
        U second;
    };
    
    template<class T, class U>
    pair<T, U> make_pair(const T&, const U&);
}

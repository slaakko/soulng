namespace std
{
    template<class T, class U>
    class map
    {
    public:
        typedef type iterator;
        typedef type const_iterator;
        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;
        void clear();
        int size() const;
        const_iterator find(const T&) const;
        pair<iterator, bool> insert(const pair<T, U>&);
        bool empty() const;
        void erase(iterator pos);
        void erase(const T&);
    };
}

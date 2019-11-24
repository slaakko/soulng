namespace std
{
    template<class T>
    class set
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
        pair<iterator, bool> insert(const T&);
        bool empty() const;
        void erase(iterator pos);
        void erase(const T&);
    };
}

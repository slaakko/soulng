namespace std
{
    template<class T>
    class list
    {
    public:
        typedef type iterator;
        typedef type const_iterator;
        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;
        const T& front() const;
        const T& back() const;
        void push_back(const T&);
        void pop_back();
        bool empty() const;
        void clear();
        iterator insert(iterator, const T&); 
        iterator erase(iterator);
    };
}

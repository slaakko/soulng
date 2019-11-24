namespace std
{
    template<class T>
    class vector
    {
    public:
        typedef type iterator;
        typedef type const_iterator;
        vector();
        vector(int, const T&);
        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;
        const T& front() const;
        const T& back() const;
        T operator[](int);
        bool empty() const;
        int size() const;
        void reserve(int);
        void clear();
        void push_back(const T&);
        void pop_back();
        void resize(int);
    };
}

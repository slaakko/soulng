namespace std
{
    template<class T>
    class unique_ptr
    {
    public:
        unique_ptr();
        unique_ptr(T* p);
        unique_ptr(unique_ptr<T>&&);
        T* release();
        void reset();
        void reset(T* p);
        void swap(unique_ptr<T>&);
        T* get();
        T& operator*() const;
        T* operator->() const;
    };
} // namespace std

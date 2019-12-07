namespace std
{
    template<class T>
    class stack
    {
    public:
        const T& top();
        void push(const T&);
        void pop();
    };    
}

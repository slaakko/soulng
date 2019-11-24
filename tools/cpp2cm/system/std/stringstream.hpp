namespace std
{
    template<class T>
    class basic_stringstream
    {
    public:
        basic_string<T> str() const;
        void str(const basic_string<T>& newStr);
    };
    
    typedef basic_stringstream<char> stringstream;
}

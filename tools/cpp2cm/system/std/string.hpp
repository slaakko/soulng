namespace std
{
    template<class CharT>
    class basic_string
    {
    public:
        typedef type iterator;
        typedef type const_iterator;
        basic_string(int, CharT);
        basic_string(const CharT*);
        basic_string(const CharT* begin, const CharT* end);
        const_iterator begin() const;
        const_iterator end() const;
        const  CharT* data() const;
        const  CharT* c_str() const;
        bool empty() const;
        int size() const;
        int length() const;
        void clear();
        void reserve(int length);
        basic_string<CharT>& append(int, CharT);
        basic_string<CharT>& append(const CharT*);
        basic_string<CharT>& append(const basic_string<CharT>&);
        basic_string<CharT> substr(int);
        basic_string<CharT> substr(int, int);
    };
    
    typedef basic_string<char> string;
    typedef basic_string<char16_t> u16string;
    typedef basic_string<char32_t> u32string;
    
    string to_string(int);
}

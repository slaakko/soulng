namespace std
{
    class ostream
    {
    public:
        ostream& ostream(const ostream&) = delete;
        ostream& operator=(const ostream&) = delete;
    };
}

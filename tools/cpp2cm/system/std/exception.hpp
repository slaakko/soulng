namespace std
{
    class runtime_error
    {
    public:
        runtime_error(const std::string& what_);
        runtime_error(const char* what_);
        const char* what() const;
    };
}

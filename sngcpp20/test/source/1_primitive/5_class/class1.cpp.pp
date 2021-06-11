class C
{
public:
    void foo(int x);
    void bar(void* p)
    {
        for (int i = 0; i < 3; ++i)
        {
            int y = i;
        }
    }
};

void C::foo(int x)
{
    int k = 0;
}


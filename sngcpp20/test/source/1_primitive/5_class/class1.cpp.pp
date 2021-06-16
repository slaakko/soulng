class B
{
public:
    int x;
};

class C : public B
{
public:
    void foo(int x);
    void bar(void* p)
    {
        Foo x;
    }
private:
    typedef int Foo;
    using B::x;
};

void C::foo(int y)
{
    int k = 0;
}


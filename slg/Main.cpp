#include <iostream>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/InitDone.hpp>
#include <stdio.h>
#include <fstream>

struct InitDone
{
    InitDone()
    {
        soulng::util::Init();
    }
    ~InitDone()
    {
        soulng::util::Done();
    }
};

void Emit(std::ostream& s, int start, int end)
{
    s << "idCont->AddSymbol(context.MakeRange(static_cast<char32_t>(" + std::to_string(start) + "), static_cast<char32_t>(" + std::to_string(end) + ")));" << std::endl;
}

int main()
{
    InitDone initDone;
    int n = 0x0010FFFF;
    std::ofstream testhpp("test.hpp");
    //testhpp << "extern int charMap[];" << std::endl;
    //std::ofstream testcpp("test.cpp");
    //testcpp << "int charMap[] = {";
    int state = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; ++i)
    {
        char32_t c = static_cast<char32_t>(i);
        switch (state)
        {
            case 0:
            {
                if (soulng::unicode::IsIdCont(c) || soulng::unicode::IsAsciiDigit(c) || c == '_')
                {
                    state = 1;
                    start = i;
                }
                break;
            }
            case 1:
            {
                if (!(soulng::unicode::IsIdCont(c) || soulng::unicode::IsAsciiDigit(c) || c == '_'))
                {
                    end = i - 1;
                    Emit(testhpp, start, end);
                    state = 0;
                }
                break;
            }
        }
    }
    if (state = 1)
    {
        end = n - 1;
        Emit(testhpp, start, end);
    }

    //testcpp << "};" << std::endl;
}

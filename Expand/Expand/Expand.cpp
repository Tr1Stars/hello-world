// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#include <iostream>
#include "windows.h"
//#include "MathLibrary.h"

int main()
{
    HMODULE hDLL = LoadLibrary(L"D:/VS项目/MathLibrary/Debug/MathLibrary.dll");

    if (hDLL == NULL)
    {
        std::cout << "获取动态链接库失败！";
        return 0;
    }
    
    typedef void (*PINIT)(const unsigned long long a, const unsigned long long b);
    typedef unsigned (*PINDEX)();
    typedef unsigned long long (*PCURRENT)();
    typedef bool (*PNEXT)();

    PINIT fibonacci_init = (PINIT)GetProcAddress(hDLL, "fibonacci_init");
    PINDEX fibonacci_index = (PINDEX)GetProcAddress(hDLL, "fibonacci_index");
    PCURRENT fibonacci_current = (PCURRENT)GetProcAddress(hDLL, "fibonacci_current");
    PNEXT fibonacci_next = (PNEXT)GetProcAddress(hDLL, "fibonacci_next");
    //使用函数
    if (fibonacci_init != NULL && fibonacci_index != NULL && fibonacci_current != NULL && fibonacci_next != NULL)
    {
        fibonacci_init(20, 10);
        // Initialize a Fibonacci relation sequence.
        //fibonacci_init(1, 1);
        // Write out the sequence values until overflow.
        do {
            std::cout << fibonacci_index() << ": "
                << fibonacci_current() << std::endl;
        } while (fibonacci_next());
        // Report count of values written before overflow.
        std::cout << fibonacci_index() + 1 <<
            " Fibonacci sequence values fit in an " <<
            "unsigned 64-bit integer." << std::endl;
    }
    FreeLibrary(hDLL);

}

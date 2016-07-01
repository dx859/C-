#include "stdio.h"
#include <iostream>
using namespace std;

// //template 告诉C++编译器 我要开始泛型编程了 .看到T, 不要随便报错
template <typename T>
void myswap(T &a, T &b)
{
    T c = 0;
    c = a;
    a = b;
    b = c;
}

int main()
{
    // 显示调用
    {
        int x = 10;
        int y = 20;

        myswap<int>(x, y);
        printf("x:%d,y:%d\n", x, y);

        char a = 'a';
        char b = 'b';

        myswap<char>(a, b);
        printf("a:%c,b:%c\n", a, b);
    }

    // 自动类型推导调用
    {
        int x = 10;
        int y = 20;

        myswap(x, y);
        printf("x:%d,y:%d\n", x, y);

        char a = 'a';
        char b = 'b';

        myswap(a, b);
        printf("a:%c,b:%c\n", a, b);
    }

    return 0;
}

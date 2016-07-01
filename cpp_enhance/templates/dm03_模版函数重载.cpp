#include <iostream>
using namespace std;

template <typename T>
void myswap(T &a, T &b)
{
    T c = 0;
    c = a;
    a = b;
    b = c;
    cout << "模版函数" << endl;
}

void myswap(int a, char c)
{
    cout << "我是普通函数" << endl;
}

int main()
{
/*
    1 函数模板可以像普通函数一样被重载
    2 C++编译器优先考虑普通函数
    3 如果函数模板可以产生一个更好的匹配，那么选择模板
    4 可以通过空模板实参列表的语法限定编译器只通过模板匹配

 函数模板机制结论
    编译器并不是把函数模板处理成能够处理任意类的函数
    编译器从函数模板通过具体类型产生不同的函数
    编译器会对函数模板进行两次编译
    在声明的地方对模板代码本身进行编译；在调用的地方对参数替换后的代码进行编译。
*/
    int a = 10;
    char c = 'z';

    myswap(a, c);
    myswap(a, a);

    return 0;
}

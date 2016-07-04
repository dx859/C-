#include <iostream>
using namespace std;

/*
    模版类：类模板用于实现类所需数据的类型参数化
*/
template <class T> class A
{
public:
    A(T a)
    {
        this->a = a;
    }
    virtual void print()
    {
        cout << "a: " << a << endl;
    }
protected:
    T a;
};

/*
    从模板类 派生了 普通类
        模板类派生时, 需要具体化模板类. C++编译器需要知道 父类的数据类型具体是什么样子的

    =====> 要知道父类所占的内存大小是多少 只有数据类型固定下来,才知道如何分配内存
 */
class B : public A<int>
{
public:
    B(int a=10, int b=20) : A<int>(a)
    {
        this->b = b;
    }
    void print()
    {
        cout << "a: " << a << " b: " << b << endl;
    }
private:
    int b;
};

/*

从模板类 派生 模板类
 */
template <typename T> class C : public A<T>
{
public:
    C(T c, T a) : A<T>(a)
    {
        this->c = c;
    }
    virtual void print()
    {
        cout << "c: " << c << endl;
    }
protected:
    T c;
};

int main()
{
    A<int> a1(1);
    a1.print();

    A<string> a2("你好");
    a2.print();

    B b1(1, 2);
    b1.print();

    B b2; // 自动调用B(int a=10, int b=20) : A<int>(a)
    b2.print();

    C<int> c(3, 4);
    c.print();

    return 0;
}

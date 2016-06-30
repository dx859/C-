#include <iostream>
using namespace std;

/*
当子类成员变量与父类成员变量同名时
1 子类依然从父类继承同名成员
2 在子类中通过作用域分辨符::进行同名成员区分（在派生类中使用基类的同名成员，显式地使用类名限定符） 
3 同名成员存储在内存中的不同位置
*/
class A
{
public:
    int a;
    int b;
public:
    void get()
    {
        cout<<"b "<<b<<endl;
    }
    void print()
    {
        cout<<"AAAAA "<<endl;
    }
protected:
private:
};

class B : public A
{
public:
    int b;
    int c;
public:
    void get_child()
    {
        cout<<"b "<<b<<endl;
    }
    void print()
    {
        cout<<"BBBB "<<endl;
    }
protected:
private:
};


//同名成员变量
int main()
{
    
    B b1;
    b1.b = 1; //
    b1.get_child();

    b1.A::b = 100; //修改父类的b
    b1.B::b = 200; //修改子类的b 默认情况是B

    b1.get();


    cout<<"hello..."<<endl;

    return 0;
}
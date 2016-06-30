
#include <iostream>
using namespace std;

//构造函数中调用虚函数能发生多态吗?
// 多态是用父类指针指向子类对象

class Parent
{
public:
    Parent(int a=0)
    {
        this->a = a;
        print();
    }

    virtual void print()
    {
        cout<<"我是爹"<<endl;
    }

private:
    int a;
};

class Child : public Parent
{
public:
    Child(int a = 0, int b=0):Parent(a)
    {
        this->b = b;
        print();
    }

    virtual void print()
    {
        cout<<"我是儿子"<<endl;
    }
private:
    int b;
};

void HowToPlay(Parent *base)
{
    base->print(); //有多态发生  //2 动手脚

}

int main()
{
    Child c;

    HowToPlay(&c);

    return 0;
}

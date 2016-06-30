#include <iostream>
using namespace std;

/*
原则：
    先构造父类，再构造成员变量、最后构造自己
    先析构自己，在析构成员变量、最后析构父类
    //先构造的对象，后释放
*/

class Object
{
public:
    Object(int a, int b)
    {
        this->a = a;
        this->b = b;
        cout << "Object构造函数" << endl;
    }
    ~Object()
    {
        cout << "Object析构函数" << endl;
    }
private:
    int a;
    int b;
};

class Parent : public Object
{
public:
    Parent(char *p) : Object(1, 2)
    {
        this->p = p;
        cout << "父类构造函数" << endl;
    }
    ~Parent()
    {
        cout << "父类析构函数" << endl;
    }
protected:
    char *p;

};

class Child : public Parent
{
public:
    Child(char *p) : Parent(p), obj1(3, 4) , obj2(5, 6)
    {
        this->cp = p;
        cout << "父类析构函数" << endl;
    }
    ~Child()
    {
        cout << "子类析构函数" << endl;
    }
private:
    char *cp;
    Object obj1;
    Object obj2;
};

int main()
{
    Child c("继承测试");

    return 0;
}

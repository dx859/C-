
#include <iostream>
using namespace std;


class Parent1
{
public:
    Parent1(int a=0)
    {
        this->a = a;
    }

    void print()
    {
        cout<<"我是爹"<<endl;
    }
private:
    int a;
};

class Parent2
{
public:
    Parent2(int a=0)
    {
        this->a = a;
    }

    virtual void print()
    {
        cout<<"我是爹"<<endl;
    }
private:
    int a;
};

int main()
{
    printf("sizeof(Parent):%d sizeof(Parent2):%d \n", sizeof(Parent1), sizeof(Parent2));

    return 0;
}

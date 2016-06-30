#include <iostream>
#include "string.h"
using namespace std;

class A
{
public:
    A()
    {
        p = new char[20];
        strcpy(p, "pbja");
        printf("A()\n");
    }
    virtual ~A()
    {
        delete [] p;
        printf("~A()\n");
    }
private:
    char *p;
};

class B : public A
{
public:
    B()
    {
        p = new char[20];
        strcpy(p, "objb");
        printf("B()\n");
    }
    ~B()
    {
        delete [] p;
        printf("~B()\n");
    }
private:
    char *p;
};

class C : public B
{
public:
    C()
    {
        p = new char[20];
        strcpy(p, "objc");
        printf("C()\n");
    }
    ~C()
    {
        delete [] p;
        printf("~C()\n");
    }
private:
    char *p;
};

int main()
{
    C *c = new C;
    delete c;

    system("pause");
    return 0;
}

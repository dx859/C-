#include <iostream>

using namespace std;

class Parent
{
public:
    int a;
protected:
    int b;
private:
    int c;

};

class Child : public Parent
{
public:
    void useVar()
    {
        int a;
        int b;
        // int c; // error
    }
};

int main()
{
    Child c;
    c.useVar();
    c.a;
    // c.b; // error
    // c.c; // error

    return 0;
}

#include <iostream>
using namespace std;

/*
异常被抛出后，从进入try块起，到异常被抛掷前，这期间在栈上的构造的所有对象，都会被自动析构。析构的顺序与构造的顺序相反。这一过程称为栈的解旋(unwinding)
 */

class Test
{
public:
    Test(int a=0, int b = 0)
    {
        this->a = a;
        this->b = b;
        cout << "Test构造函数执行：" << "a: " << a << "b: " << b << endl;
    }

    ~Test()
    {
        cout << "Test析构函数执行：" << "a: " << a << "b: " << b << endl;
    }
private:
    int a;
    int b;

};

// 函数后面写throw，表示只能抛出所列出的异常
void myDivide() throw(int, char, char *)
{
    Test t1(1, 2), t2(3, 4);
    cout << "要发生异常了" << endl;
    throw 1;
}

//不写,可以抛出任何类型
void myDivide2()
{
    Test t1(1, 2), t2(3, 4);
    cout << "要发生异常了" << endl;
    throw "ddzz";
}

// 不抛出异常
void myDivide3() throw()
{
    Test t1(1, 2), t2(3, 4);
    cout << "要发生异常了" << endl;
    throw 1;
}

int main()
{
    try {
        myDivide();
    } catch (int e) {
        cout << "int 类型异常：" << e << endl;
    } catch (...) {
        cout << "未知异常" << endl;
    }

    return 0;
}

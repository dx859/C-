#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Teacher
{
public:
    Teacher(int age)
    {
        if (age > 100) {
            string s = "年龄太大";
            throw out_of_range(s); // out_of_range 是 <stdexcept>中的标准异常
        }
        this->age = age;
    }
private:
    int age;
};

// 自定义派生exception的异常类
class MyException : public exception
{
public:
    MyException(const char *p)
    {
        this->m_p = p;
    }
    virtual const char* what()
    {
        cout << "MyException类型: " << m_p << endl;
        return m_p;
    }
private:
    const char *m_p;

};

void testMyExcept()
{
    throw MyException("函数异常"); // 如果抛出的是对象，就是引用。
}

int main()
{
    try {
        Teacher t(102);
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }

    try {
        testMyExcept();
    } catch (MyException &e) {
        e.what();
    } catch (...) {
        cout << "未知异常" << endl;
    }

    return 0;
}

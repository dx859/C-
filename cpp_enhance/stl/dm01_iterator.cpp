#include <iostream>
#include <vector>
#include <algorithm>
#include "string.h"
using namespace std;

//容器中 装 基础数据类型变量
void test1()
{
    // 1. 容器
    vector<int> v;
    v.push_back(-1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(3);

    // 2. 迭代器 相当于一个指针 分类
    for (vector<int>::iterator it=v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 3. 算法
    // count是<algorithm>库中的函数：这个函数使用一对迭代器和一个值做参数，返回这个值出现次数的统计结果
    int num = count(v.begin(), v.end(), 3);
    cout << "num: " << num << endl;

}

class Teacher
{
public:
    int age;
    char name[64];

public:
    Teacher(const char *name, int age)
    {
        this->age = age;
        strcpy(this->name, name);
    }
};

//容器中 装 对象
void test2()
{
    Teacher t1("zhangsan", 44), t2("lisi", 33), t3("wangwu", 38);

    vector<Teacher> v;
    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);

    for (vector<Teacher>::iterator it = v.begin(); it != v.end(); it++)
        cout << it->name << " age:" << it->age << endl;
}

//容器中 装 指针
void test3()
{
    Teacher t1("zhangsan", 44), t2("lisi", 33), t3("wangwu", 38);
    Teacher *p1, *p2, *p3;
    p1 = &t1;
    p2 = &t2;
    p3 = &t3;

    vector<Teacher *> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<Teacher *>::iterator it = v.begin(); it != v.end(); it++)
        cout << (*it)->name << endl;
}


int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}

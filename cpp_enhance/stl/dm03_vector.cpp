#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(vector<T> &v)
{
    /*
    1、首先类除了可以定义数据成员或函数成员之外，还可以定义类型成员。
    2、使用std::vector<T>::const_iterator时，编译器假定这样的名字指定的时数据成员，而不是数据类型。
    3、如果希望编译器将const_iterator当做类型，则必须显示告诉编译器这样做，这就是我们加typename的原因
     */
    for (typename vector<T>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

/*
push_back()
pop_back()
front()
back()
 */
void test1()
{
    vector<int> v;
    cout << "length: " << v.size() << endl;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    cout << "length: " << v.size() << endl;

    cout << "第一个元素: " << v.front() << endl;
    cout << "最后一个元素: " << v.back() << endl;

    //函数返回值当左值 应该返回一个引用
    v.front() = 11;
    v.back() = 55;

    cout << "第一个元素: " << v.front() << endl;
    cout << "最后一个元素: " << v.back() << endl;

    while (v.size() > 0) {
        cout << "尾部元素：" << v.back() << endl;
        v.pop_back(); // 删除尾部元素
    }
}

// vector的初始化
void test2()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int> v2 = v; // 对象初始化
    vector<int> v3(v.begin(), v.begin() + 2);

    printVector(v);
    printVector(v2);
    printVector(v3);
}

void test3()
{
    vector<int> v1(10);   //提前把内存准备好
    v1.push_back(100);
    v1.push_back(200);
    cout << "size: " << v1.size() << endl; // size: 12
    printVector(v1);
}

// 正反向遍历
void test4()
{
    vector<int> v(10);
    for (int i=0; i<10; i++)
        v[i] = i + 1;

    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << " ";

    cout << endl;

    for (vector<int>::reverse_iterator rit=v.rbegin(); rit!=v.rend(); rit++)
        cout << *rit << " ";

    cout << endl;
}

//vector 添加，删除，修改
void test5()
{
    vector<int> v(10);
    for (int i=0; i<10; i++)
        v[i] = i + 1;

    // 区间删除
    v.erase(v.begin(), v.begin()+3);
    printVector(v);

    // 根据元素位置，指定删除
    v.erase(v.begin());
    printVector(v);

    // 修改元素的值
    v[1] = 2;
    v[3] = 2;
    printVector(v);
    // 当 删除迭代器所指向的元素的时候,erase删除函数会让it自动下移动
    for (vector<int>::iterator it=v.begin(); it!=v.end();) {
        if (*it==2)
            it = v.erase(it);
        else
            it++;
    }

    printVector(v);

    v.insert(v.begin()+1, 200);
    v.insert(v.end() - 1, 200);
    printVector(v);
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    return 0;
}

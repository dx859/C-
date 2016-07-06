#include <iostream>
#include <map>
#include <string>
using namespace std;

map<int, string> createMap()
{
    map<int, string> m;
    // 方法1
    m.insert(pair<int, string>(1, "张三"));
    m.insert(pair<int, string>(2, "李四"));

    // 方法2
    m.insert(make_pair(3, "王五"));
    m.insert(make_pair(4, "赵六"));

    // 方法3
    m.insert(map<int, string>::value_type(5, "田七"));
    m.insert(map<int, string>::value_type(6, "孙八"));

    // 方法4
    m[7] = "钱九";
    m[8] = "李十";

    return m;
}

template <typename T1, typename T2>
void printM(map<T1, T2> &m)
{
    for (typename map<T1, T2>::iterator it=m.begin(); it!=m.end(); it++)
        cout << it->first << ": " << it->second << endl;
}

// map容器插入的四种方法
void test1()
{
    map<int, string> m;

    // 方法1
    m.insert(pair<int, string>(1, "张三"));
    m.insert(pair<int, string>(2, "李四"));

    // 方法2
    m.insert(make_pair(3, "王五"));
    m.insert(make_pair(4, "赵六"));

    // 方法3
    m.insert(map<int, string>::value_type(5, "田七"));
    m.insert(map<int, string>::value_type(6, "孙八"));

    // 方法4
    m[7] = "钱九";
    m[8] = "李十";

    // 遍历map容器
    for (map<int, string>::iterator it=m.begin(); it!=m.end(); it++)
        cout << it->first << ": " << it->second << endl;
    cout << "..." << endl;
}

// 前面三种方法如果key已存在，会报错，后面一种直接赋值，如果key相同就会把值直接覆盖
// map.insert 会返回pair<iterator, bool>类型
void test2()
{
    map<int, string> m;

    // 方法1
    m.insert(pair<int, string>(1, "张三"));
    m.insert(pair<int, string>(2, "李四"));

    // 方法2
    m.insert(make_pair(3, "王五"));
    m.insert(make_pair(4, "赵六"));

    // 方法3
    pair<map<int, string>::iterator, bool> mypair5 = m.insert(map<int, string>::value_type(5, "田七"));

    if (mypair5.second != true)
        cout << "key 5 插入失败" << endl;
    else
        cout << mypair5.first->first << ": " << mypair5.first->second << endl;

    pair<map<int, string>::iterator, bool> mypair6 = m.insert(map<int, string>::value_type(5, "孙八"));

    if (mypair6.second != true)
        cout << "key 6 插入失败" << endl;
    else
        cout << mypair6.first->first << ": " << mypair6.first->second << endl;

    // 方法4
    m[7] = "钱九";
    m[8] = "李十";

    // 遍历map容器：迭代器通过it->first, it->second取得key和value
    for (map<int, string>::iterator it=m.begin(); it!=m.end(); it++)
        cout << it->first << ": " << it->second << endl;
    cout << "..." << endl;
}

// map的查找，异常处理
void test3()
{
    map<int, string> m = createMap();

    map<int, string>::iterator it = m.find(100);

    if (it == m.end())
        cout << "key 100 不存在" << endl;
    else
        cout << it->first << ": " << it->second << endl;

    //返回两个迭代器 形成一个pair
    //第一个迭代器 >= 5的 位置
    //第一个迭代器 = 5的 位置
    pair<map<int, string>::iterator, map<int, string>::iterator> mypair = m.equal_range(5);

    if (mypair.first == m.end())
        cout << "第一个迭代器 >= 5的 位置 不存在" << endl;
    else
        cout << mypair.first->first << " :" << mypair.first->second << endl;

    if (mypair.second == m.end())
        cout << "第一个迭代器 > 5的 位置 不存在" << endl;
    else
        cout << mypair.second->first << " :" << mypair.second->second << endl;

    cout << "..." << endl;
    printM(m);
}

int main()
{
    test3();

    return 0;
}

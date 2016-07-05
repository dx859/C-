#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*

1. deque是“double-ended queue”的缩写，和vector一样都是STL的容器，deque是双端数组，而vector是单端的。
2. deque在接口上和vector非常相似，在许多操作的地方可以直接替换
3. deque可以随机存取元素
4. deque头部和尾部添加或移除元素都非常快速。但是在中部安插元素或移除元素比较费时
 */

template <typename T>
void printD(deque<T> &d)
{
    for (typename deque<T>::iterator it=d.begin(); it!=d.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(3);
    d1.push_back(5);

    d1.push_front(-11);
    d1.push_front(-33);
    d1.push_front(-55);
    cout << endl;

    cout << "头部元素:" << d1.front() <<endl;
    cout << "尾部元素:" << d1.back() << endl;
    printD(d1);

    d1.pop_front();
    d1.pop_back();
    printD(d1);
    cout <<endl;

    // 查找 -33的下标
    deque<int>::iterator it = find(d1.begin(), d1.end(), -33);

    if (it != d1.end())
        cout << "-33的下标是：" << distance(d1.begin(), it) << endl;
    else
        cout << "没有找到值为-33的元素" << endl;

    return 0;
}

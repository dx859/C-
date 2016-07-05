#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// string的遍历
void test1()
{
    string s= "abcdefg";

    // 1. 数组方式
    for (int i=0; i<s.length(); i++)
        cout << s[i] << " " ;

    cout << endl;

    // 2. 迭代器方式
    for (string::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << " ";

    cout << endl;
}

// 字符串的连接
void test2()
{
    string s1 = "aaa";
    string s2 = "bbb";
    s1 = s1 + s2;
    cout << "s1: " << s1 << endl;

    string s3 = "333";
    string s4 = "444";
    s3.append(s4);
    cout << "s3: " << s3 << endl;
}

// 字符串的长度：int length() const; bool empty() const;

// 字符串的查找和替换
void test3()
{
    string s1 = "wbm hello wbm 111  wbm 222  wbm 333 ";

    // int find(char c,int pos=0) const; pos开始查找字符c在当前字符串的位置
    // find函数如果查找不到，就返回-1(string::npos)
    int index = s1.find("wbm", 0);
    cout << "index: " << index << endl;

    // 求wbm的次数，每次出现的下标
    int offindex = s1.find("wbm", 0);
    while (offindex != string::npos) {
        cout << "offindex: " << offindex << endl;
        offindex = offindex + 1;
        offindex = s1.find("wbm", offindex);
    }

    // 把wbm替换成WBM
    offindex = s1.find("wbm", 0);
    while (offindex != string::npos) {
        s1.replace(offindex, 3, "WBM");
        offindex = s1.find("wbm", ++offindex);
    }
    cout << s1 << endl;

}

//截断（区间删除）和插入
void test4()
{
    /*
    string &insert(int pos, const char *s);
    string &insert(int pos, const string &s);
    //前两个函数在pos位置插入字符串s
    string &insert(int pos, int n, char c);  //在pos位置 插入n个字符c

    string &erase(int pos=0, int n=npos);  //删除pos开始的n个字符，返回修改后的字符串
     */

    string s1 = "hello1 hello2 helllo1";
    string::iterator it = find(s1.begin(), s1.end(), '1');
    if (it != s1.end())
        s1.erase(it);

    cout << s1 << endl;

    s1.erase(s1.begin(), s1.end());
    cout << "s1全部删除:" << s1 << endl;
    cout << "s1长度 " << s1.length() << endl;

    string s2 = "BBB";
    s2.insert(0, "AAA");
    s2.insert(s2.length(), "CCC");
    cout << s2 << endl;
}

void test5()
{
    // linux 下toupper是宏不是函数
    string s1 = "AAAbbb";
    //1函数的入口地址 2函数对象 3预定义的函数对象
    transform(s1.begin(), s1.end(), s1.begin(), (int (*)(int))toupper);
    cout << "s1:" << s1 << endl;

    string s2 = "AAAbbb";
    transform(s2.begin(), s2.end(), s2.begin(), (int (*)(int))tolower);
    cout << "s2:" << s2 << endl;
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

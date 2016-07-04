#include <iostream>
#include <string>
using namespace std;

/*
标准输入流对象cin
    cin.get() //一次只能读取一个字符
    cin.get(一个参数) //读一个字符
    cin.get(三个参数) //可以读字符串
    cin.getline()
    cin.ignore()
    cin.peek()
    cin.putback()
*/

void cinTest()
{
    int  myInt;
    long myLong;
    char mybuf[1024];

    cin >> myInt;
    cin >> myLong;
    cin >> mybuf; // 遇见空格停止接受 数据

    cout << "myInt:"  << myInt  << endl;
    cout << "myLong:" << myLong << endl;
    cout << "mybuf:"  << mybuf  << endl;
}

void getTest()
{
    char ch;
    // const int EOF = -1;
    while ( (ch=cin.get()) != EOF ) {
        cout << ch << endl;
    }
}

void get2Test()
{
    char a, b, c;

    cin.get(a);
    cin.get(b);
    cin.get(c);

    cout << a << b << c << endl;

    cout << "..." << endl;

    cin.get(a).get(b).get(c);
    cout << a << b << c << endl;
}

void getlineTest()
{
    char buf1[256] , buf2[256];

    cout << "请输入一个字符串 含有多个空格 aa bb cc dd\n";

    cin >> buf1;

    cin.getline(buf2, 256);

    cout << "buf1: " << buf1 << endl;
    cout << "buf2: " << buf2 << endl;
}

void ignoreTest()
{
    char buf1[256];
    char buf2[256];

    cout << "请输入一个字符串 含有多个空格aa  bbccdd\n";

    cin >> buf1;
    cin.ignore(20);
    int myint = cin.peek();
    cout << "myint:" << myint << endl;

    cin.getline(buf2, 256);

    cout << "buf1:" << buf1 << "\nbuf2:" << buf2 << endl;
}

int main()
{
    // cinTest();
    // getTest();
    // get2Test();
    // getlineTest();
    // ignoreTest();

    return 0;
}

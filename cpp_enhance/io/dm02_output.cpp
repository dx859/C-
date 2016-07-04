#include <iostream>
#include <iomanip>
#include "string.h"
using namespace std;


/*

标准输出流对象cout
    cout.flush()
    cout.put()
    cout.write()
    cout.width()
    cout.fill()
    cout.setf(标记)
    */

/*
manipulator(操作符、控制符)
flush
endl
oct
dec
hex
setbase
setw
setfill
setprecision
…
*/


// cout.put , cout.write;
void test1()
{
    cout.put('h').put('e').put('1'); // 一个一个字符输出

    cout << "\n..." << endl;

    const char *p = "hello";

    cout.write(p, strlen(p)) << endl;
    cout.write(p, strlen(p) - 4) << endl;
    cout.write(p, strlen(p) + 4) << endl;
}

void test2()
{
    cout << "<Start>";
    cout.width(30); // 开辟30个空间
    cout.fill('*'); // 在每个空间填充 *

    cout << hex << 123 << "<End>\n"; // 16进制输出

    cout    << "<Start>"
            << setw(30)
            << setfill('*')
            << setiosflags(ios::showbase) //基数
            << setiosflags(ios::internal)
            << hex
            << 123
            << "<End>\n"
            << endl;
}

void test3()
{
    int a;
    cout<<"input a:";
    cin>>a;
    cout<<"dec:"<<dec<<a<<endl; //以十进制形式输出整数
    cout<<"hex:"<<hex<<a<<endl; //以十六进制形式输出整数a
    cout<<"oct:"<<setbase(8)<<a<<endl; //以八进制形式输出整数a
    const char *pt="China"; //pt指向字符串"China"
    cout<<setw(10)<<pt<<endl; //指定域宽为,输出字符串
    cout<<setfill('*')<<setw(10)<<pt<<endl; //指定域宽,输出字符串,空白处以'*'填充
    double pi=22.0/7.0; //计算pi值
    //按指数形式输出,8位小数
    cout<<setiosflags(ios::scientific)<<setprecision(8);
    cout<<"pi="<<pi<<endl; //输出pi值
    cout<<"pi="<<setprecision(4)<<pi<<endl; //改为位小数
    cout<<"pi="<<setiosflags(ios::fixed)<<pi<<endl; //改为小数形式输出
}

void test4()
{
    double a=123.456,b=3.14159,c=-3214.67;
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2); // 填充，右对其，保留两位小数
    /*
        123.46
          3.14
      -3214.67
     */
    cout<<setw(10)<<a<<endl;
    cout<<setw(10)<<b<<endl;
    cout<<setw(10)<<c<<endl;

}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}

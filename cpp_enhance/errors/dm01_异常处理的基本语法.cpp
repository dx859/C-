#include <iostream>
using namespace std;

/*
    1 基本语法
    2 发生异常之后,是跨函数 :
    3 接受异常以后 可以不处理 再抛出异常
    4 catch异常的时 按照类型进行catch
    5 异常捕捉严格按照类型匹配
 */
int main1()
{
    try {
        // throw 12;
        throw 'Z';
    } catch (int e) {
        cout << "捕获int类型的异常" << endl;
    } catch (...) {
        cout << "未知类型的异常" << endl;
    }

    return 0;
}


void divide(int x, int y)
{
    if (y == 0) {
        throw x; // 抛出 int 类型的异常
    }

    cout << "divide结果" << x/y << endl;
}

void myDivide(int x, int y)
{
    try {
        divide(x, y);
    } catch (...) {
        cout << "我接受了divide的异常，但我没有处理，继续抛出" << endl;
        throw;
    }
}

int main()
{

    try {
        divide(2 , 0);
    } catch (...) {
        cout << "接受divide的异常" << endl;
    }

    try {
        myDivide(100, 0);
    } catch (int e) {
        cout << e << "被0除" << endl;
    } catch (...) {
        cout << "其他未知类型错误" << endl;
    }

    return 0;
}

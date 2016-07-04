#include <iostream>
#include <fstream>
#include "string.h"
using namespace std;

// 写文件
void test_fout()
{
    const char *fname = "D:/cpp_file_test.txt";
    ofstream fout(fname, ios::app); //建一个 输出流对象 和文件关联;

    if (!fout) {
        cout << "打开文件失败" << endl;
        return;
    }

    fout << "hello...111" << endl;
    fout << "hello...222" << endl;
    fout << "hello...333" << endl;
    fout.close();
}

// 读文件
void test_fin()
{
    const char *fname = "D:/cpp_file_test.txt";
    char ch;
    ifstream fin(fname);

    while (fin.get(ch)) {
        cout << ch;
    }
    fin.close();
}

class Teacher
{
public:
    Teacher()
    {
        age = 33;
        strcpy(name, "");
    }
    Teacher(int age, const char *name)
    {
        this->age = age;
        strcpy(this->name, name);
    }
    void printT()
    {
        cout << "age:" << age << " name:" << name <<endl;
    }
private:
    int age;
    char name[32];
};

void createTeacher()
{
    const char *fname = "D:/test_teacher.txt";
    ofstream fout(fname, ios::binary); // 建立一个输出流对象
    if (!fout) {
        cout << "打开文件失败" << endl;
        return ;
    }
    Teacher t1(31, "t31");
    Teacher t2(32, "t32");
    fout.write((char *)&t1, sizeof(Teacher));
    fout.write((char *)&t2, sizeof(Teacher));
    fout.close();
}

int main()
{
    // test_fout();
    // test_fin();
    createTeacher();

    return 0;
}

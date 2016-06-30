#include <iostream>

using namespace std;

class Hero
{
public:
    virtual int power() //如果不写virtual关键字，Playobj都会执行Hero类的power方法，而不会执行子类的power方法
    {
        return 10;
    }
};

class Enemy
{
public:
    int attack()
    {
        return 15;
    }
};

class AdvHero : public Hero
{
public:
    virtual int power()
    {
        return 15;
    }
};

class AdvAdvHero : public  Hero
{
public:
    virtual int power()
    {
        return 20;
    }
};


void Playobj(Hero *hf, Enemy *ef)
{
    if (hf->power() > ef->attack())
    {
        cout << "主角win\n";
    }
    else if (hf->power() == ef->attack())
    {
        cout << "主角与敌人同归于尽\n";
    }
    else
    {
        cout << "主角挂掉\n";
    }
}

int main()
{
    //不写virtual关键字 是静态联编 C++编译器根据HeroFighter类型,去执行 这个类型的power函数 在编译器编译阶段就已经决定了函数的调用
    //动态联编: 迟绑定:  //在运行的时候,根据具体对象(具体的类型),执行不同对象的函数 ,表现成多态.
    Hero hf;
    AdvHero ahf;
    AdvAdvHero aahf;

    Enemy ef;

    Playobj(&hf, &ef);
    Playobj(&ahf, &ef);
    Playobj(&aahf, &ef);

    return 0;
}

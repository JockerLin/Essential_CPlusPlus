//
// Created by pilcq on 2019/11/5.
//

#include<iostream>
#include "chp5.h"
using namespace std;

class Base
{
public:
    int pp = 0;
    void foo()
    {
        printf("Base foo\n");
    }
    virtual void fun()
    {
        printf("Base fun\n");
    }
};

class A : public Base
{
public:
    int pp = 45;

    void foo()  //隐藏：派生类的函数屏蔽了与其同名的基类函数
    {
        printf("A foo\n");
    }
    void fun()  //多态、覆盖
    {
        printf("A fun\n");
    }
};


class B : public Base
{
public:
    int pp = 38;
    void foo()  //隐藏：派生类的函数屏蔽了与其同名的基类函数
    {
        printf("B foo\n");
    }
    void fun()  //多态、覆盖
    {
        printf("B fun\n");
    }
};

template<class T>
void release(T op){
    op.foo();
    op.fun();
}

template<class VariableType>
class Relizase{
public:
    VariableType variable;

    Relizase(VariableType &vvv, int times){
//        vvv.fun();
//        vvv.foo();
        this->variable = vvv;
        this->variable.fun();
        this->variable.foo();
        cout << this->variable.pp<<endl;
//
//        this->variable = VariableType(vvv);
//        this->variable.fun();
//        this->variable.foo();

        //cout<<"init func"<<endl;
    }
};

int virtualFunction(void)
{
    A a;
    B b;
    Base base;
    //release(a);
    Relizase<B> par(b, 20);
//    A *p = &a;
//    p->foo();  //输出1
//    p->fun();  //输出2
//    p = &b;
//    p->foo();  //取决于指针类型，输出1
//    p->fun();  //取决于对象类型，输出4，体现了多态

//    std::cout<<"anther type"<<std::endl;
//    a.foo();
//    a.fun();
//    b.foo();
//    b.fun();


    return 0;
}

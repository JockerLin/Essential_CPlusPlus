//
// Created by pilcq on 2019/11/5.
//

#include<iostream>
#include "chp5.h"
using namespace std;

class A
{
public:
    void foo()
    {
        printf("A foo\n");
    }
    virtual void fun()
    {
        printf("A fun\n");
    }
};
class B : public A
{
public:

    void foo()  //隐藏：派生类的函数屏蔽了与其同名的基类函数
    {
        printf("B foo\n");
    }
    void fun()  //多态、覆盖
    {
        printf("B fun\n");
    }
};


int virtualFunction(void)
{
    A a;
    B b;
    A *p = &a;
    p->foo();  //输出1
    p->fun();  //输出2
    p = &b;
    p->foo();  //取决于指针类型，输出1
    p->fun();  //取决于对象类型，输出4，体现了多态

    std::cout<<"anther type"<<std::endl;
    a.foo();
    a.fun();
    b.foo();
    b.fun();

    return 0;
}

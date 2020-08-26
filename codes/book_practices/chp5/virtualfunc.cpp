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
    VariableType var;

    // 结构体 返回结构体类型的函数怎么定义呢？
    struct MyStruct{
        bool status=false;
        vector<int> img_pts;
        int number2=3;
    };

    // 构造函数也有包含模板的类型
    Relizase(VariableType &vvv, int times){
//        vvv.fun();
//        vvv.foo();
        this->var = vvv;
        this->var.fun();
        this->var.foo();
        cout << this->var.pp<<endl;
//
//        this->variable = VariableType(vvv);
//        this->variable.fun();
//        this->variable.foo();

        //cout<<"init func"<<endl;
    }
    void printFunction();
    //MyStruct structFunc();
    void variableStructFunc(MyStruct &ms);

};

template<class TTT>
void Relizase<TTT>::printFunction(){
    cout << "this is a template function" << endl;
}

//template<class TTT>
//Relizase<TTT>::MyStruct Relizase<TTT>::structFunc() {
//    cout << "this is struction" << endl;
//    MyStruct mm;
//    mm.status = false;
//    return mm;
//}

template<class TTT>
void Relizase<TTT>::variableStructFunc(MyStruct &ms) {
    cout << "template111" << endl;
    ms.number2 += 10;
}


void demoTemFunction(){
    A a;
    Relizase<A> rel(a, 76);
    rel.printFunction();
    Relizase<A>::MyStruct mysy;
    rel.variableStructFunc(mysy);
    cout<<"my sy: " << mysy.number2<<endl;
}


int virtualFunction(void)
{
//    A a;
//    B b;
//    Base base;
//    //release(a);
//    Relizase<B> par(b, 20);

    demoTemFunction();

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

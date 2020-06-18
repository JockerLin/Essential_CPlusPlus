//
// Created by pilcq on 2019/10/17.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "chp4.h"

using namespace std;

class Box{
public:
    static int objectCount;

    Box(double l=2.0, double b=2.0, double h=2.0){
        cout<<"Constructor called"<<endl;
        length = l;
        breadth = b;
        height = h;

        objectCount++;

    }
    double Volume(){
        return length*breadth*height;
    }

private:
    double length;
    double breadth;
    double height;
};

//若无初始化静态成员变量 则跑不通
//静态成员变量在类中仅仅是声明，没有定义，所以要在类的外面定义，实际上是给静态成员变量分配内存。
// 如果不加定义就会报错，初始化是赋一个初始值，而定义是分配内存。
int Box::objectCount = 0;

void test_static_func(void){
    Box Box1(3.3, 1.2, 1.5);
    Box Box2(8.5, 6.0, 2.0);
    cout<<"total objects:"<<Box::objectCount<<endl;

}
//
// Created by BlazarLin on 2020/8/26.
//

#include "../chp1/chp1.h"
#include "chp2.h"
#include "iostream"
#include <vector>

using namespace std;

// 2.1 输入多个位置 并输出这些位置上的费波那西数
int operateFibPromote21(){
    while (true){
        int pos;
        cout << "Please enter a position: ";
        cin >> pos;
        if (pos == 0){
            cout << "bye-bye";
            break;
        }
        int elem;
        if(fibonElement(pos, elem)){
            cout << "element # " << pos << " is " << elem << endl;
            printSequence(pos);
        }
        else{
            cout << "Sorry, Could not calculate element #" << pos << endl;
        }
    }
//    system("read");
    return 0;
}

//2.2 根据求值公式P=n*(3n-1)/2，产生1,5,12,22,35等元素，
// 定义函数，用上述公式，将产生元素置入用户传入的vector中，元素数目用户指定，并打印
// practice 2.2 begin-----------------------------------------------------------
void general_pentagonal(const int number, vector<int> &vec){
    if (number<=0 || number >=1024){
        cout << "over: request number is not supported"<< endl;
        return;
    }
    for (int i=1;i<=number;++i){
        vec.push_back(i*(3*i-1)/2);
    }
}

void print_vector(vector<int> vec, const string &str){
    cout << "The Pentagonal squence is :";
    for(int i=0;i<vec.size();++i){
        cout<< vec[i] << ' ';
    }
    cout << "The type of vector is: " << str << endl;
}

void practice22(){
    int number;
    vector<int> vec;
    string str = "int";
    cout << "please input a number:";
    cin >> number;
    general_pentagonal(number, vec);
    if (number>=0 && number<1024){
        print_vector(vec, str);
    }
}

// practice 2.2 end-----------------------------------------------------------


// 2.3 需求同2.2，只不过检查数据的有效性在inline函数中
// practice 2.3 start-----------------------------------------------------------

//内联函数
//代码膨胀（复制）为代价，仅仅省去了函数调用的开销，从而提高函数的执行效率。
inline bool checkNum(const int number){
    cout << "number is" << number << endl;
    if (number<=0 || number >1024){
        cout << "over: request number is not supported"<< endl;
        return false;
    }
    cout << "over: request number is supported"<< endl;
    return true;
}

void general_pentagonal2(const int num, vector<int> &vec){
//
    if (!checkNum(num))
        return;
    for (int i=1;i<=num;++i) {
        vec.push_back(i * (3 * i - 1) / 2);
    }
}

void practice23(){
    int number;
    vector<int> vec;
    string str = "int";
    cout << "please input a number:";
    cin >> number;
    general_pentagonal2(number, vec);
    if (number>=0 && number<1024){
        print_vector(vec, str);
    }
}
// practice 2.3 end-----------------------------------------------------------


// test 2.4 start-----------------------------------------------------------

const vector<int>* pentagonalPoint(int num){
    static vector<int> vec_static;
    if(num <=0 || num > 1024){
        cout << "over: request number is not supported"<< endl;
        return 0;
    }

    for (int i=1;i<=num;++i) {
        vec_static.push_back(i * (3 * i - 1) / 2);
        cout << vec_static[i-1] << endl;
    }
    return &vec_static;
}

void BackNum(int num){
    const vector<int> *vec = pentagonalPoint(num);
    cout << "the value of this number in pentagonal sequence is :";
    cout << (*vec)[num-1] << endl;
}

void practice24(){
    int number;
    cout << "please input a number:";
    cin >> number;
    //pentagonalPoint(number);
    if (number>=0 && number<1024){
        BackNum(number);
    }
}
// practice 2.4 end-----------------------------------------------------------


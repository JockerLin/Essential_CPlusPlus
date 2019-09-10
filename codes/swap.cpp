#include<iostream>
using namespace std;

template <typename T>
void myswap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
    cout << "hello------" << endl;
}

//函数模板的调用，显示类型调用，自动类型推倒
void main51()
{
    {
        int x = 10;
        int y = 20;
        myswap<int>(x, y);//函数模板的显示类型调用
        printf("x:%d y:%d \n", x, y);
    }
    {
        char a = 'a';
        char b = 'b';
        myswap<char>(a, b);//函数模板的显示类型调用
        printf("x:%d y:%d \n", a, b);
    }
}

//int main(){
//    main51();
//    return 0;
//}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "chp2.h"
using namespace std;

inline int max(int v1,int v2)
    { return v1>v2?v1:v2; }
inline double max(double v1,double v2)
    { return v1>v2?v1:v2; }
inline string max(const string &v1,const string &v2)
    { return v1>v2?v1:v2; }
inline int max(const vector<int> &vec)
    { return *max_element(vec.begin(),vec.end()); }
inline float max(const vector<float> &vec)
    { return *max_element(vec.begin(),vec.end()); }
inline string max(const vector<string> &vec)
    { return *max_element(vec.begin(),vec.end()); }
inline int max(int v[],int len)
    { return *max_element(v,v+len); }
inline double max(double v[],int len)
    { return *max_element(v,v+len); }
inline string max(string v[],int len)
    { return *max_element(v,v+len); }


// 2.5 实现一个重载的max()函数，让它接受以下参数：(a) 两个整数 (b)两个浮点数 (c)两个字符串
// (d)一个整数vector (e)一个浮点数vector (f)一个字符串vector (g)一个整数数组，以及
// 一个表示数组大小的整数值 (h)一个浮点数数组，以及一个表示数组大小的整数值 (i)一个字符
// 串数组，以及一个表示数组大小的整数值。最后，编写main()测试这些函数。
int practice25(){
    cout<<"in runP25 fun"<<endl;
    cout<<"test1"<<endl;
    cout<<max(1,3)<<endl
        <<max(1.1,3.1)<<endl
        <<max("ojbk","233")<<endl<<endl;

    const int len = 3;
    int a[len] = {1,5,6};
    double b[len] = {1.1,5.2,6.0};
    string c[len] = {"322","i am u dad","233"};
    cout<<"test2"<<endl;
    cout<<max(a,len)<<endl<<max(b, len)<<endl<<max(c,len)<<endl<<endl;

    vector<int> va(a,a+len);
    vector<float> vb(b,b+len);
    vector<string> vc(c,c+len);
    cout<<"test3"<<endl;
    cout<<max(va)<<endl
        <<max(vb)<<endl
        <<max(vc)<<endl<<endl;

    return 0;
}
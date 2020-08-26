//
// Created by pilcq on 2019/10/8.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "chp2.h"

using namespace std;
//using std::max_element;
//using std::vector;
//using std::string;
//using std::cout;
//using std::endl;


template <typename type>
inline type maxx(type v1,type v2)
    { return v1>v2?v1:v2; }

template <typename elemType>
inline elemType maxx(const vector<elemType> &vec)
    { return *max_element(vec.begin(),vec.end()); }

template <typename arrayType>
inline arrayType maxx(arrayType v[],int len)
    { return *max_element(v,v+len); }


int practice26(){
    cout<<"in runP25 fun"<<endl;
    cout<<"test1"<<endl;
    cout<<maxx(1,3)<<endl
        <<maxx(1.1,3.1)<<endl
        <<maxx("ojbk","233")<<endl<<endl;

    const int len = 3;
    int a[len] = {1,5,6};
    double b[len] = {1.1,5.2,6.0};
    string c[len] = {"322","i am u dad","233"};
    cout<<"test2"<<endl;
    cout<<maxx(a,len)<<endl<<maxx(b, len)<<endl<<maxx(c,len)<<endl<<endl;

    vector<int> va(a,a+len);
    vector<float> vb(b,b+len);
    vector<string> vc(c,c+len);
    cout<<"test3"<<endl;
    cout<<maxx(va)<<endl
        <<maxx(vb)<<endl
        <<maxx(vc)<<endl<<endl;

    return 0;
}
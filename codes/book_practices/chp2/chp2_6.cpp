//
// Created by pilcq on 2019/10/8.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "chp2.h"

//using namespace std;
using std::max_element;
using std::vector;
using std::string;
using std::cout;
using std::endl;


template <typename type>
inline type max(type v1,type v2)
    { return v1>v2?v1:v2; }

template <typename type>
inline type max(const vector<type> &vec)
    { return *max_element(vec.begin(),vec.end()); }

template <typename type>
inline type max(type v[],int len)
    { return *max_element(v,v+len); }


int runP26(){
    cout<<max(1,3)<<endl
        <<max(1.0,3.1)<<endl
        <<max("2333","233")<<endl;

    const int len = 3;
    int arr_a[len] = {1, 5, 6};
    float arr_b[len] = {1.1, 5.2, 6.0};
    string arr_c[len] = {"322", "223", "233"};

    cout << max(arr_a[0], arr_a[1]) << endl
         << max(1.1,3.1) << endl
         << max("2333","233") << endl;

    vector<int> veca(arr_a, arr_a + len);
    vector<float> vecb(arr_b, arr_b + len);
    vector<string> vecc(arr_c, arr_c + len);
    cout<<max(veca)<<endl
        <<max(vecb)<<endl
        <<max(vecc)<<endl;

    return 0;
}
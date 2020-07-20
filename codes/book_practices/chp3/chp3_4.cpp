//
// Created by pilcq on 2019/10/9.
//

#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
#include <fstream>
#include "chp3.h"

using namespace std;

//int chp34(){
////    istream_iterator<int> is(cin);
////    istream_iterator<int> eof;
////
////    ofstream odd_file("../../chp3/odd_number.txt");
////    ofstream even_file("../../chp3/even_number.txt");
////
////    vector<int> num;
////    cout<<"000";
////    copy(is ,eof, back_inserter(num));
////    cout<<num.size()<<endl;
////
////    vector<int> number_odd, number_even;
////    vector<int>::iterator iter=num.begin();
////    for(;iter!=num.end();++iter) {
////        cout<<*iter;
////        if((*iter)%2 == 0)
////            number_even.push_back(*iter);
////        else
////            number_odd.push_back(*iter);
////    }
////
////    ostream_iterator<int> os1(odd_file, " ");
////    cout<<"111";
////    copy(number_odd.begin(), number_odd.end(), os1);
////    cout<<"222";
////    ostream_iterator<int> os2(even_file, " ");
////    copy(number_even.begin(), number_even.end(), os2);
////    cout<<"333";
//
//
//
//
////    string text;
////    cout<<"1";
////    istream_iterator<int> is(cin);//绑定标准输入装置
////    cout<<"2";
////    istream_iterator<int> eof;//定义输入结束位置
////    cout<<"3";
//////    copy 有bug？ 待解决
////    copy(is,eof,back_inserter(text));
////    cout<<"4";
////    cout<<text;
////    sort(text.begin(),text.end());
////
////    ostream_iterator<int> os(cout,", ");//绑定标准输出装置
////    copy(text.begin(),text.end(),os);
//
//
//
////  使用迭代器来输出数据
//    vector<string> vec;
//    istream_iterator<string> item_in(cin), eof;//创建istream_iterator迭代器
//    while (item_in != eof)//向vec中读入string数据
//    {
//        vec.push_back(*item_in++);
//        cout<<*item_in;
//        cout << endl;
//    }
//    cout << "5555555555555555555";
//    return 0;
//}
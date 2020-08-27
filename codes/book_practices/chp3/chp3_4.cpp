//
// Created by pilcq on 2019/10/9.
//

#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
#include <fstream>
#include "chp3.h"
#include <vector>

using namespace std;

/*
使用istream_iterator对进行数字输入，对输入的数字进行排序，分奇数偶数保存至两份文件。
 * */

int chp34(){
//    string text;
//    istream_iterator<int> is(cin);//绑定标准输入装置
//    istream_iterator<int> eof;//定义输入结束位置
//    copy(is,eof,back_inserter(text));
//    sort(text.begin(),text.end());
//    cout<< text.length()<<text[0]<<endl;
//    ostream_iterator<int> os(cout,", ");//绑定标准输出装置
//    copy(text.begin(),text.end(),os);

    istream_iterator<int> is(cin);
    istream_iterator<int> eof;

    string odd_file_path="G:\\blazarlin\\personal\\essential-c\\codes\\book_practices\\chp3\\odd_number.txt";
    string even_file_path="G:\\blazarlin\\personal\\essential-c\\codes\\book_practices\\chp3\\even_number.txt";

    ofstream odd_file(odd_file_path);
    ofstream even_file(even_file_path);

    vector<int> num;
    copy(is ,eof, back_inserter(num));
    cout<<num.size()<<endl;

    vector<int> number_odd, number_even;
    vector<int>::iterator iter=num.begin();
    for(;iter!=num.end();++iter) {
//        cout<<*iter;
        if((*iter)%2 == 0)
            number_even.push_back(*iter);
        else
            number_odd.push_back(*iter);
    }

    sort(number_odd.begin(), number_odd.end());
    sort(number_even.begin(), number_even.end());

    // 绑定输出流到写入文件
    ostream_iterator<int> os1(odd_file, " ");
    copy(number_odd.begin(), number_odd.end(), os1);

    ostream_iterator<int> os2(even_file, " ");
    copy(number_even.begin(), number_even.end(), os2);

    // 绑定输出流到显示，用于查看
    ostream_iterator<int> os_out1(cout, ",");
    cout<<"sort odd number:"<<endl;
    copy(number_odd.begin(), number_odd.end(), os_out1);
    cout<<"\nsort even number:"<<endl;
    copy(number_even.begin(), number_even.end(), os_out1);

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
    return 0;
}
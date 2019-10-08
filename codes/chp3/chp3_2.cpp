//
// Created by pilcq on 2019/10/8.
//

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<set>
#include<iterator>
#include<functional>
#include<algorithm>
#include <map>
#include "chp3.h"

using namespace std;


class LessThan
{
public:
    bool operator()(const string &s1, const string &s2)
    {
        return s1.size()<s2.size();
    }
};

int chp32(){
    cout<<"in chp31"<<endl;
    ifstream pin;
//    pin.open("/home/pilcq/personal/essential-c/codes/chp3/test_data.txt", ios::in);
//  文件路径要设置到与工程路径的同一级目录下才拿得到，假如为practice3_1.txt则读不到
    string file_path="../chp3/test_data.txt";
    ifstream InputFile(file_path);
    string str;
    int times=0;

    string ia[6] = {"a", "an", "or", "the", "and", "but"};
    set<string> WordEclusion(ia, ia+6);
    map<string, int>dic;
//    pin >> str;
    vector<string> vec;

    while (InputFile >> str){
        times++;
        if(WordEclusion.count(str))
            continue;
//      如果字符是在ia里面的数据则不会在字典中建立对应的key-value
        vec.push_back(str);
    }
    printf("all %d words\n",times);
    sort(vec.begin(), vec.end(), LessThan());

    for(int i=0; i<vec.size(); ++i){
        cout<<"the value:"<<vec[i]<<endl;
    }

    return 0;
}
//
// Created by pilcq on 2019/10/8.
//
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include "chp3.h"

using namespace std;

/*
读取文本，建立一个map，key是文本的单词，value是单词出现的次数。自定义一份排除单词表，在将数据放入map之前，确定单词不在排除
 单词表中，文件读取完成后，显示单词列表与出现的次数。
 */
int chp31(){
    cout<<"in chp31"<<endl;
    ifstream pin;
//    pin.open("/home/pilcq/personal/essential-c/codes/chp3/test_data.txt", ios::in);
//  文件路径要设置到与工程路径的同一级目录下才拿得到，假如为practice3_1.txt则读不到
    string file_path="../chp3/test_data.txt";
    file_path="G:\\blazarlin\\personal\\essential-c\\codes\\book_practices\\chp3\\test_data.txt";
    ifstream InputFile(file_path);
    if (!InputFile){
        cout << "open file error!"<<endl;
    }
    else{
        string str;
        int times=0;

        string ia[6] = {"a", "an", "or", "the", "and", "but"};
        set<string> WordEclusion(ia, ia+6);
        map<string, int>dic;
//    pin >> str;

        while (InputFile >> str){
            times++;
            if(WordEclusion.count(str))
                continue;
//      如果字符是在ia里面的数据则不会在字典中建立对应的key-value
            dic[str]++;
//        cout<<times<<endl;
//        cout<<"all " <<times<<" words"<<endl;
        }
        printf("all %d words\n",times);

        map<string, int>::iterator iter = dic.begin();
        for(;iter!=dic.end();++iter){
            cout<<"the key:"<<iter->first<<",the value:"<<iter->second<<endl;
        }
    }

    return 0;
}
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

int chp33(){
    map<string, string> dic;
    string str1, str2;
    cout<<"press <q> to stop input mode "<<endl;
    while(true){
        cout<<"name:";
        cin >> str1;
        if( str1=="q"){
            break;
        }
        cout<<"age:";
        cin>>str2;
        dic[str1]=str2;
    }
    string search;
    cout << "Which family name does you want to search:  ";
	cin >> search;
	if(dic.find(search)!=dic.end())
	    cout << "The children name in this family is: " << dic[search] << endl;
	else
	    cout << "the name doesn't exist";

    return 0;
}
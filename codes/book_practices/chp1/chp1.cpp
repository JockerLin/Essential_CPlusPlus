//
// Created by pilcq on 2019/10/14.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "chp1.h"

using namespace std;

/*
练习1.5 查询用户姓名，并读取用户所输入的内容，确保用户输入的名称长度大于两个字符，如果用户输入了有效名称，则相应一些信息。
用两种方式实现操作，一是使用C-style字符串，二是使用string
*/
//    cstyle
int practice151(){
    char usr_name[128] = "";
    cout << "Please input yout name: ";
    //字符不能保存空格的版本
    //cin >> usr_name;
    //字符可以保存空格的版本
    cin.getline(usr_name, 128,'\n');
    if (strlen(usr_name)<2){
        cout << "invalid, please reinput: ";
        practice151();
    }
    else{
        cout<< "name len:" << strlen(usr_name) << endl;
        cout<< "Hello "<< usr_name << ", save succeed!";
    }
    return 0;
}

//    string
int practice152(){
    string usr_name;
    cout << "Please input yout name: ";
    cin >> usr_name;

    if (usr_name.size()<2){
        cout << "invalid, please reinput: ";
        practice152();
    }
    else{
        cout<< "Hello "<< usr_name  << ",save succeed!";
    }
    return 0;
}
/*
练习1.6 从标准输入装置读入一串整数，读入的数据置入array、vector，求总合与平均值输出。
 */
int practice16GetNumber(){
    int array_a[128];
    vector<int> array_b;
    int sum_a = 0;
    int sum_b = 0;
    int i = 0;
    int temp_number;
    while (i < 128 && cin >> temp_number){
        array_a[i] = temp_number;
        array_b.push_back(temp_number);
        i++;
        cout << "please write a number(int):";
    }
    for(int idx =0; idx<i; idx++){
        sum_a += array_a[idx];
        sum_b += array_b[idx];
    }
    int a_len = sizeof(array_a)/ sizeof((array_a[0]));
    float average_a = float(sum_a/i);
    float average_b = float(sum_b/array_b.size());
    cout << "sum array a is :"<< sum_a << ",average a is :" << average_a << endl;
    cout << "sum array b is :"<< sum_b << ",average b is :" << average_b << endl;
    return 0;
}

/*
练习1.7 读取本地txt文件，将其中每个字都读取到一个vector<string>对象中，历遍该vector，
内容显示到cout，利用sort()对文字排序
 */
int practice17(){
    string input_file_path = "G:\\blazarlin\\personal\\essential-c\\codes\\book_practices\\chp1\\test.txt";
    string output_file_path = "G:\\blazarlin\\personal\\essential-c\\codes\\book_practices\\chp1\\output.txt";

    vector<string> words;
    ifstream infile(input_file_path, ios_base::in);
    if (!infile){
        cout << "open file error";
    }
    else{
        string data;
        while (infile>>data){
            words.push_back(data);
        }
//      排序
        sort(words.begin(), words.end());
        cout << "size of words is "<<words.size()<<endl;
        for(int i=0;i<words.size();i++){
            cout << words[i] << "\n";
        }
    }
//  追加模式
    ofstream outfile(output_file_path, ios_base::app);
    if(!outfile){
        cout << "open outfile error";
    }
    else{
        for (int i = 0; i < words.size(); ++i) {
            outfile << words[i] << "\n";
        }
        cout << "write finish";
    }
    return 0;
}
/*
练习1.8 以array储存4种不同的字符串信息，以用户答错的次数作为array的索引值，显示对应的安慰语句
 */
int practice18(){
    int num_tries;
    string message[4]={
            "Oops! Nice guess but not quite it.\n",
            "Hmm. Sorry. Wrong again.\n",
            "Ah, this is harder than it looks, isn't it?\n",
            "It must be getting pretty frustrating by now!\n"
    };
    cin >> num_tries;
    switch(num_tries){
        case 1:
        case 2:
        case 3:
            cout << message[num_tries-1];
            break;
        default:
            cout << message[3];
            break;
    }
    return 0;
}


bool fibonElement(int pos, int &elem){
    if (pos <= 0 || pos > 1024){
        elem = 0;
        return false;
    }
    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int ix = 3; ix <=pos ; ++ix) {
        elem = n_2+n_1;
        n_2 = n_1; n_1 = elem;
    }
    return true;
}

// 计算对应位置的费伯纳西数
int operateFib(){
    int pos;
    cout << "Please enter a position: ";
    cin >> pos;

    int elem;
    if(fibonElement(pos, elem)){
        cout << "element # " << pos << " is " << elem << endl;
        printSequence(pos);
    }
    else{
        cout << "Sorry, Could not calculate element #" << pos << endl;
    }
    return 0;
}

bool printSequence(int pos){
    if (pos <= 0 || pos >1024){
        cerr << "invalid position: "<< pos << "-- cannot handle request! \n";

        return false;
    }
    cout << "the Fibonacci sequence for "<< pos << " position: \n\t";

    switch(pos){
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;

    }
    int elem;
    int n_2=1, n_1=1;
    for (int ix = 3; ix <= pos; ++ix) {
        elem = n_2 + n_1;//拓展成更多计算规则也不是不可以
        n_2 = n_1; n_1 = elem;

        cout << elem << (!(ix%10)? "\n\t":" ");
    }
    cout << endl;
    return true;
}
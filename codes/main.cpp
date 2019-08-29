#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

//chp 1
int practice151();
int practice152();
int practice16GetNumber();
int exampleFunction();
int practice17();
int practice18();
bool fibonElement(int, int&);
int operateFib();
bool printSequence(int);
//chp 2
int operateFibPromote();


int main() {
//    exampleFunction();
//    practice17();
//    practice18();
//    operateFib();
    operateFibPromote();
    return 0;
}

int exampleFunction(){
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int practice151(){
//    cstyle
    char usr_name[200] = "";
    cout << "Please input yout name: ";
    cin >> usr_name;
    if (strlen(usr_name)<2){
        cout << "invalid, please reinput: ";
        practice151();
    }
    else{
        cout << "save succeed!";
    }
    return 0;
}

int practice152(){
//    cstyle
    string usr_name;
    cout << "Please input yout name: ";
    cin >> usr_name;
    if (usr_name.size()<2){
        cout << "invalid, please reinput: ";
        practice152();
    }
    else{
        cout << "save succeed!";
    }
    return 0;
}

int practice16GetNumber(){
    int array_a[3];
    vector<int> array_b;
    int sum_a = 0;
    int sum_b = 0;
    int i = 0;
    int temp_number;
    while (i < 3){
        cout << "please write a number(int):";
        cin >> temp_number;
        array_a[i] = temp_number;
        array_b.push_back(temp_number);
        i++;
    }
    for(i =0; i<3; i++){
        sum_a += array_a[i];
        sum_b += array_b[i];
    }
    int a_len = sizeof(array_a)/ sizeof((array_a[0]));
    float average_a = float(sum_a/a_len);
    float average_b = float(sum_b/array_b.size());
    cout << "sum array a is :"<< sum_a << ",average a is :" << average_a << endl;
    cout << "sum array b is :"<< sum_b << ",average b is :" << average_b << endl;
    return 0;
}

int practice17(){
    string input_file_path = "/home/pilcq/personal/C-Project/Code/test.txt";
    string output_file_path = "/home/pilcq/personal/C-Project/Code/output.txt";

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
        elem = n_2 + n_1;
        n_2 = n_1; n_1 = elem;

        cout << elem << (!(ix%10)? "\n\t":" ");
    }
    cout << endl;
    return true;
}

// 2.1
int operateFibPromote(){
    while (true){
        int pos;
        cout << "Please enter a position: ";
        cin >> pos;
        if (pos == 0){
            cout << "bye-bye";
            break;
        }
        int elem;
        if(fibonElement(pos, elem)){
            cout << "element # " << pos << " is " << elem << endl;
            printSequence(pos);
        }
        else{
            cout << "Sorry, Could not calculate element #" << pos << endl;
    }
    }
//    system("read");
    return 0;
}


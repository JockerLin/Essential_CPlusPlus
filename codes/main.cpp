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

void print_msg(ostream &os, const string &msg){
    if (msg.empty())
        return;
    os << msg;
}

void display(const vector<int> *vec){
    if (! vec){
        cout << "display(): the vector pointer is 0\n";
        return;
    }
    for(int ix=0;ix< vec->size();ix++)
        cout << (*vec)[ix] << ' ';
    cout << endl;
}

void pointer_use(){
    int ia[8] = {8, 32, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia+8);
    cout << "vec is" ;
    cout << "vector before sort: ";
    display(&vec);
}
//pointer参数和reference参数之间更重要的差异是，pointer可能指向某个实际对象。当提及pointer时，一定要先确定其值
//并非0，至于reference，则必定会代表某个对象，所以不需要做此检查。

void swap(int &val1, int &val2){
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubble_sort(vector<int> &vec, ofstream *ofil = 0){
    for(int ix=0;ix<vec.size();++ix)
        for(int jx=ix+1;jx<vec.size();++jx)
            if(vec[ix]>vec[jx]){
                if(!ofil){
                    (*ofil) << "about to call swap! ix:" << ix
                    << "jx: " << jx << "\tswapping: "
                    << vec[ix] << "with "<< vec[jx]<<endl;
                }
//                swap(vec[ix], vec[jx],ofil)
            }
}
//为了更高的可见性，讲默认值放在函数的声明处而非定义处

//静态局部变量
int fib_local_staic_object(){
    static vector<int> elems;

}


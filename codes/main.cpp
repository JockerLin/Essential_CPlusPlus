#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

//chapter 1 ----------------------------------------------------------------------
int practice151();
int practice152();
int practice16GetNumber();
int exampleFunction();
int practice17();
int practice18();
bool fibonElement(int, int&);
int operateFib();
bool printSequence(int);
//chapter 2 ----------------------------------------------------------------------
int operateFibPromote();
void func();
void static_fun_test();
int* find(vector<int> &vec, int value);
int findidx(vector<int> vec, int value);
void test_find_map_value();
void general_pentagonal(const int number, vector<int> &vec);
void print_vector(vector<int> vec, const string &str);
void test22();
inline bool checkNum(const int number);
void general_pentagonal2(const int num, vector<int> &vec);
void test23();
const vector<int>* pentagonalPoint(int num);
void BackNum(int num);
void test24();
void testTrueFalse();


int main() {
//    exampleFunction();
//    practice17();
//    practice18();
//    operateFib();
//    operateFibPromote();
//    static_fun_test();
//    test23();
//    test24();
//    testTrueFalse();
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

void func(){
    static int n = 10;
//  静态局部变量
    n ++;
    cout<< "static variable n is:" << n << endl;
}

void static_fun_test(){
//静态局部变量保存在全局数据区，而不是保存在栈中，每次的值保持到下一次调用，直到下次赋新值。
//它始终驻留在全局数据区，直到程序运行结束。但其作用域为局部作用域，当定义它的函数或语句块结束时，其作用域随之结束
    func();
    func();
    func();
}

//模板函数
template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec){
//  希望推迟制定要显示的vector类型
    cout << msg;
    for(int ix=0;ix<vec.size();++ix){
        elemType t = vec[ix];
        cout << t << ' ';
    }
}

void temp_func(){
    vector<int> ivec;
    string msg;
    display_message(msg, ivec);

    vector<string> svec;
    string msg2;
    display_message(msg2, svec);
}

// test 22 begin-----------------------------------------------------------
void general_pentagonal(const int number, vector<int> &vec){
    if (number<=0 || number >=1024){
        cout << "over: request number is not supported"<< endl;
        return;
    }
    for (int i=1;i<=number;++i){
        vec.push_back(i*(3*i-1)/2);
    }
}

void print_vector(vector<int> vec, const string &str){
    cout << "The Pentagonal squence is :";
    for(int i=0;i<vec.size();++i){
        cout<< vec[i] << ' ';

    }
	cout << "The type of vector is: " << str << endl;
}

void test22(){
    int number;
    vector<int> vec;
    string str = "int";
    cout << "please input a number:";
    cin >> number;
    general_pentagonal(number, vec);
    if (number>=0 && number<1024){
        print_vector(vec, str);
    }
}

// test 2.2 end-----------------------------------------------------------

// test 2.3 start-----------------------------------------------------------

//内联函数
//代码膨胀（复制）为代价，仅仅省去了函数调用的开销，从而提高函数的执行效率。
inline bool checkNum(const int number){
    cout << "number is" << number << endl;
    if (number<=0 || number >1024){
        cout << "over: request number is not supported"<< endl;
        return false;
    }
    cout << "over: request number is supported"<< endl;
    return true;
}

void general_pentagonal2(const int num, vector<int> &vec){
//
    if (!checkNum(num))
        return;
    for (int i=1;i<=num;++i) {
        vec.push_back(i * (3 * i - 1) / 2);
    }
}

void test23(){
    int number;
    vector<int> vec;
    string str = "int";
    cout << "please input a number:";
    cin >> number;
    general_pentagonal2(number, vec);
    if (number>=0 && number<1024){
        print_vector(vec, str);
    }
}
// test 2.3 end-----------------------------------------------------------

// test 2.4 start-----------------------------------------------------------

const vector<int>* pentagonalPoint(int num){
    static vector<int> vec_static;
    if(num <=0 && num > 1024){
        cout << "over: request number is not supported"<< endl;
        return 0;
    }

    for (int i=1;i<=num;++i) {
        vec_static.push_back(i * (3 * i - 1) / 2);
        cout << vec_static[i-1] << endl;
    }
    return &vec_static;
}

void BackNum(int num){
    const vector<int> *vec = pentagonalPoint(num);
    cout << "the value of this number in pentagonal sequence is :";
    cout << (*vec)[num-1] << endl;
}

void test24(){
    int number;
    cout << "please input a number:";
    cin >> number;
    pentagonalPoint(number);
    if (number>=0 && number<1024){
            BackNum(number);
        }
}

//重载函数与模板函数待添加

template <typename elemType>
elemType* find_temple(vector<elemType> &vec, elemType &value){
    for(int ix=0;ix<vec.size();++ix)
        if(vec[ix]==value)
            return &vec[ix];
    return 0;
}

void test_find_map_value(){
    int map_value = 0;
    int ia[8] = {8, 32, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia+8);
    int *point, idx, *point2;
    point = find(vec, 32);
    idx = findidx(vec, 32);
//    cout << find_temple(vec, 21);
//    find_temple<int>(vec, 13);
    cout << *point << idx;
}

int* find(vector<int> &vec, int value){
    for(int ix=0;ix<vec.size();++ix)
        if (vec[ix] == value)
            return &vec[ix];
    return 0;
}

int findidx(vector<int> vec, int value){
    for(int ix=0;ix<vec.size();++ix)
        if (vec[ix] == value)
            return vec[ix];
    return -1;
}

void testTrueFalse(){
    bool a = true;
    cout << "a is " << a;
    cout << "!a is " << !a;

}
// chapter2 practices 带补全

// chapter 3

//传入数组与数组的某个value，返回该value的指针
template <typename elemType>
elemType* findOrigin(const elemType *array, int size, const elemType &value){
    if(!array || size <1 )
        return 0;
    for(int ix=0;ix<size; ++ix, ++array){
        if (*array == value)
            return array;
    return 0;
    }
}

template <typename elemType>
elemType* find(const elemType *first, const elemType *last, const elemType &value){
    if (!first || !last)
        return 0;
//  当first不等于last,就把value和first所指的元素相比较
//  如果两者相等，便返回first，否则将first递增1，令它指向下一个元素
    for (;first != last; ++first)
        if (*first == value)
            return first;

    return 0;
}

template <typename elemType>
inline elemType* begin(const vector<elemType> &vec){
    return vec.empty()? 0 : vec[0];
}

template <typename elemType>
inline elemType* end(const vector<elemType> &vec){
    return vec.empty()? 0 : vec[vec.size()-1];
}

//how to use:
//find(begin(svec), end(svec), search_value)
//只需要这一份，就可以同时实现array与list的寻找值功能

template <typename IteratorType, typename elemType>
IteratorType* findIterator(IteratorType first, IteratorType last, const elemType &value){
    if (!first || !last)
        return 0;
//  当first不等于last,就把value和first所指的元素相比较
//  如果两者相等，便返回first，否则将first递增1，令它指向下一个元素
    for (;first != last; ++first)
        if (*first == value)
            return first;

    return 0;
}
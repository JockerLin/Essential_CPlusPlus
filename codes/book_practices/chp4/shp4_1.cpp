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
#include "chp4.h"

using namespace std;

//class Stack{
//public:
//    bool push(const string&);
//    bool pop(string &elem);
//    bool peek(string &elem);
//
//    bool empty();
//    bool full();
//
//    int size() { return _stack.size();}
//
//private:
//    vector<string> _stack;
//};
//
//void fill_stack(Stack &stack, istream &is = cin){
//    string str;
//    while(is >> str && ! stack.full())
//        stack.push(str);
//
//    cout << "Read in" << stack.size() << " elements\n";
//}

//类的定义以及构造函数与析构函数example

class Line
{
public:
    void setLength(double len);
    double getLength();
    void operatorLength(double len);
    Line(double len);//构造函数 实例化类的时候会跑当前函数
    Line();//构造函数 实例化类的时候会跑当前函数
    ~Line();//析构函数

private:
    double length;
};

//Line::Line(double len) {
//    cout << "object is being create" <<endl;
//    length = len;
//}
// 上下两个函数等价
Line::Line(double len):length(len) {
    cout << "object is being create" << endl;
    length = len;
}

Line::~Line(){
    cout << "object is being deleted" << endl;
}

void Line::setLength(double len) {
    length = len;
}

double Line::getLength() {
    return length;
}

void Line::operatorLength(double len) {
    length += len;
}

int testLineClass(){
    Line line(10);
//    Line line;
//    line.setLength(6);
    cout << "length of line :" << line.getLength()<<endl;
    line.operatorLength(8);
    cout << "length of line :" << line.getLength()<<endl;
    return 0;
}

//Triangular trian(1,8);

class Triangular{
public:
    static bool is_elem(int);
    void gen_elements(int length);
    static void gen_elems_to_value(int value);
    void display(int length, int beg_pos, ostream &os=cout);
    static vector<int> getElems(){
        return _elems;
    }

private:
    static vector<int> _elems;
    static const int _max_elems = 1024;
};

//静态变量使用之前必须初始化
vector<int> Triangular::_elems;

//静态成员函数
bool Triangular::is_elem(int value) {
    if (!_elems.size() || _elems[_elems.size()-1]<value)
        gen_elems_to_value(value);

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elems_to_value(int value) {
    int ix = _elems.size();
    cout<<ix<<endl;
    if (!ix){
        _elems.push_back(1);
        ix = 1;
    }
    while(_elems[ix-1] < value && ix < _max_elems){
        ++ix;
        _elems.push_back(ix*(ix+1)/2);
    }
    if (ix == _max_elems)
        cerr<<"Triangular Sequence: oops:value to long"
            <<value<<"--exceeds max size of"
            <<_max_elems<<endl;
}

void testIsElemsDependence(void){
    string ch;
    bool more = true;
    while(more){
        cout<<"enter value:";
        int ival;
        cin>>ival;

        Triangular tri=Triangular();
        bool is_elem = tri.is_elem(ival);
        cout<<ival
            <<(is_elem?"is":"is not ")
            <<"an element in the Triangular series.\n"
            <<"Another value?(y/n)";

        cin>>ch;
        if(ch == "n" || ch == "N")
            more = false;
    }
}

class Triangular_iterator{
//当前类维护一个索引值 用以索引Triangular中储存数列元素的static data member 即_element,
//为了达成该目的 Triangular必须赋予Triangular_iterator的member function特殊的访问权限
//通过使用friend机制给予这种特殊权限
public:
    typedef Triangular_iterator iterator;
    Triangular_iterator begin() const {
        return Triangular_iterator(_begin_pos);
    }

    Triangular_iterator end() const {
        return Triangular_iterator(_begin_pos+_length);
    }

    Triangular_iterator(int index) : _index(index-1){}
    //为此class定义==与!=运算符的具体实现
    bool operator==(const Triangular_iterator&) const;
    bool operator!=(const Triangular_iterator&) const;
    int operator*() const;
    Triangular_iterator&    operator++();//prefix ++x
    Triangular_iterator operator++(int);//postfix x++

private:
    int _begin_pos;
    int _length;
    void check_integrity() const;
    int _index;
};

inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const {
    return _index == rhs._index;
}

inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const {
    return !(*this == rhs);
}

inline int Triangular_iterator::operator*() const {
    check_integrity();
    return Triangular::getElems()[_index];
}

//inline void Triangular_iterator::check_integrity() const {
//    if (_index >= Triangular::_max_elems)
//        throw iterator_overflow();
//}

inline Triangular_iterator& Triangular_iterator::operator++() {
    ++_index;
    check_integrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::operator++(int) {
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}


//
// Created by pilcq on 2019/10/14.
//

#ifndef CODES_CHP4_H
#define CODES_CHP4_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int testLineClass();
void testIsElemsDependence(void);
void test_static_func(void);

void testStack();

class Stack {
public:
	bool   push(const string&);
	bool   pop(string &elem);
	bool   peek(string &elem);

	bool   find(const string &elem) ;
	int    count(const string &elem);
	//以上五个成员函数全是申明
	//以下三个成员函数直接定义于class本身中
	bool   empty() { return _stack.empty(); }
	bool   full()  { return _stack.size() == _stack.max_size(); }
	int    size()  { return _stack.size(); }
	vector<string> getStack(){
        return _stack;
	}

private:
	vector<string> _stack;
};

int testChp44();
int testOperateReload();
int testChp45();


#endif //CODES_CHP4_H

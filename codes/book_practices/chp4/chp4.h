//
// Created by pilcq on 2019/10/14.
//

#ifndef CODES_CHP4_H
#define CODES_CHP4_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int testLineClass();
void testIsElemsDependence(void);
void test_static_func(void);

void chp412TestStack();

class Stack {
public:
	bool   push(const string&);
	bool   pop(string &elem);
	bool   peek(string &elem);

	bool   find(const string &elem) ;
	int    count(const string &elem);
	//以上五个成员函数全是申明,在chp4_2中重新定义
	//以下三个成员函数直接定义于class本身中
	bool   empty() { return _stack.empty(); }
	bool   full()  { return _stack.size() == _stack.max_size(); }
	int    size()  { return _stack.size(); }
	vector<string> getStack(){
        return _stack;
	}
    stack<string> ssk;

private:
	vector<string> _stack;

};

int chp44Test();
int testOperateReload();
int chp45Test();


#endif //CODES_CHP4_H

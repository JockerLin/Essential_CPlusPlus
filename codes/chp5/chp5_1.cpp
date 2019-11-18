//
// Created by pilcq on 2019/11/7.
//
// reference https://blog.csdn.net/weixin_43184615/article/details/83031468
// 实现一个两层的stack类体系。其基类是个纯抽象类Stack，只提供最简单的接口：pop()，push()，size()，
// empty()，full()，peek()，print()。两个派生类则为LIFO_Stack和Peekback_Stack。 实现普通的推压栈功能。
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include "chp5.h"
using namespace std;

// int*与 *int 区别

ostream& operator<<(ostream& os, const StackAbstract &rhs)
{
	return rhs.print(os);
}


bool LIFO_Stack::pop(string& elem)
{
	if (empty()) return false;

	elem = _stack.back();
	_stack.pop_back();
	--_top;
	return true;
}

bool LIFO_Stack::push(const string& elem)
{
	if (full()) return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

ostream& LIFO_Stack::print(ostream& os) const
{
	vector<string>::const_reverse_iterator //反向迭代器，针对vector.rbegin()和vector.rend()
		rit = _stack.rbegin(),   //指向第一个元素前一个位置
		rend = _stack.rend();    //指向最后一个元素
	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << endl;
	return os;
}



bool Peekback_Stack::pop(string& elem)
{
	if (empty()) return false;

	elem = _stack.back();
	_stack.pop_back();
	--_top;
	return true;
}

bool Peekback_Stack::push(const string& elem)
{
	if (full()) return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

ostream& Peekback_Stack::print(ostream& os) const
{
	vector<string>::const_reverse_iterator //反向迭代器，针对vector.rbegin()和vector.rend()
		rit = _stack.rbegin(),   //指向第一个元素前一个位置
		rend = _stack.rend();    //指向最后一个元素
	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << endl;
	return os;
}

bool Peekback_Stack::peek(int index, string& elem)
{
	if (empty()) return false;
	if (index < 0 || index >= size()) return false;
	elem = _stack[index];
	return true;
}

void peek(StackAbstract& st, int index){
    std::cout<<endl;
    string t;
    if (st.peek(index, t))
        std::cout<<"peek: "<<t;
    else
        std::cout<< "peek failed";
    std::cout<<endl;
}

int operateStack()
{
	LIFO_Stack st;
	string str="qwe";
////	while (cin >> str && !st.full())
    st.push(str);
    st.push("123");
    st.push("hjkhjk");
//	cout << '\n' << "About to call peek() with LIFO_Stack" << endl;
//	cout<<"st.top() - 1:"<<st.top() - 1<<endl;
//	peek(st, st.top() - 1);
//	cout << st;

	Peekback_Stack pst;
	while (!st.empty())
	{
		string t;
		if (st.pop(t))
			pst.push(t);
	}
	cout << "About to call peek() with Peekback_Stack" << endl;
	peek(pst, pst.top() - 1);
	cout << pst;

	return 0;
}

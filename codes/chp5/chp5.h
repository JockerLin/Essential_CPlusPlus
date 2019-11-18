//
// Created by pilcq on 2019/11/5.
//

#ifndef CODES_CHP5_H
#define CODES_CHP5_H
#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

class StackAbstract{
public:
	virtual ~StackAbstract(){}
	//全部声明为纯虚函数，就不用再定义了
	virtual bool pop(string& elem) = 0;  //删除栈顶元素，并改变elem 的值
	virtual bool push(const string&) = 0; //在栈顶增加元素
	virtual bool peek(int index, string&) = 0; //查找某个地址的值是否存在

	virtual int top() const = 0;
	virtual int size() const = 0;

	virtual bool empty() const = 0;
	virtual bool full() const = 0;
	virtual ostream& print(ostream &os) const = 0;

};

class LIFO_Stack:public StackAbstract{
public:
	LIFO_Stack(int capacity = 0) :_top(0){    //考虑周全一点，capacity容量
		if (capacity)
			_stack.reserve(capacity);
	}
	int size() const { return _stack.size(); }
	bool empty() const{ return !_top; }
	bool full() const{ return size() >= _stack.max_size(); }
	int top() const{ return _top; }
	ostream& print(ostream&) const;

	bool pop(string& elem);
	bool push(const string& elem);
	bool peek(int, string&) { return false; } //虽然这里peek函数没用，但基类里定义了此纯虚函数，这里必须申明定义

private:
	int _top;   //用来计算vector中的个数
	vector<string> _stack;
};

class Peekback_Stack :public StackAbstract{
public:
	Peekback_Stack()
	{
		_top = 0;
	}
	int size() const { return _stack.size(); }
	bool empty() const{ return !_top; }
	bool full() const{ return size() >= _stack.max_size(); }
	int top() const{ return _top; }
	ostream& print(ostream&) const;

	bool pop(string& elem);
	bool push(const string& elem);
	bool peek(int , string&);

private:
	int _top;
	vector<string> _stack;
};

int virtualFunction(void);
int operateStack();
void peek(StackAbstract& st, int index);

#endif //CODES_CHP5_H

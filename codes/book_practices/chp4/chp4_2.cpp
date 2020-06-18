//
// Created by pilcq on 2019/10/19.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "chp4.h"

using namespace std;


//class主体之外定义成员函数
bool
Stack::pop(string &elem)     //pop 移除栈顶元素
{
	if (empty())
		return false;

	elem = _stack.back();   //back()返回当年vector最后一个元素的引用
	_stack.pop_back();      //删除最后一个元素

	return true;
}

bool
Stack::peek(string &elem)   //peek  获得栈顶元素(即最后一个进栈元素）
{
	if (empty())
		return false;

	elem = _stack.back();
	return true;
}

bool
Stack::push(const string &elem)  //在栈顶增加元素
{
	if (full())
		return false;

	_stack.push_back(elem);
	return true;
}

//Stack中实现fing 函数
bool
Stack::find(const string &elem)
{
	return std::find(_stack.begin(), _stack.end(), elem) != _stack.end();
}

//Stack中实现count 函数
int
Stack::count(const string &elem)
{
	return std::count(_stack.begin(), _stack.end(), elem);
}

void testStack() {
    Stack st;
    string str;

    cout << "Please enter a series of strings.\n";
    while (cin >> str && !st.full()) {
        if (str == "q")
            break;
        cout << str << endl;
//	    cout<<"input"<<endl;
        st.push(str);
        cout << st.getStack().size() << endl;
//        for(int i =0;i<st.getStack().size();i++){
//            cout<<st.getStack()[i]<<endl;
//        }

    }

	if (st.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out\n ";
	}

	//st.peek(str);
	if (st.size() == 1 && str.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out\n ";
	}

	cout << '\n' << "Read in " << st.size() << " strings!" <<st.getStack().data()<< endl;
	for(int i =0;i<st.getStack().size();i++){
	    cout<<st.getStack()[i]<<endl;
	}

	//开始调用find和count函数
	//cin.clear后，可以进行第二波输入。
	cin.clear(); //***
	string word;
	cout << "Which word do you want search: ";
	cin >> word;
	if (st.find(word))
	{
		cout << "The word is in the stack,and it occurs " << st.count(word) << " times" << endl;
	}
	else
		cout << "Oops: this word not in the stack\n";

	//将stack的元素取出打印，pop在取出的同时删除该元素
	cout<< "The strings, in reverse order: ";
	while (st.size())
        if (st.pop(str))
            cout << str << ' ';

	cout << '\n' << "There are now " << st.size()
		<< " elements in the stack!\n";

}
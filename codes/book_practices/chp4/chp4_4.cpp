//
// Created by pilcq on 2019/10/19.
//

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <cstdlib>
#include <stdlib.h>
using namespace std;


//题目：一份“用户概况记录（user profile）”内含以下数据：登录记录、实际姓名、登录次数、猜过次数、猜对次数、
//等级——包括初级、中级、高级、专家，以及猜对百分比（可实时计算获得，或将其值储存起来备用）
//请写出一个名为UserProfile的class，提供以下操作：输入、输出、相等测试、不相等测试。
//其constructor必须能够处理默认的用户等级、默认的登录名称（“guest”）
//对于同样名为guest的多个用户，你如何宝恒每个guest有他独有的登录会话，不会与其他人混淆？
//原文链接：https://blog.csdn.net/weixin_43184615/article/details/82971903

//知识点：class定义（写数据cout，读取数据cin），构造函数初始化值，重载操作符operator，
// 重载输入输出流 ostream& operator<< 和istream& operator>>，枚举变量定义enum， 类的private里的static数据成员需要初始化。。


class UserProfile{
public:
    enum ulevel {Beginner, Intermediate, Advanced, Guru};
    UserProfile(string login, ulevel=Beginner);
    UserProfile();

    //重载操作符号
    bool operator==(const UserProfile &);
    bool operator!=(const UserProfile &ths);

    //读数据
    string login() const { return _login;}
    string user_name() const { return _user_name;}
    int login_count() const { return _login_count;}
    int guess_count() const { return _guess_count;}
    int guess_correct() const { return _guess_correct;};
    string level() const;
    double guess_average() const;

    //reset 数据
    void reset_login(const string &val) {_login = val;}
    void user_name(const string &val) { _user_name = val; }
	void reset_level(const string &level);
	//void reset_level(ulevel newlevel) { _user_level = newlevel; }
	void reset_login_count(int val) { _login_count = val; }
	void reset_guess_count(int val) { _guess_count = val; }
	void reset_guess_correct(int val){ _guess_correct = val; }
	void bump_login_count(int cnt = 1){ _login_count += cnt; }
	void bump_guess_count(int cnt = 1){ _guess_count += cnt; }
	void bump_guess_correct(int cnt = 1){ _guess_correct += cnt; }

private:
    string _login;
    string _user_name;
    int _login_count;
    int _guess_count;
    int _guess_correct;
    ulevel _user_level;

    static map<string, ulevel> _level_map;
    static void init_level_map();
};

inline double UserProfile::guess_average() const
{
	return _guess_count ? double(_guess_correct) /double(_guess_count) * 100 : 0.0;
}

inline UserProfile::UserProfile(string login, ulevel level)
:_login(login),_user_level(level), _login_count(1), _guess_count(0), _guess_correct(0) {}


inline UserProfile::UserProfile()
:_login("guess"), _user_level(Beginner), _login_count(1), _guess_count(0), _guess_correct(0) {
    static int id=0;
    char buffer[16];
    string buffer0;
//    itoa(id++, buffer, 10);
    buffer0 = to_string(id++);
    _login += buffer0;
}

//定义两个重载操作符函数，rhs：right hand side
//本例中没用到
inline bool UserProfile::operator==(const UserProfile &rhs)
{
    cout<<"operator=="<<endl;
	if (_login == rhs._login && _user_name == rhs._user_name)
		return true;
	return false;
}

inline bool UserProfile::operator!=(const UserProfile &rhs)
{
    cout<<"operator!="<<endl;
	return  !(*this == rhs);
}

//输出流重载
ostream& operator<<(ostream &os, const UserProfile &rhs)
{// 输出格式：qing Beginner 12 100 10 10%
	os << rhs.login() << ' '
		<< rhs.level() << ' '
		<< rhs.login_count() << ' '
		<< rhs.guess_count() << ' '
		<< rhs.guess_correct() << ' '
		<< rhs.guess_average() << '%'<<endl;
	return os;  //不要忘了要返回输出量os
}

//静态static数据成员初始化
map<string, UserProfile::ulevel> UserProfile::_level_map;
void UserProfile::init_level_map()
{
	_level_map["Beginner"] = Beginner;          //等价于dic={"Beginner":0,"Intermediate":1,"Advanced":2,"Guru":3}
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

//定义level函数,返回的是等级的字符串string形式。
inline string UserProfile::level() const
{
	static string _level_table[] = { "Beginner", "Intermediate", "Advanced", "Guru" };
	return _level_table[_user_level]; //枚举元素作为常量，是有值的，分别为0, 1, 2, 3, 4.....
}

//定义reset_level函数，得到_user_level参数
inline void UserProfile::reset_level(const string &level)
{
	map<string, ulevel>::iterator it;
	if (_level_map.empty())
		init_level_map();
	//确保level的确代表一个可识别的用户等级
	_user_level = ((it = _level_map.find(level)) != _level_map.end())
		? it->second : Beginner;
}


//输入流重载
istream& operator>>(istream &is, UserProfile &rhs)
{
	string login, level;
	is >> login >> level;

	int lcount, gcount, gcorrect;
	is >> lcount >> gcount >> gcorrect;

	rhs.reset_login(login);
	rhs.reset_level(level);
	rhs.reset_login_count(lcount);
	rhs.reset_guess_count(gcount);
	rhs.reset_guess_correct(gcorrect);

	return is;
}

int chp44Test(){

    UserProfile measure1;
	cout << measure1;

	UserProfile measure2;
	cout << measure2;

	UserProfile measure3("xiaoNong", UserProfile::Advanced);
	cout << measure3;
	measure3.bump_login_count();
	measure3.bump_guess_count(28);
	measure3.bump_guess_correct(20);
	cout << measure3;

	UserProfile measure4;
	cin >> measure4;
	cout << measure4;

    return 0;
}
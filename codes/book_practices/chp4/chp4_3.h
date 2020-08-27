//
// Created by BlazarLin on 2020/8/27.
//

#ifndef CODES_CHP4_1_H
#define CODES_CHP4_1_H

#endif //CODES_CHP4_1_H

#include <string>

using std::string;

// 定义一个好的数据结构包含以下全局变量
string program_name;
string version_stamp;
int version_number;
int tests_run;
int tests_passed;

// 如下数据结构
class globalWrapper{
public:
    static int tests_passed() {return _tests_passed;}
    static int tests_run() {return _tests_run;}
    static int version_number() {return _version_number;}
    static string version_stamp(){return _version_stamp;}
    static string program_name(){return _program_name;}

    static void tests_passed(int val) {_tests_passed=val;}
    static void tests_run(int val){_tests_run=val;}
    static void version_number(int val){_version_number=val;}
    static void version_stamp(const string& val){_version_stamp=val;}
    static void program_name(const string& npn){_program_name=npn;}

private:
    static string _program_name;
    static string _version_stamp;
    static int _version_number;
    static int _tests_run;
    static int _tests_passed;
};

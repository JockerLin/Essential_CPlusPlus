//
// Created by BlazarLin on 2020/8/28.
//

#ifndef CODES_CHP7_H
#define CODES_CHP7_H

#endif //CODES_CHP7_H

#include <iostream>
#include <fstream>
#include <vector>
#include <alloca.h>

using namespace std;

//7.1 修正如下的错误程序

int *alloc_and_init(string file_name){
    ifstream infile(file_name);
    int elem_cnt;
    infile>>elem_cnt;
    int *pi = allocate_array(elem_cnt);

    int elem;
    int index=0;
    while(infile>>elem)
        pi[index++]=elem;

    sort_array(pi, elem_cnt);
    register_data(pi);
    return pi;
}
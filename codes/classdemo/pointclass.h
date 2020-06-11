//
// Created by pilcq on 2020/6/11.
//

#ifndef CODES_POINTCLASS_H
#define CODES_POINTCLASS_H

#include <iostream>
using namespace std;

//class Point{
//
//private:
//    int xPos;
//    int yPos;
//
//public:
//    void setPoint(int x, int y){
//        xPos = x;
//        yPos = y;
//    }
//
//    void printPoint(){
//        cout<< "x= "<< xPos << endl;
//        cout<< "y= "<< yPos << endl;
//    }
//};



class Point{

private:
    int xPos;
    int yPos;

public:
    void setPoint(int x, int y);
    void printPoint();
};

Point CalculatePoint();

#endif //CODES_POINTCLASS_H

//
// Created by pilcq on 2020/6/11.
//

#include "pointclass.h"

// 类外定义函数要在.c中，.h中会抛错
void Point::setPoint(int x, int y) {
    xPos = x;
    yPos = y;
}

void Point::printPoint() {
    cout<< "x= "<< xPos << endl;
    cout<< "y= "<< yPos << endl;
}

Point CalculatePoint(){
    Point M;
    M.setPoint(30, 40);
    M.printPoint();
    return M;
}
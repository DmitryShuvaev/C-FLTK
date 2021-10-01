#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Dependicies.h"
#include <FL/fl_draw.H>
#include <cmath>
#include <iostream>
using namespace std;
class Triangle
{
    public:
        Triangle(int width, int height);
        virtual ~Triangle();

    void tri(int n,Point a,Point b,Point c);
    Point mid(Point p1,Point p2);
    
    int level=0;
    int i=0;
    Point a,b,c;
};

#endif // TRIANGLE_H

#ifndef PLUS_H
#define PLUS_H
#include "Dependicies.h"
#include <FL/fl_draw.H>
#include <cmath>
#include <iostream>
using namespace std;

class Plus
{
    public:
        Plus(int width, int height);
        virtual ~Plus();
        void pls(int n,Point center,int line);
        
    int level=0;
    int i=0;
    Point a,b,c,d,center;
    int linelen;

};

#endif // PLUS_H

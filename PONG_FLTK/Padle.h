#include "headers.h"
#ifndef __PADLE_H
#define __PADLE_H


class Padle : public Fl_Widget { 
    void draw() {                                       // Take full control of drawing our widget
	  //fl_color(FL_WHITE);
      fl_rectf(x(), y(), w(), h(),FL_WHITE);  
	  //fl_circle(x(), y()+50, 20);
    }
public:
    Padle(int X,int Y,int W,int H) : Fl_Widget(X,Y,W,H) {
    }

};

#endif
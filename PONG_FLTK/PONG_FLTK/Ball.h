#include "headers.h"
#include "Padle.h"
#ifndef __BALL_H
#define __BALL_H


class Ball : public Fl_Widget { 
    void draw() {                                       // Take full control of drawing our widget
	  fl_color(FL_YELLOW);

	  fl_pie(x(), y(), w(), h(), 0.0, 360.0);
    }
public:
    Ball(int X,int Y,int W,int H) : Fl_Widget(X,Y,W,H) {
		ballX=X;ballY=Y;
    }
	void updatePos(int xp,int yp){
		ballX=xp;ballY=yp;
     position(ballX,ballY);   
	 //redraw();
	}
	bool collides(Padle *paddle){
		if(ballX>paddle->x()+paddle->w()||paddle->x()>ballX+this->w())
         return false;
		if(ballY>paddle->y()+paddle->h()||paddle->y()>ballY+this->h())
		 return false;
		return true;
	}
	double ballX,ballY;
};

#endif
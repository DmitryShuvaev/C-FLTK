#include "headers.h"

#define BG_COLOR   45
#define TICK_COLOR 50
#define CIRC_COLOR 0
class MyTimer : public Fl_Box {
	 int counterRED,counterYELLOW,counterGREEN,
		 x1,y1,y2,y3;
    void draw();
	void drawYELOW();
	void drawTEXT(char *secs,int);
    static void Timer_CB(void *userdata) {
        MyTimer *o = (MyTimer*)userdata;
        o->redraw();
        Fl::repeat_timeout(1, Timer_CB, userdata);
    }
public:
    // CONSTRUCTOR
    MyTimer(int X,int Y,int W,int H,const char*L=0) : Fl_Box(X,Y,W,H,L) {
        box(FL_FLAT_BOX);
        color(BG_COLOR);
        Fl::add_timeout(0, Timer_CB, (void*)this);
		counterRED=0;
		counterYELLOW=0;
		counterGREEN=0;
		    x1 = (int)(x() + w()/2),
            y1 = 50,
			y2=y1+50,
			y3=y2+50;

    }
};
#ifndef WINDOW_H
#define WINDOW_H
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Button.H> // For the button class
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/fl_draw.H>
#include <iostream>
//#include <Windows.h>
//#include "Box.h"
#include "Line.h"
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include <stdexcept>
#include <limits>
#define BG_COLOR   45
#define TICK_COLOR 50
#define CIRC_COLOR 0
using namespace std;
//https://www.youtube.com/watch?v=A86COO8KC58
class Windowi: public Fl_Double_Window
{
    public:

        Windowi(int width, int height, char* title=0);
        Windowi(int x,int y,int width, int height, char* title=0);
        virtual ~Windowi();
        void segmentIntersect(Line &l1,Line &l2);
    static void Timer_CB(void *userdata)
    {
        Windowi *o = (Windowi*)userdata;
        o->redraw();
    }

    void draw()
    {

        Fl_Double_Window::draw();
        fl_color(FL_BLACK);
        fl_line_style(FL_SOLID,3);
        //fl_line(0, 0, 500, 500);
        l1->draw();
        l2->draw();
        segmentIntersect(*l1,*l2);
        if(pintersec!=NULL)
        {
            //cout<<"intersect"<<endl;
            fl_color(FL_RED);
            pintersec->draw();
        }

        //cout<<"redraw\n";
    }
//int xx=0,yy=0;
//float angl=3.14;

Line *l1,*l2;
Box *pintersec=NULL;
};

#endif // WINDOW_H

#ifndef BOX_H
#define BOX_H
#include <FL/Fl_Box.h>
#include <FL/fl_draw.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Double_Window.H>
#include <iostream>
#include <vector>
using namespace std;
#include <FL/Fl.H>
class Box: public Fl_Box
{
    public:
        struct POINT
        {
            int x,y;
        };
 // Constructor
 Box(int t, int l, int width, int height,Fl_Double_Window *G_win
);

void draw()
{
 //color(FL_BLACK);
 //fl_line_style(FL_SOLID,3);
 fl_pie(xx1, yy1, r*2, r*2, 0.0, 360.0);
 //fl_line(x1, y1, x2, y2);
}
 // Event handler
 int handle(int e);
        virtual ~Box();
Fl_Double_Window *wn;
vector<POINT>points;
int xx1;
int yy1;
int r;
};

#endif // BOX_H

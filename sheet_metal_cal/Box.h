#ifndef BOX_H
#define BOX_H
#include <FL/Fl_Box.h>
#include <FL/fl_draw.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Window.H>
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
 Box(int t, int l, int width, int height,Fl_Window *G_win);

void draw()
{

draw_filled_shape1();
//draw outlined figure
draw_outlined_shape1();
draw_filled_shape2();
draw_outlined_shape2();
draw_text();
}
void draw_filled_shape1();
void draw_filled_shape2();
void draw_outlined_shape1();
void draw_outlined_shape2();
void draw_text();
 // Event handler
 int handle(int e);
        virtual ~Box();
Fl_Window *wn;

vector<POINT>points;
int xx1;
int yy1;
int r;
};

#endif // BOX_H

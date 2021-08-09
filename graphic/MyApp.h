#ifndef MYAPP_H
#define MYAPP_H
#include <FL/Fl.H>
#include <FL/Fl_Window.h>
#include <FL/fl_draw.H>
#include <iostream>
#include "Y_x_square.h"
#include "Graphic.h"
using namespace std;
class MyApp: public Fl_Window
{
    public:
        MyApp(int x,int y,int width, int height, char* title=0);
        virtual ~MyApp();
        int handle(int event);
    protected:

    private:
        void draw_line()
        {
                ys.init(sep);
                ys.add_points_y_pow_x();
                ys.inrement_sep(sep);
                int lsiz=ys.lines.size();
                for(int i=0;i<lsiz;i++)
                {
                 fl_color(FL_GREEN);
                 fl_line_style(FL_SOLID,2);
                 fl_line(g.zero_x+ys.lines[i]->p1.x,g.zero_y-ys.lines[i]->p1.y,
                         g.zero_x+ys.lines[i]->p2.x,g.zero_y-ys.lines[i]->p2.y);
                 //
                 g.draw_conectedLines(ys.lines[i]->p2);
                }

        }
        void draw()
        {
            Fl_Window::draw();
            g.draw_graph(&sep);
            draw_line();
        }

Graphic g;
Y_x_square ys;
double curx=g.zero_x,cury=g.zero_y;
double sep=100;
};

#endif // MYAPP_H

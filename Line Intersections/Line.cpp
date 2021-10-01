#include "Line.h"
Line::Line(Fl_Double_Window *G_win)
{
    //ctor
    wn=G_win;
    point1 = new Box(wn->w()/2, wn->h()/2, 20, 20,wn);
    point2 = new Box(wn->w()/4, wn->h()/4, 20, 20,wn);
}
//----------------------------------------------------
void Line::draw()
{
    point1->draw();
    point2->draw();
    fl_line(point1->xx1+10, point1->yy1+10, point2->xx1+10, point2->yy1+10);

}
//----------------------------------------------------
Line::~Line()
{
    //dtor
}

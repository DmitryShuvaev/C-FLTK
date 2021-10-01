#include "Window.h"



Mwindow::~Mwindow()
{
    //if(tr!=NULL)
    //delete tr;
}
Mwindow::Mwindow(int width, int height, char* title)
         : Fl_Window(width, height, title)

{


}
Mwindow::Mwindow(int x,int y,int width, int height, char* title)
         : Fl_Window(x,y,width, height, title)
{
    //tr=new Triangle(width,height);
    pl=new Plus(width,height);
}

void Mwindow::draw()
{
    Fl_Window::draw();
    fl_color(FL_BLUE);
    fl_line_style(FL_SOLID,3);
    //tr->tri(tr->level,tr->a,tr->b,tr->c);
    pl->pls(pl->level,pl->center,pl->linelen);
}


#include "Window.h"


WWindow::WWindow(int x,int y,int width, int height, char* title)
         : Fl_Double_Window(x,y,width, height, title),b(40,40,400,800)
{
    color(FL_BLACK);

}
void WWindow:: draw()
{
    Fl_Double_Window::draw();
    b.draw_boad();

}
WWindow::~WWindow()
{
    //dtor
}

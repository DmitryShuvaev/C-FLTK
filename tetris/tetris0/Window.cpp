#include "Window.h"


Window::Window(int x,int y,int width, int height, char* title)
         : Fl_Double_Window(x,y,width, height, title)
{
    color(FL_BLACK);

}
Window::~Window()
{
    //dtor
}

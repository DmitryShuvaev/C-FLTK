#include "Button.h"

Button::Button(int x,int y,int width, int height,char* title):
    Fl_Button(x,y,width, height, title)
{
    //ctor
    n=0;
}

Button::~Button()
{
    //dtor
}

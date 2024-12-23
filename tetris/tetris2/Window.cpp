#include "Window.h"


WWindow::WWindow(int x,int y,int width, int height, char* title)
         : Fl_Double_Window(x,y,width, height, title),b(40,40,400,800)
{
    bc=new Board_calc();
    ip=new I_piece(bc,r);
    color(FL_BLACK);

}
void WWindow:: draw()
{
    Fl_Double_Window::draw();
    b.draw_boad();
    draw_piece();
}
 void WWindow::draw_piece()
{
    for(int i=0;i<4;i++)
    {
        //cout<<r[i]<<endl;
        if(r[i]!=NULL)
        r[i]->draw_rec();
    }

}
WWindow::~WWindow()
{
    //dtor
}

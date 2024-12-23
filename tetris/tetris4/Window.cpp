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
int WWindow::handle(int event)
{
   int ret=Fl_Double_Window::handle(event);
    if(event==FL_KEYUP)
    {
        if(Fl::event_key()==113||Fl::event_key()==81)
        {
          if(curpiece==0){
          if(ip!=NULL){
            ip->dir++;
            if(ip->dir>3)ip->dir=0;
          ip->add_piece(bc,r);
          }
          }
        }
        else if(Fl::event_key()==100||Fl::event_key()==68)
        {
            if(curpiece==0){
             if(ip!=NULL)
            ip->move_pieces_right(bc,r);
            }
        }
        else if(Fl::event_key()==97||Fl::event_key()==65)
        {
            if(curpiece==0){
            if(ip!=NULL)
            ip->move_pieces_left(bc,r);
            }
        }
        else if(Fl::event_key()==32)//space pressed
        {
         //timerv=timerv/30;
         if(ip!=NULL){
           ip->move_down(r);
             }
        }
        redraw();
    }
    return ret;
}
WWindow::~WWindow()
{
    //dtor
    delete bc,ip;
}

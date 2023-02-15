#ifndef MYAPP_H
#define MYAPP_H
#include <FL/Fl.H>
#include <FL/Fl_Window.h>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include "Graph.h"
#include "Board_calc.h"
#include "Pieces.h"
#include <iostream>
using namespace std;
class MyApp: public Fl_Double_Window
{
    public:
        MyApp(int x,int y,int width, int height, char* title=0);
        virtual ~MyApp();

    private:
        void draw_line()
        {

            fl_color(FL_RED);
            //fl_line_style(FL_DASH,10);
           //fl_rectf(200,y,40,40);
           if(ip!=NULL)
           {
               ip->draw_piece();
           }
           b.draw_from_array(bc->board);
        }
        void draw()
        {
            Fl_Double_Window::draw();
            draw_line();
        }
        int handle(int event)
        {
           int ret=Fl_Double_Window::handle(event);
            if(event==FL_KEYUP)
            {
                if(Fl::event_key()==113||Fl::event_key()==81)
                {
                  if(curpiece==0){
                  if(ip!=NULL){
                  if(ip->dir==0)ip->dir=1;
                  else if(ip->dir==1)ip->dir=2;
                  else if(ip->dir==2)ip->dir=3;
                  else ip->dir=0;
                  ip->rotate_piece(bc);
                  }
                  }
                }
                else if(Fl::event_key()==100||Fl::event_key()==68)
                {
                    if(curpiece==0){
                     if(ip!=NULL)
                    ip->move_pieces_right(bc);
                    }
                }
                else if(Fl::event_key()==97||Fl::event_key()==65)
                {
                    if(curpiece==0){
                    if(ip!=NULL)
                    ip->move_pieces_left(bc);
                    }
                }
                else if(Fl::event_key()==32)//space pressed
                {
                 timerv=timerv/30;
                }
                redraw();
            }
            return ret;
        }
        static void Timer_CB(void *userdata) {
        MyApp *o = (MyApp*)userdata;
        o->redraw();

    if(o->ip!=NULL){
    o->ip->move_down();
    if(o->curent_game)
    {
    if(o->bc->check_col_y(o->ip->r))
    {
     o->start_new_piece(o);

    }
    }
    }
    if(o->curent_game)
        Fl::repeat_timeout(o->timerv, o->Timer_CB, userdata);
    }
    void start_new_game(MyApp*win);
    void start_new_piece(MyApp*win);
int sep=0;
int y=0;
Board b;
float timerv=1;
I_piece*ip=NULL;
Board_calc*bc=NULL;
int curpiece=0;
bool curent_game=true;
};

#endif // MYAPP_H

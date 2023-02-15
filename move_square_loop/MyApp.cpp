#include "MyApp.h"

MyApp::MyApp(int x,int y,int width, int height, char* title)
         : Fl_Double_Window(x,y,width, height, title),
         b(40,40,400,800)
{
    //ctor
    bc=new Board_calc();
    bc->board[1][1]=1;
    ip=new I_piece(bc);
    bc->Board_print();
    color(FL_BLACK);
    sep=10;
    Fl::add_timeout(timerv, Timer_CB, (void*)this);
}

MyApp::~MyApp()
{
    //dtor
}
void MyApp::start_new_game(MyApp*win)
{
        if(win->bc->can_add_to_board(win->ip->r))
        {
            //cout<<"can";

        }
        else
        {cout<<"cant add";
         win->curent_game=false;
         delete win->ip;
         win->ip=NULL;
        }
}//
void MyApp::start_new_piece(MyApp*win)
{
     win->bc->add(win->ip->r);
     //else win->curent_game=false;
     win->bc->shift_y();

     //win->bc->Board_print();
     //win->ipt=win->ip;
     if(win->ip!=NULL)
     delete win->ip;
     win->ip=NULL;
     win->timerv=1;
     if(win->bc->check_level())
    {
         win->bc->Board_print();
         win->bc->init();
         Fl::remove_timeout(win->Timer_CB);
         win->curent_game=false;
         cout<<"Finish"<<endl;

    }else
    {
        //I_piece tp(&win->bc);
       if(win->ip==NULL)
       {
        //
        win->ip=new I_piece(win->bc);
        win->start_new_game(win);
        //delete win->ipt;

       }


    }

}

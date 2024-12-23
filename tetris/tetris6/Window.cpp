#include "Window.h"


WWindow::WWindow(int x,int y,int width, int height, char* title)
         : Fl_Double_Window(x,y,width, height, title),b(40,40,400,800)
{
    bc=new Board_calc();
    curpiece=4;
    if(curpiece==0)
    {
     ip=new I_piece(bc,r);
    }else if(curpiece==1)
    {
     np=new N_piece(bc,r);
    }else if(curpiece==2)
    {
     tp=new T_piece(bc,r);
    }else if(curpiece==3)
    {
     sp=new S_piece(bc,r);
    }else if(curpiece==4)
    {
     lp=new L_piece(bc,r);
    }


    color(FL_BLACK);

}
void WWindow:: draw()
{
    Fl_Double_Window::draw();
    draw_line();
}/********************/
void WWindow::draw_line()
{
    fl_color(FL_RED);

       if(ip!=NULL||np!=NULL||tp!=NULL||sp!=NULL||lp!=NULL)
       {
           draw_piece();
       }


   b.draw_from_array(bc->board);
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
          }else if(curpiece==1){
              if(np!=NULL){
                np->dir++;
                if(np->dir>3)np->dir=0;
                np->add_piece(bc,r);
              }
          }else if(curpiece==2){
              if(tp!=NULL){
                tp->dir++;
                if(tp->dir>3)tp->dir=0;
                tp->add_piece(bc,r);
              }
          }else if(curpiece==4){
              if(lp!=NULL){
                lp->dir++;
                if(lp->dir>3)lp->dir=0;
                lp->add_piece(bc,r);
              }
          }
        }/**************************/
        else if(Fl::event_key()==100||Fl::event_key()==68)
        {
            if(curpiece==0){
             if(ip!=NULL)
            ip->move_pieces_right(bc,r);
            }else if(curpiece==1){
             if(np!=NULL)
            np->move_pieces_right(bc,r);
            }else if(curpiece==2){
             if(tp!=NULL)
            tp->move_pieces_right(bc,r);
            }else if(curpiece==3){
             if(sp!=NULL)
            sp->move_pieces_right(bc,r);
            }else if(curpiece==4){
             if(lp!=NULL)
            lp->move_pieces_right(bc,r);
            }
        }
        else if(Fl::event_key()==97||Fl::event_key()==65)
        {
            if(curpiece==0){
            if(ip!=NULL)
            ip->move_pieces_left(bc,r);
            }else if(curpiece==1){
             if(np!=NULL)
             np->move_pieces_left(bc,r);
            }else if(curpiece==2){
             if(tp!=NULL)
             tp->move_pieces_left(bc,r);
            }else if(curpiece==3){
             if(sp!=NULL)
             sp->move_pieces_left(bc,r);
            }else if(curpiece==4){
             if(lp!=NULL)
             lp->move_pieces_left(bc,r);
            }
        }
        else if(Fl::event_key()==32)//space pressed
        {
         //timerv=timerv/30;
         if(curpiece==0){
         if(ip!=NULL){
           ip->move_down(r);
             }
         }else if(curpiece==1){
         if(np!=NULL){
           np->move_down(r);
             }
         }else if(curpiece==2){
         if(tp!=NULL){
           tp->move_down(r);
             }
         }else if(curpiece==3){
         if(sp!=NULL){
           sp->move_down(r);
             }
         }else if(curpiece==4){
         if(lp!=NULL){
           lp->move_down(r);
             }
         }
        if(curent_game)
        {
        if(bc->check_col_y(r))
        {
        start_new_piece();

        }
        }
        }
        redraw();
    }
    return ret;
}/********************/
void WWindow::start_new_piece()
{
     bc->add(r);
     bc->shift_y();
     if(curpiece==0){
     if(ip!=NULL){
        ip->delet_pieces(r);
        delete ip;
        ip=NULL;
     }
     }else if(curpiece==1){
     if(np!=NULL){
        np->delet_pieces(r);
        delete np;
        np=NULL;
     }
     }else if(curpiece==2){
     if(tp!=NULL){
        tp->delet_pieces(r);
        delete tp;
        tp=NULL;
     }
     }else if(curpiece==3){
     if(sp!=NULL){
        sp->delet_pieces(r);
        delete sp;
        sp=NULL;
     }
     }else if(curpiece==4){
     if(lp!=NULL){
        lp->delet_pieces(r);
        delete lp;
        lp=NULL;
     }
     }
     timerv=1;
     if(bc->check_level())
    {
         bc->Board_print();
         bc->init();
         //Fl::remove_timeout(Timer_CB);
         curent_game=false;
         cout<<"Finish"<<endl;

    }else
    {
       if(curpiece==0){
       if(ip==NULL)
       {
        ip=new I_piece(bc,r);
        //cout<<r[0]->x<<endl;

       }
       }else if(curpiece==1){
        np=new N_piece(bc,r);
       }else if(curpiece==2){
        if(tp==NULL){
        tp=new T_piece(bc,r);
        }
       }else if(curpiece==3){
        if(sp==NULL){
        sp=new S_piece(bc,r);
        }
       }else if(curpiece==4){
        if(lp==NULL){
        lp=new L_piece(bc,r);
        }
       }
       start_new_game();
    }

}/*****************/
void WWindow::start_new_game()
{
        if(bc->can_add_to_board(r))
        {
            //cout<<"can";
        }
        else
        {
         cout<<"cant add";
         curent_game=false;
         if(ip!=NULL){
         delete ip;
         ip=NULL;
         }else if(np!=NULL){
         delete np;
         np=NULL;
         }else if(tp!=NULL){
         delete tp;
         tp=NULL;
         }else if(sp!=NULL){
         delete sp;
         sp=NULL;
         }else if(lp!=NULL){
         delete lp;
         lp=NULL;
         }
        }
}//
WWindow::~WWindow()
{
    //dtor
    delete bc,ip,np,tp,sp,lp;
}

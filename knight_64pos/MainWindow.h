#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Pixmap.H>
#include <string>
#include <iostream>

#include <sstream>
#include "DrawLine.h"
#include "Text.h"
#include "Knight.h"
using namespace std;
class MainWindow:Fl_Window
{
    public:
        MainWindow(int width, int height,const char* title=0);
        virtual ~MainWindow();
        struct Knight_pos
        {
        int x,y;
        };
        static	void button1_cb(Fl_Widget* buttonptr,void* o);
        void cal_cb(int n);
    static void Timer_CB(void *userdata)
    {
        MainWindow *o = (MainWindow*)userdata;
        o->redraw();
        static int i=0;
        if(i<o->coords.size())
        {

            o->show_knightoni(i);
            i++;
        }else
        {
            Fl::remove_timeout(o->Timer_CB, (void*)o);
            return;
        }
        cout<<i<<endl;
        Fl::repeat_timeout(1, Timer_CB, userdata);
    }//END TIMER_CB function
    void show_knightoni(int i)
    {
        char n[80];
        if(k->G[coords[i].y][coords[i].x]>=10)
        txte[coords[i].y][coords[i].x]->draw_coord((coords[i].x*BOXSIZE+8)+10,(coords[i].y*BOXSIZE+8)+10,20,20,40);
        else txte[coords[i].y][coords[i].x]->draw_coord(coords[i].x*BOXSIZE+8,(coords[i].y*BOXSIZE+8)+10,20,20,40);
           sprintf(n, "%2ld", k->G[coords[i].y][coords[i].x]);
           txte[coords[i].y][coords[i].x]->drawText(n);
    }
    struct charArr
    {
     char n[80];
     Text txte;
    };
//
bool notDone(int t[boardSize][boardSize])
{
    bool done=true;
     for(int y=0;y<boardSize;y++)
      for(int x=0;x<boardSize;x++)
      {
          if(t[y][x]!=-1){done=false;
          return done;
          }
      }
      return done;
}
Knight_pos findMin()
{
    Knight_pos p;
    int xmin=-8,ymin=-8;

    for(int y=0;y<boardSize;y++)
    {
      for(int x=0;x<boardSize;x++)
      {
       if(Temparr[y][x]!=-1)
       {
        xmin=x;ymin=y;
        p.x=xmin;p.y=ymin;
        return p;
       }
      }//for
    }//for
    p.x=xmin;p.y=ymin;
    return p;
}//end findMin
void printKnights(Knight *kn)
{

    for(int y=0;y<boardSize;y++)
      for(int x=0;x<boardSize;x++)
      {
       Temparr[y][x]=kn->G[y][x];

      }
      //
       Knight_pos coord;
       int minv;
       coord=findMin();
    while(coord.x!=-8&&coord.y!=-8)
    {
     minv=Temparr[coord.y][coord.x];
     int xmin=coord.x,ymin=coord.y;

    for(int y=0;y<boardSize;y++)
    {

      for(int x=0;x<boardSize;x++)
      {
       if(Temparr[y][x]<minv&&Temparr[y][x]!=-1)
       {
           minv=Temparr[y][x];
           xmin=x;ymin=y;
       }
      }
    }//end  for loop
      Temparr[ymin][xmin]=-1;
      coord.x=xmin;coord.y=ymin;
      coords.push_back(coord);
     // cout<<"minv="<<coords[0].x<<endl;
      coord=findMin();
    }//end while
//          for(int y=0;y<boardSize;y++)
//      for(int x=0;x<boardSize;x++)cout<<Temparr[y][x]<<endl;
cout<<k->G[coords[2].y][coords[2].x];

}
	Fl_Button *button1;
int Temparr[boardSize][boardSize];
	//
    Knight *k;
    DrawLine l;
    vector<Knight_pos>coords;
    Text *txtX,*txte[BORDERSIZE][BORDERSIZE];

    //charArr kings[BORDERSIZE][BORDERSIZE];
    protected:

    private:
};

#endif // MAINWINDOW_H

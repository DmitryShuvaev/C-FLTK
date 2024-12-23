#ifndef GRAPH_H
#define GRAPH_H
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>

struct Board
{
    Board(int w,int h,int width,int hight)
    {
     this->w=w;this->h=h;
     this->width=width;this->hight=hight;

    }
void draw_boad()
{
    fl_color(FL_WHITE);
    for(int x=0;x<width;x+=w)
    {
        for(int y=0;y<hight;y+=h)
        {
         fl_rect(x,y,w,h);

        }
    }
}
void draw_from_point(int indx,int indy)
{
 fl_color(FL_BLACK);

 fl_rectf(indx,indy,w,h);
}//
void draw_from_array(int board[20][10])
{

        for(int y=0;y<20;y++)
        {
          for(int x=0;x<10;x++)
          {
           if(board[y][x]==1)
           {
            fl_color(FL_RED);
            fl_rectf(x*40,y*40,w,h);
            fl_color(FL_WHITE);
            fl_rect(x*40,y*40,w,h);
           }else
           {
            fl_color(FL_WHITE);
            fl_rect(x*40,y*40,w,h);
           }
          }
        }
}
 int w,h;
 int width,hight;
};

#endif // GRAPH_H

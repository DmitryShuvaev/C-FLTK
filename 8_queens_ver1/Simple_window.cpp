
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/fl_utf8.h>
//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    q()
{
  // -- draw the board itself
for(int y=0;y<8;y++){
    for(int x=0;x<8;x++){
    if(y%2==0){
    if (x%2==0){
     boxes[y][x]=new Graph_lib::Rectangle(Point(BORDER+x*BOXSIZE,BORDER+y*BOXSIZE),BOXSIZE-BORDER,BOXSIZE-BORDER);
     boxes[y][x]->set_fill_color((Fl_Color)10);

     attach(*boxes[y][x]);
     }
    }else{
    if (x%2!=0){
     boxes[y][x]=new Graph_lib::Rectangle(Point(BORDER+x*BOXSIZE,BORDER+y*BOXSIZE),BOXSIZE-BORDER,BOXSIZE-BORDER);
     boxes[y][x]->set_fill_color((Fl_Color)10);

     attach(*boxes[y][x]);
     }
    }
    }

}
  // -- draw outlines around the fileds
      fl_color(FL_DARK3);
  for (int x=0; x<9; x++) {
    boxesborders[x]=new Graph_lib::Rectangle(Point(x*BOXSIZE,0),BORDER,BOXSIZE*8);
    boxesborders[x]->set_fill_color(FL_DARK3);
    attach(*boxesborders[x]);
    boxesbordersv[x]=new Graph_lib::Rectangle(Point(0,x*BOXSIZE),BOXSIZE*8,BORDER);
    boxesbordersv[x]->set_fill_color(FL_DARK3);
    attach(*boxesbordersv[x]);
  }
    add_queens();
    show();
}//

void Simple_window::add_queens()
{
 int c=0;
 for(int y=0;y<8;y++){

  for(int x=0;x<8;x++)
  {
    if(q.chese_board[y][x]>0)
    {
     queen_light[c++]=new Image(Point(x*BOXSIZE+8,y*BOXSIZE+8),"Resources/Chess_qlt60.png");
    }
  }

 }
  for(int y=0;y<8;y++)attach(*queen_light[y]);
}














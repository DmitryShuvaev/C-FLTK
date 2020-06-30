#ifndef DRAWLINE_H
#define DRAWLINE_H
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#define BORDERSIZE 5
#define BOXSIZE 52
#define BORDER 4
#define BOARDSIZE (BORDERSIZE*BOXSIZE+BORDER)

class DrawLine: public Fl_Widget
{
    public:
        DrawLine(): Fl_Widget(0,0,0,0,0){}
        DrawLine(int X, int Y, int W, int H, const char*L=0) : Fl_Widget(X,Y,W,H,L) {

    }

        virtual ~DrawLine();
    void draw() {
    fl_line_style(FL_SOLID,3);
       // fl_rect(x1,y1,20,20);//draws not filled rectangle
     // -- draw the board
     fl_color(FL_WHITE);
     fl_rectf(0,0,BOARDSIZE,BOARDSIZE);
for(int y=0;y<BORDERSIZE;y++){
    for(int x=0;x<BORDERSIZE;x++){
    if(y%2==0){
    if (x%2==0){
     fl_color((Fl_Color)10);
     //draws filled rectangle
     fl_rectf(BORDER+x*BOXSIZE,BORDER+y*BOXSIZE,BOXSIZE-BORDER,BOXSIZE-BORDER);
     fl_color(FL_BLACK);
     //fl_rect(BORDER+x*BOXSIZE,BORDER+y*BOXSIZE,BOXSIZE-BORDER,BOXSIZE-BORDER);//draws not filled rectangle
     }
    }else
    {
        if (x%2!=0)
        {
         fl_color((Fl_Color)10);
         fl_rectf(BORDER+x*BOXSIZE,BORDER+y*BOXSIZE,BOXSIZE-BORDER,BOXSIZE-BORDER);
         fl_color(FL_BLACK);
     //fl_rect(BORDER+x*BOXSIZE,BORDER+y*BOXSIZE,BOXSIZE-BORDER,BOXSIZE-BORDER);//dr
        }
    }

    }
    }//end for loop
    // -- draw outlines around the fileds
      for (int x=0; x<BORDERSIZE+1; x++)
      {
       fl_rectf(x*BOXSIZE,0,BORDER,BOXSIZE*BORDERSIZE);
       fl_color(FL_DARK3);
       fl_rectf(0,x*BOXSIZE,BOXSIZE*BORDERSIZE,BORDER);
      }
  }

};

#endif // DRAWLINE_H

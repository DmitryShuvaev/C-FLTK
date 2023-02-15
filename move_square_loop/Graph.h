#ifndef GRAPH_H
#define GRAPH_H
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>

struct Rectangle1
{
 Rectangle1(int x,int y,int w,int h)
{
 this->x=x;this->y=y;
 width=w;
 buffer = new unsigned char[4*w*h];


//color((Fl_Color)0);
}
void color(Fl_Color c) {
r = (c >> 24);
g = (c >> 16);
b = (c >> 8);
fill_buffer();

}
void fill_buffer() {
uchar *p = buffer;
for (int i = 0; i < 4*width*height; i+=4) {
*p++ = r;
*p++ = g;
*p++ = b;
*p++ = alpha;
}
}

void set_alpha(unsigned char a) {
alpha = a;
fill_buffer();

}
void draw_rec()
{
    //fl_color(FL_BLACK);
    fl_color(FL_RED);
    //color(fl_rgb_color(255,0,0));
    fl_color(0,255,0);
    fl_rectf(x,y,width,width);
    fl_color(FL_WHITE);
    fl_rect(x,y,width,width);
}
int x=0,y=0;
int width=40;
int height=40;
unsigned char* buffer;
unsigned char r;
unsigned char g;
unsigned char b;
unsigned char alpha;
Fl_Color *fl_rgb_color;
};
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

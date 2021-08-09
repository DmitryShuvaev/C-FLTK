#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <FL/fl_draw.H>
#include <iostream>
#include "Depend.h"
using namespace std;

class Graphic
{
    public:
        Graphic();
        virtual ~Graphic();
void draw_graph(double *sep)
{
            fl_color(FL_YELLOW);
            char secs[80];
            fl_line_style(FL_SOLID,2);
            fl_line(zero_x,0,250,500);
            fl_line(0,zero_y,500,250);
            sprintf(secs, "x");
                //draw x text
            fl_font(FL_HELVETICA,20);
            fl_draw(secs, zero_x+200, zero_y+30);
            sprintf(secs, "y");
            fl_draw(secs, zero_x-40, zero_y-220);
            int temp=*sep;

            for(int x=*sep, i=1;x<zero_x-*sep;i++,x+=*sep)
            {
                //sep line x ax
                if(temp<40)
                {
                    temp+=*sep;
                }
                else
                {
                fl_color(FL_YELLOW);
                if(*sep>60)
                {
                  harphLineX(x-(*sep/2.),i-0.5);
                }
                fl_line(zero_x+(x),zero_y-10,zero_x+(x),zero_y+10);
                fl_color(FL_WHITE);
                fl_font(FL_HELVETICA,16);
                sprintf(secs, "%i", i);
                //draw x text
                fl_draw(secs, zero_x+(x), zero_y+(14));
                temp=*sep;

                }
            }
            temp=*sep;
            for(int y=*sep,i=1;y<zero_y-*sep;i++,y+=*sep)
            {
                //sep line y ax
                if(temp<40)
                {
                    temp+=*sep;

                }
                else
                {
                fl_color(FL_YELLOW);
                if(*sep>60)
                {
                  harphLineY(y-(*sep/2.),i-0.5);
                }
                fl_line(zero_x-10,zero_y-(y),zero_x+10,zero_y-(y));
                fl_color(FL_WHITE);

                fl_font(FL_HELVETICA,fontsize);
                sprintf(secs, "%i", i);
                //draw y text
                if(i>=100)fl_draw(secs, zero_x-(fontsize+12), zero_y-(y));
                else
                fl_draw(secs, zero_x-(fontsize+4), zero_y-(y));
                temp=*sep;
                }
            }
            //cout<<*sep<<'\n';
           fl_color(FL_YELLOW);
}
void draw_conectedLines(Point p)
{
                fl_color(FL_YELLOW);
                fl_line_style(FL_DASH,1);
                fl_line(zero_x,zero_y-p.y,zero_x+p.x,zero_y-p.y);
                fl_line(zero_x+p.x,zero_y,zero_x+p.x,zero_y-p.y);
                fl_line_style(FL_SOLID,2);
}
void harphLineX(double xv,double i)
{
                fl_color(FL_YELLOW);
                fl_line(zero_x+xv,zero_y-10,zero_x+xv,zero_y+10);
                fl_color(FL_WHITE);
                fl_font(FL_HELVETICA,16);
                char secs[80];
                sprintf(secs, "%.1f", i);
                //draw x text
                fl_draw(secs, zero_x+xv, zero_y+(14));
                cout<<i<<endl;
}
void harphLineY(double yv,double i)
{
                fl_color(FL_YELLOW);
                fl_line(zero_x-10,zero_y-yv,zero_x+10,zero_y-yv);
                fl_color(FL_WHITE);

                fl_font(FL_HELVETICA,fontsize);
                char secs[80];
                sprintf(secs, "%.1f", i);
                //draw y text
                fl_draw(secs, zero_x-(fontsize+8), zero_y-yv);

}
double zero_x,zero_y;
    private:
        int fontsize=16;
};

#endif // GRAPHIC_H

#include "Plus.h"

Plus::Plus(int width, int height)
{
    //ctor
    center.x=width/2;
    center.y=height/2;
    linelen=center.x/2;
    a.x=center.x-linelen;
    a.y=center.y;
    b.x=center.x;
    b.y=center.y+linelen;
    c.x=center.x+linelen;
    c.y=center.y;
    d.x=center.x;
    d.y=center.y-linelen;
    level=7;
}

Plus::~Plus()
{
    //dtor
}

void Plus::pls(int n,Point center,int line)
{

    if(n>0)
    {
        n-=1;
        i+=1;
        cout<<"i="<<i<<endl;
        Point a;
        a.x=center.x-line;
        a.y=center.y;
        Point b;
        b.x=center.x;
        b.y=center.y+line;
        Point c;
        c.x=center.x+line;
        c.y=center.y;
        Point d;
        d.x=center.x;
        d.y=center.y-line;
        fl_line(a.x, a.y, c.x, c.y);
        fl_line(d.x, d.y, b.x, b.y);

        line/=2;
        pls(n,a,line);
        pls(n,b,line);
        pls(n,c,line);
        pls(n,d,line);
        //cout<<"ab="<<ab.x<<endl;
    }
}

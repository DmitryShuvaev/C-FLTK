#include "Triangle.h"

Triangle::Triangle(int width, int height)
{
    //ctor
    a.x=0;
    a.y=height-50;
    b.x=width;
    b.y=height-50;//bottom right
    c.x=width/2;
    double root=pow(3,1.0/2);//root of 3 pow of 2
    c.y=width-(root/2*width)-50;
    //double nthRoot=pow(25,1.0/2);
    //cout<<c.y<<endl;
    i=0;
    level=3;
}

Triangle::~Triangle()
{
    //dtor
}
Point Triangle::mid(Point p1,Point p2)
{
 //calculate midpoint of a line segment
 Point tp;
 tp.x=(p1.x+p2.x)/2;
 tp.y=(p1.y+p2.y)/2;
 return tp;
}
void Triangle::tri(int n,Point a,Point b,Point c)
{

    if(n>0)
    {
        n-=1;
        i+=1;
        cout<<"i="<<i<<endl;
        fl_line(a.x, a.y, b.x, b.y);
        fl_line(b .x, b.y, c.x, c.y);
        fl_line(c.x,c.y, a.x, a.y);
        Point ab=mid(a,b);
        Point ac=mid(a,c);
        Point bc=mid(b,c);
        tri(n,a,ab,ac);
        tri(n,b,ab,bc);
        tri(n,c,ac,bc);
        //mid point of ab
        //cout<<"ab="<<ab.x<<endl;
    }
}
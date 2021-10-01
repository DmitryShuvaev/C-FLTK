#include "Window.h"



Windowi::~Windowi()
{
    //dtor
    //delete box;
}
Windowi::Windowi(int width, int height, char* title)
         : Fl_Double_Window(width, height, title)

{

}
Windowi::Windowi(int x,int y,int width, int height, char* title)
         : Fl_Double_Window(x,y,width, height, title)
{
 l1=new Line(this);
 l2=new Line(this);
 //SetConsoleOutputCP (1251);
 setlocale(LC_ALL,".ACP");
 show();
 //Fl::scheme("plastic");
}
void Windowi::segmentIntersect(Line &l1,Line &l2)
{
    if(pintersec!=NULL)
    {
        delete pintersec;
        pintersec=NULL;
    }
    double A1=l1.point2->yy1-l1.point1->yy1;
    //cout<<A1<<endl;
    double B1=l1.point1->xx1-l1.point2->xx1;
    //cout<<B1<<endl;
    double C1=A1*l1.point1->xx1+B1*l1.point1->yy1;
    //cout<<C1<<endl;
    double A2=l2.point2->yy1-l2.point1->yy1;
    double B2=l2.point1->xx1-l2.point2->xx1;
    double C2=A2*l2.point1->xx1+B2*l2.point1->yy1;
    int denominator=A1*B2-A2*B1;
    if(denominator==0)
    {
        cout<<"den="<<denominator<<endl;
        return;
    }
    double intersectX=(B2*C1-B1*C2)/denominator;
    //cout<<intersectX<<endl;
    double intersectY=(A1*C2-A2*C1)/denominator;
    double rx0=(intersectX-l1.point1->xx1)/(l1.point2->xx1-l1.point1->xx1);
    double ry0=(intersectY-l1.point1->yy1)/(l1.point2->yy1-l1.point1->yy1);
    double rx1=(intersectX-l2.point1->xx1)/(l2.point2->xx1-l2.point1->xx1);
    double ry1=(intersectY-l2.point1->yy1)/(l2.point2->yy1-l2.point1->yy1);
    if(((rx0>=0&&rx0<=1)||(ry0>=0&&ry0<=1))&&
       ((rx1>=0&&rx1<=1)||(ry1>=0&&ry1<=1)) )
    {
        //cout<<"intersect"<<endl;
        pintersec=new Box(intersectX, intersectY, 20, 20,this);
    }

}

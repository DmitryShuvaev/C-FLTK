#ifndef DEPEND_H
#define DEPEND_H
#include <iostream>
using namespace std;
        struct Point
        {
         double x=0,y=0;
         Point(double xv,double yv):x(xv),y(yv){}

        };
        struct Line
        {
            Point p1,p2;
            Line(Point pp1,Point pp2):p1(pp1),p2(pp2){}
            void printline(std::ostream& stream)
            {

            }
            friend std::ostream& operator<< (std::ostream& out, const Line& line)
            {
              out<<"x="<<line.p1.x<<" y="<<line.p1.y<<
              " x2="<<line.p2.x<<" y2="<<line.p2.y<<endl;
              return out;
            }
        };


#endif // DEPEND_H

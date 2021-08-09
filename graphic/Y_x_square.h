#ifndef Y_X_SQUARE_H
#define Y_X_SQUARE_H
#include <cmath>
#include <vector>
#include <iostream>
#include "Depend.h"
using namespace std;

class Y_x_square
{
    public:

        Y_x_square();
        void clearPoints();
//std::ostream& operator<<(ostream& os,const Line l) {
//
//        //cout<<"x="<<p1.x<<" y="<<p1.y<<endl;
//        return os;
//}
        void init(int sep)
        {
            clearPoints();
            this->sep=sep;
            //psize=250/sep;
        }
        double y_powx(double x)
        {

            return pow(x, 2.0);
        }
        void add_points_y_pow_x()
        {
            double t=10./sep;
            double x=0;
            double i=y_powx(x);
            int tempx=x*sep,tempy=i*sep;
            while(tempx<250&&tempy<250)
            {
              i=y_powx(x);
              points.push_back(new Point(x,i));
              x+=t;
              tempx=x*sep;
              tempy=i*sep;
            }

            for(float x=0;x<points.size();x++)
            {
             cout<<"x="<<points[x]->x<<" y="<<points[x]->y<<endl;
            }

             add_lines();
        }
        void inrement_sep(double sep)
        {
            int sze=lines.size();
            for(int i=0;i<sze;i++)
            {
              lines[i]->p1.x*=sep;
              lines[i]->p1.y*=sep;
              lines[i]->p2.x*=sep;
              lines[i]->p2.y*=sep;
              //cout<<lines[i]->p1.x<<'\n';
            }
/*
            for(int i=0;i<lines.size();i++)
            {
             cout<<*lines[i];
            }
*/
        }
        void add_lines()
        {
            int next;
            int siz=points.size();
            for(int i=0;i<siz-1;i++)
            {
              next=i+1;
              Point p=*points[i];
              //cout<<p.x<<endl;
              lines.push_back(new Line(*points[i],*points[next]));
            }
            /*
            for(int i=0;i<lines.size();i++)
            {
             cout<<*lines[i];
            }
            */

        }
        virtual ~Y_x_square();

double x,y,sep=20;;
//int psize;
vector<Point*>points;
vector<Line*>lines;
};

#endif // Y_X_SQUARE_H

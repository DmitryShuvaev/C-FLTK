#include "Box.h"

Box::Box(int t, int l, int width, int height,Fl_Double_Window *G_win)
         :Fl_Box(FL_UP_BOX, t, l, width, height, "")
{
    //ctor
    wn=G_win;
    xx1=t,yy1=l;
    r=10;
}
int Box::handle(int e)
//=======================================================================
{
    static int offset[2] = { 0, 0 };
    static int tex=0,tey,dx=0,dy=0;
    POINT p2;
 switch(e) {
 case FL_ENTER: // When the cursor enters this box
//wn->begin();
 // Change the color to red
 color (FL_RED);
 // Change the label to black
 //labelcolor(FL_WHITE);
//wn->end();
 // Notify window to redraw is needed
 damage(1);
 return 1;
 case FL_LEAVE: // When the cursor leave this box
 // Change the color to gray
 color(FL_GRAY);
 // Change the label to black
 labelcolor(FL_BLACK);
 // Notify window to redraw is needed
 damage(1);
 return 1;
 case FL_PUSH:
     // When mouse button is pushing
        offset[0] = x() - Fl::event_x();    // save where user clicked for dragging
        offset[1] = y() - Fl::event_y();
        //cout<<wn->b->x();
        tex=x();
        tey=y();
        POINT p;
        p.x=x();p.y=y();
        points.push_back(p);
        //points.clear();

        //cout<<"tex="<<tex<<endl;
         // Notify window to redraw is needed
         damage(1);
 return 1;
 case FL_RELEASE: // When release the mouse button

                   points.clear();
                   damage(1);
                   return 1;
                   case FL_DRAG:
                   // When drag the mouse button
                   //cout<<"x="<<x()<<endl;
                   //cout<<" tex="<<tex<<endl;

                    color(FL_YELLOW);
                    p2.x=x();p2.y=y();
                    points.push_back(p2);
                    xx1=offset[0]+Fl::event_x();
                    yy1=offset[1]+Fl::event_y();
                    position(xx1,yy1 );// handle dragging
                 damage(1);
                 wn->redraw();
 return 1;
 default:
 return Fl_Box::handle(e);
 };

}
Box::~Box()
{
    //dtor

}

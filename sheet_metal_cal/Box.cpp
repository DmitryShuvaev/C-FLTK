#include "Box.h"

Box::Box(int t, int l, int width, int height,Fl_Window *G_win)
         :Fl_Box(FL_UP_BOX, t, l, width, height, "")
{
    //ctor
    wn=G_win;
    xx1=t,yy1=l;
    r=10;
}
void Box::draw_outlined_shape1()
{
fl_begin_line();

fl_color(FL_BLACK);
fl_line_style(FL_SOLID,3);
fl_line(x()+134, y()+12, x()+134, y()+145);
int R=69;
fl_arc(x()+203, y()+144, R, 180, 270);
fl_vertex(x()+525, y()+144+R);
fl_arc(x()+525, y()+144, R, -90, 0);
fl_vertex(x()+594, y()+12);
fl_vertex(x()+559, y()+12);
R=33;
fl_arc(x()+526, y()+147, R, 0, -90);
fl_arc(x()+201, y()+146, R, 270, 180);
fl_vertex(x()+168, y()+12);
fl_vertex(x()+134, y()+12);
fl_end_line();
fl_line_style(FL_SOLID,2);
fl_line(x()+116, y()+12, x()+113, y()+22);
fl_line(x()+116, y()+12, x()+118, y()+22);
fl_line(x()+116, y()+12, x()+116, y()+145);
//
fl_line(x()+116, y()+145, x()+113, y()+135);
fl_line(x()+116, y()+145, x()+118, y()+135);
//
fl_line(x()+124, y()+12, x()+113, y()+12);
fl_line(x()+124, y()+145, x()+113, y()+145);
R=85;
fl_begin_line();
fl_arc(x()+134, y()+213, R, 180, 90);
fl_end_line();
fl_line(x()+50, y()+213, x()+48, y()+203);
fl_line(x()+50, y()+213, x()+53, y()+203);
fl_line(x()+134, y()+129, x()+124, y()+127);
fl_line(x()+134, y()+129, x()+124, y()+132);
//
fl_line(x()+116, y()+12, x()+52, y()+12);
fl_line(x()+52, y()+12, x()+54, y()+22);
fl_line(x()+52, y()+12, x()+49, y()+22);
fl_line(x()+52, y()+12, x()+52, y()+213);
//
fl_line(x()+193, y()+213, x()+50, y()+213);
fl_line(x()+134, y()+155, x()+134, y()+278);
fl_line(x()+134, y()+278, x()+591, y()+278);
fl_line(x()+134, y()+278, x()+144, y()+275);
fl_line(x()+134, y()+278, x()+144, y()+280);
fl_line(x()+594, y()+278, x()+581, y()+275);
fl_line(x()+594, y()+278, x()+581, y()+280);
fl_line(x()+594, y()+278, x()+594, y()+155);
fl_line(x()+199, y()+253, x()+199, y()+189);
fl_line(x()+199, y()+253, x()+209, y()+250);
fl_line(x()+199, y()+253, x()+525, y()+253);
fl_line(x()+199, y()+253, x()+209, y()+256);
fl_line(x()+525, y()+253, x()+515, y()+250);
fl_line(x()+525, y()+253, x()+515, y()+256);
fl_line(x()+525, y()+253, x()+525, y()+189);
  fl_line_style(FL_DASHDOT,2);
  fl_circle(x()+201,y()+146,34);
  fl_circle(x()+525,y()+146,34);
  fl_line_style(FL_SOLID,2);
fl_line(x()+536, y()+213, x()+671, y()+213);
fl_line(x()+671, y()+213, x()+668, y()+203);
fl_line(x()+671, y()+213, x()+674, y()+203);
fl_line(x()+671, y()+213, x()+671, y()+12);
fl_line(x()+671, y()+12, x()+674, y()+22);
fl_line(x()+671, y()+12, x()+668, y()+22);
fl_line(x()+671, y()+12, x()+641, y()+12);
fl_line(x()+601, y()+12, x()+631, y()+12);
fl_line(x()+631, y()+12, x()+631, y()+146);
fl_line(x()+631, y()+12, x()+633, y()+22);
fl_line(x()+631, y()+12, x()+628, y()+22);
fl_line(x()+631, y()+146, x()+633, y()+136);
fl_line(x()+631, y()+146, x()+628, y()+136);
fl_line(x()+631, y()+146, x()+601, y()+146);
}
void Box::draw_filled_shape1()
{
    //fl_color(FL_DARK3);
    fl_color(128,128,128);
    fl_line_style(FL_SOLID,3);
    //draw filled figure
    fl_begin_complex_polygon();
    //fl_arc(300.0, 100.0, 50.0, 0.0, 180.0);
    fl_vertex(x()+134, y()+12);
    fl_vertex(x()+134, y()+145);
    //fl_rotate(-5);
    //fl_translate(0, 20);
    int R=69;
    fl_arc(x()+203, y()+144, R, 180, 270);
    //fl_rotate(-180);
    fl_vertex(x()+525, y()+144+R);
    fl_arc(x()+525, y()+144, R, -90, 0);
    fl_vertex(x()+594, y()+12);
    fl_vertex(x()+559, y()+12);
    R=33;
    fl_arc(x()+526, y()+147, R, 0, -90);
    fl_arc(x()+201, y()+146, R, 270, 180);
    fl_vertex(x()+168, y()+12);
    fl_end_complex_polygon();
}//
void Box::draw_filled_shape2()
{
    //fl_color(FL_DARK3);
    fl_color(128,128,128);
    fl_line_style(FL_SOLID,3);
    //draw filled figure
    fl_begin_complex_polygon();
    //fl_arc(300.0, 100.0, 50.0, 0.0, 180.0);
    fl_vertex(x()+195, y()+316);
    fl_vertex(x()+164, y()+400);
    int R=54;
    fl_arc(x()+217, y()+416, R, 163, 270);
    //fl_vertex(x()+490, y()+470);
    R=55;
    fl_arc(x()+490, y()+415, R, 270, 330);
    fl_vertex(x()+603, y()+329);
    fl_vertex(x()+580, y()+315);
    R=27;
    fl_arc(x()+490, y()+416, R, 320, 270);
    fl_arc(x()+217, y()+416, R, 270, 163);
    fl_vertex(x()+220, y()+326);
    fl_end_complex_polygon();
}
void Box::draw_outlined_shape2()
{
  fl_begin_line();
    fl_color(FL_BLACK);
    fl_line_style(FL_SOLID,3);
    fl_vertex(x()+195, y()+316);
    fl_vertex(x()+164, y()+400);
    int R=54;
    fl_arc(x()+217, y()+416, R, 163, 270);
    R=55;
    fl_arc(x()+490, y()+415, R, 270, 330);
    fl_vertex(x()+603, y()+329);
    fl_vertex(x()+580, y()+315);
    R=27;
    fl_arc(x()+490, y()+416, R, 320, 270);
    fl_arc(x()+217, y()+416, R, 270, 163);
    fl_vertex(x()+220, y()+326);
    fl_vertex(x()+195, y()+316);
  fl_end_line();
  fl_line_style(FL_SOLID,2);
  fl_begin_line();
      R=56;
      fl_arc(x()+139, y()+470, R, 70, 180);
  fl_end_line();
  fl_line(x()+158, y()+417, x()+149, y()+412);
  fl_line(x()+158, y()+417, x()+148, y()+417);
  fl_line(x()+83, y()+470, x()+81, y()+460);
  fl_line(x()+83, y()+470, x()+86, y()+460);
  //
  fl_line(x()+182, y()+312, x()+151, y()+395);
  fl_line(x()+182, y()+312, x()+181, y()+322);
  fl_line(x()+182, y()+312, x()+176, y()+320);
  fl_line(x()+151, y()+395, x()+157, y()+387);
  fl_line(x()+151, y()+395, x()+152, y()+385);
  //
  fl_line(x()+186, y()+313, x()+147, y()+299);
  fl_line(x()+147, y()+299, x()+91, y()+453);
  fl_line(x()+91, y()+453, x()+130, y()+467);
  fl_line(x()+151, y()+395, x()+155, y()+397);
  fl_line(x()+147, y()+299, x()+146, y()+309);
  fl_line(x()+147, y()+299, x()+141, y()+307);
  //
  fl_line(x()+91, y()+453, x()+97, y()+444);
  fl_line(x()+91, y()+453, x()+92, y()+442);
  //
  fl_line_style(FL_DASHDOT,2);
  fl_circle(x()+217,y()+416,27);
  fl_circle(x()+490,y()+416,27);
  fl_line_style(FL_DASH,2);
  fl_line(x()+139, y()+470, x()+74, y()+470);
  fl_line_style(FL_SOLID,2);
  fl_line(x()+139, y()+480, x()+139, y()+541);
  fl_line(x()+139, y()+541, x()+521, y()+541);
  fl_line(x()+521, y()+541, x()+521, y()+480);
  fl_line(x()+217, y()+513, x()+490, y()+513);
  fl_line(x()+217, y()+513, x()+217, y()+426);
  fl_line(x()+490, y()+513, x()+490, y()+426);

  fl_line(x()+217, y()+513, x()+227, y()+511);
  fl_line(x()+217, y()+513, x()+227, y()+516);
  fl_line(x()+490, y()+513, x()+480, y()+516);
  fl_line(x()+490, y()+513, x()+480, y()+511);
  //
  fl_line(x()+139, y()+541, x()+149, y()+544);
  fl_line(x()+139, y()+541, x()+149, y()+539);
  fl_line(x()+521, y()+541, x()+511, y()+544);
  fl_line(x()+521, y()+541, x()+511, y()+539);
  //
  fl_begin_line();
      R=70;
      fl_arc(x()+521, y()+470, R, 60, 0);
  fl_end_line();
  fl_line(x()+557, y()+409, x()+563, y()+417);
  fl_line(x()+557, y()+409, x()+567, y()+412);
  fl_line(x()+592, y()+470, x()+588, y()+460);
  fl_line(x()+592, y()+470, x()+594, y()+460);
  //
  fl_line(x()+530, y()+475, x()+584, y()+506);
  fl_line(x()+584, y()+506, x()+587, y()+496);
  fl_line(x()+584, y()+506, x()+592, y()+499);
  fl_line(x()+584, y()+506, x()+666, y()+365);
  fl_line(x()+666, y()+365, x()+663, y()+375);
  fl_line(x()+666, y()+365, x()+659, y()+372);
  fl_line(x()+666, y()+365, x()+612, y()+334);
  //
  fl_line(x()+567, y()+460, x()+574, y()+452);
  fl_line(x()+567, y()+460, x()+570, y()+450);
  fl_line(x()+567, y()+460, x()+633, y()+346);
  fl_line(x()+633, y()+346, x()+630, y()+356);
  fl_line(x()+633, y()+346, x()+626, y()+353);
  fl_line(x()+567, y()+460, x()+537, y()+442);
  fl_line_style(FL_SOLID,1);
  fl_line(x()+537, y()+442, x()+521, y()+470);
  fl_line(x()+521, y()+470, x()+490, y()+470);

  fl_line(x()+217, y()+470, x()+139, y()+470);
  fl_line(x()+139, y()+470, x()+164, y()+400);
  fl_line(x()+521, y()+470, x()+592, y()+470);
}
//=======================================================================
void Box::draw_text()
{
 fl_font(FL_HELVETICA,18);
 fl_draw(90,"L1", x()+42, y()+123);
 fl_draw(90,"LL1", x()+105, y()+127);
 fl_draw("LL2", x()+352, y()+243);
 fl_draw("L2", x()+338, y()+272);
 fl_draw(90,"LL1", x()+621, y()+89);
 fl_draw(90,"L3", x()+660, y()+115);
 fl_draw(70,"L1", x()+110, y()+372);
 fl_draw(70,"LL", x()+157, y()+349);
 fl_draw("LL2", x()+319, y()+508);
 fl_draw("L2", x()+310, y()+535);
 fl_draw(60,"LL", x()+585, y()+408);
 fl_draw(60,"L3", x()+616, y()+431);
 fl_draw(-60,"A2", x()+587, y()+423);
 fl_draw(35,"A1", x()+109, y()+422);
 fl_draw(35,"A", x()+65, y()+149);
 fl_draw("T", x()+147, y()+35);
 fl_draw("R", x()+184, y()+153);
 fl_draw(-35,"BA1", x()+161, y()+182);
 fl_draw(35,"BA2", x()+545, y()+195);
}
int Box::handle(int e)
//=======================================================================
{
    static int offset[2] = { 0, 0 };
    static int tex=0,tey,dx=0,dy=0;
    POINT p2;
 switch(e) {
 case FL_ENTER: // When the cursor enters this box
    damage(1);
 return 1;
 case FL_LEAVE: // When the cursor leave this box
    damage(1);
 return 1;
 case FL_PUSH:
     // When mouse button is pushing
        offset[0] = x() - Fl::event_x();    // save where user clicked for dragging
        offset[1] = y() - Fl::event_y();
        tex=x();
        tey=y();
        POINT p;
        p.x=x();p.y=y();
        points.push_back(p);
        // Notify window to redraw is needed
        damage(1);
 return 1;
 case FL_RELEASE: // When release the mouse button
        points.clear();
        damage(1);
        return 1;
 case FL_DRAG:
       // When drag the mouse button
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

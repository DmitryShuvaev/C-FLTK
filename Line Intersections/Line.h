#ifndef LINE_H
#define LINE_H
#include "Box.h"

class Line
{
    public:
        Line(Fl_Double_Window *G_win);
        virtual ~Line();
    void draw();

    Fl_Double_Window *wn;
    Box *point1;
    Box *point2;
};

#endif // LINE_H

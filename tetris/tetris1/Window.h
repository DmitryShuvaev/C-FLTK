#ifndef WINDOW_H
#define WINDOW_H

#include "Graph.h"
//using namespace std;
class WWindow: public Fl_Double_Window
{
    public:

        WWindow(int x,int y,int width, int height, char* title=0);
        void draw();
        virtual ~WWindow();
    Board b;
};

#endif // WINDOW_H

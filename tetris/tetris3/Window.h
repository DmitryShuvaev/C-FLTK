#ifndef WINDOW_H
#define WINDOW_H
//#include "Board_calc.h"
//#include "Graph.h"
#include "Pieces.h"
//using namespace std;
class WWindow: public Fl_Double_Window
{
    public:

        WWindow(int x,int y,int width, int height, char* title=0);
        void draw();
        void draw_piece();
        int handle(int event);
        virtual ~WWindow();
    Board b;
    Rectangle1*r[4];
    I_piece*ip=NULL;
    Board_calc*bc=NULL;
    int curpiece=0;
};

#endif // WINDOW_H

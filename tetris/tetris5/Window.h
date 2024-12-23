#ifndef WINDOW_H
#define WINDOW_H
//#include "Board_calc.h"
//#include "Graph.h"
#include "I_piece.h"
//using namespace std;
class WWindow: public Fl_Double_Window
{
    public:

        WWindow(int x,int y,int width, int height, char* title=0);
        void draw();
        void draw_piece();
        void draw_line();
        int handle(int event);
        void start_new_piece();
        void start_new_game();
        virtual ~WWindow();
    Board b;
    Rectangle1*r[4];
    I_piece*ip=NULL;
    Board_calc*bc=NULL;
    int curpiece=0;
    bool curent_game=true;
    float timerv=1;
};

#endif // WINDOW_H

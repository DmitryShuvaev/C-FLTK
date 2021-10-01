#ifndef WINDOW_H
#define WINDOW_H
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Button.H> // For the button class
#include <FL/Fl_Shared_Image.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.h>

#include <iostream>
#include <string>
#include <list>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Group.H>
#include <FL/fl_ask.H>
//#include "Dependicies.h"
#include "Triangle.h"
#include "Plus.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
using namespace std;

class Mwindow: public Fl_Window
{
    public:

        Mwindow(int width, int height, char* title=0);
        Mwindow(int x,int y,int width, int height, char* title=0);
        void draw();

        virtual ~Mwindow();
Triangle *tr;
Plus *pl;
};

#endif // WINDOW_H

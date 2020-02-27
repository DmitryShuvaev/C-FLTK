
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include <iostream>
#include "Queens.h"
using namespace Graph_lib;
using namespace std;
//------------------------------------------------------------------------------
#define BOXSIZE 52
#define BORDER 4
#define BOARDSIZE (8*BOXSIZE+BORDER)

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title );
void add_queens();

private:
 static void Timer_CB(void *data);
Graph_lib::Rectangle *boxes[8][8];
Graph_lib::Rectangle *boxesborders[8];
Graph_lib::Rectangle *boxesbordersv[8];

Image *queen_light[8];
Queens q;
};

//------------------------------------------------------------------------------

#endif // SIMPLE_WINDOW_GUARD

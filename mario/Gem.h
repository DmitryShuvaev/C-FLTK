#ifndef GEM_H
#define GEM_H
#include "Graph.h"
#include <FL/Fl_PNG_Image.H>
//#include "Level_Maker.h" actual it doesn't work
using namespace Graph_lib;

class Gem
{
    public:
        Gem();
        Gem( int xx,int yy);
        void initial( int xx=0,int yy=0);
        virtual ~Gem();
   Image *tile;
   int x,y;
   //int gID;
    private:
};

#endif // GEM_H

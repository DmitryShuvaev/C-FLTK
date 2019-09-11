#ifndef LEVEL_MAKER_H
#define LEVEL_MAKER_H
#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include <iostream>
#include <time.h>
#include "Point.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
//#include "Gem.h"
//#include "Window.h"
#include "Jumping_Box.h"
using namespace Graph_lib;
using namespace std;
struct Jump_box{
Jump_box():gem_in(false),is_showd(false),id(0){}
bool gem_in;
bool is_showd;//if colision show gem
bool is_consumed;
int id;
//static int cc;
//Gem *gem;

//static void Timer_move_gem(void *pw){
// reference_to<Jump_box>(pw).move_gem_up(pw);
//
//}
//void move_gem_up(void *pw)
//{
// Fl::repeat_timeout(0.5, Timer_move_gem, pw);
// gem->tile->move(0, -1);
//}
~Jump_box(){
    //if(gem_in)it does'nt work when jumpin it gives error
    //delete gem;
    }
};
struct Tiles{

Image *tile;
Jump_box jump_block;
//Jumping_box *b;
int id;

//static void Timer_move_gem(void *pw){
// reference_to<Tiles>(pw).move_gem_up(pw);
//
//}
//void move_gem_up(void *pw)
//{
// Fl::repeat_timeout(0.5, Timer_move_gem, pw);
// jump_block.gem->tile->move(0, -1);
//}
//int id2;
Tiles& operator=(Tiles *a){
 tile=a->tile;
 id=a->id;
 //id2=a->id2;
jump_block=a->jump_block;
 //is_gem=a->is_gem;
}
 //~Tiles(){};
};
//------------------------------------------------------------------------------

class Level_Maker
{
    public:
        Level_Maker();
        void load_top_tiles(int dx,int dy,int randx,int randy);
        void load_jump_boxes();
        void init_jump_boxes(int,int);
        virtual ~Level_Maker();
	Tiles tiles[9][20];
	Tiles top_tiles[40];

	Fl_PNG_Image *tile_top;
	Fl_Image *top_g;
	 int jump_block_id;
	  Fl_Image *temp1;
	  Point tile_p[5][6];
	private:
Point top_tile_start_point[18][6];//this is starting points for mask top tiles
};

#endif // LEVEL_MAKER_H


//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef MANE_WINDOW_GUARD
#define MANE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include <iostream>
#include <time.h>
#include "Point.h"
#include <stdlib.h>
//#include <algorithm>
//#include <vector>
//#include <FL/Fl_PNG_Image.H>
//#include <FL/Fl_Shared_Image.H>
#include "Level_Maker.h"
#include "Snail.h"
//#include "Gem.h"
#include "Gem_obj.h"
using namespace Graph_lib;
using namespace std;
//------------------------------------------------------------------------------

struct Mane_Window : Graph_lib::Window {
    Mane_Window(Point xy, int w, int h, const string& title );
	//destructor
	virtual ~Mane_Window()
	{
		cout<<"deleted\n";

	}//
	void clearWind()
	{

	}

	void newSec();

string toString(int n)
{
	std::string out_string;
	std::stringstream ss;
	ss << n;
	out_string = ss.str();
	return out_string;
}
string getString(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);
    return s;
}

void loadTiles();
int handle(int e);
int handle_key(int event, int key);
void moveLeft();
void moveRight();
void moveLeft_to_midle();
void moveRight_to_midle();
void update(void *pw);
bool colisy(int y,int x);
bool colisy_jump(int y,int x);
bool colisx_right(int y,int x);
bool colisx_left(int y,int x);
void gravi();
void jump();
void animright();
void falling(void *pw);
void move_left_jump();
void move_left_jump_to_midle();
void move_right_jump();
void move_right_jump_to_midle();
void move_tiles_left(int tdx,int tdy);
void set_fall_anim_right();
void set_fall_anim_left();
void move_caracter_to_middle_x(int dxv);
//gem
bool gem_colis();
void set_gem_move();
void move_gems(int dxx);
private:

	Button close;
	//RadButton al;
	bool lett;
     static void cb_next(void *userdata);
     static void cb_rightAnim(void *userdata);
	static void window_cb (Address, Address) ;
    static void Timer_CB(void *userdata);
    static void Falling_CB(void *userdata);

    void next();// action to be done when next_button is pressed
	void closeWindow();
	void Arleters();
	void movBackgroundleft(int dxv);
    void movBackgroundright(int dxv);
	int ii;
	int cameraScroll;
	int CAMERA_SCROLL_SPEED;
	Tiles tiles[9][20];
	Tiles top_tiles[40];
    Image caracter;
    int dx;
    int jvalue;
    //background tile
    Image backgimg;
//
	Image *frames[2];
    Image *framesRight[2];
    Image *framesJump[2];
int timeN;
bool left;
bool right;
bool jumpAnim;
bool star_fall;
bool main_tim;
bool fall;
bool left_col;
bool left_move;
bool right_move;
bool jum_left;
bool lef_j;
bool rigt_j;
bool left_fal;
bool right_mve_fall;
bool left_mve_fall;
bool if_left_timeout;
int dy;
int dy_fal;
int dy_count;
	const int mapWidth = 20;
    const int mapHeight = 9;
    //

    Snail snail,s2;
    //gems id

   Gem_obj gem[10];
   Text score;
   Text game_over;
   Font f;
   int scoreValue;
   int prev_dy;
   int cur_dy;
};

//------------------------------------------------------------------------------

#endif // MANE_WINDOW_GUARD

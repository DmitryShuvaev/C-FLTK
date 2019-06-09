
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef MAZE_WINDOW_GUARD
#define MAZE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "WORD_SEL.H"
#include "MAZE.H"
using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Maze_Window : Window {
    Maze_Window(Point xy, int w, int h, const string& title );
	//destructor
	virtual ~Maze_Window() 
	{
		cout<<"deleted\n";
	for(int i=0;i<verl.size();i++)delete verl[i];
	for(int i=0;i<leters.size();i++){
		delete leters[i];
	}
		leters.clear();verl.clear();
	}//
	void clearWind()
	{
		for(int i=0;i<verl.size();i++)
		{   detach( *verl[i]);
			delete verl[i];
		}
		for(int i=0;i<leters.size();i++){
			detach(* leters[i]);
			delete leters[i];
		}
				for(int i=0;i<arows.size();i++)
		{   detach( *arows[i]);
			delete arows[i];
		}
			leters.clear();verl.clear();arows.clear();
			detach(*sw);
			if(sw)
			delete sw;
			sw=NULL;
			detach(*ew);
			if(ew)
			delete ew;
			ew=NULL;
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
 void printLeft(int,int,int,int);
  void printTop();
  void printRight(int y,int x,int xv,int yv);
  void printBot(int y,int x,int xv,int yv);
  void rectFiled(Closed_polyline &poly_rect,Maze_Window& win);
  //drawin arows
  void right_arow(int xstart,int ystart);
  void left_arow(int xstart,int ystart);
  void low_arow(int xstart,int ystart);
  void up_arow(int xstart,int ystart);
  void draw_arows();
   vector<Lines*> arows;

  //arows
  Closed_polyline poly_rect;
	 vector<Text*> leters;
	
	 vector<Lines*> verl;
	 Point p;
	
Maze *m;
private:
    Button generate;     //button
	Button close;
	RadButton al;
	bool lett;
    static void cb_next(Address, Address); // callback for generate_button
	static void window_cb (Address, Address) ;
	static void arows_cb(void *);
	static void add_lett_cb(Address, Address);
    void next();            // action to be done when next_button is pressed
	void closeWindow();
	void Arleters();
	int ii;
	//start wall
	 Lines *sw;
	 Lines *ew;
};

//------------------------------------------------------------------------------

#endif // MAZE_WINDOW_GUARD

//#include "Graph.h"
//#include "Simple_window.h"
#include "Maze_Window.h"

int main()
{
	//using namespace Graph_lib;
	srand(time(0));
    //CrossGeneratGUI gue;
	Point p(150,150);
    Maze_Window win(p,600,400,"Maze Randomized Prim's algorithm");
	Fl::run();


    
}
//#include "Graph.h"
//#include "Simple_window.h"
#include "Mane_Window.h"
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
int main()
{
	//using namespace Graph_lib;
	srand(time(0));
	Point p(150,150);
    Mane_Window win(p,WINDOW_WIDTH,WINDOW_HEIGHT,"Super Mario");
	Fl::run();

}


//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include <iostream>
#include <FL/Fl_Input.H>
#include "Skip_list.h"
using namespace Graph_lib;
using namespace std;
//------------------------------------------------------------------------------
#define BOXSIZE 52
#define BORDER 4
#define HEIGH (8*BOXSIZE+BORDER)
#define WIDTH 800
#define ZEROY 416-52
struct Arrow{
     enum Arrow_type {
      right,low
     };
  Arrow(Arrow_type art,int x,int y)
  {
   if(art==right)
   {
       //cout<<"right arrow"<<endl;
    r_arrow(x,y);
   }else if(art==low)
   {
    l_arrow(x,y);
   }
  }//end cnst
void r_arrow(int x,int y)
{
 int x1,y1;
 x1=x+BOXSIZE/2;
 y1=y;
//Graph_lib::Line *l1=new Graph_lib::Line(Point(x,y),Point(x1,y1));
    arrow[0]=new Graph_lib::Line(Point(x,y),Point(x1,y1));
    arrow[1]=new Graph_lib::Line(Point(x1,y1),Point(x1-10,y1-4));
    arrow[2]=new Graph_lib::Line(Point(x1,y1),Point(x1-10,y1+4));

    for(int i=0;i<3;i++)
    {
     arrow[i]->set_style(Line_style(Line_style::solid,2));//width 2 pixels
     //attach(*arrow[i]);
    }
}//
void l_arrow(int x,int y)
{
 int x1,y1;
 x1=x;
 y1=y+BOXSIZE/2;
//Graph_lib::Line *l1=new Graph_lib::Line(Point(x,y),Point(x1,y1));
arrow[0]=new Graph_lib::Line(Point(x,y),Point(x1,y1));
arrow[1]=new Graph_lib::Line(Point(x1,y1),Point(x1-4,y1-10));
arrow[2]=new Graph_lib::Line(Point(x1,y1),Point(x1+4,y1-10));

for(int i=0;i<3;i++)
{
     arrow[i]->set_style(Line_style(Line_style::solid,2));

}

}//
void remove_arrow()
{
 for(int i=0;i<3;i++)
{
    if(arrow[i])
     delete arrow[i];

}
}
Graph_lib::Line *arrow[3];
};
//------------------------------------------------------------------------------
struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title );
void draw_list(vector<Point>p,vector<int>txtdata);
void add(Skip_list*l);
string toString(int n)
{
	std::string out_string;
	std::stringstream ss;
	ss << n;
	out_string = ss.str();
	return out_string;
}//
Graph_lib::Button search_button;
static void cb_search(Graph_lib::Address, Graph_lib::Address);
void findv(int v);
In_box in;
void r_arrow(int x,int y);
void l_arrow(int x,int y);
Node* search_data(int data);//the same function like in skip_list
void clear_arows();
void remove_graphic();
virtual ~Simple_window(){
    //if(slist!=NULL)delete slist;

    }
vector<Graph_lib::Rectangle *>cels;
vector<Graph_lib::Text *>textn;
vector<Arrow>arrows;
vector<int>txtd;//for arrows
Graph_lib::Text *txt;
Skip_list *slist;//only works outside this class in main()
private:

    int zerol;
    int zerox;
//
};

//------------------------------------------------------------------------------

#endif // SIMPLE_WINDOW_GUARD

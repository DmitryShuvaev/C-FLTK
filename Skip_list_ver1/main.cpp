#include "Graph.h"
#include "Simple_window.h"
#include <FL/Fl_Shared_Image.H>

using namespace Graph_lib;
using namespace std;
void f(){
    Skip_list l;
    l.clear_skip_list();
    }
int main()
{
    srand(time(0));
    //f();
    Skip_list *l=new Skip_list();
    vector<Point>ps;
    vector<int>bdata;
    ps=l->add_points(&bdata);
    //for(int i=0;i<bdata.size();i++)cout<<bdata[i]<<endl;
    //bdata.clear();
    Point tl(150,150);
    Simple_window win(tl,WIDTH,HEIGH,"Skip list");

    win.add(l);
    win.color(FL_WHITE);
    win.draw_list(ps,bdata);

//vector<int>v1;
//
//v1.push_back(1);
//v1.push_back(2);
//vector<int>v2;
//v2=v1;
//v2.clear();
//cout<<v2.size();
//for(int i=0;i<v2.size();i++)
//cout<<v2[i];
    Fl::run();
    //win.set_active();
}

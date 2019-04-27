#include "Simple_window.h"
#include "WORD_SEL.H"
#include <iostream>
using namespace std;
	using namespace Graph_lib;
class CrossGeneratGUI{
public:
	CrossGeneratGUI():p(150,150),
		win(p,600,400,"My window"),
	 generate(Point(600-70,200), 70, 20, "Generate", cb_reg)
	{
		win.attach(generate);
		 ww.checkLetters();
         ww.printcrosw();
		//p=new Point(150,150);
  //      win=new Simple_window(*p,600,400,"My window");
  //      win->wait_for_button();
           // in.set_one_char();
		//In_box in(Point(30,0), 30, 30, "");
		//win.attach(in);
		//Text t(Point(10,40),"12");
		//win.attach(t);
		//t=new Text[3];
		 int yrow=20;int xrow=10;
		for(int y=0;y<ww.crossw.size();y++){
				
			 for (int x = 0; x < ww.crossw[y].size(); x++)
			 {
			 if(ww.crossw[y][x].c!='#'&&ww.crossw[y][x].c!='8')
			 cels.push_back(new In_box(Point(x*30,y*30), 30, 30, ""));
		     if(ww.crossw[y][x].num>0) nums.push_back(new Text(Point(x*30,yrow),toString(ww.crossw[y][x].num)));
			 //t=new Text(Point(i*30,50),"12");
			 //	t->set_font(FL_COURIER);
				//t->set_font_size(20);
			 if(isalpha(ww.crossw[y][x].c)){
			 leters.push_back(new Text(Point(xrow,yrow),getString(ww.crossw[y][x].c)));
			 }
			 xrow+=30;
			 }
		 xrow=10;
		 yrow=yrow+30;
 //cels.push_back(new In_box(Point(30*x,30), 30, 30, ""));
 //nums.push_back(new Text(Point(20*x,50),"12"));
		}
		//cout<<t[0];
        for(int i=0;i<cels.size();i++){
		 win.attach(*cels[i]);
		  cels[i]->set_one_char();
		}
		for(int i=0;i<leters.size();i++){
		 leters[i]->set_font(FL_COURIER);
		 leters[i]->set_font_size(20);
		 win.attach(*leters[i]);
		}
		 for(int i=0;i<nums.size();i++){
		 nums[i]->set_font(FL_COURIER);
		 nums[i]->set_font_size(12);
		 win.attach(*nums[i]);
		 
		}
		// win.wait_for_button();
		//Fl::wait();
		//Fl::draw();
		Fl::run();
	    }
	 virtual ~CrossGeneratGUI() {
	 //delete win;
	 //delete p;
	 cout<<"deleted\n";
	for(int i=0;i<cels.size();i++)delete cels[i];
	for(int i=0;i<leters.size();i++){
		delete leters[i];
	}
		for(int i=0;i<nums.size();i++){
		delete nums[i];
	}
	system("pause");
	 }
	 //
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
	static void cb_reg(Address, Address pw)
// call Simple_window::next() for the window located at pw
{  
    reference_to<CrossGeneratGUI>(pw).~CrossGeneratGUI();
	
}
	//Point *p;
    //Simple_window *win;
	 vector<In_box*> cels;
	 vector<Text*> leters;
	 vector<Text*> nums;
	 Button generate;
		 //void cb_reg(Address, Address); // callback for next_button
     Word_sel ww;
	//In_box in;
	//Text *t;
	Point p;
    Simple_window win;
	    
     

};
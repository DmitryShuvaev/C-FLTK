
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Maze_Window.h"
//#include <FL/Fl_Round_Button.H>
//------------------------------------------------------------------------------

Maze_Window::Maze_Window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    generate(Point(x_max()-70,0), 70, 20, "generate", cb_next),
	close(Point(x_max()-70,200), 70, 20, "Close", window_cb),
	al(Point(x_max()-70,150), 70, 20, "Arows", add_lett_cb),
	lett(false)
{
	
    attach(generate);
	attach(close);
	attach(al);
    rectFiled(poly_rect,*this);
	//newSec();
	sw=NULL;ew=NULL;
}
	void Maze_Window::newSec()		
{     
	m=new Maze();
	ii=0;
    Lines *vl= NULL;

	int xv=20;
	int yv=20;
	int width=20;
	printTop();
	      for (int y = 0; y < m->cels.size(); y++)
          {
			    for (int x = 0; x < m->cels[y].size(); x++){
					
					printLeft(y,x,xv,yv);
					printRight(y,x,xv,yv);
				if(y==m->cels.size()-1){
					printBot(y,x,xv,yv);
				}
				    xv+=20;

				}
				yv+=20;
				xv=20;

		 }
 //

const int sizeLines=m->lines.size();
if(lett){
 for(int i=0;i<sizeLines;i++){
	if(m->lines[i].p1.x<m->lines[i].p2.x)right_arow(m->lines[i].p1.x,m->lines[i].p1.y);
	else if(m->lines[i].p1.x>m->lines[i].p2.x)left_arow(m->lines[i].p1.x,m->lines[i].p1.y);
	else if(m->lines[i].p1.y<m->lines[i].p2.y)low_arow(m->lines[i].p1.x,m->lines[i].p1.y);
	else if(m->lines[i].p1.y>m->lines[i].p2.y)up_arow(m->lines[i].p1.x,m->lines[i].p1.y);
	Fl::remove_timeout(arows_cb, (void*)this);
		Fl::add_timeout(1.0/1.0, arows_cb,(void*)this);
 }
}else {
		Fl::remove_timeout(arows_cb, (void*)this);
	for(int i=0;i<leters.size();i++)
    attach(*leters[i]);
}

	for(int i=0;i<verl.size();i++)
    attach(*verl[i]);
	//start end walls
	sw= new Lines;
    sw->set_style(Line_style(Line_style::solid,3));
	sw->set_color(Color::white);
	if(m->lines[0].p1.x<m->lines[0].p2.x)
	sw->add(Point(20,20),Point(20,20+width));
	else sw->add(Point(20,20),Point(20+width,20));
	
	//end wall
	ew= new Lines;
    ew->set_style(Line_style(Line_style::solid,3));
	ew->set_color(Color::white);
	if(m->lines[sizeLines-1].p1.x<m->lines[sizeLines-1].p2.x)
	ew->add(Point(20*9,20*8),Point(20*9,20*8+width));
	else ew->add(Point(20*8,20*9),Point(20*8+width,20*9));
	attach(*sw);
	attach(*ew);
		 redraw();
		 if(m){
			 cout<<"ww del\n";
		 delete m;
		 }
}

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

void Maze_Window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{  
    reference_to<Maze_Window>(pw).next();    
}
//------------------------------------------------------------------------------
void Maze_Window::window_cb(Address, Address pw)
// call closew
{  
    reference_to<Maze_Window>(pw).closeWindow();    
}
void Maze_Window::add_lett_cb(Address, Address pw)
// add letters
{  
    reference_to<Maze_Window>(pw).Arleters(); 
	
}
//------------------------------------------------------------------------------

void Maze_Window::next()
{
	clearWind();
	newSec();	
	//
}
//------------------------------------------------------------------------------
void Maze_Window::Arleters()
{
	if(al.getval())lett=true;//cout<<"true";
	else lett=false;//cout<<"false";
}
//------------------------------------------------------------------------------
void Maze_Window::closeWindow()
{
//The default callback hides the window (and if all windows are hidden, your application ends)
    hide();
	//
}
//------------------------------------------------------------------------------
void Maze_Window::arows_cb(void *pw)
{  
     Maze_Window *o = (Maze_Window*)pw;
	 o->draw_arows();
		if(o->ii>=o->arows.size()){
		Fl::remove_timeout(arows_cb, o);
		cout<<"\ntime remov"<<endl;
		
		}
		else
	Fl::repeat_timeout(1.0/1.0, arows_cb, o);
}
//------------------------------------------------------------------------------
void Maze_Window::draw_arows(){
	
	if(ii<arows.size()){
    attach(*arows[ii]);
	ii++;
	cout<<ii;
	}
	if(ii==arows.size())ew->set_color(Color::red);
	 redraw();

}
//------------------------------------------------------------------------------
 void Maze_Window::printLeft(int y,int x,int xv,int yv)
 {
	const int width=20;
	  Lines *vl= NULL;
	            for(int i=0;i<1;i++){
                if(m->cels[y][x]->w[0].wal[i]!='8'&&m->cels[y][x]->w[0].wal[i]!='r'){
						 vl= new Lines;
						 vl->set_style(Line_style(Line_style::solid,3));
	                     vl->add(Point(xv,yv),Point(xv,yv+width));
	                     verl.push_back(vl);
						 leters.push_back(new Text(Point(xv+7,yv+15),getString(m->cels[y][x]->leter)));
				}
               // cout<<w[0].wal[i]<<leter;
                else if(m->cels[y][x]->w[0].wal[i]=='r'){//r means wall removed
                        //cout<<' '<<leter;//
					leters.push_back(new Text(Point(xv+7,yv+15),getString(m->cels[y][x]->leter)));

                    }

                  }
 }//
 void Maze_Window::printTop()
{
		const int width=20;
			int xv=20;
	int yv=20;

	      for (int y = 0; y < m->cels.size(); y++)
          {
			    for (int x = 0; x < m->cels[y].size(); x++){
	             Lines *vl= NULL;
  
                if(m->cels[y][x]->w[1].wal[1]!='8'&&m->cels[y][x]->w[1].wal[1]!='r'){
                //cout<<w[1].wal[i];
						 vl= new Lines;
						 vl->set_style(Line_style(Line_style::solid,3));
						 //vl->set_color(Color::red);
	                     vl->add(Point(xv,yv),Point(xv+width,yv));
	                     verl.push_back(vl);
				}
                else if(m->cels[y][x]->w[1].wal[1]=='r') {
					//cout<<' ';
					//xv+=20;
				}
				xv+=20;
				}
				yv+=20;
				xv=20;
		  }
        
}//
void Maze_Window::printRight(int y,int x,int xv,int yv)
{
	  const int width=20;
	  Lines *vl= NULL;
        for(int i=0;i<1;i++){
                //r means wall removed
                if(m->cels[y][x]->w[2].wal[i]!='8'&&m->cels[y][x]->w[2].wal[i]!='r')
				{
						 vl= new Lines;
						 vl->set_style(Line_style(Line_style::solid,3));
						 //vl->set_color(Color::blue);
	                     vl->add(Point(xv+width,yv),Point(xv+width,yv+width));
	                     verl.push_back(vl);
				}
                //cout<<w[2].wal[i];
        }
}
void Maze_Window::printBot(int y,int x,int xv,int yv)
{
//int xv=20;
const int width=20;
 Lines *vl= NULL;
   if(m->cels[y][x]->w[3].wal[1]!='8'&&m->cels[y][x]->w[3].wal[1]!='r'){
           //cout<<w[3].wal[i];
	   					 vl= new Lines;
						 vl->set_style(Line_style(Line_style::solid,3));
						 //vl->set_color(Color::green);
	                     vl->add(Point(xv,yv+width),Point(xv+width,yv+width));
	                     verl.push_back(vl);
   }
               //else if(m->cels[y][x]->w[3].wal[i]=='r') cout<<' ';
      
}//
void Maze_Window::rectFiled(Closed_polyline &poly_rect,Maze_Window& win){
	poly_rect.set_color(Color::red);
    poly_rect.add(Point(20,20));
    poly_rect.add(Point(180,20));
    poly_rect.add(Point(180,180));
    poly_rect.add(Point(20,180));
    poly_rect.set_fill_color(Color::green);
    win.attach(poly_rect);
}
void Maze_Window::right_arow(int xf,int yf){
    int xstart=(xf*20)+25;
    int ystart=(yf*20)+30;
	 Lines *arow= NULL;
using namespace Graph_lib;
    int xend=xstart+20;
    int yend=ystart;
    int arowXstartt=xstart+5;
    int arowYstartt=ystart-3;
    int arowXstartb=xstart+5;
    int arowYstartb=ystart+3;
	arow=new Lines;
    arow->set_color(Color::black);
    arow->set_style(Line_style(Line_style::solid,2));
    arow->add(Point(xstart,ystart),Point(xend,yend));
    arow->add(Point(arowXstartt,arowYstartt),Point(xend,yend));
    arow->add(Point(arowXstartb,arowYstartb),Point(xend,yend));
	arows.push_back(arow);

}
void Maze_Window::left_arow(int xf,int yf){
    int xstart=(xf*20)+30;
    int ystart=(yf*20)+30;
	 Lines *arow= NULL;
using namespace Graph_lib;
    int xend=xstart-20;
    int yend=ystart;
    int arowXstartt=xstart-5;
    int arowYstartt=ystart-3;
    int arowXstartb=xstart-5;
    int arowYstartb=ystart+3;
	arow=new Lines;
    arow->set_color(Color::black);
    arow->set_style(Line_style(Line_style::solid,2));
    arow->add(Point(xstart,ystart),Point(xend,yend));
    arow->add(Point(arowXstartt,arowYstartt),Point(xend,yend));
    arow->add(Point(arowXstartb,arowYstartb),Point(xend,yend));
	arows.push_back(arow);
}
void Maze_Window::low_arow(int xf,int yf){
    int xstart=(xf*20)+30;
    int ystart=(yf*20)+30;
	 Lines *arow= NULL;
using namespace Graph_lib;
    int xend=xstart;
    int yend=ystart+20;
    int arowXstartt=xstart+3;
    int arowYstartt=ystart+5;
    int arowXstartb=xstart-3;
    int arowYstartb=ystart+5;
	arow=new Lines;
    arow->set_color(Color::black);
    arow->set_style(Line_style(Line_style::solid,2));
    arow->add(Point(xstart,ystart),Point(xend,yend));
    arow->add(Point(arowXstartt,arowYstartt),Point(xend,yend));
    arow->add(Point(arowXstartb,arowYstartb),Point(xend,yend));
	arows.push_back(arow);
}
void Maze_Window::up_arow(int xf,int yf){
    int xstart=(xf*20)+30;
    int ystart=(yf*20)+30;
	 Lines *arow= NULL;
using namespace Graph_lib;
    int xend=xstart;
    int yend=ystart-20;
    int arowXstartt=xstart+3;
    int arowYstartt=ystart-5;
    int arowXstartb=xstart-3;
    int arowYstartb=ystart-5;
	arow=new Lines;
    arow->set_color(Color::black);
    arow->set_style(Line_style(Line_style::solid,2));
    arow->add(Point(xstart,ystart),Point(xend,yend));
    arow->add(Point(arowXstartt,arowYstartt),Point(xend,yend));
    arow->add(Point(arowXstartb,arowYstartb),Point(xend,yend));
	arows.push_back(arow);
}
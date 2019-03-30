#include "headers.h"
class TextScore : public Fl_Widget { 
	        //char s[80]; 
			char s2[80];
          void draw() {  
            //fl_font(labelfont(), labelsize());          // set font/size
            //fl_color(labelcolor());  
		    //static int redraws = 0;
			//sprintf(s, "%d:%d", 0,0);
			
            fl_color(FL_WHITE);
            fl_font(FL_COURIER, 20);
            fl_draw(s2,1280/2,50,w(),h(),align()); 
			 //fl_font(FL_COURIER, 80);
    //        fl_draw(s,1280/2,720/2,w(),h(),align());   // draw text over image and background
		  
        
    }
public:
    TextScore(int X,int Y,int W,int H) : Fl_Widget(X,Y,W,H) {   // ctor
		sprintf(s2, "");
    }
	void drawText(char *s){
       sprintf(s2, s);
	}
};
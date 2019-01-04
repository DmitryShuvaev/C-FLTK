#include "T1.h"

void MyTimer::drawYELOW(){
		 fl_color(CIRC_COLOR);
		 fl_pie(x1-25, y1-25, 50, 50, 0.0, 360.0);
		 fl_pie(x1-25, y3-25, 50, 50, 0.0, 360.0);
		 fl_color(FL_YELLOW);
		 fl_pie(x1-25, y2-25, 50, 50, 0.0, 360.0);
		 counterYELLOW++;
}
void MyTimer::drawTEXT(char *secs,int y){
		 // DRAW TIMER TEXT STRING
        fl_color(TICK_COLOR);
        fl_font(FL_HELVETICA,16);
        fl_draw(secs, x1-8, y+4);
}
void MyTimer::draw() {
        // COMPUTE NEW COORDS OF LINE
        static long start = time(NULL);
        long tick = time(NULL) - start;
		
        char secs[80];  

        // TELL BASE WIDGET TO DRAW ITS BACKGROUND
        Fl_Box::draw();
		//red
		if(tick>0 && tick<=2){
		//counterYELLOW=0;
         fl_color(FL_RED);
		 fl_pie(x1-25, y1-25, 50, 50, 0.0, 360.0);
		 fl_color(CIRC_COLOR);
		 fl_pie(x1-25, y2-25, 50, 50, 0.0, 360.0);
		 fl_pie(x1-25, y3-25, 50, 50, 0.0, 360.0);
		   counterRED++;
		   sprintf(secs, "%02ld", counterRED);
          drawTEXT(secs,y1);

		}
		//yellow
		else if(tick>2 && tick<=4){
		drawYELOW();

		 sprintf(secs, "%02ld", counterYELLOW);
		 drawTEXT(secs,y2);
		}
		//green
		else if(tick>4 && tick<=6){
		 fl_color(CIRC_COLOR);
		 fl_pie(x1-25, y1-25, 50, 50, 0.0, 360.0);
		 fl_pie(x1-25, y2-25, 50, 50, 0.0, 360.0);
		 fl_color(FL_GREEN);
		 fl_pie(x1-25, y3-25, 50, 50, 0.0, 360.0);
		 counterGREEN++;
		 sprintf(secs, "%02ld", counterGREEN);
        drawTEXT(secs,y3);
		counterYELLOW=0;
		}
		//yellow again
		else if(tick>6 && tick<=8){
         drawYELOW();
		 sprintf(secs, "%02ld", counterYELLOW);
		 // DRAW TIMER TEXT STRING
        drawTEXT(secs,y2);
		}
		else{

        fl_color(CIRC_COLOR);
		fl_pie(x1-25, y1-25, 50, 50, 0.0, 360.0);
		fl_pie(x1-25, y2-25, 50, 50, 0.0, 360.0);
		fl_pie(x1-25, y3-25, 50, 50, 0.0, 360.0);
		}
		if(tick==8){
          start = time(NULL);
		  counterRED=0;
		  counterYELLOW=0;
		  counterGREEN=0;
		}
     
		       fl_draw_box(FL_BORDER_FRAME,(x1-25)-5,20,60,
      160,FL_BLUE);
		

    }

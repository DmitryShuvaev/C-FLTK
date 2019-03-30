//#include "Padle.h"
#include "Ball.h"
#include "Text.h"
#ifndef __EVENTWINDOW_H
#define __EVENTWINDOW_H


enum State { start, play }; 
class EventWindow: public Fl_Double_Window
{
        private:
    //            int handle_mouse(int event, int button, int x, int y);
				int handle_key(int event,int key);
				TextScore *score;
				double player1Y,player2Y;
				double PADDLE_SPEED,ballDX,ballDY;
				
				Padle *p1,*p2;
				Ball*ball;
				State gameState;
				bool w_pres,s_pres,up_pres,down_pres;
        public:

                EventWindow(int width, int height);
                int handle(int e);

	void Timer_CB(EventWindow *o) {

		
		if(check_Padle_pos((player1Y+PADDLE_SPEED))){
          player1Y+=PADDLE_SPEED;
		}
		p1->position(p1->x(),player1Y);
        o->redraw();
		
    }
	
	void Timer_CB_DOWN(EventWindow *o) {
		if(check_Padle_pos((player2Y+PADDLE_SPEED))){
		player2Y+=PADDLE_SPEED;
		p2->position(p2->x(),player2Y);
			}
        o->redraw();
		
    }
	static void Timer_CB_S(void *userdata) {
        EventWindow *o = (EventWindow*)userdata;
		o->Timer_CB(o);

        Fl::repeat_timeout(0.01, Timer_CB_S, userdata);
    }
	void Timer_CB_UP(EventWindow *o) {
		if(check_Padle_pos((player1Y-PADDLE_SPEED))){
		 player1Y-=PADDLE_SPEED;
		p1->position(p1->x(),player1Y);
		}
        //o->redraw();
     
	  redraw();
	 
	}
		void Timer_CB_UP_R(EventWindow *o) {
		if(check_Padle_pos((player2Y-PADDLE_SPEED))){
		 player2Y-=PADDLE_SPEED;
		 p2->position(p2->x(),player2Y);
		}
	     redraw();
	 
	}
		static void Timer_CB_UP_S(void *userdata) {
        EventWindow *o = (EventWindow*)userdata;
		o->Timer_CB_UP(o);
		 Fl::repeat_timeout(0.01, Timer_CB_UP_S, userdata);
		}
		/**********************************/
		static void Timer_CB_UP_R(void *userdata) {
        EventWindow *o = (EventWindow*)userdata;
		o->Timer_CB_UP_R(o);
		 Fl::repeat_timeout(0.01, Timer_CB_UP_R, userdata);
		}
		static void Timer_CB_DOWN_S(void *userdata) {
        EventWindow *o = (EventWindow*)userdata;
		o->Timer_CB_DOWN(o);
		 Fl::repeat_timeout(0.01, Timer_CB_DOWN_S, userdata);
		}
		void Timer_BALL(EventWindow *o) {
	  //  ball->ballX = ball->ballX + ballDX*2;
   //     ball->ballY = ball->ballY + ballDY*0.5;
   //      ball->position(ball->ballX,ball->ballY);
		 //redraw();
			update_ball_colis(p1);
			update_ball_colis(p2);
						//detect upper and lower screen boundary collision and reverse if collided
			
			if(ball->ballY<=0){
				
			
				ballDY=-ballDY;
				if(ballDY>-1 && ballDY<=0)ballDY=-5;
				label("ball0");
				//if(ball->ballY==0)ballDY=-ballDY;
				ball->updatePos(ball->x(),0);
			}
				
			
			if(ball->y()>=WINDOW_HEIGHT-20){
				ball->updatePos(ball->x(),WINDOW_HEIGHT-ball->h());
				ballDY=-ballDY;
			}
			ball->updatePos(ball->ballX + ballDX*2,ball->ballY + ballDY*1);
			p2->position(p2->x(),ball->y());
			redraw();
		}
		static void Timer_BALL_S(void *userdata) {
          EventWindow *o = (EventWindow*)userdata;
		  o->Timer_BALL(o);
		 Fl::repeat_timeout(0.01, Timer_BALL_S, userdata);
		}
	void draw_text(char *st){

     score->drawText(st);
	}
	void add_text(){
		if(gameState == start){
		draw_text("Hello Start State!");
		}
		else draw_text("Hello Play State!");
	}
	int getRandom(int from,int to);
	void ballRandPos();
	bool check_Padle_pos(double player1Y);
	//bool check_rightPadle_pos(double player2Y);
	void update_ball_colis(Padle *paddle);
};

 

#endif
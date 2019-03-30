#include "mainwindow.h"

EventWindow::EventWindow(int width,int height):Fl_Double_Window(width,height,"")
{
	label("Demo Window for CS 559");
	srand(time(0));
	gameState=start;
	this->color(FL_BLACK);
	player1Y=0;PADDLE_SPEED = 10;player2Y=0;
	score = new TextScore(10,player1Y,50,34);  // create custom button
    w_pres=false; up_pres=false;
	s_pres=false; down_pres=false;
	p1=new Padle(25,0,5*5,20*5);
	p2=new Padle(WINDOW_WIDTH-50,0,5*5,20*5);
	ball=new Ball(w()/2,WINDOW_HEIGHT/2-50,4*5,4*5);
    ballRandPos();
	//ballDY==1?ballDY:ballDY=-1;
}//end CONSTRUCTOR

int EventWindow::getRandom(int from, int to) {
	int dif = (to+1) - from;
	return from + rand() % dif;

}
void EventWindow::ballRandPos(){
	ballDX=getRandom(0,1);//random nums from 0 to 1
	ballDX==1?ballDX:ballDX=-1;
	ballDY=getRandom(-1,1);

}
	bool EventWindow::check_Padle_pos(double pl1){
     if(pl1>=0 && pl1<=WINDOW_HEIGHT-p1->h()){
		 return true;
	 }
	 return false;
	}
	void EventWindow::update_ball_colis(Padle *paddle){
			if(ball->collides(paddle)){
	
				ballDX=-ballDX;

			  if(w_pres==true){
              	if(ballDY<0)ballDY=-(getRandom(1,2)+PADDLE_SPEED/4);
			    else ballDY=getRandom(1,2)-PADDLE_SPEED/4;
             
				}
			  else if(s_pres==true){
			    if(ballDY<0)ballDY=-(getRandom(1,2)-PADDLE_SPEED/4);
			    else ballDY=getRandom(1,2)+PADDLE_SPEED/4;
					
			  }else{
			   if(ballDY<0)ballDY=-getRandom(1,2);
			   else ballDY=getRandom(1,2);
			  }
			}

	}

int EventWindow::handle(int event)
{
	switch(event){
	case FL_PUSH:
	//case FL_RELEASE:
	case FL_DRAG:
	case FL_MOVE:
		return 1;//handle_mouse(event,Fl::event_button(),Fl::event_x(),Fl::event_y());
	case FL_FOCUS:
		label("Gained focus");
		damage(1);
		return 1;
	case FL_UNFOCUS:
		label("Lost focus");
		damage(1);
		return 1;
	case FL_KEYBOARD:  return handle_key(event,Fl::event_key());

	default:
		if(w_pres==true){
         Fl::remove_timeout(Timer_CB_UP_S, (void*)this);
		 w_pres=false;
		}
		if(s_pres==true){
         Fl::remove_timeout(Timer_CB_S, (void*)this);
		 s_pres=false;
		}
		if(up_pres==true){
         Fl::remove_timeout(Timer_CB_UP_R, (void*)this);
          up_pres=false;
		}
		if(down_pres==true){
		 Fl::remove_timeout(Timer_CB_DOWN_S, (void*)this);
          down_pres=false;
		}

		return Fl_Window::handle(event);
	}
}
int EventWindow::handle_key(int event, int key) {

	
					
                switch ( key ) {
				case FL_Escape:label ("letter esc was depressed");
					exit(0);	
					return 1;
				case FL_Enter :
			   if (gameState == start) {
				   draw_text("Hello Start State!");
				   	Fl::remove_timeout(Timer_BALL_S, (void*)this);
					//set default ball position
					ball->updatePos(WINDOW_WIDTH/2,WINDOW_HEIGHT/2-50);
					ballRandPos();
				   redraw();
				gameState = play;
				/*label ("play was depressed"+gameState);*/
				}
               else{
				   draw_text("Hello Play State!");
				   	Fl::add_timeout(0.01, Timer_BALL_S, (void*)this);
				   //redraw();
				gameState = start;
				//label ("start was depressed"+gameState);

			   }
					return 1;
	
                case 'w':  label ("letter w was depressed");
					
					if(w_pres==false){
						w_pres=true;
					Fl::remove_timeout(Timer_CB_S, (void*)this);
					Fl::add_timeout(0.01, Timer_CB_UP_S, (void*)this);
					}

                        damage(1);
                        return 1;
				case 's':
					if(s_pres==false){
						s_pres=true;
					Fl::remove_timeout(Timer_CB_UP_S, (void*)this);
					Fl::add_timeout(0, Timer_CB_S, (void*)this);
					//player1Y+=PADDLE_SPEED*10;
					}
				    //pic1->position(pic1->x(),player1Y);
					//this->redraw();
                        damage(1);
                        return 1;
				case FL_Up:
					if(up_pres==false){
						up_pres=true;
                    Fl::remove_timeout(Timer_CB_DOWN_S,(void*)this);
					Fl::add_timeout(0.01, Timer_CB_UP_R, (void*)this);
					}

                return 1;
				case FL_Down:
					if(	down_pres==false){
						down_pres=true;
					 Fl::remove_timeout(Timer_CB_UP_R,(void*)this);
					Fl::add_timeout(0.01,Timer_CB_DOWN_S,(void*)this);
									}
					return 1;
                default:  label ("Nothing to do!");
                                damage(1);
                                printf("nothing to do\n");
                                return 1;
                }
}
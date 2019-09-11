
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Mane_Window.h"
//#include <FL/Fl_Round_Button.H>
//------------------------------------------------------------------------------

Mane_Window::Mane_Window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
	close(Point(x_max()-70,200), 70, 20, "Close", window_cb),
	CAMERA_SCROLL_SPEED(10),
	backgimg(Point(0,0),"Resources/backgrounds.png"),
	caracter(Point(0,0),"Resources/character.png"),
	dx(0),
	lett(false),
	score(Point(10,50),"0"),
	game_over(Point(w/7,h/2),"GAME OVER"),
	f(1),
	scoreValue(0)
{
    	left=false;
    	right=false;
    	jumpAnim=false;
    	star_fall=false;
    	main_tim=true;
    	fall=false;
    	left_col=false;
    	right_move=false;
    	left_move=false;
    	jum_left=false;
    	lef_j=false;
    	rigt_j=false;
    	left_fal=false;
    	right_mve_fall=false;
    	left_mve_fall=false;
    	if_left_timeout=false;
    	prev_dy=0;cur_dy=0;
	this->color(FL_WHITE);
	jvalue=0;
	dy=0;dy_count=0;dy_fal=5;
	//background
	Fl_PNG_Image *bimg = new Fl_PNG_Image("Resources/backgrounds.png");
    Fl_Image *tempb;
    tempb=bimg->copy(bimg->w()*6,bimg->h()*6);
	backgimg=tempb;
	backgimg.set_mask(Point(0,0),260*6,128*6);

	//
	Fl_PNG_Image *img = new Fl_PNG_Image("Resources/character.png");//x_max()/2,y_max()/2
    frames[0]=new Image(Point(0,0),"Resources/character.png");
    frames[1]=new Image(Point(0,0),"Resources/character.png");
    //
    Fl_PNG_Image *img2 = new Fl_PNG_Image("Resources/character2.png");
    framesRight[0]=new Image(Point(0,0),"Resources/character2.png");
    framesRight[1]=new Image(Point(0,0),"Resources/character2.png");
    //jump
    framesJump[0]=new Image(Point(0,0),"Resources/character.png");
    framesJump[1]=new Image(Point(0,0),"Resources/character2.png");
	attach(close);
    Fl_Image *temp;
    temp=img->copy(img->w()*5,img->h()*5);//highte 20px
	 caracter=temp;
	 caracter.set_mask(Point(0,0),16*5,20*5);//40-width of x ,0-start on y pos 51 width x, 65 height y
	 //caracter.move(0,20);
    *frames[0]= temp;
	 frames[0]->set_mask(Point(144*5,0),16*5,20*5);
	 //jumping frames
    *framesJump[0]= temp;
    framesJump[0]->set_mask(Point(32*5,0),16*5,20*5);
	 //frames[0]->move(0,20);
	 *frames[1]= temp;
	 frames[1]->set_mask(Point(160*5,0),16*5,20*5);
	 //
     temp=img2->copy(img2->w()*5,img2->h()*5);
    *framesRight[0]= temp;
	 framesRight[0]->set_mask(Point(0,0),16*5,20*5);
    *framesRight[1]= temp;
	 framesRight[1]->set_mask(Point(16*5,0),16*5,20*5);

    *framesJump[1]= temp;
    framesJump[1]->set_mask(Point(128*5,0),16*5,20*5);


    delete img;
    delete img2;
    delete bimg;
    attach(backgimg);

    //tile
	loadTiles();
//
//Color colr(7);
score.set_font_size(50);
score.set_font(f);
score.set_color(Color(7));
score.set_label(toString(scoreValue));
attach(score);
game_over.set_font_size(150);
game_over.set_color(Color(7));

//detach(*s2.snail[1]);
//attach(*s2.snail[1]);
    Fl::add_timeout(1.0/30.0, Timer_CB, (void*)this);
}
	void Mane_Window::newSec()
{

}

//------------------------------------------------------------------------------
void  Mane_Window::loadTiles()
{

Level_Maker lvm;
//int xgemv=0;
for(int y=0;y<mapHeight;y++)
{
    for(int x=0;x<mapWidth;x++){
      tiles[y][x]=lvm.tiles[y][x];

        if(tiles[y][x].jump_block.gem_in)//cout<<"gemy="<<y<<"gemx="<<x<<endl;
        {
         gem[tiles[y][x].jump_block.id].addGem(this,&gem[tiles[y][x].jump_block.id],tiles,&dx,&caracter,
         tiles[y][x].jump_block.id);
//attach(*gem[tiles[y][x].jump_block.id].gem);
         //cout<<tiles[y][x].jump_block.id<<endl;
           cout<<y<<endl;
           cout<<x<<endl;
        }
//         attach(*tiles[y][x].jump_block.gem->tile);
      if(tiles[y][x].id==1) attach(*tiles[y][x].tile);

    }
}
	//tops

for(int i=0;i<40;i++){
 top_tiles[i]=lvm.top_tiles[i];
 if(top_tiles[i].id==1) attach(*top_tiles[i].tile);
}
//attach(*snail.snails[2]);
attach(*framesJump[0]);
s2.addSnail(this,&s2,tiles,&dx,&caracter,&main_tim);

//s2.attach_snail();
	redraw();

}
//------------------------------------------------------------------------------
void Mane_Window::moveLeft()
{
 int cnt=0;
	for(int y=0;y<mapHeight;y++)
	{
		for(int x=0;x<mapWidth;x++){
		if(tiles[y][x].id==1){
          cnt=0;
          while(cnt++<CAMERA_SCROLL_SPEED){
          if(colisx_left((caracter.point(0).y)/80,(caracter.point(0).x+10+dx)/80)){
                left=false;

            }
            tiles[y][x].tile->move(-1,0);

          }

		}

		}
	}
	cnt=0;
	for(int i=0;i<40;i++){
        if(top_tiles[i].id==1){
             cnt=0;
        while(cnt++<CAMERA_SCROLL_SPEED){
             top_tiles[i].tile->move(-1,0);
            }
          }
	}
	dx+=CAMERA_SCROLL_SPEED;
	Fl::lock();
   	redraw();
    Fl::unlock();

}
void Mane_Window::moveRight()
{
 int cnt=0;


	for(int y=0;y<mapHeight;y++)
	{
		for(int x=0;x<mapWidth;x++){
		if(tiles[y][x].id==1){
          cnt=0;

          while(cnt++<CAMERA_SCROLL_SPEED){
          if(colisx_right((caracter.point(0).y)/80,(caracter.point(0).x-20+dx)/80)){
                right=false;
//if(tiles[6][0].tile->point(0).x>=0)right=false;
            }
            //if(right)
 tiles[y][x].tile->move(1,0);
          }
		}

		}
	}

	//if(!right)dx+=CAMERA_SCROLL_SPEED;
	//if(!right)
	//caracter.move(CAMERA_SCROLL_SPEED,0);

		cnt=0;
	for(int i=0;i<40;i++){
        if(top_tiles[i].id==1){
            cnt=0;
        while(cnt++<CAMERA_SCROLL_SPEED){

             top_tiles[i].tile->move(1,0);
            }
          }
	}
	//if(right)
	dx+=-CAMERA_SCROLL_SPEED;



	Fl::lock();
   	redraw();
   Fl::unlock();
}
void Mane_Window::Timer_CB(void *pw)
{
reference_to<Mane_Window>(pw).update(pw);

}
//------------------------------------------------------------------------------
void Mane_Window::update(void *pw)
{
//cout<<"x="<<(caracter.point(0).x+dx)/80<<endl;
    gravi();
s2.SnailMovingState();
if(s2.colis_left_cara_snail()
   ||s2.colis_right_cara_snail())attach(game_over);
	if(jumpAnim){

     	 jump();
	}else
	{

	}

	   //if(left_move)left=true;
	   if(left&&!right){

        if((caracter.point(0).x+dx)>=x_max()/2
           &&(caracter.point(0).x+dx)/80<=12
&&tiles[6][19].tile->point(0).x+80>1280
           )

        {
         moveLeft();

         s2.move_snail(-10);
         movBackgroundleft(3);
         move_gems(-10);
        }
        else if(((caracter.point(0).x+dx)<x_max()/2)
                //||(caracter.point(0).x+dx)/80>12)
                ||(tiles[6][19].tile->point(0).x<=1280))
        {
         moveLeft_to_midle();
        }
	   }
	   else if(right&&!left){
       if((caracter.point(0).x+dx)>=x_max()/2
          &&(caracter.point(0).x+dx)/80<=12
          &&(tiles[6][0].tile->point(0).x<0)
            )
       {
        moveRight();
        s2.move_snail(10);
        movBackgroundright(3);
        move_gems(10);
       }
       else if((caracter.point(0).x+dx)<x_max()/2
               ||((caracter.point(0).x+dx)/80>12&&(caracter.point(0).x+dx)>=x_max()/2)
               ||(tiles[6][0].tile->point(0).x>=0)
               )
       {
        moveRight_to_midle();
       }
	   }

   	redraw();
    //Fl::unlock();
if(caracter.point(0).y>720||main_tim==false){
        //cout<<"delte\n";
main_tim=false;
        detach(caracter);
        Fl::remove_timeout(Timer_CB, (void*)this);
        Fl::remove_timeout(Falling_CB, (void*)this);
        Fl::remove_timeout(cb_rightAnim, (void*)this);
        Fl::remove_timeout(cb_next, (void*)this);

}else  Fl::repeat_timeout(1.0/30., Timer_CB, pw);//30 fps
//cout<<"update call"<<endl;
}
//------------------------------------------------------------------------------
int Mane_Window::handle(int event)
{
 int ret = Window::handle(event);
 //cout<<Fl::event_key()<<endl;

   if(event==FL_KEYUP) {
if_left_timeout=false;
	   label ("relessed");
	   if(left_move&& Fl::event_key()==65361){
        left_move=false;
        jum_left=false;
        lef_j=false;
        right=false;
        left=false;
        left_mve_fall=false;
        Fl::remove_timeout(cb_next, (void*)this);
        Fl::remove_timeout(cb_rightAnim, (void*)this);
        for(int i=0;i<2;i++) detach(*frames[i]);
        for(int i=0;i<2;i++) detach(*framesJump[i]);
        attach(caracter);
	   }

	   if(left&& Fl::event_key()==65361){

	   left=false;
       lef_j=false;//it removes left move after jump colis

		}
      if(right_move&& Fl::event_key()==65363){
       Fl::remove_timeout(cb_next, (void*)this);
	   Fl::remove_timeout(cb_rightAnim, (void*)this);
	   right_move=false;
	   rigt_j=false;
	   left=false;
	   lef_j=false;
	   right_mve_fall=false;
	   for(int i=0;i<2;i++) detach(*framesRight[i]);
	   for(int i=0;i<2;i++) detach(*framesJump[i]);
	   attach(caracter);
		}
      if(right&& Fl::event_key()==65363){
      rigt_j=false;
      left=false;
	   right=false;
		}
		if(jumpAnim&& Fl::event_key()==65362){


		}else{

		}
//if_left_timeout=false;
		}
	if(event==FL_KEYBOARD)  return handle_key(event,Fl::event_key());
	else
		return ret;
}

int Mane_Window::handle_key(int event, int key) {
     switch ( key )
	 {
				case FL_Escape:label ("letter esc was depressed");
					 exit(0);
					 return 1;
				case FL_Enter :
				   //main_tim=false;
				    //s2.move_snail(-1);
//				    tiles[1][3].jump_block.gem->tile->move(0, -1);
					 return 1;
                case FL_ALT:

                    return 1;
                case FL_Right:label ("letter right was depressed");
					 damage(1);

                    if(!jumpAnim&&!right_move){//&&!jumpAnim
					 detach(caracter);
					 right=true;
					 left=false;
					 if(!right_move){right_move=true;}

					 left_move=false;
					 timeN=0;

                     //if(!right_mve_fall){
                      Fl::remove_timeout(cb_next, (void*)this);
                      Fl::add_timeout(0, cb_rightAnim, (void*)this);
                      right_mve_fall=true;
                     //}

					 }else if(!right_move&&jumpAnim){
                     detach(caracter);
                     detach(*framesJump[0]);
					 right=true;
					 left=false;
					 right_mve_fall=true;
					 left_move=false;
					 right_move=true;
					 timeN=0;
					 attach(*framesJump[1]);
					 }
					// }
                     return 1;
                case FL_Left:  label ("letter left was depressed");
                     damage(1);

                    if(!jumpAnim&&!left_move){
                     //cout<<left_move<<endl;
                     if(!left_move)left_move=true;
					 detach(caracter);
					 right=false;
					 left=true;
					 //for jumping
                     right_move=false;
					 timeN=0;

					 //if(!left_mve_fall){
                      Fl::remove_timeout(cb_rightAnim, (void*)this);
                      Fl::add_timeout(0, cb_next, (void*)this);
                      left_mve_fall=true;
					 //}

					 }else if(!left_move&&jumpAnim){
					     left_move=true;
                     //for jumping
                     //if(!jum_left)
                     jum_left=true;
                     detach(caracter);
                     detach(*framesJump[1]);
					 right=false;
					 left=true;
					 right_move=false;
					 left_mve_fall=true;
					 timeN=0;
					 attach(*framesJump[0]);
					 }

                     return 1;

                case FL_Up:
                    damage(1);
                    if(jumpAnim==false){
                        jumpAnim=true;
                        jvalue=60;//40
                    if(right_move){
                        rigt_j=true;
                        lef_j=false;
                       Fl::remove_timeout(cb_rightAnim, (void*)this);
                        Fl::remove_timeout(cb_next, (void*)this);
                       detach(caracter);
                       for(int i=0;i<2;i++) detach(*framesRight[i]);
                       for(int i=0;i<2;i++) detach(*frames[i]);
                       attach(*framesJump[1]);
                    //
                     }
                     else if(left_move){
                            jum_left=true;lef_j=true;
                        Fl::remove_timeout(cb_rightAnim, (void*)this);
                        Fl::remove_timeout(cb_next, (void*)this);
                       detach(caracter);
                       for(int i=0;i<2;i++) detach(*framesRight[i]);
                       for(int i=0;i<2;i++) detach(*frames[i]);
                       attach(*framesJump[0]);
                     }
                    }

                default:
					label ("Nothing to do!");
                    damage(1);
                    //printf("nothing to do\n");
                    return 1;
      }
}
bool Mane_Window::colisy(int y,int x){
 bool flag=false;
 //if(fall==false){
    if(y>=0&&x>=0&&y<mapHeight&&x<mapWidth)
    {
     if(tiles[y][x].id==1&&caracter.point(0).y+100.>=tiles[y][x].tile->point(0).y)
     {
        flag=true;
     }
     if(tiles[y][x+1].id==1&&caracter.point(0).y+100>=tiles[y][x+1].tile->point(0).y&&
      caracter.point(0).x+75>tiles[y][x+1].tile->point(0).x )
     {
//cout<<"tile ycol ="<<y<<endl;
      flag=true;
     }
         if(tiles[y-1][x].id==1&&caracter.point(0).x<=tiles[y-1][x].tile->point(0).x+80
        //&&caracter.point(0).x<tiles[y][x].tile->point(0).x+80
        ){
     }

    }//end if
 return flag;

 }
 bool Mane_Window::colisy_jump(int y,int x){
    bool flag=false;
    if(y>=0&&x>=0&&y<mapHeight&&x<mapWidth)
    {
     if(tiles[y][x].id==1&&caracter.point(0).y<=tiles[y][x].tile->point(0).y+80)
     {
        flag=true;
     }

     if(tiles[y][x+1].id==1&&caracter.point(0).y<=tiles[y][x+1].tile->point(0).y+80
        &&caracter.point(0).x+80>tiles[y][x+1].tile->point(0).x)
     {
        flag=true;
     }

    }//end if
 return flag;
 }
 //------------------------------------------------------------------------------
 bool Mane_Window::colisx_right(int y,int x){
 bool colis=false;
 if(y>=0&&x>=0&&y<mapHeight&&x<mapWidth){
 if(tiles[y][x-1].id==1&&caracter.point(0).x<=tiles[y][x-1].tile->point(0).x+80
   &&caracter.point(0).y<tiles[y][x-1].tile->point(0).y+78){
    colis=true;right=false; //cout<<"r";
    //left_col=true;

    //Fl::remove_timeout(cb_rightAnim, (void*)this);
  }
       if(tiles[y+1][x].id==1&&caracter.point(0).x<=tiles[y+1][x].tile->point(0).x+80
        &&caracter.point(0).y+95>=tiles[y+1][x].tile->point(0).y
        )
        {
         colis=true;right=false; //cout<<"r";
         //left_col=true;
//                       for(int i=0;i<2;i++) detach(*framesRight[i]);
//                       for(int i=0;i<2;i++) detach(*frames[i]);
//                       attach(caracter);
        }//
//               if(tiles[y+1][x-1].id==1&&caracter.point(0).x<=tiles[y+1][x-1].tile->point(0).x+80
//        //&&caracter.point(0).y+95>=tiles[y+1][x-1].tile->point(0).y
//        )
//        {
//         colis=true;right=false; //cout<<"r";
//
//        }
       // if(!colisy((caracter.point(0).y+101)/80,(caracter.point(0).x+dx)/80)){
       if(tiles[y][x].id==1&&caracter.point(0).x<=tiles[y][x].tile->point(0).x+80
        &&caracter.point(0).y<tiles[y][x].tile->point(0).y+78
        //&&caracter.point(0).y>=tiles[y][x].tile->point(0).y+40
        //&&caracter.point(0).x>=tiles[y][x].tile->point(0).x+40
        ){
            colis=true;right=false;
            //if(!jumpAnim)
            //if(colisy((caracter.point(0).y+120)/80,(caracter.point(0).x+dx)/80))
           //cout<<"coli"<<endl;
            //else right=true;
        }
       // }
        int xx=(caracter.point(0).x+dx)/80;
        int yy=(caracter.point(0).y+100)/80;
        if(yy<mapHeight){
    if(tiles[yy][xx].id==1&&caracter.point(0).y+100.>tiles[yy][xx].tile->point(0).y+1
       //&&caracter.point(0).x<tiles[yy][xx].tile->point(0).x+80
       )
       {
//
if((caracter.point(0).x+dx)<=x_max()/2
   ||((caracter.point(0).x+dx)/80>12&&(caracter.point(0).x+dx)>=x_max()/2))
{
    move_caracter_to_middle_x(10);
}else
{
        caracter.move(0,-1);
        for(int i=0;i<2;i++){
         frames[i]->move(0,-1);
         framesRight[i]->move(0,-1);
         framesJump[i]->move(0,-1);
                }
}

        }//end if
 }
 }
 return colis;
 }
  //------------------------------------------------------------------------------
bool Mane_Window::colisx_left(int y,int x){
   bool colis=false;
 if(y>=0&&x>=0&&y<mapHeight&&x+1<mapWidth){
    if(tiles[y][x+1].id==1&&caracter.point(0).x+80>=tiles[y][x+1].tile->point(0).x
    &&caracter.point(0).y<tiles[y][x+1].tile->point(0).y+78){
    colis=true;
    left=false;
//cout<<"cols"<<endl;
     }
//     else if(tiles[y-1][x+1].id!=1&&jum_left){
//         left=true;
//     }
    if(tiles[y+1][x+1].id==1&&caracter.point(0).x+80>=tiles[y+1][x+1].tile->point(0).x
        &&caracter.point(0).y+95>=tiles[y+1][x+1].tile->point(0).y
       )
    {
    colis=true;
    left=false;
    //cout<<"colsinnnn"<<'\n';
    }
        int xx=(caracter.point(0).x-10+dx)/80;
        int yy=(caracter.point(0).y+100)/80;
        if(yy<mapHeight){
    if(tiles[yy][xx+1].id==1&&caracter.point(0).y+100.>tiles[yy][xx+1].tile->point(0).y+1
       ){
if((caracter.point(0).x+dx)<x_max()/2
   ||((caracter.point(0).x+dx)/80>12&&(caracter.point(0).x+dx)>=x_max()/2))
{
    move_caracter_to_middle_x(-10);
}else
{
         caracter.move(0,-1);
        for(int i=0;i<2;i++){
         frames[i]->move(0,-1);
         framesRight[i]->move(0,-1);
         framesJump[i]->move(0,-1);
        }
}

        //move_tiles_left(1,1);
        }//end if

    }
 }
   return colis;
}
    //------------------------------------------------------------------------------
void Mane_Window::gravi()
{
 int counter=0;
 dy_fal+=dy;
    while(counter++<dy_fal){
    if(s2.colisTopSnail()){   s2.snail_status();}
     if(colisx_right((caracter.point(0).y)/80,(caracter.point(0).x-20+dx)/80)){//cout<<"in colr_gravi"<<endl;
     }
     if(colisx_left((caracter.point(0).y)/80,(caracter.point(0).x+dx)/80)){
            //cout<<"in col_gravi"<<endl;
          //colisx_left((caracter.point(0).y+20)/80,(caracter.point(0).x+dx)/80);
          //break;
     }
     if(colisy((caracter.point(0).y+100)/80,(caracter.point(0).x+dx)/80)){
            dy=0;dy_count=0;dy_fal=5;prev_dy=cur_dy;
            star_fall=false;
        Fl::remove_timeout(Falling_CB, (void*)this);
 //if(tiles[(caracter.point(0).y+100)/80][(caracter.point(0).x+dx)/80].jump_block.gem_in)cout<<"gem cols"<<endl;
 gem_colis();
//cout<<"colision"<<endl;
if(right_move)
{
 if(!colisx_right((caracter.point(0).y)/80,(caracter.point(0).x-20+dx)/80))
 {
    right=true;
 }
 if(right_mve_fall==false)
 {
    right_mve_fall=true;
    Fl::add_timeout(0, cb_rightAnim, (void*)this);
 }
}
else if(left_move)
{
 if(!colisx_left((caracter.point(0).y)/80,(caracter.point(0).x+dx)/80))
 {
   left=true;
 }
 if(left_mve_fall==false)
 {
    //left_mve_fall=true;
    //cout<<"jump mve fall"<<endl;
    //left=false;
//here need to check after landing y colision
    if(if_left_timeout==false){
     Fl::remove_timeout(cb_next, (void*)this);
     Fl::add_timeout(0, cb_next, (void*)this);
     if_left_timeout=true;
    }//else if_left_timeout=false;

    //Fl::add_timeout(0, cb_next, (void*)this);
 }
}
    break;
     }else if(jumpAnim){
     //cout<<"jump fall"<<endl;

     }
if(star_fall==false&&dy_count==0&&jvalue<=0)
{
    star_fall=true;
    Fl::add_timeout(0, Falling_CB, (void*)this);

if(right_move&&!jumpAnim){
        //cout<<"right move in grav fall"<<endl;
right_mve_fall=false;
set_fall_anim_right();
}else if(left_move&&!jumpAnim){

    if(!if_left_timeout){
      left_mve_fall=false;

    }//else if_left_timeout=false;

set_fall_anim_left();
}
// if(colisx_right((caracter.point(0).y)/80,(caracter.point(0).x-20+dx)/80)&&right_move
//    )right=false;
}

prev_dy=cur_dy;
cur_dy+=1;
        caracter.move(0,1);
        for(int i=0;i<2;i++){
         frames[i]->move(0,1);
         framesRight[i]->move(0,1);
         framesJump[i]->move(0,1);
        }
}//end while
      //here need to check colisy if colide
    //jump =false add timeut left or right

if(prev_dy!=cur_dy){
    //cout<<"prev_dy=cur_dy="<<prev_dy<<endl;
if(left)if_left_timeout=false;
}
 redraw();
}
void Mane_Window::jump()
{
int cnt=0;
int dxc=0;
 if(jvalue>0)
 {
  while(cnt++<jvalue)
  {//loop
   if(dxc++>1){
    dxc=0;
   }
    if(colisy_jump((caracter.point(0).y)/80,(caracter.point(0).x+dx)/80))
    {
      jvalue=-1;
      dy=0;    dy_count=0;star_fall=false;dy_fal=5;
      set_gem_move();
      //cout<<"jump\n";
    }
    caracter.move(0, -1);
    for(int i=0;i<2;i++){
     frames[i]->move(0, -1);
     framesRight[i]->move(0, -1);
     framesJump[i]->move(0, -1);
    }

  }//end while
     jvalue-=6;//-3
      //cout<<"left="<<left<<endl;
//      cout<<"right_j="<<rigt_j<<endl;
//      cout<<"lef_j="<<lef_j<<endl;
//      cout<<"right="<<right<<endl;
      //cout<<"col="<<colisx_right((caracter.point(0).y+20)/80,(caracter.point(0).x-20+dx)/80)<<endl;
    if(lef_j&&!left&&!right&&!right_move&&jum_left&&!colisx_left((caracter.point(0).y+20)/80,(caracter.point(0).x+dx)/80))
    {
    move_left_jump();
    left=true;

    right=false;
    //cout<<"jump_left"<<jum_left<<endl;
    }else if(rigt_j&&!lef_j&&!right&&!colisx_right((caracter.point(0).y+20)/80,(caracter.point(0).x-20+dx)/80)){
     move_right_jump();
     //cout<<"\nright!\n"<<endl;
     right=true;

    }
     redraw();
 }
    if(colisy((caracter.point(0).y+101)/80,(caracter.point(0).x+dx)/80)){
     jumpAnim=false;

     dy=0;    dy_count=0;star_fall=false;dy_fal=5;
     Fl::remove_timeout(Falling_CB, (void*)this);
     if(right_move)
     {
     if(!colisx_right((caracter.point(0).y+20)/80,(caracter.point(0).x-20+dx)/80))
      right=true;//here set move after jump
      Fl::add_timeout(0, cb_rightAnim, (void*)this);
     }
     else if(left_move)
     {
      if(!colisx_left((caracter.point(0).y+20)/80,(caracter.point(0).x+dx)/80))
      left=true;
      //if(left_mve_fall)
      //left_mve_fall=false;

      if(if_left_timeout==false){
        if_left_timeout=true;

       // cout<<"left_mve_fall="<<if_left_timeout<<endl;
        left_mve_fall=false;
        Fl::add_timeout(0, cb_next, (void*)this);
      }else {
 if_left_timeout=false;
      }

      //cout<<"left_move"<<endl;

     }
 }//end if
}
//------------------------------------------------------------------------------
void Mane_Window::move_left_jump(){
int cnt=0;
if((caracter.point(0).x+dx)<x_max()/2
   ||((caracter.point(0).x+dx)/80>12&&(caracter.point(0).x+dx)>=x_max()/2)){
 move_left_jump_to_midle();
}else
{
	for(int y=0;y<mapHeight;y++)
	{
		for(int x=0;x<mapWidth;x++){
		if(tiles[y][x].id==1){
          cnt=0;
          while(cnt++<10){
          if(colisx_left((caracter.point(0).y)/80,(caracter.point(0).x+dx)/80)){
                left=false;

            }
            tiles[y][x].tile->move(-1,0);

          }

		}

		}
	}
	cnt=0;
	for(int i=0;i<40;i++){
        if(top_tiles[i].id==1){
             cnt=0;
        while(cnt++<10){
             top_tiles[i].tile->move(-1,0);
            }
          }
	}
	dx+=10;
	s2.move_snail(-10);
	movBackgroundleft(3);
	move_gems(-10);
}
	Fl::lock();
   	redraw();
    Fl::unlock();
}
//------------------------------------------------------------------------------
void Mane_Window::move_right_jump(){
int cnt=0;
if((caracter.point(0).x+dx)<=x_max()/2
   ||((caracter.point(0).x+dx)/80>12&&(caracter.point(0).x+dx)>=x_max()/2)){
 move_right_jump_to_midle();
}else
{
	for(int y=0;y<mapHeight;y++)
	{
		for(int x=0;x<mapWidth;x++){
		if(tiles[y][x].id==1){
          cnt=0;
          while(cnt++<10){
          if(colisx_right((caracter.point(0).y)/80,(caracter.point(0).x+dx)/80)){
                right=false;

            }
            tiles[y][x].tile->move(1,0);

          }

		}

		}
	}
	cnt=0;
	for(int i=0;i<40;i++){
        if(top_tiles[i].id==1){
             cnt=0;
        while(cnt++<10){
             top_tiles[i].tile->move(1,0);
            }
          }
	}
	dx+=-10;
	s2.move_snail(10);
	movBackgroundright(3);
	move_gems(10);
}
	Fl::lock();
   	redraw();
    Fl::unlock();
}
//------------------------------------------------------------------------------
void Mane_Window::move_tiles_left(int tdx,int tdy){
    int dxv=0;
        caracter.move(10,0);
        for(int i=0;i<2;i++){
         frames[i]->move(10,0);
         framesRight[i]->move(10,0);
         framesJump[i]->move(10,0);
        }
    while(dxv++<10){


for(int y=0;y<mapHeight;y++)
	{
		for(int x=0;x<mapWidth;x++){
		if(tiles[y][x].id==1){

          if(colisx_left((caracter.point(0).y)/80,(caracter.point(0).x+1+dx)/80)){
                left=false;

            }
            tiles[y][x].tile->move(1,0);



		}

		}
	}
	for(int i=0;i<40;i++){
        if(top_tiles[i].id==1){

             top_tiles[i].tile->move(1,0);

          }
	}
    }
	dx+=-10;

}
//------------------------------------------------------------------------------
void Mane_Window::cb_next(void *pw)
// call Simple_window::next() for the window located at pw
{
    reference_to<Mane_Window>(pw).next();
	 Fl::repeat_timeout(0.2, cb_next, pw);
}
void Mane_Window::cb_rightAnim(void *pw)
// call Simple_window::next() for the window located at pw
{
    reference_to<Mane_Window>(pw).animright();
	 Fl::repeat_timeout(0.2, cb_rightAnim, pw);
}
//------------------------------------------------------------------------------
void Mane_Window::window_cb(Address, Address pw)
// call closew
{
    reference_to<Mane_Window>(pw).closeWindow();
}
//------------------------------------------------------------------------------
void Mane_Window::Falling_CB(void *pw)
// call closew
{
    reference_to<Mane_Window>(pw).falling(pw);

}
//------------------------------------------------------------------------------

void Mane_Window::next()
{
    for(int i=0;i<2;i++) detach(*framesRight[i]);
    for(int i=0;i<2;i++) detach(*framesJump[i]);
	if(timeN==2)timeN=0;
	if(timeN==0){
	  detach(*frames[1]);
	  attach(*frames[0]);
	}
	else if(timeN==1){
	  detach(*frames[0]);
	  attach(*frames[1]);
	}
	timeN++;

		//redraw();
}
//------------------------------------------------------------------------------
void Mane_Window::animright()
{
    for(int i=0;i<2;i++) detach(*frames[i]);
        for(int i=0;i<2;i++) detach(*framesJump[i]);
	if(timeN==2)timeN=0;
	if(timeN==0){
	  detach(*framesRight[1]);
	  attach(*framesRight[0]);
	}
	else if(timeN==1){
	  detach(*framesRight[0]);
	  attach(*framesRight[1]);
	}
	timeN++;

		//redraw();
}
//------------------------------------------------------------------------------
void Mane_Window::closeWindow()
{
//The default callback hides the window (and if all windows are hidden, your application ends)
    hide();
	//
}

//------------------------------------------------------------------------------
void Mane_Window::falling(void *pw)
{
            //Mane_Window *o = (Mane_Window*)pw;

    dy+=2;
    dy_count++;
    //cout<<"falling"<<endl;
        //cout<<"dy="<<dy<<endl;
        if(dy_count>=3){
            //dy=0;
           //cout<<"dy="<<dy<<endl;
            Fl::remove_timeout(Falling_CB, (void*)this);
    //dy_count=0;
    }else  Fl::repeat_timeout(0.1, Falling_CB, pw);

}
//------------------------------------------------------------------------------
void Mane_Window::set_fall_anim_right()
{
//Fl::remove_timeout(cb_next, (void*)this);
Fl::remove_timeout(cb_rightAnim, (void*)this);
for(int i=0;i<2;i++) detach(*framesRight[i]);
for(int i=0;i<2;i++) detach(*framesJump[i]);
detach(*framesRight[1]);
attach(*framesJump[1]);
}
//------------------------------------------------------------------------------
void Mane_Window::set_fall_anim_left()
{
 Fl::remove_timeout(cb_next, (void*)this);
 //Fl::remove_timeout(cb_rightAnim, (void*)this);
//for(int i=0;i<2;i++) detach(*framesRight[i]);
for(int i=0;i<2;i++) detach(*framesJump[i]);
for(int i=0;i<2;i++) detach(*frames[i]);
//detach(caracter);
detach(*framesRight[0]);
//detach(*framesRight[1]);
attach(*framesJump[0]);
}
//------------------------------------------------------------------------------
void Mane_Window::moveLeft_to_midle()
{
 int cnt=0;
 if((caracter.point(0).x+dx)/80<19)
 {
  while(cnt++<CAMERA_SCROLL_SPEED)
  {
   move_caracter_to_middle_x(1);
  }
 }

	Fl::lock();
   	redraw();
    Fl::unlock();
}
//------------------------------------------------------------------------------
void Mane_Window::moveRight_to_midle()
{
 int cnt=0;
 if(caracter.point(0).x>0)
 {
  while(cnt++<CAMERA_SCROLL_SPEED)
  {
   move_caracter_to_middle_x(-1);
  }
 }
	Fl::lock();
   	redraw();
   Fl::unlock();
}
//------------------------------------------------------------------------------
void Mane_Window::move_caracter_to_middle_x(int dxv)
{
         caracter.move(dxv,0);
        for(int i=0;i<2;i++){
         frames[i]->move(dxv,0);
         framesRight[i]->move(dxv,0);
         framesJump[i]->move(dxv,0);
        }
}
//------------------------------------------------------------------------------
void Mane_Window::move_left_jump_to_midle(){
int cnt=0;
if(caracter.point(0).x<x_max()/2)
{
    while(cnt++<10){
        if(colisx_left((caracter.point(0).y)/80,(caracter.point(0).x+dx)/80))
        {
            left=false;
        }
         move_caracter_to_middle_x(1);
    }
}

	Fl::lock();
   	redraw();
    Fl::unlock();
}
//------------------------------------------------------------------------------
void Mane_Window::move_right_jump_to_midle(){
int cnt=0;
if(caracter.point(0).x>0){
          while(cnt++<10){
          if(colisx_right((caracter.point(0).y)/80,(caracter.point(0).x+dx)/80)){
                right=false;

            }
            move_caracter_to_middle_x(-1);
          }
}
	Fl::lock();
   	redraw();
    Fl::unlock();
}
//------------------------------------------------------------------------------
void Mane_Window::movBackgroundleft(int dxv)
{
 //if(backgimg.point(0).x>0)//backgimg.point(0).x=0;
 backgimg.move(-dxv,0);
}
//------------------------------------------------------------------------------
void Mane_Window::movBackgroundright(int dxv)
{
 if(backgimg.point(0).x<0)
 backgimg.move(dxv,0);
}
//gem it checks where the is collision with gem and player when player is on top of the jumping box
bool Mane_Window::gem_colis(){
 bool colis=false;
 int xx=(caracter.point(0).x+dx)/80;
 int yy=(caracter.point(0).y+100)/80;

 if(tiles[yy][xx].jump_block.gem_in
    &&tiles[yy][xx].jump_block.is_consumed==false)
 {
    int i=tiles[yy][xx].jump_block.id;//i is index int positions in gems array
     if(yy>gem[i].gem->point(0).y-40)
     //if(yy>tiles[yy][xx].jump_block.gem->tile->point(0).y-40)
        {
         //cout<<"gem cols"<<endl;
         gem[i].detach_gem();
         tiles[yy][xx].jump_block.is_consumed=true;
         scoreValue+=100;
         score.set_label(toString(scoreValue));
        }

 }else if(tiles[yy][xx+1].jump_block.gem_in
          &&tiles[yy][xx+1].jump_block.is_consumed==false)
 {
    int i=tiles[yy][xx+1].jump_block.id;//i is index int positions in gems array
     if(yy>gem[i].gem->point(0).y-40)
     //if(yy>tiles[yy][xx].jump_block.gem->tile->point(0).y-40)
        {
         //cout<<"gem cols+1"<<endl;
         gem[i].detach_gem();
         tiles[yy][xx+1].jump_block.is_consumed=true;
         scoreValue+=100;
         score.set_label(toString(scoreValue));
        }
 }
}
//moves the gem on top of the jumping_box
void Mane_Window::set_gem_move()
{
 int xx=(caracter.point(0).x+dx)/80;
 int yy=(caracter.point(0).y)/80;

 if(tiles[yy][xx].jump_block.gem_in
    &&tiles[yy][xx].jump_block.is_showd==false
    )
    {
     tiles[yy][xx].jump_block.is_showd=true;
     gem[tiles[yy][xx].jump_block.id].ad_t();

    }
 else if(tiles[yy][xx+1].jump_block.gem_in
        &&tiles[yy][xx+1].jump_block.is_showd==false)
 {
    tiles[yy][xx+1].jump_block.is_showd=true;
    gem[tiles[yy][xx+1].jump_block.id].ad_t();

 }

}

void Mane_Window::move_gems(int dxx)
{

for(int i=0;i<10;i++)
{
    gem[i].gem->move(dxx,0);
}

}

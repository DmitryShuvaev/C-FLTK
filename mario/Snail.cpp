#include "Snail.h"
#include <FL/Fl_PNG_Image.H>
Snail::Snail()
:
snailWidth(80),
snailHight(80),
mapWidth(20),
mapHeight(9),
timeN(0)
{
    //ctor
    movingDirection=right;
    islive=true;
    //snail 1
    snails[0]=new Image(Point(0,0),"Resources/creatures.png");
    Fl_PNG_Image *img = new Fl_PNG_Image("Resources/creatures.png");
    Fl_Image *temp;
    temp=img->copy(img->w()*5,img->h()*5);//highte 20px
    *snails[0]=temp;
    snails[0]->set_mask(Point(0,96*5),16*5,16*5);//0 start x, 96*5-start y
    //snail 2
    snails[1]=new Image(Point(0,0),"Resources/creatures.png");
    *snails[1]=temp;
    snails[1]->set_mask(Point(16*5,96*5),16*5,16*5);
    //snail 3 left
    snails[2]=new Image(Point(0,0),"Resources/creatures1.png");
    Fl_PNG_Image *img1 = new Fl_PNG_Image("Resources/creatures1.png");
    temp=img1->copy(img1->w()*5,img1->h()*5);
    *snails[2]=temp;
    snails[2]->set_mask(Point(112*5,96*5),16*5,16*5);
    snails[3]=new Image(Point(0,0),"Resources/creatures1.png");
    *snails[3]=temp;
    snails[3]->set_mask(Point(96*5,96*5),16*5,16*5);
    delete img;
    delete img1;
    cn=0;
    snail=snails[1];
}
//------------------------------------------------------------------------------
void Snail::init(Tiles (&a)[9][20])
{

 for(int y=0;y<mapHeight;y++)
 {
    for(int x=0;x<mapWidth;x++)
    {
      tiles[y][x]=a[y][x];
    }
 }
}
//------------------------------------------------------------------------------
void Snail::add(Tiles (&tiles)[9][20])
{
 for(int y=0;y<mapHeight;y++)
 {
 for(int x=0;x<mapWidth;x++)
 {
  if(y==5&&x==8)
  {
 for(int i=0;i<4;i++)
   snails[i]->move(x*snailWidth,y*snailHight);
  }
 }
 }
 init(tiles);
}
Snail::~Snail()
{
    //dtor
    delete[]snails;
    delete snail;
}
//------------------------------------------------------------------------------
void Snail::move_snail(int dxv)
{
 for(int i=0;i<4;i++)
 {
  snails[i]->move(dxv,0);

 }
   //if(tiles[5][6].id==1)
//cout<<"tiles.x="<<tiles[5][6].tile->point(0).x<<endl;
}
void Snail::snail_status(){
    //main_tim=false;
   islive=false;
   detach_snail();
}
//------------------------------------------------------------------------------
void Snail::SnailMovingState()
{
double dxv=-1;
if(islive){
if(cn<1)cn++;
else {
 cn=0;
if(colisTopSnail())
{
 snail_status();
}else{
    if(!colisy_left((snail->point(0).y+80)/80,(snail->point(0).x+*dx)/80)&&movingDirection==left)
    {
     cout<<"tile ycol1 ="<<endl;
    if(movingDirection==left)movingDirection=right;
     else movingDirection=left;
    }
    else if(!colisy_right((snail->point(0).y+80)/80,(snail->point(0).x+*dx)/80)&&movingDirection==right)
    {
          cout<<"tile ycol2 ="<<endl;
    if(movingDirection==left)movingDirection=right;
     else movingDirection=left;
    }




//if snail is alive
  if(colisx_right((snail->point(0).y)/80,(snail->point(0).x+*dx)/80)
     )
  {
//reset direction if we hit a wall
   movingDirection=left;
  }
  else if(colisx_left((snail->point(0).y)/80,(snail->point(0).x+*dx)/80)
          )
  {
   movingDirection=right;
  }
  if(movingDirection==right){
       animright();
       movetiles(dxv);
      }else {
       animleft();
       movetiles(-dxv);
      }
//}
}
}

//calculate difference between snail and player on X axis abs if dif<200 snail in chase state
int diffX = abs(player->point(0).x - snail->point(0).x);
//cout<<"diffX="<<diffX<<endl;
}
//cout<<"rand="<<to_rand(0,1);
}
void Snail::movetiles(int dxv)
{
 for(int i=0;i<4;i++)
 {
  snails[i]->move(dxv,0);
 }
}
//------------------------------------------------------------------------------
 bool Snail::colisx_right(int y,int x){
 bool colis=false;

 if(y>=0&&x>=0&&y<mapHeight&&x<mapWidth){
 if(tiles[y][x-1].id==1&&snail->point(0).x<=tiles[y][x-1].tile->point(0).x+80)
    colis=true;
     //if(tiles[y][x-1].id!=1)colis=true;
  }
  return colis;
 }
//------------------------------------------------------------------------------
bool Snail::colisx_left(int y,int x){
 bool colis=false;
 if(y>=0&&x>=0&&y<mapHeight&&x+1<mapWidth)
 {
    if(tiles[y][x+1].id==1&&snail->point(0).x+80>=tiles[y][x+1].tile->point(0).x
    ){
      colis=true;
     }
 }
 return colis;
}
//------------------------------------------------------------------------------
void Snail::animright()
{
 if(timeN==4)timeN=0;
 if(timeN==0){
  detach_snail();
  snail=snails[0];
  attach_snail();
 }
 else if(timeN==2){
  detach_snail();
  snail=snails[1];
  attach_snail();
 }
timeN++;

}
//------------------------------------------------------------------------------
void Snail::animleft()
{
 if(timeN==4)timeN=0;
 if(timeN==0){
  detach_snail();
  snail=snails[2];
  attach_snail();
 }
 else if(timeN==2){
  detach_snail();
  snail=snails[3];
  attach_snail();
 }
timeN++;

}
//------------------------------------------------------------------------------
bool Snail::colisTopSnail()
{
//height of the snail is 12 pixels *5=60px
 bool colis=false;
  if(player->point(0).y+100>snail->point(0).y+20
     &&player->point(0).x<snail->point(0).x+snailWidth-10
     &&player->point(0).x+80>snail->point(0).x+10
     &&player->point(0).y+100<snail->point(0).y+snailHight-2
     ){
   colis=true;

  }
  return colis;
}
bool Snail::colisy_left(int y,int x)
{
 bool flag=false;
 if(y>=0&&x>=0&&y<mapHeight&&x<mapWidth)
 {
    if(tiles[y][x+1].id==1)flag=true;//
 }//end if
//this need to be checked only if no tiles when moving left
 return flag;
 }
 //
bool Snail::colisy_right(int y,int x)
{
 bool flag=false;
//this need to be checked only if snail moves right
 if(y>=0&&x>=0&&y<mapHeight&&x<mapWidth)
 {
     if(tiles[y][x].id==1)flag=true;//
 }
   return flag;
}
//this checks colision only if caracter moves and not in a fall
bool Snail::colis_left_cara_snail()
{
 bool col=false;
if(islive){
  if(player->point(0).x+80>snail->point(0).x
     &&player->point(0).y+100>snail->point(0).y+20
     &&player->point(0).x+80<snail->point(0).x+40)
  {
    //cout<<"left_colision"<<endl;
    col=true;
    *main_tim=false;
  }
  //cout<<"left colis"<<endl;
}
  return col;
}
bool Snail::colis_right_cara_snail()
{
 bool col=false;
if(islive){
  if(player->point(0).x<snail->point(0).x+80
     &&player->point(0).y+100>snail->point(0).y+20
     &&player->point(0).x>snail->point(0).x+40)
  {
    //cout<<"left_colision"<<endl;
    col=true;
    *main_tim=false;
  }
  //cout<<"left colis"<<endl;
}
  return col;
}



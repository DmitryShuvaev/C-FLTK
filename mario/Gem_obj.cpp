#include "Gem_obj.h"

Gem_obj::Gem_obj():
gemWidth(80),
gemHight(80),
mapWidth(20),//size of the x in array
mapHeight(9),
timeN(0)
{
    gem=new Image(Point(0,0),"Resources/gems.png");
    Fl_PNG_Image *img = new Fl_PNG_Image("Resources/gems.png");
    Fl_Image *temp;
    temp=img->copy(img->w()*5,img->h()*5);//highte 20px
    *gem=temp;
    gem->set_mask(Point(0,0),gemWidth,gemHight);
    delete img;
}
//------------------------------------------------------------------------------
void Gem_obj::init(Tiles (&a)[9][20])
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
void Gem_obj::add(Tiles (&a)[9][20])
{
 init(a);
 for(int y=0;y<mapHeight;y++)
 {
 for(int x=0;x<mapWidth;x++)
 {
  if(tiles[y][x].jump_block.id==gemID&&tiles[y][x].id==1)
  {
   gem->move(tiles[y][x].tile->point(0).x,tiles[y][x].tile->point(0).y-4*5);
   cout<<tiles[y][x].tile->point(0).x<<endl;
   cout<<"gem moved";
  }
 }
 }

}
void Gem_obj::initial(int xx,int yy)
{
gem->move(xx,yy);
}
Gem_obj::~Gem_obj()
{
    //dtor
}

#include "Gem.h"

Gem::Gem():x(0),y(0)
{
    //ctor
//initial();
}
Gem::Gem(int xx,int yy):x(xx),y(yy)
{
    //ctor
initial(xx,yy);
}
void Gem::initial(int xx,int yy)
{
     tile=new Image(Point(xx,yy),"Resources/gems.png");
    Fl_PNG_Image *img = new Fl_PNG_Image("Resources/gems.png");
    Fl_Image *temp;
    temp=img->copy(img->w()*5,img->h()*5);//highte 20px
    *tile=temp;
    tile->set_mask(Point(0,0*5),16*5,16*5);
    delete img;
}
Gem::~Gem()
{
    //dtor
    //delete tile;
}

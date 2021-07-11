#include "Box.h"


Box::Box(int x,int y,int w,int h,const char* file_name)
:Fl_Box(x,y,w,h)
{
    Fl_PNG_Image  *png=new Fl_PNG_Image(file_name);
    png_image = png->copy(this->w()-4, this->h()-40);
    delete png;
    image(png_image);
    this->box (FL_SHADOW_BOX);
    this->color(207);
}
Box::~Box()
{
    //dtor
    delete png_image;
    cout<<"box_deleted"<<endl;
}
void Box::set_image(const char* file_name)
{
    Fl_PNG_Image  *png=new Fl_PNG_Image(file_name);
    png_image = png->copy(this->w()-4, this->h()-40);
    delete png;
    image(png_image);
}

#ifndef BOX_H
#define BOX_H
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>
using namespace std;
class Box:public Fl_Box
{
    public:

        Box(int x,int y,int w,int h,char* file_name);
        virtual ~Box();
        void set_image(char* file_name);
        void draw()
        {

          if(png_image!=NULL)
          {
           Fl_Box::draw();
          }
        }
Fl_Image* png_image=NULL;
char* file_name=NULL;
};

#endif // BOX_H

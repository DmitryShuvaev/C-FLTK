#ifndef BOX_H
#define BOX_H
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>
using namespace std;
class Box:public Fl_Box
{
    public:

        Box(int x,int y,int w,int h,const char* file_name);
        virtual ~Box();
        void set_image(const char* file_name);
Fl_Image* png_image;

};

#endif // BOX_H

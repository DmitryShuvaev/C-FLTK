#ifndef WINDOW_H
#define WINDOW_H
#include <FL/Fl.H>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Button.H> // For the button class
#include <FL/Fl_Shared_Image.H>
#include <iostream>
#include <string>
#include <list>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Group.H>
#include <FL/fl_ask.H>
#include "Box.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
class Window: public Fl_Window
{
    public:
        struct Boxes {
            Box*box=NULL;
            ~Boxes() {
                if(box!=NULL)
                {
                    delete box;
                    box=NULL;
                    cout<<"struct deleted"<<endl;
                }
            }
        };
        Window(int width, int height, char* title=0);
        Window(int x,int y,int width, int height, char* title=0);
        virtual ~Window();
        char* intToStr(int data)
        {
            std::string strData = std::to_string(data);

            char* temp = new char[strData.length() + 1];
            strcpy(temp, strData.c_str());

           return temp;
        }
                // * The button callback function
        //=============================================================================
        static void butn_calb(Fl_Widget *w, void* v)
        {

         Window* win = (Window*)v;

         win->Button_Callback(w);
        }
        void Button_Callback(Fl_Widget *w)
        //=============================================================================
        {

          rand_images();

        }//
        void draw()
        {
            for(int i = 0; i < size; i++)
            {
                if(b[i].box!=NULL)
                {
                    //b[i].box->draw();
                    cout<<"b["<<i<<"].box!=NULL"<<endl;
                    Fl_Window::draw();
                    //
                }else
                {
                    //cout<<"b["<<i<<"].box=NULL"<<endl;
                }
            }
            //Fl_Window::draw();
        }
        int handle(int e);
        int handle_key(int event, int key);
        void rand_images();
        void resizeAr(Boxes*&ar);
        int size=0;
    Boxes*b=NULL;
    Fl_Pack*pack;
    Fl_Button*button;
    //
    char* fnames[7];
};

#endif // WINDOW_H

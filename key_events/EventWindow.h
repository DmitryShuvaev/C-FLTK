
#ifndef __EVENTWINDOW_H
#define __EVENTWINDOW_H
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Round_Button.H>
#include <stdio.h>

 
class EventWindow: public Fl_Window
{
        private:
    //            int handle_mouse(int event, int button, int x, int y);
				//int handle_key(int event,int key);
				Fl_Check_Button* check_b;
                Fl_Light_Button* light_b;
				Fl_Round_Button* round_b;
        public:

                EventWindow(int width, int height);
                //int handle(int e);
				void checkbutton_cb(Fl_Widget* w);
				static void checkbutton_cb_s(Fl_Widget*w,void*data);
				// Create pointers to a check button and a light button
				void lightbutton_cb(Fl_Widget* w);
				static void lightbutton_cb_s(Fl_Widget*w,void*data);
				static void round_b_cb_s(Fl_Widget* w,void*data);
				void round_b_cb(Fl_Widget* w);

};

 

#endif
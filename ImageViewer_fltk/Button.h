#ifndef BUTTON_H
#define BUTTON_H
#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <string>
#include <cstring>
using namespace std;
class Button: public Fl_Button
{
    public:
        Button(int x,int y,int width, int height, char* title=0);
        virtual ~Button();
        char* intToStr(int data)
        {
            std::string strData = std::to_string(data);

            char* temp = new char[strData.length() + 1];
            strcpy(temp, strData.c_str());

           return temp;
        }
                // * The button callback function
        //=============================================================================
        static void btn_cb(Fl_Widget *w, void* v)
        {

         Button* win = (Button*)v;

         win->Button_Callback(w,win->n);
        }
        void Button_Callback(Fl_Widget *w,int num)
        //=============================================================================
        {
         if(Fl::event_button()==FL_RIGHT_MOUSE)
         {
          w->color (FL_RED);
         }
         else if(Fl::event_button()==FL_LEFT_MOUSE)
         {
          w->color (FL_GREEN);
         }
         w->label(intToStr(num));
        }
    int n;
};

#endif // BUTTON_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Choice.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.h>
#include "Calculate.h"
#include "Box.h"
using namespace std;

class MainWindow: public Fl_Window
{
    public:

        MainWindow(int w, int h, const char* title);
        virtual ~MainWindow();
       void draw()
       {
           Fl_Window::draw();

           this->redraw();

       }
      Fl_Button* copy;
      Fl_Button* quit;

      //
      Fl_Button*but_cbB;
      Fl_Input* inp;
      Fl_Output* out;
      Fl_Choice *materialchoice;
      Fl_Choice *radiuschoice;
      Fl_Text_Display *BAtext;
      Fl_Text_Buffer* tb;
      //Fl_PNG_Image  *pic1;
      //Fl_Box*box;
      Fl_Image *pic1;
      Box *picbox=NULL;
   private:
      //static void cb_copy(Fl_Widget*, void*);
      //inline void cb_copy_i(const char* v);

      static void cb_quit(Fl_Widget*, void*);
      inline void cb_quit_i();
      static void but_cb(Fl_Widget* o, void*);
      inline void but_cb_i();
      double res;
       int x1;
};

#endif // MAINWINDOW_H

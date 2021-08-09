#include "MyApp.h"

MyApp::MyApp(int x,int y,int width, int height, char* title)
         : Fl_Window(x,y,width, height, title)
{
    //ctor
    color(FL_BLACK);

}

MyApp::~MyApp()
{
    //dtor
}
        int MyApp::handle(int event)
        {
        int r=Fl_Window::handle(event);
        switch (event) {
         case FL_SHORTCUT:

             if(Fl::event_key()==FL_Up)
             {

              if(sep<100)
              {
                  sep+=1;
                  redraw();
              }
             }
              //
             else if(Fl::event_key()==FL_Down)
             {

              if(sep>1)
              {
                  sep-=1;
                  redraw();
              }
             }

              return 1;

          default:
          return r;
            };

        }

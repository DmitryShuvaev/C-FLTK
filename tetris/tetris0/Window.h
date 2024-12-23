#ifndef WINDOW_H
#define WINDOW_H
#include <FL/Fl.H>
#include <FL/Fl_Window.h>
#include <FL/Fl_Double_Window.H>

class Window: public Fl_Double_Window
{
    public:

        Window(int x,int y,int width, int height, char* title=0);
        virtual ~Window();
    //protected:

    private:
};

#endif // WINDOW_H

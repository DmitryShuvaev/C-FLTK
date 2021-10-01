#include "Window.h"

int main (int argc, char ** argv)
{
system("chcp 65001  > nul");        // Important code line executed before any printf call
  //Window win(650,400,"sierpinski");
  Mwindow win(100,0,700,700,"sierpinski");
  win.show();
  return(Fl::run());
}

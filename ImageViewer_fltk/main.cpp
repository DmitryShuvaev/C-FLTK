
#include "Window.h"
int main (int argc, char ** argv)
{
  Window win(0,0,700+(2*50),300,"Imageviewer");
  win.show();
  return(Fl::run());
}

#include "Window.h"

int main (int argc, char ** argv)
{

  Window win(650,400,"Slot Machine");
  //Window win(300,400,400,400,"Empty Window");
  win.show();
  return(Fl::run());
}

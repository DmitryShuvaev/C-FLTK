#include "Window.h"


int main (int argc, char ** argv)
{
  const int width=400; const int height=800;
  WWindow win(800,20,width, height,"tetris");
  win.show();
  return(Fl::run());
}

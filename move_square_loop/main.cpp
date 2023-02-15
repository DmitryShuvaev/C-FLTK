#include "MyApp.h"
int main (int argc, char ** argv)
{
  const int size=301;
  MyApp win(800,20,400, 800);
  win.show();
  return(Fl::run());
}


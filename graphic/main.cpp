#include "MyApp.h"
int main (int argc, char ** argv)
{
  const int size=500;
  MyApp win(500,200,size, size);
  win.show();
  return(Fl::run());
}

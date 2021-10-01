#include "MainWindow.h"

int main (int argc, char ** argv)
{
   setlocale(LC_ALL,".ACP");
   MainWindow win(1024,768,"Sheetmetal Flat length Calculation");
   return Fl::run();
}

#include "MainWindow.h"

MainWindow::MainWindow(int width, int height, const char* title):Fl_Window(width,height,title),
//txtX(450,10,20,20,20),
//txte(450,200,20,20,40),
l(0,0,BOARDSIZE,BOARDSIZE)

{
    //ctor
    //label("Integral");
  uchar buffer[32*32*3];
  Fl_RGB_Image icon(buffer, 32, 32, 3);
  icon.color_average(FL_BLUE, 0.0);
  //icon.;
  this->icon(&icon);
    button1 = new Fl_Button(450,15,140,40,"OK");
    button1->callback(button1_cb,this);
     for(int y=0;y<boardSize;y++)
      for(int x=0;x<boardSize;x++)
      txte[y][x]=new Text(0,5,20,20,40);
    Fl_Window::draw();
    show();
}
//***************************
void MainWindow::button1_cb(Fl_Widget* buttonptr,void* o){
 MainWindow *w = (MainWindow*)o;
 static int n=0;
  w->cal_cb(n++);
}//
//***************************
void MainWindow:: cal_cb(int n){
   if(n==0)
 k=new Knight();
 else
 {
     cout<<"n>0"<<endl;
    k->step_back();

    k->run();
 }
 printKnights(k);
 k->print();
// for(int y=0;y<boardSize;y++){
//
//  for(int x=0;x<boardSize;x++)
//  {
//
//    if(k->G[y][x]>0)
//    {
//        char n[80];
//        if(k->G[y][x]>=10)
//        txte[y][x]->draw_coord((x*BOXSIZE+8)+10,(y*BOXSIZE+8)+10,20,20,40);
//        else txte[y][x]->draw_coord(x*BOXSIZE+8,(y*BOXSIZE+8)+10,20,20,40);
//          //kings[x][y].txte.draw_coord(x*BOXSIZE+8,y*BOXSIZE+8,20,20,40);
//           sprintf(n, "%2ld", k->G[y][x]);
//           txte[y][x]->drawText(n);
//    }
//  }
//
// }
Fl::add_timeout(0, Timer_CB, (void*)this);
//txt.drawText("X1");
redraw();
}
MainWindow::~MainWindow()
{
    //dtor
    if(button1)
    delete button1;
    delete k;
    for(int y=0;y<5;y++)
      for(int x=0;x<5;x++)
        delete txte[x][y];
        //delete []txte;
}

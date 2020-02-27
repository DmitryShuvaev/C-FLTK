#include "Graph.h"
#include "Simple_window.h"
#include <FL/Fl_Shared_Image.H>
//#include "Queens.h"
using namespace Graph_lib;
void polyf(Graph_lib::Polygon &poly,Simple_window& win){
    poly.add(Point{300,200}); //add point
    poly.add(Point{350,100}); //another point
    poly.add(Point{400,200}); //third point
    poly.set_color(Color::red);  //adjust properties of poly
    win.attach(poly);      //connect poly to the window
}
void rectFiled(Closed_polyline &poly_rect,Simple_window& win){
    poly_rect.add(Point(100,50));
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(100,100));
    //poly_rect.add(Point(50,75));
    poly_rect.set_fill_color(Color::green);
    //win.attach(poly_rect);
}
void gridf(Graph_lib::Lines &grid,Simple_window& win){

    int x_size=win.x_max();
    int y_size=win.y_max();
    int x_grid=80;
    int y_grid=40;
    //Graph_lib::Lines grid;
    grid.set_color(Color::red);
    grid.set_style(Line_style(Line_style::dash,2));
    for(int x=x_grid;x<x_size;x+=x_grid)
        grid.add(Point(x,0),Point(x,y_size));
    for(int y=y_grid;y<y_size;y+=y_grid)
        grid.add(Point(0,y),Point(x_size,y));
    win.attach(grid);
}//
void axisF(Simple_window& win){



}
void imagef(Simple_window& win){

}
struct Cell{
bool queen;
};
void print_top(int wid){
for(int i=0;i<wid;i++){
cout<<"-";
}
}
void board_pr()
{
     string cheseBoard[8][8];
for(int i=0;i<8;i++){

for(int j=0;j<8;j++){
 if(i%2==0){
//if(j<4){
 cheseBoard[i][j]="-----";

 print_top(2);
 //}
 }
 else if(j==0){
 cout<<"|";
  cheseBoard[i][j]="|";
 }else {
cheseBoard[i][j]="x|";
cout<<"x|";
}
}
string t=cheseBoard[i][4]+"\n";
cheseBoard[i][4]=t;
cout<<"\n";
}
}
int chese_board[4][4];
void print_ches_top(int n)
{
    int len=(n*3)-(n-1);
  for(int i=0;i<len;i++)
  {
      cout<<"-";
  }
cout<<"\n";
}
void print_ches_wals(int n,int y)
{

  for(int x=0;x<n;x++)
  {
      cout<<"|";
      cout<<chese_board[y][x];
  }
  cout<<"|\n";
}
void print_board()
{
 int x=4;
 int y=4;

 for(int i=0;i<y;i++)
 {
    print_ches_top(x);
    print_ches_wals(x,i);
 }
 print_ches_top(x);
}
int main()
{
    Point tl(150,150);
    Simple_window win(tl,BOARDSIZE,BOARDSIZE,"8 Queens");
    win.color(FL_WHITE);

    Fl::run();
}

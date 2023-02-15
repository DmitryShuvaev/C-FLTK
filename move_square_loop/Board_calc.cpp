#include "Board_calc.h"

Board_calc::Board_calc()
{
    //ctor
 init();
    //Board_print();
}//
void Board_calc::init()
{
     for(int x=0;x<width;x++)
    {
        for(int y=height-1;y>=0;y--)
        {
         board[y][x]=0;
         //if(y==height-1)board[y][x]=1;
        }
    }
}
void Board_calc::Board_print()
{

        for(int y=0;y<height;y++)
        {
          for(int x=0;x<width;x++)
          {
           cout<<board[y][x]<<" ";
          }
          cout<<endl;
        }
cout<<"***************"<<endl;
}
bool Board_calc::colision(int indx,int indy)
{
    if(board[indy][indx]==1)return true;
    if(indy==height-1)return true;
    return false;
}//
void Board_calc::check_col(Rectangle1*r[4])
{
     if(r==NULL)cout<<"null";
     for(int i=0;i<4;i++)
     {
      colision(r[i]->x/40,r[i]->y/40);
     }
}//
bool Board_calc::chec_empty_r(Rectangle1*r[4])
{
 for(int i=0;i<4;i++)
 {
 if(r[i]==NULL)return false;
 }
     return true;
}//
bool Board_calc::check_col_y(Rectangle1*r[4])
{
     if(chec_empty_r(r))
     {
     for(int i=0;i<4;i++)
     {

      int yv=r[i]->y/40;
      int xv=r[i]->x/40;

      if(yv>=0&&xv>=0)
      {

      if(yv==height||
         board[yv][xv]==1
         )return true;
      }
     }
     }
     return false;
}//
bool Board_calc::finish_game(Rectangle1*r[4])
{
 //cout<<r[0]->y/40<<endl;
 for(int i=0;i<4;i++)
 {
   int yv=((r[i]->y)-40)/40;
   if((yv)<=0)
   {
       cout<<yv<<endl;
       return true;
   }
 }
 return false;
}
bool Board_calc::check_same_x_line(const int indexy)
{
     for(int x=0;x<width;x++)
     {
      if(board[indexy][x]!=1)return false;
     }
  return true;
}//
void Board_calc::shift_y()
{
 int miny=height-1;int shift_to;
 bool foundx=false;
 for(int y=height-1;y>=0;y--)
 {
  if(check_same_x_line(y))
  {
   if(y<miny)
   miny=y;
   if(!foundx)shift_to=y;
   foundx=true;
  }
 }
  if(foundx){
        //cout<<miny<<" "<<shift_to<<endl;
        shift_from_to(miny,shift_to);
        //Board_print();
  }
}//
void Board_calc::shift_from_to(int miny,int shift_to)
{
 for(int y=miny-1;y>=0;y--,shift_to--)
 {
   for(int x=0;x<width;x++)
   {
    board[shift_to][x]= board[y][x];
   }

 }
}//
bool Board_calc::can_add_to_board(Rectangle1*r[4])
{
if(!chec_empty_r(r))
{
return false;
}
 for(int i=0;i<4;i++)
 {
    int yv=r[i]->y/40;
    int xv=r[i]->x/40;
//cout<<"y="<<yv<<"x="<<xv<<endl;
    //if(yv<height-1)
    if(board[yv][xv]!=0)
    {

        return false;
    }
 }

 return true;
}
void Board_calc::add(Rectangle1*r[4])
{
     if(r==NULL)cout<<"null";
     for(int i=0;i<4;i++)
     {
      int yv=r[i]->y/40-1;
      int xv=r[i]->x/40;
      if(yv>=0)
      board[yv][xv]=1;

     }
}
bool Board_calc::check_level()
{

          for(int x=0;x<width;x++)
          {
           if(board[0][x]==1)return true;;
          }

        return false;
}
Board_calc::~Board_calc()
{
    //dtor
}

#ifndef QUEENS_H
#define QUEENS_H
#include "Graph.h"
#include <iostream>
using namespace Graph_lib;
using namespace std;
class Queens
{
    public:
    struct Queen{
        int x,y;
        Queen(){x=0;y=0;}
        };
        Queens();
        virtual ~Queens();


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
 int x=x_size;
 int y=y_size;

 for(int i=0;i<y;i++)
 {
    print_ches_top(x);
    print_ches_wals(x,i);
 }
 print_ches_top(x);
}
Queen get_queen(int y)
{
    Queen q;
    for(int x=0;x<=x_size-1;x++)
    {
     if(chese_board[y][x]>0)
     {
         q.x=x;
         q.y=y;

     }
    }
    return q;
}
bool can_move(Queen q)
{
 if(chese_board[q.y][q.x]!=0)
 {
  if(q.x==x_size-1)return false;
 }
    return true;
}
//
void move_queen_right()
{
 chese_board[queen.y][queen.x+1]= chese_board[queen.y][queen.x];
 chese_board[queen.y][queen.x]=0;
 queen.x++;
}
bool check_vertical(int x)
{
bool q=false;
for(int y=y_size-1;y>=0;y--)
{
    if(chese_board[y][x]>0)
    {
        q=true;
        break;
    }
}
//it return true if queen found
return q;
}
//shift all queens down the current level
void shift_queens()
{
    for(int y=cur_ylevel+1;y<y_size;y++)
    {
        queen=get_queen(y);
        for(int x=0;x<x_size;x++)
        {
         if(check_vertical(x)==false)
         {
           chese_board[y][x]= chese_board[y][queen.x];
           chese_board[y][queen.x]=0;
           break;
         }
        }
    }
}
//checking horizontal moves so whether the queen can be placed in propriate place
bool check_horizontal(int x,int y)
{
    bool hor=true;
    for(int xl=0;xl<x_size;xl++)
    {
        if(chese_board[y][xl]>0&&xl!=x)
        {
            hor=false;
            break;
        }
    }
    //it returns true if no other queens in line
    return hor;
}
//
bool check_vertical_bord(int x,int y)
{
    bool ver=true;
    for(int yl=y_size-1;yl>=0;yl--)
    {
        if(chese_board[yl][x]>0&&yl!=y)
        {
            ver=false;
            break;
        }
    }
    return ver;
}
//checking diagonal position of the queens
bool check_left_diag(int x,int y)
{
 bool diag=true;
 int cx=x;
 for(int cy=y-1;cy>=0;cy--)
 {
     cx--;
     if(cx>0)
     {

      if(chese_board[cy][cx]>0&&cy!=y&&cx!=x)
      {
          diag=false;
          //chese_board[cy][cx]=8;
          break;
      }
     }
 }
 return diag;
}
//
bool check_right_top_diag(int x,int y)
{
 bool diag=true;
  int cx=x;
  int cy=y-1;
 for(;cy>=0;cy--)
 {

      ++cx;
    if(cx<x_size)
     {
      if(chese_board[cy][cx]>0&&cy!=y&&cx!=x)
      {
          diag=false;
          break;
       //chese_board[cy][cx]=8;
      }
      //chese_board[cy][v]=v;
     }
    // cout<<cy<<endl;
 }
 return diag;
}//
bool check_left_diag_low(int x,int y)
{
  bool diag=true;
  int cx=x;
   for(int cy=y+1;cy<y_size;cy++)
   {
       cx--;
       if(cx>0)
       {

            if(chese_board[cy][cx]>0&&cy!=y&&cx!=x)
            {
             diag=false;
            }

       }
   }
    return diag;
}//
bool check_right_diag_low(int x,int y)
{
   bool diag=true;
   int cx=x;
   for(int cy=y+1;cy<y_size;cy++)
   {
       cx++;
       if(cx<x_size)
       {

           if(chese_board[cy][cx]>0&&cy!=y&&cx!=x)
           {
               diag=false;
           }
       }
   }
    return diag;
}//
bool solved()
{
    bool solved=true;
    Queen q;
    for(int y=0;y<y_size;y++)
    {
        q=get_queen(y);
        if(check_vertical_bord(q.x,q.y)==false)
        {
            solved=false;
            break;
        }
        if(check_left_diag(q.x,q.y)==false)
        {
            solved=false;
            break;
        }
        if(check_left_diag_low(q.x,q.y)==false)
        {
            solved=false;
            break;
        }
        if(check_right_top_diag(q.x,q.y)==false)
        {
            solved=false;
            break;
        }
        if(check_right_diag_low(q.x,q.y)==false)
        {
            solved=false;
            break;
        }
    }
    return solved;
}
void start_sequence()
{
 //here must be while loop to start
 //
 int count=0;
 while(solved()==false){
//
//if(solved())break;
  while(can_move(queen)==false)
  {
    cur_ylevel--;
    queen=get_queen(cur_ylevel);
  }
  //print_board();

//cout<<chese_board[queen.y][queen.x]<<endl;
    //cout<<can_move(queen)<<endl;
    //cout<<cur_ylevel<<endl;
    //now queen can be moved horizintaly so
    //move queen to the right to one position
    if(can_move(queen))
    {
     move_queen_right();
     shift_queens();
    }

    cur_ylevel=y_size-1;

   queen=get_queen(cur_ylevel);
    //cout<<queen.x<<" "<<queen.y<<endl;
    //cout<<chese_board[queen.y][queen.x]<<endl;
//    //cout<<check_horizontal(queen.x,queen.y)<<endl;
//    //cout<<check_vertical_bord(queen.x,queen.y)<<endl;
//    cout<<check_left_diag(queen.x,queen.y)<<endl;
    //cout<<check_right_top_diag(queen.x,queen.y)<<endl;
cout<<count++<<endl;
 }
    print_board();
}
int x_size,y_size;
int chese_board[8][8];
int cur_ylevel;

Queen queen;
};

#endif // QUEENS_H

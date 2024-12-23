#include "N_piece.h"

N_piece::N_piece()
{
    //ctor
}
N_piece::N_piece(Board_calc *bc,Rectangle1*r[4])
{
    //ctor
 //bc->board[2][3]=1;
 bc->Board_print();
// for(int i=0;i<4;i++)
// {
// if(r[i]==NULL)
// r[i]=new Rectangle1((1+indx)*40,i*40,40,40);
// }
rot_dir_0(bc,r);
}//
void N_piece::add_piece(Board_calc *bc,Rectangle1*r[4])
{

 if(indx<0)indx=0;

 if(dir==0)
 {
  if(can_add_dir_0(bc))
  {

   rot_dir_0(bc,r);
  }
 }
 else if(dir==1)
 {
   if(can_add_dir_1_2_3(bc,N_hor_low))
   {

    rot_dir_1_2_3(bc,r,N_hor_low);
   }
}
 else if(dir==2)
 {
  if(can_add_dir_1_2_3(bc,N_ver_right))
  {

    rot_dir_1_2_3(bc,r,N_ver_right);
  }
}
 else if(dir==3)
 {
   if(can_add_dir_1_2_3(bc,N_hor))
   {

    rot_dir_1_2_3(bc,r,N_hor);
   }
}//end if dir3


}//
void N_piece::rot_dir_0(Board_calc *bc,Rectangle1*r[4]){
 delet_pieces(r);
 int i=0;
 for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(N_ver[y][x]==1)
      {
       int x_v=((x*40))+(indx*40);
       int y_v=y*40+(indy*40);
       r[i++]=new Rectangle1(x_v,y_v,40,40);

      }
     }
 }

}/****************/
void N_piece::rot_dir_1_2_3(Board_calc *bc,Rectangle1*r[4],const int (&N_dir)[3][3]){
delet_pieces(r);
int tx=indx+1;
int i=0;
for(int y=0;y<3;y++)
{
 for(int x=0;x<3;x++)
 {
  if(N_dir[y][x]==1)
  {
//   if(tx>7)
//   {
//       indx=7;
//   }
   int x_v=((x*40))+(indx*40);
   int y_v=y*40+(indy*40);
   r[i++]=new Rectangle1(x_v,y_v,40,40);

  }
 }
}
}
bool N_piece::can_add(Board_calc *bc,int xv,int yv)
{
  if(bc->board[yv][xv]==1)
  {
      return false;
  }
  return true;
}/**************************/



void N_piece::move_right_loop(Rectangle1*r[4])
{
     indx++;
     for(int i=0;i<4;i++)
     {
     r[i]->x+=40;
     }
}//
void N_piece::move_pieces_right(Board_calc *bc,Rectangle1*r[4])
{
 if(can_move_right(bc,r)){
 if(indx<8&&dir==0)
 {
  move_right_loop(r);
 }else if(indx<=6&&(dir==1||dir==3))//horizontal
 {
move_right_loop(r);
 }else if(indx<7&&dir==2)
 {
move_right_loop(r);
 }
 }
}/*************************/
bool N_piece::can_move_right(Board_calc *bc,Rectangle1*r[4])
{
 int tx;
 for(int i=0;i<4;i++)
 {
  tx=(r[i]->x/40)+1;
  if(bc->board[r[i]->y/40][tx]==1)
  {
      return false;
  }
 }
 return true;
}/************************/
void N_piece::move_pieces_left(Board_calc *bc,Rectangle1*r[4])
{
 if(can_move_left(bc,r)){
 if(indx>0&&(dir==1||dir==3))
 {
  move_left_loop(r);
 }else if(indx>0&&dir==0)
 {
  move_left_loop(r);
 }else if(indx>-1&&dir==2)
 {
  move_left_loop(r);
 }
 }
}/************************/
bool N_piece::can_move_left(Board_calc *bc,Rectangle1*r[4])
{
 int tx;
 for(int i=0;i<4;i++)
 {
  tx=(r[i]->x/40)-1;
  if(bc->board[r[i]->y/40][tx]==1)
  {
      return false;
  }
 }
 return true;
}/*******************************/
void N_piece::move_left_loop(Rectangle1*r[4])
{
     indx--;
     for(int i=0;i<4;i++)
     {
     r[i]->x-=40;
     }
}/**************************/
void N_piece::move_down(Rectangle1*r[4])
{
      if(r!=NULL)
      {
      indy++;
     for(int i=0;i<4;i++)
     {
     //if(r[i]!=0)
     r[i]->y+=40;
     }
      }
}
bool N_piece::can_add_dir_0(Board_calc *bc)
{
 for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(N_ver[y][x]==1)
      {
       int x_v=x+indx;
       int y_v=y+indy;
       if(!can_add(bc,x_v,y_v))return false;
      }
     }
 }
 return true;
}/**********************************************/
bool N_piece::can_add_dir_1_2_3(Board_calc *bc,const int (&N_dir)[3][3])
{
    int tx=indx+1;
    for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {

      if(N_dir[y][x]==1)
      {
       if(tx>7)
       {
           indx=7;
       }
      int x_v=x+indx;
      int y_v=y+indy;
      if(!can_add(bc,x_v,y_v))return false;

      }
     }
 }
 return true;
}//
void N_piece::delet_pieces(Rectangle1*r[4])
{
  for(int i=0;i<4;i++)
 {
  if(r[i]!=NULL)
  {
    delete r[i];
    r[i]=NULL;
  }

 }
}/*****************/



N_piece::~N_piece()
{
    //dtor
}

#include "Pieces.h"
//I piece

I_piece::I_piece(Board_calc *bc,Rectangle1*r[4])
{
    //ctor
bc->board[1][5]=1;
bc->Board_print();
 for(int i=0;i<4;i++)
 {
 r[i]=new Rectangle1(1*40,i*40,40,40);
 }

 add_piece(bc,r);

}//
void I_piece::add_piece(Board_calc *bc,Rectangle1*r[4])
{
 delet_pieces(r);
 if(indx<0)indx=0;
 int tx=indx+1;
 int i=0;
 if(dir==0)
 {
 if(can_add_dir_0(bc))
 {
 for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {
      if(I_ver[y][x]==1)
      {
       int x_v=((x*40))+(indx*40);
       int y_v=y*40+(indy*40);
       r[i++]=new Rectangle1(x_v,y_v,40,40);

      }
     }
 }
 }
 }

}/***************/
bool I_piece::can_add_dir_0(Board_calc *bc)
{
 for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {
      if(I_ver[y][x]==1)
      {
       int x_v=x+indx;
       int y_v=y+indy;
       if(!can_add(bc,x_v,y_v))return false;
      }
     }
 }
 return true;
}/**********************************************/
bool I_piece::can_add(Board_calc *bc,int xv,int yv)
{
  if(bc->board[yv][xv]==1)
  {
      return false;
  }
  return true;
}/**************************/
void I_piece::delet_pieces(Rectangle1*r[4])
{
  for(int i=0;i<4;i++)
 {
  if(r[i]!=NULL)
  {
    delete r[i];
    r[i]=NULL;
  }

 }
}

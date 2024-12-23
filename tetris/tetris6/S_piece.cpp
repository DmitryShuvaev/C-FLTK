#include "S_piece.h"

S_piece::S_piece()
{
    //ctor
}
S_piece::S_piece(Board_calc *bc,Rectangle1*r[4])
{
    //ctor
 //bc->board[2][3]=1;
 bc->Board_print();

rot_dir_0(bc,r);
}//
void S_piece::rot_dir_0(Board_calc *bc,Rectangle1*r[4]){
 delet_pieces(r);
 int i=0;
 for(int y=0;y<2;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(S_ver[y][x]==1)
      {
       int x_v=((x*40))+(indx*40);
       int y_v=y*40+(indy*40);
       r[i++]=new Rectangle1(x_v,y_v,40,40);

      }
     }
 }

}/****************/
void S_piece::move_pieces_right(Board_calc *bc,Rectangle1*r[4])
{
 if(can_move_right(bc,r)){
 if(indx<7)
 {
  move_right_loop(r);
 }
 }
}/*************************/
bool S_piece::can_move_right(Board_calc *bc,Rectangle1*r[4])
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
void S_piece::move_right_loop(Rectangle1*r[4])
{
     indx++;
     for(int i=0;i<4;i++)
     {
     r[i]->x+=40;
     }
}//
void S_piece::move_pieces_left(Board_calc *bc,Rectangle1*r[4])
{
 if(can_move_left(bc,r)){
 if(indx>=0)
 {
  move_left_loop(r);
 }
 }
}/************************/
bool S_piece::can_move_left(Board_calc *bc,Rectangle1*r[4])
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
void S_piece::move_left_loop(Rectangle1*r[4])
{
     indx--;
     for(int i=0;i<4;i++)
     {
     r[i]->x-=40;
     }
}/**************************/
void S_piece::move_down(Rectangle1*r[4])
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
void S_piece::delet_pieces(Rectangle1*r[4])
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
S_piece::~S_piece()
{
    //dtor
}

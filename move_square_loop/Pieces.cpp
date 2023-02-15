#include "Pieces.h"
//I piece
I_piece::I_piece()
{
    //ctor

 for(int i=0;i<4;i++)
 {
 r[i]=NULL;
 }

 //rotate_piece();

}//
I_piece::I_piece(Board_calc *bc)
{
  for(int i=0;i<4;i++)
 {
 r[i]=NULL;
 }
 rotate_piece(bc);
}//
bool I_piece::chec_empty_r()
{
  for(int i=0;i<4;i++)
     {
     if(r[i]==NULL)return false;
     }
     return true;
}//
void I_piece::move_right_loop()
{
     indx++;
     for(int i=0;i<4;i++)
     {
     r[i]->x+=40;
     }
}//
bool I_piece::can_rot_dir_0(Board_calc *bc)
{
 int i=0;
 for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {
      int x_v=((x*40))+(indx*40);
      int y_v=y*40+(indy*40);

      if(I_ver[y][x]==1)
      {
       if(!can_rotate(bc,x_v/40,y_v/40))return false;


      }
     }
 }
 return true;
}//
bool I_piece::can_rot_dir_1(Board_calc *bc)
{
    int tx=indx+1;
    for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {

      if(I_hor[y][x]==1)
      {
       if(tx>6)
       {
           indx=6;
       }
      int x_v=((x*40))+(indx*40);
      int y_v=y*40+(indy*40);
      if(!can_rotate(bc,x_v/40,y_v/40))return false;

      }
     }
 }
 return true;
}//
bool I_piece::can_rot_dir_2(Board_calc *bc)
{
    int tx=indx+1;
    for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {
      if(I_ver_right[y][x]==1)
      {
       if(tx>6)
       {
           indx=6;
       }
       int x_v=((x*40))+(indx*40);
       int y_v=y*40+(indy*40);
       if(!can_rotate(bc,x_v/40,y_v/40))return false;

      }
     }
 }
 return true;
}//
bool I_piece::can_rot_dir_3(Board_calc *bc)
{
   int tx=indx+1;
   for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {
      if(I_hor_up[y][x]==1)
      {
       if(tx>6)
       {
           indx=6;
       }
       int x_v=((x*40))+(indx*40);
       int y_v=y*40+(indy*40);
       if(!can_rotate(bc,x_v/40,y_v/40))return false;

      }
     }
 }
 return true;
}
void I_piece::rotate_piece(Board_calc *bc)
{
 delet_pieces();
 if(indx<0)indx=0;
 int tx=indx+1;
 int i=0;
 if(dir==0)
 {
 if(can_rot_dir_0(bc))
 {
 for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {
      int x_v=((x*40))+(indx*40);
      int y_v=y*40+(indy*40);

      if(I_ver[y][x]==1)
      {
       r[i++]=new Rectangle1(x_v,y_v,40,40);

      }
     }
 }
 }
 }
 else if(dir==1)
 {
   if(can_rot_dir_1(bc))
   {
   for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {

      if(I_hor[y][x]==1)
      {
       if(tx>6)
       {
           indx=6;
       }
      int x_v=((x*40))+(indx*40);
      int y_v=y*40+(indy*40);
       r[i++]=new Rectangle1(x_v,y_v,40,40);

      }
     }
 }
   }
}
 else if(dir==2)
 {
  if(can_rot_dir_2(bc))
  {
   for(int y=0;y<4;y++)
 {
     for(int x=0;x<4;x++)
     {
      if(I_ver_right[y][x]==1)
      {
       if(tx>6)
       {
           indx=6;
       }
       int x_v=((x*40))+(indx*40);
       int y_v=y*40+(indy*40);
       r[i++]=new Rectangle1(x_v,y_v,40,40);

      }
     }
 }
  }
}
 else if(dir==3)
 {
   if(can_rot_dir_3(bc))
   {
       for(int y=0;y<4;y++)
       {
         for(int x=0;x<4;x++)
         {
          if(I_hor_up[y][x]==1)
          {
           if(tx>6)
           {
               indx=6;
           }
           int x_v=((x*40))+(indx*40);
           int y_v=y*40+(indy*40);
           r[i++]=new Rectangle1(x_v,y_v,40,40);

          }
         }
        }
   }
}//end if dir3


}//
bool I_piece::can_rotate(Board_calc *bc,int xv,int yv)
{
  if(bc->board[yv][xv]==1)
  {
      return false;
  }
  return true;
}
void I_piece::move_pieces_right(Board_calc *bc)
{
 if(can_move_right(bc)){
 if(indx<8&&dir==0)
 {
  move_right_loop();
 }else if(indx<=5&&(dir==1||dir==3))//horizontal
 {
move_right_loop();
 }else if(indx<7&&dir==2)
 {
move_right_loop();
 }
 }
}//
void I_piece::move_left_loop()
{
     indx--;
     for(int i=0;i<4;i++)
     {
     r[i]->x-=40;
     }
}
void I_piece::move_pieces_left(Board_calc *bc)
{
 if(can_move_left(bc)){
 if(indx>0&&(dir==1||dir==3))
 {
  move_left_loop();
 }else if(indx>-1&&dir==0)
 {
  move_left_loop();
 }else if(indx>-2&&dir==2)
 {
  move_left_loop();
 }
 }
}//
bool I_piece::can_move_left(Board_calc *bc)
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
}//
bool I_piece::can_move_right(Board_calc *bc)
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
}//
void I_piece::move_down()
{
      if(r!=NULL)
      {
      indy++;
     for(int i=0;i<4;i++)
     {
     if(r[i]!=0)
     r[i]->y+=40;
     }
      }
}
void I_piece::delet_pieces()
{
  for(int i=0;i<4;i++)
 {
  if(r[i]!=NULL)
  {
      //cout<<"delete"<<endl;
      delete r[i];
  }

 }
}
I_piece::~I_piece()
{
    //dtor
    delet_pieces();
}//
//N piece
N_piece::N_piece()
{
    //ctor

 for(int i=0;i<4;i++)
 {
 r[i]=NULL;
 }

 rotate_piece();

}
void N_piece::rotate_piece()
{
 delet_pieces();
 int tx=indx+1;
 int i=0;
 if(dir==0)
 {
 for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(N_ver[y][x]==1)
      {
       r[i++]=new Rectangle1(((x*40))+(indx*40),y*40,40,40);

      }
     }
 }
 }
 else if(dir==1)
 {
  if(indx>=7)indx=7;
 for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(N_hor_low[y][x]==1)
      {
       r[i++]=new Rectangle1(((x*40))+(indx*40),y*40,40,40);

      }
     }
 }
 }
  else if(dir==2)
 {

 for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(N_ver_right[y][x]==1)
      {
       r[i++]=new Rectangle1(((x*40))+(indx*40),y*40,40,40);

      }
     }
 }
 }
 else if(dir==3)
 {
   if(indx<0)indx=0;
   for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(N_hor[y][x]==1)
      {

       r[i++]=new Rectangle1((x*40)+(indx*40),y*40,40,40);

      }
     }
 }
}
//print_indxy();

}//end rotate n piece
void N_piece::move_right_loop()
{
      indx++;
     for(int i=0;i<4;i++)
     {
     r[i]->x+=40;
     }
}
void N_piece::move_pieces_right()
{
 if(indx<=7&&dir==0)
 {
  move_right_loop();
 }else if(indx<=6&&(dir==1||dir==2||dir==3))//horizontal
 {
  move_right_loop();
 }
}//
void N_piece::move_left_loop()
{
     indx--;
     for(int i=0;i<4;i++)
     {
     r[i]->x-=40;
     }
}
void N_piece::move_pieces_left()
{
 if(dir==3&&indx<0)indx=1;
 if(indx>0&&dir!=2)
 {
  move_left_loop();
 }else if(indx>-1&&dir==2)
 {
  move_left_loop();
 }
}//
void N_piece::print_indxy()
{
 for(int i=0;i<4;i++)
 {
  cout<<"x="<<r[i]->x/40<<" y="<<r[i]->y/40<<endl;
 }
 cout<<'\n';
}//
void N_piece::delet_pieces()
{
  for(int i=0;i<4;i++)
 {
  if(r[i]!=NULL)
  {
      //cout<<"delete"<<endl;
      delete r[i];
  }

 }
}
N_piece::~N_piece()
{
    //dtor
    delet_pieces();
}//
/*T piece**T piece**T piece**T piece**T piece**T piece**T piece*/
void T_piece::rotate_piece()
{
 delet_pieces();
 int tx=indx+1;
 int i=0;
 if(dir==0)
 {
 for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(T_ver[y][x]==1)
      {
        if(indx>=8)
       {
           indx=7;
          //cout<<indx<<endl;
       }
       r[i++]=new Rectangle1(((x*40))+(indx*40),y*40,40,40);

      }
     }
 }
 }
 else if(dir==1)
 {
   for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(T_left[y][x]==1)
      {
        if(indx==7){

         //indx=8;
        }

       r[i++]=new Rectangle1((x*40)+(indx*40),y*40,40,40);

      }
     }
 }
} else if(dir==2)
 {
   for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(T_low[y][x]==1)
      {
        if(indx>=8)
       {
           indx=7;
          //cout<<indx<<endl;
       }

       r[i++]=new Rectangle1((x*40)+(indx*40),y*40,40,40);

      }
     }
 }
}else if(dir==3)
 {
   for(int y=0;y<3;y++)
 {
     for(int x=0;x<3;x++)
     {
      if(T_right[y][x]==1)
      {
        if(indx>=8)
       {
           indx=7;
          //cout<<indx<<endl;
       }

       r[i++]=new Rectangle1((x*40)+(indx*40),y*40,40,40);

      }
     }
 }
}


}//
void T_piece::move_pieces_right()
{
 int tx=indx+1;
 if(tx<=7&&(dir==0||dir==2||dir==3))
 {
     indx++;
     for(int i=0;i<4;i++)
     {
     r[i]->x+=40;
     }
 }else if(tx<=8&&dir==1)//horizontal
 {
     indx++;
     for(int i=0;i<4;i++)
     {
     r[i]->x+=40;
     }
 }
}//
T_piece::T_piece()
{
    //ctor

 for(int i=0;i<4;i++)
 {
 r[i]=NULL;
 }

 rotate_piece();

}//
void T_piece::delet_pieces()
{
  for(int i=0;i<4;i++)
 {
  if(r[i]!=NULL)
  {
      //cout<<"delete"<<endl;
      delete r[i];
  }

 }
}
T_piece::~T_piece()
{
    //dtor
    delet_pieces();
}//


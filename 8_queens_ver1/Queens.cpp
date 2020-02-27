#include "Queens.h"

Queens::Queens():
cur_ylevel(0),x_size(8),y_size(8)
{
    //ctor
    for(int y=0;y<y_size;y++)
    {
        for(int x=0;x<x_size;x++)
        {
          chese_board[y][x]=0;
        }
    }
    cur_ylevel=y_size-1;
    chese_board[0][6]=1;
    chese_board[1][4]=2;
    chese_board[2][2]=3;
    chese_board[3][0]=4;
    chese_board[4][5]=5;
    chese_board[5][7]=6;
    chese_board[6][1]=7;
    chese_board[7][3]=8;
    queen=get_queen(cur_ylevel);
    //cout<<chese_board[queen.y][queen.x]<<endl;
    start_sequence();
}

Queens::~Queens()
{
    //dtor
}

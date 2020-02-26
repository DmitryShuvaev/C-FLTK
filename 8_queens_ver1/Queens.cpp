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
    chese_board[0][0]=1;
    chese_board[1][1]=2;
    chese_board[2][2]=3;
    chese_board[3][3]=4;
    chese_board[4][4]=5;
    chese_board[5][5]=6;
    chese_board[6][6]=7;
    chese_board[7][7]=8;
    queen=get_queen(cur_ylevel);
    //cout<<chese_board[queen.y][queen.x]<<endl;
    start_sequence();
}

Queens::~Queens()
{
    //dtor
}

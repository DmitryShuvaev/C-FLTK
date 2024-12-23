#ifndef L_PIECE_H
#define L_PIECE_H
#include "Graph.h"
#include "Board_calc.h"
#include <iostream>
using namespace std;

class L_piece
{
    public:
        L_piece();
        virtual ~L_piece();
     L_piece(Board_calc *bc,Rectangle1*r[4]);
     void add_piece(Board_calc *bc,Rectangle1*r[4]);
     void delet_pieces(Rectangle1*r[4]);
     bool can_add(Board_calc *bc,int xv,int yv);
     bool can_add_dir_0(Board_calc *bc);
     bool can_add_dir_1_2_3(Board_calc *bc,const int (&T_dir)[3][3]);
     void move_left_loop(Rectangle1*r[4]);
     void move_pieces_left(Board_calc *bc,Rectangle1*r[4]);
     void move_pieces_right(Board_calc *bc,Rectangle1*r[4]);
     void move_right_loop(Rectangle1*r[4]);
     bool can_move_left(Board_calc *bc,Rectangle1*r[4]);
     bool can_move_right(Board_calc *bc,Rectangle1*r[4]);
     void move_down(Rectangle1*r[4]);
     /*************/
     void rot_dir_0(Board_calc *bc,Rectangle1*r[4]);
     void rot_dir_1_2_3(Board_calc *bc,Rectangle1*r[4],const int (&L_dir)[3][3]);
    Rectangle1*r[4];
int L_ver[3][3]=//dir=0[y][x]
            {{1,1,0},
             {0,1,0},
             {0,1,0}};
int L_left[3][3]=//dir=1[y][x]
            {{0,0,0},
             {1,1,1},
             {1,0,0}};
int L_low[3][3]=//dir=2[y][x]
            {{0,1,0},
             {0,1,0},
             {0,1,1}};
int L_right[3][3]=//dir=3[y][x]
            {{0,0,1},
             {1,1,1},
             {0,0,0}};
int dir=0;
int indx=4;
int indy=0;
};

#endif // L_PIECE_H

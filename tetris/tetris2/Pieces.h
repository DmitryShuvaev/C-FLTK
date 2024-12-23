#ifndef PIECES_H
#define PIECES_H
#include "Graph.h"
#include "Board_calc.h"
#include <iostream>
using namespace std;

class I_piece
{
     public:
     I_piece();
     I_piece(Board_calc *bc, Rectangle1*r[4]);
     void add_piece(Board_calc *bc,Rectangle1*r[4]);
     void delet_pieces(Rectangle1*r[4]);
     bool can_add(Board_calc *bc,int xv,int yv);
     bool can_add_dir_0(Board_calc *bc);
     ~I_piece();


int I_ver[4][4]=//[y][x]
            {{0,1,0,0},
             {0,1,0,0},
             {0,1,0,0},
             {0,1,0,0}};
int I_hor[4][4]=//[y][x]
            {{0,0,0,0},
             {0,0,0,0},
             {1,1,1,1},
             {0,0,0,0}};
int I_ver_right[4][4]=//[y][x]
            {{0,0,1,0},
             {0,0,1,0},
             {0,0,1,0},
             {0,0,1,0}};
int I_hor_up[4][4]=//[y][x]
            {{0,0,0,0},
             {1,1,1,1},
             {0,0,0,0},
             {0,0,0,0}};
int dir=0;
int indx=3;
int indy=0;
};

#endif // PIECES_H

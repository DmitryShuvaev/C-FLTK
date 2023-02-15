#ifndef PIECES_H
#define PIECES_H
#include "Graph.h"
#include "Board_calc.h"
#include <iostream>
using namespace std;

struct I_piece
{
     I_piece();
     I_piece(Board_calc *bc);
     ~I_piece();
     void draw_piece()
    {
        for(int i=0;i<4;i++)
        {
            //cout<<r[i]<<endl;
            if(r[i]!=0)
            r[i]->draw_rec();
        }

    }
    void rotate_piece(Board_calc *bc);
    void delet_pieces();
    void move_pieces_right(Board_calc *bc);
    void move_pieces_left(Board_calc *bc);
    void move_right_loop();
    void move_left_loop();
    bool can_move_left(Board_calc *bc);
    bool can_move_right(Board_calc *bc);
    bool can_rotate(Board_calc *bc,int xv,int yv);
    bool can_rot_dir_0(Board_calc *bc);
    bool can_rot_dir_1(Board_calc *bc);
    bool can_rot_dir_2(Board_calc *bc);
    bool can_rot_dir_3(Board_calc *bc);
    bool chec_empty_r();
    void move_down();
    Rectangle1*r[4];
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
struct N_piece
{
     N_piece();
     ~N_piece();
     void draw_piece()
    {
        for(int i=0;i<4;i++)
        r[i]->draw_rec();
    }
    void rotate_piece();
    void delet_pieces();
    void move_pieces_right();
    void move_pieces_left();
    void move_right_loop();
    void move_left_loop();
    void print_indxy();
    Rectangle1*r[4];
int N_ver[3][3]=//dir=0
            {{1,0,0},
             {1,1,0},
             {0,1,0}};
int N_hor_low[3][3]=//dir=1[y][x]
            {{0,0,0},
             {0,1,1},
             {1,1,0}};
int N_ver_right[3][3]=//dir=2[y][x]
            {{0,1,0},
             {0,1,1},
             {0,0,1}};
int N_hor[3][3]=//dir=3[y][x]
            {{0,1,1},
             {1,1,0},
             {0,0,0}};


int dir=0;
int indx=0;
};//
struct T_piece
{
     T_piece();
     ~T_piece();
     void draw_piece()
    {
        for(int i=0;i<4;i++)
        r[i]->draw_rec();
    }
    void rotate_piece();
    void delet_pieces();
    void move_pieces_right();
    void move_pieces_left();
    Rectangle1*r[4];
int T_ver[3][3]=//[y][x]
            {{0,1,0},
             {1,1,1},
             {0,0,0}};
int T_left[3][3]=//[y][x]
            {{0,1,0},
             {1,1,0},
             {0,1,0}};
int T_low[3][3]=//[y][x]
            {{0,0,0},
             {1,1,1},
             {0,1,0}};
int T_right[3][3]=//[y][x]
            {{0,1,0},
             {0,1,1},
             {0,1,0}};
int dir=0;
int indx=0;
};
#endif // PIECES_H

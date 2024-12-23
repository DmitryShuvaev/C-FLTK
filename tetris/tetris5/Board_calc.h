#ifndef BOARD_CALC_H
#define BOARD_CALC_H
#include <iostream>
#include "Graph.h"
using namespace std;
class Board_calc
{
    public:
        Board_calc();
        void init();
        virtual ~Board_calc();
        void Board_print();
        void check_col(Rectangle1*r[4]);
        bool colision(int indx,int indy);
        bool check_col_y(Rectangle1*r[4]);
        bool check_same_x_line(const int indexy);
        bool finish_game(Rectangle1*r[4]);
        bool can_add_to_board(Rectangle1*r[4]);
        bool check_level();
        //bool chec_empty_r(Rectangle1*r[4]);
        void shift_y();
        void shift_from_to(int miny,int shift_to);
        void add(Rectangle1*r[4]);
const static int width=10;
const static int height=20;
int board[height][width];//[y][x]
};

#endif // BOARD_CALC_H

#ifndef SNAIL_H
#define SNAIL_H
#include "Graph.h"
#include "Window.h"
#include "Level_Maker.h"
//#include "SnailMovingState.h"
using namespace Graph_lib;
class Snail
{
    public:
        enum Direction{left,right};
        Snail();
//        Snail(Graph_lib::Window *pw):
//         snailWidth(80),
//         snailHight(80),
//         w(pw){}
       void init(Tiles (&a)[9][20]);
       virtual ~Snail();
       static void addSnail(Graph_lib::Window *pw,Snail*s,Tiles (&a)[9][20],int *dxx,Image *caracter,
       bool *main_tim){
        //s->attach_snail(pw,a,dxx);
          s->initSnail(pw,a,dxx,caracter,main_tim);
        }
       void initSnail(Graph_lib::Window *o,Tiles (&a)[9][20],int*dxx,Image *caracter,bool *main_tim){
           add(a);
           dx=dxx;
           player=caracter;
           w=o;
           this->main_tim=main_tim;
       }
       void attach_snail( ){
           w->attach(*snail);
        }
        void detach_snail(){
         w->detach(*snail);
        }
        void move_snail(int dxv);
        void SnailMovingState();
        void add(Tiles (&a)[9][20]);
        void movetiles(int);
        bool colisx_right(int y,int x);
        bool colisx_left(int y,int x);
        bool colisTopSnail();
        bool colisy_left(int y,int x);
        bool colisy_right(int y,int x);
        void animright();
        void animleft();
        void snail_status();
        bool colis_left_cara_snail();
        bool colis_right_cara_snail();
    Image *snails[4];
    Image *snail;//snail linked with snails[1] with pointer
    const int snailWidth;
    const int snailHight;
    const int mapWidth;
    const int mapHeight;
    private:
    Graph_lib::Window *w ;
    //tiles is reference from Mane_window tiles
    Tiles tiles[9][20];
   int cn;
   int *dx;
   Direction movingDirection;
   int timeN;
   Image *player;
   bool islive;
   bool *main_tim;
};

#endif // SNAIL_H

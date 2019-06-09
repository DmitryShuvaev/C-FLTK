#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include "Point.h"
using namespace std;

class Maze
{
    public:
        struct Wall{
         char wal[3];
        };
        //
        struct Cell{
        Wall w[4];
        char leter;
        bool visited;
		Cell():visited(false){}
        void printLeft(){
                for(int i=0;i<1;i++){

                if(w[0].wal[i]!='8'&&w[0].wal[i]!='r')
                cout<<w[0].wal[i]<<leter;
                else if(w[0].wal[i]=='r'){//r means wall removed
                        cout<<' '<<leter;//
                }

        }
        }
        void printTop(){
        for(int i=0;i<sizeof(w[1].wal) / sizeof(w[1].wal[0]);i++){
                if(w[1].wal[i]!='8'&&w[1].wal[i]!='r')//&&w[1].wal[i]!='r'
                cout<<w[1].wal[i];
                else if(w[1].wal[i]=='r') cout<<' ';
        }
        }//
        void printBot(){
        for(int i=0;i<sizeof(w[3].wal) / sizeof(w[3].wal[0]);i++){
                if(w[3].wal[i]!='8'&&w[3].wal[i]!='r')//&&w[3].wal[i]!='r'
                cout<<w[3].wal[i];
               else if(w[3].wal[i]=='r') cout<<' ';
        }
        }//
        void printRight(){
        for(int i=0;i<1;i++){
                //r means wall removed
                if(w[2].wal[i]!='8'&&w[2].wal[i]!='r')
                cout<<w[2].wal[i];
        }
        }

        };
        //
        struct WalsColect{
         int x,y;
         int walIndx;
        };
        Maze();
        void init();
        void print();
        void addWals(int x,int y);
        void remWal(int);
        void makeMove();
        void mazePassage();
        //
void leftPos(int, int);
void rightPos(int,int);
void topPos(int,int);
void botPos(int,int);
void PosiblePos();
    int getRandom(int from, int to){
        int dif = (to+1) - from;
        return from + rand() % dif;
    }
        virtual ~Maze();
     void remeRightWal(const int x,const int y,char el='#'){
        // if (cels[y].size() > 1&&x<cels[y].size()) {
          cels[y][x]->w[2].wal[0]='r';
          if(x!=cels[y].size()-1){
           cels[y][x+1]->w[0].wal[0]='r';
           curx=x+1;cury=y;
           cels[cury][curx]->visited=true;
          }

         //}
     }
    void remeLeftWal(const int x,const int y,char el='#'){
        // if (cels[y].size() > 1&&x<cels[y].size()) {
          cels[y][x]->w[0].wal[0]='r';
          if(x>0){
           cels[y][x-1]->w[2].wal[0]='r';
           curx=x-1;cury=y;
           cels[cury][curx]->visited=true;
          }

        // }
     }
    void remeBotWal(const int x,const int y,char el='#'){
        // if (cels[y].size() > 0&&x<cels[y].size()&&y<cels.size()) {
          cels[y][x]->w[3].wal[1]='r';
          if(y+1<cels.size()){//removing top wall if next cell is exist
          cels[y+1][x]->w[1].wal[1]='r';
          curx=x;cury=y+1;
          cels[cury][curx]->visited=true;
          }
         //}
     }
    void remeTopWal(const int x,const int y,char el='#'){
        // if (cels[y].size() > 0&&x<cels[y].size()&&y<cels.size()) {
          cels[y][x]->w[1].wal[1]='r';//removing top wall
          if(y-1>=0){//removing bot wall if next cell is exist
          cels[y-1][x]->w[3].wal[1]='r';
          curx=x;cury=y-1;
          cels[cury][curx]->visited=true;
          }
         //}
     }
struct mazeSolver{
    bool fvisited;
    bool svisited;
mazeSolver():fvisited(false),svisited(false){}
};
void printmazeSolver(){
        for (int y = 0; y < ms.size(); y++){
            for (int x = 0; x < 8; x++)
                {
                 cout<<ms[y][x]->fvisited;
                }
                 cout<<'\n';
            }
}
struct emptyCell{
int x,y;
emptyCell():x(0),y(0){}
};
struct line{
//    line() :p1(0), p2(0) { }
Point p1;Point p2;
};
void clearCels();
vector<vector<Cell*> >cels;
vector<Wall*>w;
vector<WalsColect*>wc;
vector<emptyCell*>empCels;
Cell *curentCel;
int curx,cury;
vector<vector<mazeSolver*> >ms;
stack<emptyCell> celstack;
//
int countedCels[8][8];
int counter;
vector<line>lines;
void putLine();
void printNumCels();
Point findMin();
void lineCoord();
vector<int>points;
};

#endif // MAZE_H

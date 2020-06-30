#ifndef KNIGHT_H
#define KNIGHT_H
#include <vector>
#include <iostream>
using namespace std;
const int boardSize=5;
struct Knight_pos
{
int x,y,move_direct;
};
class Knight
{
    public:
        Knight();
        virtual ~Knight();
void initial();
void print();
void run();
	Knight_pos jump( Knight_pos knight)
	{
     Knight_pos kn;
     kn=knight;
     switch(M[kn.x][kn.y]){
		case 0:
			kn.x=kn.x-1;
			kn.y=kn.y+2;
			//kn.move_direct=0;
		break;
		case 1:
			kn.x=kn.x-2;
			kn.y=kn.y+1;
			//kn.kn=1;
		break;
		case 2:
			kn.x=kn.x-2;
			kn.y=kn.y-1;
			//kn.move_direct=2;
		break;
		case 3:
			kn.x=kn.x-1;
			kn.y=kn.y-2;
			//kn.move_direct=3;
		break;
		case 4:
			kn.x=kn.x+1;
			kn.y=kn.y-2;
			//kn.move_direct=4;
		break;
		case 5:
			kn.x=kn.x+2;
			kn.y=kn.y-1;
			//kn.move_direct=5;
		break;
		case 6:
			kn.x=kn.x+2;
			kn.y=kn.y+1;
			//kn.move_direct=6;
		break;
		case 7:
			kn.x=kn.x+1;
			kn.y=kn.y+2;
			//kn.move_direct=7;
			break;

		}//end switch
		return kn;
	}//
	bool done()
	{
	    int c=0;
    for(int x=0;x<boardSize;x++)
     {
     for(int y=0;y<boardSize;y++)
     {
        if(G[x][y]>=0)c++;

     }
     }
     if(c==boardSize*boardSize)return true;
     else return false;
	}//
	void step_back()
	{
	   // mn.pop_back();
     //Knight_pos k;
     k=mn.back();
     //M[k.x][k.y]=M[k.x][k.y]+1;
//           G[k.x][k.y]=-1;
//       M[k.x][k.y]=0;
//       s--;
//       mn.pop_back();
     //k=mn.back();
     while(M[k.x][k.y]==7)
     {
      G[k.x][k.y]=-1;
       M[k.x][k.y]=0;
      s--;
       if(mn.size()>0)
       {
        mn.pop_back();
       }else break;

      k=mn.back();
     }
     M[k.x][k.y]=M[k.x][k.y]+1;
//2nd
//     k=mn.back();
//     //k=mn.back();
//     while(M[k.x][k.y]==7)
//     {
//      G[k.x][k.y]=-1;
//       M[k.x][k.y]=0;
//      s--;
//       if(mn.size()>0)
//       {
//        mn.pop_back();
//       }else break;
//
//      k=mn.back();
//     }
//      M[k.x][k.y]=M[k.x][k.y]+1;
	}//
	int s;
	Knight_pos k;
int G[boardSize][boardSize];
int M[boardSize][boardSize];
vector<Knight_pos>mn;
};

#endif // KNIGHT_H

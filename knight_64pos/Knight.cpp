#include "Knight.h"

Knight::Knight()
{
    //ctor
    initial();
    s=0;
    //initial position
    k.x=0;k.y=0;
    //default move direction
    k.move_direct=0;
    mn.push_back(k);
    run();
}//
void Knight::run()
{
bool maxv=false;
    //Knight_pos k;

    //k.x=0;k.y=0;
    //default move direction
//    k.move_direct=0;
//    mn.push_back(k);
 while(!done()){
     if(k.x>=0&&k.x<boardSize&&k.y>=0&&k.y<boardSize&&G[k.x][k.y]==-1)
    {

     mn.push_back(k);
     G[k.x][k.y]=++s;
     //cout<<M[k.x][k.y]<<endl;

    }else
    {
        k=mn.back();
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


//cout<<M[k.x][k.y]<<endl;
    }
    k=jump(k);

//    cout<<k.x<<endl;
//    cout<<k.y<<endl;

 }//end while
//found path copy it
//here code for coping path
    print();
}

Knight::~Knight()
{
    //dtor
}
void Knight::initial()
{
	//initialise
	for(int x=0;x<boardSize;x++)
		for(int y=0;y<boardSize;y++)
        {
        G[x][y]=-1;
        M[x][y]=0;
        }
}
void Knight::print()
{
     for(int x=0;x<boardSize;x++)
     {
     for(int y=0;y<boardSize;y++)
     {
        if(G[x][y]<10)cout<<' ';
         cout<<G[x][y]<<' ';
     }
      cout<<'\n';
     }
        cout<<"_________________\n";
/*
    for(int x=0;x<boardSize;x++)
     {
     for(int y=0;y<boardSize;y++)
     {
        if(M[x][y]<10)cout<<' ';
         cout<<M[x][y]<<' ';
     }
      cout<<'\n';
     }
        cout<<"_________________\n";
        */
}

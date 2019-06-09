#include "Maze.h"

Maze::Maze()
{
  init();
  makeMove();
  mazePassage();
  print();
  printNumCels();
  lineCoord();
}
void Maze::init(){
	for (int y = 0; y < 8; y++) {
     for (int x = 0; x < 8; x++)countedCels[y][x]=0;
	}
   //ctor
    for (int i = 0; i < 8; i++) {
        cels.push_back(vector<Cell*>()); // Add an empty row
        ms.push_back(vector<mazeSolver*>());
    }
            for (int y = 0; y < cels.size(); y++) {
            for (int x = 0; x < 8; x++){
              cels[y].push_back(new Cell); // Add column to all rows
              ms[y].push_back(new mazeSolver);
            }
        }

            for (int y = 0; y < cels.size(); y++) {
            for (int x = 0; x < 8; x++){
                //value
                    cels[y][x]->leter=' ';

                 cels[y][x]->w[0].wal[0]='|';
                 cels[y][x]->w[2].wal[0]='8';//right

                if(x==7){
                 cels[y][x]->w[2].wal[0]='|';
                }

                //end left
                //top
                if(x<7){
                cels[y][x]->w[1].wal[0]='+';
                cels[y][x]->w[1].wal[1]='-';
                cels[y][x]->w[1].wal[2]='8';
                }else {
                 cels[y][x]->w[1].wal[0]='+';
                cels[y][x]->w[1].wal[1]='-';
                cels[y][x]->w[1].wal[2]='+';
                }
                //end top
                //bot
                if(x<7){
                cels[y][x]->w[3].wal[0]='+';
                cels[y][x]->w[3].wal[1]='-';
                cels[y][x]->w[3].wal[2]='8';
                }else {
                 cels[y][x]->w[3].wal[0]='+';
                cels[y][x]->w[3].wal[1]='-';
                cels[y][x]->w[3].wal[2]='+';
                }
            //rigth
            if(x==7)
            cels[y][x]->w[2].wal[0]='|';
            }
            }//end of cels

            //
curx=0;cury=0;
counter=0;
curentCel=cels[cury][curx];
curentCel->visited=true;
//
}//init
void Maze::addWals(int x,int y){
    WalsColect* p = NULL;
    if(x>0&&cels[cury][x-1]->visited==false){//check left cell is not visited
      p=new WalsColect();
      p->y=y;p->x=x;p->walIndx=0;
      wc.push_back(p);
    }
    if(y+1<cels.size()&&cels[y+1][x]->visited==false){//check bot cell if not visited
    p=new WalsColect();
    p->y=y;p->x=x;p->walIndx=3;
    wc.push_back(p);
    }
    if(y>0&&cels[y-1][x]->visited==false){//check top cell if not visited
     p=new WalsColect();
    p->y=y;p->x=x;p->walIndx=1;
    wc.push_back(p);
    }
    if(x+1<cels[y].size()&&cels[y][x+1]->visited==false){
     p=new WalsColect();
    p->y=y;p->x=x;p->walIndx=2;
    wc.push_back(p);
    }

}//addWals
void Maze::remWal(int i){

                    switch(wc[i]->walIndx)
                    {
                    case 0 : remeLeftWal(wc[i]->x,wc[i]->y);
                    wc.erase(wc.begin()+i );

                             break;       // and exits the switch
                    case 1 : remeTopWal(wc[i]->x,wc[i]->y);
                    wc.erase(wc.begin()+i );

                             break;
                    case 2 :remeRightWal(wc[i]->x,wc[i]->y);
                    wc.erase(wc.begin()+i );

                             break;
                    case 3 :remeBotWal(wc[i]->x,wc[i]->y);

                    wc.erase(wc.begin()+i );

                    break;

                    }

}//remWal
void Maze::makeMove(){

int cou=0;
cels[cury][curx]->visited=true;
addWals(curx,cury);
        while(wc.size()>0){

    //pick random wall from list
       int hw=getRandom(0,wc.size()-1);
       remWal(hw);
    for (int i = 0; i < wc.size(); i++){
        delete wc[i];
     }
     wc.clear();

          for (int y = 0; y < cels.size(); y++)
          {
            for (int x = 0; x < cels[y].size(); x++){
             if(cels[y][x]->visited){
               addWals(x,y);
             }
            }
          }//

    }
    //
}
//
void Maze::clearCels(){
for(int i=0;i<empCels.size();i++){
    delete empCels[i];
}
empCels.clear();
}
void Maze::leftPos(int cx,int cy){
    if(cels[cy][cx]->w[0].wal[0]=='r')//
    {
        if(ms[cy][cx-1]->fvisited==false){
        emptyCell *ec=new emptyCell();
        ec->x=cx-1;ec->y=cy;
        empCels.push_back(ec);
    }
    }
}
void Maze::rightPos(int cx,int cy){
    if(cels[cy][cx]->w[2].wal[0]=='r')//
    {
    if(ms[cy][cx+1]->fvisited==false){
    emptyCell *ec=new emptyCell();
    ec->x=cx+1;ec->y=cy;
    empCels.push_back(ec);
    }
    }
}
void Maze::topPos(int cx,int cy){
    if(cels[cy][cx]->w[1].wal[1]=='r')//
    {
    if(ms[cy-1][cx]->fvisited==false){
    emptyCell *ec=new emptyCell();
    ec->x=cx;ec->y=cy-1;
    empCels.push_back(ec);
    }
    }
}
void Maze::botPos(int cx,int cy){
    if(cels[cy][cx]->w[3].wal[1]=='r')//
    {
    if(ms[cy+1][cx]->fvisited==false&&
       ms[cy+1][cx]->svisited==false){
    emptyCell *ec=new emptyCell();
    ec->x=cx;ec->y=cy+1;
    empCels.push_back(ec);
    }
    }
}
void Maze::PosiblePos(){
leftPos(curx,cury);
rightPos(curx,cury);
topPos(curx,cury);
botPos(curx,cury);
}
void Maze::mazePassage(){
emptyCell ec;

leftPos(ec.x,ec.y);
rightPos(ec.x,ec.y);
topPos(ec.x,ec.y);
botPos(ec.x,ec.y);
if(empCels.size()>0){

 celstack.push(ec);
  cels[celstack.top().y][celstack.top().x]->leter='s';//start position
  ms[celstack.top().y][celstack.top().x]->fvisited=true;
  curx=celstack.top().x;cury=celstack.top().y;
  countedCels[cury][curx]=++counter;
}
//
while(true){
    while(empCels.size()>0){
            if(empCels.size()<2){
              curx=empCels[0]->x;
              cury=empCels[0]->y;
              cels[cury][curx]->leter='o';
			  countedCels[cury][curx]=++counter;
              ms[cury][curx]->fvisited=true;
              celstack.push(*empCels[0]);
            }else if(empCels.size()>1){
              int rcv=getRandom(0,empCels.size()-1);
              curx=empCels[rcv]->x;
              cury=empCels[rcv]->y;
              cels[cury][curx]->leter='b';
			  countedCels[cury][curx]=++counter;
              celstack.push(*empCels[rcv]);
              ms[cury][curx]->fvisited=true;
            }
            clearCels();
            //
            PosiblePos();
    }
    if(empCels.size()==0&&celstack.size()>0){
        if(cury==7&&curx==7){
           cels[cury][curx]->leter='f';//finish position
                break;
        }
     cels[cury][curx]->leter='x';
	      counter--;
     countedCels[cury][curx]=-1;
     ms[cury][curx]->svisited=true;
     celstack.pop();
     if(celstack.size()==0||(cury==cels.size()-1&&curx==cels[cury].size()-1))break;
     curx=celstack.top().x;
     cury=celstack.top().y;
     PosiblePos();
     //
    }

}
}
void Maze::print(){
          for (int y = 0; y < cels.size(); y++)
          {
            for (int x = 0; x < cels[y].size(); x++)
            cels[y][x]->printTop();
            cout<<'\n';
            for (int x = 0; x < cels[y].size(); x++){
                cels[y][x]->printLeft();
                cels[y][x]->printRight();
            }
           if(y==cels.size()-1){
                cout<<'\n';
            for (int x = 0; x < cels[y].size(); x++){
             if(y==cels.size()-1) {
               cels[y][x]->printBot();
             }
            }
            }//if
          cout<<'\n';
          }
          cout<<'\n';
}
void Maze::printNumCels(){
 for (int y = 0; y < 8; y++){
    for (int x = 0; x < 8; x++)
    {
     cout<<countedCels[y][x]<<"  ";
    }
     cout<<'\n';
     }
}
Point Maze::findMin(){
    int min=countedCels[0][0];
    Point p;
       p.x=0;
       p.y=0;
  for (int y = 0; y < 8; y++)
 {
    for (int x = 0; x < 8; x++)
    {
     if(countedCels[y][x]>0){
		 if(min==0||min==-1){min=countedCels[y][x];
		   p.x=x;
		   p.y=y;
		 }
      if(countedCels[y][x]<min){
       min=countedCels[y][x];
       p.x=x;
       p.y=y;
      }
     }
    }
 }
countedCels[p.y][p.x]=-1;
return p;
}
void Maze::lineCoord(){
    int v=0;
    int maxsize=0;
  for (int y = 0; y < 8; y++)
 {
    for (int x = 0; x < 8; x++)
    {
        if(countedCels[y][x]>0)
         maxsize++;
    }
 }
 //cout<<"mazsize="<<maxsize<<endl;

while(maxsize>0){
 line lin;
 if(lines.size()==0){
while(v<2){
if(v==0){
lin.p1=findMin();
maxsize--;
}

else if(v==1){
 lin.p2=findMin();
 maxsize--;
 lines.push_back(lin);
}

v++;
}
v=0;
}
 else{
	 int n = lines.size(); 	 
 lin.p1=lines[n - 1].p2;
 lin.p2=findMin();
 maxsize--;
 lines.push_back(lin);
 }
    //maxsize--;
}
 cout<<"mazsize="<<lines.size()<<endl;
  for (int y = 0; y < lines.size(); y++)
 {
     cout<<lines[y].p1.x<<' '<<lines[y].p1.y<<' '<<lines[y].p2.x<<' '<<lines[y].p2.y<<endl;
 }
   for(int i=0;i<points.size();i++)cout<<points[i]<<endl;
}
Maze::~Maze()
{
    //dtor
     for (int i = 0; i < wc.size(); i++){
        delete wc[i];
     }
     wc.clear();
     for(int y=0;y<ms.size();y++)
         for (int i = 0; i < ms[y].size(); i++){
        delete ms[y][i];
     }
     ms.clear();
     for(int y=0;y<cels.size();y++)
         for (int i = 0; i < cels[y].size(); i++){
        delete cels[y][i];
     }
     cels.clear();
}

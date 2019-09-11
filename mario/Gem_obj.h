#ifndef GEM_OBJ_H
#define GEM_OBJ_H
#include "Graph.h"
#include "Window.h"
#include "Level_Maker.h"

using namespace Graph_lib;
class Gem_obj
{
    public:
        Gem_obj();
        void init(Tiles (&a)[9][20]);
    static void addGem(Graph_lib::Window *pw,Gem_obj*s,Tiles (&a)[9][20],int *dxx,Image *caracter,
       int &id)
    {

     s->initGem(pw,a,dxx,caracter,id);
    }
    void initGem(Graph_lib::Window *o,Tiles (&a)[9][20],int*dxx,Image *caracter,int &id)
    {
     gemID=id;
     add(a);
     dx=dxx;
     player=caracter;
     w=o;

     attach_gem();
    }
    void attach_gem( )
    {
     w->attach(*gem);
    }
    void detach_gem(){
     w->detach(*gem);
    }
    void ad_t()
    {
     Fl::add_timeout(0, Timer_move_gem,(void*)this);
    }
    static void Timer_move_gem(void *pw){
    reference_to<Gem_obj>(pw).move_gem_up(pw);

    }
    void move_gem_up(void *pw)
    {
    if(timeN>13)
    {
     Fl::remove_timeout(Timer_move_gem, (void*)this);
    }else
    {
     Fl::repeat_timeout(1.0/30.0, Timer_move_gem, pw);
     gem->move(0, -3);
     timeN++;
    }

    }
    void initial(int xx,int yy);
    void add(Tiles (&a)[9][20]);
    virtual ~Gem_obj();
    Graph_lib::Window *w ;
    Image *gem;
    const int gemWidth;
    const int gemHight;
    const int mapWidth;
    const int mapHeight;
    Tiles tiles[9][20];
    int timeN;
    int *dx;
   Image *player;
   int gemID;
};

#endif // GEM_OBJ_H

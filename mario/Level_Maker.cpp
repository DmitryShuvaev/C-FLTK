#include "Level_Maker.h"

Level_Maker::Level_Maker()
{
    //ctor
    jump_block_id=0;
    Point tile_start_point[10][6];

//    tile_start_point[0].x=0;
//    tile_start_point[0].y=32*5;
    int dx=0;
    int dy=32*5;

    for(int y=0;y<10;y++){

     for(int x=0;x<6;x++){
        if(y==5&&x==0){
//          //dx+=80*5;
        tile_start_point[y][x].x=21*5;
        tile_start_point[y][x].y=353*5;

        }
        else{
        tile_start_point[y][x].x=dx;
        tile_start_point[y][x].y=dy;
        }

        dx+=80*5;

        }
        dx=0;
        dy+=64*5;
    }
    //generate top tiles points
    dy=0;
    dx=0;
    for(int y=0;y<18;y++){

     for(int x=0;x<6;x++){
     top_tile_start_point[y][x].x=dx;
     top_tile_start_point[y][x].y=dy;
     dx+=80*5;
     }
     dx=0;
     dy+=64*5;
    }

    const int mapWidth = 20;
    const int mapHeight = 9;
    Fl_PNG_Image *tile = new Fl_PNG_Image("Resources/tiles.png");
	Fl_Image *t2;
	   // Fl_Image *temp;
    int tiles_width=tile->w()*5;
	int tiles_height=tile->h()*5;
    t2=tile->copy(tiles_width,tiles_height);//highte 20px
    //cout<<tiles_width<<endl;
	const int tile_wid=16*5;//80 width of tile
	const int tile_hit=16*5;//80
	tile_top = new Fl_PNG_Image("Resources/tile_tops.png");
    top_g=tile_top->copy(tile_top->w()*5,tile_top->h()*5);
    int ground_level=5;
    const int randx=to_rand(0,5);//this is x position
    const int randy=to_rand(0,9);
    //if(randx==0&&randy==5)cout<<"y="<<randy<<" x="<<randx<<endl;
    //rand indexes top tiles
    const int randx_top=to_rand(0,5);
    const int randy_top=to_rand(0,17);
    //aray of random x indexes
   bool xindexes[mapWidth];
   for(int i=0;i<mapWidth;i++)
   {

     int random_xindex=to_rand(0,8);//chance to generate a pillar
        if(random_xindex==1)
        {
         xindexes[i]=true;
        }else xindexes[i]=false;
        if(i==1)xindexes[i]=false;
   }//end for

	for(int y=0;y<mapHeight;y++)
	{
		int yw=y*80;
		for(int x=0;x<mapWidth;x++)
		{
		   int xw=x*80;
		   tiles[y][x].id=0;

		   if(y>2){
             if(xindexes[x])ground_level=2;else ground_level=5;

            //cout<<random_xindex<<endl;
           // if(x==5||(x==10))ground_level=2;else ground_level=5;//x=5 and x==10
		   }

		   if(y>ground_level&&x!=2)
		   {
		   tiles[y][x].tile=new Image(Point(0,0),"Resources/tiles1.png");
		   *tiles[y][x].tile=t2;

		   tiles[y][x].tile->set_mask(Point(tile_start_point[randy][randx].x,tile_start_point[randy][randx].y),tile_wid,tile_hit);
		   tiles[y][x].id=1;
//		   tiles[y][x].id2=0;
		   tiles[y][x].tile->move(xw,yw);
		   if(y==ground_level+1)
            load_top_tiles(xw,yw,randx_top,randy_top);//index n 5 will be last in x 17 last element y
		   }

		}
	}
           //tiles[1][3].tile=new Image(Point(0,0),"Resources/tiles1.png");
           Fl_PNG_Image *tile3 = new Fl_PNG_Image("Resources/tiles1.png");
//	       Fl_Image *t3;
//	       t3=tile3->copy(32*5,16*5);
//           tiles[5][6].tile=new Image(Point(0,0),"Resources/tiles1.png");
//		   *tiles[5][6].tile=t3;
//		   tiles[5][6].id=1;
//		   tiles[5][6].tile->move(6*80,5*80);
           load_jump_boxes();
	delete tile;
	delete tile3;
    delete tile_top;

}
//------------------------------------------------------------------------------
void Level_Maker::load_top_tiles(int dx,int dy,int randx,int randy){
    static int i=0;
    top_tiles[i].tile=new Image(Point(0,0),"Resources/tiles1.png");
    *top_tiles[i].tile=top_g;
    top_tiles[i].tile->set_mask(Point(top_tile_start_point[randy][randx].x,top_tile_start_point[randy][randx].y),16*5,8*5);
    top_tiles[i].id=1;
    top_tiles[i].tile->move(dx,dy);

        //if(top_tiles[0].id==1) attach(*top_tiles[0].tile);
    i++;
}

void Level_Maker::load_jump_boxes()
{

    int dx=0;
    int dy=0;

    for(int y=0;y<5;y++){

     for(int x=0;x<6;x++){

        tile_p[y][x].x=dx;
        tile_p[y][x].y=dy;

        dx+=16*5;

        }
        dx=0;
        dy+=16*5;
    }
 int movex=0;int movey=0;//posit gem

 int x=0;int y=0;
 Fl_PNG_Image *tile = new Fl_PNG_Image("Resources/jump_blocks.png");

 int tiles_width=tile->w()*5;
 int tiles_height=tile->h()*5;
 temp1=tile->copy(tiles_width,tiles_height);
 x=3;y=1;
init_jump_boxes(3,1);
init_jump_boxes(8,1);

 //jump box with position y=5,x=15;
 tiles[3][15].tile=new Image(Point(0,0),"Resources/jump_blocks.png");
 *tiles[3][15].tile=temp1;
 tiles[3][15].id=1;
 //tiles[3][15].is_gem=false;
 tiles[3][15].tile->set_mask(Point(0,0),16*5,16*5);
 movex=15*80;
 movey=3*80;
 tiles[3][15].tile->move(movex,movey);
  //jump box with position y=2,x=16;
 tiles[2][16].tile=new Image(Point(0,0),"Resources/jump_blocks.png");
 *tiles[2][16].tile=temp1;
 tiles[2][16].id=1;
 //tiles[3][15].is_gem=false;
 tiles[2][16].tile->set_mask(Point(0,0),16*5,16*5);
 movex=16*80;
 movey=2*80;
 tiles[2][16].tile->move(movex,movey);
 delete tile;
}
void Level_Maker:: init_jump_boxes(int xi,int yi)
{
int movex=0;int movey=0;//posit gem
 //x can be random value from 0 to 5 and 5 also in index position
const int randx_=to_rand(0,5);//random texture values for x
const int randy_=to_rand(0,4);//random texture value for y
tiles[yi][xi].tile=new Image(Point(0,0),"Resources/jump_blocks.png");
*tiles[yi][xi].tile=temp1;
tiles[yi][xi].id=1;
const int tile_wid=16*5;//80 width of tile
const int tile_hit=16*5;//80
tiles[yi][xi].tile->set_mask(Point(tile_p[randy_][randx_].x,tile_p[randy_][randx_].y),tile_wid,tile_hit);
 movex=xi*80;
 movey=yi*80;
 tiles[yi][xi].tile->move(movex,movey);
//here adding gem and increment jump_block_id wich will be need for Gem_obj array index
tiles[yi][xi].jump_block.gem_in=true;
tiles[yi][xi].jump_block.id=jump_block_id++;
}
Level_Maker::~Level_Maker()
{
    //dtor
//        const int mapWidth = 20;
//    const int mapHeight = 9;
//    for(int y=0;y<mapHeight;y++)
//		{
//          for(int x=0;x<mapWidth;x++)
//		{
//		    if(tiles[y][x].tile)
//		    delete tiles[y][x].tile;
//		}
//		}
}

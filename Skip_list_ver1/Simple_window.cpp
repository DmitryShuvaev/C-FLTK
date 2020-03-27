
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/fl_utf8.h>
//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    search_button(Point(x_max()-74,4), 70, 20, "Search", cb_search),
    in(Point(600,4), 70, 20, "input")
{
  //
zerol=ZEROY;
zerox=BORDER;
attach(search_button);
attach(in);

show();
}//
//------------------------------------------------------------------------------

void Simple_window::cb_search(Graph_lib::Address, Graph_lib::Address pw)
{
    Simple_window *w = (Simple_window*)pw;//get data from input box
    Graph_lib::reference_to<Simple_window>(pw).findv(w->in.get_int());
}//
void Simple_window::clear_arows()
{
 zerol=ZEROY;
 zerox=BORDER;
 int sz=arrows.size();
 for(int v=0;v<sz;v++){
    for(int i=0;i<3;i++)
    {
     detach(*arrows[v].arrow[i]);
    }
    arrows[v].remove_arrow();
 }
 arrows.clear();
 int csize=cels.size();
 for(int i=0;i<csize;i++)
 {
    cels[i]->set_fill_color((Fl_Color)10);
 }
}
void Simple_window::findv(int v)
{
   //cout<<v<<end;
clear_arows();
cout<<"s["<<v<<"]="<<search_data(v)->data;
//cell found set color to it to red
for(int i=0;i<txtd.size()&&i<cels.size();i++)
{
    if(txtd[i]==v)cels[i]->set_fill_color(Color::red);
}
//draw arrow
int sz=arrows.size();
for(int v=0;v<sz;v++)
    for(int i=0;i<3;i++)
    {
     attach(*arrows[v].arrow[i]);
    }
//remove_graphic();
    redraw();
}
void Simple_window::draw_list(vector<Point>p,vector<int>txtdata)
{
vector<Point>ps;
ps=p;
txtd=txtdata;
for(int i=0;i<ps.size();i++){
//cout<<ps[i].y<<endl;
    cels.push_back(new Graph_lib::Rectangle(ps[i],BOXSIZE,BOXSIZE));
    cels[i]->set_fill_color((Fl_Color)10);
    attach(*cels[i]);

}
//draw text
for(int i=0;i<txtdata.size();i++)
{
 textn.push_back(new Graph_lib::Text(
 Point(ps[i].x+BOXSIZE/2-4,ps[i].y+BOXSIZE/2+4),toString(txtdata[i])));
 textn[i]->set_fill_color(FL_BLACK);
 attach(*textn[i]);
}
//p.clear();
//
redraw();
}//
void Simple_window::r_arrow(int x,int y)
{

arrows.push_back(Arrow(Arrow::right,x,y));

}
//------------------------------------------------------------------------------
void Simple_window::l_arrow(int x,int y)
{

arrows.push_back(Arrow(Arrow::low,x,y));
}//
void Simple_window::add(Skip_list*l)
{
 slist=l;
}
void Simple_window::remove_graphic()
{
    //clear_arows();
 for(int i=0;i<cels.size();i++)
 {
    detach(*cels[i]);
    detach(*textn[i]);
 }
 cels.clear();
 textn.clear();
 //slist->display(slist->head);
 //slist->clear_skip_list();
}
//------------------------------------------------------------------------------
Node* Simple_window::search_data(int data)
{
    Node*cur=slist->head;
    int cur_size=slist->level_size(cur);
    Node*curi=slist->get_node(cur,cur_size-1);
    zerol=zerol-(BOXSIZE*(cur_size-1));
    if(cur_size==1){

     while(curi->next!=NULL&&cur_size==1&&curi->next->data<=data){curi=curi->next;
      cur_size=slist->level_size(curi);
      curi=slist->get_node(curi,cur_size-1);
      zerox=zerox+BOXSIZE;
      zerol=(416-52)-(BOXSIZE*(cur_size-1));
     }
    }

    if(slist->head!=slist->tail)
    while(data>curi->data&&curi->down!=NULL&&curi!=slist->tail)
    {
        while(curi->next==NULL&&curi->down!=NULL)
        {
         curi=curi->down;
         cout<<"next==NULL go->down"<<curi->down<<endl;
         l_arrow(zerox+BOXSIZE/2,zerol+BOXSIZE/2);
         zerol=zerol+BOXSIZE;

        }

        while(curi->next!=NULL&&curi->next->data>=data&&curi->down!=NULL){curi=curi->down;
        cout<<"data1go down="<<curi->data<<endl;
        l_arrow(zerox+BOXSIZE/2,zerol+BOXSIZE/2);
        zerol=zerol+BOXSIZE;

        }

        while(curi->next!=NULL&&curi->next->data<data){
        cout<<"data2go next="<<curi->data<<endl;
               Node*temp=curi;//this only need to skip spaces in graphic window
                curi=curi->next;
                r_arrow(zerox+BOXSIZE/2,zerol+BOXSIZE/2);
                ;
                temp=slist->zero_level(temp);
                while(temp->data<curi->data){
                        zerox=zerox+BOXSIZE;
                        temp=temp->next;
                temp=slist->zero_level(temp);
                }
                //r_arrow(zerox,zerol);//this prints right arrow in widget window
                if(curi->next==NULL){
                    Node*temp=curi;temp=slist->zero_level(temp);
                    if(temp==slist->tail) return slist->tail;
                }
        }
        if(curi->next!=NULL){
         Node*temp=curi->next;temp=slist->zero_level(temp);
         if(data>=temp->data&&temp==slist->tail){
            curi=temp;
             break;
         }
        if(curi->down==NULL)
        cout<<"zero level="<<curi->data<<endl;
        //
        if(curi->next->data==data&&curi->down==NULL)
        {
        cout<<"found="<<curi->next->data<<endl;

        //zerox=zerox+BOXSIZE;
        r_arrow(zerox+BOXSIZE/2,zerol+BOXSIZE/2);
         return curi->next;
        }
}//END IF

    }//end while
    if(curi!=NULL){
     //cout<<" v data="<<curi->data<<endl;
     //if(curi==head) cout<<"head v data="<<curi->data<<endl;
    }
    curi=slist->zero_level(curi);
    return curi;
}//end search














#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include "Point.h"
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node*next;
    Node*prev;
    Node*high;
    Node*down;
};

class Skip_list
{
    public:
        Skip_list();
    void insert_end(Node**head,int newdata)
        {
            Node*newNode=new Node;
            Node*last=*head;
            newNode->data=newdata;
            newNode->next=NULL;
            newNode->high=NULL;
            if(*head==NULL)
            {
                newNode->down=NULL;
                *head=newNode;
               // tail=*head;
                return;
            }
            while(last->high!=NULL)//this will print from last to first node
            {
                last=last->high;
            }
            last->high=newNode;
            newNode->down=last;

        }
void create_level(Node**h,int newdata,int height)
{
 int i=0;
 Node*last=*h;
 if(*h==NULL)
 {
     while(i++<height)
     {
      insert_end(h,newdata);

     }
     tail=*h;
     return;
 }else
 {
// while(last->next!=NULL)//here need to connect all the levels
// {
//     last=last->next;
// }
 Node*newnode=NULL;
 //i=0;
 while(i++<height)
 insert_end(&newnode,newdata);
 if(*h==tail)
 {

    //cout<<"head==tail"<<(*(*h)).data<<endl;
     if(tail->data>newdata)//insert front
     {
      connect_front(*h,newnode);
     }else
     {
      connect_end(tail,newnode);
     }
 }else
 {
   //cout<<head->data;
  Node*temp=search_data(newdata);
  //cout<<"search p="<<temp->data<<'\n';
  //cout<<"last="<<tail->data<<'\n';
  //here connect high nodes with new nodes
  if(temp==tail)
  connect_end(tail,newnode);
  else if(temp==head)
  {
      //cout<<"front\n";
      if(head->data>newdata)//front ins
      connect_front(head,newnode);
      else
      {
        Node*sc=temp->next;
        Node*lastn=tail;
        Node*h=head;
        connect_end(temp,newnode);
        connect_front(sc,newnode);
//cout<<"lastn="<<lastn->data<<endl;
        tail=lastn;
        head=h;
      }
     //if(head->data>data)//front ins
  }else
  {
      //cout<<"middle="<<temp->data<<"\n";
    Node*sc=temp->next;
    Node*lastn=tail;
    Node*h=head;
    connect_end(temp,newnode);
    connect_front(sc,newnode);
    tail=lastn;
    head=h;
  }



// tail=newnode;
 //connect_front(*head,newnode);
 //*head=newnode;

 //cout<<"\ntail="<<tail->data<<"\n";
 }
 }
}//
void display(Node*node)
{
    Node*last;
    Node*cur=node;
    Node *top=cur;
    while(cur!=NULL){
        while(top!=NULL)
        {
            if(top->high!=NULL)
            cout <<top->data<<"<<==>>";
            last=top;
            top=top->high;
        }
        cout<<last->data<<"\n";
        cur=cur->next;
        top=cur;

    }

}//
int level_size(Node*node)
{
    int index=0;
    while(node!=NULL)
    {
        index++;
        node=node->high;
    }
    return index;
}//
Node* get_node(Node *curNode,int i)
{
    Node*last=curNode;
    int indx=0;
    while(indx<i)
    {

      indx++;
      //if(last->high!=NULL)
      last=last->high;
    }
    return last;
}//get node from i position of the hight
void connect_end(Node*last,Node*newn)//connect tail node with new nodes
{
    int new_node_l_size=level_size(newn);
    Node*cur=last;
    Node*newi=newn;
    Node*lasti=last;
    int lsize;
    //cout<<l_size;
    for(int i=0;i<new_node_l_size;i++)
    {
      lsize=level_size(lasti);
      newi=get_node(newn,i);
        if(i<lsize)
        {
            cur=get_node(lasti,i);
            cur->next=newi;
            newi->prev=cur;
        }else
        {
//
            while(i>=lsize&&lasti->prev!=NULL){
              lasti=lasti->prev;
              lsize=level_size(lasti);
            }

                if(i<lsize)
                {
                    cur=get_node(lasti,i);
                    cur->next=newi;
                    newi->prev=cur;
                }

        }
    }
tail=newn;
}//
void connect_front(Node*first,Node*newn)
{
 int new_node_l_size=level_size(newn);
 Node*cur=first;
 Node*newi=newn;
 Node*headi=first;
 int lsize;
 for(int i=0;i<new_node_l_size;i++)
 {
  lsize=level_size(headi);
  newi=get_node(newn,i);
  if(i<lsize)
  {
      cur=get_node(headi,i);
      cur->prev=newi;
      newi->next=cur;
      //cout<<"cf"<<lsize;
  }else
  {
    while(i>=lsize&&headi->next!=NULL)
    {
        headi=headi->next;
        lsize=level_size(headi);
    }
    if(i<lsize)
    {
        cur=get_node(headi,i);
        cur->prev=newi;
        newi->next=cur;
    }
  }
 }
 head=newn;
}//

Node*zero_level(Node*n)
{
if(n==NULL)return n;
while(n->down!=NULL)n=n->down;
    return n;
}
Node* search_data(int data)
{
    Node*cur=head;
    int cur_size=level_size(cur);
    Node*curi=get_node(cur,cur_size-1);
    if(cur_size==1){

     while(curi->next!=NULL&&cur_size==1&&curi->next->data<=data){curi=curi->next;
      //cout<<"cuda="<<curi->data;
      cur_size=level_size(curi);
      curi=get_node(curi,cur_size-1);
     }
    }

    //cout<<"search data="<<curi->data<<endl;
    if(head!=tail)
    while(data>curi->data&&curi->down!=NULL&&curi!=tail)
    {
        while(curi->next==NULL&&curi->down!=NULL)
        {
         curi=curi->down;
         cout<<"next==NULL go->down"<<curi->down<<endl;
        }

        while(curi->next!=NULL&&curi->next->data>=data&&curi->down!=NULL){curi=curi->down;
        cout<<"data1go down="<<curi->data<<endl;
        }

        while(curi->next!=NULL&&curi->next->data<data){
        cout<<"data2go next="<<curi->data<<endl;
                curi=curi->next;
                if(curi->next==NULL){
                    Node*temp=curi;temp=zero_level(temp);
                    if(temp==tail) return tail;

//return tail;
                }
//if(curi->data==data)return tail;

        }
        //cout<<"exit"<<endl;
if(curi->next!=NULL){
        Node*temp=curi->next;temp=zero_level(temp);
         if(data>=temp->data&&temp==tail){
            curi=temp;
            //cout<<"tail"<<endl;
             break;
         }
        if(curi->down==NULL)
        //cout<<"zero level="<<curi->data<<endl;
        //
        if(curi->next->data==data&&curi->down==NULL)
        {
        //cout<<"found="<<curi->next->data<<endl;
        return curi->next;
        }
}//END IF

//curi=zero_level(curi);
//cout<<"e";


    }//end while

//curi=zero_level(curi);
if(curi!=NULL){
 //cout<<" v data="<<curi->data<<endl;
 //if(curi==head) cout<<"head v data="<<curi->data<<endl;
}

curi=zero_level(curi);
return curi;
}//end search
void delet_node(int data)
{
    Node*temp=search_data(data);
    Node*h=temp;
    Node*cur=temp;
    if(temp!=NULL)
    {
     if(temp==head)
     {
         //cout<<"tempddata="<<temp->data;
         if(h->next!=NULL)head=head->next;
         while(h!=NULL)
         {
            cur=h;
             if(cur->next!=NULL)
             {
                 cur=cur->next;
                 cur->prev=NULL;
                 h->next=NULL;
                 cur=h;
                 h=h->high;
                 delete cur;
             }else
             {
              h=h->high;
              delete cur;
              //cout<<"cdata2="<<cur->data<<endl;
             }

     }
    }//
    else if(temp==tail)
    {
     Node*p=temp->prev;
     Node*cur=temp;
     tail=p;
     while(cur!=NULL)
     {
      p=temp->prev;
      p->next=NULL;
      temp->prev=NULL;
      cur=cur->high;
      delete temp;
      temp=cur;
     }//end while
     //cout<<"temp==tail"<<endl;
    }else//here remove node in middle
    {
        Node*p=temp->prev;
        Node*s=temp->next;
        //Node*cur=temp;
        while(cur!=NULL)
        {
             p=temp->prev;
             s=temp->next;
             p->next=s;
             s->prev=p;
            cur=cur->high;
            if(temp!=NULL)
            {
            //cout<<"delete"<<endl;
            free(temp);
            temp=NULL;
            }
            //cout<<"tempdata="<<temp->data<<endl;
            temp=cur;
        }
    }
    };
    //while()
}
        virtual ~Skip_list();
//------------------------------------------------------------------------------
inline int to_rand(int from,int to)
{
    int dif=(to+1)-from;
    return from+rand()%dif;
}//
void clear_skip_list();

vector<Point> add_points(vector<int>*bdata);
vector<Point> add_text();

Node*head;
Node*tail;

};

#endif // SKIP_LIST_H

#include "Skip_list.h"

Skip_list::Skip_list():head(NULL),tail(NULL)
{
    //ctor
//    head=NULL;
//    tail=NULL;

    create_level(&head,2,to_rand(1,5));
//    //create_level(&head,3,3);
//    //Node*sn=search_data(2);
    create_level(&head,4,to_rand(1,5));
    create_level(&head,5,to_rand(1,5));
    create_level(&head,8,to_rand(1,5));
    create_level(&head,3,to_rand(1,5));
    create_level(&head,6,to_rand(1,5));
    create_level(&head,1,to_rand(1,5));
    create_level(&head,12,to_rand(1,5));
    create_level(&head,14,to_rand(1,5));
    create_level(&head,13,to_rand(1,5));
    create_level(&head,16,to_rand(1,5));
    create_level(&head,15,to_rand(1,5));
    create_level(&head,7,to_rand(1,5));
    create_level(&head,17,to_rand(1,5));
    //display(head);
    //delet_node(3);
    //cout<<"level size="<<level_size(head)<<endl;
//    int lsize=level_size(tail);
//    for(int i=0;i<lsize;i++)
//    {
//     Node*nd=get_node(tail,i);//1 is second element here
//     cout<<"nod["<<i<<"]="<<nd->data<<endl;
//    }
//      Node*nd=get_node(head,0);//1 is second element here
//      //nd=nd->next;
////////      //if(nd==NULL)cout<<"NULL";
////      nd=nd->next;
////      nd=nd->next;
////      nd=nd->next;
////      //nd=nd->prev;
//      cout<<"nod["<<1<<"]="<<nd->data<<endl;
//
////     if(tail !=NULL)
////     cout<<"tail data="<<head->data;;
//
//       //create_level(&head,13,2);
       int d=8;
       Node*sn=search_data(d);//works only from min to max
       cout<<"search=["<<d<<"]"<<sn->data<<'\n';
       display(head);
       //add_points();
}

Skip_list::~Skip_list()
{
    //dtor
   clear_skip_list();
    cout<<"destructor"<<endl;
}//
vector<Point>Skip_list:: add_points(vector<int>*bdata)
{
    vector<Point>points;

    Node*last;
    Node*cur=head;
    Node *top=cur;
    Point p;
    int x=4,zy=7*52-4;
    int curz=zy;
    while(cur!=NULL){
            //points.push_back(p);
        while(top!=NULL)
        {
            //if(top->high!=NULL)
            //cout <<top->data<<"<<==>>";
            last=top;
            p.x=x;p.y=curz;
           points.push_back(p);
           bdata->push_back(top->data);
            top=top->high;
           curz=curz-52;
        }
        //cout<<last->data<<"\n";
        //points.push_back(p);
       curz=zy;
       x=x+52;
        cur=cur->next;
        top=cur;

    }

 return   points;
}//
void Skip_list::clear_skip_list()
{
    Node*last;
    Node*cur=head;
    Node *top=cur;
    while(cur!=NULL){
        while(top!=NULL)
        {
            if(top->high!=NULL)
            //cout <<top->data<<"<<==>>";
            last=top;

            top=top->high;
            delete last;
        }
        //cout<<last->data<<"\n";
        delete last;
        cur=cur->next;
        top=cur;

    }
}

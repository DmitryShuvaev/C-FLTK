#include "Window.h"



Window::~Window()
{
if(b!=NULL)
{
 delete [] b;  // When done, free memory pointed to by b.
 b = NULL;     // Clear b to prevent using invalid memory reference.
 cout<<"b_removed"<<endl;
}

}
Window::Window(int width, int height, char* title)
         : Fl_Window(width, height, title)

{
  /* initialize random seed: */
  srand (time(NULL));
 fnames[0]="chery.png";
 fnames[1]="7.png";
 fnames[2]="lemon.png";
 fnames[3]="watermelon.png";
 fnames[4]="bell.png";
 fnames[5]="grape.png";
 int i = rand() % 6;
 //cout<<i<<endl;
  //
  pack=new Fl_Pack(2,2,width-2,height-2);

  pack->type(Fl_Pack::HORIZONTAL);

  //b= new Boxes[1];
  resizeAr(b);
  //resizeAr(b);
  //resizeAr(b);
  cout<<size<<endl;
  b[size-1].box=new Box(0,0,200,pack->h(),fnames[i]);
  //cout<<"b[0]created"<<endl;
//  Fl::release_widget_pointer(b[0].b);
  //b[0].b->hide();
  //b[0].b=NULL;
//  delete b[0].b;
//  b[0].b=NULL;
  resizeAr(b);
  cout<<size<<endl;
  i = rand() % 6;
  b[size-1].box=new Box(0,0,200,pack->h(),fnames[i]);

  resizeAr(b);
  cout<<size<<endl;
  i = rand() % 6;
  b[size-1].box=new Box(0,0,200,pack->h(),fnames[i]);
//cout<<size<<endl;
button = new Fl_Button(0, 0, 50, h(), "Pull");
button->callback(butn_calb,this);
Fl::scheme("plastic");
//rand_images();
}
Window::Window(int x,int y,int width, int height, char* title)
         : Fl_Window(x,y,width, height, title)
{

}
int Window::handle_key(int event, int key) {
        switch ( key )
        {
            case  FL_Enter:
                Button_Callback(button);
                    damage(1);
                    return 1;
            default:  label ("Exit!");
                    damage(1);
                    printf("exit\n");
                    this->~Window();
                    exit(0);
                    return 1;
        }

}
int Window::handle(int event)
{
    switch (event) {
     case FL_KEYBOARD:  return handle_key(event,Fl::event_key());
      default:
      return Fl_Window::handle(event);
        };

}
void Window::rand_images()
{
         int a = rand() % 6;
         int i = rand() % 6;
         int c = rand() % 6;

         b[0].box->set_image(fnames[a]);

         b[1].box->set_image(fnames[i]);

         b[2].box->set_image(fnames[c]);
         redraw();
         if(a==i&&a==c)
         fl_message("You win!");
}
void Window::resizeAr(Boxes*&ar)
{
    Boxes *resize = new Boxes[size+1];
    for(int i = 0; i < size; i++)
    {
     if(ar[i].box!=NULL)
     {
     resize[i].box=new Box(0,0,200,pack->h(),(ar[i].box->file_name));
     }

    }
    if(ar!=NULL)
    delete[] ar;
    ar = resize;

    size+=1;
//cout << size<<endl;
}

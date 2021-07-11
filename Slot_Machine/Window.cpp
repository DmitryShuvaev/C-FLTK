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
 cout<<i<<endl;
  //
  pack=new Fl_Pack(2,2,width-2,height-2);

  pack->type(Fl_Pack::HORIZONTAL);

  b= new Boxes[3];
  //resizeAr(b);
  //resizeAr(b);
  b[0].b=new Box(0,0,200,pack->h(),fnames[i]);

//  Fl::release_widget_pointer(b[0].b);
  //b[0].b->hide();
  //b[0].b=NULL;
//  delete b[0].b;
//  b[0].b=NULL;
  //resizeAr(b);
  i = rand() % 6;
  b[1].b=new Box(0,0,200,pack->h(),fnames[i]);

  //resizeAr(b);
  i = rand() % 6;
  b[2].b=new Box(0,0,200,pack->h(),fnames[i]);

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

         b[0].b->set_image(fnames[a]);

         b[1].b->set_image(fnames[i]);

         b[2].b->set_image(fnames[c]);
         redraw();
         if(a==i&&a==c)
         fl_message("You win!");
}
void Window::resizeAr(Boxes*&ar)
{
    Boxes *resize = new Boxes[size+1];
    //if(ar!=NULL)
    for(int i = 0; i < size; i++)
    {
     if(ar[i].b!=NULL)
     {
     resize[i] = ar[i];
     //resize[i].b = ar[i].b;
     //ar[i].b->hide();
     //
     //delete ar[i].b;
     ar[i].b=NULL;
     }

    }
    //if(ar!=NULL)
    delete[] ar;

    ar=NULL;
    //if(ar!=NULL)

    ar = resize;

    size+=1;
cout << size<<endl;
}

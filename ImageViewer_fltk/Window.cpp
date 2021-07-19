#include "Window.h"
Window::~Window()
{
    //dtor
    delete picbox;
    delete lbut;
    delete rbut;
    if(img!=NULL)
    {
        delete img;
    }

}
Window::Window(int width, int height, char* title)
         : Fl_Window(width, height, title)

{

}
Window::Window(int x,int y,int width, int height, char* title)
         : Fl_Window(x,y,width, height, title)
{
 d="";
   //SetConsoleOutputCP (1251);
   //SetConsoleCP(1251);
system("chcp 65001  > nul");

 lbut=new Button(0, 0, 50, 300, "@<");
 lbut->n=-1;
 lbut->callback(butn_calb,this);
 lbut->tooltip("Middle click to select new directory");
 lbut->shortcut(FL_ALT|FL_Left);
 //
 picbox = new Fl_Box (50, 0, 700, 300);

 rbut = new Button(50+700, 0, 50, 300, "@>");
 rbut->n=1;

 rbut->callback(butn_calb,this);
 rbut->tooltip("нажми среднюю кнопку мыши выбрать новую директорию");
 rbut->shortcut(FL_ALT|FL_Right);
 //
 //Fl::e_keysym = FL_Left;
 resizable(picbox);
 Fl::scheme("plastic");
 char*val=NULL;
 val=fl_dir_chooser("Pick a directory","");

 if(val==NULL)
 {
    fl_alert("cancel");
    return ;
 }
 else
 {
    d=val;
    //fl_message(val);
    files=get_all_files_names_within_folder(d);
 }
if(files.size()==0)
{
    fl_alert("нет фото в директории");
    return;
}
    string fname=files[0];
    char* name= ToStr(fname);
if(lastN(fname)==".png")
{
    Fl_PNG_Image  *png=new Fl_PNG_Image(name);
    // Error checking
    switch ( png->fail() )
    {
        case Fl_Image::ERR_NO_IMAGE:
        case Fl_Image::ERR_FILE_ACCESS:
            fl_alert("%s: %s", val, strerror(errno));// shows actual os error to user
            return ;
        case Fl_Image::ERR_FORMAT:
            fl_alert("%s: couldn't decode image", val);
            return ;
    }
          int pw=png->w();
          int ph=png->h();
          cout<<"pw="<<pw<<" ph="<<ph<<endl;
          float ar=(float)pw/(float)ph;
          if(ph>1000)
          {
              ph=800;
              pw=ar*ph;
          }

          int buth=ph;
          int ww=pw+(2*50);
          pw*=1;
          //if(ar!=0)//if int ar==0 error devision
           buth=pw/ar;
           //cout<<buth<<endl;
           resize(this->Fl_Window::x(),this->Fl_Window::y(),ww,buth);
           //
           img = png->copy(pw, buth);
           delete png;
           picbox->image(img);
           redraw();
}
else if(lastN(fname)==".jpg")
{

           Fl_JPEG_Image  *jpg=new Fl_JPEG_Image(name);
          int pw=jpg->w();//
          int ph=jpg->h();//
          float ar=(float)pw/(float)ph;
          //cout<<ar<<endl;
          if(ph>1000)
          {
              ph=800;
              pw=ar*ph;
          }
          int buth=ph;
          int ww=pw+(2*50);
           buth=pw/ar;

           resize(this->Fl_Window::x(),this->Fl_Window::y(),ww,buth);
           //
           img = jpg->copy(pw, buth);
           delete jpg;
           picbox->image(img);
           redraw();
}
}//END constr

int Window::handle(int event)
{
    switch (event)
    {
      case FL_SHORTCUT:
      case FL_KEYDOWN:
          if(Fl::event_key()==FL_Left)
          {
             lbut->take_focus();
             lbut->value(1);
             lbut->do_callback();
          }
         else if(Fl::event_key()==FL_Right)
          {
             rbut->take_focus();
             rbut->value(1);
             rbut->do_callback();

          }
        else if(Fl::event_key()==FL_Escape)exit(0);
          return 1;
      case FL_KEYUP:
         if(Fl::event_key()==FL_Left)
          {
            lbut->value(0);

          }
        else if(Fl::event_key()==FL_Right)
          {
             rbut->value(0);

          }
            return 1;
      default:
      return Fl_Window::handle(event);
    }
}

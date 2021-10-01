#include "MainWindow.h"

MainWindow::MainWindow(int w, int h, const char* title):Fl_Window(w,h,title)
{

   begin();
      copy = new Fl_Button( 10, 150, 70, 30, "C&alcul");
      copy->callback( but_cb, this );

      quit = new Fl_Button(100, 150, 70, 30, "&Quit");
      quit->callback(cb_quit, this);

      inp = new Fl_Input(50, 50, 500, 30, "Input:");
      inp->value("3+2*8");
      out = new Fl_Output(50, 100, 140, 30, "Output:");
      materialchoice=new Fl_Choice(60,10,120,25,"Material");
      materialchoice->add("Aluminum soft materials");
      materialchoice->add("Aluminum medium materials");
      materialchoice->add("Steel hard materials");
      materialchoice->value(0);//set default celected first
      //
      radiuschoice=new Fl_Choice(230,10,120,25,"Radius");
      radiuschoice->add("Air bending 0 to thikness");
      radiuschoice->add("Air bending thickness to 3x thickness");
      radiuschoice->add("Air bending greater than 3x thickness");
      radiuschoice->add("Bottoming 0 to thikness");
      radiuschoice->add("Bottoming thickness to 3x thickness");
      radiuschoice->add("Bottoming greater than 3x thickness");
      radiuschoice->add("Coining 0 to thikness");
      radiuschoice->add("Coining thickness to 3x thickness");
      radiuschoice->add("Coining greater than 3x thickness");
      radiuschoice->value(0);
      tb = new Fl_Text_Buffer();
      BAtext = new Fl_Text_Display(10,190,250,130,"");
      BAtext->buffer(tb);
      char*t1="BA=BA(R,A)\nLL1=L(L,R,A)\nWhere R-radius,A-angle,L-lenth\n";
      char*t2="BA=bend allowance\n";
      char*t3="LL2=L(L,R,A,R,A)-2 bend parameters\n";
      char*t4="Lf=(LL1+LL2+...LLn)+\n(BA1+BA2+...BAn)";
      string total( string(t1) + t2+t3+t4);
      tb->text(total.c_str());
      //
      //box=new Fl_Box(FL_UP_BOX, 260, 140, 757, 557, "");
      //box->color(FL_WHITE);
      //Fl_PNG_Image*temp=new Fl_PNG_Image("pic1.png");
      Fl_PNG_Image *temp=new Fl_PNG_Image("pic1.png");
      //Fl_Image *temp;
      pic1 = temp->copy(757,557);
      delete temp;
      //pic1=temp;
      //pic1->copy(20,20);
      //box->image(pic1);
      //box->redraw();
      picbox=new Box(260, 140, 757, 557,this);
   end();

   resizable(this);
   show();
}
MainWindow::~MainWindow()
{
    //dtor
}

void MainWindow::but_cb(Fl_Widget* o, void* v) {
    MainWindow* T=(MainWindow*)v;
    T->but_cb_i();
}
//

void MainWindow::but_cb_i()
{
       Calculate clt;
       clt.expressionToParse=const_cast<char*>(inp->value());
       try
        {
        clt.radiusv=radiuschoice->value();
        clt.materialv=materialchoice->value();
        clt.setK();
        clt.solve();
        out->value(clt.result);
        }

      catch(const Converter::Lexical_error& e) {
      std::cerr << "Lexical error: " << e << '\n';
      std::string er="Lexical error: "+e.get_message();
      fl_message(const_cast<char*>(er.c_str()));
    } catch(const Converter::Syntax_error& e) {
      std::cerr << "Syntax error: " << e << '\n';
      std::string er="Syntax error: "+e.get_message();
      out->value("ERROR");
      fl_message(const_cast<char*>(er.c_str()));
    } catch(const Converter::Runtime_error& e) {
      std::cerr << "Runtime error: " << e << '\n';
      std::string er="Runtime error: "+e.get_message();
      fl_message(const_cast<char*>(er.c_str()));
    }


}


//----------------------------------------------------

void MainWindow::cb_quit(Fl_Widget* , void* v) {

   ( (MainWindow*)v )->cb_quit_i();
}


void MainWindow::cb_quit_i() {

    hide();
}

//----------------------------------------------------

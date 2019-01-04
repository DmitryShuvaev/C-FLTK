#include "T1.h"

// MAIN
int main() {
     Fl_Double_Window win(220, 220);
	// win.begin();
     MyTimer tim(10, 10, win.w()-20, win.h()-20);
	 //MyTimer2 tim2(10, 10, win.w()-20, win.h()-20);
	 //win.add(tim);
	 //win.add(tim2);
	 //win.end();
     win.show();
     return(Fl::run());
}
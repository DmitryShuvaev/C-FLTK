#include "mainwindow.h"
//
// Test 'cross' cursor when mouse in GL window
// erco 11/03/05
//
class MyGlWindow : public Fl_Gl_Window {
    int handle(int e) {
        int ret = Fl_Gl_Window::handle(e);
        switch ( e ) {
            case FL_ENTER:
                window()->cursor(FL_CURSOR_CROSS);           // 'window()->cursor()' needed on WIN32 for 1.1.6 and older.
                ret = 1;                                     // 1.1.7 and up can probably just use fl_cursor(..)
                break;
            case FL_LEAVE:
                window()->cursor(FL_CURSOR_DEFAULT);
                ret = 1;
                break;
        }
        return(ret);
    }
    void draw() {
        if (!valid()) {
            valid(1);
            glViewport(0,0,w(),h());

        }
        glClear(GL_COLOR_BUFFER_BIT);

    }
public:
    MyGlWindow(int x,int y,int w,int h,const char*l=0) : Fl_Gl_Window(x,y,w,h,l) {
    }
};

void init(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glShadeModel(GL_FLAT);
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
int main(int argc, char **argv) {
	EventWindow b(WINDOW_WIDTH,WINDOW_HEIGHT);
	b.show();
	return Fl::run();

	   // Fl_Window win(500, 500);
    //MyGlWindow glwin(10,10,500-20,500-20);
	
    //win.show();
    //return(Fl::run());

//glutInit (&argc,argv);
//glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
//glutInitWindowSize(400,100);
//glutInitWindowPosition(100,100);
//glutCreateWindow("First Chapter-Openint an ");
//init();
//glutDisplayFunc(display);
//glutMainLoop();
//return 0;
}
#include "EventWindow.h"
char*foo;

EventWindow::EventWindow(int width,int height):Fl_Window(width,height,"")
{
	label("Demo Window for CS 559");
	// Instantiate the check button
    // x , y , width, height, label
    check_b = new Fl_Check_Button(25,15,140,20,"Check Button");
	light_b = new Fl_Light_Button(25,45,140,20,"Hide Check Button");
	// Make all of the default colors for the labels cyan
    check_b->labelcolor(FL_CYAN);
    light_b->labelcolor(FL_CYAN);
	// Register the callbacks for each of the buttons
    check_b->callback(checkbutton_cb_s,(void*)this);
	light_b->callback(lightbutton_cb_s,(void*)this);
	round_b = new Fl_Round_Button(25, 75, 140, 20, "Activate Light B");
    round_b->labelcolor(FL_CYAN);
	round_b->callback(round_b_cb_s,(void*)this);
}

//int EventWindow::handle(int event)
//{
//	switch(event){
//	case FL_PUSH:
//	case FL_RELEASE:
//	case FL_DRAG:
//	case FL_MOVE:
//		return 1;//handle_mouse(event,Fl::event_button(),Fl::event_x(),Fl::event_y());
//	case FL_FOCUS:
//		label("Gained focus");
//		damage(1);
//		return 1;
//	case FL_UNFOCUS:
//		label("Lost focus");
//		damage(1);
//		return 1;
//	case FL_KEYBOARD:  return handle_key(event,Fl::event_key());
//	default:
//		return Fl_Window::handle(event);
//	};
//	
//}
//int EventWindow::handle_mouse(int event, int button, int x, int y) {
//
//        if (foo) delete [] foo;
//        foo = new char[100];
//    int ret = 0;
//
//    switch ( button ) {
//                        case 1: // LMB
//                                        ret = 1;
//                                        // Based on the action, print the action and
//                                        // coordinates where it occurred.
//
//                                        if ( event == FL_PUSH ) {
//
//                                                        sprintf(foo,"LMB PUSH ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//
//                                        }
//
//                                        else if (event == FL_DRAG ) {
//
//                                                        sprintf(foo,"LMB Drag ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//
//                                        }
//
//                                        else if ( event == FL_RELEASE ) {
//
//                                                        sprintf(foo,"LMB Release ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//
//                                        }
//
// 
//
//                                        break;
//
// 
//
//                        case 2: // MMB
//
//                                        ret = 1;
//
//                                        // Based on the action, print the action and
//
//                                        // coordinates where it occurred.
//
//                                        if ( event == FL_PUSH ) {
//                                                        sprintf(foo,"MMB Push ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//                                        }
//
//                                        else if (event == FL_DRAG ) {
//                                                        sprintf(foo,"MMB Drag ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//
//                                        }
//
//                                        else if ( event == FL_RELEASE ) {
//
//                                                        sprintf(foo,"MMB Release ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//
//                                        }
//                                        break;
//                        case 3: // RMB
//                                        ret = 1;
//                                        // Based on the action, print the action and
//                                        // coordinates where it occurred.
//
//                                        if ( event == FL_PUSH ) {
//                                                        sprintf(foo,"RMB Push ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//
//                                        }
//
//                                        else if (event == FL_DRAG ) {
//                                                        sprintf(foo,"RMB Drag ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//
//                                        }
//
//                                        else if ( event == FL_RELEASE ) {
//                                                        sprintf(foo,"RMB Release ( %d , %d )",x,y);
//                                                        label(foo);
//                                                        damage(1);
//                                        }
//                                        break;
//                        }
//
//        return ret;
//
//}
//int EventWindow::handle_key(int event, int key) {
//
//                switch ( key ) {
//                case 'c':  label ("letter c was depressed");
//                              damage(1);
//                                return 1;
//                default:  label ("Nothing to do!");
//                                damage(1);
//                                printf("nothing to do\n");
//                                return 1;
//                }
//
//}
// Callback function for the check button.

// Turn the label red and change it to read Checked if the

// check button is checked.

void EventWindow::checkbutton_cb(Fl_Widget* w) {
                Fl_Check_Button* flcb = ((Fl_Check_Button*)w);
                if ( flcb->value() == 1 ) {
                                flcb->labelcolor(FL_RED);
                                flcb->label("Checked");                               
                }

                else{
                                flcb->labelcolor(FL_CYAN);
                                flcb->label("Check Button1");
                }             
                flcb->damage(1);
                flcb->parent()->redraw();
}
void EventWindow::checkbutton_cb_s(Fl_Widget*w,void*data){
     EventWindow*o=(EventWindow*)data;
     o->checkbutton_cb(w);
}
void EventWindow::lightbutton_cb(Fl_Widget*w){
                Fl_Light_Button* fllb = ((Fl_Light_Button*)w);
                if ( fllb->value() == 1 ) {
                                check_b->hide();
                }
                else {
                                check_b->show();
                }             
                fllb->damage(1);
                fllb->parent()->redraw();
}
void EventWindow::lightbutton_cb_s(Fl_Widget*w,void*data){
     EventWindow*o=(EventWindow*)data;
	 o->lightbutton_cb(w);
}
void EventWindow::round_b_cb(Fl_Widget*w){
	if ( ((Fl_Round_Button*)w)->value() == 1 ) {
     light_b->activate();
}
else {
     light_b->deactivate();
}
w->damage(1);
w->parent()->redraw();
}
void EventWindow::round_b_cb_s(Fl_Widget*w,void*data){
     EventWindow*o=(EventWindow*)data;
	 o->round_b_cb(w);
}
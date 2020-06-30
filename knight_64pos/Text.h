#ifndef TEXT_H
#define TEXT_H

#include <FL/fl_draw.H>

class Text: public Fl_Widget
{
    public:
        Text(): Fl_Widget(0,0,0,0,0){}
        Text(int X,int Y,int W,int H,int sz);

          void draw() {
            fl_color(FL_BLACK);
            fl_font(FL_COURIER, sz);
            fl_draw(s2,this->X,this->Y,this->W,this->H,align());


    //        fl_draw(s,1280/2,720/2,w(),h(),align());   // draw text over image and background
    }
    void draw_coord(int X,int Y,int W,int H,int sz)
    {
     this->X=X;
     this->Y=Y;this->sz=sz;
     this->W=W;this->H=H;

    // draw();
    }

	void drawText(char *s){

       sprintf(s2, s);
	}
	void setFont(int s){
	    size(s,s);
	    //textsize(s);
//redraw();
	}
        virtual ~Text();
        //varial
			char s2[80];
    protected:

    private:
        int X,Y,W,H;
        int sz;
};

#endif // TEXT_H

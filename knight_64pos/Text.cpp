#include "Text.h"

Text::Text(int X,int Y,int W,int H,int sz): Fl_Widget(X,Y,W,H)
{
    //ctor
    this->X=X;
    this->Y=Y;this->sz=sz;
            sprintf(s2, "");
}

Text::~Text()
{
    //dtor
}

#include "Y_x_square.h"

Y_x_square::Y_x_square()
{
    //ctor


}
void Y_x_square::clearPoints()
{
     for (auto p : points)
    {
        delete p;
    }
    points.clear();
    for (auto p : lines)
    {
        delete p;
    }
    lines.clear();
}
Y_x_square::~Y_x_square()
{
    //dtor
 clearPoints();
}

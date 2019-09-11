#ifndef JUMPING_BOX_H
#define JUMPING_BOX_H
#include "Gem.h"
#include "Level_Maker.h"

using namespace Graph_lib;
class Jumping_box
{
    public:
        Jumping_box();
        virtual ~Jumping_box();
//Jump_box():gem_in(false){}
bool gem_in;
bool is_showd;//if colision show gem
bool is_consumed;
Gem *gem;

};

#endif // JUMPING_BOX_H

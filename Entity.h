#pragma once
#include <string>
#include "Map.h"
class Entity
{
protected:
    Entity(){};
public:
    int x,y;
    Map* map;
    std::string character;
    virtual ~Entity(){};
    virtual void update()=0;
    virtual void draw()=0;
    virtual void moveUP()=0;
    virtual void moveDOWN()=0;
    virtual void moveRIGHT()=0;
    virtual void moveLEFT()=0;
};
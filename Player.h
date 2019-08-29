#pragma once
#include "Entity.h"
// forward declaration
class Map;

class Player: public Entity
{
public:
    Player(int x, int y, Map* map);
    ~Player();
    virtual void update() override;
    virtual void draw() override;
    virtual void moveUP() override;
    virtual void moveDOWN() override;
    virtual void moveRIGHT() override;
    virtual void moveLEFT() override;
};


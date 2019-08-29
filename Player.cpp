#include "Player.h"
#include <curses.h>
#include "Generator.h"
void Player::update(){
}
void Player::draw(){
    mvprintw(y,x,character.c_str());
}
Player::Player(int x, int y, Map* map)
{
    this->x = x;
    this->y = y;
    this->character = "@";
    this->map = map;
}

Player::~Player()
{
}
void Player::moveUP(){
    int x1=this->x;
    int y1=this->y; 
    if (map->getTile(x1,y1-1)!=map->ch){
        y--;
    }
}
void Player::moveDOWN(){
    int x1=this->x;
    int y1=this->y;
    if (map->getTile(x1,y1+1)!=map->ch){
        y++;
    }
}
void Player::moveRIGHT(){
    int x1=this->x;
    int y1=this->y; 
    if (map->getTile(x1+1,y1)!=map->ch){
        this->x++;
    }
}
void Player::moveLEFT(){
    int x1=this->x;
    int y1=this->y;
    if (map->getTile(x1-1,y1)!=map->ch){
        x--;
    }
}
#include "Map.h"
#include <curses.h>
#include <vector>



unsigned long Map::getTile(int x, int y){
    return map[x + y * width];
}
void Map::setTile(int x, int y, unsigned long ch){
    if(x > width | x < 0 | y > hight | y < 0){

    }else{
        this->map[x + y * width] = ch;
    }
}

void Map::draw(){
    for(int x = 0; x < width; x++){
        for(int y = 0; y < hight; y++){
            mvaddch (y,x,getTile(x,y));
        }
    }
}

int Map::getWidth(){
    return this->width;
}
int Map::getHeight(){
    return this->hight;
}
void Map::setWidth(int width){
    this->width=width;
}
void Map::setHight(int hight){
    this->hight=hight;
}
void Map::resizeMap(){
 map.resize(width * hight);
    for(auto& element:map){
    //element=ACS_BULLET;
    element=(unsigned long)' ';
    }
}
Map::Map()
{
    //width = 119;
    //height = 29;
   
    this->ch= ACS_CKBOARD;
    /*for(int x=0;x<120;x++){
        map[x] = ch;
        map[x+width*29]=ch;
    }
    for(int x=1;x<29;x++){
        map[x*120+119]=ch;
        map[x*120]=ch;
    }*/
    
}

Map::~Map()
{
}

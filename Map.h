#pragma once
#include <vector>
#include <string>
#include <curses.h>
class Map
{
private:
    int width, hight;
    std::vector<unsigned long> map;
    
public:
    unsigned long ch;
    unsigned long getTile(int x, int y);
    void setTile(int x, int y, unsigned long ch);
    int getWidth();
    int getHeight();
    void setWidth(int width);
    void setHight(int hight);
    void resizeMap();
    void draw();
    Map();
    ~Map();
};

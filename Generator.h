#pragma once
#include "Map.h"
#include <vector>
#include <bitset>
#include <stack>
struct Cell {
std::bitset<8> walls=std::bitset<8>("00000000");
int x;
int y;
Map* map;
int toWorld(int number);
void putToMap();
bool isVisited=false;
};



class Generator
{
private:
    std::vector<Cell*> cells;
    Map* map;
    Cell* pickRandomCell(std::vector<Cell*> cells);
    std::vector<Cell*> getNeighbours(Cell* cell);
    void openTheDoor(Cell* original, Cell* destination);
    bool inField(int x,int y);
    Cell* getCell(int x, int y);
    std::stack<Cell*> visited;
    int width, height;
    
public:
void generate();
void draw();
    Generator(int width, int height, Map* map );
    ~Generator();
};



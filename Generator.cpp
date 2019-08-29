#include "Generator.h"
#include <bitset>
#include <curses.h>
#include <ctime>


#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_RIGHT 7



int Cell::toWorld(int number){
    if(number==0){
        return 1;
    }else if(x==-1){
        return 0;
    }else{
        return number*2 + 1;
    }
}
void Generator::generate(){
    Cell* current=pickRandomCell(cells);
    current->isVisited=true;
    visited.push(current);
    while (!visited.empty())
    {
        std::vector<Cell*> neighbours = getNeighbours(current);
        if(!neighbours.empty()){
            Cell* next = pickRandomCell(neighbours);
            next->isVisited = true;
            visited.push(next);
            openTheDoor(current, next);
            current = next;
        }
        else
        {
           visited.pop();
           if(!visited.empty())
           current = visited.top();
        }
    }
    
    //wybieramy losowo neiboursa
    //oznaczamy jako vivited
    //rozwalamy ściany
    //zapisujemy na stosie
    //sprawdzenie czy jest sąsiad -> jeżeli nie to zdjęcie ze stosu
    //sprawdzenie czy stos pusty -> koniec


};
 Cell* Generator::pickRandomCell(std::vector<Cell*> cells){
     
     unsigned int los=std::rand()%(cells.size());
     return cells[los];
 };
std::vector<Cell*> Generator::getNeighbours(Cell* cell){
    std::vector<Cell*> neighbours;
    int x_directions[4] = { 0, 1, 0,-1};
    int y_directions[4] = {-1, 0, 1, 0};
    for (int i=0; i<4; i++){
        int X = cell->x;
        int Y = cell->y;
        if (inField(X+x_directions[i],Y+y_directions[i])==true){
            auto neighbour = getCell(X+x_directions[i],Y+y_directions[i]);
                if(!neighbour->isVisited){
                    neighbours.push_back(neighbour);
                }
        };
    }
    return neighbours;
};

void Generator::openTheDoor(Cell* original, Cell* destination){
    int xo = original->x;
    int yo = original->y;
    int xd = destination->x;
    int yd = destination->y;

    if(xo<xd){
        original->walls[RIGHT] = 0;
        destination->walls[LEFT] = 0;
    }else if(xo>xd){
        original->walls[LEFT] = 0;
        destination->walls[RIGHT] = 0;
    }else if(yo<yd){
        original->walls[DOWN] = 0;
        destination->walls[UP] = 0;
    }else
    {
        original->walls[UP] = 0;
        destination->walls[DOWN] = 0;
    }
};

 bool Generator::inField(int x, int y){
    if (x<0 || x>= this->width || y<0 || y>= this->height) return false;
    return true;
 };

 Cell* Generator::getCell(int x, int y){
     return cells[x + y * width];
 }
 

void Cell::putToMap(){
    int X = toWorld(x);
    int Y = toWorld(y);
    unsigned long ch = map->ch;
    if(walls.test(UP)){
        map->setTile(Y-1,X,ch);
    }
    if(walls.test(DOWN)){
        map->setTile(Y+1,X,ch);
    }
    if(walls.test(LEFT)){
        map->setTile(Y,X-1,ch);
    }
    if(walls.test(RIGHT)){
        map->setTile(Y,X+1,ch);
    }
    if(walls.test(UP_LEFT)){
        map->setTile(Y-1,X-1,ch);
    }
    if(walls.test(UP_RIGHT)){
        map->setTile(Y-1,X+1,ch);
    }
    if(walls.test(DOWN_LEFT)){
        map->setTile(Y+1,X-1,ch);
    }
    if(walls.test(DOWN_RIGHT)){
        map->setTile(Y+1,X+1,ch);
    }  
}
void Generator::draw(){
    for(auto cell : cells){
        cell->putToMap();
    }
}

Generator::Generator(int width, int height, Map* map )
{
    this->map = map;
    this->height=height;
    this->width=width;
    cells.resize(width*height);
    for(int i=0;i<cells.size();i++){
        Cell* cell = new Cell();
        cell->map = map;
        cell->walls = std::bitset<8>("11111111");
        cell->y = std::div(i,width).quot;
        cell->x = std::div(i,width).rem;
        cells[i] = cell;
    }
    Cell conv;
    int HEIGHT = conv.toWorld(cells[cells.size()-1]->y)+1;
    int WIDTH = conv.toWorld(cells[cells.size()-1]->x)+1;
    this->map->setWidth(HEIGHT+1);
    this->map->setHight(WIDTH+1);
    this->map->resizeMap();
}

Generator::~Generator()
{
    for(auto cell : cells){
        delete cell;
    }
}